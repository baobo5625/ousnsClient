#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// ShareFileListTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class ShareFileListTab : public System::Windows::Forms::Form
	{
	public:
		ShareFileListTab(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~ShareFileListTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl5;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel22;
	private: DevComponents::DotNetBar::Bar^  bar1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem6;
	private: DevComponents::DotNetBar::LabelItem^  personalShareFileListFileTotalCountLabelItem;
	private: DevComponents::DotNetBar::LabelItem^  labelItem7;
	private: DevComponents::DotNetBar::LabelItem^  personalShareFileListFileTotalSizeLabelItem;
	private: DevComponents::AdvTree::AdvTree^  personalShareFileListAdvTree;
	private: DevComponents::AdvTree::ColumnHeader^  personalShareFileListFileNameColumnHeader;
	private: DevComponents::AdvTree::ColumnHeader^  personalShareFileListFileSizeColumnHeader;
	private: DevComponents::AdvTree::ColumnHeader^  personalShareFileListFileActualPathColumnHeader;
	private: DevComponents::AdvTree::ColumnHeader^  personalShareFileListFilePrivilegeColumnHeader;
	private: DevComponents::AdvTree::Node^  node5;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector3;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle3;
	private: DevComponents::DotNetBar::SuperTabItem^  shareFileSuperTabItem;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel19;
	private: DevComponents::DotNetBar::ButtonX^  searchFileDownloadFileButtonX;
	private: DevComponents::AdvTree::AdvTree^  searchFileSearchResultFileListAdvTree;
	private: DevComponents::AdvTree::Node^  node6;
	private: DevComponents::AdvTree::Node^  node8;
	private: DevComponents::AdvTree::Node^  node7;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector4;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle4;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  searchFileFileExtentionEntryTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  searchFileFileExtentionEntryLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  searchFileSearchFilterChoiceLabelXComboBoxEx;
	private: DevComponents::DotNetBar::LabelX^  searchFileSearchFilterChoiceLabelX;
	private: DevComponents::DotNetBar::ButtonX^  searchFileSearchResultNextPage;
	private: DevComponents::DotNetBar::ButtonX^  searchFileSearchResultPreviousPage;
	private: DevComponents::DotNetBar::LabelX^  searchFileSearchResultLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  searchFileSearchTypeComboBoxEx;
	private: DevComponents::Editors::ComboItem^  comboItem1;
	private: DevComponents::Editors::ComboItem^  comboItem2;
	private: DevComponents::Editors::ComboItem^  comboItem3;
	private: DevComponents::Editors::ComboItem^  comboItem4;
	private: DevComponents::DotNetBar::LabelX^  searchFileSearchTypeTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  searchFileTabKeyWordTitleLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  searchFileKeyWorkTextBoxX;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem2;
	private: DevComponents::DotNetBar::ButtonItem^  addSharFileButtonItem;


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
			this->superTabControl5 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel19 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->searchFileDownloadFileButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchFileSearchResultFileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->node6 = (gcnew DevComponents::AdvTree::Node());
			this->node8 = (gcnew DevComponents::AdvTree::Node());
			this->node7 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector4 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle4 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->searchFileFileExtentionEntryTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->searchFileFileExtentionEntryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFileSearchFilterChoiceLabelXComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->searchFileSearchFilterChoiceLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFileSearchResultNextPage = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchFileSearchResultPreviousPage = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchFileSearchResultLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFileSearchTypeComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem1 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem2 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem3 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem4 = (gcnew DevComponents::Editors::ComboItem());
			this->searchFileSearchTypeTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFileTabKeyWordTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFileKeyWorkTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->superTabItem2 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel22 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->bar1 = (gcnew DevComponents::DotNetBar::Bar());
			this->labelItem6 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->personalShareFileListFileTotalCountLabelItem = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem7 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->personalShareFileListFileTotalSizeLabelItem = (gcnew DevComponents::DotNetBar::LabelItem());
			this->personalShareFileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->personalShareFileListFileNameColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->personalShareFileListFileSizeColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->personalShareFileListFileActualPathColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->personalShareFileListFilePrivilegeColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node5 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector3 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle3 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->shareFileSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->addSharFileButtonItem = (gcnew DevComponents::DotNetBar::ButtonItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl5))->BeginInit();
			this->superTabControl5->SuspendLayout();
			this->superTabControlPanel19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->searchFileSearchResultFileListAdvTree))->BeginInit();
			this->superTabControlPanel22->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->personalShareFileListAdvTree))->BeginInit();
			this->SuspendLayout();
			// 
			// superTabControl5
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl5->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl5->ControlBox->MenuBox->Name = L"";
			this->superTabControl5->ControlBox->Name = L"";
			this->superTabControl5->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl5->ControlBox->MenuBox, 
				this->superTabControl5->ControlBox->CloseBox});
			this->superTabControl5->ControlBox->Visible = false;
			this->superTabControl5->Controls->Add(this->superTabControlPanel22);
			this->superTabControl5->Controls->Add(this->superTabControlPanel19);
			this->superTabControl5->Cursor = System::Windows::Forms::Cursors::Default;
			this->superTabControl5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl5->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl5->Location = System::Drawing::Point(0, 0);
			this->superTabControl5->Name = L"superTabControl5";
			this->superTabControl5->ReorderTabsEnabled = true;
			this->superTabControl5->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl5->SelectedTabIndex = 0;
			this->superTabControl5->Size = System::Drawing::Size(593, 529);
			this->superTabControl5->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl5->TabIndex = 1;
			this->superTabControl5->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->shareFileSuperTabItem, 
				this->superTabItem2, this->addSharFileButtonItem});
			this->superTabControl5->Text = L"superTabControl5";
			this->superTabControl5->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel19
			// 
			this->superTabControlPanel19->Controls->Add(this->searchFileDownloadFileButtonX);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchResultFileListAdvTree);
			this->superTabControlPanel19->Controls->Add(this->searchFileFileExtentionEntryTextBoxX);
			this->superTabControlPanel19->Controls->Add(this->searchFileFileExtentionEntryLabelX);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchFilterChoiceLabelXComboBoxEx);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchFilterChoiceLabelX);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchResultNextPage);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchResultPreviousPage);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchResultLabelX);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchTypeComboBoxEx);
			this->superTabControlPanel19->Controls->Add(this->searchFileSearchTypeTitleLabelX);
			this->superTabControlPanel19->Controls->Add(this->searchFileTabKeyWordTitleLabelX);
			this->superTabControlPanel19->Controls->Add(this->searchFileKeyWorkTextBoxX);
			this->superTabControlPanel19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel19->Location = System::Drawing::Point(0, 0);
			this->superTabControlPanel19->Name = L"superTabControlPanel19";
			this->superTabControlPanel19->Size = System::Drawing::Size(593, 529);
			this->superTabControlPanel19->TabIndex = 0;
			this->superTabControlPanel19->TabItem = this->superTabItem2;
			// 
			// searchFileDownloadFileButtonX
			// 
			this->searchFileDownloadFileButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFileDownloadFileButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFileDownloadFileButtonX->Location = System::Drawing::Point(463, 472);
			this->searchFileDownloadFileButtonX->Name = L"searchFileDownloadFileButtonX";
			this->searchFileDownloadFileButtonX->Size = System::Drawing::Size(75, 23);
			this->searchFileDownloadFileButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFileDownloadFileButtonX->TabIndex = 26;
			this->searchFileDownloadFileButtonX->Text = L"搜索";
			// 
			// searchFileSearchResultFileListAdvTree
			// 
			this->searchFileSearchResultFileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->searchFileSearchResultFileListAdvTree->AllowDrop = true;
			this->searchFileSearchResultFileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->searchFileSearchResultFileListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->searchFileSearchResultFileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileSearchResultFileListAdvTree->GridRowLines = true;
			this->searchFileSearchResultFileListAdvTree->Location = System::Drawing::Point(32, 205);
			this->searchFileSearchResultFileListAdvTree->MultiSelect = true;
			this->searchFileSearchResultFileListAdvTree->MultiSelectRule = DevComponents::AdvTree::eMultiSelectRule::AnyNode;
			this->searchFileSearchResultFileListAdvTree->Name = L"searchFileSearchResultFileListAdvTree";
			this->searchFileSearchResultFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(2) {this->node6, 
				this->node7});
			this->searchFileSearchResultFileListAdvTree->NodesConnector = this->nodeConnector4;
			this->searchFileSearchResultFileListAdvTree->NodeStyle = this->elementStyle4;
			this->searchFileSearchResultFileListAdvTree->PathSeparator = L";";
			this->searchFileSearchResultFileListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->searchFileSearchResultFileListAdvTree->Size = System::Drawing::Size(528, 250);
			this->searchFileSearchResultFileListAdvTree->Styles->Add(this->elementStyle4);
			this->searchFileSearchResultFileListAdvTree->TabIndex = 25;
			this->searchFileSearchResultFileListAdvTree->Text = L"advTree1";
			// 
			// node6
			// 
			this->node6->Expanded = true;
			this->node6->Name = L"node6";
			this->node6->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node8});
			this->node6->Text = L"node6";
			// 
			// node8
			// 
			this->node8->Name = L"node8";
			this->node8->Text = L"visualFile";
			// 
			// node7
			// 
			this->node7->Expanded = true;
			this->node7->Name = L"node7";
			this->node7->Text = L"node7";
			// 
			// nodeConnector4
			// 
			this->nodeConnector4->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle4
			// 
			this->elementStyle4->Class = L"";
			this->elementStyle4->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle4->Name = L"elementStyle4";
			this->elementStyle4->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// searchFileFileExtentionEntryTextBoxX
			// 
			// 
			// 
			// 
			this->searchFileFileExtentionEntryTextBoxX->Border->Class = L"TextBoxBorder";
			this->searchFileFileExtentionEntryTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileFileExtentionEntryTextBoxX->Location = System::Drawing::Point(131, 148);
			this->searchFileFileExtentionEntryTextBoxX->Name = L"searchFileFileExtentionEntryTextBoxX";
			this->searchFileFileExtentionEntryTextBoxX->Size = System::Drawing::Size(429, 21);
			this->searchFileFileExtentionEntryTextBoxX->TabIndex = 24;
			// 
			// searchFileFileExtentionEntryLabelX
			// 
			this->searchFileFileExtentionEntryLabelX->AutoSize = true;
			this->searchFileFileExtentionEntryLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFileFileExtentionEntryLabelX->BackgroundStyle->Class = L"";
			this->searchFileFileExtentionEntryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileFileExtentionEntryLabelX->Location = System::Drawing::Point(32, 151);
			this->searchFileFileExtentionEntryLabelX->Name = L"searchFileFileExtentionEntryLabelX";
			this->searchFileFileExtentionEntryLabelX->Size = System::Drawing::Size(105, 18);
			this->searchFileFileExtentionEntryLabelX->TabIndex = 23;
			this->searchFileFileExtentionEntryLabelX->Text = L"仅搜索扩展名为：";
			// 
			// searchFileSearchFilterChoiceLabelXComboBoxEx
			// 
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->DisplayMember = L"Text";
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->FormattingEnabled = true;
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->ItemHeight = 15;
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->Location = System::Drawing::Point(131, 108);
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->Name = L"searchFileSearchFilterChoiceLabelXComboBoxEx";
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->Size = System::Drawing::Size(121, 21);
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFileSearchFilterChoiceLabelXComboBoxEx->TabIndex = 22;
			// 
			// searchFileSearchFilterChoiceLabelX
			// 
			this->searchFileSearchFilterChoiceLabelX->AutoSize = true;
			this->searchFileSearchFilterChoiceLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFileSearchFilterChoiceLabelX->BackgroundStyle->Class = L"";
			this->searchFileSearchFilterChoiceLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileSearchFilterChoiceLabelX->Location = System::Drawing::Point(32, 108);
			this->searchFileSearchFilterChoiceLabelX->Name = L"searchFileSearchFilterChoiceLabelX";
			this->searchFileSearchFilterChoiceLabelX->Size = System::Drawing::Size(93, 18);
			this->searchFileSearchFilterChoiceLabelX->TabIndex = 21;
			this->searchFileSearchFilterChoiceLabelX->Text = L"搜索文件种类：";
			// 
			// searchFileSearchResultNextPage
			// 
			this->searchFileSearchResultNextPage->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFileSearchResultNextPage->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFileSearchResultNextPage->Location = System::Drawing::Point(131, 472);
			this->searchFileSearchResultNextPage->Name = L"searchFileSearchResultNextPage";
			this->searchFileSearchResultNextPage->Size = System::Drawing::Size(75, 23);
			this->searchFileSearchResultNextPage->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFileSearchResultNextPage->TabIndex = 20;
			this->searchFileSearchResultNextPage->Text = L"下一页";
			// 
			// searchFileSearchResultPreviousPage
			// 
			this->searchFileSearchResultPreviousPage->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFileSearchResultPreviousPage->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFileSearchResultPreviousPage->Location = System::Drawing::Point(32, 472);
			this->searchFileSearchResultPreviousPage->Name = L"searchFileSearchResultPreviousPage";
			this->searchFileSearchResultPreviousPage->Size = System::Drawing::Size(75, 23);
			this->searchFileSearchResultPreviousPage->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFileSearchResultPreviousPage->TabIndex = 19;
			this->searchFileSearchResultPreviousPage->Text = L"上一页";
			// 
			// searchFileSearchResultLabelX
			// 
			this->searchFileSearchResultLabelX->AutoSize = true;
			this->searchFileSearchResultLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFileSearchResultLabelX->BackgroundStyle->Class = L"";
			this->searchFileSearchResultLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileSearchResultLabelX->Location = System::Drawing::Point(32, 179);
			this->searchFileSearchResultLabelX->Name = L"searchFileSearchResultLabelX";
			this->searchFileSearchResultLabelX->Size = System::Drawing::Size(68, 18);
			this->searchFileSearchResultLabelX->TabIndex = 18;
			this->searchFileSearchResultLabelX->Text = L"搜索结果：";
			// 
			// searchFileSearchTypeComboBoxEx
			// 
			this->searchFileSearchTypeComboBoxEx->DisplayMember = L"Text";
			this->searchFileSearchTypeComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->searchFileSearchTypeComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->searchFileSearchTypeComboBoxEx->FormattingEnabled = true;
			this->searchFileSearchTypeComboBoxEx->ItemHeight = 15;
			this->searchFileSearchTypeComboBoxEx->Items->AddRange(gcnew cli::array< System::Object^  >(4) {this->comboItem1, this->comboItem2, 
				this->comboItem3, this->comboItem4});
			this->searchFileSearchTypeComboBoxEx->Location = System::Drawing::Point(131, 69);
			this->searchFileSearchTypeComboBoxEx->Name = L"searchFileSearchTypeComboBoxEx";
			this->searchFileSearchTypeComboBoxEx->Size = System::Drawing::Size(121, 21);
			this->searchFileSearchTypeComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFileSearchTypeComboBoxEx->TabIndex = 17;
			// 
			// comboItem1
			// 
			this->comboItem1->Text = L"搜索文件名";
			// 
			// comboItem2
			// 
			this->comboItem2->Text = L"搜索文件描述";
			// 
			// comboItem3
			// 
			this->comboItem3->Text = L"搜索文件标签";
			// 
			// comboItem4
			// 
			this->comboItem4->Text = L"全部";
			// 
			// searchFileSearchTypeTitleLabelX
			// 
			this->searchFileSearchTypeTitleLabelX->AutoSize = true;
			this->searchFileSearchTypeTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFileSearchTypeTitleLabelX->BackgroundStyle->Class = L"";
			this->searchFileSearchTypeTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileSearchTypeTitleLabelX->Location = System::Drawing::Point(32, 69);
			this->searchFileSearchTypeTitleLabelX->Name = L"searchFileSearchTypeTitleLabelX";
			this->searchFileSearchTypeTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->searchFileSearchTypeTitleLabelX->TabIndex = 16;
			this->searchFileSearchTypeTitleLabelX->Text = L"搜索类型：";
			// 
			// searchFileTabKeyWordTitleLabelX
			// 
			this->searchFileTabKeyWordTitleLabelX->AutoSize = true;
			this->searchFileTabKeyWordTitleLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFileTabKeyWordTitleLabelX->BackgroundStyle->Class = L"";
			this->searchFileTabKeyWordTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileTabKeyWordTitleLabelX->Location = System::Drawing::Point(32, 35);
			this->searchFileTabKeyWordTitleLabelX->Name = L"searchFileTabKeyWordTitleLabelX";
			this->searchFileTabKeyWordTitleLabelX->Size = System::Drawing::Size(81, 18);
			this->searchFileTabKeyWordTitleLabelX->TabIndex = 15;
			this->searchFileTabKeyWordTitleLabelX->Text = L"搜索关键词：";
			// 
			// searchFileKeyWorkTextBoxX
			// 
			// 
			// 
			// 
			this->searchFileKeyWorkTextBoxX->Border->Class = L"TextBoxBorder";
			this->searchFileKeyWorkTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFileKeyWorkTextBoxX->Location = System::Drawing::Point(131, 35);
			this->searchFileKeyWorkTextBoxX->Name = L"searchFileKeyWorkTextBoxX";
			this->searchFileKeyWorkTextBoxX->Size = System::Drawing::Size(429, 21);
			this->searchFileKeyWorkTextBoxX->TabIndex = 14;
			// 
			// superTabItem2
			// 
			this->superTabItem2->AttachedControl = this->superTabControlPanel19;
			this->superTabItem2->GlobalItem = false;
			this->superTabItem2->Name = L"superTabItem2";
			this->superTabItem2->Text = L"搜索共享文件";
			// 
			// superTabControlPanel22
			// 
			this->superTabControlPanel22->Controls->Add(this->personalShareFileListAdvTree);
			this->superTabControlPanel22->Controls->Add(this->bar1);
			this->superTabControlPanel22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel22->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel22->Name = L"superTabControlPanel22";
			this->superTabControlPanel22->Size = System::Drawing::Size(593, 487);
			this->superTabControlPanel22->TabIndex = 1;
			this->superTabControlPanel22->TabItem = this->shareFileSuperTabItem;
			// 
			// bar1
			// 
			this->bar1->AntiAlias = true;
			this->bar1->Dock = System::Windows::Forms::DockStyle::Top;
			this->bar1->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->bar1->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(4) {this->labelItem6, this->personalShareFileListFileTotalCountLabelItem, 
				this->labelItem7, this->personalShareFileListFileTotalSizeLabelItem});
			this->bar1->Location = System::Drawing::Point(0, 0);
			this->bar1->Margin = System::Windows::Forms::Padding(0);
			this->bar1->Name = L"bar1";
			this->bar1->PaddingBottom = 0;
			this->bar1->PaddingLeft = 0;
			this->bar1->PaddingRight = 0;
			this->bar1->PaddingTop = 0;
			this->bar1->Size = System::Drawing::Size(593, 16);
			this->bar1->Stretch = true;
			this->bar1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar1->TabIndex = 1;
			this->bar1->TabStop = false;
			this->bar1->Text = L"bar1";
			// 
			// labelItem6
			// 
			this->labelItem6->Name = L"labelItem6";
			this->labelItem6->PaddingLeft = 50;
			this->labelItem6->Text = L"共享文件总数：";
			// 
			// personalShareFileListFileTotalCountLabelItem
			// 
			this->personalShareFileListFileTotalCountLabelItem->Name = L"personalShareFileListFileTotalCountLabelItem";
			this->personalShareFileListFileTotalCountLabelItem->Text = L"0";
			// 
			// labelItem7
			// 
			this->labelItem7->Name = L"labelItem7";
			this->labelItem7->PaddingLeft = 50;
			this->labelItem7->Text = L"共享文件大小：";
			// 
			// personalShareFileListFileTotalSizeLabelItem
			// 
			this->personalShareFileListFileTotalSizeLabelItem->Name = L"personalShareFileListFileTotalSizeLabelItem";
			this->personalShareFileListFileTotalSizeLabelItem->Text = L"0.0MB";
			// 
			// personalShareFileListAdvTree
			// 
			this->personalShareFileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->personalShareFileListAdvTree->AllowDrop = true;
			this->personalShareFileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->personalShareFileListAdvTree->BackgroundStyle->Class = L"";
			this->personalShareFileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->personalShareFileListAdvTree->Columns->Add(this->personalShareFileListFileNameColumnHeader);
			this->personalShareFileListAdvTree->Columns->Add(this->personalShareFileListFileSizeColumnHeader);
			this->personalShareFileListAdvTree->Columns->Add(this->personalShareFileListFileActualPathColumnHeader);
			this->personalShareFileListAdvTree->Columns->Add(this->personalShareFileListFilePrivilegeColumnHeader);
			this->personalShareFileListAdvTree->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->personalShareFileListAdvTree->Location = System::Drawing::Point(0, 30);
			this->personalShareFileListAdvTree->Name = L"personalShareFileListAdvTree";
			this->personalShareFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node5});
			this->personalShareFileListAdvTree->NodesConnector = this->nodeConnector3;
			this->personalShareFileListAdvTree->NodeStyle = this->elementStyle3;
			this->personalShareFileListAdvTree->PathSeparator = L";";
			this->personalShareFileListAdvTree->Size = System::Drawing::Size(593, 457);
			this->personalShareFileListAdvTree->Styles->Add(this->elementStyle3);
			this->personalShareFileListAdvTree->TabIndex = 0;
			this->personalShareFileListAdvTree->Text = L"advTree1";
			// 
			// personalShareFileListFileNameColumnHeader
			// 
			this->personalShareFileListFileNameColumnHeader->Name = L"personalShareFileListFileNameColumnHeader";
			this->personalShareFileListFileNameColumnHeader->Text = L"文件名称";
			this->personalShareFileListFileNameColumnHeader->Width->Absolute = 150;
			// 
			// personalShareFileListFileSizeColumnHeader
			// 
			this->personalShareFileListFileSizeColumnHeader->Name = L"personalShareFileListFileSizeColumnHeader";
			this->personalShareFileListFileSizeColumnHeader->Text = L"文件大小";
			this->personalShareFileListFileSizeColumnHeader->Width->Absolute = 150;
			// 
			// personalShareFileListFileActualPathColumnHeader
			// 
			this->personalShareFileListFileActualPathColumnHeader->Name = L"personalShareFileListFileActualPathColumnHeader";
			this->personalShareFileListFileActualPathColumnHeader->Text = L"文件路径";
			this->personalShareFileListFileActualPathColumnHeader->Width->Absolute = 150;
			// 
			// personalShareFileListFilePrivilegeColumnHeader
			// 
			this->personalShareFileListFilePrivilegeColumnHeader->Name = L"personalShareFileListFilePrivilegeColumnHeader";
			this->personalShareFileListFilePrivilegeColumnHeader->Text = L"文件访问权限";
			this->personalShareFileListFilePrivilegeColumnHeader->Width->Absolute = 150;
			// 
			// node5
			// 
			this->node5->Expanded = true;
			this->node5->Name = L"node5";
			this->node5->Text = L"node5";
			// 
			// nodeConnector3
			// 
			this->nodeConnector3->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle3
			// 
			this->elementStyle3->Class = L"";
			this->elementStyle3->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle3->Name = L"elementStyle3";
			this->elementStyle3->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// shareFileSuperTabItem
			// 
			this->shareFileSuperTabItem->AttachedControl = this->superTabControlPanel22;
			this->shareFileSuperTabItem->GlobalItem = false;
			this->shareFileSuperTabItem->Name = L"shareFileSuperTabItem";
			this->shareFileSuperTabItem->Text = L"我的共享列表";
			// 
			// addSharFileButtonItem
			// 
			this->addSharFileButtonItem->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
			this->addSharFileButtonItem->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addSharFileButtonItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addSharFileButtonItem->FontBold = true;
			this->addSharFileButtonItem->ItemAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			this->addSharFileButtonItem->Name = L"addSharFileButtonItem";
			this->addSharFileButtonItem->Text = L"   添加共享文件";
			this->addSharFileButtonItem->Click += gcnew System::EventHandler(this, &ShareFileListTab::addSharFileButtonItem_Click);
			// 
			// ShareFileListTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 529);
			this->Controls->Add(this->superTabControl5);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ShareFileListTab";
			this->Text = L"ShareFileListTab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl5))->EndInit();
			this->superTabControl5->ResumeLayout(false);
			this->superTabControlPanel19->ResumeLayout(false);
			this->superTabControlPanel19->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->searchFileSearchResultFileListAdvTree))->EndInit();
			this->superTabControlPanel22->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->personalShareFileListAdvTree))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void addSharFileButtonItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
