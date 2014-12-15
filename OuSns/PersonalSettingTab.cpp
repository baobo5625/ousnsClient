#include "StdAfx.h"
#include "PersonalSettingTab.h"
#include "MainDlg1.h"
#include "OusnsLoginUser.h"

PersonalSettingTab::PersonalSettingTab(MainDlg^ mainDlg)
{
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//
	this->mainDlg = mainDlg;
	this->superTabControl4->SuspendLayout();
	DevComponents::Editors::ComboItem^  comboItem;
	DateTime^ now = DateTime::Today;
	int i;
	for(i = 1900;i<= now->Year;i++){
		comboItem = (gcnew DevComponents::Editors::ComboItem());
		comboItem->Text = i.ToString();
		this->personalInformationSettingBirthdayYearComboBoxEx->Items->Add(comboItem);
	}
	for(i = 1;i<=12;i++){
		comboItem = (gcnew DevComponents::Editors::ComboItem());
		comboItem->Text = i.ToString();
		this->personalInformationSettingBirthdayMonthComboBoxEx->Items->Add(comboItem);
	}

	for(i = 1;i<=31;i++){
		comboItem = (gcnew DevComponents::Editors::ComboItem());
		comboItem->Text = i.ToString();
		this->personalInformationSettingBirthdayDayComboBoxEx->Items->Add(comboItem);
	}
	this->superTabControl4->ResumeLayout(false);
}
System::Void PersonalSettingTab::personalInformationSettingBirthdayMonthComboBoxEx_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->RefreshPersonalSettingTabBirthdayDayComboBox();
}

System::Void PersonalSettingTab::personalInformationSettingBirthdayYearComboBoxEx_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->RefreshPersonalSettingTabBirthdayDayComboBox();
}



System::Void PersonalSettingTab::RefreshPersonalSettingTabBirthdayDayComboBox(void){
	if(this->personalInformationSettingBirthdayMonthComboBoxEx->SelectedIndex != -1 &&
		this->personalInformationSettingBirthdayYearComboBoxEx->SelectedIndex != -1){
			int monthValue =  this->personalInformationSettingBirthdayMonthComboBoxEx->SelectedIndex + 1;
			int yearValue = this->personalInformationSettingBirthdayYearComboBoxEx->SelectedIndex + 1900;
			int dayValue = DateTime::DaysInMonth(yearValue,monthValue);
			this->personalInformationSettingBirthdayDayComboBoxEx->Items->Clear();

			int i;

			DevComponents::Editors::ComboItem^  comboItem;
			for(i = 1;i<=31;i++){
				comboItem = (gcnew DevComponents::Editors::ComboItem());
				comboItem->Text = i.ToString();
				this->personalInformationSettingBirthdayDayComboBoxEx->Items->Add(comboItem);
			}
	}

}


System::Void PersonalSettingTab::UpdatePersonalSettingTabInfo(void){
	this->superTabControl4->SuspendLayout();
	this->personalInformationSettingOuIDLabel->Text = this->mainDlg->loginUser->userID.ToString();
	this->personalInformationSettingEmailIDLabel->Text = this->mainDlg->loginUser->emailID;
	this->personalInformationSettingEmailTextBoxX->Text = this->mainDlg->loginUser->email;
	this->personalInformationSettingNicknameTextBoxX->Text = this->mainDlg->loginUser->nickname;
	this->personalInformationSettingSignatureTextBoxX->Text = this->mainDlg->loginUser->signature;
	this->personalInformationSettingSexComboBoxEx->SelectedIndex = this->mainDlg->loginUser->SexInt;
	this->personalInformationSettingZodiacComboBoxX->SelectedIndex = this->mainDlg->loginUser->ZodiacInt;

	this->personalInformationSettingBirthdayYearComboBoxEx->SelectedIndex = this->mainDlg->loginUser->birthYear - 1900;
	this->personalInformationSettingBirthdayMonthComboBoxEx->SelectedIndex = this->mainDlg->loginUser->birthMonth - 1;
	this->personalInformationSettingBirthdayDayComboBoxEx->SelectedIndex = this->mainDlg->loginUser->birthDay - 1;

	this->personalInformationSettingProvinceTextBoxX->Text =this->mainDlg->loginUser->province;
	this->personalInformationSettingCityTextBoxX->Text =this->mainDlg->loginUser->city;
	this->personalInformationSettingCountryTextBoxX->Text =this->mainDlg->loginUser->country;	
	Bitmap^ myImage;
	if(this->mainDlg->loginUser->displayPictureFilename != L""){
		myImage = gcnew Bitmap(OUSNS_FILE_PATH+"\\" +this->mainDlg->loginUser->displayPictureFilename);
		this->personalInformationSettingDisplayPicturePictureBox->Image = dynamic_cast<Image^>(myImage);
	}
	this->superTabControl4->ResumeLayout(false);

}
