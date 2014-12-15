#include "stdAfx.h"
#include "MainDlg1.h"
#include "PersonalSettingTab.h"


System::Void MainDlg::personalSettingTab_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->newPersonalSettingTab == nullptr){
		this->newPersonalSettingTab = gcnew OuSns::PersonalSettingTab(this);
		this->newPersonalSettingTab->TopLevel = false;
		this->newPersonalSettingTab->Parent = this;
		this->superTabControlPanel8->Controls->Add(this->newPersonalSettingTab);
	}
	this->newPersonalSettingTab->Show();
}

