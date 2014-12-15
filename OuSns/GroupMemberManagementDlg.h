#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for GroupMemberManagementDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
//	public ref class GroupMemberManagementDlg : public System::Windows::Forms::Form
	public ref class GroupMemberManagementDlg : DevComponents::DotNetBar::Office2007Form
	{
	public:
		GroupMemberManagementDlg(void)
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
		~GroupMemberManagementDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX1;
	private: DevComponents::DotNetBar::LabelX^  labelX1;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  comboBoxEx1;
	private: DevComponents::AdvTree::AdvTree^  advTree1;
	private: DevComponents::AdvTree::Node^  node1;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector1;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle1;
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;
	private: DevComponents::DotNetBar::LabelX^  labelX2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX2;
	private: DevComponents::AdvTree::AdvTree^  advTree2;

	private: DevComponents::AdvTree::NodeConnector^  nodeConnector2;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX3;
	private: DevComponents::DotNetBar::ButtonX^  buttonX4;
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
			this->textBoxX1 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->labelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->comboBoxEx1 = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->advTree1 = (gcnew DevComponents::AdvTree::AdvTree());
			this->node1 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector1 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle1 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->labelX2 = (gcnew DevComponents::DotNetBar::LabelX());
			this->buttonX2 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->advTree2 = (gcnew DevComponents::AdvTree::AdvTree());
			this->nodeConnector2 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle2 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->buttonX3 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->buttonX4 = (gcnew DevComponents::DotNetBar::ButtonX());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxX1
			// 
			// 
			// 
			// 
			this->textBoxX1->Border->Class = L"TextBoxBorder";
			this->textBoxX1->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX1->Location = System::Drawing::Point(13, 13);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(166, 20);
			this->textBoxX1->TabIndex = 0;
			// 
			// labelX1
			// 
			// 
			// 
			// 
			this->labelX1->BackgroundStyle->Class = L"";
			this->labelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX1->Location = System::Drawing::Point(13, 40);
			this->labelX1->Name = L"labelX1";
			this->labelX1->Size = System::Drawing::Size(61, 23);
			this->labelX1->TabIndex = 1;
			this->labelX1->Text = L"选择范围:";
			// 
			// comboBoxEx1
			// 
			this->comboBoxEx1->DisplayMember = L"Text";
			this->comboBoxEx1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxEx1->FormattingEnabled = true;
			this->comboBoxEx1->ItemHeight = 14;
			this->comboBoxEx1->Location = System::Drawing::Point(69, 43);
			this->comboBoxEx1->Name = L"comboBoxEx1";
			this->comboBoxEx1->Size = System::Drawing::Size(110, 20);
			this->comboBoxEx1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->comboBoxEx1->TabIndex = 2;
			// 
			// advTree1
			// 
			this->advTree1->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->advTree1->AllowDrop = true;
			this->advTree1->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->advTree1->BackgroundStyle->Class = L"TreeBorderKey";
			this->advTree1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->advTree1->Location = System::Drawing::Point(13, 69);
			this->advTree1->Name = L"advTree1";
			this->advTree1->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
			this->advTree1->NodesConnector = this->nodeConnector1;
			this->advTree1->NodeStyle = this->elementStyle1;
			this->advTree1->PathSeparator = L";";
			this->advTree1->Size = System::Drawing::Size(166, 263);
			this->advTree1->Styles->Add(this->elementStyle1);
			this->advTree1->TabIndex = 3;
			this->advTree1->Text = L"advTree1";
			// 
			// node1
			// 
			this->node1->Expanded = true;
			this->node1->Name = L"node1";
			this->node1->Text = L"node1";
			// 
			// nodeConnector1
			// 
			this->nodeConnector1->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle1
			// 
			this->elementStyle1->Class = L"";
			this->elementStyle1->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle1->Name = L"elementStyle1";
			this->elementStyle1->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// buttonX1
			// 
			this->buttonX1->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX1->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX1->Location = System::Drawing::Point(185, 111);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(75, 23);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 4;
			this->buttonX1->Text = L"添加>";
			// 
			// labelX2
			// 
			// 
			// 
			// 
			this->labelX2->BackgroundStyle->Class = L"";
			this->labelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX2->Location = System::Drawing::Point(266, 9);
			this->labelX2->Name = L"labelX2";
			this->labelX2->Size = System::Drawing::Size(75, 23);
			this->labelX2->TabIndex = 5;
			this->labelX2->Text = L"已选联系人:";
			// 
			// buttonX2
			// 
			this->buttonX2->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX2->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX2->Location = System::Drawing::Point(185, 215);
			this->buttonX2->Name = L"buttonX2";
			this->buttonX2->Size = System::Drawing::Size(75, 23);
			this->buttonX2->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX2->TabIndex = 6;
			this->buttonX2->Text = L"<删除";
			// 
			// advTree2
			// 
			this->advTree2->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->advTree2->AllowDrop = true;
			this->advTree2->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->advTree2->BackgroundStyle->Class = L"TreeBorderKey";
			this->advTree2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->advTree2->Location = System::Drawing::Point(266, 40);
			this->advTree2->Name = L"advTree2";
			this->advTree2->NodesConnector = this->nodeConnector2;
			this->advTree2->NodeStyle = this->elementStyle2;
			this->advTree2->PathSeparator = L";";
			this->advTree2->Size = System::Drawing::Size(166, 292);
			this->advTree2->Styles->Add(this->elementStyle2);
			this->advTree2->TabIndex = 7;
			this->advTree2->Text = L"advTree2";
			// 
			// nodeConnector2
			// 
			this->nodeConnector2->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle2
			// 
			this->elementStyle2->Class = L"";
			this->elementStyle2->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle2->Name = L"elementStyle2";
			this->elementStyle2->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// buttonX3
			// 
			this->buttonX3->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX3->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX3->Location = System::Drawing::Point(266, 346);
			this->buttonX3->Name = L"buttonX3";
			this->buttonX3->Size = System::Drawing::Size(75, 23);
			this->buttonX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX3->TabIndex = 8;
			this->buttonX3->Text = L"确定";
			// 
			// buttonX4
			// 
			this->buttonX4->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX4->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX4->Location = System::Drawing::Point(357, 346);
			this->buttonX4->Name = L"buttonX4";
			this->buttonX4->Size = System::Drawing::Size(75, 23);
			this->buttonX4->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX4->TabIndex = 9;
			this->buttonX4->Text = L"取消";
			// 
			// GroupMemberManagementDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 381);
			this->Controls->Add(this->buttonX4);
			this->Controls->Add(this->buttonX3);
			this->Controls->Add(this->advTree2);
			this->Controls->Add(this->buttonX2);
			this->Controls->Add(this->labelX2);
			this->Controls->Add(this->buttonX1);
			this->Controls->Add(this->advTree1);
			this->Controls->Add(this->comboBoxEx1);
			this->Controls->Add(this->labelX1);
			this->Controls->Add(this->textBoxX1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GroupMemberManagementDlg";
			this->Text = L"GroupMemberManagementDlg";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
