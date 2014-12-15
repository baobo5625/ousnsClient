#include "stdAfx.h"
#include "GroupListTab.h"
#include "MainDlg1.h"
#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageCreator.h"
#include "NotifyUserDlg.h"
#include "OusnsLoginUser.h"
#include "OusnsGroup.h"
#include "OusnsFriend.h"
#include "SearchResult.h"
GroupListTab::GroupListTab(MainDlg^ mainDlgInput, Communication^ commInput,OusnsLoginUser^ loginUserInput, MessageCreator^ msgCreatorInput)
{
	InitializeComponent();
	this->mainDlg = mainDlgInput;
	this->comm = commInput;
	this->loginUser = loginUserInput;
	this->msgsByGroup = gcnew Dictionary<unsigned int , LinkedList<ChatMessage^>^>();
	this->pendingCountsByGroup = gcnew Dictionary<unsigned int, unsigned int>();
	this->groupChatDlgDict = gcnew Dictionary<unsigned int, OuSns::GroupChatDlg^>();
	this->msgCreator = msgCreatorInput;

	Dictionary<unsigned int, unsigned int>^ testAdmin = gcnew Dictionary<unsigned int, unsigned int>();
	testAdmin->Add(100001,0);
	array<OusnsGroupUser^>^ testGroupUserArray;
	OusnsGroupUser^ testGroupUser = gcnew OusnsGroupUser(100010,100001,"testNickname","testDP");
	testGroupUserArray = gcnew array<OusnsGroupUser^>(1){testGroupUser};
	OusnsGroup^ testGroup = gcnew OusnsGroup(100001,"testGroup",\
		"testDescription","testCategory","testAnnounancement",100000,testAdmin,testGroupUserArray);
	array<OusnsGroup^>^ testGroupArray = gcnew array<OusnsGroup^>(1){testGroup};
	this->loginUser->UpdateGroupArray(testGroupArray);

	this->UpdateGroupListToUI();
	//
	//TODO: 在此处添加构造函数代码
	//
}
System::Void GroupListTab::createGroupSuperTabItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->InitializeCreateGroupTab();
		 }

System::Void GroupListTab::searchGroupSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->searchGroupInputBox->Text->Length == 0){
		NotifyUserDlg^ dlg = gcnew NotifyUserDlg(OuSns::ERROR_DLG,L"确定",SEARCH_ERROR_NOTIFICATION);
	}
	else{
		int searchGroupIDType;
		if(searchGroupOuidRadioButton->Checked){
			searchGroupIDType = 0;
		}
		else{
			searchGroupIDType = 1;
		}
		String^ keyword = this->searchGroupInputBox->Text;
		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchGroupMessage(this->loginUser->userID,this->loginUser->sessionID,searchGroupIDType,keyword,0,SEARCH_RESULT_PAGE_LIMIT);
		this->comm->AddToWorkQueue(msg);
	}
}


System::Void GroupListTab::InitializeSearchGroupSearchResult(void){
	this->searchGroupResultList->Items->Clear();
	this->searchGroupPreviousPageLabelX->Enabled = false;
	this->searchGroupPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->searchGroupPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->searchGroupNextPageLabelX->Enabled = false;
	this->searchGroupNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->searchGroupNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->searchGroupJoinGroupButton->Enabled = false;
	this->searchGroupInputBox->Text = L"";

	OusnsGroup^ tempGroup;
	int createdGroupTotal = 0;
	for each(tempGroup in this->loginUser->groupListArray){
		if(tempGroup->GroupOwnerID == this->loginUser->UserID){
			createdGroupTotal++;
		}
	}
	int createGroupLeft = CREATE_GROUP_LIMIT - createdGroupTotal;
	this->createGroupTabCreateCountRemainingCounterLabelX->Text = createGroupLeft.ToString();
	if(createGroupLeft <= 0){
		this->createGroupTabEnableControls(false);
	}
	else{
		this->createGroupTabEnableControls(true);
	}
}

System::Void GroupListTab::groupList_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if(sender->GetType()->Name == L"SideBarPanelItem"){
		this->openGroupDlgToolStripMenuItem->Visible = false;
		this->exitGroupToolStripMenuItem->Visible = false;
		this->deleteGroupToolStripMenuItem->Visible = false;
		this->createGroupToolStripMenuItem->Visible = true;
	}
	else{
		this->mainDlg->ListClickAutoCheck(sender,e);
		//if(e->Button ==::MouseButtons::Left)
		//   dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Checked = !dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Checked;
		OusnsGroup^ checkedGroup = this->FindSelectedGroup();

		if(checkedGroup != nullptr){
			this->openGroupDlgToolStripMenuItem->Visible = true;
			if(checkedGroup->GroupOwnerID == this->loginUser->UserID){
				this->deleteGroupToolStripMenuItem->Visible = true;
				this->exitGroupToolStripMenuItem->Visible = false;
			}
			else{
				this->deleteGroupToolStripMenuItem->Visible = false;
				this->exitGroupToolStripMenuItem->Visible = true;
			}
			this->createGroupToolStripMenuItem->Visible = false;
		}
	}
	if(e->Button == ::MouseButtons::Right)
		this->groupListContextMenuStrip->Show(this->groupList,e->Location);
		
}


System::Void GroupListTab::InitializeCreateGroupTab(){
	this->createGroupTabGroupNameTextBoxX->Text = L"";
	this->createGroupTabGroupDescriptionTextBoxX->Text = L"";
	this->createGroupTabGroupTagTextBoxX->Text  = L"仅限文字，字母以及数字，请以空格分隔每个关键字词";
	this->createGroupTabSearchContactTextBoxX->Text = L"搜索联系人";
	this->createGroupTabGroupCategoryComboBoxEx->SelectedIndex = 0;
	this->createGroupTabMemberListAdvTree->Nodes->Clear();
	this->createGroupTabContactListAdvTree->Nodes->Clear();
	array<OusnsFriend^>^ tempFriendArray = gcnew array<OusnsFriend^>(this->loginUser->friendListArray->Length);
	Array::Copy(this->loginUser->friendListArray,tempFriendArray,this->loginUser->friendListArray->Length);
	DevComponents::AdvTree::Node^ node;
	int i;
	this->createGroupTabContactListAdvTree->Nodes->Clear();
	this->createGroupTabContactListAdvTree->SuspendLayout();
	for (i = 0; i < tempFriendArray->Length;i++){
		node = gcnew DevComponents::AdvTree::Node();
		node->Name = tempFriendArray[i]->UserID.ToString() ;
		node->Text = tempFriendArray[i]->CommentName + "(" + tempFriendArray[i]->UserID.ToString() + ")";
		this->createGroupTabContactListAdvTree->Nodes->Add(node);
	}
	this->createGroupTabContactListAdvTree->ResumeLayout();
	this->createGroupTabContactListAdvTree->Nodes->Sort();
}



System::Void GroupListTab::joinGroupTab_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchGroupSearchResult();
}

System::Void GroupListTab::searchGroupOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchGroupSearchResult();
}

System::Void GroupListTab::searchGroupKeywordRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchGroupSearchResult();
}




System::Void GroupListTab::OpenGroupChatDlg(Object^ sender, EventArgs^ e){

	OusnsGroup ^ targetGroup = this->loginUser->FindGroup(UInt32::Parse(dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender)->Name->Substring(11)));


	if (this->groupChatDlgDict->ContainsKey(targetGroup->GroupID)) {
		this->groupChatDlgDict[targetGroup->GroupID]->Focus();
	} else {
		OuSns::GroupChatDlg^ groupChatDlg = gcnew OuSns::GroupChatDlg(this, targetGroup, this->loginUser);
		this->groupChatDlgDict[targetGroup->GroupID] = groupChatDlg;
		if (this->msgsByGroup->ContainsKey(targetGroup->GroupID)) {
			if (this->msgsByGroup[targetGroup->GroupID]->Count > 0) {
				NewMessageDelegate ^ msgDelegate = gcnew NewMessageDelegate(this->groupChatDlgDict[targetGroup->GroupID], 
					&GroupChatDlg::PushNewMessage);

				// Push messages onto the window.
				for each (ChatMessage^ m in this->msgsByGroup[targetGroup->GroupID]) {
					array<Object ^>^ args = {m};
					this->Invoke(msgDelegate, args);
					this->pendingGroupMsgTotal -= 1;
					this->pendingCountsByGroup[targetGroup->GroupID] -= 1;
				}

				// Clear the unread message queue.
				int i = 0;
				int num_msgs_to_remove = this->msgsByGroup[targetGroup->GroupID]->Count;
				while (i < num_msgs_to_remove) {
					this->msgsByGroup[targetGroup->GroupID]->RemoveLast();
					i += 1;
				}
				// Remove the unread message reminder from the friend icon.
				for each(DevComponents::DotNetBar::ButtonItem^ i in this->myGroupListSideBarPanelItem->SubItems){
					if (i->Name->Substring(11) == targetGroup->GroupID.ToString()) {
						i->Text = targetGroup->GroupName;
						break;
					}

				}

				// Update the unread message reminders of the friend list tab and panel.
				if (this->pendingGroupMsgTotal > 0) {
					this->mainDlg->groupListTab->Text = "我的群组" + L"(" + this->pendingGroupMsgTotal.ToString() + ")";
					this->myGroupListTab->Text = "我的群组" + L"(" + pendingGroupMsgTotal.ToString() + ")";
				} else {
					this->mainDlg->groupListTab->Text = "我的群组";
					this->myGroupListTab->Text = "我的群组";
				}

			}

		}

		groupChatDlg->Show();
	}


}




System::Void GroupListTab::createGroupTabGroupTagTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e) {
	if (this->createGroupTabGroupTagTextBoxX->Text->CompareTo(L"仅限文字，字母以及数字，请以空格分隔每个关键字词") == 0){
		this->createGroupTabGroupTagTextBoxX->Text = L"";
	}
}

System::Void GroupListTab::createGroupTabSearchContactTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e) {
	if (this->createGroupTabSearchContactTextBoxX->Text->CompareTo(L"搜索联系人") == 0){
		this->createGroupTabSearchContactTextBoxX->Text = L"";
	}
}

System::Void GroupListTab::createGroupTabSearchContactTextBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	this->UpdateCreateGroupTabContactList();
}

System::Void GroupListTab::UpdateCreateGroupTabContactList(void){
	String^ keyword;
	if(this->createGroupTabSearchContactTextBoxX->Text->Length > 0 \
		&& this->createGroupTabSearchContactTextBoxX->Text->CompareTo(L"搜索联系人") != 0 ){
			keyword = this->createGroupTabSearchContactTextBoxX->Text ;
	}
	else{
		keyword = L"";
	}

	LinkedList<OusnsFriend^>^ tempFriendList = gcnew LinkedList<OusnsFriend^>();
	OusnsFriend^ tempFriend;
	DevComponents::AdvTree::Node^ node;
	bool flag;
	//Array::Copy(this->loginUser->friendListArray,tempFriendArray,this->loginUser->friendListArray->Length);
	int i;
	for(i = 0; i < this->loginUser->friendListArray->Length; i++){
		if(this->loginUser->friendListArray[i]->CommentName->Contains(keyword)||\
			this->loginUser->friendListArray[i]->UserID.ToString()->Contains(keyword) ){

				//If the user was not selected, add to the list
				//if(!this->createGroupTabMemberListAdvTree->FindNodeByName	((this->loginUser->friendListArray[i]->UserID).ToString()))
				flag = false;
				for each(node in this->createGroupTabMemberListAdvTree->Nodes){
					if(node->Name->CompareTo(this->loginUser->friendListArray[i]->UserID.ToString()) == 0)
						flag = true;
				}
				if(!flag)
					tempFriendList->AddLast(this->loginUser->friendListArray[i]);

		}
	}
	array<OusnsFriend^>^ tempFriendArray = gcnew array<OusnsFriend^>(tempFriendList->Count);
	i = 0;
	for each(tempFriend in tempFriendList){
		tempFriendArray[i] = tempFriend;
		i++;
	}
	this->createGroupTabContactListAdvTree->Nodes->Clear();
	this->createGroupTabContactListAdvTree->SuspendLayout();
	for (i = 0; i < tempFriendArray->Length;i++){
		node = gcnew DevComponents::AdvTree::Node();
		node->Name = tempFriendArray[i]->UserID.ToString();
		node->Text = tempFriendArray[i]->CommentName + "(" + tempFriendArray[i]->UserID.ToString() + ")";
		this->createGroupTabContactListAdvTree->Nodes->Add(node);
	}
	this->createGroupTabContactListAdvTree->ResumeLayout();
	this->createGroupTabContactListAdvTree->Nodes->Sort();
}

System::Void GroupListTab::createGroupTabAddMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->createGroupTabContactListAdvTree->SelectedNodes->Count){
		DevComponents::AdvTree::Node^ node;
		DevComponents::AdvTree::Node^ newNode;
		this->createGroupTabMemberListAdvTree->SuspendLayout();
		for each (node in this->createGroupTabContactListAdvTree->SelectedNodes){
			newNode = gcnew DevComponents::AdvTree::Node();
			newNode->Name = node->Name;
			newNode->Text = node->Text;
			this->createGroupTabMemberListAdvTree->Nodes->Add(newNode);

		}
		this->createGroupTabMemberListAdvTree->ResumeLayout();
		this->createGroupTabMemberListAdvTree->Nodes->Sort();
		this->UpdateCreateGroupTabContactList();
	}
}

System::Void GroupListTab::createGroupTabRemoveMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->createGroupTabMemberListAdvTree->SelectedNodes->Count){
		DevComponents::AdvTree::Node^ node;
		//DevComponents::AdvTree::Node^ newNode;
		array<DevComponents::AdvTree::Node^>^ selectedNodeArray = gcnew array<DevComponents::AdvTree::Node^>(this->createGroupTabMemberListAdvTree->SelectedNodes->Count);
		this->createGroupTabMemberListAdvTree->SelectedNodes->CopyTo(selectedNodeArray);
		this->createGroupTabMemberListAdvTree->SuspendLayout();
		for each (node in selectedNodeArray){
			this->createGroupTabMemberListAdvTree->Nodes->Remove(node);
		}
		this->createGroupTabMemberListAdvTree->ResumeLayout();
		this->createGroupTabMemberListAdvTree->Nodes->Sort();
		this->UpdateCreateGroupTabContactList();
	}
}

System::Void GroupListTab::createGroupTabCreateGroupButtonX_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ groupName;
	String^ groupDescription;
	String^ groupTag;
	String^ groupCategory;
	String^ groupAnounancement;
	if(this->createGroupTabGroupNameTextBoxX->Text->CompareTo(L"") == 0){
		MessageBox::Show(CREATE_GROUP_GROUP_NAME_ERROR);
		return;
	}
	groupName = this->createGroupTabGroupNameTextBoxX->Text;
	if(this->createGroupTabGroupDescriptionTextBoxX->Text->CompareTo(L"") == 0){
		MessageBox::Show(CREATE_GROUP_GROUP_DESCRIPTION_ERROR);
		return;
	}
	groupDescription = this->createGroupTabGroupDescriptionTextBoxX->Text;

	if(this->createGroupTabGroupTagTextBoxX->Text->CompareTo(L"仅限文字，字母以及数字，请以空格分隔每个关键字词") == 0){
		//this->createGroupTabGroupTagTextBoxX->Text = L"";
		groupTag = L"";
	}
	else{
		groupTag = this->createGroupTabGroupCategoryComboBoxEx->SelectedText;
	}
	groupAnounancement = CREATE_GROUP_DEFAULT_GROUP_ANOUNANCEMENT + " " + groupName;
	LinkedList<unsigned int>^ memberList = gcnew LinkedList<unsigned int>();
	memberList->AddLast(this->loginUser->UserID);
	DevComponents::AdvTree::Node^ node;
	for each(node in this->createGroupTabMemberListAdvTree->Nodes){
		memberList->AddLast(UInt32::Parse(node->Name));
	}
	OusnsMessage^ msg = this->msgCreator->MakeCreateGroupMessage(this->loginUser->UserID, this->loginUser->SessionID,\
		groupName,groupDescription,groupCategory,groupAnounancement,groupTag,memberList);
	this->comm->AddToWorkQueue(msg);
	return;
}

System::Void GroupListTab::createGroupTabEnableControls(bool flag){
	this->superTabControlPanel26->SuspendLayout();
	this->createGroupTabGroupNameTextBoxX->Enabled = flag;
	this->createGroupTabGroupCategoryComboBoxEx->Enabled = flag;
	this->createGroupTabGroupDescriptionTextBoxX->Enabled = flag;
	this->createGroupTabGroupTagTextBoxX->Enabled = flag;
	this->createGroupTabSearchContactTextBoxX->Enabled = flag;
	this->createGroupTabContactListAdvTree->Enabled = flag;
	this->createGroupTabAddMemberButtonX->Enabled = flag;
	this->createGroupTabRemoveMemberButtonX->Enabled = flag;
	this->createGroupTabMemberListAdvTree->Enabled = flag;
	this->createGroupTabCreateGroupButtonX->Enabled = flag;
	this->superTabControlPanel26->ResumeLayout();
}


System::Void GroupListTab::exitGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	OusnsGroup ^ targetGroup = this->FindSelectedGroup();
	if(targetGroup != nullptr){
		OusnsMessage^ msg = this->msgCreator->MakeExitGroupMessage(this->loginUser->UserID,this->loginUser->SessionID,targetGroup->GroupID);
		String^ content = GROUP_LIST_EXIT_GROUP +"\n"+\
			targetGroup->GroupName +"("+ targetGroup->GroupID.ToString() \
			+ ")";
		array<String^>^ buttons = {L"确定",L"取消"};
		OuSns::NotifyUINonBlockingMsg(OuSns::QUESTION_DLG,content,buttons,msg,this->comm);
		this->comm->AddToWorkQueue(msg);
	}
}

/*
* This function will be used to find the checked button item in the friend list
*/
OusnsGroup^ GroupListTab::FindSelectedGroup(void){
	DevComponents::DotNetBar::ButtonItem^ eachButton;
	DevComponents::DotNetBar::SideBarPanelItem^ buttonParent = this->groupList->ExpandedPanel;
	OusnsGroup ^ targetGroup;
	for each( eachButton in buttonParent->SubItems){
		if (eachButton->Checked == true){
			targetGroup = this->loginUser->FindGroup(UInt32::Parse(eachButton->Name->Substring(11)));
		}
	}
	return targetGroup;
}

System::Void GroupListTab::createGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	this->superTabControl3->SuspendLayout();
	this->superTabControl3->SelectedTab = this->createGroupSuperTabItem;
	this->superTabControl3->ResumeLayout();
	//this->createGroupSuperTabItem->OnClick();
}

System::Void GroupListTab::GroupButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);
	if(button->Checked){
		OusnsGroup^ selectedGroup = this->FindSelectedGroup();
		OusnsMessage^ msg = this->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,selectedGroup->GroupID);
		this->comm->AddToWorkQueue(msg);
	}
}

System::Void GroupListTab::myGroupListTabRefreshButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	OusnsGroup^ selectedGroup = this->FindSelectedGroup();
	if(selectedGroup != nullptr){
		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeQueryGroupInformationMessage(this->loginUser->UserID, this->loginUser->SessionID,selectedGroup->GroupID);
		this->comm->AddToWorkQueue(msg);
	}
}


System::Void GroupListTab::deleteGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OusnsGroup ^ targetGroup = this->FindSelectedGroup();
	if(targetGroup != nullptr){
		OusnsMessage^ msg = this->msgCreator->MakeExitGroupMessage(this->loginUser->UserID,this->loginUser->SessionID,targetGroup->GroupID);
		String^ content = GROUP_LIST_DELETE_GROUP +"\n"+\
			targetGroup->GroupName +"("+ targetGroup->GroupID.ToString() \
			+ ")";
		array<String^>^ buttons = {L"确定",L"取消"};
		OuSns::NotifyUINonBlockingMsg(OuSns::QUESTION_DLG,content,buttons,msg,this->comm);
		this->comm->AddToWorkQueue(msg);
	}
}



/* 
*  This function will be called when there is a response for the request that the login user is querying one of his joined group information, like the group announcement.
* This function will take ONLY 1 param 
* ousnsGroup, the type is OusnsGroup. This function will dynamically cast the first element in the param to OusnsGroup type and display this group information in the UI.
*/
System::Void GroupListTab::DisplayGroupInfo(LinkedList<Object^>^ params){
	if(params->Count){
		OusnsGroup^ selectedGroup = this->FindSelectedGroup();
		if(selectedGroup != nullptr){
			OusnsGroup^ queryedGroup = dynamic_cast<OusnsGroup^>(params->First->Value);
			if(selectedGroup->GroupID == queryedGroup->GroupID){
				this->myGroupListTabGroupOuIDLabelX->Text = queryedGroup->GroupID.ToString();
				this->myGroupListTabGroupOwnerIDLabelX->Text = queryedGroup->GroupOwner->Nickname + "(" + queryedGroup->GroupOwnerID.ToString() + ")";
				this->myGroupListTabGroupOwnerIDLabelX->Name = queryedGroup->GroupOwnerID.ToString();
				this->myGroupListTabGroupNameLabelX->Text = queryedGroup->GroupName;
				this->myGroupListTabGroupCategoryLabelX->Text = queryedGroup->GroupCategory;
				this->myGroupListTabGroupDescriptionTextBoxX->Text = queryedGroup->GroupDescription;

			}
		}
	}

}

/*
* This function will update the groups that user joined to the UI
*/
System::Void GroupListTab::UpdateGroupListToUI(){
	this->myGroupListSideBarPanelItem->SubItems->Clear();
	int i;
	for (i = 0; i < this->loginUser->groupListArray->Length; i++){
		DevComponents::DotNetBar::ButtonItem^ newGroup = gcnew DevComponents::DotNetBar::ButtonItem();
		newGroup->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
		newGroup->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
		newGroup->Name = L"groupButton" + this->loginUser->groupListArray[i]->GroupID.ToString();
		newGroup->Text = this->loginUser->groupListArray[i]->GroupName;
		newGroup->DoubleClick += gcnew System::EventHandler(this, &GroupListTab::OpenGroupChatDlg);
		newGroup->Cursor = System::Windows::Forms::Cursors::Arrow;
		newGroup->CheckedChanged += gcnew System::EventHandler(this,&GroupListTab::GroupButtonItem_CheckedChanged);
		this->myGroupListSideBarPanelItem->SubItems->Add(newGroup);
	}
}


/*
* This function will be called when there is a response for the request that search specific group
* This function will dynamic cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
* Each Object represent a search result entry. 
*/
System::Void GroupListTab::DisplaySearchGroupResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults){

	if(totalResult > offset + SEARCH_RESULT_PAGE_LIMIT){
		this->searchGroupNextPageLabelX->Enabled = true;
		this->searchGroupNextPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchGroupNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchGroupNextPageLabelX->Enabled = false;
		this->searchGroupNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchGroupNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}
	if(offset > SEARCH_RESULT_PAGE_LIMIT){
		this->searchGroupPreviousPageLabelX->Enabled = true;
		this->searchGroupPreviousPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchGroupPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchGroupPreviousPageLabelX->Enabled = false;
		this->searchGroupPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchGroupPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}

	SearchResult^ searchResult;
	System::Windows::Forms::ListViewItem^  listViewItem;
	this->searchGroupOffSet = offset;
	for each (searchResult in searchResults){
		listViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {searchResult->Get("groupID"), 
			searchResult->Get("groupName"), searchResult->Get("groupDescription")}, -1));
		this->searchGroupResultList->Items->Add(listViewItem);

	}

	return;
}