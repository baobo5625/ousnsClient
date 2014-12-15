#include "stdAfx.h"
#include "MainDlg1.h"
#include "friendChatDlg.h"
//#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "FriendListTab.h"
#include "NotifyUserDlg.h"
#include "OusnsFriend.h"
#include "SearchResult.h"
#include "OusnsLoginUser.h"


FriendListTab::FriendListTab(MainDlg^ mainDlgInput, Communication^ commInput,OusnsLoginUser^ loginUserInput)
{
	InitializeComponent();
	this->mainDlg = mainDlgInput;
	this->comm = commInput;
	this->friend_chat_dlg_list = gcnew Dictionary<unsigned int, friendChatDlg ^>();
	this->msgs_by_user = gcnew Dictionary<OusnsFriend ^, LinkedList<ChatMessage^>^>();
	this->transferFilesByUser = gcnew Dictionary<OusnsFriend ^, LinkedList<DirectTransferFile ^> ^>();
	this->pending_counts_by_user = gcnew Dictionary<OusnsFriend ^, unsigned int>;
	this->loginUser = loginUserInput;
	this->InitializeFriendListTab();
	this->searchFriendOffSet = 0;
	//
	//TODO: 在此处添加构造函数代码
	//
}

System::Void FriendListTab::searchFriendOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->searchFriendIDColumn->Text = L"OuID";
	this->searchFriendInfoColumn->Text = L"昵称";
	this->InitializeSearchFriendSearchResult();

}


System::Void FriendListTab::searchFriendEmailRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->searchFriendIDColumn->Text = L"Email";
	this->searchFriendInfoColumn->Text = L"昵称";
	this->InitializeSearchFriendSearchResult();
}

System::Void FriendListTab::searchFriendNicknameRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->searchFriendIDColumn->Text = L"昵称";
	this->searchFriendInfoColumn->Text = L"OuID";
	this->InitializeSearchFriendSearchResult();
}



/*
* this function doing the adding friend request
*/
System::Void FriendListTab::searchFriendAddFriendButton_Click(System::Object^  sender, System::EventArgs^  e){

	ListViewItem::ListViewSubItemCollection^ selectedSubItems;
	ListViewItem::ListViewSubItem^ selectedSubItem;
	ListView::SelectedListViewItemCollection^ selected = this->searchFriendResultList->SelectedItems;

	System::Collections::IEnumerator^ myEnum = selected->GetEnumerator();
	unsigned int userID;
	OusnsMessage^ msg;
	while ( myEnum->MoveNext() )
	{
		ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
		//Start to send the add friend request
		selectedSubItems = item->SubItems;

		if(searchFriendOuidRadioButton->Checked){
			selectedSubItem = selectedSubItems[0];
			userID = Convert::ToUInt32(selectedSubItem->Text->ToString());
		}
		else if (searchFriendEmailRadioButton->Checked){
			selectedSubItem = selectedSubItems[2];
			userID = Convert::ToUInt32(selectedSubItem->Text->ToString());
		}
		else{
			selectedSubItem = selectedSubItems[1];
			userID = Convert::ToUInt32(selectedSubItem->Text->ToString());
		}
		msg = this->mainDlg->msgCreator->MakeAddFriendMessage(this->loginUser->userID,this->loginUser->sessionID, userID, L"no reason at the moment");
		this->mainDlg->comm->AddToWorkQueue(msg);
	}


}


System::Void FriendListTab::InitializeFriendListTab(void){
	this->InitializeSearchFriendSearchResult();
}




System::Void FriendListTab::searchFriendNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
	int searchUserIDType;
	if(searchFriendOuidRadioButton->Checked){
		searchUserIDType = 0;
	}
	else if (searchFriendEmailRadioButton->Checked){
		searchUserIDType = 1;
	}
	else{
		searchUserIDType = 2;
	}
	String^ keyword = this->searchFriendInputBox->Text;
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchFriendOffSet + SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->mainDlg->comm->AddToWorkQueue(msg);
}


System::Void FriendListTab::searchFriendPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
	int searchUserIDType;
	if(searchFriendOuidRadioButton->Checked){
		searchUserIDType = 0;
	}
	else if (searchFriendEmailRadioButton->Checked){
		searchUserIDType = 1;
	}
	else{
		searchUserIDType = 2;
	}
	String^ keyword = this->searchFriendInputBox->Text;
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchFriendOffSet - SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->mainDlg->comm->AddToWorkQueue(msg);
}

System::Void FriendListTab::searchFriendResultList_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) {
	if(this->searchFriendResultList->SelectedItems->Count && ! this->searchFriendAddFriendButton->Enabled)
		this->searchFriendAddFriendButton->Enabled = true;
	if(!this->searchFriendResultList->SelectedItems->Count && this->searchFriendAddFriendButton->Enabled)
		this->searchFriendAddFriendButton->Enabled = false;
}

System::Void FriendListTab::QueryFriendPersonalInfo(System::Object^  sender, System::EventArgs^  e) {
	OusnsFriend ^ targetFriend = this->loginUser->FindFriend(UInt32::Parse(dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Name->Substring(12)));
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,targetFriend->UserID);
	this->mainDlg->comm->AddToWorkQueue(msg);
}

System::Void FriendListTab::removeFriendToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	OusnsFriend ^ targetFriend = this->FindSelectedFriend();
	if(targetFriend != nullptr){

		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeRemoveFriendMessage(this->loginUser->UserID,this->loginUser->SessionID,targetFriend->UserID);
		String^ content = FRIEND_LIST_REMOVE_FRIEND +"\n"+\
			targetFriend->Nickname +"("+ targetFriend->UserID.ToString() \
			+ ")";
		array<String^>^ buttons = {L"确定",L"取消"};
		OuSns::NotifyUINonBlockingMsg(OuSns::QUESTION_DLG,content,buttons,msg,this->mainDlg->comm);
	}
}

System::Void FriendListTab::FriendListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if(sender->GetType()->Name == L"SideBarPanelItem"){
		this->removeFriendToolStripMenuItem->Visible = false;
		this->openFriendDlgToolStripMenuItem->Visible = false;
	}
	else{
		//if(e->Button == ::MouseButtons::Right)
		this->mainDlg->ListClickAutoCheck(sender,e);
		this->removeFriendToolStripMenuItem->Visible = true;
		this->openFriendDlgToolStripMenuItem->Visible = true;
	}
	if(e->Button == ::MouseButtons::Right)
		this->friendListContextMenuStrip->Show(this->friendList,e->Location);

}




System::Void FriendListTab::searchFriendSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchFriendSearchResult();
	if(this->searchFriendInputBox->Text->Length == 0){
		NotifyUserDlg^ dlg = gcnew NotifyUserDlg(OuSns::ERROR_DLG,L"确定",SEARCH_ERROR_NOTIFICATION);
	}
	else{
		int searchUserIDType;
		if(searchFriendOuidRadioButton->Checked){
			searchUserIDType = 0;
		}
		else if (searchFriendEmailRadioButton->Checked){
			searchUserIDType = 1;
		}
		else{
			searchUserIDType = 2;
		}
		String^ keyword = this->searchFriendInputBox->Text;
		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,0,SEARCH_RESULT_PAGE_LIMIT);
		this->mainDlg->comm->AddToWorkQueue(msg);
	}
}


System::Void FriendListTab::InitializeSearchFriendSearchResult(void){
	this->searchFriendResultList->Items->Clear();
	this->searchFriendPreviousPageLabelX->Enabled = false;
	this->searchFriendPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->searchFriendPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->searchFriendNextPageLabelX->Enabled = false;
	this->searchFriendNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->searchFriendNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->searchFriendAddFriendButton->Enabled = false;
	//this->searchFriendInputBox->Text = L"";
}


System::Void FriendListTab::RemoveTargetFileTransferJob(unsigned srcID, String ^ fileName, String ^ md5, int reason) {

	String ^ panelName;
	Dictionary<String ^, DirectTransferFile ^>^ panelList =
		this->friend_chat_dlg_list[srcID]->fileTransferJobPanelList;
	for each (String ^ p in panelList->Keys) {
		if (panelList[p]->fileName == fileName && panelList[p]->md5 == md5) {
			panelName = p;
			break;
		}
	}
	if (panelName != nullptr) {
		OuSns::friendChatDlg::RemoveFileTransferJobDelegate^ delegateFunction = 
			gcnew OuSns::friendChatDlg::RemoveFileTransferJobDelegate(this->friend_chat_dlg_list[srcID], 
			&OuSns::friendChatDlg::RemoveFileTransferJobPanel);
		array<Object ^>^ args = {panelName, reason};
		this->Invoke(delegateFunction, args);
	} else {
		MessageBox::Show("ProcessCancelFileTransfer: unknown fileName: " + fileName + "\nmd5: " + md5);
	}

}



System::Void FriendListTab::OpenFriendChatDlg(Object^ sender, EventArgs^ e){

	OusnsFriend ^ target_friend = this->loginUser->FindFriend(UInt32::Parse(dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Name->Substring(12)));


	if (this->friend_chat_dlg_list->ContainsKey(target_friend->UserID)) {
		this->friend_chat_dlg_list[target_friend->UserID]->Focus();
	} else {
		OuSns::friendChatDlg^ friendChatDlg = gcnew OuSns::friendChatDlg(this, target_friend, this->loginUser);
		this->friend_chat_dlg_list[target_friend->userID] = friendChatDlg;
		if (this->msgs_by_user->ContainsKey(target_friend)) {
			if (this->msgs_by_user[target_friend]->Count > 0) {
				NewMessageDelegate ^ msg_delegate = gcnew NewMessageDelegate(this->friend_chat_dlg_list[target_friend->userID], 
					&friendChatDlg::push_new_message);

				// Push messages onto the window.
				for each (ChatMessage^ m in this->msgs_by_user[target_friend]) {
					array<Object ^>^ args = {m};
					this->Invoke(msg_delegate, args);
					this->mainDlg->pending_msg_total -= 1;
					this->pending_counts_by_user[target_friend] -= 1;
				}

				// Clear the unread message queue.
				int i = 0;
				int num_msgs_to_remove = this->msgs_by_user[target_friend]->Count;
				while (i < num_msgs_to_remove) {
					this->msgs_by_user[target_friend]->RemoveLast();
					i += 1;
				}			
				// Remove the unread message reminder from the friend icon.
				for each(DevComponents::DotNetBar::ButtonItem^ i in this->myFriendListSideBarPanelItem->SubItems){
					if (i->Name->Substring(13) == target_friend->userID.ToString()) {
						i->Text = target_friend->nickname;
						break;
					}
				}		
				// Update the unread message reminders of the friend list tab and panel.
				if (this->mainDlg->pending_msg_total > 0) {
					//this->mainDlg->friendListTab->Text = "我的好友" + L"(" + this->mainDlg->pending_msg_total.ToString() + ")";
					this->myFriendListTab->Text = "我的好友" + L"(" + this->mainDlg->pending_msg_total.ToString() + ")";
				} else {
					//this->mainDlg->friendListTab->Text = "我的好友";
					this->myFriendListTab->Text = "我的好友";
				}

			}



		}

		if (this->transferFilesByUser->ContainsKey(target_friend)) {
			if (this->transferFilesByUser[target_friend]->Count > 0) {
				OuSns::friendChatDlg::AddFileTransferJobDelegate^ delegateFunction = 
					gcnew OuSns::friendChatDlg::AddFileTransferJobDelegate(this->friend_chat_dlg_list[target_friend->userID], 
					&OuSns::friendChatDlg::AddFileTransferJobPanel);

				for each (DirectTransferFile ^ f in this->transferFilesByUser[target_friend]) {

					array<Object ^>^ args = {f->fileName, f->filePath, f->fileSize, f->md5, false};
					this->Invoke(delegateFunction, args);
					this->mainDlg->pending_msg_total -= 1;
					this->pending_counts_by_user[target_friend] -= 1;

					if (f->isCancelled) {
						this->RemoveTargetFileTransferJob(target_friend->userID, f->fileName, f->md5, REMOTE_CANCEL);
					}

				}

				while (this->transferFilesByUser[target_friend]->Count > 0) {
					this->transferFilesByUser[target_friend]->RemoveLast();
				}

				// Remove the unread message reminder from the friend icon.
				for each(DevComponents::DotNetBar::ButtonItem^ i in this->myFriendListSideBarPanelItem->SubItems){
					if (i->Name->Substring(12) == target_friend->userID.ToString()) {
						i->Text = target_friend->nickname;
						break;
					}

				}

				// Update the unread message reminders of the friend list tab and panel.
				if (this->mainDlg->pending_msg_total > 0) {
					//this->mainDlg->friendListTab->Text = "我的好友" + L"(" + this->mainDlg->pending_msg_total.ToString() + ")";
					this->myFriendListTab->Text = "我的好友" + L"(" + this->mainDlg->pending_msg_total.ToString() + ")";
				} else {
					//this->mainDlg->friendListTab->Text = "我的好友";
					this->myFriendListTab->Text = "我的好友";
				}
			}
		}
		friendChatDlg->Show();
	}

}

/*
* This function will be used to find the checked button item in the friend list
*/
OusnsFriend^ FriendListTab::FindSelectedFriend(void){
	DevComponents::DotNetBar::ButtonItem^ eachButton;
	DevComponents::DotNetBar::SideBarPanelItem^ buttonParent = this->friendList->ExpandedPanel;
	OusnsFriend ^ targetFriend;
	for each( eachButton in buttonParent->SubItems){
		if (eachButton->Checked == true){
			targetFriend = this->loginUser->FindFriend(UInt32::Parse(eachButton->Name->Substring(12)));
		}
	}
	return targetFriend;
}

System::Void FriendListTab::FriendButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);
	if(button->Checked){
		OusnsFriend^ selectedFriend = this->FindSelectedFriend();
		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,selectedFriend->UserID);
		this->comm->AddToWorkQueue(msg);
	}
}

/* 
* This function will be called when there is a response for the request that search specific friend 
* This function will dynamic cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
* Each Object represent a search result entry. 
*/
System::Void FriendListTab::DisplaySearchFriendResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults){

	if(totalResult > offset + SEARCH_RESULT_PAGE_LIMIT){
		this->searchFriendNextPageLabelX->Enabled = true;
		this->searchFriendNextPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchFriendNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchFriendNextPageLabelX->Enabled = false;
		this->searchFriendNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchFriendNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}
	if(offset > SEARCH_RESULT_PAGE_LIMIT){
		this->searchFriendPreviousPageLabelX->Enabled = true;
		this->searchFriendPreviousPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchFriendPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchFriendPreviousPageLabelX->Enabled = false;
		this->searchFriendPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchFriendPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}

	SearchResult^ searchResult;
	System::Windows::Forms::ListViewItem^  listViewItem;
	this->searchFriendOffSet = offset;
	for each (searchResult in searchResults){
		if(searchFriendOuidRadioButton->Checked){
			listViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {searchResult->Get("targetUserID"), 
				searchResult->Get("nickname"), searchResult->Get("email")}, -1));
		}
		else if (searchFriendEmailRadioButton->Checked){
			listViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {searchResult->Get("email"), 
				searchResult->Get("nickname"), searchResult->Get("targetUserID")}, -1));
		}
		else{
			listViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {searchResult->Get("nickname"), 
				searchResult->Get("targetUserID"), searchResult->Get("email")}, -1));
		}

		this->searchFriendResultList->Items->Add(listViewItem);

	}

	return;
}

/* 
* This function will display the friend list in the login in user to UI
*/
System::Void FriendListTab::UpdateFriendListToUI(){

	this->myFriendListSideBarPanelItem->SubItems->Clear();
	//array<String ^> ^ statusDict = {"Offline","Online", "Away", "Busy", "Invisible"};
	OusnsFriend^ f;
	int i;
	for(i = 0; i < this->loginUser->friendListArray->Length;i++){
		f = this->loginUser->friendListArray[i];
		//}
		//for each(OusnsFriend^ f in this->loginUser->friendList) {
		DevComponents::DotNetBar::ButtonItem^ newFriend = gcnew DevComponents::DotNetBar::ButtonItem();
		newFriend->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
		newFriend->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
		newFriend->Name = L"friendButton" + f->userID.ToString();
		newFriend->Text = f->nickname + "(" + OuSns::UserStatusIntToString(f->Status) + ")";
		newFriend->DoubleClick += gcnew System::EventHandler(this, &FriendListTab::OpenFriendChatDlg);
		newFriend->Cursor = System::Windows::Forms::Cursors::Arrow;
		newFriend->CheckedChanged += gcnew System::EventHandler(this,&FriendListTab::FriendButtonItem_CheckedChanged);
		newFriend->AutoCheckOnClick = true;
		this->myFriendListSideBarPanelItem->SubItems->Add(newFriend);
	}
	this->myFriendListSideBarPanelItem->Refresh();

}


/*
* This function will be called when there is a response for the request that the login user is querying one of his friends personal information, like the birthday.
* This function will take ONLY 1 param.
* ousnsFriend, the type is OusnsFriend. This function will dynamically cast the first element in the param to OusnsFriend type and display this friend personal information in the UI.
*/
System::Void FriendListTab::DisplayFriendPersonalInfo(LinkedList<Object^>^ params){
	if(params->Count){
		OusnsFriend^ selectedFriend = this->FindSelectedFriend();
		if(selectedFriend != nullptr){
			OusnsFriend^ queryedFriend = dynamic_cast<OusnsFriend^>(params->First->Value);
			if(selectedFriend->UserID == queryedFriend->UserID){
				this->myFriendListTabFriendNicknameLabelX->Text = queryedFriend->Nickname;
				this->myFriendListTabFriendOuIDLabelX->Text = queryedFriend->UserID.ToString();
				this->myFriendListTabFriendSignatureLabelX->Text = queryedFriend->Signature;
				this->myFriendListTabSexLabelX->Text = queryedFriend->Sex;
				this->myFriendListTabBirthdayLabelX->Text = queryedFriend->BirthMonth.ToString() \
					+ FRIEND_PERSONAL_INFO_BIRTHMONTH_LABEL + queryedFriend->BirthDay.ToString() \
					+ FRIEND_PERSONAL_INFO_BIRTHDAY_LABEL;
				System::DateTime^ dtDateTime = gcnew DateTime(1970,1,1,0,0,0,0);
				dtDateTime = dtDateTime->AddSeconds(this->loginUser->loginTimeStamp);
				this->myFriendListTabAgeLabelX->Text = (dtDateTime->Year - queryedFriend->BirthYear).ToString();
				this->myFriendListTabZodiacLabelX->Text = queryedFriend->Zodiac;
				this->myFriendListTabEmailLabelX->Text = queryedFriend->Email;
				this->myFriendListTabCountryLabelX->Text = queryedFriend->Country;
				this->myFriendListTabProvinceLabelX->Text = queryedFriend->Province;
				this->myFriendListTabCityLabelX->Text = queryedFriend->City;
			}
		}
	}
}