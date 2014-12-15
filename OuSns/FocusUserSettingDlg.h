#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for FocusUserSettingDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
//	public ref class FocusUserSettingDlg : public System::Windows::Forms::Form
	public ref class FocusUserSettingDlg : DevComponents::DotNetBar::Office2007Form
	{
	public:
		FocusUserSettingDlg(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FocusUserSettingDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	protected: 
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: DevComponents::DotNetBar::ButtonX^  buttonX2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX2;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX1;
	private: DevComponents::DotNetBar::LabelX^  labelX1;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel1;

	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX3;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX16;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX15;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX14;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX13;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX12;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX11;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX10;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX9;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX8;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX7;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX6;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX5;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX4;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel4;


	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX32;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX33;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX34;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX35;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX36;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel3;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX18;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX19;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX20;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX21;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX22;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX23;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel2;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX24;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX25;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX26;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX27;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX28;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX29;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX30;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel6;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX46;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX45;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX17;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX31;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX41;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX42;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX43;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX44;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel5;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX37;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX38;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX39;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX40;
	private: DevComponents::DotNetBar::Controls::GroupPanel^  groupPanel7;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX51;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX52;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX53;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  checkBoxX54;





	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelEx1 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->buttonX2 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->labelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->checkBoxX2 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX1 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel1 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX3 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX4 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX5 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX6 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX7 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX8 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX9 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX10 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX11 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX12 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX13 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX14 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX15 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX16 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel2 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX24 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX25 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX26 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX27 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX28 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX29 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX30 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel3 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX18 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX19 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX20 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX21 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX22 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX23 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel4 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX32 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX33 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX34 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX35 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX36 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel5 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX37 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX38 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX39 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX40 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel6 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX17 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX31 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX41 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX42 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX43 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX44 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX45 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX46 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->groupPanel7 = (gcnew DevComponents::DotNetBar::Controls::GroupPanel());
			this->checkBoxX51 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX52 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX53 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->checkBoxX54 = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->panelEx1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupPanel1->SuspendLayout();
			this->groupPanel2->SuspendLayout();
			this->groupPanel3->SuspendLayout();
			this->groupPanel4->SuspendLayout();
			this->groupPanel5->SuspendLayout();
			this->groupPanel6->SuspendLayout();
			this->groupPanel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelEx1
			// 
			this->panelEx1->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->splitContainer1);
			this->panelEx1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx1->Location = System::Drawing::Point(0, 0);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Size = System::Drawing::Size(570, 541);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 0;
			this->panelEx1->Text = L"panelEx1";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel7);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel6);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel5);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel4);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel3);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel2);
			this->splitContainer1->Panel1->Controls->Add(this->groupPanel1);
			this->splitContainer1->Panel1->Controls->Add(this->checkBoxX2);
			this->splitContainer1->Panel1->Controls->Add(this->checkBoxX1);
			this->splitContainer1->Panel1->Controls->Add(this->labelX1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->buttonX2);
			this->splitContainer1->Panel2->Controls->Add(this->buttonX1);
			this->splitContainer1->Size = System::Drawing::Size(570, 541);
			this->splitContainer1->SplitterDistance = 483;
			this->splitContainer1->TabIndex = 0;
			// 
			// buttonX1
			// 
			this->buttonX1->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX1->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX1->Location = System::Drawing::Point(381, 9);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(75, 23);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 0;
			this->buttonX1->Text = L"确定";
			// 
			// buttonX2
			// 
			this->buttonX2->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX2->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX2->Location = System::Drawing::Point(480, 9);
			this->buttonX2->Name = L"buttonX2";
			this->buttonX2->Size = System::Drawing::Size(75, 23);
			this->buttonX2->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX2->TabIndex = 1;
			this->buttonX2->Text = L"取消";
			// 
			// labelX1
			// 
			// 
			// 
			// 
			this->labelX1->BackgroundStyle->Class = L"";
			this->labelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX1->Location = System::Drawing::Point(13, 13);
			this->labelX1->Name = L"labelX1";
			this->labelX1->Size = System::Drawing::Size(126, 23);
			this->labelX1->TabIndex = 0;
			this->labelX1->Text = L"请选择关注的处理方式";
			// 
			// checkBoxX2
			// 
			// 
			// 
			// 
			this->checkBoxX2->BackgroundStyle->Class = L"";
			this->checkBoxX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX2->CheckBoxStyle = DevComponents::DotNetBar::eCheckBoxStyle::RadioButton;
			this->checkBoxX2->Location = System::Drawing::Point(13, 71);
			this->checkBoxX2->Name = L"checkBoxX2";
			this->checkBoxX2->Size = System::Drawing::Size(175, 23);
			this->checkBoxX2->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX2->TabIndex = 2;
			this->checkBoxX2->Text = L"关注并自动下载对方的文件";
			// 
			// checkBoxX1
			// 
			// 
			// 
			// 
			this->checkBoxX1->BackgroundStyle->Class = L"";
			this->checkBoxX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX1->CheckBoxStyle = DevComponents::DotNetBar::eCheckBoxStyle::RadioButton;
			this->checkBoxX1->Checked = true;
			this->checkBoxX1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxX1->CheckValue = L"Y";
			this->checkBoxX1->Location = System::Drawing::Point(13, 42);
			this->checkBoxX1->Name = L"checkBoxX1";
			this->checkBoxX1->Size = System::Drawing::Size(175, 23);
			this->checkBoxX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX1->TabIndex = 1;
			this->checkBoxX1->Text = L"仅关注";
			// 
			// groupPanel1
			// 
			this->groupPanel1->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel1->Controls->Add(this->checkBoxX16);
			this->groupPanel1->Controls->Add(this->checkBoxX15);
			this->groupPanel1->Controls->Add(this->checkBoxX14);
			this->groupPanel1->Controls->Add(this->checkBoxX13);
			this->groupPanel1->Controls->Add(this->checkBoxX12);
			this->groupPanel1->Controls->Add(this->checkBoxX11);
			this->groupPanel1->Controls->Add(this->checkBoxX10);
			this->groupPanel1->Controls->Add(this->checkBoxX9);
			this->groupPanel1->Controls->Add(this->checkBoxX8);
			this->groupPanel1->Controls->Add(this->checkBoxX7);
			this->groupPanel1->Controls->Add(this->checkBoxX6);
			this->groupPanel1->Controls->Add(this->checkBoxX5);
			this->groupPanel1->Controls->Add(this->checkBoxX4);
			this->groupPanel1->Controls->Add(this->checkBoxX3);
			this->groupPanel1->DrawTitleBox = false;
			this->groupPanel1->Location = System::Drawing::Point(30, 100);
			this->groupPanel1->Name = L"groupPanel1";
			this->groupPanel1->Size = System::Drawing::Size(525, 78);
			// 
			// 
			// 
			this->groupPanel1->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel1->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel1->Style->BackColorGradientAngle = 90;
			this->groupPanel1->Style->BorderBottomWidth = 1;
			this->groupPanel1->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel1->Style->BorderLeftWidth = 1;
			this->groupPanel1->Style->BorderRightWidth = 1;
			this->groupPanel1->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel1->Style->BorderTopWidth = 1;
			this->groupPanel1->Style->Class = L"";
			this->groupPanel1->Style->CornerDiameter = 4;
			this->groupPanel1->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel1->Style->HideMnemonic = true;
			this->groupPanel1->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel1->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel1->StyleMouseDown->Class = L"";
			this->groupPanel1->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel1->StyleMouseOver->Class = L"";
			this->groupPanel1->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel1->TabIndex = 3;
			this->groupPanel1->Text = L"视频文件";
			// 
			// checkBoxX3
			// 
			// 
			// 
			// 
			this->checkBoxX3->BackgroundStyle->Class = L"";
			this->checkBoxX3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX3->Location = System::Drawing::Point(4, 4);
			this->checkBoxX3->Name = L"checkBoxX3";
			this->checkBoxX3->Size = System::Drawing::Size(56, 23);
			this->checkBoxX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX3->TabIndex = 0;
			this->checkBoxX3->Text = L"RMVB";
			// 
			// checkBoxX4
			// 
			// 
			// 
			// 
			this->checkBoxX4->BackgroundStyle->Class = L"";
			this->checkBoxX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX4->Location = System::Drawing::Point(66, 4);
			this->checkBoxX4->Name = L"checkBoxX4";
			this->checkBoxX4->Size = System::Drawing::Size(56, 23);
			this->checkBoxX4->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX4->TabIndex = 1;
			this->checkBoxX4->Text = L"MKV";
			// 
			// checkBoxX5
			// 
			// 
			// 
			// 
			this->checkBoxX5->BackgroundStyle->Class = L"";
			this->checkBoxX5->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX5->Location = System::Drawing::Point(128, 4);
			this->checkBoxX5->Name = L"checkBoxX5";
			this->checkBoxX5->Size = System::Drawing::Size(56, 23);
			this->checkBoxX5->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX5->TabIndex = 2;
			this->checkBoxX5->Text = L"AVI";
			// 
			// checkBoxX6
			// 
			// 
			// 
			// 
			this->checkBoxX6->BackgroundStyle->Class = L"";
			this->checkBoxX6->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX6->Location = System::Drawing::Point(190, 4);
			this->checkBoxX6->Name = L"checkBoxX6";
			this->checkBoxX6->Size = System::Drawing::Size(56, 23);
			this->checkBoxX6->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX6->TabIndex = 3;
			this->checkBoxX6->Text = L"MP4";
			// 
			// checkBoxX7
			// 
			// 
			// 
			// 
			this->checkBoxX7->BackgroundStyle->Class = L"";
			this->checkBoxX7->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX7->Location = System::Drawing::Point(252, 4);
			this->checkBoxX7->Name = L"checkBoxX7";
			this->checkBoxX7->Size = System::Drawing::Size(56, 23);
			this->checkBoxX7->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX7->TabIndex = 4;
			this->checkBoxX7->Text = L"WMV";
			// 
			// checkBoxX8
			// 
			// 
			// 
			// 
			this->checkBoxX8->BackgroundStyle->Class = L"";
			this->checkBoxX8->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX8->Location = System::Drawing::Point(314, 4);
			this->checkBoxX8->Name = L"checkBoxX8";
			this->checkBoxX8->Size = System::Drawing::Size(56, 23);
			this->checkBoxX8->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX8->TabIndex = 5;
			this->checkBoxX8->Text = L"MOV";
			// 
			// checkBoxX9
			// 
			// 
			// 
			// 
			this->checkBoxX9->BackgroundStyle->Class = L"";
			this->checkBoxX9->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX9->Location = System::Drawing::Point(376, 4);
			this->checkBoxX9->Name = L"checkBoxX9";
			this->checkBoxX9->Size = System::Drawing::Size(56, 23);
			this->checkBoxX9->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX9->TabIndex = 6;
			this->checkBoxX9->Text = L"TS";
			// 
			// checkBoxX10
			// 
			// 
			// 
			// 
			this->checkBoxX10->BackgroundStyle->Class = L"";
			this->checkBoxX10->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX10->Location = System::Drawing::Point(438, 4);
			this->checkBoxX10->Name = L"checkBoxX10";
			this->checkBoxX10->Size = System::Drawing::Size(56, 23);
			this->checkBoxX10->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX10->TabIndex = 7;
			this->checkBoxX10->Text = L"FLV";
			// 
			// checkBoxX11
			// 
			// 
			// 
			// 
			this->checkBoxX11->BackgroundStyle->Class = L"";
			this->checkBoxX11->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX11->Location = System::Drawing::Point(4, 33);
			this->checkBoxX11->Name = L"checkBoxX11";
			this->checkBoxX11->Size = System::Drawing::Size(56, 23);
			this->checkBoxX11->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX11->TabIndex = 8;
			this->checkBoxX11->Text = L"MPEG";
			// 
			// checkBoxX12
			// 
			// 
			// 
			// 
			this->checkBoxX12->BackgroundStyle->Class = L"";
			this->checkBoxX12->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX12->Location = System::Drawing::Point(66, 33);
			this->checkBoxX12->Name = L"checkBoxX12";
			this->checkBoxX12->Size = System::Drawing::Size(56, 23);
			this->checkBoxX12->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX12->TabIndex = 9;
			this->checkBoxX12->Text = L"MPG";
			// 
			// checkBoxX13
			// 
			// 
			// 
			// 
			this->checkBoxX13->BackgroundStyle->Class = L"";
			this->checkBoxX13->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX13->Location = System::Drawing::Point(128, 33);
			this->checkBoxX13->Name = L"checkBoxX13";
			this->checkBoxX13->Size = System::Drawing::Size(56, 23);
			this->checkBoxX13->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX13->TabIndex = 10;
			this->checkBoxX13->Text = L"ASF";
			// 
			// checkBoxX14
			// 
			// 
			// 
			// 
			this->checkBoxX14->BackgroundStyle->Class = L"";
			this->checkBoxX14->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX14->Location = System::Drawing::Point(190, 33);
			this->checkBoxX14->Name = L"checkBoxX14";
			this->checkBoxX14->Size = System::Drawing::Size(56, 23);
			this->checkBoxX14->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX14->TabIndex = 11;
			this->checkBoxX14->Text = L"M4V";
			// 
			// checkBoxX15
			// 
			// 
			// 
			// 
			this->checkBoxX15->BackgroundStyle->Class = L"";
			this->checkBoxX15->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX15->Location = System::Drawing::Point(252, 33);
			this->checkBoxX15->Name = L"checkBoxX15";
			this->checkBoxX15->Size = System::Drawing::Size(56, 23);
			this->checkBoxX15->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX15->TabIndex = 12;
			this->checkBoxX15->Text = L"F4V";
			// 
			// checkBoxX16
			// 
			// 
			// 
			// 
			this->checkBoxX16->BackgroundStyle->Class = L"";
			this->checkBoxX16->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX16->Location = System::Drawing::Point(314, 33);
			this->checkBoxX16->Name = L"checkBoxX16";
			this->checkBoxX16->Size = System::Drawing::Size(56, 23);
			this->checkBoxX16->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX16->TabIndex = 13;
			this->checkBoxX16->Text = L"SWF";
			// 
			// groupPanel2
			// 
			this->groupPanel2->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel2->Controls->Add(this->checkBoxX24);
			this->groupPanel2->Controls->Add(this->checkBoxX25);
			this->groupPanel2->Controls->Add(this->checkBoxX26);
			this->groupPanel2->Controls->Add(this->checkBoxX27);
			this->groupPanel2->Controls->Add(this->checkBoxX28);
			this->groupPanel2->Controls->Add(this->checkBoxX29);
			this->groupPanel2->Controls->Add(this->checkBoxX30);
			this->groupPanel2->DrawTitleBox = false;
			this->groupPanel2->Location = System::Drawing::Point(30, 178);
			this->groupPanel2->Name = L"groupPanel2";
			this->groupPanel2->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel2->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel2->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel2->Style->BackColorGradientAngle = 90;
			this->groupPanel2->Style->BorderBottomWidth = 1;
			this->groupPanel2->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel2->Style->BorderLeftWidth = 1;
			this->groupPanel2->Style->BorderRightWidth = 1;
			this->groupPanel2->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel2->Style->BorderTopWidth = 1;
			this->groupPanel2->Style->Class = L"";
			this->groupPanel2->Style->CornerDiameter = 4;
			this->groupPanel2->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel2->Style->HideMnemonic = true;
			this->groupPanel2->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel2->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel2->StyleMouseDown->Class = L"";
			this->groupPanel2->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel2->StyleMouseOver->Class = L"";
			this->groupPanel2->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel2->TabIndex = 4;
			this->groupPanel2->Text = L"字幕文件";
			// 
			// checkBoxX24
			// 
			// 
			// 
			// 
			this->checkBoxX24->BackgroundStyle->Class = L"";
			this->checkBoxX24->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX24->Location = System::Drawing::Point(376, 4);
			this->checkBoxX24->Name = L"checkBoxX24";
			this->checkBoxX24->Size = System::Drawing::Size(56, 23);
			this->checkBoxX24->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX24->TabIndex = 6;
			this->checkBoxX24->Text = L"TXT";
			// 
			// checkBoxX25
			// 
			// 
			// 
			// 
			this->checkBoxX25->BackgroundStyle->Class = L"";
			this->checkBoxX25->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX25->Location = System::Drawing::Point(314, 4);
			this->checkBoxX25->Name = L"checkBoxX25";
			this->checkBoxX25->Size = System::Drawing::Size(56, 23);
			this->checkBoxX25->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX25->TabIndex = 5;
			this->checkBoxX25->Text = L"XML";
			// 
			// checkBoxX26
			// 
			// 
			// 
			// 
			this->checkBoxX26->BackgroundStyle->Class = L"";
			this->checkBoxX26->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX26->Location = System::Drawing::Point(252, 4);
			this->checkBoxX26->Name = L"checkBoxX26";
			this->checkBoxX26->Size = System::Drawing::Size(56, 23);
			this->checkBoxX26->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX26->TabIndex = 4;
			this->checkBoxX26->Text = L"SMI";
			// 
			// checkBoxX27
			// 
			// 
			// 
			// 
			this->checkBoxX27->BackgroundStyle->Class = L"";
			this->checkBoxX27->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX27->Location = System::Drawing::Point(190, 4);
			this->checkBoxX27->Name = L"checkBoxX27";
			this->checkBoxX27->Size = System::Drawing::Size(56, 23);
			this->checkBoxX27->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX27->TabIndex = 3;
			this->checkBoxX27->Text = L"VOB";
			// 
			// checkBoxX28
			// 
			// 
			// 
			// 
			this->checkBoxX28->BackgroundStyle->Class = L"";
			this->checkBoxX28->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX28->Location = System::Drawing::Point(128, 4);
			this->checkBoxX28->Name = L"checkBoxX28";
			this->checkBoxX28->Size = System::Drawing::Size(56, 23);
			this->checkBoxX28->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX28->TabIndex = 2;
			this->checkBoxX28->Text = L"SSA";
			// 
			// checkBoxX29
			// 
			// 
			// 
			// 
			this->checkBoxX29->BackgroundStyle->Class = L"";
			this->checkBoxX29->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX29->Location = System::Drawing::Point(66, 4);
			this->checkBoxX29->Name = L"checkBoxX29";
			this->checkBoxX29->Size = System::Drawing::Size(56, 23);
			this->checkBoxX29->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX29->TabIndex = 1;
			this->checkBoxX29->Text = L"ASS";
			// 
			// checkBoxX30
			// 
			// 
			// 
			// 
			this->checkBoxX30->BackgroundStyle->Class = L"";
			this->checkBoxX30->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX30->Location = System::Drawing::Point(4, 4);
			this->checkBoxX30->Name = L"checkBoxX30";
			this->checkBoxX30->Size = System::Drawing::Size(56, 23);
			this->checkBoxX30->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX30->TabIndex = 0;
			this->checkBoxX30->Text = L"SRT";
			// 
			// groupPanel3
			// 
			this->groupPanel3->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel3->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel3->Controls->Add(this->checkBoxX18);
			this->groupPanel3->Controls->Add(this->checkBoxX19);
			this->groupPanel3->Controls->Add(this->checkBoxX20);
			this->groupPanel3->Controls->Add(this->checkBoxX21);
			this->groupPanel3->Controls->Add(this->checkBoxX22);
			this->groupPanel3->Controls->Add(this->checkBoxX23);
			this->groupPanel3->DrawTitleBox = false;
			this->groupPanel3->Location = System::Drawing::Point(30, 227);
			this->groupPanel3->Name = L"groupPanel3";
			this->groupPanel3->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel3->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel3->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel3->Style->BackColorGradientAngle = 90;
			this->groupPanel3->Style->BorderBottomWidth = 1;
			this->groupPanel3->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel3->Style->BorderLeftWidth = 1;
			this->groupPanel3->Style->BorderRightWidth = 1;
			this->groupPanel3->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel3->Style->BorderTopWidth = 1;
			this->groupPanel3->Style->Class = L"";
			this->groupPanel3->Style->CornerDiameter = 4;
			this->groupPanel3->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel3->Style->HideMnemonic = true;
			this->groupPanel3->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel3->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel3->StyleMouseDown->Class = L"";
			this->groupPanel3->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel3->StyleMouseOver->Class = L"";
			this->groupPanel3->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel3->TabIndex = 5;
			this->groupPanel3->Text = L"音频文件";
			// 
			// checkBoxX18
			// 
			// 
			// 
			// 
			this->checkBoxX18->BackgroundStyle->Class = L"";
			this->checkBoxX18->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX18->Location = System::Drawing::Point(314, 4);
			this->checkBoxX18->Name = L"checkBoxX18";
			this->checkBoxX18->Size = System::Drawing::Size(56, 23);
			this->checkBoxX18->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX18->TabIndex = 5;
			this->checkBoxX18->Text = L"WMA";
			// 
			// checkBoxX19
			// 
			// 
			// 
			// 
			this->checkBoxX19->BackgroundStyle->Class = L"";
			this->checkBoxX19->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX19->Location = System::Drawing::Point(252, 4);
			this->checkBoxX19->Name = L"checkBoxX19";
			this->checkBoxX19->Size = System::Drawing::Size(56, 23);
			this->checkBoxX19->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX19->TabIndex = 4;
			this->checkBoxX19->Text = L"WAV";
			// 
			// checkBoxX20
			// 
			// 
			// 
			// 
			this->checkBoxX20->BackgroundStyle->Class = L"";
			this->checkBoxX20->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX20->Location = System::Drawing::Point(190, 4);
			this->checkBoxX20->Name = L"checkBoxX20";
			this->checkBoxX20->Size = System::Drawing::Size(56, 23);
			this->checkBoxX20->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX20->TabIndex = 3;
			this->checkBoxX20->Text = L"FALC";
			// 
			// checkBoxX21
			// 
			// 
			// 
			// 
			this->checkBoxX21->BackgroundStyle->Class = L"";
			this->checkBoxX21->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX21->Location = System::Drawing::Point(128, 4);
			this->checkBoxX21->Name = L"checkBoxX21";
			this->checkBoxX21->Size = System::Drawing::Size(56, 23);
			this->checkBoxX21->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX21->TabIndex = 2;
			this->checkBoxX21->Text = L"CUE";
			// 
			// checkBoxX22
			// 
			// 
			// 
			// 
			this->checkBoxX22->BackgroundStyle->Class = L"";
			this->checkBoxX22->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX22->Location = System::Drawing::Point(66, 4);
			this->checkBoxX22->Name = L"checkBoxX22";
			this->checkBoxX22->Size = System::Drawing::Size(56, 23);
			this->checkBoxX22->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX22->TabIndex = 1;
			this->checkBoxX22->Text = L"APE";
			// 
			// checkBoxX23
			// 
			// 
			// 
			// 
			this->checkBoxX23->BackgroundStyle->Class = L"";
			this->checkBoxX23->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX23->Location = System::Drawing::Point(4, 4);
			this->checkBoxX23->Name = L"checkBoxX23";
			this->checkBoxX23->Size = System::Drawing::Size(56, 23);
			this->checkBoxX23->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX23->TabIndex = 0;
			this->checkBoxX23->Text = L"MP3";
			// 
			// groupPanel4
			// 
			this->groupPanel4->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel4->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel4->Controls->Add(this->checkBoxX32);
			this->groupPanel4->Controls->Add(this->checkBoxX33);
			this->groupPanel4->Controls->Add(this->checkBoxX34);
			this->groupPanel4->Controls->Add(this->checkBoxX35);
			this->groupPanel4->Controls->Add(this->checkBoxX36);
			this->groupPanel4->DrawTitleBox = false;
			this->groupPanel4->Location = System::Drawing::Point(30, 276);
			this->groupPanel4->Name = L"groupPanel4";
			this->groupPanel4->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel4->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel4->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel4->Style->BackColorGradientAngle = 90;
			this->groupPanel4->Style->BorderBottomWidth = 1;
			this->groupPanel4->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel4->Style->BorderLeftWidth = 1;
			this->groupPanel4->Style->BorderRightWidth = 1;
			this->groupPanel4->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel4->Style->BorderTopWidth = 1;
			this->groupPanel4->Style->Class = L"";
			this->groupPanel4->Style->CornerDiameter = 4;
			this->groupPanel4->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel4->Style->HideMnemonic = true;
			this->groupPanel4->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel4->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel4->StyleMouseDown->Class = L"";
			this->groupPanel4->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel4->StyleMouseOver->Class = L"";
			this->groupPanel4->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel4->TabIndex = 6;
			this->groupPanel4->Text = L"镜像文件";
			// 
			// checkBoxX32
			// 
			// 
			// 
			// 
			this->checkBoxX32->BackgroundStyle->Class = L"";
			this->checkBoxX32->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX32->Location = System::Drawing::Point(252, 4);
			this->checkBoxX32->Name = L"checkBoxX32";
			this->checkBoxX32->Size = System::Drawing::Size(56, 23);
			this->checkBoxX32->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX32->TabIndex = 4;
			this->checkBoxX32->Text = L"CUE";
			// 
			// checkBoxX33
			// 
			// 
			// 
			// 
			this->checkBoxX33->BackgroundStyle->Class = L"";
			this->checkBoxX33->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX33->Location = System::Drawing::Point(190, 4);
			this->checkBoxX33->Name = L"checkBoxX33";
			this->checkBoxX33->Size = System::Drawing::Size(56, 23);
			this->checkBoxX33->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX33->TabIndex = 3;
			this->checkBoxX33->Text = L"BIN";
			// 
			// checkBoxX34
			// 
			// 
			// 
			// 
			this->checkBoxX34->BackgroundStyle->Class = L"";
			this->checkBoxX34->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX34->Location = System::Drawing::Point(128, 4);
			this->checkBoxX34->Name = L"checkBoxX34";
			this->checkBoxX34->Size = System::Drawing::Size(56, 23);
			this->checkBoxX34->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX34->TabIndex = 2;
			this->checkBoxX34->Text = L"MDS";
			// 
			// checkBoxX35
			// 
			// 
			// 
			// 
			this->checkBoxX35->BackgroundStyle->Class = L"";
			this->checkBoxX35->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX35->Location = System::Drawing::Point(66, 4);
			this->checkBoxX35->Name = L"checkBoxX35";
			this->checkBoxX35->Size = System::Drawing::Size(56, 23);
			this->checkBoxX35->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX35->TabIndex = 1;
			this->checkBoxX35->Text = L"MDF";
			// 
			// checkBoxX36
			// 
			// 
			// 
			// 
			this->checkBoxX36->BackgroundStyle->Class = L"";
			this->checkBoxX36->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX36->Location = System::Drawing::Point(4, 4);
			this->checkBoxX36->Name = L"checkBoxX36";
			this->checkBoxX36->Size = System::Drawing::Size(56, 23);
			this->checkBoxX36->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX36->TabIndex = 0;
			this->checkBoxX36->Text = L"ISO";
			// 
			// groupPanel5
			// 
			this->groupPanel5->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel5->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel5->Controls->Add(this->checkBoxX37);
			this->groupPanel5->Controls->Add(this->checkBoxX38);
			this->groupPanel5->Controls->Add(this->checkBoxX39);
			this->groupPanel5->Controls->Add(this->checkBoxX40);
			this->groupPanel5->DrawTitleBox = false;
			this->groupPanel5->Location = System::Drawing::Point(30, 325);
			this->groupPanel5->Name = L"groupPanel5";
			this->groupPanel5->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel5->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel5->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel5->Style->BackColorGradientAngle = 90;
			this->groupPanel5->Style->BorderBottomWidth = 1;
			this->groupPanel5->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel5->Style->BorderLeftWidth = 1;
			this->groupPanel5->Style->BorderRightWidth = 1;
			this->groupPanel5->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel5->Style->BorderTopWidth = 1;
			this->groupPanel5->Style->Class = L"";
			this->groupPanel5->Style->CornerDiameter = 4;
			this->groupPanel5->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel5->Style->HideMnemonic = true;
			this->groupPanel5->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel5->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel5->StyleMouseDown->Class = L"";
			this->groupPanel5->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel5->StyleMouseOver->Class = L"";
			this->groupPanel5->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel5->TabIndex = 7;
			this->groupPanel5->Text = L"压缩文件";
			// 
			// checkBoxX37
			// 
			// 
			// 
			// 
			this->checkBoxX37->BackgroundStyle->Class = L"";
			this->checkBoxX37->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX37->Location = System::Drawing::Point(190, 4);
			this->checkBoxX37->Name = L"checkBoxX37";
			this->checkBoxX37->Size = System::Drawing::Size(56, 23);
			this->checkBoxX37->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX37->TabIndex = 3;
			this->checkBoxX37->Text = L"GZ";
			// 
			// checkBoxX38
			// 
			// 
			// 
			// 
			this->checkBoxX38->BackgroundStyle->Class = L"";
			this->checkBoxX38->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX38->Location = System::Drawing::Point(128, 4);
			this->checkBoxX38->Name = L"checkBoxX38";
			this->checkBoxX38->Size = System::Drawing::Size(56, 23);
			this->checkBoxX38->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX38->TabIndex = 2;
			this->checkBoxX38->Text = L"7Z";
			// 
			// checkBoxX39
			// 
			// 
			// 
			// 
			this->checkBoxX39->BackgroundStyle->Class = L"";
			this->checkBoxX39->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX39->Location = System::Drawing::Point(66, 4);
			this->checkBoxX39->Name = L"checkBoxX39";
			this->checkBoxX39->Size = System::Drawing::Size(56, 23);
			this->checkBoxX39->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX39->TabIndex = 1;
			this->checkBoxX39->Text = L"ZIP";
			// 
			// checkBoxX40
			// 
			// 
			// 
			// 
			this->checkBoxX40->BackgroundStyle->Class = L"";
			this->checkBoxX40->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX40->Location = System::Drawing::Point(4, 4);
			this->checkBoxX40->Name = L"checkBoxX40";
			this->checkBoxX40->Size = System::Drawing::Size(56, 23);
			this->checkBoxX40->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX40->TabIndex = 0;
			this->checkBoxX40->Text = L"RAR";
			// 
			// groupPanel6
			// 
			this->groupPanel6->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel6->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel6->Controls->Add(this->checkBoxX46);
			this->groupPanel6->Controls->Add(this->checkBoxX45);
			this->groupPanel6->Controls->Add(this->checkBoxX17);
			this->groupPanel6->Controls->Add(this->checkBoxX31);
			this->groupPanel6->Controls->Add(this->checkBoxX41);
			this->groupPanel6->Controls->Add(this->checkBoxX42);
			this->groupPanel6->Controls->Add(this->checkBoxX43);
			this->groupPanel6->Controls->Add(this->checkBoxX44);
			this->groupPanel6->DrawTitleBox = false;
			this->groupPanel6->Location = System::Drawing::Point(30, 374);
			this->groupPanel6->Name = L"groupPanel6";
			this->groupPanel6->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel6->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel6->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel6->Style->BackColorGradientAngle = 90;
			this->groupPanel6->Style->BorderBottomWidth = 1;
			this->groupPanel6->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel6->Style->BorderLeftWidth = 1;
			this->groupPanel6->Style->BorderRightWidth = 1;
			this->groupPanel6->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel6->Style->BorderTopWidth = 1;
			this->groupPanel6->Style->Class = L"";
			this->groupPanel6->Style->CornerDiameter = 4;
			this->groupPanel6->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel6->Style->HideMnemonic = true;
			this->groupPanel6->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel6->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel6->StyleMouseDown->Class = L"";
			this->groupPanel6->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel6->StyleMouseOver->Class = L"";
			this->groupPanel6->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel6->TabIndex = 8;
			this->groupPanel6->Text = L"图片文件";
			// 
			// checkBoxX17
			// 
			// 
			// 
			// 
			this->checkBoxX17->BackgroundStyle->Class = L"";
			this->checkBoxX17->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX17->Location = System::Drawing::Point(314, 4);
			this->checkBoxX17->Name = L"checkBoxX17";
			this->checkBoxX17->Size = System::Drawing::Size(56, 23);
			this->checkBoxX17->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX17->TabIndex = 5;
			this->checkBoxX17->Text = L"TIFF";
			// 
			// checkBoxX31
			// 
			// 
			// 
			// 
			this->checkBoxX31->BackgroundStyle->Class = L"";
			this->checkBoxX31->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX31->Location = System::Drawing::Point(252, 4);
			this->checkBoxX31->Name = L"checkBoxX31";
			this->checkBoxX31->Size = System::Drawing::Size(56, 23);
			this->checkBoxX31->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX31->TabIndex = 4;
			this->checkBoxX31->Text = L"TIF";
			// 
			// checkBoxX41
			// 
			// 
			// 
			// 
			this->checkBoxX41->BackgroundStyle->Class = L"";
			this->checkBoxX41->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX41->Location = System::Drawing::Point(190, 4);
			this->checkBoxX41->Name = L"checkBoxX41";
			this->checkBoxX41->Size = System::Drawing::Size(56, 23);
			this->checkBoxX41->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX41->TabIndex = 3;
			this->checkBoxX41->Text = L"TGA";
			// 
			// checkBoxX42
			// 
			// 
			// 
			// 
			this->checkBoxX42->BackgroundStyle->Class = L"";
			this->checkBoxX42->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX42->Location = System::Drawing::Point(128, 4);
			this->checkBoxX42->Name = L"checkBoxX42";
			this->checkBoxX42->Size = System::Drawing::Size(56, 23);
			this->checkBoxX42->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX42->TabIndex = 2;
			this->checkBoxX42->Text = L"BMP";
			// 
			// checkBoxX43
			// 
			// 
			// 
			// 
			this->checkBoxX43->BackgroundStyle->Class = L"";
			this->checkBoxX43->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX43->Location = System::Drawing::Point(66, 4);
			this->checkBoxX43->Name = L"checkBoxX43";
			this->checkBoxX43->Size = System::Drawing::Size(56, 23);
			this->checkBoxX43->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX43->TabIndex = 1;
			this->checkBoxX43->Text = L"JPEG";
			// 
			// checkBoxX44
			// 
			// 
			// 
			// 
			this->checkBoxX44->BackgroundStyle->Class = L"";
			this->checkBoxX44->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX44->Location = System::Drawing::Point(4, 4);
			this->checkBoxX44->Name = L"checkBoxX44";
			this->checkBoxX44->Size = System::Drawing::Size(56, 23);
			this->checkBoxX44->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX44->TabIndex = 0;
			this->checkBoxX44->Text = L"JPG";
			// 
			// checkBoxX45
			// 
			// 
			// 
			// 
			this->checkBoxX45->BackgroundStyle->Class = L"";
			this->checkBoxX45->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX45->Location = System::Drawing::Point(376, 4);
			this->checkBoxX45->Name = L"checkBoxX45";
			this->checkBoxX45->Size = System::Drawing::Size(56, 23);
			this->checkBoxX45->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX45->TabIndex = 6;
			this->checkBoxX45->Text = L"PNG";
			// 
			// checkBoxX46
			// 
			// 
			// 
			// 
			this->checkBoxX46->BackgroundStyle->Class = L"";
			this->checkBoxX46->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX46->Location = System::Drawing::Point(438, 4);
			this->checkBoxX46->Name = L"checkBoxX46";
			this->checkBoxX46->Size = System::Drawing::Size(56, 23);
			this->checkBoxX46->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX46->TabIndex = 7;
			this->checkBoxX46->Text = L"GIF";
			// 
			// groupPanel7
			// 
			this->groupPanel7->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupPanel7->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupPanel7->Controls->Add(this->checkBoxX51);
			this->groupPanel7->Controls->Add(this->checkBoxX52);
			this->groupPanel7->Controls->Add(this->checkBoxX53);
			this->groupPanel7->Controls->Add(this->checkBoxX54);
			this->groupPanel7->DrawTitleBox = false;
			this->groupPanel7->Location = System::Drawing::Point(30, 423);
			this->groupPanel7->Name = L"groupPanel7";
			this->groupPanel7->Size = System::Drawing::Size(525, 48);
			// 
			// 
			// 
			this->groupPanel7->Style->BackColor = System::Drawing::Color::Transparent;
			this->groupPanel7->Style->BackColor2 = System::Drawing::Color::Transparent;
			this->groupPanel7->Style->BackColorGradientAngle = 90;
			this->groupPanel7->Style->BorderBottomWidth = 1;
			this->groupPanel7->Style->BorderColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupPanel7->Style->BorderLeftWidth = 1;
			this->groupPanel7->Style->BorderRightWidth = 1;
			this->groupPanel7->Style->BorderTop = DevComponents::DotNetBar::eStyleBorderType::Solid;
			this->groupPanel7->Style->BorderTopWidth = 1;
			this->groupPanel7->Style->Class = L"";
			this->groupPanel7->Style->CornerDiameter = 4;
			this->groupPanel7->Style->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel7->Style->HideMnemonic = true;
			this->groupPanel7->Style->TextColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupPanel7->Style->TextLineAlignment = DevComponents::DotNetBar::eStyleTextAlignment::Near;
			// 
			// 
			// 
			this->groupPanel7->StyleMouseDown->Class = L"";
			this->groupPanel7->StyleMouseDown->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			// 
			// 
			// 
			this->groupPanel7->StyleMouseOver->Class = L"";
			this->groupPanel7->StyleMouseOver->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupPanel7->TabIndex = 9;
			this->groupPanel7->Text = L"说明文件";
			// 
			// checkBoxX51
			// 
			// 
			// 
			// 
			this->checkBoxX51->BackgroundStyle->Class = L"";
			this->checkBoxX51->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX51->Location = System::Drawing::Point(190, 4);
			this->checkBoxX51->Name = L"checkBoxX51";
			this->checkBoxX51->Size = System::Drawing::Size(56, 23);
			this->checkBoxX51->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX51->TabIndex = 3;
			this->checkBoxX51->Text = L"TXT";
			// 
			// checkBoxX52
			// 
			// 
			// 
			// 
			this->checkBoxX52->BackgroundStyle->Class = L"";
			this->checkBoxX52->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX52->Location = System::Drawing::Point(128, 4);
			this->checkBoxX52->Name = L"checkBoxX52";
			this->checkBoxX52->Size = System::Drawing::Size(56, 23);
			this->checkBoxX52->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX52->TabIndex = 2;
			this->checkBoxX52->Text = L"DOCX";
			// 
			// checkBoxX53
			// 
			// 
			// 
			// 
			this->checkBoxX53->BackgroundStyle->Class = L"";
			this->checkBoxX53->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX53->Location = System::Drawing::Point(66, 4);
			this->checkBoxX53->Name = L"checkBoxX53";
			this->checkBoxX53->Size = System::Drawing::Size(56, 23);
			this->checkBoxX53->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX53->TabIndex = 1;
			this->checkBoxX53->Text = L"DOC";
			// 
			// checkBoxX54
			// 
			// 
			// 
			// 
			this->checkBoxX54->BackgroundStyle->Class = L"";
			this->checkBoxX54->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->checkBoxX54->Location = System::Drawing::Point(4, 4);
			this->checkBoxX54->Name = L"checkBoxX54";
			this->checkBoxX54->Size = System::Drawing::Size(56, 23);
			this->checkBoxX54->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->checkBoxX54->TabIndex = 0;
			this->checkBoxX54->Text = L"NFO";
			// 
			// FocusUserSettingDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 541);
			this->Controls->Add(this->panelEx1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FocusUserSettingDlg";
			this->Text = L"FocusUserSettingDlg";
			this->Load += gcnew System::EventHandler(this, &FocusUserSettingDlg::FocusUserSettingDlg_Load);
			this->panelEx1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->groupPanel1->ResumeLayout(false);
			this->groupPanel2->ResumeLayout(false);
			this->groupPanel3->ResumeLayout(false);
			this->groupPanel4->ResumeLayout(false);
			this->groupPanel5->ResumeLayout(false);
			this->groupPanel6->ResumeLayout(false);
			this->groupPanel7->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FocusUserSettingDlg_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

};
}
