#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// GroupListTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	ref class Communication;
	ref class SearchResult;
	ref class ChatMessage;
	ref class OusnsLoginUser;
	ref class OusnsGroup;
	ref class GroupChatDlg;
	ref class MessageCreator;
	public ref class GroupListTab : public System::Windows::Forms::Form
	{
	public:
		Communication^ comm;
		MainDlg^ mainDlg;
		delegate System::Void NewMessageDelegate(ChatMessage ^ msg);
		delegate System::Void UpdateInfoDelegate(unsigned int srcID);
		delegate System::Void ActionDelegate();
		delegate System::Void ParamActionDelegate(LinkedList<Object^>^ params);
		delegate System::Void SearchActionDelegate(int totalResult, int offset, LinkedList<SearchResult^>^ searchResult);
		OusnsLoginUser^ loginUser;
		MessageCreator^ msgCreator;
		GroupListTab(MainDlg^ mainDlgInput, Communication^ commInput,OusnsLoginUser^ loginUserInput, MessageCreator^ msgCreatorInput);

		// The following three dictionaries are used for keeping incoming message/file transfer requests when the corresponding
		// chat window is closed. As long as the chat window is open, these three dictionaries are always "empty" (i.e. no msgs, 
		// no file request, counts are all zeros).
		Dictionary<unsigned int, OuSns::GroupChatDlg^>^ groupChatDlgDict;
		Dictionary<unsigned int , LinkedList<ChatMessage^>^>^ msgsByGroup;
		Dictionary<unsigned int, unsigned int>^ pendingCountsByGroup;
		int pendingGroupMsgTotal;
		int searchGroupOffSet;
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~GroupListTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl3;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel18;
	private: DevComponents::DotNetBar::PanelEx^  panelEx3;
	private: DevComponents::DotNetBar::ExpandablePanel^  groupSharingFilePanel;
	private: DevComponents::AdvTree::AdvTree^  groupShareFileListAdvTree;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader1;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader2;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader5;
	private: DevComponents::AdvTree::Node^  node3;
	private: DevComponents::AdvTree::Node^  node4;
	private: DevComponents::AdvTree::Cell^  cell5;
	private: DevComponents::AdvTree::Cell^  cell6;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector2;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle2;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter5;
	private: DevComponents::DotNetBar::ExpandablePanel^  groupInformationPanel;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupCategoryLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupNameLabelX;
	private: DevComponents::DotNetBar::ButtonX^  myGroupListTabRefreshButtonX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  myGroupListTabGroupDescriptionTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupDescriptionTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupCategoryTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupNameTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupOwnerIDLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupOwnerIDTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupOuIDLabelX;
	private: DevComponents::DotNetBar::LabelX^  myGroupListTabGroupOuIDTitleLabelX;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter6;
	private: DevComponents::DotNetBar::SideBar^  groupList;
	private: DevComponents::DotNetBar::SideBarPanelItem^  myGroupListSideBarPanelItem;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem5;
	private: DevComponents::DotNetBar::Bar^  myGroupListBar;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem6;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem7;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem8;
	private: DevComponents::DotNetBar::SuperTabItem^  myGroupListTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel26;
	private: DevComponents::DotNetBar::LabelX^  labelX14;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  createGroupTabGroupTagTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabGroupTagLabelX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  createGroupTabGroupCategoryComboBoxEx;
	private: DevComponents::Editors::ComboItem^  comboItem9;
	private: DevComponents::Editors::ComboItem^  comboItem10;
	private: DevComponents::Editors::ComboItem^  comboItem8;
	private: DevComponents::DotNetBar::ButtonX^  createGroupTabCreateGroupButtonX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  createGroupTabSearchContactTextBoxX;
	private: DevComponents::AdvTree::AdvTree^  createGroupTabMemberListAdvTree;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector6;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle6;
	private: DevComponents::DotNetBar::ButtonX^  createGroupTabRemoveMemberButtonX;
	private: DevComponents::DotNetBar::ButtonX^  createGroupTabAddMemberButtonX;
	private: DevComponents::AdvTree::AdvTree^  createGroupTabContactListAdvTree;
	private: DevComponents::AdvTree::Node^  node9;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector5;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle5;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabGroupMemberLabelX;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabGroupCategoryLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  createGroupTabGroupDescriptionTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabGroupDescriptionLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  createGroupTabGroupNameTextBoxX;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabCreateCountRemainingLabelX2;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabCreateCountRemainingCounterLabelX;
	private: DevComponents::DotNetBar::LabelX^  createGroupTabCreateCountRemainingLabelX1;
	private: DevComponents::DotNetBar::SuperTabItem^  createGroupSuperTabItem;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel20;
	private: DevComponents::DotNetBar::LabelX^  searchGroupNextPageLabelX;
	private: DevComponents::DotNetBar::LabelX^  searchGroupPreviousPageLabelX;
	private: DevComponents::DotNetBar::ButtonX^  searchGroupJoinGroupButton;
	private: DevComponents::DotNetBar::Controls::ListViewEx^  searchGroupResultList;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: DevComponents::DotNetBar::LabelX^  labelX8;
	private: DevComponents::DotNetBar::ButtonX^  searchGroupSearchButton;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  searchGroupInputBox;
	private: System::Windows::Forms::RadioButton^  searchGroupKeywordRadioButton;
	private: System::Windows::Forms::RadioButton^  searchGroupOuidRadioButton;
	private: DevComponents::DotNetBar::LabelX^  labelX9;
	private: DevComponents::DotNetBar::SuperTabItem^  joinGroupTab;
	private: System::Windows::Forms::ContextMenuStrip^  groupListContextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  openGroupDlgToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitGroupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteGroupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createGroupToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->superTabControl3 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel18 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->panelEx3 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->groupSharingFilePanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->groupShareFileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->columnHeader1 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader2 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader5 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node3 = (gcnew DevComponents::AdvTree::Node());
			this->node4 = (gcnew DevComponents::AdvTree::Node());
			this->cell5 = (gcnew DevComponents::AdvTree::Cell());
			this->cell6 = (gcnew DevComponents::AdvTree::Cell());
			this->nodeConnector2 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle2 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->expandableSplitter5 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->groupInformationPanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->myGroupListTabGroupCategoryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupNameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabRefreshButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->myGroupListTabGroupDescriptionTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->myGroupListTabGroupDescriptionTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupCategoryTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupNameTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupOwnerIDLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupOwnerIDTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupOuIDLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myGroupListTabGroupOuIDTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->expandableSplitter6 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->groupList = (gcnew DevComponents::DotNetBar::SideBar());
			this->myGroupListSideBarPanelItem = (gcnew DevComponents::DotNetBar::SideBarPanelItem());
			this->buttonItem5 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->myGroupListBar = (gcnew DevComponents::DotNetBar::Bar());
			this->buttonItem6 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem7 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem8 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->myGroupListTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel26 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->labelX14 = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabGroupTagTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->createGroupTabGroupTagLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabGroupCategoryComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem9 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem10 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem8 = (gcnew DevComponents::Editors::ComboItem());
			this->createGroupTabCreateGroupButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->createGroupTabSearchContactTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->createGroupTabMemberListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->nodeConnector6 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle6 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->createGroupTabRemoveMemberButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->createGroupTabAddMemberButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->createGroupTabContactListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->node9 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector5 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle5 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->createGroupTabGroupMemberLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabGroupCategoryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabGroupDescriptionTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->createGroupTabGroupDescriptionLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabGroupNameTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->createGroupTabCreateCountRemainingLabelX2 = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabCreateCountRemainingCounterLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupTabCreateCountRemainingLabelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->createGroupSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel20 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->searchGroupNextPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchGroupPreviousPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchGroupJoinGroupButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchGroupResultList = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelX8 = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchGroupSearchButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchGroupInputBox = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->searchGroupKeywordRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->searchGroupOuidRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->labelX9 = (gcnew DevComponents::DotNetBar::LabelX());
			this->joinGroupTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->groupListContextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->openGroupDlgToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitGroupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteGroupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createGroupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl3))->BeginInit();
			this->superTabControl3->SuspendLayout();
			this->superTabControlPanel18->SuspendLayout();
			this->panelEx3->SuspendLayout();
			this->groupSharingFilePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groupShareFileListAdvTree))->BeginInit();
			this->groupInformationPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->myGroupListBar))->BeginInit();
			this->superTabControlPanel26->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->createGroupTabMemberListAdvTree))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->createGroupTabContactListAdvTree))->BeginInit();
			this->superTabControlPanel20->SuspendLayout();
			this->groupListContextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// superTabControl3
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl3->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl3->ControlBox->MenuBox->Name = L"";
			this->superTabControl3->ControlBox->MenuBox->Visible = false;
			this->superTabControl3->ControlBox->Name = L"";
			this->superTabControl3->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl3->ControlBox->MenuBox, 
				this->superTabControl3->ControlBox->CloseBox});
			this->superTabControl3->Controls->Add(this->superTabControlPanel20);
			this->superTabControl3->Controls->Add(this->superTabControlPanel26);
			this->superTabControl3->Controls->Add(this->superTabControlPanel18);
			this->superTabControl3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl3->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl3->Location = System::Drawing::Point(0, 0);
			this->superTabControl3->Name = L"superTabControl3";
			this->superTabControl3->ReorderTabsEnabled = true;
			this->superTabControl3->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl3->SelectedTabIndex = 0;
			this->superTabControl3->Size = System::Drawing::Size(593, 573);
			this->superTabControl3->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl3->TabIndex = 3;
			this->superTabControl3->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->myGroupListTab, 
				this->joinGroupTab, this->createGroupSuperTabItem});
			this->superTabControl3->Text = L"superTabControl3";
			this->superTabControl3->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel18
			// 
			this->superTabControlPanel18->Controls->Add(this->panelEx3);
			this->superTabControlPanel18->Controls->Add(this->expandableSplitter6);
			this->superTabControlPanel18->Controls->Add(this->groupList);
			this->superTabControlPanel18->Controls->Add(this->myGroupListBar);
			this->superTabControlPanel18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel18->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel18->Name = L"superTabControlPanel18";
			this->superTabControlPanel18->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel18->TabIndex = 1;
			this->superTabControlPanel18->TabItem = this->myGroupListTab;
			// 
			// panelEx3
			// 
			this->panelEx3->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx3->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx3->Controls->Add(this->groupSharingFilePanel);
			this->panelEx3->Controls->Add(this->expandableSplitter5);
			this->panelEx3->Controls->Add(this->groupInformationPanel);
			this->panelEx3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx3->Location = System::Drawing::Point(121, 25);
			this->panelEx3->Name = L"panelEx3";
			this->panelEx3->Size = System::Drawing::Size(472, 506);
			this->panelEx3->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx3->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->panelEx3->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->panelEx3->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->panelEx3->Style->GradientAngle = 90;
			this->panelEx3->TabIndex = 9;
			// 
			// groupSharingFilePanel
			// 
			this->groupSharingFilePanel->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupSharingFilePanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->groupSharingFilePanel->Controls->Add(this->groupShareFileListAdvTree);
			this->groupSharingFilePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupSharingFilePanel->ExpandButtonVisible = false;
			this->groupSharingFilePanel->Location = System::Drawing::Point(0, 235);
			this->groupSharingFilePanel->Name = L"groupSharingFilePanel";
			this->groupSharingFilePanel->Size = System::Drawing::Size(472, 271);
			this->groupSharingFilePanel->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->groupSharingFilePanel->Style->BackColor1->Color = System::Drawing::Color::White;
			this->groupSharingFilePanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->groupSharingFilePanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->groupSharingFilePanel->Style->GradientAngle = 90;
			this->groupSharingFilePanel->TabIndex = 2;
			this->groupSharingFilePanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->groupSharingFilePanel->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->groupSharingFilePanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->groupSharingFilePanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->groupSharingFilePanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupSharingFilePanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupSharingFilePanel->TitleStyle->GradientAngle = 90;
			this->groupSharingFilePanel->TitleText = L"群组共享的文件";
			// 
			// groupShareFileListAdvTree
			// 
			this->groupShareFileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->groupShareFileListAdvTree->AllowDrop = true;
			this->groupShareFileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->groupShareFileListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->groupShareFileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupShareFileListAdvTree->Columns->Add(this->columnHeader1);
			this->groupShareFileListAdvTree->Columns->Add(this->columnHeader2);
			this->groupShareFileListAdvTree->Columns->Add(this->columnHeader5);
			this->groupShareFileListAdvTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupShareFileListAdvTree->HotTracking = true;
			this->groupShareFileListAdvTree->Location = System::Drawing::Point(0, 26);
			this->groupShareFileListAdvTree->Name = L"groupShareFileListAdvTree";
			this->groupShareFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node3});
			this->groupShareFileListAdvTree->NodesConnector = this->nodeConnector2;
			this->groupShareFileListAdvTree->NodeStyle = this->elementStyle2;
			this->groupShareFileListAdvTree->PathSeparator = L";";
			this->groupShareFileListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->groupShareFileListAdvTree->Size = System::Drawing::Size(472, 245);
			this->groupShareFileListAdvTree->Styles->Add(this->elementStyle2);
			this->groupShareFileListAdvTree->TabIndex = 2;
			this->groupShareFileListAdvTree->Text = L"advTree1";
			// 
			// columnHeader1
			// 
			this->columnHeader1->DisplayIndex = 1;
			this->columnHeader1->Name = L"columnHeader1";
			this->columnHeader1->Text = L"文件名称";
			this->columnHeader1->Width->Absolute = 150;
			// 
			// columnHeader2
			// 
			this->columnHeader2->DisplayIndex = 2;
			this->columnHeader2->Name = L"columnHeader2";
			this->columnHeader2->Text = L"文件大小";
			this->columnHeader2->Width->Absolute = 150;
			// 
			// columnHeader5
			// 
			this->columnHeader5->DisplayIndex = 3;
			this->columnHeader5->Name = L"columnHeader5";
			this->columnHeader5->Text = L"文件描述";
			this->columnHeader5->Width->Absolute = 150;
			// 
			// node3
			// 
			this->node3->Expanded = true;
			this->node3->Name = L"node3";
			this->node3->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node4});
			this->node3->Text = L"文件名1";
			// 
			// node4
			// 
			this->node4->Cells->Add(this->cell5);
			this->node4->Cells->Add(this->cell6);
			this->node4->Name = L"node4";
			this->node4->Text = L"文件名2";
			// 
			// cell5
			// 
			this->cell5->Name = L"cell5";
			this->cell5->StyleMouseOver = nullptr;
			this->cell5->Text = L"文件大小2";
			// 
			// cell6
			// 
			this->cell6->Name = L"cell6";
			this->cell6->StyleMouseOver = nullptr;
			this->cell6->Text = L"文件描述2";
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
			// expandableSplitter5
			// 
			this->expandableSplitter5->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter5->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter5->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter5->Dock = System::Windows::Forms::DockStyle::Top;
			this->expandableSplitter5->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter5->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter5->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter5->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter5->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter5->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter5->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter5->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter5->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter5->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter5->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter5->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter5->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter5->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter5->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter5->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter5->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter5->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter5->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter5->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter5->Location = System::Drawing::Point(0, 230);
			this->expandableSplitter5->Name = L"expandableSplitter5";
			this->expandableSplitter5->Size = System::Drawing::Size(472, 5);
			this->expandableSplitter5->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter5->TabIndex = 1;
			this->expandableSplitter5->TabStop = false;
			// 
			// groupInformationPanel
			// 
			this->groupInformationPanel->CanvasColor = System::Drawing::SystemColors::Control;
			this->groupInformationPanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupCategoryLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupNameLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabRefreshButtonX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupDescriptionTextBoxX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupDescriptionTitleLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupCategoryTitleLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupNameTitleLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupOwnerIDLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupOwnerIDTitleLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupOuIDLabelX);
			this->groupInformationPanel->Controls->Add(this->myGroupListTabGroupOuIDTitleLabelX);
			this->groupInformationPanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->groupInformationPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupInformationPanel->ExpandButtonVisible = false;
			this->groupInformationPanel->Location = System::Drawing::Point(0, 0);
			this->groupInformationPanel->Name = L"groupInformationPanel";
			this->groupInformationPanel->Size = System::Drawing::Size(472, 230);
			this->groupInformationPanel->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->groupInformationPanel->Style->BackColor1->Color = System::Drawing::Color::White;
			this->groupInformationPanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->groupInformationPanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->groupInformationPanel->Style->GradientAngle = 90;
			this->groupInformationPanel->TabIndex = 0;
			this->groupInformationPanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->groupInformationPanel->TitleStyle->BackColor1->Color = System::Drawing::Color::White;
			this->groupInformationPanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->groupInformationPanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->groupInformationPanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->groupInformationPanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->groupInformationPanel->TitleStyle->GradientAngle = 90;
			this->groupInformationPanel->TitleText = L"群组资料";
			// 
			// myGroupListTabGroupCategoryLabelX
			// 
			this->myGroupListTabGroupCategoryLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupCategoryLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupCategoryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupCategoryLabelX->Location = System::Drawing::Point(70, 76);
			this->myGroupListTabGroupCategoryLabelX->Name = L"myGroupListTabGroupCategoryLabelX";
			this->myGroupListTabGroupCategoryLabelX->Size = System::Drawing::Size(13, 16);
			this->myGroupListTabGroupCategoryLabelX->TabIndex = 14;
			this->myGroupListTabGroupCategoryLabelX->Text = L"-";
			// 
			// myGroupListTabGroupNameLabelX
			// 
			this->myGroupListTabGroupNameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupNameLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupNameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupNameLabelX->Location = System::Drawing::Point(77, 54);
			this->myGroupListTabGroupNameLabelX->Name = L"myGroupListTabGroupNameLabelX";
			this->myGroupListTabGroupNameLabelX->Size = System::Drawing::Size(13, 16);
			this->myGroupListTabGroupNameLabelX->TabIndex = 13;
			this->myGroupListTabGroupNameLabelX->Text = L"-";
			// 
			// myGroupListTabRefreshButtonX
			// 
			this->myGroupListTabRefreshButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->myGroupListTabRefreshButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->myGroupListTabRefreshButtonX->Location = System::Drawing::Point(385, 3);
			this->myGroupListTabRefreshButtonX->Name = L"myGroupListTabRefreshButtonX";
			this->myGroupListTabRefreshButtonX->Size = System::Drawing::Size(75, 19);
			this->myGroupListTabRefreshButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->myGroupListTabRefreshButtonX->TabIndex = 12;
			this->myGroupListTabRefreshButtonX->Text = L"刷新";
			this->myGroupListTabRefreshButtonX->Click += gcnew System::EventHandler(this, &GroupListTab::myGroupListTabRefreshButtonX_Click);
			// 
			// myGroupListTabGroupDescriptionTextBoxX
			// 
			this->myGroupListTabGroupDescriptionTextBoxX->BackColor = System::Drawing::SystemColors::Info;
			// 
			// 
			// 
			this->myGroupListTabGroupDescriptionTextBoxX->Border->Class = L"TextBoxBorder";
			this->myGroupListTabGroupDescriptionTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupDescriptionTextBoxX->Location = System::Drawing::Point(27, 118);
			this->myGroupListTabGroupDescriptionTextBoxX->MaxLength = 200;
			this->myGroupListTabGroupDescriptionTextBoxX->MinimumSize = System::Drawing::Size(0, 70);
			this->myGroupListTabGroupDescriptionTextBoxX->Multiline = true;
			this->myGroupListTabGroupDescriptionTextBoxX->Name = L"myGroupListTabGroupDescriptionTextBoxX";
			this->myGroupListTabGroupDescriptionTextBoxX->ReadOnly = true;
			this->myGroupListTabGroupDescriptionTextBoxX->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->myGroupListTabGroupDescriptionTextBoxX->Size = System::Drawing::Size(433, 70);
			this->myGroupListTabGroupDescriptionTextBoxX->TabIndex = 11;
			// 
			// myGroupListTabGroupDescriptionTitleLabelX
			// 
			// 
			// 
			// 
			this->myGroupListTabGroupDescriptionTitleLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupDescriptionTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupDescriptionTitleLabelX->Location = System::Drawing::Point(27, 96);
			this->myGroupListTabGroupDescriptionTitleLabelX->Name = L"myGroupListTabGroupDescriptionTitleLabelX";
			this->myGroupListTabGroupDescriptionTitleLabelX->Size = System::Drawing::Size(75, 23);
			this->myGroupListTabGroupDescriptionTitleLabelX->TabIndex = 9;
			this->myGroupListTabGroupDescriptionTitleLabelX->Text = L"群组简介：";
			// 
			// myGroupListTabGroupCategoryTitleLabelX
			// 
			this->myGroupListTabGroupCategoryTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupCategoryTitleLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupCategoryTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupCategoryTitleLabelX->Location = System::Drawing::Point(27, 76);
			this->myGroupListTabGroupCategoryTitleLabelX->Name = L"myGroupListTabGroupCategoryTitleLabelX";
			this->myGroupListTabGroupCategoryTitleLabelX->Size = System::Drawing::Size(44, 18);
			this->myGroupListTabGroupCategoryTitleLabelX->TabIndex = 7;
			this->myGroupListTabGroupCategoryTitleLabelX->Text = L"分类：";
			// 
			// myGroupListTabGroupNameTitleLabelX
			// 
			this->myGroupListTabGroupNameTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupNameTitleLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupNameTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupNameTitleLabelX->Location = System::Drawing::Point(27, 54);
			this->myGroupListTabGroupNameTitleLabelX->Name = L"myGroupListTabGroupNameTitleLabelX";
			this->myGroupListTabGroupNameTitleLabelX->Size = System::Drawing::Size(44, 18);
			this->myGroupListTabGroupNameTitleLabelX->TabIndex = 5;
			this->myGroupListTabGroupNameTitleLabelX->Text = L"名称：";
			// 
			// myGroupListTabGroupOwnerIDLabelX
			// 
			this->myGroupListTabGroupOwnerIDLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupOwnerIDLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupOwnerIDLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupOwnerIDLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
			this->myGroupListTabGroupOwnerIDLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->myGroupListTabGroupOwnerIDLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->myGroupListTabGroupOwnerIDLabelX->Location = System::Drawing::Point(322, 33);
			this->myGroupListTabGroupOwnerIDLabelX->Name = L"myGroupListTabGroupOwnerIDLabelX";
			this->myGroupListTabGroupOwnerIDLabelX->Size = System::Drawing::Size(13, 16);
			this->myGroupListTabGroupOwnerIDLabelX->TabIndex = 4;
			this->myGroupListTabGroupOwnerIDLabelX->Text = L"-";
			// 
			// myGroupListTabGroupOwnerIDTitleLabelX
			// 
			this->myGroupListTabGroupOwnerIDTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupOwnerIDTitleLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupOwnerIDTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupOwnerIDTitleLabelX->Location = System::Drawing::Point(241, 33);
			this->myGroupListTabGroupOwnerIDTitleLabelX->Name = L"myGroupListTabGroupOwnerIDTitleLabelX";
			this->myGroupListTabGroupOwnerIDTitleLabelX->Size = System::Drawing::Size(56, 18);
			this->myGroupListTabGroupOwnerIDTitleLabelX->TabIndex = 3;
			this->myGroupListTabGroupOwnerIDTitleLabelX->Text = L"创建人：";
			// 
			// myGroupListTabGroupOuIDLabelX
			// 
			this->myGroupListTabGroupOuIDLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupOuIDLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupOuIDLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupOuIDLabelX->Location = System::Drawing::Point(92, 33);
			this->myGroupListTabGroupOuIDLabelX->Name = L"myGroupListTabGroupOuIDLabelX";
			this->myGroupListTabGroupOuIDLabelX->Size = System::Drawing::Size(13, 16);
			this->myGroupListTabGroupOuIDLabelX->TabIndex = 2;
			this->myGroupListTabGroupOuIDLabelX->Text = L"-";
			// 
			// myGroupListTabGroupOuIDTitleLabelX
			// 
			this->myGroupListTabGroupOuIDTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myGroupListTabGroupOuIDTitleLabelX->BackgroundStyle->Class = L"";
			this->myGroupListTabGroupOuIDTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myGroupListTabGroupOuIDTitleLabelX->Location = System::Drawing::Point(27, 33);
			this->myGroupListTabGroupOuIDTitleLabelX->Name = L"myGroupListTabGroupOuIDTitleLabelX";
			this->myGroupListTabGroupOuIDTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myGroupListTabGroupOuIDTitleLabelX->TabIndex = 1;
			this->myGroupListTabGroupOuIDTitleLabelX->Text = L"群组号码：";
			// 
			// expandableSplitter6
			// 
			this->expandableSplitter6->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter6->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter6->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter6->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter6->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter6->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter6->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter6->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter6->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter6->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter6->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter6->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter6->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter6->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter6->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter6->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter6->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter6->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter6->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter6->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter6->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter6->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter6->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter6->Location = System::Drawing::Point(116, 25);
			this->expandableSplitter6->Name = L"expandableSplitter6";
			this->expandableSplitter6->Size = System::Drawing::Size(5, 506);
			this->expandableSplitter6->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter6->TabIndex = 8;
			this->expandableSplitter6->TabStop = false;
			// 
			// groupList
			// 
			this->groupList->AccessibleRole = System::Windows::Forms::AccessibleRole::ToolBar;
			this->groupList->BorderStyle = DevComponents::DotNetBar::eBorderType::None;
			this->groupList->Dock = System::Windows::Forms::DockStyle::Left;
			this->groupList->ExpandedPanel = this->myGroupListSideBarPanelItem;
			this->groupList->Location = System::Drawing::Point(0, 25);
			this->groupList->MinimumSize = System::Drawing::Size(116, 0);
			this->groupList->Name = L"groupList";
			this->groupList->Panels->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->myGroupListSideBarPanelItem});
			this->groupList->Size = System::Drawing::Size(116, 506);
			this->groupList->Style = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->groupList->TabIndex = 3;
			this->groupList->Text = L"sideBar3";
			this->groupList->UsingSystemColors = true;
			this->groupList->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GroupListTab::groupList_MouseUp);
			// 
			// myGroupListSideBarPanelItem
			// 
			this->myGroupListSideBarPanelItem->FontBold = true;
			this->myGroupListSideBarPanelItem->Name = L"myGroupListSideBarPanelItem";
			this->myGroupListSideBarPanelItem->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->buttonItem5});
			this->myGroupListSideBarPanelItem->Text = L"我的群组";
			// 
			// buttonItem5
			// 
			this->buttonItem5->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
			this->buttonItem5->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
			this->buttonItem5->Name = L"buttonItem5";
			this->buttonItem5->Text = L"New Button";
			// 
			// myGroupListBar
			// 
			this->myGroupListBar->AntiAlias = true;
			this->myGroupListBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->myGroupListBar->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->myGroupListBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->buttonItem6, this->buttonItem7, 
				this->buttonItem8});
			this->myGroupListBar->Location = System::Drawing::Point(0, 0);
			this->myGroupListBar->MinimumSize = System::Drawing::Size(0, 25);
			this->myGroupListBar->Name = L"myGroupListBar";
			this->myGroupListBar->PaddingTop = 4;
			this->myGroupListBar->Size = System::Drawing::Size(593, 25);
			this->myGroupListBar->Stretch = true;
			this->myGroupListBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->myGroupListBar->TabIndex = 2;
			this->myGroupListBar->TabStop = false;
			this->myGroupListBar->Text = L"bar3";
			// 
			// buttonItem6
			// 
			this->buttonItem6->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem6->Name = L"buttonItem6";
			this->buttonItem6->Text = L"创建新分类";
			// 
			// buttonItem7
			// 
			this->buttonItem7->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem7->Name = L"buttonItem7";
			this->buttonItem7->Text = L"重命名分类";
			// 
			// buttonItem8
			// 
			this->buttonItem8->FixedSize = System::Drawing::Size(100, 17);
			this->buttonItem8->Name = L"buttonItem8";
			this->buttonItem8->Text = L"删除分类";
			// 
			// myGroupListTab
			// 
			this->myGroupListTab->AttachedControl = this->superTabControlPanel18;
			this->myGroupListTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->myGroupListTab->GlobalItem = false;
			this->myGroupListTab->Name = L"myGroupListTab";
			this->myGroupListTab->Text = L"我的群组";
			// 
			// superTabControlPanel26
			// 
			this->superTabControlPanel26->Controls->Add(this->labelX14);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupTagTextBoxX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupTagLabelX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupCategoryComboBoxEx);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabCreateGroupButtonX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabSearchContactTextBoxX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabMemberListAdvTree);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabRemoveMemberButtonX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabAddMemberButtonX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabContactListAdvTree);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupMemberLabelX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupCategoryLabelX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupDescriptionTextBoxX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupDescriptionLabelX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabGroupNameTextBoxX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabCreateCountRemainingLabelX2);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabCreateCountRemainingCounterLabelX);
			this->superTabControlPanel26->Controls->Add(this->createGroupTabCreateCountRemainingLabelX1);
			this->superTabControlPanel26->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->superTabControlPanel26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel26->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel26->Name = L"superTabControlPanel26";
			this->superTabControlPanel26->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel26->TabIndex = 0;
			this->superTabControlPanel26->TabItem = this->createGroupSuperTabItem;
			// 
			// labelX14
			// 
			this->labelX14->AutoSize = true;
			this->labelX14->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX14->BackgroundStyle->Class = L"";
			this->labelX14->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX14->Cursor = System::Windows::Forms::Cursors::Default;
			this->labelX14->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->labelX14->Location = System::Drawing::Point(31, 50);
			this->labelX14->Name = L"labelX14";
			this->labelX14->Size = System::Drawing::Size(90, 26);
			this->labelX14->TabIndex = 52;
			this->labelX14->Text = L"群组名称：";
			// 
			// createGroupTabGroupTagTextBoxX
			// 
			// 
			// 
			// 
			this->createGroupTabGroupTagTextBoxX->Border->Class = L"TextBoxBorder";
			this->createGroupTabGroupTagTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupTagTextBoxX->Location = System::Drawing::Point(164, 163);
			this->createGroupTabGroupTagTextBoxX->Name = L"createGroupTabGroupTagTextBoxX";
			this->createGroupTabGroupTagTextBoxX->Size = System::Drawing::Size(350, 21);
			this->createGroupTabGroupTagTextBoxX->TabIndex = 51;
			this->createGroupTabGroupTagTextBoxX->Text = L"仅限文字，字母以及数字，请以空格分隔每个关键字词";
			this->createGroupTabGroupTagTextBoxX->Enter += gcnew System::EventHandler(this, &GroupListTab::createGroupTabGroupTagTextBoxX_Enter);
			// 
			// createGroupTabGroupTagLabelX
			// 
			this->createGroupTabGroupTagLabelX->AutoSize = true;
			this->createGroupTabGroupTagLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabGroupTagLabelX->BackgroundStyle->Class = L"";
			this->createGroupTabGroupTagLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupTagLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabGroupTagLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->createGroupTabGroupTagLabelX->Location = System::Drawing::Point(32, 161);
			this->createGroupTabGroupTagLabelX->Name = L"createGroupTabGroupTagLabelX";
			this->createGroupTabGroupTagLabelX->Size = System::Drawing::Size(123, 26);
			this->createGroupTabGroupTagLabelX->TabIndex = 50;
			this->createGroupTabGroupTagLabelX->Text = L"群组搜索标签：";
			// 
			// createGroupTabGroupCategoryComboBoxEx
			// 
			this->createGroupTabGroupCategoryComboBoxEx->DisplayMember = L"Text";
			this->createGroupTabGroupCategoryComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->createGroupTabGroupCategoryComboBoxEx->FormattingEnabled = true;
			this->createGroupTabGroupCategoryComboBoxEx->ItemHeight = 15;
			this->createGroupTabGroupCategoryComboBoxEx->Items->AddRange(gcnew cli::array< System::Object^  >(3) {this->comboItem9, this->comboItem10, 
				this->comboItem8});
			this->createGroupTabGroupCategoryComboBoxEx->Location = System::Drawing::Point(398, 54);
			this->createGroupTabGroupCategoryComboBoxEx->Name = L"createGroupTabGroupCategoryComboBoxEx";
			this->createGroupTabGroupCategoryComboBoxEx->Size = System::Drawing::Size(116, 21);
			this->createGroupTabGroupCategoryComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->createGroupTabGroupCategoryComboBoxEx->TabIndex = 49;
			// 
			// comboItem9
			// 
			this->comboItem9->Text = L"影视";
			// 
			// comboItem10
			// 
			this->comboItem10->Text = L"游戏";
			// 
			// comboItem8
			// 
			this->comboItem8->Text = L"其他";
			// 
			// createGroupTabCreateGroupButtonX
			// 
			this->createGroupTabCreateGroupButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->createGroupTabCreateGroupButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->createGroupTabCreateGroupButtonX->Location = System::Drawing::Point(460, 484);
			this->createGroupTabCreateGroupButtonX->Name = L"createGroupTabCreateGroupButtonX";
			this->createGroupTabCreateGroupButtonX->Size = System::Drawing::Size(75, 23);
			this->createGroupTabCreateGroupButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->createGroupTabCreateGroupButtonX->TabIndex = 48;
			this->createGroupTabCreateGroupButtonX->Text = L"建立群组";
			this->createGroupTabCreateGroupButtonX->Click += gcnew System::EventHandler(this, &GroupListTab::createGroupTabCreateGroupButtonX_Click);
			// 
			// createGroupTabSearchContactTextBoxX
			// 
			// 
			// 
			// 
			this->createGroupTabSearchContactTextBoxX->Border->Class = L"TextBoxBorder";
			this->createGroupTabSearchContactTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabSearchContactTextBoxX->Location = System::Drawing::Point(35, 225);
			this->createGroupTabSearchContactTextBoxX->MaxLength = 20;
			this->createGroupTabSearchContactTextBoxX->Name = L"createGroupTabSearchContactTextBoxX";
			this->createGroupTabSearchContactTextBoxX->Size = System::Drawing::Size(184, 21);
			this->createGroupTabSearchContactTextBoxX->TabIndex = 47;
			this->createGroupTabSearchContactTextBoxX->Text = L"搜索联系人";
			this->createGroupTabSearchContactTextBoxX->Enter += gcnew System::EventHandler(this, &GroupListTab::createGroupTabSearchContactTextBoxX_Enter);
			this->createGroupTabSearchContactTextBoxX->TextChanged += gcnew System::EventHandler(this, &GroupListTab::createGroupTabSearchContactTextBoxX_TextChanged);
			// 
			// createGroupTabMemberListAdvTree
			// 
			this->createGroupTabMemberListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->createGroupTabMemberListAdvTree->AllowDrop = true;
			this->createGroupTabMemberListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->createGroupTabMemberListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->createGroupTabMemberListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabMemberListAdvTree->ExpandWidth = 0;
			this->createGroupTabMemberListAdvTree->Location = System::Drawing::Point(350, 258);
			this->createGroupTabMemberListAdvTree->MultiSelect = true;
			this->createGroupTabMemberListAdvTree->Name = L"createGroupTabMemberListAdvTree";
			this->createGroupTabMemberListAdvTree->NodesConnector = this->nodeConnector6;
			this->createGroupTabMemberListAdvTree->NodeStyle = this->elementStyle6;
			this->createGroupTabMemberListAdvTree->PathSeparator = L";";
			this->createGroupTabMemberListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->createGroupTabMemberListAdvTree->Size = System::Drawing::Size(184, 207);
			this->createGroupTabMemberListAdvTree->Styles->Add(this->elementStyle6);
			this->createGroupTabMemberListAdvTree->TabIndex = 46;
			this->createGroupTabMemberListAdvTree->Text = L"advTree2";
			// 
			// nodeConnector6
			// 
			this->nodeConnector6->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle6
			// 
			this->elementStyle6->Class = L"";
			this->elementStyle6->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle6->Name = L"elementStyle6";
			this->elementStyle6->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// createGroupTabRemoveMemberButtonX
			// 
			this->createGroupTabRemoveMemberButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->createGroupTabRemoveMemberButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->createGroupTabRemoveMemberButtonX->Location = System::Drawing::Point(250, 388);
			this->createGroupTabRemoveMemberButtonX->Name = L"createGroupTabRemoveMemberButtonX";
			this->createGroupTabRemoveMemberButtonX->Size = System::Drawing::Size(75, 23);
			this->createGroupTabRemoveMemberButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->createGroupTabRemoveMemberButtonX->TabIndex = 45;
			this->createGroupTabRemoveMemberButtonX->Text = L"<-移除";
			this->createGroupTabRemoveMemberButtonX->Click += gcnew System::EventHandler(this, &GroupListTab::createGroupTabRemoveMemberButtonX_Click);
			// 
			// createGroupTabAddMemberButtonX
			// 
			this->createGroupTabAddMemberButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->createGroupTabAddMemberButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->createGroupTabAddMemberButtonX->Location = System::Drawing::Point(251, 324);
			this->createGroupTabAddMemberButtonX->Name = L"createGroupTabAddMemberButtonX";
			this->createGroupTabAddMemberButtonX->Size = System::Drawing::Size(75, 23);
			this->createGroupTabAddMemberButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->createGroupTabAddMemberButtonX->TabIndex = 44;
			this->createGroupTabAddMemberButtonX->Text = L"添加->";
			this->createGroupTabAddMemberButtonX->Click += gcnew System::EventHandler(this, &GroupListTab::createGroupTabAddMemberButtonX_Click);
			// 
			// createGroupTabContactListAdvTree
			// 
			this->createGroupTabContactListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->createGroupTabContactListAdvTree->AllowDrop = true;
			this->createGroupTabContactListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->createGroupTabContactListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->createGroupTabContactListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabContactListAdvTree->ExpandWidth = 0;
			this->createGroupTabContactListAdvTree->Location = System::Drawing::Point(35, 258);
			this->createGroupTabContactListAdvTree->MultiSelect = true;
			this->createGroupTabContactListAdvTree->Name = L"createGroupTabContactListAdvTree";
			this->createGroupTabContactListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node9});
			this->createGroupTabContactListAdvTree->NodesConnector = this->nodeConnector5;
			this->createGroupTabContactListAdvTree->NodeStyle = this->elementStyle5;
			this->createGroupTabContactListAdvTree->PathSeparator = L";";
			this->createGroupTabContactListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->createGroupTabContactListAdvTree->Size = System::Drawing::Size(184, 207);
			this->createGroupTabContactListAdvTree->Styles->Add(this->elementStyle5);
			this->createGroupTabContactListAdvTree->TabIndex = 43;
			this->createGroupTabContactListAdvTree->Text = L"advTree1";
			// 
			// node9
			// 
			this->node9->Expanded = true;
			this->node9->Name = L"node9";
			this->node9->Text = L"node9";
			// 
			// nodeConnector5
			// 
			this->nodeConnector5->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle5
			// 
			this->elementStyle5->Class = L"";
			this->elementStyle5->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle5->Name = L"elementStyle5";
			this->elementStyle5->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// createGroupTabGroupMemberLabelX
			// 
			this->createGroupTabGroupMemberLabelX->AutoSize = true;
			this->createGroupTabGroupMemberLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabGroupMemberLabelX->BackgroundStyle->Class = L"";
			this->createGroupTabGroupMemberLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupMemberLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabGroupMemberLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->createGroupTabGroupMemberLabelX->Location = System::Drawing::Point(32, 188);
			this->createGroupTabGroupMemberLabelX->Name = L"createGroupTabGroupMemberLabelX";
			this->createGroupTabGroupMemberLabelX->Size = System::Drawing::Size(90, 26);
			this->createGroupTabGroupMemberLabelX->TabIndex = 42;
			this->createGroupTabGroupMemberLabelX->Text = L"群组成员：";
			// 
			// createGroupTabGroupCategoryLabelX
			// 
			this->createGroupTabGroupCategoryLabelX->AutoSize = true;
			this->createGroupTabGroupCategoryLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabGroupCategoryLabelX->BackgroundStyle->Class = L"";
			this->createGroupTabGroupCategoryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupCategoryLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabGroupCategoryLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->createGroupTabGroupCategoryLabelX->Location = System::Drawing::Point(304, 51);
			this->createGroupTabGroupCategoryLabelX->Name = L"createGroupTabGroupCategoryLabelX";
			this->createGroupTabGroupCategoryLabelX->Size = System::Drawing::Size(90, 26);
			this->createGroupTabGroupCategoryLabelX->TabIndex = 40;
			this->createGroupTabGroupCategoryLabelX->Text = L"群组类别：";
			// 
			// createGroupTabGroupDescriptionTextBoxX
			// 
			// 
			// 
			// 
			this->createGroupTabGroupDescriptionTextBoxX->Border->Class = L"TextBoxBorder";
			this->createGroupTabGroupDescriptionTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupDescriptionTextBoxX->Location = System::Drawing::Point(128, 86);
			this->createGroupTabGroupDescriptionTextBoxX->Multiline = true;
			this->createGroupTabGroupDescriptionTextBoxX->Name = L"createGroupTabGroupDescriptionTextBoxX";
			this->createGroupTabGroupDescriptionTextBoxX->Size = System::Drawing::Size(386, 69);
			this->createGroupTabGroupDescriptionTextBoxX->TabIndex = 39;
			// 
			// createGroupTabGroupDescriptionLabelX
			// 
			this->createGroupTabGroupDescriptionLabelX->AutoSize = true;
			this->createGroupTabGroupDescriptionLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabGroupDescriptionLabelX->BackgroundStyle->Class = L"";
			this->createGroupTabGroupDescriptionLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupDescriptionLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabGroupDescriptionLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->createGroupTabGroupDescriptionLabelX->Location = System::Drawing::Point(32, 85);
			this->createGroupTabGroupDescriptionLabelX->Name = L"createGroupTabGroupDescriptionLabelX";
			this->createGroupTabGroupDescriptionLabelX->Size = System::Drawing::Size(90, 26);
			this->createGroupTabGroupDescriptionLabelX->TabIndex = 37;
			this->createGroupTabGroupDescriptionLabelX->Text = L"群组描述：";
			// 
			// createGroupTabGroupNameTextBoxX
			// 
			// 
			// 
			// 
			this->createGroupTabGroupNameTextBoxX->Border->Class = L"TextBoxBorder";
			this->createGroupTabGroupNameTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabGroupNameTextBoxX->Location = System::Drawing::Point(128, 54);
			this->createGroupTabGroupNameTextBoxX->Name = L"createGroupTabGroupNameTextBoxX";
			this->createGroupTabGroupNameTextBoxX->Size = System::Drawing::Size(124, 21);
			this->createGroupTabGroupNameTextBoxX->TabIndex = 36;
			// 
			// createGroupTabCreateCountRemainingLabelX2
			// 
			this->createGroupTabCreateCountRemainingLabelX2->AutoSize = true;
			this->createGroupTabCreateCountRemainingLabelX2->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabCreateCountRemainingLabelX2->BackgroundStyle->Class = L"";
			this->createGroupTabCreateCountRemainingLabelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabCreateCountRemainingLabelX2->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabCreateCountRemainingLabelX2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold));
			this->createGroupTabCreateCountRemainingLabelX2->Location = System::Drawing::Point(164, 8);
			this->createGroupTabCreateCountRemainingLabelX2->Name = L"createGroupTabCreateCountRemainingLabelX2";
			this->createGroupTabCreateCountRemainingLabelX2->Size = System::Drawing::Size(57, 26);
			this->createGroupTabCreateCountRemainingLabelX2->TabIndex = 34;
			this->createGroupTabCreateCountRemainingLabelX2->Text = L"个群组";
			// 
			// createGroupTabCreateCountRemainingCounterLabelX
			// 
			this->createGroupTabCreateCountRemainingCounterLabelX->AutoSize = true;
			this->createGroupTabCreateCountRemainingCounterLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabCreateCountRemainingCounterLabelX->BackgroundStyle->Class = L"";
			this->createGroupTabCreateCountRemainingCounterLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabCreateCountRemainingCounterLabelX->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabCreateCountRemainingCounterLabelX->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->createGroupTabCreateCountRemainingCounterLabelX->Location = System::Drawing::Point(140, 8);
			this->createGroupTabCreateCountRemainingCounterLabelX->Name = L"createGroupTabCreateCountRemainingCounterLabelX";
			this->createGroupTabCreateCountRemainingCounterLabelX->Size = System::Drawing::Size(18, 26);
			this->createGroupTabCreateCountRemainingCounterLabelX->TabIndex = 33;
			this->createGroupTabCreateCountRemainingCounterLabelX->Text = L"5";
			// 
			// createGroupTabCreateCountRemainingLabelX1
			// 
			this->createGroupTabCreateCountRemainingLabelX1->AutoSize = true;
			this->createGroupTabCreateCountRemainingLabelX1->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->createGroupTabCreateCountRemainingLabelX1->BackgroundStyle->Class = L"";
			this->createGroupTabCreateCountRemainingLabelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->createGroupTabCreateCountRemainingLabelX1->Cursor = System::Windows::Forms::Cursors::Default;
			this->createGroupTabCreateCountRemainingLabelX1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->createGroupTabCreateCountRemainingLabelX1->Location = System::Drawing::Point(32, 8);
			this->createGroupTabCreateCountRemainingLabelX1->Name = L"createGroupTabCreateCountRemainingLabelX1";
			this->createGroupTabCreateCountRemainingLabelX1->Size = System::Drawing::Size(107, 26);
			this->createGroupTabCreateCountRemainingLabelX1->TabIndex = 32;
			this->createGroupTabCreateCountRemainingLabelX1->Text = L"您还可以创建";
			// 
			// createGroupSuperTabItem
			// 
			this->createGroupSuperTabItem->AttachedControl = this->superTabControlPanel26;
			this->createGroupSuperTabItem->GlobalItem = false;
			this->createGroupSuperTabItem->Name = L"createGroupSuperTabItem";
			this->createGroupSuperTabItem->Text = L"建立群组";
			this->createGroupSuperTabItem->Click += gcnew System::EventHandler(this, &GroupListTab::createGroupSuperTabItem_Click);
			// 
			// superTabControlPanel20
			// 
			this->superTabControlPanel20->Controls->Add(this->searchGroupNextPageLabelX);
			this->superTabControlPanel20->Controls->Add(this->searchGroupPreviousPageLabelX);
			this->superTabControlPanel20->Controls->Add(this->searchGroupJoinGroupButton);
			this->superTabControlPanel20->Controls->Add(this->searchGroupResultList);
			this->superTabControlPanel20->Controls->Add(this->labelX8);
			this->superTabControlPanel20->Controls->Add(this->searchGroupSearchButton);
			this->superTabControlPanel20->Controls->Add(this->searchGroupInputBox);
			this->superTabControlPanel20->Controls->Add(this->searchGroupKeywordRadioButton);
			this->superTabControlPanel20->Controls->Add(this->searchGroupOuidRadioButton);
			this->superTabControlPanel20->Controls->Add(this->labelX9);
			this->superTabControlPanel20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel20->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel20->Name = L"superTabControlPanel20";
			this->superTabControlPanel20->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel20->TabIndex = 0;
			this->superTabControlPanel20->TabItem = this->joinGroupTab;
			// 
			// searchGroupNextPageLabelX
			// 
			this->searchGroupNextPageLabelX->AutoSize = true;
			this->searchGroupNextPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchGroupNextPageLabelX->BackgroundStyle->Class = L"";
			this->searchGroupNextPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchGroupNextPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchGroupNextPageLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->searchGroupNextPageLabelX->Location = System::Drawing::Point(100, 463);
			this->searchGroupNextPageLabelX->Name = L"searchGroupNextPageLabelX";
			this->searchGroupNextPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchGroupNextPageLabelX->TabIndex = 16;
			this->searchGroupNextPageLabelX->Text = L"下一页";
			// 
			// searchGroupPreviousPageLabelX
			// 
			this->searchGroupPreviousPageLabelX->AutoSize = true;
			this->searchGroupPreviousPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchGroupPreviousPageLabelX->BackgroundStyle->Class = L"";
			this->searchGroupPreviousPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchGroupPreviousPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchGroupPreviousPageLabelX->ForeColor = System::Drawing::Color::Gray;
			this->searchGroupPreviousPageLabelX->Location = System::Drawing::Point(48, 463);
			this->searchGroupPreviousPageLabelX->Name = L"searchGroupPreviousPageLabelX";
			this->searchGroupPreviousPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchGroupPreviousPageLabelX->TabIndex = 15;
			this->searchGroupPreviousPageLabelX->Text = L"上一页";
			// 
			// searchGroupJoinGroupButton
			// 
			this->searchGroupJoinGroupButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchGroupJoinGroupButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchGroupJoinGroupButton->Location = System::Drawing::Point(472, 473);
			this->searchGroupJoinGroupButton->Name = L"searchGroupJoinGroupButton";
			this->searchGroupJoinGroupButton->Size = System::Drawing::Size(75, 23);
			this->searchGroupJoinGroupButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchGroupJoinGroupButton->TabIndex = 14;
			this->searchGroupJoinGroupButton->Text = L"加入此群组";
			// 
			// searchGroupResultList
			// 
			// 
			// 
			// 
			this->searchGroupResultList->Border->Class = L"ListViewBorder";
			this->searchGroupResultList->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchGroupResultList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {this->columnHeader3, 
				this->columnHeader4, this->columnHeader8});
			this->searchGroupResultList->Location = System::Drawing::Point(36, 175);
			this->searchGroupResultList->Name = L"searchGroupResultList";
			this->searchGroupResultList->Size = System::Drawing::Size(520, 280);
			this->searchGroupResultList->TabIndex = 13;
			this->searchGroupResultList->UseCompatibleStateImageBehavior = false;
			this->searchGroupResultList->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"GroupID";
			this->columnHeader3->Width = 120;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"名称";
			this->columnHeader4->Width = 200;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"描述";
			this->columnHeader8->Width = 200;
			// 
			// labelX8
			// 
			this->labelX8->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX8->BackgroundStyle->Class = L"";
			this->labelX8->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->labelX8->Location = System::Drawing::Point(36, 145);
			this->labelX8->Name = L"labelX8";
			this->labelX8->Size = System::Drawing::Size(95, 23);
			this->labelX8->TabIndex = 12;
			this->labelX8->Text = L"查询结果：";
			// 
			// searchGroupSearchButton
			// 
			this->searchGroupSearchButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchGroupSearchButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchGroupSearchButton->Location = System::Drawing::Point(260, 98);
			this->searchGroupSearchButton->Name = L"searchGroupSearchButton";
			this->searchGroupSearchButton->Size = System::Drawing::Size(75, 25);
			this->searchGroupSearchButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchGroupSearchButton->TabIndex = 11;
			this->searchGroupSearchButton->Text = L"查  找";
			this->searchGroupSearchButton->Click += gcnew System::EventHandler(this, &GroupListTab::searchGroupSearchButton_Click);
			// 
			// searchGroupInputBox
			// 
			// 
			// 
			// 
			this->searchGroupInputBox->Border->Class = L"TextBoxBorder";
			this->searchGroupInputBox->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchGroupInputBox->Location = System::Drawing::Point(36, 98);
			this->searchGroupInputBox->Name = L"searchGroupInputBox";
			this->searchGroupInputBox->Size = System::Drawing::Size(203, 21);
			this->searchGroupInputBox->TabIndex = 10;
			// 
			// searchGroupKeywordRadioButton
			// 
			this->searchGroupKeywordRadioButton->AutoSize = true;
			this->searchGroupKeywordRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->searchGroupKeywordRadioButton->Location = System::Drawing::Point(36, 76);
			this->searchGroupKeywordRadioButton->Name = L"searchGroupKeywordRadioButton";
			this->searchGroupKeywordRadioButton->Size = System::Drawing::Size(197, 16);
			this->searchGroupKeywordRadioButton->TabIndex = 9;
			this->searchGroupKeywordRadioButton->Text = L"输入群组关键字（不少于2个字）";
			this->searchGroupKeywordRadioButton->UseVisualStyleBackColor = false;
			this->searchGroupKeywordRadioButton->Click += gcnew System::EventHandler(this, &GroupListTab::searchGroupKeywordRadioButton_Click);
			// 
			// searchGroupOuidRadioButton
			// 
			this->searchGroupOuidRadioButton->AutoSize = true;
			this->searchGroupOuidRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->searchGroupOuidRadioButton->Checked = true;
			this->searchGroupOuidRadioButton->Location = System::Drawing::Point(36, 53);
			this->searchGroupOuidRadioButton->Name = L"searchGroupOuidRadioButton";
			this->searchGroupOuidRadioButton->Size = System::Drawing::Size(95, 16);
			this->searchGroupOuidRadioButton->TabIndex = 8;
			this->searchGroupOuidRadioButton->TabStop = true;
			this->searchGroupOuidRadioButton->Text = L"输入群组OuID";
			this->searchGroupOuidRadioButton->UseVisualStyleBackColor = false;
			this->searchGroupOuidRadioButton->Click += gcnew System::EventHandler(this, &GroupListTab::searchGroupOuidRadioButton_Click);
			// 
			// labelX9
			// 
			this->labelX9->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX9->BackgroundStyle->Class = L"";
			this->labelX9->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX9->Location = System::Drawing::Point(36, 28);
			this->labelX9->Name = L"labelX9";
			this->labelX9->Size = System::Drawing::Size(80, 23);
			this->labelX9->TabIndex = 7;
			this->labelX9->Text = L"输入群组信息";
			// 
			// joinGroupTab
			// 
			this->joinGroupTab->AttachedControl = this->superTabControlPanel20;
			this->joinGroupTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->joinGroupTab->GlobalItem = false;
			this->joinGroupTab->Name = L"joinGroupTab";
			this->joinGroupTab->Text = L"加入群组";
			this->joinGroupTab->Click += gcnew System::EventHandler(this, &GroupListTab::joinGroupTab_Click);
			// 
			// groupListContextMenuStrip
			// 
			this->groupListContextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openGroupDlgToolStripMenuItem, 
				this->exitGroupToolStripMenuItem, this->deleteGroupToolStripMenuItem, this->createGroupToolStripMenuItem});
			this->groupListContextMenuStrip->Name = L"groupListContextMenuStrip";
			this->groupListContextMenuStrip->Size = System::Drawing::Size(159, 92);
			// 
			// openGroupDlgToolStripMenuItem
			// 
			this->openGroupDlgToolStripMenuItem->Name = L"openGroupDlgToolStripMenuItem";
			this->openGroupDlgToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->openGroupDlgToolStripMenuItem->Text = L"发送群组信息";
			// 
			// exitGroupToolStripMenuItem
			// 
			this->exitGroupToolStripMenuItem->Name = L"exitGroupToolStripMenuItem";
			this->exitGroupToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->exitGroupToolStripMenuItem->Text = L"退出群组";
			this->exitGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &GroupListTab::exitGroupToolStripMenuItem_Click);
			// 
			// deleteGroupToolStripMenuItem
			// 
			this->deleteGroupToolStripMenuItem->Name = L"deleteGroupToolStripMenuItem";
			this->deleteGroupToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->deleteGroupToolStripMenuItem->Text = L"解散此群组";
			this->deleteGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &GroupListTab::deleteGroupToolStripMenuItem_Click);
			// 
			// createGroupToolStripMenuItem
			// 
			this->createGroupToolStripMenuItem->Name = L"createGroupToolStripMenuItem";
			this->createGroupToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->createGroupToolStripMenuItem->Text = L"创建一个新群组";
			this->createGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &GroupListTab::createGroupToolStripMenuItem_Click);
			// 
			// GroupListTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->ControlBox = false;
			this->Controls->Add(this->superTabControl3);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GroupListTab";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"GroupListTab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl3))->EndInit();
			this->superTabControl3->ResumeLayout(false);
			this->superTabControlPanel18->ResumeLayout(false);
			this->panelEx3->ResumeLayout(false);
			this->groupSharingFilePanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groupShareFileListAdvTree))->EndInit();
			this->groupInformationPanel->ResumeLayout(false);
			this->groupInformationPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->myGroupListBar))->EndInit();
			this->superTabControlPanel26->ResumeLayout(false);
			this->superTabControlPanel26->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->createGroupTabMemberListAdvTree))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->createGroupTabContactListAdvTree))->EndInit();
			this->superTabControlPanel20->ResumeLayout(false);
			this->superTabControlPanel20->PerformLayout();
			this->groupListContextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void searchGroupSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
	public: System::Void GroupListTab::InitializeSearchGroupSearchResult(void);
private: System::Void groupList_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	public:System::Void GroupListTab::InitializeCreateGroupTab();
private: System::Void createGroupSuperTabItem_Click(System::Object^  sender, System::EventArgs^  e) ;
	public:System::Void GroupListTab::joinGroupTab_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void GroupListTab::searchGroupOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void GroupListTab::searchGroupKeywordRadioButton_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void GroupListTab::OpenGroupChatDlg(Object^ sender, EventArgs^ e);
			System::Void GroupListTab::createGroupTabGroupTagTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e);
			System::Void GroupListTab::createGroupTabSearchContactTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::createGroupTabSearchContactTextBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::UpdateCreateGroupTabContactList(void);
		System::Void GroupListTab::createGroupTabAddMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::createGroupTabRemoveMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::createGroupTabCreateGroupButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::createGroupTabEnableControls(bool flag);
		System::Void GroupListTab::exitGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		OusnsGroup^ GroupListTab::FindSelectedGroup(void);
		System::Void GroupListTab::createGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void GroupListTab::GroupButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void GroupListTab::myGroupListTabRefreshButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
		System::Void GroupListTab::deleteGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) ;

		 /* 
		 *  This function will be called when there is a response for the request that the login user is querying one of his joined group information, like the group announcement.
		 * This function will take ONLY 1 param 
		 * ousnsGroup, the type is OusnsGroup. This function will dynamically cast the first element in the param to OusnsGroup type and display this group information in the UI.
		 */
		 System::Void DisplayGroupInfo(LinkedList<Object^>^ params);
		 /*
		 * This function will update the groups that user joined to the UI
		 */
		 System::Void GroupListTab::UpdateGroupListToUI();
		 /*
		 * This function will be called when there is a response for the request that search specific group
		 * This function will dynamic cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
		 * Each Object represent a search result entry. 
		 */
		 System::Void GroupListTab::DisplaySearchGroupResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults);


};
}
