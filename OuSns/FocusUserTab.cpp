#include "StdAfx.h"
#include "FocusUserTab.h"
#include "OusnsLoginUser.h"
#include "OusnsFocusUser.h"
#include "OusnsGroup.h"
#include "MainDlg1.h"
#include "MessageCreator.h"
#include "Communication.h"
#include "NotifyUserDlg.h"

FocusUserTab::FocusUserTab(MainDlg^ mainDlgInput,OusnsLoginUser^ loginUserInput)
{
	InitializeComponent();
	
	//
	//TODO: 在此处添加构造函数代码
	//
	this->mainDlg = mainDlgInput;
	this->loginUser = loginUserInput;
	this->searchGroupOffSet = 0;
	this->searchUserOffset= 0;
}
System::Void FocusUserTab::UpdateFocusUserListToUI(){
	this->focusUserSideBarPanelItem->SubItems->Clear();
	int i;
	for (i = 0; i < this->loginUser->focusUserListArray->Length; i++){
		DevComponents::DotNetBar::ButtonItem^ newFocusUser = gcnew DevComponents::DotNetBar::ButtonItem();
		newFocusUser->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
		newFocusUser->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
		newFocusUser->Name = L"focusUserButton" + this->loginUser->focusUserListArray[i]->UserID.ToString();
		newFocusUser->Text = this->loginUser->focusUserListArray[i]->Nickname;
		//newFocusUser->DoubleClick += gcnew System::EventHandler(this, &FocusUserTab::OpenGroupChatDlg);
		newFocusUser->Cursor = System::Windows::Forms::Cursors::Arrow;
		//newFocusUser->CheckedChanged += gcnew System::EventHandler(this,&FocusUserTab::GroupButtonItem_CheckedChanged);
		this->focusUserSideBarPanelItem->SubItems->Add(newFocusUser);
	}
}

System::Void FocusUserTab::UpdateFocusGroupListToUI(){
	this->focusGroupSideBarPanelItem->SubItems->Clear();
	int i;
	for (i = 0; i < this->loginUser->focusGroupListArray->Length; i++){
		DevComponents::DotNetBar::ButtonItem^ newFocusGroup = gcnew DevComponents::DotNetBar::ButtonItem();
		newFocusGroup->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
		newFocusGroup->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
		newFocusGroup->Name = L"focusGroupButton" + this->loginUser->focusGroupListArray[i]->GroupID.ToString();
		newFocusGroup->Text = this->loginUser->focusGroupListArray[i]->GroupName;
		//newFocusGroup->DoubleClick += gcnew System::EventHandler(this, &FocusUserTab::OpenGroupChatDlg);
		newFocusGroup->Cursor = System::Windows::Forms::Cursors::Arrow;
		//newFocusGroup->CheckedChanged += gcnew System::EventHandler(this,&FocusUserTab::GroupButtonItem_CheckedChanged);
		this->focusGroupSideBarPanelItem->SubItems->Add(newFocusGroup);
	}
}

System::Void FocusUserTab::addGroupFocusSearchButtonX_Click(System::Object^  sender, System::EventArgs^  e) {

 }
System::Void FocusUserTab::addGroupFocusPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
	int searchGroupIDType;
	if(groupIDRadioButton->Checked){
		searchGroupIDType = 0;
	}/*
	else if (groupKeywordRadioButton->Checked){
		searchGroupIDType = 1;
	}
	*/
	else{
		searchGroupIDType = 2;
	}
	String^ keyword = this->addGroupFocusKeywordTextBoxX->Text;
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchGroupMessage(this->loginUser->userID,this->loginUser->sessionID,searchGroupIDType,keyword,this->searchGroupOffSet - SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->mainDlg->comm->AddToWorkQueue(msg);
}
System::Void FocusUserTab::addGroupFocusNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
}
System::Void FocusUserTab::addGroupFocusAddButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
}

System::Void FocusUserTab::ouIDRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchUserIDColumnHeader->Text = L"OuID";
	this->searchUserInfoColumnHeader->Text = L"昵称";
	this->InitializeSearchUserSearchResult();

}
System::Void FocusUserTab::emailRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchUserIDColumnHeader->Text = L"Email";
	this->searchUserInfoColumnHeader->Text = L"昵称";
	this->InitializeSearchUserSearchResult();
}
System::Void FocusUserTab::nicknameRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchUserIDColumnHeader->Text = L"昵称";
	this->searchUserInfoColumnHeader->Text = L"OuID";
	this->InitializeSearchUserSearchResult();
}
System::Void FocusUserTab::addUserFocusSearchButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	this->InitializeSearchUserSearchResult();
	if(this->addUserFocusKeywordTextBoxX->Text->Length == 0){
		NotifyUserDlg^ dlg = gcnew NotifyUserDlg(OuSns::ERROR_DLG,L"确定",SEARCH_ERROR_NOTIFICATION);
	}
	else{
		int searchUserIDType;
		if(ouIDRadioButton->Checked){
			searchUserIDType = 0;
		}
		else if (emailRadioButton->Checked){
			searchUserIDType = 1;
		}
		else{
			searchUserIDType = 2;
		}
		String^ keyword = this->addUserFocusKeywordTextBoxX->Text;
		OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,0,SEARCH_RESULT_PAGE_LIMIT);
		this->mainDlg->comm->AddToWorkQueue(msg);
	}
}
System::Void FocusUserTab::addUserFocusPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
	int searchUserIDType;
	if(ouIDRadioButton->Checked){
		searchUserIDType = 0;
	}
	else if (emailRadioButton->Checked){
		searchUserIDType = 1;
	}
	else{
		searchUserIDType = 2;
	}
	String^ keyword = this->addUserFocusKeywordTextBoxX->Text;
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchUserOffset - SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->mainDlg->comm->AddToWorkQueue(msg);
}
System::Void FocusUserTab::addUserFocusNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
	int searchUserIDType;
	if(ouIDRadioButton->Checked){
		searchUserIDType = 0;
	}
	else if (emailRadioButton->Checked){
		searchUserIDType = 1;
	}
	else{
		searchUserIDType = 2;
	}
	String^ keyword = this->addUserFocusKeywordTextBoxX->Text;
	OusnsMessage^ msg = this->mainDlg->msgCreator->MakeSearchFriendMessage(this->loginUser->userID,this->loginUser->sessionID,searchUserIDType,keyword,this->searchUserOffset + SEARCH_RESULT_PAGE_LIMIT,SEARCH_RESULT_PAGE_LIMIT);
	this->mainDlg->comm->AddToWorkQueue(msg);
}
System::Void FocusUserTab::addUserFocusAddButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
}

System::Void FocusUserTab::InitializeSearchUserSearchResult(){
	this->addUserFocusSearchResultListViewEx->Items->Clear();
	this->addUserFocusPreviousPageLabelX->Enabled = false;
	this->addUserFocusPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->addUserFocusPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->addUserFocusNextPageLabelX->Enabled = false;
	this->addUserFocusNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->addUserFocusNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->addUserFocusAddButtonX->Enabled = false;
	//this->searchFriendInputBox->Text = L"";

}

System::Void FocusUserTab::InitializeSearchGroupSearchResult(){
	this->addGroupFocusListViewEx->Items->Clear();
	this->addGroupFocusPreviousPageLabelX->Enabled = false;
	this->addGroupFocusPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->addGroupFocusPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->addGroupFocusNextPageLabelX->Enabled = false;
	this->addGroupFocusNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	this->addGroupFocusNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
	this->addGroupFocusAddButtonX->Enabled = false;
	//this->searchFriendInputBox->Text = L"";

}

System::Void FocusUserTab::AddFocusGroupSuperTabItem_ExpandChange(System::Object^  sender, System::EventArgs^  e) {
	if(this->AddFocusGroupSuperTabItem->Expanded)
		this->InitializeSearchGroupSearchResult();
}
System::Void FocusUserTab::AddUserFocusSuperTabItem_ExpandChange(System::Object^  sender, System::EventArgs^  e) {
	if(this->AddUserFocusSuperTabItem->Expanded)
		this->InitializeSearchUserSearchResult();
}