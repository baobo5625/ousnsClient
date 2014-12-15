#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for GroupFileManagementDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
//	public ref class GroupFileManagementDlg : public System::Windows::Forms::Form
	public ref class GroupFileManagementDlg : DevComponents::DotNetBar::Office2007Form
	{
	public:
		GroupFileManagementDlg(void)
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
		~GroupFileManagementDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::Bar^  bar1;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem2;








	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;

	private: DevComponents::DotNetBar::LabelX^  labelX1;
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	private: DevComponents::DotNetBar::LabelX^  labelX2;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  comboBoxEx1;
	private: DevComponents::DotNetBar::LabelX^  labelX3;
	private: DevComponents::DotNetBar::LabelX^  labelX4;
	private: DevComponents::Editors::ComboItem^  comboItem1;
	private: DevComponents::Editors::ComboItem^  comboItem2;
	private: DevComponents::Editors::ComboItem^  comboItem3;
	private: DevComponents::DotNetBar::ItemPanel^  itemPanel1;





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
			this->bar1 = (gcnew DevComponents::DotNetBar::Bar());
			this->buttonItem1 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem2 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
			this->comboBoxEx1 = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem1 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem2 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem3 = (gcnew DevComponents::Editors::ComboItem());
			this->labelX3 = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX2 = (gcnew DevComponents::DotNetBar::LabelX());
			this->itemPanel1 = (gcnew DevComponents::DotNetBar::ItemPanel());
			this->labelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->panelEx1 = (gcnew DevComponents::DotNetBar::PanelEx());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->panelEx1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bar1
			// 
			this->bar1->AntiAlias = true;
			this->bar1->Dock = System::Windows::Forms::DockStyle::Top;
			this->bar1->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->buttonItem1, this->buttonItem2});
			this->bar1->Location = System::Drawing::Point(0, 0);
			this->bar1->Name = L"bar1";
			this->bar1->Size = System::Drawing::Size(343, 25);
			this->bar1->Stretch = true;
			this->bar1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar1->TabIndex = 0;
			this->bar1->TabStop = false;
			this->bar1->Text = L"bar1";
			// 
			// buttonItem1
			// 
			this->buttonItem1->Name = L"buttonItem1";
			this->buttonItem1->Text = L"上传";
			// 
			// buttonItem2
			// 
			this->buttonItem2->Name = L"buttonItem2";
			this->buttonItem2->Text = L"刷新";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
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
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			this->splitContainer1->Panel1MinSize = 20;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->labelX1);
			this->splitContainer1->Panel2MinSize = 20;
			this->splitContainer1->Size = System::Drawing::Size(343, 303);
			this->splitContainer1->SplitterDistance = 279;
			this->splitContainer1->TabIndex = 0;
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
			this->splitContainer2->Panel1->Controls->Add(this->labelX4);
			this->splitContainer2->Panel1->Controls->Add(this->comboBoxEx1);
			this->splitContainer2->Panel1->Controls->Add(this->labelX3);
			this->splitContainer2->Panel1->Controls->Add(this->labelX2);
			this->splitContainer2->Panel1MinSize = 20;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->itemPanel1);
			this->splitContainer2->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GroupFileManagementDlg::splitContainer2_Panel2_Paint);
			this->splitContainer2->Panel2MinSize = 20;
			this->splitContainer2->Size = System::Drawing::Size(343, 279);
			this->splitContainer2->SplitterDistance = 20;
			this->splitContainer2->TabIndex = 0;
			// 
			// labelX4
			// 
			// 
			// 
			// 
			this->labelX4->BackgroundStyle->Class = L"";
			this->labelX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX4->Dock = System::Windows::Forms::DockStyle::Right;
			this->labelX4->Location = System::Drawing::Point(158, 0);
			this->labelX4->Name = L"labelX4";
			this->labelX4->Size = System::Drawing::Size(41, 20);
			this->labelX4->TabIndex = 3;
			this->labelX4->Text = L"显示:";
			this->labelX4->TextAlignment = System::Drawing::StringAlignment::Far;
			// 
			// comboBoxEx1
			// 
			this->comboBoxEx1->DisplayMember = L"Text";
			this->comboBoxEx1->Dock = System::Windows::Forms::DockStyle::Right;
			this->comboBoxEx1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxEx1->FormattingEnabled = true;
			this->comboBoxEx1->ItemHeight = 14;
			this->comboBoxEx1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {this->comboItem1, this->comboItem2, this->comboItem3});
			this->comboBoxEx1->Location = System::Drawing::Point(199, 0);
			this->comboBoxEx1->Name = L"comboBoxEx1";
			this->comboBoxEx1->Size = System::Drawing::Size(69, 20);
			this->comboBoxEx1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->comboBoxEx1->TabIndex = 2;
			// 
			// comboItem1
			// 
			this->comboItem1->Text = L"30";
			// 
			// comboItem2
			// 
			this->comboItem2->Text = L"30";
			// 
			// comboItem3
			// 
			this->comboItem3->Text = L"50";
			// 
			// labelX3
			// 
			// 
			// 
			// 
			this->labelX3->BackgroundStyle->Class = L"";
			this->labelX3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX3->Dock = System::Windows::Forms::DockStyle::Right;
			this->labelX3->Location = System::Drawing::Point(268, 0);
			this->labelX3->Name = L"labelX3";
			this->labelX3->PaddingRight = 5;
			this->labelX3->Size = System::Drawing::Size(75, 20);
			this->labelX3->TabIndex = 1;
			this->labelX3->Text = L"显示全部>>";
			this->labelX3->TextAlignment = System::Drawing::StringAlignment::Far;
			// 
			// labelX2
			// 
			// 
			// 
			// 
			this->labelX2->BackgroundStyle->Class = L"";
			this->labelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX2->Dock = System::Windows::Forms::DockStyle::Left;
			this->labelX2->Location = System::Drawing::Point(0, 0);
			this->labelX2->Name = L"labelX2";
			this->labelX2->PaddingLeft = 5;
			this->labelX2->Size = System::Drawing::Size(105, 20);
			this->labelX2->TabIndex = 0;
			this->labelX2->Text = L"最近上传的文件";
			// 
			// itemPanel1
			// 
			this->itemPanel1->AutoScroll = true;
			// 
			// 
			// 
			this->itemPanel1->BackgroundStyle->Class = L"ItemPanel";
			this->itemPanel1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->itemPanel1->ContainerControlProcessDialogKey = true;
			this->itemPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->itemPanel1->LayoutOrientation = DevComponents::DotNetBar::eOrientation::Vertical;
			this->itemPanel1->Location = System::Drawing::Point(0, 0);
			this->itemPanel1->Name = L"itemPanel1";
			this->itemPanel1->Size = System::Drawing::Size(343, 255);
			this->itemPanel1->TabIndex = 0;
			this->itemPanel1->Text = L"itemPanel1";
			// 
			// labelX1
			// 
			// 
			// 
			// 
			this->labelX1->BackgroundStyle->Class = L"";
			this->labelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelX1->Location = System::Drawing::Point(0, 0);
			this->labelX1->Name = L"labelX1";
			this->labelX1->PaddingLeft = 10;
			this->labelX1->PaddingRight = 10;
			this->labelX1->Size = System::Drawing::Size(343, 20);
			this->labelX1->TabIndex = 0;
			this->labelX1->Text = L"永久空间:";
			// 
			// panelEx1
			// 
			this->panelEx1->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->splitContainer1);
			this->panelEx1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx1->Location = System::Drawing::Point(0, 25);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Size = System::Drawing::Size(343, 303);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 1;
			this->panelEx1->Text = L"panelEx1";
			// 
			// GroupFileManagementDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 328);
			this->Controls->Add(this->panelEx1);
			this->Controls->Add(this->bar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GroupFileManagementDlg";
			this->Text = L"GroupFileManagementDlg";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->ResumeLayout(false);
			this->panelEx1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void splitContainer2_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}
