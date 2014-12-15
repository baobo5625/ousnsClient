#include "stdAfx.h"
#include "MainDlg.h"
#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageCreator.h"
#include "NotifyUserDlg.h"
#include "OusnsLoginUser.h"
#include "OusnsGroup.h"
#include "OusnsFriend.h"


System::Void MainDlg::searchGroupSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
		OusnsMessage^ msg = msgCreator->MakeSearchGroupMessage(this->loginUser->userID,this->loginUser->sessionID,searchGroupIDType,keyword,0,SEARCH_RESULT_PAGE_LIMIT);
		this->comm->AddToWorkQueue(msg);
	}
}


System::Void MainDlg::joinGroupTab_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->InitializeSearchGroupSearchResult();
}

System::Void MainDlg::searchGroupOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->InitializeSearchGroupSearchResult();
}

System::Void MainDlg::searchGroupKeywordRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 this->InitializeSearchGroupSearchResult();
 }


System::Void MainDlg::InitializeSearchGroupSearchResult(void){
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


System::Void MainDlg::GroupListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
	if(sender->GetType()->Name == L"SideBarPanelItem"){
		this->openGroupDlgToolStripMenuItem->Visible = false;
		this->exitGroupToolStripMenuItem->Visible = false;
		this->deleteGroupToolStripMenuItem->Visible = false;
		this->createGroupToolStripMenuItem->Visible = true;
	}
	else{
		this->ListClickAutoCheck(sender,e);
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





System::Void MainDlg::OpenGroupChatDlg(Object^ sender, EventArgs^ e){

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
					this->groupListTab->Text = "我的群组" + L"(" + this->pendingGroupMsgTotal.ToString() + ")";
					this->myGroupListTab->Text = "我的群组" + L"(" + pendingGroupMsgTotal.ToString() + ")";
				} else {
					this->groupListTab->Text = "我的群组";
					this->myGroupListTab->Text = "我的群组";
				}

			}

		}

		groupChatDlg->Show();
	}


}



System::Void MainDlg::createGroupSuperTabItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeCreateGroupTab();
 }
System::Void MainDlg::InitializeCreateGroupTab(){
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

System::Void MainDlg::createGroupTabGroupTagTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e) {
	 if (this->createGroupTabGroupTagTextBoxX->Text->CompareTo(L"仅限文字，字母以及数字，请以空格分隔每个关键字词") == 0){
		 this->createGroupTabGroupTagTextBoxX->Text = L"";
	 }
 }

System::Void MainDlg::createGroupTabSearchContactTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e) {
	 if (this->createGroupTabSearchContactTextBoxX->Text->CompareTo(L"搜索联系人") == 0){
		 this->createGroupTabSearchContactTextBoxX->Text = L"";
	 }
 }

System::Void MainDlg::createGroupTabSearchContactTextBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	 this->UpdateCreateGroupTabContactList();
 }

System::Void MainDlg::UpdateCreateGroupTabContactList(void){
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

System::Void MainDlg::createGroupTabAddMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
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

System::Void MainDlg::createGroupTabRemoveMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
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

System::Void MainDlg::createGroupTabCreateGroupButtonX_Click(System::Object^  sender, System::EventArgs^  e) {

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

System::Void MainDlg::createGroupTabEnableControls(bool flag){
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


System::Void MainDlg::exitGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
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
OusnsGroup^ MainDlg::FindSelectedGroup(void){
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

System::Void MainDlg::createGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	this->superTabControl3->SuspendLayout();
	this->superTabControl3->SelectedTab = this->createGroupSuperTabItem;
	this->superTabControl3->ResumeLayout();
	//this->createGroupSuperTabItem->OnClick();
}

System::Void MainDlg::GroupButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);
	if(button->Checked){
		OusnsGroup^ selectedGroup = this->FindSelectedGroup();
		OusnsMessage^ msg = this->msgCreator->MakeQueryUserInfoMessage(this->loginUser->UserID,this->loginUser->SessionID,selectedGroup->GroupID);
		this->comm->AddToWorkQueue(msg);
	}
}

System::Void MainDlg::myGroupListTabRefreshButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	OusnsGroup^ selectedGroup = this->FindSelectedGroup();
	if(selectedGroup != nullptr){
		OusnsMessage^ msg = this->msgCreator->MakeQueryGroupInformationMessage(this->loginUser->UserID, this->loginUser->SessionID,selectedGroup->GroupID);
		this->comm->AddToWorkQueue(msg);
	}
}


System::Void MainDlg::deleteGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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