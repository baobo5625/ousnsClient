#include "StdAfx.h"
#include "OusnsUserInfo.h"
using namespace OuSns;
OusnsUserInfo::OusnsUserInfo(OusnsUser^ usr)
{
	InitializeComponent();
	this->usr = usr;
	//
	//TODO: �ڴ˴���ӹ��캯������
	//
	this->userNicknameLabelX->Text = this->usr->Nickname;
	this->userOuIDLabelX->Text = this->usr->UserID.ToString();
	this->signatureLabelX->Text = this->usr->Signature;
	this->sexLabelX->Text = this->usr->Sex;
	
	this->birthdayLabelX->Text = this->usr->BirthMonth.ToString() + "��" + this->usr->BirthDay + "��";
	int age = DateTime::Now.Year - this->usr->BirthYear;
	this->ageLabelX->Text = age.ToString();
	this->zodiacLabelX->Text = this->usr->Zodiac;
	this->emailLabelX->Text = this->usr->Email;
	this->countryLabelX->Text = this->usr->Country;
	this->provinceLabelX->Text = this->usr->Province;
	this->cityLabelX->Text = this->usr->City;
}