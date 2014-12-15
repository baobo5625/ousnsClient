#include "stdafx.h"
#include "OusnsUser.h"

#pragma once
/*
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
*/

namespace OuSns {

	/// <summary>
	/// OusnsUserInfo 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class OusnsUserInfo : DevComponents::DotNetBar::Office2007Form
	{
	public:
		OusnsUser^ usr;
	public:
		//OusnsUserInfo(void)
		OusnsUserInfo(OusnsUser^ usr);
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~OusnsUserInfo()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl1;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel1;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem2;
	private: DevComponents::DotNetBar::LabelItem^  labelItem3;
	private: DevComponents::DotNetBar::LabelItem^  labelItem4;
	private: DevComponents::DotNetBar::LabelX^  userOuIDLabelX;
	private: DevComponents::DotNetBar::LabelX^  userNicknameLabelX;
	private: DevComponents::DotNetBar::LabelX^  signatureTitleLabelX;





	private: DevComponents::DotNetBar::LabelX^  basicInformationLabelX;
	private: DevComponents::DotNetBar::LabelX^  signatureLabelX;

	private: DevComponents::DotNetBar::LabelX^  emailLabelX;

	private: DevComponents::DotNetBar::LabelX^  emailTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  cityLabelX;


	private: DevComponents::DotNetBar::LabelX^  myFriendListTabCityTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  provinceLabelX;

	private: DevComponents::DotNetBar::LabelX^  myFriendListTabProvinceTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  countryLabelX;

	private: DevComponents::DotNetBar::LabelX^  countryTitleLabelX;

	private: DevComponents::DotNetBar::LabelX^  zodiacLabelX;

	private: DevComponents::DotNetBar::LabelX^  zodiacTitleLabelX;

	private: DevComponents::DotNetBar::LabelX^  birthdayLabelX;

	private: DevComponents::DotNetBar::LabelX^  birthdayTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  ageLabelX;


	private: DevComponents::DotNetBar::LabelX^  sexLabelX;
	private: DevComponents::DotNetBar::LabelX^  ageTitleLabelX;


	private: DevComponents::DotNetBar::LabelX^  sexTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  labelX2;
	private: DevComponents::DotNetBar::LabelX^  focusCounterLabelX;


	private: DevComponents::DotNetBar::LabelX^  focusCounterTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  sharingFileCounterLabelX;
	private: DevComponents::DotNetBar::LabelX^  sharingFileCounterTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  sharingFileSizeLabelX;
	private: DevComponents::DotNetBar::LabelX^  sharingFileSizeTitleLabelX;










	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->superTabControl1 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel1 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->sharingFileSizeLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->sharingFileSizeTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->sharingFileCounterLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->sharingFileCounterTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->focusCounterLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->focusCounterTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX2 = (gcnew DevComponents::DotNetBar::LabelX());
			this->emailLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->emailTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->cityLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabCityTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->provinceLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabProvinceTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->countryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->countryTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->zodiacLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->zodiacTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->birthdayLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->birthdayTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->ageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->sexLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->ageTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->sexTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->basicInformationLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->signatureLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->signatureTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->userOuIDLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->userNicknameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->superTabItem1 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->labelItem1 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem2 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem3 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem4 = (gcnew DevComponents::DotNetBar::LabelItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->BeginInit();
			this->superTabControl1->SuspendLayout();
			this->superTabControlPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 80);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// superTabControl1
			// 
			this->superTabControl1->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl1->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl1->ControlBox->MenuBox->Name = L"";
			this->superTabControl1->ControlBox->Name = L"";
			this->superTabControl1->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl1->ControlBox->MenuBox, 
				this->superTabControl1->ControlBox->CloseBox});
			this->superTabControl1->ControlBox->Visible = false;
			this->superTabControl1->Controls->Add(this->superTabControlPanel1);
			this->superTabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl1->FixedTabSize = System::Drawing::Size(100, 25);
			this->superTabControl1->Location = System::Drawing::Point(0, 0);
			this->superTabControl1->Name = L"superTabControl1";
			this->superTabControl1->ReorderTabsEnabled = false;
			this->superTabControl1->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl1->SelectedTabIndex = 4;
			this->superTabControl1->Size = System::Drawing::Size(558, 415);
			this->superTabControl1->TabAlignment = DevComponents::DotNetBar::eTabStripAlignment::Left;
			this->superTabControl1->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl1->TabIndex = 2;
			this->superTabControl1->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(5) {this->labelItem1, this->labelItem2, 
				this->labelItem3, this->labelItem4, this->superTabItem1});
			this->superTabControl1->TabVerticalSpacing = 0;
			this->superTabControl1->Text = L"superTabControl1";
			this->superTabControl1->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel1
			// 
			this->superTabControlPanel1->Controls->Add(this->sharingFileSizeLabelX);
			this->superTabControlPanel1->Controls->Add(this->sharingFileSizeTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->sharingFileCounterLabelX);
			this->superTabControlPanel1->Controls->Add(this->sharingFileCounterTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->focusCounterLabelX);
			this->superTabControlPanel1->Controls->Add(this->focusCounterTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->labelX2);
			this->superTabControlPanel1->Controls->Add(this->emailLabelX);
			this->superTabControlPanel1->Controls->Add(this->emailTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->cityLabelX);
			this->superTabControlPanel1->Controls->Add(this->myFriendListTabCityTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->provinceLabelX);
			this->superTabControlPanel1->Controls->Add(this->myFriendListTabProvinceTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->countryLabelX);
			this->superTabControlPanel1->Controls->Add(this->countryTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->zodiacLabelX);
			this->superTabControlPanel1->Controls->Add(this->zodiacTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->birthdayLabelX);
			this->superTabControlPanel1->Controls->Add(this->birthdayTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->ageLabelX);
			this->superTabControlPanel1->Controls->Add(this->sexLabelX);
			this->superTabControlPanel1->Controls->Add(this->ageTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->sexTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->basicInformationLabelX);
			this->superTabControlPanel1->Controls->Add(this->signatureLabelX);
			this->superTabControlPanel1->Controls->Add(this->signatureTitleLabelX);
			this->superTabControlPanel1->Controls->Add(this->userOuIDLabelX);
			this->superTabControlPanel1->Controls->Add(this->userNicknameLabelX);
			this->superTabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel1->Location = System::Drawing::Point(102, 0);
			this->superTabControlPanel1->Name = L"superTabControlPanel1";
			this->superTabControlPanel1->Size = System::Drawing::Size(456, 415);
			this->superTabControlPanel1->TabIndex = 1;
			this->superTabControlPanel1->TabItem = this->superTabItem1;
			// 
			// sharingFileSizeLabelX
			// 
			this->sharingFileSizeLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sharingFileSizeLabelX->BackgroundStyle->Class = L"";
			this->sharingFileSizeLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sharingFileSizeLabelX->Location = System::Drawing::Point(178, 323);
			this->sharingFileSizeLabelX->Name = L"sharingFileSizeLabelX";
			this->sharingFileSizeLabelX->Size = System::Drawing::Size(13, 16);
			this->sharingFileSizeLabelX->TabIndex = 44;
			this->sharingFileSizeLabelX->Text = L"-";
			// 
			// sharingFileSizeTitleLabelX
			// 
			this->sharingFileSizeTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sharingFileSizeTitleLabelX->BackgroundStyle->Class = L"";
			this->sharingFileSizeTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sharingFileSizeTitleLabelX->Location = System::Drawing::Point(24, 321);
			this->sharingFileSizeTitleLabelX->Name = L"sharingFileSizeTitleLabelX";
			this->sharingFileSizeTitleLabelX->Size = System::Drawing::Size(149, 18);
			this->sharingFileSizeTitleLabelX->TabIndex = 43;
			this->sharingFileSizeTitleLabelX->Text = L"他/她分享的文件总大小：";
			// 
			// sharingFileCounterLabelX
			// 
			this->sharingFileCounterLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sharingFileCounterLabelX->BackgroundStyle->Class = L"";
			this->sharingFileCounterLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sharingFileCounterLabelX->Location = System::Drawing::Point(165, 287);
			this->sharingFileCounterLabelX->Name = L"sharingFileCounterLabelX";
			this->sharingFileCounterLabelX->Size = System::Drawing::Size(13, 16);
			this->sharingFileCounterLabelX->TabIndex = 42;
			this->sharingFileCounterLabelX->Text = L"-";
			// 
			// sharingFileCounterTitleLabelX
			// 
			this->sharingFileCounterTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sharingFileCounterTitleLabelX->BackgroundStyle->Class = L"";
			this->sharingFileCounterTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sharingFileCounterTitleLabelX->Location = System::Drawing::Point(24, 286);
			this->sharingFileCounterTitleLabelX->Name = L"sharingFileCounterTitleLabelX";
			this->sharingFileCounterTitleLabelX->Size = System::Drawing::Size(136, 18);
			this->sharingFileCounterTitleLabelX->TabIndex = 41;
			this->sharingFileCounterTitleLabelX->Text = L"他/她分享的文件个数：";
			// 
			// focusCounterLabelX
			// 
			this->focusCounterLabelX->AutoSize = true;
			// 
			// 
			// 
			this->focusCounterLabelX->BackgroundStyle->Class = L"";
			this->focusCounterLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->focusCounterLabelX->Location = System::Drawing::Point(129, 256);
			this->focusCounterLabelX->Name = L"focusCounterLabelX";
			this->focusCounterLabelX->Size = System::Drawing::Size(13, 16);
			this->focusCounterLabelX->TabIndex = 40;
			this->focusCounterLabelX->Text = L"-";
			// 
			// focusCounterTitleLabelX
			// 
			this->focusCounterTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->focusCounterTitleLabelX->BackgroundStyle->Class = L"";
			this->focusCounterTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->focusCounterTitleLabelX->Location = System::Drawing::Point(24, 255);
			this->focusCounterTitleLabelX->Name = L"focusCounterTitleLabelX";
			this->focusCounterTitleLabelX->Size = System::Drawing::Size(99, 18);
			this->focusCounterTitleLabelX->TabIndex = 39;
			this->focusCounterTitleLabelX->Text = L"关注他/她的人：";
			// 
			// labelX2
			// 
			this->labelX2->AutoSize = true;
			// 
			// 
			// 
			this->labelX2->BackgroundStyle->Class = L"";
			this->labelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->labelX2->Location = System::Drawing::Point(20, 225);
			this->labelX2->Name = L"labelX2";
			this->labelX2->Size = System::Drawing::Size(82, 23);
			this->labelX2->TabIndex = 38;
			this->labelX2->Text = L"飞享统计:";
			// 
			// emailLabelX
			// 
			this->emailLabelX->AutoSize = true;
			// 
			// 
			// 
			this->emailLabelX->BackgroundStyle->Class = L"";
			this->emailLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->emailLabelX->Location = System::Drawing::Point(215, 151);
			this->emailLabelX->Name = L"emailLabelX";
			this->emailLabelX->Size = System::Drawing::Size(13, 16);
			this->emailLabelX->TabIndex = 37;
			this->emailLabelX->Text = L"-";
			// 
			// emailTitleLabelX
			// 
			this->emailTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->emailTitleLabelX->BackgroundStyle->Class = L"";
			this->emailTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->emailTitleLabelX->Location = System::Drawing::Point(165, 151);
			this->emailTitleLabelX->Name = L"emailTitleLabelX";
			this->emailTitleLabelX->Size = System::Drawing::Size(50, 18);
			this->emailTitleLabelX->TabIndex = 36;
			this->emailTitleLabelX->Text = L"Email：";
			// 
			// cityLabelX
			// 
			this->cityLabelX->AutoSize = true;
			// 
			// 
			// 
			this->cityLabelX->BackgroundStyle->Class = L"";
			this->cityLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->cityLabelX->Location = System::Drawing::Point(409, 178);
			this->cityLabelX->Name = L"cityLabelX";
			this->cityLabelX->Size = System::Drawing::Size(13, 16);
			this->cityLabelX->TabIndex = 35;
			this->cityLabelX->Text = L"-";
			// 
			// myFriendListTabCityTitleLabelX
			// 
			this->myFriendListTabCityTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabCityTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabCityTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabCityTitleLabelX->Location = System::Drawing::Point(339, 178);
			this->myFriendListTabCityTitleLabelX->Name = L"myFriendListTabCityTitleLabelX";
			this->myFriendListTabCityTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabCityTitleLabelX->TabIndex = 34;
			this->myFriendListTabCityTitleLabelX->Text = L"城    市：";
			// 
			// provinceLabelX
			// 
			this->provinceLabelX->AutoSize = true;
			// 
			// 
			// 
			this->provinceLabelX->BackgroundStyle->Class = L"";
			this->provinceLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->provinceLabelX->Location = System::Drawing::Point(241, 178);
			this->provinceLabelX->Name = L"provinceLabelX";
			this->provinceLabelX->Size = System::Drawing::Size(13, 16);
			this->provinceLabelX->TabIndex = 33;
			this->provinceLabelX->Text = L"-";
			// 
			// myFriendListTabProvinceTitleLabelX
			// 
			this->myFriendListTabProvinceTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabProvinceTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabProvinceTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabProvinceTitleLabelX->Location = System::Drawing::Point(165, 178);
			this->myFriendListTabProvinceTitleLabelX->Name = L"myFriendListTabProvinceTitleLabelX";
			this->myFriendListTabProvinceTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabProvinceTitleLabelX->TabIndex = 32;
			this->myFriendListTabProvinceTitleLabelX->Text = L"省    份：";
			// 
			// countryLabelX
			// 
			this->countryLabelX->AutoSize = true;
			// 
			// 
			// 
			this->countryLabelX->BackgroundStyle->Class = L"";
			this->countryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->countryLabelX->Location = System::Drawing::Point(97, 178);
			this->countryLabelX->Name = L"countryLabelX";
			this->countryLabelX->Size = System::Drawing::Size(13, 16);
			this->countryLabelX->TabIndex = 31;
			this->countryLabelX->Text = L"-";
			// 
			// countryTitleLabelX
			// 
			this->countryTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->countryTitleLabelX->BackgroundStyle->Class = L"";
			this->countryTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->countryTitleLabelX->Location = System::Drawing::Point(24, 178);
			this->countryTitleLabelX->Name = L"countryTitleLabelX";
			this->countryTitleLabelX->Size = System::Drawing::Size(74, 18);
			this->countryTitleLabelX->TabIndex = 30;
			this->countryTitleLabelX->Text = L"国家/地区：";
			// 
			// zodiacLabelX
			// 
			this->zodiacLabelX->AutoSize = true;
			// 
			// 
			// 
			this->zodiacLabelX->BackgroundStyle->Class = L"";
			this->zodiacLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->zodiacLabelX->Location = System::Drawing::Point(97, 151);
			this->zodiacLabelX->Name = L"zodiacLabelX";
			this->zodiacLabelX->Size = System::Drawing::Size(13, 16);
			this->zodiacLabelX->TabIndex = 29;
			this->zodiacLabelX->Text = L"-";
			// 
			// zodiacTitleLabelX
			// 
			this->zodiacTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->zodiacTitleLabelX->BackgroundStyle->Class = L"";
			this->zodiacTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->zodiacTitleLabelX->Location = System::Drawing::Point(24, 151);
			this->zodiacTitleLabelX->Name = L"zodiacTitleLabelX";
			this->zodiacTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->zodiacTitleLabelX->TabIndex = 28;
			this->zodiacTitleLabelX->Text = L"星    座：";
			// 
			// birthdayLabelX
			// 
			this->birthdayLabelX->AutoSize = true;
			// 
			// 
			// 
			this->birthdayLabelX->BackgroundStyle->Class = L"";
			this->birthdayLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->birthdayLabelX->Location = System::Drawing::Point(239, 120);
			this->birthdayLabelX->Name = L"birthdayLabelX";
			this->birthdayLabelX->Size = System::Drawing::Size(44, 18);
			this->birthdayLabelX->TabIndex = 27;
			this->birthdayLabelX->Text = L"-月-日";
			// 
			// birthdayTitleLabelX
			// 
			this->birthdayTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->birthdayTitleLabelX->BackgroundStyle->Class = L"";
			this->birthdayTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->birthdayTitleLabelX->Location = System::Drawing::Point(165, 121);
			this->birthdayTitleLabelX->Name = L"birthdayTitleLabelX";
			this->birthdayTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->birthdayTitleLabelX->TabIndex = 26;
			this->birthdayTitleLabelX->Text = L"生    日：";
			// 
			// ageLabelX
			// 
			this->ageLabelX->AutoSize = true;
			// 
			// 
			// 
			this->ageLabelX->BackgroundStyle->Class = L"";
			this->ageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->ageLabelX->Location = System::Drawing::Point(409, 122);
			this->ageLabelX->Name = L"ageLabelX";
			this->ageLabelX->Size = System::Drawing::Size(13, 16);
			this->ageLabelX->TabIndex = 25;
			this->ageLabelX->Text = L"1";
			// 
			// sexLabelX
			// 
			this->sexLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sexLabelX->BackgroundStyle->Class = L"";
			this->sexLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sexLabelX->Location = System::Drawing::Point(97, 122);
			this->sexLabelX->Name = L"sexLabelX";
			this->sexLabelX->Size = System::Drawing::Size(13, 16);
			this->sexLabelX->TabIndex = 24;
			this->sexLabelX->Text = L"-";
			// 
			// ageTitleLabelX
			// 
			this->ageTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->ageTitleLabelX->BackgroundStyle->Class = L"";
			this->ageTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->ageTitleLabelX->Location = System::Drawing::Point(339, 121);
			this->ageTitleLabelX->Name = L"ageTitleLabelX";
			this->ageTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->ageTitleLabelX->TabIndex = 23;
			this->ageTitleLabelX->Text = L"年    龄：";
			// 
			// sexTitleLabelX
			// 
			this->sexTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->sexTitleLabelX->BackgroundStyle->Class = L"";
			this->sexTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sexTitleLabelX->Location = System::Drawing::Point(24, 121);
			this->sexTitleLabelX->Name = L"sexTitleLabelX";
			this->sexTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->sexTitleLabelX->TabIndex = 22;
			this->sexTitleLabelX->Text = L"性    别：";
			// 
			// basicInformationLabelX
			// 
			this->basicInformationLabelX->AutoSize = true;
			// 
			// 
			// 
			this->basicInformationLabelX->BackgroundStyle->Class = L"";
			this->basicInformationLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->basicInformationLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->basicInformationLabelX->Location = System::Drawing::Point(20, 96);
			this->basicInformationLabelX->Name = L"basicInformationLabelX";
			this->basicInformationLabelX->Size = System::Drawing::Size(82, 23);
			this->basicInformationLabelX->TabIndex = 6;
			this->basicInformationLabelX->Text = L"基本资料:";
			// 
			// signatureLabelX
			// 
			this->signatureLabelX->AutoSize = true;
			// 
			// 
			// 
			this->signatureLabelX->BackgroundStyle->Class = L"";
			this->signatureLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->signatureLabelX->Location = System::Drawing::Point(94, 60);
			this->signatureLabelX->Name = L"signatureLabelX";
			this->signatureLabelX->Size = System::Drawing::Size(99, 16);
			this->signatureLabelX->TabIndex = 5;
			this->signatureLabelX->Text = L"signatureLabelX";
			// 
			// signatureTitleLabelX
			// 
			this->signatureTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->signatureTitleLabelX->BackgroundStyle->Class = L"";
			this->signatureTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->signatureTitleLabelX->Location = System::Drawing::Point(20, 59);
			this->signatureTitleLabelX->Name = L"signatureTitleLabelX";
			this->signatureTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->signatureTitleLabelX->TabIndex = 4;
			this->signatureTitleLabelX->Text = L"个性签名：";
			// 
			// userOuIDLabelX
			// 
			this->userOuIDLabelX->AutoSize = true;
			// 
			// 
			// 
			this->userOuIDLabelX->BackgroundStyle->Class = L"";
			this->userOuIDLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->userOuIDLabelX->Location = System::Drawing::Point(20, 37);
			this->userOuIDLabelX->Name = L"userOuIDLabelX";
			this->userOuIDLabelX->Size = System::Drawing::Size(31, 16);
			this->userOuIDLabelX->TabIndex = 1;
			this->userOuIDLabelX->Text = L"OuID";
			// 
			// userNicknameLabelX
			// 
			this->userNicknameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->userNicknameLabelX->BackgroundStyle->Class = L"";
			this->userNicknameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->userNicknameLabelX->Location = System::Drawing::Point(20, 14);
			this->userNicknameLabelX->Name = L"userNicknameLabelX";
			this->userNicknameLabelX->Size = System::Drawing::Size(31, 18);
			this->userNicknameLabelX->TabIndex = 0;
			this->userNicknameLabelX->Text = L"昵称";
			// 
			// superTabItem1
			// 
			this->superTabItem1->AttachedControl = this->superTabControlPanel1;
			this->superTabItem1->Category = L"property1";
			this->superTabItem1->CloseButtonVisible = false;
			this->superTabItem1->GlobalItem = false;
			this->superTabItem1->Name = L"superTabItem1";
			this->superTabItem1->Text = L"个人资料";
			// 
			// labelItem1
			// 
			this->labelItem1->Name = L"labelItem1";
			// 
			// labelItem2
			// 
			this->labelItem2->Name = L"labelItem2";
			// 
			// labelItem3
			// 
			this->labelItem3->Name = L"labelItem3";
			// 
			// labelItem4
			// 
			this->labelItem4->Name = L"labelItem4";
			// 
			// OusnsUserInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 415);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->superTabControl1);
			this->MaximizeBox = false;
			this->Name = L"OusnsUserInfo";
			this->Text = L"OusnsUserInfo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->EndInit();
			this->superTabControl1->ResumeLayout(false);
			this->superTabControlPanel1->ResumeLayout(false);
			this->superTabControlPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
