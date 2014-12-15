#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// PersonalSettingTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	public ref class PersonalSettingTab : public System::Windows::Forms::Form
	{
	public:
		MainDlg^ mainDlg;
		PersonalSettingTab(MainDlg^ mainDlg);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~PersonalSettingTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl4;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel23;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingPSTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingPSTitleLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  personalInformationSettingZodiacComboBoxX;
	private: DevComponents::Editors::ComboItem^  comboItem11;
	private: DevComponents::Editors::ComboItem^  comboItem12;
	private: DevComponents::Editors::ComboItem^  comboItem13;
	private: DevComponents::Editors::ComboItem^  comboItem14;
	private: DevComponents::Editors::ComboItem^  comboItem15;
	private: DevComponents::Editors::ComboItem^  comboItem16;
	private: DevComponents::Editors::ComboItem^  comboItem17;
	private: DevComponents::Editors::ComboItem^  comboItem18;
	private: DevComponents::Editors::ComboItem^  comboItem19;
	private: DevComponents::Editors::ComboItem^  comboItem20;
	private: DevComponents::Editors::ComboItem^  comboItem21;
	private: DevComponents::Editors::ComboItem^  comboItem22;
	private: DevComponents::Editors::ComboItem^  comboItem23;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingZodiacTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingEmailIDLabel;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingEmailIDTitleLabel;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingEmailTextBoxX;
	private: DevComponents::DotNetBar::ButtonX^  personalInformationSettingUploadButtonX;
	private: DevComponents::DotNetBar::ButtonX^  personalInformationSettingChooseNewDPButtonX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingCityTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingCityTitleLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingProvinceTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingProvinceTitleLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingCountryTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingCountryTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingBirthdayDayLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  personalInformationSettingBirthdayDayComboBoxEx;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingBirthdayMonthLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  personalInformationSettingBirthdayMonthComboBoxEx;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingBirthDayYearLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  personalInformationSettingBirthdayYearComboBoxEx;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingBirthdayTitleLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  personalInformationSettingSexComboBoxEx;
	private: DevComponents::Editors::ComboItem^  comboItem5;
	private: DevComponents::Editors::ComboItem^  comboItem6;
	private: DevComponents::Editors::ComboItem^  comboItem7;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingSexTitleLabel;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingBasicInformationLabelX;
	private: System::Windows::Forms::PictureBox^  personalInformationSettingDisplayPicturePictureBox;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingDisplayPictureTitleLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingSignatureTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingSignatureTitleLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  personalInformationSettingNicknameTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingNicknameTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingEmailTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingOuIDLabel;
	private: DevComponents::DotNetBar::LabelX^  personalInformationSettingOuIDTitleLabel;
	private: DevComponents::DotNetBar::SuperTabItem^  personalInformationSettingTabItem;

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
			this->superTabControl4 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel23 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->personalInformationSettingPSTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingPSTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingZodiacComboBoxX = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem11 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem12 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem13 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem14 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem15 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem16 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem17 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem18 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem19 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem20 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem21 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem22 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem23 = (gcnew DevComponents::Editors::ComboItem());
			this->personalInformationSettingZodiacTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingEmailIDLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingEmailIDTitleLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingEmailTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingUploadButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->personalInformationSettingChooseNewDPButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->personalInformationSettingCityTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingCityTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingProvinceTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingProvinceTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingCountryTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingCountryTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingBirthdayDayLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingBirthdayDayComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->personalInformationSettingBirthdayMonthLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingBirthdayMonthComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->personalInformationSettingBirthDayYearLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingBirthdayYearComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->personalInformationSettingBirthdayTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingSexComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem5 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem6 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem7 = (gcnew DevComponents::Editors::ComboItem());
			this->personalInformationSettingSexTitleLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingBasicInformationLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingDisplayPicturePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->personalInformationSettingDisplayPictureTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingSignatureTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingSignatureTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingNicknameTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->personalInformationSettingNicknameTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingEmailTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingOuIDLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingOuIDTitleLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->personalInformationSettingTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl4))->BeginInit();
			this->superTabControl4->SuspendLayout();
			this->superTabControlPanel23->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->personalInformationSettingDisplayPicturePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// superTabControl4
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl4->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl4->ControlBox->MenuBox->Name = L"";
			this->superTabControl4->ControlBox->Name = L"";
			this->superTabControl4->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl4->ControlBox->MenuBox, 
				this->superTabControl4->ControlBox->CloseBox});
			this->superTabControl4->ControlBox->Visible = false;
			this->superTabControl4->Controls->Add(this->superTabControlPanel23);
			this->superTabControl4->Cursor = System::Windows::Forms::Cursors::Default;
			this->superTabControl4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl4->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl4->Location = System::Drawing::Point(0, 0);
			this->superTabControl4->Name = L"superTabControl4";
			this->superTabControl4->ReorderTabsEnabled = true;
			this->superTabControl4->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl4->SelectedTabIndex = 0;
			this->superTabControl4->Size = System::Drawing::Size(593, 573);
			this->superTabControl4->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl4->TabIndex = 1;
			this->superTabControl4->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->personalInformationSettingTabItem});
			this->superTabControl4->Text = L"个人信息设置";
			this->superTabControl4->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel23
			// 
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingPSTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingPSTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingZodiacComboBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingZodiacTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingEmailIDLabel);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingEmailIDTitleLabel);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingEmailTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingUploadButtonX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingChooseNewDPButtonX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingCityTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingCityTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingProvinceTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingProvinceTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingCountryTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingCountryTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayDayLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayDayComboBoxEx);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayMonthLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayMonthComboBoxEx);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthDayYearLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayYearComboBoxEx);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBirthdayTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingSexComboBoxEx);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingSexTitleLabel);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingBasicInformationLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingDisplayPicturePictureBox);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingDisplayPictureTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingSignatureTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingSignatureTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingNicknameTextBoxX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingNicknameTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingEmailTitleLabelX);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingOuIDLabel);
			this->superTabControlPanel23->Controls->Add(this->personalInformationSettingOuIDTitleLabel);
			this->superTabControlPanel23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel23->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel23->Name = L"superTabControlPanel23";
			this->superTabControlPanel23->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel23->TabIndex = 2;
			this->superTabControlPanel23->TabItem = this->personalInformationSettingTabItem;
			// 
			// personalInformationSettingPSTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingPSTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingPSTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingPSTextBoxX->Location = System::Drawing::Point(38, 388);
			this->personalInformationSettingPSTextBoxX->Multiline = true;
			this->personalInformationSettingPSTextBoxX->Name = L"personalInformationSettingPSTextBoxX";
			this->personalInformationSettingPSTextBoxX->Size = System::Drawing::Size(427, 70);
			this->personalInformationSettingPSTextBoxX->TabIndex = 35;
			// 
			// personalInformationSettingPSTitleLabelX
			// 
			this->personalInformationSettingPSTitleLabelX->AutoSize = true;
			this->personalInformationSettingPSTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingPSTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingPSTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingPSTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingPSTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingPSTitleLabelX->Location = System::Drawing::Point(31, 355);
			this->personalInformationSettingPSTitleLabelX->Name = L"personalInformationSettingPSTitleLabelX";
			this->personalInformationSettingPSTitleLabelX->Size = System::Drawing::Size(90, 26);
			this->personalInformationSettingPSTitleLabelX->TabIndex = 34;
			this->personalInformationSettingPSTitleLabelX->Text = L"个人简介：";
			// 
			// personalInformationSettingZodiacComboBoxX
			// 
			this->personalInformationSettingZodiacComboBoxX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingZodiacComboBoxX->DisplayMember = L"Text";
			this->personalInformationSettingZodiacComboBoxX->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->personalInformationSettingZodiacComboBoxX->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->personalInformationSettingZodiacComboBoxX->FormattingEnabled = true;
			this->personalInformationSettingZodiacComboBoxX->ItemHeight = 15;
			this->personalInformationSettingZodiacComboBoxX->Items->AddRange(gcnew cli::array< System::Object^  >(13) {this->comboItem11, 
				this->comboItem12, this->comboItem13, this->comboItem14, this->comboItem15, this->comboItem16, this->comboItem17, this->comboItem18, 
				this->comboItem19, this->comboItem20, this->comboItem21, this->comboItem22, this->comboItem23});
			this->personalInformationSettingZodiacComboBoxX->Location = System::Drawing::Point(127, 253);
			this->personalInformationSettingZodiacComboBoxX->Name = L"personalInformationSettingZodiacComboBoxX";
			this->personalInformationSettingZodiacComboBoxX->Size = System::Drawing::Size(77, 21);
			this->personalInformationSettingZodiacComboBoxX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingZodiacComboBoxX->TabIndex = 33;
			// 
			// comboItem11
			// 
			this->comboItem11->Text = L"-";
			// 
			// comboItem12
			// 
			this->comboItem12->Text = L"白羊座";
			// 
			// comboItem13
			// 
			this->comboItem13->Text = L"金牛座";
			// 
			// comboItem14
			// 
			this->comboItem14->Text = L"双子座";
			// 
			// comboItem15
			// 
			this->comboItem15->Text = L"巨蟹座";
			// 
			// comboItem16
			// 
			this->comboItem16->Text = L"狮子座";
			// 
			// comboItem17
			// 
			this->comboItem17->Text = L"处女座";
			// 
			// comboItem18
			// 
			this->comboItem18->Text = L"天秤座";
			// 
			// comboItem19
			// 
			this->comboItem19->Text = L"天蝎座";
			// 
			// comboItem20
			// 
			this->comboItem20->Text = L"射手座";
			// 
			// comboItem21
			// 
			this->comboItem21->Text = L"摩羯座";
			// 
			// comboItem22
			// 
			this->comboItem22->Text = L"水瓶座";
			// 
			// comboItem23
			// 
			this->comboItem23->Text = L"双鱼座";
			// 
			// personalInformationSettingZodiacTitleLabelX
			// 
			this->personalInformationSettingZodiacTitleLabelX->AutoSize = true;
			this->personalInformationSettingZodiacTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingZodiacTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingZodiacTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingZodiacTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingZodiacTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingZodiacTitleLabelX->Location = System::Drawing::Point(31, 253);
			this->personalInformationSettingZodiacTitleLabelX->Name = L"personalInformationSettingZodiacTitleLabelX";
			this->personalInformationSettingZodiacTitleLabelX->Size = System::Drawing::Size(57, 26);
			this->personalInformationSettingZodiacTitleLabelX->TabIndex = 32;
			this->personalInformationSettingZodiacTitleLabelX->Text = L"星座：";
			// 
			// personalInformationSettingEmailIDLabel
			// 
			this->personalInformationSettingEmailIDLabel->AutoSize = true;
			this->personalInformationSettingEmailIDLabel->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingEmailIDLabel->BackgroundStyle->Class = L"";
			this->personalInformationSettingEmailIDLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingEmailIDLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingEmailIDLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->personalInformationSettingEmailIDLabel->Location = System::Drawing::Point(308, 19);
			this->personalInformationSettingEmailIDLabel->MaximumSize = System::Drawing::Size(250, 25);
			this->personalInformationSettingEmailIDLabel->Name = L"personalInformationSettingEmailIDLabel";
			this->personalInformationSettingEmailIDLabel->Size = System::Drawing::Size(86, 26);
			this->personalInformationSettingEmailIDLabel->TabIndex = 31;
			this->personalInformationSettingEmailIDLabel->Text = L"a@b.com";
			// 
			// personalInformationSettingEmailIDTitleLabel
			// 
			this->personalInformationSettingEmailIDTitleLabel->AutoSize = true;
			this->personalInformationSettingEmailIDTitleLabel->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingEmailIDTitleLabel->BackgroundStyle->Class = L"";
			this->personalInformationSettingEmailIDTitleLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingEmailIDTitleLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingEmailIDTitleLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->personalInformationSettingEmailIDTitleLabel->Location = System::Drawing::Point(221, 21);
			this->personalInformationSettingEmailIDTitleLabel->Name = L"personalInformationSettingEmailIDTitleLabel";
			this->personalInformationSettingEmailIDTitleLabel->Size = System::Drawing::Size(76, 26);
			this->personalInformationSettingEmailIDTitleLabel->TabIndex = 30;
			this->personalInformationSettingEmailIDTitleLabel->Text = L"EmailID:";
			// 
			// personalInformationSettingEmailTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingEmailTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingEmailTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingEmailTextBoxX->Location = System::Drawing::Point(193, 54);
			this->personalInformationSettingEmailTextBoxX->Name = L"personalInformationSettingEmailTextBoxX";
			this->personalInformationSettingEmailTextBoxX->Size = System::Drawing::Size(189, 21);
			this->personalInformationSettingEmailTextBoxX->TabIndex = 28;
			// 
			// personalInformationSettingUploadButtonX
			// 
			this->personalInformationSettingUploadButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->personalInformationSettingUploadButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->personalInformationSettingUploadButtonX->Location = System::Drawing::Point(403, 481);
			this->personalInformationSettingUploadButtonX->Name = L"personalInformationSettingUploadButtonX";
			this->personalInformationSettingUploadButtonX->Size = System::Drawing::Size(75, 23);
			this->personalInformationSettingUploadButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingUploadButtonX->TabIndex = 27;
			this->personalInformationSettingUploadButtonX->Text = L"更新资料";
			// 
			// personalInformationSettingChooseNewDPButtonX
			// 
			this->personalInformationSettingChooseNewDPButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->personalInformationSettingChooseNewDPButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->personalInformationSettingChooseNewDPButtonX->Location = System::Drawing::Point(416, 233);
			this->personalInformationSettingChooseNewDPButtonX->Name = L"personalInformationSettingChooseNewDPButtonX";
			this->personalInformationSettingChooseNewDPButtonX->Size = System::Drawing::Size(75, 23);
			this->personalInformationSettingChooseNewDPButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingChooseNewDPButtonX->TabIndex = 26;
			this->personalInformationSettingChooseNewDPButtonX->Text = L"选择新头像";
			// 
			// personalInformationSettingCityTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingCityTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingCityTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingCityTextBoxX->Location = System::Drawing::Point(127, 319);
			this->personalInformationSettingCityTextBoxX->Name = L"personalInformationSettingCityTextBoxX";
			this->personalInformationSettingCityTextBoxX->Size = System::Drawing::Size(100, 21);
			this->personalInformationSettingCityTextBoxX->TabIndex = 25;
			// 
			// personalInformationSettingCityTitleLabelX
			// 
			this->personalInformationSettingCityTitleLabelX->AutoSize = true;
			this->personalInformationSettingCityTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingCityTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingCityTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingCityTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingCityTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingCityTitleLabelX->Location = System::Drawing::Point(31, 319);
			this->personalInformationSettingCityTitleLabelX->Name = L"personalInformationSettingCityTitleLabelX";
			this->personalInformationSettingCityTitleLabelX->Size = System::Drawing::Size(57, 26);
			this->personalInformationSettingCityTitleLabelX->TabIndex = 24;
			this->personalInformationSettingCityTitleLabelX->Text = L"城市：";
			// 
			// personalInformationSettingProvinceTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingProvinceTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingProvinceTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingProvinceTextBoxX->Location = System::Drawing::Point(365, 287);
			this->personalInformationSettingProvinceTextBoxX->Name = L"personalInformationSettingProvinceTextBoxX";
			this->personalInformationSettingProvinceTextBoxX->Size = System::Drawing::Size(100, 21);
			this->personalInformationSettingProvinceTextBoxX->TabIndex = 23;
			// 
			// personalInformationSettingProvinceTitleLabelX
			// 
			this->personalInformationSettingProvinceTitleLabelX->AutoSize = true;
			this->personalInformationSettingProvinceTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingProvinceTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingProvinceTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingProvinceTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingProvinceTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingProvinceTitleLabelX->Location = System::Drawing::Point(269, 287);
			this->personalInformationSettingProvinceTitleLabelX->Name = L"personalInformationSettingProvinceTitleLabelX";
			this->personalInformationSettingProvinceTitleLabelX->Size = System::Drawing::Size(57, 26);
			this->personalInformationSettingProvinceTitleLabelX->TabIndex = 22;
			this->personalInformationSettingProvinceTitleLabelX->Text = L"省份：";
			// 
			// personalInformationSettingCountryTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingCountryTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingCountryTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingCountryTextBoxX->Location = System::Drawing::Point(127, 287);
			this->personalInformationSettingCountryTextBoxX->Name = L"personalInformationSettingCountryTextBoxX";
			this->personalInformationSettingCountryTextBoxX->Size = System::Drawing::Size(100, 21);
			this->personalInformationSettingCountryTextBoxX->TabIndex = 21;
			// 
			// personalInformationSettingCountryTitleLabelX
			// 
			this->personalInformationSettingCountryTitleLabelX->AutoSize = true;
			this->personalInformationSettingCountryTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingCountryTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingCountryTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingCountryTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingCountryTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingCountryTitleLabelX->Location = System::Drawing::Point(31, 287);
			this->personalInformationSettingCountryTitleLabelX->Name = L"personalInformationSettingCountryTitleLabelX";
			this->personalInformationSettingCountryTitleLabelX->Size = System::Drawing::Size(90, 26);
			this->personalInformationSettingCountryTitleLabelX->TabIndex = 20;
			this->personalInformationSettingCountryTitleLabelX->Text = L"所在国家：";
			// 
			// personalInformationSettingBirthdayDayLabelX
			// 
			this->personalInformationSettingBirthdayDayLabelX->AutoSize = true;
			this->personalInformationSettingBirthdayDayLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingBirthdayDayLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingBirthdayDayLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingBirthdayDayLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthdayDayLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingBirthdayDayLabelX->Location = System::Drawing::Point(332, 221);
			this->personalInformationSettingBirthdayDayLabelX->Name = L"personalInformationSettingBirthdayDayLabelX";
			this->personalInformationSettingBirthdayDayLabelX->Size = System::Drawing::Size(24, 26);
			this->personalInformationSettingBirthdayDayLabelX->TabIndex = 19;
			this->personalInformationSettingBirthdayDayLabelX->Text = L"日";
			// 
			// personalInformationSettingBirthdayDayComboBoxEx
			// 
			this->personalInformationSettingBirthdayDayComboBoxEx->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthdayDayComboBoxEx->DisplayMember = L"Text";
			this->personalInformationSettingBirthdayDayComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->personalInformationSettingBirthdayDayComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->personalInformationSettingBirthdayDayComboBoxEx->FormattingEnabled = true;
			this->personalInformationSettingBirthdayDayComboBoxEx->ItemHeight = 15;
			this->personalInformationSettingBirthdayDayComboBoxEx->Location = System::Drawing::Point(290, 221);
			this->personalInformationSettingBirthdayDayComboBoxEx->Name = L"personalInformationSettingBirthdayDayComboBoxEx";
			this->personalInformationSettingBirthdayDayComboBoxEx->Size = System::Drawing::Size(42, 21);
			this->personalInformationSettingBirthdayDayComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingBirthdayDayComboBoxEx->TabIndex = 18;
			// 
			// personalInformationSettingBirthdayMonthLabelX
			// 
			this->personalInformationSettingBirthdayMonthLabelX->AutoSize = true;
			this->personalInformationSettingBirthdayMonthLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingBirthdayMonthLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingBirthdayMonthLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingBirthdayMonthLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingBirthdayMonthLabelX->Location = System::Drawing::Point(260, 221);
			this->personalInformationSettingBirthdayMonthLabelX->Name = L"personalInformationSettingBirthdayMonthLabelX";
			this->personalInformationSettingBirthdayMonthLabelX->Size = System::Drawing::Size(24, 26);
			this->personalInformationSettingBirthdayMonthLabelX->TabIndex = 17;
			this->personalInformationSettingBirthdayMonthLabelX->Text = L"月";
			// 
			// personalInformationSettingBirthdayMonthComboBoxEx
			// 
			this->personalInformationSettingBirthdayMonthComboBoxEx->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthdayMonthComboBoxEx->DisplayMember = L"Text";
			this->personalInformationSettingBirthdayMonthComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->personalInformationSettingBirthdayMonthComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->personalInformationSettingBirthdayMonthComboBoxEx->FormattingEnabled = true;
			this->personalInformationSettingBirthdayMonthComboBoxEx->ItemHeight = 15;
			this->personalInformationSettingBirthdayMonthComboBoxEx->Location = System::Drawing::Point(221, 221);
			this->personalInformationSettingBirthdayMonthComboBoxEx->Name = L"personalInformationSettingBirthdayMonthComboBoxEx";
			this->personalInformationSettingBirthdayMonthComboBoxEx->Size = System::Drawing::Size(33, 21);
			this->personalInformationSettingBirthdayMonthComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingBirthdayMonthComboBoxEx->TabIndex = 16;
			this->personalInformationSettingBirthdayMonthComboBoxEx->SelectedIndexChanged += gcnew System::EventHandler(this, &PersonalSettingTab::personalInformationSettingBirthdayMonthComboBoxEx_SelectedIndexChanged);
			// 
			// personalInformationSettingBirthDayYearLabelX
			// 
			this->personalInformationSettingBirthDayYearLabelX->AutoSize = true;
			this->personalInformationSettingBirthDayYearLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingBirthDayYearLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingBirthDayYearLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingBirthDayYearLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthDayYearLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingBirthDayYearLabelX->Location = System::Drawing::Point(191, 221);
			this->personalInformationSettingBirthDayYearLabelX->Name = L"personalInformationSettingBirthDayYearLabelX";
			this->personalInformationSettingBirthDayYearLabelX->Size = System::Drawing::Size(24, 26);
			this->personalInformationSettingBirthDayYearLabelX->TabIndex = 15;
			this->personalInformationSettingBirthDayYearLabelX->Text = L"年";
			// 
			// personalInformationSettingBirthdayYearComboBoxEx
			// 
			this->personalInformationSettingBirthdayYearComboBoxEx->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthdayYearComboBoxEx->DisplayMember = L"Text";
			this->personalInformationSettingBirthdayYearComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->personalInformationSettingBirthdayYearComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->personalInformationSettingBirthdayYearComboBoxEx->FormattingEnabled = true;
			this->personalInformationSettingBirthdayYearComboBoxEx->ItemHeight = 15;
			this->personalInformationSettingBirthdayYearComboBoxEx->Location = System::Drawing::Point(127, 221);
			this->personalInformationSettingBirthdayYearComboBoxEx->Name = L"personalInformationSettingBirthdayYearComboBoxEx";
			this->personalInformationSettingBirthdayYearComboBoxEx->Size = System::Drawing::Size(58, 21);
			this->personalInformationSettingBirthdayYearComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingBirthdayYearComboBoxEx->TabIndex = 14;
			this->personalInformationSettingBirthdayYearComboBoxEx->SelectedIndexChanged += gcnew System::EventHandler(this, &PersonalSettingTab::personalInformationSettingBirthdayYearComboBoxEx_SelectedIndexChanged);
			// 
			// personalInformationSettingBirthdayTitleLabelX
			// 
			this->personalInformationSettingBirthdayTitleLabelX->AutoSize = true;
			this->personalInformationSettingBirthdayTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingBirthdayTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingBirthdayTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingBirthdayTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBirthdayTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingBirthdayTitleLabelX->Location = System::Drawing::Point(31, 221);
			this->personalInformationSettingBirthdayTitleLabelX->Name = L"personalInformationSettingBirthdayTitleLabelX";
			this->personalInformationSettingBirthdayTitleLabelX->Size = System::Drawing::Size(57, 26);
			this->personalInformationSettingBirthdayTitleLabelX->TabIndex = 13;
			this->personalInformationSettingBirthdayTitleLabelX->Text = L"生日：";
			// 
			// personalInformationSettingSexComboBoxEx
			// 
			this->personalInformationSettingSexComboBoxEx->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingSexComboBoxEx->DisplayMember = L"Text";
			this->personalInformationSettingSexComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->personalInformationSettingSexComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->personalInformationSettingSexComboBoxEx->FormattingEnabled = true;
			this->personalInformationSettingSexComboBoxEx->ItemHeight = 15;
			this->personalInformationSettingSexComboBoxEx->Items->AddRange(gcnew cli::array< System::Object^  >(3) {this->comboItem5, 
				this->comboItem6, this->comboItem7});
			this->personalInformationSettingSexComboBoxEx->Location = System::Drawing::Point(127, 190);
			this->personalInformationSettingSexComboBoxEx->Name = L"personalInformationSettingSexComboBoxEx";
			this->personalInformationSettingSexComboBoxEx->Size = System::Drawing::Size(60, 21);
			this->personalInformationSettingSexComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationSettingSexComboBoxEx->TabIndex = 12;
			// 
			// comboItem5
			// 
			this->comboItem5->Text = L"-";
			// 
			// comboItem6
			// 
			this->comboItem6->Text = L"男";
			// 
			// comboItem7
			// 
			this->comboItem7->Text = L"女";
			// 
			// personalInformationSettingSexTitleLabel
			// 
			this->personalInformationSettingSexTitleLabel->AutoSize = true;
			this->personalInformationSettingSexTitleLabel->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingSexTitleLabel->BackgroundStyle->Class = L"";
			this->personalInformationSettingSexTitleLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingSexTitleLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingSexTitleLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingSexTitleLabel->Location = System::Drawing::Point(31, 190);
			this->personalInformationSettingSexTitleLabel->Name = L"personalInformationSettingSexTitleLabel";
			this->personalInformationSettingSexTitleLabel->Size = System::Drawing::Size(57, 26);
			this->personalInformationSettingSexTitleLabel->TabIndex = 11;
			this->personalInformationSettingSexTitleLabel->Text = L"性别：";
			// 
			// personalInformationSettingBasicInformationLabelX
			// 
			this->personalInformationSettingBasicInformationLabelX->AutoSize = true;
			this->personalInformationSettingBasicInformationLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingBasicInformationLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingBasicInformationLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingBasicInformationLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingBasicInformationLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingBasicInformationLabelX->Location = System::Drawing::Point(31, 162);
			this->personalInformationSettingBasicInformationLabelX->Name = L"personalInformationSettingBasicInformationLabelX";
			this->personalInformationSettingBasicInformationLabelX->Size = System::Drawing::Size(156, 26);
			this->personalInformationSettingBasicInformationLabelX->TabIndex = 10;
			this->personalInformationSettingBasicInformationLabelX->Text = L"您的个人基本资料：";
			// 
			// personalInformationSettingDisplayPicturePictureBox
			// 
			this->personalInformationSettingDisplayPicturePictureBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingDisplayPicturePictureBox->Location = System::Drawing::Point(416, 100);
			this->personalInformationSettingDisplayPicturePictureBox->Name = L"personalInformationSettingDisplayPicturePictureBox";
			this->personalInformationSettingDisplayPicturePictureBox->Size = System::Drawing::Size(123, 111);
			this->personalInformationSettingDisplayPicturePictureBox->TabIndex = 9;
			this->personalInformationSettingDisplayPicturePictureBox->TabStop = false;
			// 
			// personalInformationSettingDisplayPictureTitleLabelX
			// 
			this->personalInformationSettingDisplayPictureTitleLabelX->AutoSize = true;
			this->personalInformationSettingDisplayPictureTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingDisplayPictureTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingDisplayPictureTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingDisplayPictureTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingDisplayPictureTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingDisplayPictureTitleLabelX->Location = System::Drawing::Point(416, 54);
			this->personalInformationSettingDisplayPictureTitleLabelX->Name = L"personalInformationSettingDisplayPictureTitleLabelX";
			this->personalInformationSettingDisplayPictureTitleLabelX->Size = System::Drawing::Size(123, 26);
			this->personalInformationSettingDisplayPictureTitleLabelX->TabIndex = 8;
			this->personalInformationSettingDisplayPictureTitleLabelX->Text = L"您当前的头像：";
			// 
			// personalInformationSettingSignatureTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingSignatureTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingSignatureTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingSignatureTextBoxX->Location = System::Drawing::Point(193, 127);
			this->personalInformationSettingSignatureTextBoxX->MaxLength = 150;
			this->personalInformationSettingSignatureTextBoxX->Name = L"personalInformationSettingSignatureTextBoxX";
			this->personalInformationSettingSignatureTextBoxX->Size = System::Drawing::Size(189, 21);
			this->personalInformationSettingSignatureTextBoxX->TabIndex = 7;
			// 
			// personalInformationSettingSignatureTitleLabelX
			// 
			this->personalInformationSettingSignatureTitleLabelX->AutoSize = true;
			this->personalInformationSettingSignatureTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingSignatureTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingSignatureTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingSignatureTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingSignatureTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingSignatureTitleLabelX->Location = System::Drawing::Point(31, 127);
			this->personalInformationSettingSignatureTitleLabelX->Name = L"personalInformationSettingSignatureTitleLabelX";
			this->personalInformationSettingSignatureTitleLabelX->Size = System::Drawing::Size(123, 26);
			this->personalInformationSettingSignatureTitleLabelX->TabIndex = 6;
			this->personalInformationSettingSignatureTitleLabelX->Text = L"您的个人签名：";
			// 
			// personalInformationSettingNicknameTextBoxX
			// 
			// 
			// 
			// 
			this->personalInformationSettingNicknameTextBoxX->Border->Class = L"TextBoxBorder";
			this->personalInformationSettingNicknameTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingNicknameTextBoxX->Location = System::Drawing::Point(193, 89);
			this->personalInformationSettingNicknameTextBoxX->MaxLength = 24;
			this->personalInformationSettingNicknameTextBoxX->Name = L"personalInformationSettingNicknameTextBoxX";
			this->personalInformationSettingNicknameTextBoxX->Size = System::Drawing::Size(189, 21);
			this->personalInformationSettingNicknameTextBoxX->TabIndex = 5;
			// 
			// personalInformationSettingNicknameTitleLabelX
			// 
			this->personalInformationSettingNicknameTitleLabelX->AutoSize = true;
			this->personalInformationSettingNicknameTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingNicknameTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingNicknameTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingNicknameTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingNicknameTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingNicknameTitleLabelX->Location = System::Drawing::Point(31, 89);
			this->personalInformationSettingNicknameTitleLabelX->Name = L"personalInformationSettingNicknameTitleLabelX";
			this->personalInformationSettingNicknameTitleLabelX->Size = System::Drawing::Size(90, 26);
			this->personalInformationSettingNicknameTitleLabelX->TabIndex = 4;
			this->personalInformationSettingNicknameTitleLabelX->Text = L"您的昵称：";
			// 
			// personalInformationSettingEmailTitleLabelX
			// 
			this->personalInformationSettingEmailTitleLabelX->AutoSize = true;
			this->personalInformationSettingEmailTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingEmailTitleLabelX->BackgroundStyle->Class = L"";
			this->personalInformationSettingEmailTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingEmailTitleLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingEmailTitleLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingEmailTitleLabelX->Location = System::Drawing::Point(31, 54);
			this->personalInformationSettingEmailTitleLabelX->Name = L"personalInformationSettingEmailTitleLabelX";
			this->personalInformationSettingEmailTitleLabelX->Size = System::Drawing::Size(135, 26);
			this->personalInformationSettingEmailTitleLabelX->TabIndex = 2;
			this->personalInformationSettingEmailTitleLabelX->Text = L"您的Email地址：";
			// 
			// personalInformationSettingOuIDLabel
			// 
			this->personalInformationSettingOuIDLabel->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingOuIDLabel->BackgroundStyle->Class = L"";
			this->personalInformationSettingOuIDLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingOuIDLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingOuIDLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->personalInformationSettingOuIDLabel->Location = System::Drawing::Point(134, 21);
			this->personalInformationSettingOuIDLabel->Name = L"personalInformationSettingOuIDLabel";
			this->personalInformationSettingOuIDLabel->Size = System::Drawing::Size(75, 23);
			this->personalInformationSettingOuIDLabel->TabIndex = 1;
			this->personalInformationSettingOuIDLabel->Text = L"10000";
			// 
			// personalInformationSettingOuIDTitleLabel
			// 
			this->personalInformationSettingOuIDTitleLabel->AutoSize = true;
			this->personalInformationSettingOuIDTitleLabel->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->personalInformationSettingOuIDTitleLabel->BackgroundStyle->Class = L"";
			this->personalInformationSettingOuIDTitleLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalInformationSettingOuIDTitleLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->personalInformationSettingOuIDTitleLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->personalInformationSettingOuIDTitleLabel->Location = System::Drawing::Point(31, 21);
			this->personalInformationSettingOuIDTitleLabel->Name = L"personalInformationSettingOuIDTitleLabel";
			this->personalInformationSettingOuIDTitleLabel->Size = System::Drawing::Size(100, 26);
			this->personalInformationSettingOuIDTitleLabel->TabIndex = 0;
			this->personalInformationSettingOuIDTitleLabel->Text = L"您的OuID：";
			// 
			// personalInformationSettingTabItem
			// 
			this->personalInformationSettingTabItem->AttachedControl = this->superTabControlPanel23;
			this->personalInformationSettingTabItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->personalInformationSettingTabItem->GlobalItem = false;
			this->personalInformationSettingTabItem->Name = L"personalInformationSettingTabItem";
			this->personalInformationSettingTabItem->Text = L"个人信息设置";
			// 
			// PersonalSettingTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->Controls->Add(this->superTabControl4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"PersonalSettingTab";
			this->Text = L"PersonalSettingTab";
			this->DoubleBuffered = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl4))->EndInit();
			this->superTabControl4->ResumeLayout(false);
			this->superTabControlPanel23->ResumeLayout(false);
			this->superTabControlPanel23->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->personalInformationSettingDisplayPicturePictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void personalInformationSettingBirthdayMonthComboBoxEx_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void personalInformationSettingBirthdayYearComboBoxEx_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) ;
		 System::Void PersonalSettingTab::RefreshPersonalSettingTabBirthdayDayComboBox(void);
		 System::Void PersonalSettingTab::UpdatePersonalSettingTabInfo(void);
};
}
