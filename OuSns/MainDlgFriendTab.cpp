#include "stdAfx.h"
#include "MainDlg.h"
#include "friendChatDlg.h"
#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageProcessor.h"

System::Void MainDlg::searchFriendOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->searchFriendIDColumn->Text = L"OuID";
	 this->searchFriendInfoColumn->Text = L"昵称";
	 this->InitializeSearchFriendSearchResult();

 }


System::Void MainDlg::searchFriendEmailRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->searchFriendIDColumn->Text = L"Email";
	 this->searchFriendInfoColumn->Text = L"昵称";
	 this->InitializeSearchFriendSearchResult();
 }

System::Void MainDlg::searchFriendNicknameRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->searchFriendIDColumn->Text = L"昵称";
	 this->searchFriendInfoColumn->Text = L"OuID";
	 this->InitializeSearchFriendSearchResult();
 }



/*
* this function doing the adding friend request
*/
System::Void MainDlg::searchFriendAddFriendButton_Click(System::Object^  sender, System::EventArgs^  e){

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
		msg = this->msgCreator->MakeAddFriendMessage(this->loginUser->userID,this->loginUser->sessionID, userID, L"no reason at the moment");
		this->comm->AddToWorkQueue(msg);
	}


}


System::Void MainDlg::InitializeFriendListTab(void){
	this->InitializeSearchFriendSearchResult();
}

System::Void MainDlg::friendListTab_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->InitializeFriendListTab();
 }


System::Void MainDlg::searchFriendNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
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
	OusnsMessage^ msg = msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchFriendOffSet + SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->comm->AddToWorkQueue(msg);
}


System::Void MainDlg::searchFriendPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
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
	OusnsMessage^ msg = msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchFriendOffSet - SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->comm->AddToWorkQueue(msg);
}

System::Void MainDlg::searchFriendResultList_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) {
	 if(this->searchFriendResultList->SelectedItems->Count && ! this->searchFriendAddFriendButton->Enabled)
		 this->searchFriendAddFriendButton->Enabled = true;
	 if(!this->searchFriendResultList->SelectedItems->Count && this->searchFriendAddFriendButton->Enabled)
		 this->searchFriendAddFriendButton->Enabled = false;
 }

System::Void MainDlg::QueryFriendPersonalInfo(System::Object^  sender, System::EventArgs^  e) {
	OusnsFriend ^ targetFriend = this->loginUser->FindFriend(UInt32::Parse(dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Name->Substring(12)));
	OusnsMessage^ msg = this->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,targetFriend->UserID);
	this->comm->AddToWorkQueue(msg);
}

System::Void MainDlg::removeFriendToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	OusnsFriend ^ targetFriend = this->FindSelectedFriend();
	if(targetFriend != nullptr){

		OusnsMessage^ msg = this->msgCreator->MakeRemoveFriendMessage(this->loginUser->UserID,this->loginUser->SessionID,targetFriend->UserID);
		String^ content = FRIEND_LIST_REMOVE_FRIEND +"\n"+\
			targetFriend->Nickname +"("+ targetFriend->UserID.ToString() \
			+ ")";
		array<String^>^ buttons = {L"确定",L"取消"};
		OuSns::NotifyUINonBlockingMsg(OuSns::QUESTION_DLG,content,buttons,msg,this->comm);
	}
}

System::Void MainDlg::FriendListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	if(sender->GetType()->Name == L"SideBarPanelItem"){
		this->removeFriendToolStripMenuItem->Visible = false;
		this->openFriendDlgToolStripMenuItem->Visible = false;
	}
	else{
		//if(e->Button == ::MouseButtons::Right)
		this->ListClickAutoCheck(sender,e);
		this->removeFriendToolStripMenuItem->Visible = true;
		this->openFriendDlgToolStripMenuItem->Visible = true;
	}
	if(e->Button == ::MouseButtons::Right)
		this->friendListContextMenuStrip->Show(this->friendList,e->Location);

}


System::Void MainDlg::ListClickAutoCheck(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){

	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);

	DevComponents::DotNetBar::SideBarPanelItem^ buttonParent = \
		dynamic_cast<DevComponents::DotNetBar::SideBarPanelItem^> (button->Parent);
	DevComponents::DotNetBar::ButtonItem^ eachButton;
	this->superTabControl2->SuspendLayout();
	for each( eachButton in buttonParent->SubItems){
		if(eachButton->Checked)
			eachButton->Checked = false;
	}
	if(e->Button ==::MouseButtons::Right)
		button->Checked = true;
	this->superTabControl2->ResumeLayout();
}



System::Void MainDlg::searchFriendSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchFriendSearchResult();
	if(this->searchFriendInputBox->Text->Length == 0){
		NotifyUserDlg^ dlg = gcnew NotifyUserDlg(OuSns::NotifyUIDlgType::ERROR_DLG,L"确定",SEARCH_ERROR_NOTIFICATION);
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
		OusnsMessage^ msg = msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,0,SEARCH_RESULT_PAGE_LIMIT);
		this->comm->AddToWorkQueue(msg);
	}
}


System::Void MainDlg::InitializeSearchFriendSearchResult(void){
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


System::Void MainDlg::RemoveTargetFileTransferJob(unsigned srcID, String ^ fileName, String ^ md5, int reason) {

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



System::Void MainDlg::OpenFriendChatDlg(Object^ sender, EventArgs^ e){

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
					this->pending_msg_total -= 1;
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
				if (pending_msg_total > 0) {
					this->friendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
					this->myFriendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
				} else {
					this->friendListTab->Text = "我的好友";
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
					this->pending_msg_total -= 1;
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
				if (pending_msg_total > 0) {
					this->friendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
					this->myFriendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
				} else {
					this->friendListTab->Text = "我的好友";
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
OusnsFriend^ MainDlg::FindSelectedFriend(void){
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

System::Void MainDlg::FriendButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);
	if(button->Checked){
		OusnsFriend^ selectedFriend = this->FindSelectedFriend();
		OusnsMessage^ msg = this->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,selectedFriend->UserID);
		this->comm->AddToWorkQueue(msg);
	}
}