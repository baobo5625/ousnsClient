#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// FocusUserTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	ref class OusnsLoginUser;
	ref class SearchResult;
	public ref class FocusUserTab : public System::Windows::Forms::Form
	{
	public:
		OusnsLoginUser^ loginUser;
		MainDlg^ mainDlg;
		FocusUserTab(MainDlg^ mainDlgInput,OusnsLoginUser^ loginUserInput);
		int searchGroupOffSet;
		int searchUserOffset;
		delegate System::Void UpdateInfoDelegate(unsigned int srcID);
		delegate System::Void ActionDelegate();
		delegate System::Void ParamActionDelegate(LinkedList<Object^>^ params);
		delegate System::Void SearchActionDelegate(int totalResult, int offset, LinkedList<SearchResult^>^ searchResult);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~FocusUserTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl6;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel27;
	private: DevComponents::DotNetBar::PanelEx^  panelEx4;
	private: DevComponents::DotNetBar::ExpandablePanel^  expandablePanel3;
	private: DevComponents::AdvTree::AdvTree^  sharingListAdvTree;

	private: DevComponents::AdvTree::ColumnHeader^  columnHeader9;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader10;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader11;
	private: DevComponents::AdvTree::Node^  node10;
	private: DevComponents::AdvTree::Node^  node11;
	private: DevComponents::AdvTree::Cell^  cell1;
	private: DevComponents::AdvTree::Cell^  cell8;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector7;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle7;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter7;
	private: DevComponents::DotNetBar::ExpandablePanel^  recentUpdateExpandablePanel;

	private: DevComponents::AdvTree::AdvTree^  advTree4;
	private: DevComponents::AdvTree::Node^  node17;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector10;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle10;
	private: DevComponents::DotNetBar::ButtonX^  buttonX3;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter8;
	private: DevComponents::DotNetBar::SideBar^  focusListSideBar;


	private: DevComponents::DotNetBar::SideBarPanelItem^  focusGroupSideBarPanelItem;

	private: DevComponents::DotNetBar::ButtonItem^  buttonItem18;
	private: DevComponents::DotNetBar::Bar^  bar4;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem19;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem20;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem21;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem4;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel30;
	private: DevComponents::DotNetBar::LabelX^  addUserFocusNextPageLabelX;

	private: DevComponents::DotNetBar::LabelX^  addUserFocusPreviousPageLabelX;
	private: DevComponents::DotNetBar::ButtonX^  addUserFocusAddButtonX;



	private: DevComponents::DotNetBar::Controls::ListViewEx^  addUserFocusSearchResultListViewEx;
	private: System::Windows::Forms::ColumnHeader^  searchUserIDColumnHeader;
	private: System::Windows::Forms::ColumnHeader^  searchUserInfoColumnHeader;



	private: DevComponents::DotNetBar::LabelX^  labelX20;
	private: System::Windows::Forms::RadioButton^  nicknameRadioButton;
	private: DevComponents::DotNetBar::ButtonX^  addUserFocusSearchButtonX;


	private: DevComponents::DotNetBar::Controls::TextBoxX^  addUserFocusKeywordTextBoxX;

	private: System::Windows::Forms::RadioButton^  emailRadioButton;

	private: System::Windows::Forms::RadioButton^  ouIDRadioButton;

	private: DevComponents::DotNetBar::LabelX^  labelX17;
	private: DevComponents::DotNetBar::SuperTabItem^  AddUserFocusSuperTabItem;

	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel29;
	private: DevComponents::DotNetBar::LabelX^  addGroupFocusNextPageLabelX;


	private: DevComponents::DotNetBar::LabelX^  addGroupFocusPreviousPageLabelX;
	private: DevComponents::DotNetBar::ButtonX^  addGroupFocusAddButtonX;


	private: DevComponents::DotNetBar::Controls::ListViewEx^  addGroupFocusListViewEx;
	private: System::Windows::Forms::ColumnHeader^  groupIDColumnHeader;
	private: System::Windows::Forms::ColumnHeader^  groupNameColumnHeader;
	private: System::Windows::Forms::ColumnHeader^  groupDescriptionColumnHeader;




	private: DevComponents::DotNetBar::LabelX^  labelX27;
	private: DevComponents::DotNetBar::ButtonX^  addGroupFocusSearchButtonX;

	private: DevComponents::DotNetBar::Controls::TextBoxX^  addGroupFocusKeywordTextBoxX;


	private: System::Windows::Forms::RadioButton^  groupKeywordRadioButton;

	private: System::Windows::Forms::RadioButton^  groupIDRadioButton;

	private: DevComponents::DotNetBar::LabelX^  labelX28;
	private: DevComponents::DotNetBar::SuperTabItem^  AddFocusGroupSuperTabItem;

	private: DevComponents::DotNetBar::SideBarPanelItem^  focusUserSideBarPanelItem;


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
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {L"tester1", 
				L"tester2", L"tester3333"}, -1));
			this->superTabControl6 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel30 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->addUserFocusNextPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->addUserFocusPreviousPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->addUserFocusAddButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->addUserFocusSearchResultListViewEx = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->searchUserIDColumnHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->searchUserInfoColumnHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelX20 = (gcnew DevComponents::DotNetBar::LabelX());
			this->nicknameRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->addUserFocusSearchButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->addUserFocusKeywordTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->emailRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->ouIDRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->labelX17 = (gcnew DevComponents::DotNetBar::LabelX());
			this->AddUserFocusSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel27 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->panelEx4 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->expandablePanel3 = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->sharingListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->columnHeader9 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader10 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader11 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node10 = (gcnew DevComponents::AdvTree::Node());
			this->node11 = (gcnew DevComponents::AdvTree::Node());
			this->cell1 = (gcnew DevComponents::AdvTree::Cell());
			this->cell8 = (gcnew DevComponents::AdvTree::Cell());
			this->nodeConnector7 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle7 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->expandableSplitter7 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->recentUpdateExpandablePanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->advTree4 = (gcnew DevComponents::AdvTree::AdvTree());
			this->node17 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector10 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle10 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->buttonX3 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->expandableSplitter8 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->focusListSideBar = (gcnew DevComponents::DotNetBar::SideBar());
			this->focusGroupSideBarPanelItem = (gcnew DevComponents::DotNetBar::SideBarPanelItem());
			this->buttonItem18 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->focusUserSideBarPanelItem = (gcnew DevComponents::DotNetBar::SideBarPanelItem());
			this->bar4 = (gcnew DevComponents::DotNetBar::Bar());
			this->buttonItem19 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem20 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem21 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->superTabItem4 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel29 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->addGroupFocusNextPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->addGroupFocusPreviousPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->addGroupFocusAddButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->addGroupFocusListViewEx = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->groupIDColumnHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupNameColumnHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupDescriptionColumnHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelX27 = (gcnew DevComponents::DotNetBar::LabelX());
			this->addGroupFocusSearchButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->addGroupFocusKeywordTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->groupKeywordRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupIDRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->labelX28 = (gcnew DevComponents::DotNetBar::LabelX());
			this->AddFocusGroupSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl6))->BeginInit();
			this->superTabControl6->SuspendLayout();
			this->superTabControlPanel30->SuspendLayout();
			this->superTabControlPanel27->SuspendLayout();
			this->panelEx4->SuspendLayout();
			this->expandablePanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sharingListAdvTree))->BeginInit();
			this->recentUpdateExpandablePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar4))->BeginInit();
			this->superTabControlPanel29->SuspendLayout();
			this->SuspendLayout();
			// 
			// superTabControl6
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl6->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl6->ControlBox->MenuBox->Name = L"";
			this->superTabControl6->ControlBox->MenuBox->Visible = false;
			this->superTabControl6->ControlBox->Name = L"";
			this->superTabControl6->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl6->ControlBox->MenuBox, 
				this->superTabControl6->ControlBox->CloseBox});
			this->superTabControl6->Controls->Add(this->superTabControlPanel30);
			this->superTabControl6->Controls->Add(this->superTabControlPanel27);
			this->superTabControl6->Controls->Add(this->superTabControlPanel29);
			this->superTabControl6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl6->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl6->Location = System::Drawing::Point(0, 0);
			this->superTabControl6->Name = L"superTabControl6";
			this->superTabControl6->ReorderTabsEnabled = true;
			this->superTabControl6->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl6->SelectedTabIndex = 0;
			this->superTabControl6->Size = System::Drawing::Size(593, 573);
			this->superTabControl6->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl6->TabIndex = 4;
			this->superTabControl6->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->superTabItem4, 
				this->AddFocusGroupSuperTabItem, this->AddUserFocusSuperTabItem});
			this->superTabControl6->Text = L"superTabControl6";
			this->superTabControl6->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel30
			// 
			this->superTabControlPanel30->Controls->Add(this->addUserFocusNextPageLabelX);
			this->superTabControlPanel30->Controls->Add(this->addUserFocusPreviousPageLabelX);
			this->superTabControlPanel30->Controls->Add(this->addUserFocusAddButtonX);
			this->superTabControlPanel30->Controls->Add(this->addUserFocusSearchResultListViewEx);
			this->superTabControlPanel30->Controls->Add(this->labelX20);
			this->superTabControlPanel30->Controls->Add(this->nicknameRadioButton);
			this->superTabControlPanel30->Controls->Add(this->addUserFocusSearchButtonX);
			this->superTabControlPanel30->Controls->Add(this->addUserFocusKeywordTextBoxX);
			this->superTabControlPanel30->Controls->Add(this->emailRadioButton);
			this->superTabControlPanel30->Controls->Add(this->ouIDRadioButton);
			this->superTabControlPanel30->Controls->Add(this->labelX17);
			this->superTabControlPanel30->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel30->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel30->Name = L"superTabControlPanel30";
			this->superTabControlPanel30->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel30->TabIndex = 0;
			this->superTabControlPanel30->TabItem = this->AddUserFocusSuperTabItem;
			// 
			// addUserFocusNextPageLabelX
			// 
			this->addUserFocusNextPageLabelX->AutoSize = true;
			this->addUserFocusNextPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->addUserFocusNextPageLabelX->BackgroundStyle->Class = L"";
			this->addUserFocusNextPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addUserFocusNextPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addUserFocusNextPageLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->addUserFocusNextPageLabelX->Location = System::Drawing::Point(90, 476);
			this->addUserFocusNextPageLabelX->Name = L"addUserFocusNextPageLabelX";
			this->addUserFocusNextPageLabelX->Size = System::Drawing::Size(44, 18);
			this->addUserFocusNextPageLabelX->TabIndex = 20;
			this->addUserFocusNextPageLabelX->Text = L"下一页";
			this->addUserFocusNextPageLabelX->Click += gcnew System::EventHandler(this, &FocusUserTab::addUserFocusNextPageLabelX_Click);
			// 
			// addUserFocusPreviousPageLabelX
			// 
			this->addUserFocusPreviousPageLabelX->AutoSize = true;
			this->addUserFocusPreviousPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->addUserFocusPreviousPageLabelX->BackgroundStyle->Class = L"";
			this->addUserFocusPreviousPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addUserFocusPreviousPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addUserFocusPreviousPageLabelX->ForeColor = System::Drawing::Color::Gray;
			this->addUserFocusPreviousPageLabelX->Location = System::Drawing::Point(38, 476);
			this->addUserFocusPreviousPageLabelX->Name = L"addUserFocusPreviousPageLabelX";
			this->addUserFocusPreviousPageLabelX->Size = System::Drawing::Size(44, 18);
			this->addUserFocusPreviousPageLabelX->TabIndex = 19;
			this->addUserFocusPreviousPageLabelX->Text = L"上一页";
			this->addUserFocusPreviousPageLabelX->Click += gcnew System::EventHandler(this, &FocusUserTab::addUserFocusPreviousPageLabelX_Click);
			// 
			// addUserFocusAddButtonX
			// 
			this->addUserFocusAddButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->addUserFocusAddButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addUserFocusAddButtonX->Location = System::Drawing::Point(462, 486);
			this->addUserFocusAddButtonX->Name = L"addUserFocusAddButtonX";
			this->addUserFocusAddButtonX->Size = System::Drawing::Size(75, 23);
			this->addUserFocusAddButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->addUserFocusAddButtonX->TabIndex = 18;
			this->addUserFocusAddButtonX->Text = L"添加关注";
			this->addUserFocusAddButtonX->Click += gcnew System::EventHandler(this, &FocusUserTab::addUserFocusAddButtonX_Click);
			// 
			// addUserFocusSearchResultListViewEx
			// 
			// 
			// 
			// 
			this->addUserFocusSearchResultListViewEx->Border->Class = L"ListViewBorder";
			this->addUserFocusSearchResultListViewEx->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addUserFocusSearchResultListViewEx->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->searchUserIDColumnHeader, 
				this->searchUserInfoColumnHeader});
			this->addUserFocusSearchResultListViewEx->FullRowSelect = true;
			this->addUserFocusSearchResultListViewEx->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) {listViewItem2});
			this->addUserFocusSearchResultListViewEx->Location = System::Drawing::Point(39, 189);
			this->addUserFocusSearchResultListViewEx->MultiSelect = false;
			this->addUserFocusSearchResultListViewEx->Name = L"addUserFocusSearchResultListViewEx";
			this->addUserFocusSearchResultListViewEx->Size = System::Drawing::Size(520, 280);
			this->addUserFocusSearchResultListViewEx->TabIndex = 17;
			this->addUserFocusSearchResultListViewEx->UseCompatibleStateImageBehavior = false;
			this->addUserFocusSearchResultListViewEx->View = System::Windows::Forms::View::Details;
			// 
			// searchUserIDColumnHeader
			// 
			this->searchUserIDColumnHeader->Text = L"OuID";
			this->searchUserIDColumnHeader->Width = 120;
			// 
			// searchUserInfoColumnHeader
			// 
			this->searchUserInfoColumnHeader->Text = L"昵称";
			this->searchUserInfoColumnHeader->Width = 400;
			// 
			// labelX20
			// 
			this->labelX20->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX20->BackgroundStyle->Class = L"";
			this->labelX20->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX20->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->labelX20->Location = System::Drawing::Point(38, 165);
			this->labelX20->Name = L"labelX20";
			this->labelX20->Size = System::Drawing::Size(95, 23);
			this->labelX20->TabIndex = 16;
			this->labelX20->Text = L"查询结果：";
			// 
			// nicknameRadioButton
			// 
			this->nicknameRadioButton->AutoSize = true;
			this->nicknameRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->nicknameRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nicknameRadioButton->Location = System::Drawing::Point(39, 99);
			this->nicknameRadioButton->Name = L"nicknameRadioButton";
			this->nicknameRadioButton->Size = System::Drawing::Size(107, 16);
			this->nicknameRadioButton->TabIndex = 15;
			this->nicknameRadioButton->Text = L"输入对方的昵称";
			this->nicknameRadioButton->UseVisualStyleBackColor = false;
			this->nicknameRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FocusUserTab::nicknameRadioButton_CheckedChanged);
			// 
			// addUserFocusSearchButtonX
			// 
			this->addUserFocusSearchButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->addUserFocusSearchButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addUserFocusSearchButtonX->Location = System::Drawing::Point(262, 128);
			this->addUserFocusSearchButtonX->Name = L"addUserFocusSearchButtonX";
			this->addUserFocusSearchButtonX->Size = System::Drawing::Size(75, 25);
			this->addUserFocusSearchButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->addUserFocusSearchButtonX->TabIndex = 13;
			this->addUserFocusSearchButtonX->Text = L"查  找";
			this->addUserFocusSearchButtonX->Click += gcnew System::EventHandler(this, &FocusUserTab::addUserFocusSearchButtonX_Click);
			// 
			// addUserFocusKeywordTextBoxX
			// 
			// 
			// 
			// 
			this->addUserFocusKeywordTextBoxX->Border->Class = L"TextBoxBorder";
			this->addUserFocusKeywordTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addUserFocusKeywordTextBoxX->Location = System::Drawing::Point(38, 128);
			this->addUserFocusKeywordTextBoxX->Name = L"addUserFocusKeywordTextBoxX";
			this->addUserFocusKeywordTextBoxX->Size = System::Drawing::Size(203, 21);
			this->addUserFocusKeywordTextBoxX->TabIndex = 12;
			// 
			// emailRadioButton
			// 
			this->emailRadioButton->AutoSize = true;
			this->emailRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->emailRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->emailRadioButton->Location = System::Drawing::Point(38, 75);
			this->emailRadioButton->Name = L"emailRadioButton";
			this->emailRadioButton->Size = System::Drawing::Size(107, 16);
			this->emailRadioButton->TabIndex = 11;
			this->emailRadioButton->Text = L"输入对方E-MAIL";
			this->emailRadioButton->UseVisualStyleBackColor = false;
			this->emailRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FocusUserTab::emailRadioButton_CheckedChanged);
			// 
			// ouIDRadioButton
			// 
			this->ouIDRadioButton->AutoSize = true;
			this->ouIDRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->ouIDRadioButton->Checked = true;
			this->ouIDRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ouIDRadioButton->Location = System::Drawing::Point(38, 52);
			this->ouIDRadioButton->Name = L"ouIDRadioButton";
			this->ouIDRadioButton->Size = System::Drawing::Size(95, 16);
			this->ouIDRadioButton->TabIndex = 10;
			this->ouIDRadioButton->TabStop = true;
			this->ouIDRadioButton->Text = L"输入对方OuID";
			this->ouIDRadioButton->UseVisualStyleBackColor = false;
			this->ouIDRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FocusUserTab::ouIDRadioButton_CheckedChanged);
			// 
			// labelX17
			// 
			this->labelX17->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX17->BackgroundStyle->Class = L"";
			this->labelX17->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX17->Location = System::Drawing::Point(38, 27);
			this->labelX17->Name = L"labelX17";
			this->labelX17->Size = System::Drawing::Size(80, 23);
			this->labelX17->TabIndex = 9;
			this->labelX17->Text = L"输入对方帐号";
			// 
			// AddUserFocusSuperTabItem
			// 
			this->AddUserFocusSuperTabItem->AttachedControl = this->superTabControlPanel30;
			this->AddUserFocusSuperTabItem->GlobalItem = false;
			this->AddUserFocusSuperTabItem->Name = L"AddUserFocusSuperTabItem";
			this->AddUserFocusSuperTabItem->Text = L"添加个人关注";
			this->AddUserFocusSuperTabItem->ExpandChange += gcnew System::EventHandler(this, &FocusUserTab::AddUserFocusSuperTabItem_ExpandChange);
			// 
			// superTabControlPanel27
			// 
			this->superTabControlPanel27->Controls->Add(this->panelEx4);
			this->superTabControlPanel27->Controls->Add(this->expandableSplitter8);
			this->superTabControlPanel27->Controls->Add(this->focusListSideBar);
			this->superTabControlPanel27->Controls->Add(this->bar4);
			this->superTabControlPanel27->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel27->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel27->Name = L"superTabControlPanel27";
			this->superTabControlPanel27->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel27->TabIndex = 1;
			this->superTabControlPanel27->TabItem = this->superTabItem4;
			// 
			// panelEx4
			// 
			this->panelEx4->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx4->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx4->Controls->Add(this->expandablePanel3);
			this->panelEx4->Controls->Add(this->expandableSplitter7);
			this->panelEx4->Controls->Add(this->recentUpdateExpandablePanel);
			this->panelEx4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx4->Location = System::Drawing::Point(121, 25);
			this->panelEx4->Name = L"panelEx4";
			this->panelEx4->Size = System::Drawing::Size(472, 506);
			this->panelEx4->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx4->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->panelEx4->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->panelEx4->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->panelEx4->Style->GradientAngle = 90;
			this->panelEx4->TabIndex = 9;
			// 
			// expandablePanel3
			// 
			this->expandablePanel3->CanvasColor = System::Drawing::SystemColors::Control;
			this->expandablePanel3->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->expandablePanel3->Controls->Add(this->sharingListAdvTree);
			this->expandablePanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->expandablePanel3->ExpandButtonVisible = false;
			this->expandablePanel3->Location = System::Drawing::Point(0, 235);
			this->expandablePanel3->Name = L"expandablePanel3";
			this->expandablePanel3->Size = System::Drawing::Size(472, 271);
			this->expandablePanel3->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel3->Style->BackColor1->Color = System::Drawing::Color::White;
			this->expandablePanel3->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->expandablePanel3->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandablePanel3->Style->GradientAngle = 90;
			this->expandablePanel3->TabIndex = 2;
			this->expandablePanel3->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel3->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandablePanel3->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->expandablePanel3->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->expandablePanel3->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandablePanel3->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->expandablePanel3->TitleStyle->GradientAngle = 90;
			this->expandablePanel3->TitleText = L"共享的文件";
			// 
			// sharingListAdvTree
			// 
			this->sharingListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->sharingListAdvTree->AllowDrop = true;
			this->sharingListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->sharingListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->sharingListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->sharingListAdvTree->Columns->Add(this->columnHeader9);
			this->sharingListAdvTree->Columns->Add(this->columnHeader10);
			this->sharingListAdvTree->Columns->Add(this->columnHeader11);
			this->sharingListAdvTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sharingListAdvTree->HotTracking = true;
			this->sharingListAdvTree->Location = System::Drawing::Point(0, 26);
			this->sharingListAdvTree->Name = L"sharingListAdvTree";
			this->sharingListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node10});
			this->sharingListAdvTree->NodesConnector = this->nodeConnector7;
			this->sharingListAdvTree->NodeStyle = this->elementStyle7;
			this->sharingListAdvTree->PathSeparator = L";";
			this->sharingListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->sharingListAdvTree->Size = System::Drawing::Size(472, 245);
			this->sharingListAdvTree->Styles->Add(this->elementStyle7);
			this->sharingListAdvTree->TabIndex = 2;
			this->sharingListAdvTree->Text = L"advTree1";
			// 
			// columnHeader9
			// 
			this->columnHeader9->DisplayIndex = 1;
			this->columnHeader9->Name = L"columnHeader9";
			this->columnHeader9->Text = L"文件名称";
			this->columnHeader9->Width->Absolute = 150;
			// 
			// columnHeader10
			// 
			this->columnHeader10->DisplayIndex = 2;
			this->columnHeader10->Name = L"columnHeader10";
			this->columnHeader10->Text = L"文件大小";
			this->columnHeader10->Width->Absolute = 150;
			// 
			// columnHeader11
			// 
			this->columnHeader11->DisplayIndex = 3;
			this->columnHeader11->Name = L"columnHeader11";
			this->columnHeader11->Text = L"文件描述";
			this->columnHeader11->Width->Absolute = 150;
			// 
			// node10
			// 
			this->node10->Expanded = true;
			this->node10->Name = L"node10";
			this->node10->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node11});
			this->node10->Text = L"文件名1";
			// 
			// node11
			// 
			this->node11->Cells->Add(this->cell1);
			this->node11->Cells->Add(this->cell8);
			this->node11->Name = L"node11";
			this->node11->Text = L"文件名2";
			// 
			// cell1
			// 
			this->cell1->Name = L"cell1";
			this->cell1->StyleMouseOver = nullptr;
			this->cell1->Text = L"文件大小2";
			// 
			// cell8
			// 
			this->cell8->Name = L"cell8";
			this->cell8->StyleMouseOver = nullptr;
			this->cell8->Text = L"文件描述2";
			// 
			// nodeConnector7
			// 
			this->nodeConnector7->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle7
			// 
			this->elementStyle7->Class = L"";
			this->elementStyle7->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle7->Name = L"elementStyle7";
			this->elementStyle7->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// expandableSplitter7
			// 
			this->expandableSplitter7->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter7->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter7->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter7->Dock = System::Windows::Forms::DockStyle::Top;
			this->expandableSplitter7->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter7->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter7->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter7->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter7->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter7->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter7->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter7->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter7->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter7->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter7->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter7->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter7->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter7->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter7->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter7->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter7->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter7->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter7->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter7->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter7->Location = System::Drawing::Point(0, 230);
			this->expandableSplitter7->Name = L"expandableSplitter7";
			this->expandableSplitter7->Size = System::Drawing::Size(472, 5);
			this->expandableSplitter7->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter7->TabIndex = 1;
			this->expandableSplitter7->TabStop = false;
			// 
			// recentUpdateExpandablePanel
			// 
			this->recentUpdateExpandablePanel->CanvasColor = System::Drawing::SystemColors::Control;
			this->recentUpdateExpandablePanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->recentUpdateExpandablePanel->Controls->Add(this->advTree4);
			this->recentUpdateExpandablePanel->Controls->Add(this->buttonX3);
			this->recentUpdateExpandablePanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->recentUpdateExpandablePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->recentUpdateExpandablePanel->ExpandButtonVisible = false;
			this->recentUpdateExpandablePanel->Location = System::Drawing::Point(0, 0);
			this->recentUpdateExpandablePanel->Name = L"recentUpdateExpandablePanel";
			this->recentUpdateExpandablePanel->Size = System::Drawing::Size(472, 230);
			this->recentUpdateExpandablePanel->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->recentUpdateExpandablePanel->Style->BackColor1->Color = System::Drawing::Color::White;
			this->recentUpdateExpandablePanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->recentUpdateExpandablePanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->recentUpdateExpandablePanel->Style->GradientAngle = 90;
			this->recentUpdateExpandablePanel->TabIndex = 0;
			this->recentUpdateExpandablePanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->recentUpdateExpandablePanel->TitleStyle->BackColor1->Color = System::Drawing::Color::White;
			this->recentUpdateExpandablePanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->recentUpdateExpandablePanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->recentUpdateExpandablePanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->recentUpdateExpandablePanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->recentUpdateExpandablePanel->TitleStyle->GradientAngle = 90;
			this->recentUpdateExpandablePanel->TitleText = L"群的最新动态";
			// 
			// advTree4
			// 
			this->advTree4->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->advTree4->AllowDrop = true;
			this->advTree4->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->advTree4->BackgroundStyle->Class = L"TreeBorderKey";
			this->advTree4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->advTree4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->advTree4->Location = System::Drawing::Point(0, 26);
			this->advTree4->Name = L"advTree4";
			this->advTree4->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node17});
			this->advTree4->NodesConnector = this->nodeConnector10;
			this->advTree4->NodeStyle = this->elementStyle10;
			this->advTree4->PathSeparator = L";";
			this->advTree4->Size = System::Drawing::Size(472, 204);
			this->advTree4->Styles->Add(this->elementStyle10);
			this->advTree4->TabIndex = 13;
			this->advTree4->Text = L"advTree4";
			// 
			// node17
			// 
			this->node17->Expanded = true;
			this->node17->Name = L"node17";
			this->node17->Text = L"node17";
			// 
			// nodeConnector10
			// 
			this->nodeConnector10->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle10
			// 
			this->elementStyle10->Class = L"";
			this->elementStyle10->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle10->Name = L"elementStyle10";
			this->elementStyle10->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// buttonX3
			// 
			this->buttonX3->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX3->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX3->Location = System::Drawing::Point(385, 3);
			this->buttonX3->Name = L"buttonX3";
			this->buttonX3->Size = System::Drawing::Size(75, 19);
			this->buttonX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX3->TabIndex = 12;
			this->buttonX3->Text = L"刷新";
			// 
			// expandableSplitter8
			// 
			this->expandableSplitter8->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter8->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter8->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter8->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter8->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter8->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter8->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter8->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter8->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter8->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter8->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter8->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter8->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter8->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter8->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter8->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter8->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter8->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter8->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter8->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter8->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter8->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter8->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter8->Location = System::Drawing::Point(116, 25);
			this->expandableSplitter8->Name = L"expandableSplitter8";
			this->expandableSplitter8->Size = System::Drawing::Size(5, 506);
			this->expandableSplitter8->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter8->TabIndex = 8;
			this->expandableSplitter8->TabStop = false;
			// 
			// focusListSideBar
			// 
			this->focusListSideBar->AccessibleRole = System::Windows::Forms::AccessibleRole::ToolBar;
			this->focusListSideBar->BorderStyle = DevComponents::DotNetBar::eBorderType::None;
			this->focusListSideBar->Dock = System::Windows::Forms::DockStyle::Left;
			this->focusListSideBar->ExpandedPanel = this->focusGroupSideBarPanelItem;
			this->focusListSideBar->Location = System::Drawing::Point(0, 25);
			this->focusListSideBar->MinimumSize = System::Drawing::Size(116, 0);
			this->focusListSideBar->Name = L"focusListSideBar";
			this->focusListSideBar->Panels->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->focusGroupSideBarPanelItem, 
				this->focusUserSideBarPanelItem});
			this->focusListSideBar->Size = System::Drawing::Size(116, 506);
			this->focusListSideBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->focusListSideBar->TabIndex = 3;
			this->focusListSideBar->Text = L"focusListSideBar";
			this->focusListSideBar->UsingSystemColors = true;
			// 
			// focusGroupSideBarPanelItem
			// 
			this->focusGroupSideBarPanelItem->FontBold = true;
			this->focusGroupSideBarPanelItem->Name = L"focusGroupSideBarPanelItem";
			this->focusGroupSideBarPanelItem->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->buttonItem18});
			this->focusGroupSideBarPanelItem->Text = L"我关注的群";
			this->focusGroupSideBarPanelItem->ExpandChange += gcnew System::EventHandler(this, &FocusUserTab::focusGroupSideBarPanelItem_ExpandChange);
			// 
			// buttonItem18
			// 
			this->buttonItem18->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
			this->buttonItem18->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
			this->buttonItem18->Name = L"buttonItem18";
			this->buttonItem18->Text = L"New Button";
			// 
			// focusUserSideBarPanelItem
			// 
			this->focusUserSideBarPanelItem->Name = L"focusUserSideBarPanelItem";
			this->focusUserSideBarPanelItem->Text = L"我关注的个人";
			this->focusUserSideBarPanelItem->ExpandChange += gcnew System::EventHandler(this, &FocusUserTab::focusIndividualSideBarPanelItem_ExpandChange);
			// 
			// bar4
			// 
			this->bar4->AntiAlias = true;
			this->bar4->Dock = System::Windows::Forms::DockStyle::Top;
			this->bar4->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->bar4->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->buttonItem19, this->buttonItem20, 
				this->buttonItem21});
			this->bar4->Location = System::Drawing::Point(0, 0);
			this->bar4->MinimumSize = System::Drawing::Size(0, 25);
			this->bar4->Name = L"bar4";
			this->bar4->PaddingTop = 4;
			this->bar4->Size = System::Drawing::Size(593, 25);
			this->bar4->Stretch = true;
			this->bar4->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar4->TabIndex = 2;
			this->bar4->TabStop = false;
			this->bar4->Text = L"bar3";
			// 
			// buttonItem19
			// 
			this->buttonItem19->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem19->Name = L"buttonItem19";
			this->buttonItem19->Text = L"创建新分类";
			// 
			// buttonItem20
			// 
			this->buttonItem20->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem20->Name = L"buttonItem20";
			this->buttonItem20->Text = L"重命名分类";
			// 
			// buttonItem21
			// 
			this->buttonItem21->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem21->Name = L"buttonItem21";
			this->buttonItem21->Text = L"删除分类";
			// 
			// superTabItem4
			// 
			this->superTabItem4->AttachedControl = this->superTabControlPanel27;
			this->superTabItem4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->superTabItem4->GlobalItem = false;
			this->superTabItem4->Name = L"superTabItem4";
			this->superTabItem4->Text = L"我的关注";
			// 
			// superTabControlPanel29
			// 
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusNextPageLabelX);
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusPreviousPageLabelX);
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusAddButtonX);
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusListViewEx);
			this->superTabControlPanel29->Controls->Add(this->labelX27);
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusSearchButtonX);
			this->superTabControlPanel29->Controls->Add(this->addGroupFocusKeywordTextBoxX);
			this->superTabControlPanel29->Controls->Add(this->groupKeywordRadioButton);
			this->superTabControlPanel29->Controls->Add(this->groupIDRadioButton);
			this->superTabControlPanel29->Controls->Add(this->labelX28);
			this->superTabControlPanel29->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel29->Location = System::Drawing::Point(0, 0);
			this->superTabControlPanel29->Name = L"superTabControlPanel29";
			this->superTabControlPanel29->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel29->TabIndex = 0;
			this->superTabControlPanel29->TabItem = this->AddFocusGroupSuperTabItem;
			// 
			// addGroupFocusNextPageLabelX
			// 
			this->addGroupFocusNextPageLabelX->AutoSize = true;
			this->addGroupFocusNextPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->addGroupFocusNextPageLabelX->BackgroundStyle->Class = L"";
			this->addGroupFocusNextPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addGroupFocusNextPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addGroupFocusNextPageLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->addGroupFocusNextPageLabelX->Location = System::Drawing::Point(100, 463);
			this->addGroupFocusNextPageLabelX->Name = L"addGroupFocusNextPageLabelX";
			this->addGroupFocusNextPageLabelX->Size = System::Drawing::Size(44, 18);
			this->addGroupFocusNextPageLabelX->TabIndex = 16;
			this->addGroupFocusNextPageLabelX->Text = L"下一页";
			this->addGroupFocusNextPageLabelX->Click += gcnew System::EventHandler(this, &FocusUserTab::addGroupFocusNextPageLabelX_Click);
			// 
			// addGroupFocusPreviousPageLabelX
			// 
			this->addGroupFocusPreviousPageLabelX->AutoSize = true;
			this->addGroupFocusPreviousPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->addGroupFocusPreviousPageLabelX->BackgroundStyle->Class = L"";
			this->addGroupFocusPreviousPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addGroupFocusPreviousPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addGroupFocusPreviousPageLabelX->ForeColor = System::Drawing::Color::Gray;
			this->addGroupFocusPreviousPageLabelX->Location = System::Drawing::Point(48, 463);
			this->addGroupFocusPreviousPageLabelX->Name = L"addGroupFocusPreviousPageLabelX";
			this->addGroupFocusPreviousPageLabelX->Size = System::Drawing::Size(44, 18);
			this->addGroupFocusPreviousPageLabelX->TabIndex = 15;
			this->addGroupFocusPreviousPageLabelX->Text = L"上一页";
			this->addGroupFocusPreviousPageLabelX->Click += gcnew System::EventHandler(this, &FocusUserTab::addGroupFocusPreviousPageLabelX_Click);
			// 
			// addGroupFocusAddButtonX
			// 
			this->addGroupFocusAddButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->addGroupFocusAddButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addGroupFocusAddButtonX->Location = System::Drawing::Point(472, 473);
			this->addGroupFocusAddButtonX->Name = L"addGroupFocusAddButtonX";
			this->addGroupFocusAddButtonX->Size = System::Drawing::Size(75, 23);
			this->addGroupFocusAddButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->addGroupFocusAddButtonX->TabIndex = 14;
			this->addGroupFocusAddButtonX->Text = L"加入此群组";
			this->addGroupFocusAddButtonX->Click += gcnew System::EventHandler(this, &FocusUserTab::addGroupFocusAddButtonX_Click);
			// 
			// addGroupFocusListViewEx
			// 
			// 
			// 
			// 
			this->addGroupFocusListViewEx->Border->Class = L"ListViewBorder";
			this->addGroupFocusListViewEx->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addGroupFocusListViewEx->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {this->groupIDColumnHeader, 
				this->groupNameColumnHeader, this->groupDescriptionColumnHeader});
			this->addGroupFocusListViewEx->Location = System::Drawing::Point(36, 175);
			this->addGroupFocusListViewEx->Name = L"addGroupFocusListViewEx";
			this->addGroupFocusListViewEx->Size = System::Drawing::Size(520, 280);
			this->addGroupFocusListViewEx->TabIndex = 13;
			this->addGroupFocusListViewEx->UseCompatibleStateImageBehavior = false;
			this->addGroupFocusListViewEx->View = System::Windows::Forms::View::Details;
			// 
			// groupIDColumnHeader
			// 
			this->groupIDColumnHeader->Text = L"GroupID";
			this->groupIDColumnHeader->Width = 120;
			// 
			// groupNameColumnHeader
			// 
			this->groupNameColumnHeader->Text = L"名称";
			this->groupNameColumnHeader->Width = 200;
			// 
			// groupDescriptionColumnHeader
			// 
			this->groupDescriptionColumnHeader->Text = L"描述";
			this->groupDescriptionColumnHeader->Width = 200;
			// 
			// labelX27
			// 
			this->labelX27->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX27->BackgroundStyle->Class = L"";
			this->labelX27->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX27->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->labelX27->Location = System::Drawing::Point(36, 145);
			this->labelX27->Name = L"labelX27";
			this->labelX27->Size = System::Drawing::Size(95, 23);
			this->labelX27->TabIndex = 12;
			this->labelX27->Text = L"查询结果：";
			// 
			// addGroupFocusSearchButtonX
			// 
			this->addGroupFocusSearchButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->addGroupFocusSearchButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addGroupFocusSearchButtonX->Location = System::Drawing::Point(260, 98);
			this->addGroupFocusSearchButtonX->Name = L"addGroupFocusSearchButtonX";
			this->addGroupFocusSearchButtonX->Size = System::Drawing::Size(75, 25);
			this->addGroupFocusSearchButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->addGroupFocusSearchButtonX->TabIndex = 11;
			this->addGroupFocusSearchButtonX->Text = L"查  找";
			this->addGroupFocusSearchButtonX->Click += gcnew System::EventHandler(this, &FocusUserTab::addGroupFocusSearchButtonX_Click);
			// 
			// addGroupFocusKeywordTextBoxX
			// 
			// 
			// 
			// 
			this->addGroupFocusKeywordTextBoxX->Border->Class = L"TextBoxBorder";
			this->addGroupFocusKeywordTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->addGroupFocusKeywordTextBoxX->Location = System::Drawing::Point(36, 98);
			this->addGroupFocusKeywordTextBoxX->Name = L"addGroupFocusKeywordTextBoxX";
			this->addGroupFocusKeywordTextBoxX->Size = System::Drawing::Size(203, 21);
			this->addGroupFocusKeywordTextBoxX->TabIndex = 10;
			// 
			// groupKeywordRadioButton
			// 
			this->groupKeywordRadioButton->AutoSize = true;
			this->groupKeywordRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->groupKeywordRadioButton->Location = System::Drawing::Point(36, 76);
			this->groupKeywordRadioButton->Name = L"groupKeywordRadioButton";
			this->groupKeywordRadioButton->Size = System::Drawing::Size(221, 16);
			this->groupKeywordRadioButton->TabIndex = 9;
			this->groupKeywordRadioButton->Text = L"输入群组名称关键字（不少于2个字）";
			this->groupKeywordRadioButton->UseVisualStyleBackColor = false;
			// 
			// groupIDRadioButton
			// 
			this->groupIDRadioButton->AutoSize = true;
			this->groupIDRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->groupIDRadioButton->Checked = true;
			this->groupIDRadioButton->Location = System::Drawing::Point(36, 53);
			this->groupIDRadioButton->Name = L"groupIDRadioButton";
			this->groupIDRadioButton->Size = System::Drawing::Size(95, 16);
			this->groupIDRadioButton->TabIndex = 8;
			this->groupIDRadioButton->TabStop = true;
			this->groupIDRadioButton->Text = L"输入群组OuID";
			this->groupIDRadioButton->UseVisualStyleBackColor = false;
			// 
			// labelX28
			// 
			this->labelX28->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX28->BackgroundStyle->Class = L"";
			this->labelX28->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX28->Location = System::Drawing::Point(36, 28);
			this->labelX28->Name = L"labelX28";
			this->labelX28->Size = System::Drawing::Size(80, 23);
			this->labelX28->TabIndex = 7;
			this->labelX28->Text = L"输入群组信息";
			// 
			// AddFocusGroupSuperTabItem
			// 
			this->AddFocusGroupSuperTabItem->AttachedControl = this->superTabControlPanel29;
			this->AddFocusGroupSuperTabItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddFocusGroupSuperTabItem->GlobalItem = false;
			this->AddFocusGroupSuperTabItem->Name = L"AddFocusGroupSuperTabItem";
			this->AddFocusGroupSuperTabItem->Text = L"添加群组关注";
			this->AddFocusGroupSuperTabItem->ExpandChange += gcnew System::EventHandler(this, &FocusUserTab::AddFocusGroupSuperTabItem_ExpandChange);
			// 
			// FocusUserTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->Controls->Add(this->superTabControl6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FocusUserTab";
			this->Text = L"FocusUserTab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl6))->EndInit();
			this->superTabControl6->ResumeLayout(false);
			this->superTabControlPanel30->ResumeLayout(false);
			this->superTabControlPanel30->PerformLayout();
			this->superTabControlPanel27->ResumeLayout(false);
			this->panelEx4->ResumeLayout(false);
			this->expandablePanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sharingListAdvTree))->EndInit();
			this->recentUpdateExpandablePanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar4))->EndInit();
			this->superTabControlPanel29->ResumeLayout(false);
			this->superTabControlPanel29->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void focusIndividualSideBarPanelItem_ExpandChange(System::Object^  sender, System::EventArgs^  e) {
				 if(this->focusUserSideBarPanelItem->Expanded)
					 this->recentUpdateExpandablePanel->Text = L"用户的最新动态";
			 }
private: System::Void focusGroupSideBarPanelItem_ExpandChange(System::Object^  sender, System::EventArgs^  e) {
			 if(this->focusGroupSideBarPanelItem->Expanded)
				 this->recentUpdateExpandablePanel->Text = L"群的最新动态";
		 }
public:
	System::Void FocusUserTab::UpdateFocusUserListToUI();
	System::Void FocusUserTab::UpdateFocusGroupListToUI();

private: System::Void addGroupFocusSearchButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void addGroupFocusPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void addGroupFocusNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void addGroupFocusAddButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void ouIDRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void emailRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void nicknameRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void addUserFocusSearchButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void addUserFocusPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void addUserFocusNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void addUserFocusAddButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
		 System::Void FocusUserTab::InitializeSearchUserSearchResult();
		 System::Void FocusUserTab::InitializeSearchGroupSearchResult();
private: System::Void AddFocusGroupSuperTabItem_ExpandChange(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void AddUserFocusSuperTabItem_ExpandChange(System::Object^  sender, System::EventArgs^  e);
};
}
