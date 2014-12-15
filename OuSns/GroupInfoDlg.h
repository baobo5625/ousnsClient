#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for GroupInfoDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
//	public ref class GroupInfoDlg : public System::Windows::Forms::Form
	public ref class GroupInfoDlg : DevComponents::DotNetBar::Office2007Form
	{
	public:
		GroupInfoDlg(void)
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
		~GroupInfoDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	protected: 
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl1;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel1;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem2;
	private: DevComponents::DotNetBar::LabelItem^  labelItem3;
	private: DevComponents::DotNetBar::LabelItem^  labelItem4;
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel4;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem4;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel3;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem3;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel2;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX3;
	private: DevComponents::DotNetBar::ButtonX^  buttonX2;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX8;
	private: DevComponents::DotNetBar::LabelX^  labelX8;








	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX2;
	private: DevComponents::DotNetBar::LabelX^  labelX2;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX1;
	private: DevComponents::DotNetBar::LabelX^  labelX1;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX7;
	private: DevComponents::DotNetBar::LabelX^  labelX7;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX6;
	private: DevComponents::DotNetBar::LabelX^  labelX6;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX3;
	private: DevComponents::DotNetBar::LabelX^  labelX3;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX4;
	private: DevComponents::DotNetBar::LabelX^  labelX4;
	private: DevComponents::DotNetBar::PanelEx^  panelEx2;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: DevComponents::DotNetBar::Bar^  bar1;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem1;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem2;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem3;
	private: DevComponents::DotNetBar::Controls::ListViewEx^  listViewEx1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;














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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->superTabControl1 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel2 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->panelEx2 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->bar1 = (gcnew DevComponents::DotNetBar::Bar());
			this->buttonItem1 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem2 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem3 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->superTabItem2 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel3 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->superTabItem3 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel1 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->textBoxX7 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX7 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX6 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX6 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX3 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX3 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX4 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX8 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX8 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX2 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX2 = (gcnew DevComponents::DotNetBar::LabelX());
			this->textBoxX1 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->superTabItem1 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel4 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->superTabItem4 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->labelItem1 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem2 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem3 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem4 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->buttonX3 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->buttonX2 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->listViewEx1 = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panelEx1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->BeginInit();
			this->superTabControl1->SuspendLayout();
			this->superTabControlPanel2->SuspendLayout();
			this->panelEx2->SuspendLayout();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->BeginInit();
			this->superTabControlPanel1->SuspendLayout();
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
			this->panelEx1->Size = System::Drawing::Size(545, 435);
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
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainer1->Panel1->Controls->Add(this->superTabControl1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->buttonX3);
			this->splitContainer1->Panel2->Controls->Add(this->buttonX2);
			this->splitContainer1->Panel2->Controls->Add(this->buttonX1);
			this->splitContainer1->Size = System::Drawing::Size(545, 435);
			this->splitContainer1->SplitterDistance = 385;
			this->splitContainer1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 87);
			this->pictureBox1->TabIndex = 3;
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
			this->superTabControl1->Controls->Add(this->superTabControlPanel2);
			this->superTabControl1->Controls->Add(this->superTabControlPanel3);
			this->superTabControl1->Controls->Add(this->superTabControlPanel4);
			this->superTabControl1->Controls->Add(this->superTabControlPanel1);
			this->superTabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl1->FixedTabSize = System::Drawing::Size(100, 25);
			this->superTabControl1->Location = System::Drawing::Point(0, 0);
			this->superTabControl1->Name = L"superTabControl1";
			this->superTabControl1->ReorderTabsEnabled = false;
			this->superTabControl1->SelectedTabFont = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl1->SelectedTabIndex = 4;
			this->superTabControl1->Size = System::Drawing::Size(545, 385);
			this->superTabControl1->TabAlignment = DevComponents::DotNetBar::eTabStripAlignment::Left;
			this->superTabControl1->TabFont = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl1->TabIndex = 4;
			this->superTabControl1->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(8) {this->labelItem1, this->labelItem2, 
				this->labelItem3, this->labelItem4, this->superTabItem1, this->superTabItem2, this->superTabItem3, this->superTabItem4});
			this->superTabControl1->TabVerticalSpacing = 0;
			this->superTabControl1->Text = L"superTabControl1";
			this->superTabControl1->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel2
			// 
			this->superTabControlPanel2->Controls->Add(this->panelEx2);
			this->superTabControlPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel2->Location = System::Drawing::Point(102, 0);
			this->superTabControlPanel2->Name = L"superTabControlPanel2";
			this->superTabControlPanel2->Size = System::Drawing::Size(443, 385);
			this->superTabControlPanel2->TabIndex = 0;
			this->superTabControlPanel2->TabItem = this->superTabItem2;
			// 
			// panelEx2
			// 
			this->panelEx2->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx2->Controls->Add(this->splitContainer2);
			this->panelEx2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx2->Location = System::Drawing::Point(0, 0);
			this->panelEx2->Name = L"panelEx2";
			this->panelEx2->Size = System::Drawing::Size(443, 385);
			this->panelEx2->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx2->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx2->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx2->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx2->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx2->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx2->Style->GradientAngle = 90;
			this->panelEx2->TabIndex = 0;
			this->panelEx2->Text = L"panelEx2";
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->listViewEx1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->bar1);
			this->splitContainer2->Size = System::Drawing::Size(443, 385);
			this->splitContainer2->SplitterDistance = 354;
			this->splitContainer2->TabIndex = 0;
			// 
			// bar1
			// 
			this->bar1->AntiAlias = true;
			this->bar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bar1->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->buttonItem1, this->buttonItem2, 
				this->buttonItem3});
			this->bar1->Location = System::Drawing::Point(0, 2);
			this->bar1->Name = L"bar1";
			this->bar1->Size = System::Drawing::Size(443, 25);
			this->bar1->Stretch = true;
			this->bar1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar1->TabIndex = 0;
			this->bar1->TabStop = false;
			this->bar1->Text = L"bar1";
			// 
			// buttonItem1
			// 
			this->buttonItem1->Name = L"buttonItem1";
			this->buttonItem1->Text = L"添加成员";
			// 
			// buttonItem2
			// 
			this->buttonItem2->Name = L"buttonItem2";
			this->buttonItem2->Text = L"删除成员";
			// 
			// buttonItem3
			// 
			this->buttonItem3->Name = L"buttonItem3";
			this->buttonItem3->Text = L"设置管理员";
			// 
			// superTabItem2
			// 
			this->superTabItem2->AttachedControl = this->superTabControlPanel2;
			this->superTabItem2->GlobalItem = false;
			this->superTabItem2->Name = L"superTabItem2";
			this->superTabItem2->Text = L"群成员";
			// 
			// superTabControlPanel3
			// 
			this->superTabControlPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel3->Location = System::Drawing::Point(102, 0);
			this->superTabControlPanel3->Name = L"superTabControlPanel3";
			this->superTabControlPanel3->Size = System::Drawing::Size(443, 385);
			this->superTabControlPanel3->TabIndex = 0;
			this->superTabControlPanel3->TabItem = this->superTabItem3;
			// 
			// superTabItem3
			// 
			this->superTabItem3->AttachedControl = this->superTabControlPanel3;
			this->superTabItem3->GlobalItem = false;
			this->superTabItem3->Name = L"superTabItem3";
			this->superTabItem3->Text = L"群名片";
			// 
			// superTabControlPanel1
			// 
			this->superTabControlPanel1->Controls->Add(this->textBoxX7);
			this->superTabControlPanel1->Controls->Add(this->labelX7);
			this->superTabControlPanel1->Controls->Add(this->textBoxX6);
			this->superTabControlPanel1->Controls->Add(this->labelX6);
			this->superTabControlPanel1->Controls->Add(this->textBoxX3);
			this->superTabControlPanel1->Controls->Add(this->labelX3);
			this->superTabControlPanel1->Controls->Add(this->textBoxX4);
			this->superTabControlPanel1->Controls->Add(this->labelX4);
			this->superTabControlPanel1->Controls->Add(this->textBoxX8);
			this->superTabControlPanel1->Controls->Add(this->labelX8);
			this->superTabControlPanel1->Controls->Add(this->textBoxX2);
			this->superTabControlPanel1->Controls->Add(this->labelX2);
			this->superTabControlPanel1->Controls->Add(this->textBoxX1);
			this->superTabControlPanel1->Controls->Add(this->labelX1);
			this->superTabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel1->Location = System::Drawing::Point(102, 0);
			this->superTabControlPanel1->Name = L"superTabControlPanel1";
			this->superTabControlPanel1->Size = System::Drawing::Size(443, 385);
			this->superTabControlPanel1->TabIndex = 1;
			this->superTabControlPanel1->TabItem = this->superTabItem1;
			// 
			// textBoxX7
			// 
			// 
			// 
			// 
			this->textBoxX7->Border->Class = L"TextBoxBorder";
			this->textBoxX7->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX7->Location = System::Drawing::Point(9, 295);
			this->textBoxX7->Multiline = true;
			this->textBoxX7->Name = L"textBoxX7";
			this->textBoxX7->Size = System::Drawing::Size(404, 73);
			this->textBoxX7->TabIndex = 23;
			// 
			// labelX7
			// 
			// 
			// 
			// 
			this->labelX7->BackgroundStyle->Class = L"";
			this->labelX7->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX7->Location = System::Drawing::Point(9, 265);
			this->labelX7->Name = L"labelX7";
			this->labelX7->Size = System::Drawing::Size(191, 23);
			this->labelX7->TabIndex = 22;
			this->labelX7->Text = L"群的简介:";
			// 
			// textBoxX6
			// 
			// 
			// 
			// 
			this->textBoxX6->Border->Class = L"TextBoxBorder";
			this->textBoxX6->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX6->Location = System::Drawing::Point(9, 121);
			this->textBoxX6->Name = L"textBoxX6";
			this->textBoxX6->Size = System::Drawing::Size(191, 20);
			this->textBoxX6->TabIndex = 19;
			// 
			// labelX6
			// 
			// 
			// 
			// 
			this->labelX6->BackgroundStyle->Class = L"";
			this->labelX6->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX6->Location = System::Drawing::Point(9, 101);
			this->labelX6->Name = L"labelX6";
			this->labelX6->Size = System::Drawing::Size(191, 23);
			this->labelX6->TabIndex = 18;
			this->labelX6->Text = L"分类:";
			// 
			// textBoxX3
			// 
			// 
			// 
			// 
			this->textBoxX3->Border->Class = L"TextBoxBorder";
			this->textBoxX3->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX3->Location = System::Drawing::Point(222, 75);
			this->textBoxX3->Name = L"textBoxX3";
			this->textBoxX3->Size = System::Drawing::Size(191, 20);
			this->textBoxX3->TabIndex = 17;
			// 
			// labelX3
			// 
			// 
			// 
			// 
			this->labelX3->BackgroundStyle->Class = L"";
			this->labelX3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX3->Location = System::Drawing::Point(222, 55);
			this->labelX3->Name = L"labelX3";
			this->labelX3->Size = System::Drawing::Size(191, 23);
			this->labelX3->TabIndex = 16;
			this->labelX3->Text = L"备注:";
			// 
			// textBoxX4
			// 
			// 
			// 
			// 
			this->textBoxX4->Border->Class = L"TextBoxBorder";
			this->textBoxX4->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX4->Location = System::Drawing::Point(9, 75);
			this->textBoxX4->Name = L"textBoxX4";
			this->textBoxX4->Size = System::Drawing::Size(191, 20);
			this->textBoxX4->TabIndex = 15;
			// 
			// labelX4
			// 
			// 
			// 
			// 
			this->labelX4->BackgroundStyle->Class = L"";
			this->labelX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX4->Location = System::Drawing::Point(9, 55);
			this->labelX4->Name = L"labelX4";
			this->labelX4->Size = System::Drawing::Size(191, 23);
			this->labelX4->TabIndex = 14;
			this->labelX4->Text = L"名称:";
			// 
			// textBoxX8
			// 
			// 
			// 
			// 
			this->textBoxX8->Border->Class = L"TextBoxBorder";
			this->textBoxX8->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX8->Location = System::Drawing::Point(9, 184);
			this->textBoxX8->Multiline = true;
			this->textBoxX8->Name = L"textBoxX8";
			this->textBoxX8->Size = System::Drawing::Size(404, 73);
			this->textBoxX8->TabIndex = 13;
			// 
			// labelX8
			// 
			// 
			// 
			// 
			this->labelX8->BackgroundStyle->Class = L"";
			this->labelX8->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX8->Location = System::Drawing::Point(9, 154);
			this->labelX8->Name = L"labelX8";
			this->labelX8->Size = System::Drawing::Size(191, 23);
			this->labelX8->TabIndex = 12;
			this->labelX8->Text = L"群内公告(仅成员可见):";
			// 
			// textBoxX2
			// 
			// 
			// 
			// 
			this->textBoxX2->Border->Class = L"TextBoxBorder";
			this->textBoxX2->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX2->Location = System::Drawing::Point(222, 29);
			this->textBoxX2->Name = L"textBoxX2";
			this->textBoxX2->Size = System::Drawing::Size(191, 20);
			this->textBoxX2->TabIndex = 3;
			// 
			// labelX2
			// 
			// 
			// 
			// 
			this->labelX2->BackgroundStyle->Class = L"";
			this->labelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX2->Location = System::Drawing::Point(222, 9);
			this->labelX2->Name = L"labelX2";
			this->labelX2->Size = System::Drawing::Size(191, 23);
			this->labelX2->TabIndex = 2;
			this->labelX2->Text = L"创建人:";
			// 
			// textBoxX1
			// 
			// 
			// 
			// 
			this->textBoxX1->Border->Class = L"TextBoxBorder";
			this->textBoxX1->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX1->Location = System::Drawing::Point(9, 29);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(191, 20);
			this->textBoxX1->TabIndex = 1;
			// 
			// labelX1
			// 
			// 
			// 
			// 
			this->labelX1->BackgroundStyle->Class = L"";
			this->labelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX1->Location = System::Drawing::Point(9, 9);
			this->labelX1->Name = L"labelX1";
			this->labelX1->Size = System::Drawing::Size(191, 23);
			this->labelX1->TabIndex = 0;
			this->labelX1->Text = L"号码:";
			// 
			// superTabItem1
			// 
			this->superTabItem1->AttachedControl = this->superTabControlPanel1;
			this->superTabItem1->Category = L"property1";
			this->superTabItem1->CloseButtonVisible = false;
			this->superTabItem1->GlobalItem = false;
			this->superTabItem1->Name = L"superTabItem1";
			this->superTabItem1->Text = L"群资料";
			// 
			// superTabControlPanel4
			// 
			this->superTabControlPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel4->Location = System::Drawing::Point(102, 0);
			this->superTabControlPanel4->Name = L"superTabControlPanel4";
			this->superTabControlPanel4->Size = System::Drawing::Size(443, 385);
			this->superTabControlPanel4->TabIndex = 0;
			this->superTabControlPanel4->TabItem = this->superTabItem4;
			// 
			// superTabItem4
			// 
			this->superTabItem4->AttachedControl = this->superTabControlPanel4;
			this->superTabItem4->GlobalItem = false;
			this->superTabItem4->Name = L"superTabItem4";
			this->superTabItem4->Text = L"群设置";
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
			// buttonX3
			// 
			this->buttonX3->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX3->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX3->Location = System::Drawing::Point(459, 9);
			this->buttonX3->Name = L"buttonX3";
			this->buttonX3->Size = System::Drawing::Size(75, 23);
			this->buttonX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX3->TabIndex = 2;
			this->buttonX3->Text = L"应用";
			// 
			// buttonX2
			// 
			this->buttonX2->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX2->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX2->Location = System::Drawing::Point(378, 9);
			this->buttonX2->Name = L"buttonX2";
			this->buttonX2->Size = System::Drawing::Size(75, 23);
			this->buttonX2->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX2->TabIndex = 1;
			this->buttonX2->Text = L"取消";
			// 
			// buttonX1
			// 
			this->buttonX1->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX1->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX1->Location = System::Drawing::Point(297, 9);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(75, 23);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 0;
			this->buttonX1->Text = L"确定";
			// 
			// listViewEx1
			// 
			// 
			// 
			// 
			this->listViewEx1->Border->Class = L"ListViewBorder";
			this->listViewEx1->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->listViewEx1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {this->columnHeader1, 
				this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5});
			this->listViewEx1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewEx1->FullRowSelect = true;
			this->listViewEx1->Location = System::Drawing::Point(0, 0);
			this->listViewEx1->Name = L"listViewEx1";
			this->listViewEx1->Size = System::Drawing::Size(443, 354);
			this->listViewEx1->TabIndex = 0;
			this->listViewEx1->UseCompatibleStateImageBehavior = false;
			this->listViewEx1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Tag = L"2";
			this->columnHeader1->Text = L"";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Tag = L"0";
			this->columnHeader2->Text = L"帐号";
			// 
			// columnHeader3
			// 
			this->columnHeader3->Tag = L"0";
			this->columnHeader3->Text = L"昵称";
			// 
			// columnHeader4
			// 
			this->columnHeader4->Tag = L"0";
			this->columnHeader4->Text = L"性别";
			this->columnHeader4->Width = 62;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Tag = L"0";
			this->columnHeader5->Text = L"最后发言";
			// 
			// GroupInfoDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 435);
			this->Controls->Add(this->panelEx1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GroupInfoDlg";
			this->Text = L"GroupInfoDlg";
			this->panelEx1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->EndInit();
			this->superTabControl1->ResumeLayout(false);
			this->superTabControlPanel2->ResumeLayout(false);
			this->panelEx2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->EndInit();
			this->superTabControlPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void dataGridViewX1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
};
}
