


namespace OuSns {

	ref class MainDlg;
	/// <summary>
	/// FriendListTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class SearchResult;
	ref class friendChatDlg;
	ref class OusnsLoginUser;
	public ref class FriendListTab : public System::Windows::Forms::Form
	{
		/* Commons for all tabs*/
	public:
		MainDlg^ mainDlg;
		Communication^ comm;
		OusnsLoginUser^ loginUser;
		delegate System::Void NewMessageDelegate(ChatMessage ^ msg);
		delegate System::Void UpdateInfoDelegate(unsigned int srcID);
		delegate System::Void ActionDelegate();
		delegate System::Void ParamActionDelegate(LinkedList<Object^>^ params);
		delegate System::Void SearchActionDelegate(int totalResult, int offset, LinkedList<SearchResult^>^ searchResult);
	public:
		FriendListTab(MainDlg^ mainDlgInput, Communication^ commInput,OusnsLoginUser^ loginUserInput);
		Dictionary<unsigned int, OuSns::friendChatDlg ^> ^ friend_chat_dlg_list; // Indexed by the userID of the friend.
		Dictionary <OusnsFriend ^, LinkedList<ChatMessage^>^ > ^ msgs_by_user; // Stores msgs from different sources(users).
		Dictionary <OusnsFriend ^, unsigned int> ^ pending_counts_by_user;
		Dictionary <OusnsFriend ^, LinkedList<DirectTransferFile ^> ^> ^ transferFilesByUser;
		//MainDlg^ mainDlg;
	private: System::Windows::Forms::ContextMenuStrip^  friendListContextMenuStrip;
	public: 
	private: System::Windows::Forms::ToolStripMenuItem^  openFriendDlgToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeFriendToolStripMenuItem;
			 int searchFriendOffSet;
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~FriendListTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl2;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel17;
	private: DevComponents::DotNetBar::PanelEx^  panelEx2;
	private: DevComponents::DotNetBar::ExpandablePanel^  sharingFileListPanel;
	private: DevComponents::AdvTree::AdvTree^  friendShareFileListAdvTree;
	private: DevComponents::AdvTree::ColumnHeader^  friendFileNameColumnHeader;
	private: DevComponents::AdvTree::ColumnHeader^  friendFileSizeColumnHeader;
	private: DevComponents::AdvTree::ColumnHeader^  friendFileDescriptionColumnHeader;
	private: DevComponents::AdvTree::Node^  node1;
	private: DevComponents::AdvTree::Node^  node2;
	private: DevComponents::AdvTree::Cell^  cell3;
	private: DevComponents::AdvTree::Cell^  cell4;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector1;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle1;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter4;
	private: DevComponents::DotNetBar::ExpandablePanel^  personalInformationPanel;
	private: DevComponents::DotNetBar::ButtonX^  myFriendListTabRefreshButtonX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabEmailLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabEmailTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabCityLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabCityTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabProvinceLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabProvinceTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabCountryLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabCountryTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabZodiacLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabZodiacTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabBirthdayLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabBirthdayTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabAgeLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabSexLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabAgeTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabSexTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabPersonalInformationTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabFriendSignatureLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabFriendSignatureTitleLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabFriendOuIDLabelX;
	private: DevComponents::DotNetBar::LabelX^  myFriendListTabFriendNicknameLabelX;
	private: DevComponents::DotNetBar::ExpandableSplitter^  expandableSplitter3;
	private: DevComponents::DotNetBar::SideBar^  friendList;
	public: DevComponents::DotNetBar::SideBarPanelItem^  myFriendListSideBarPanelItem;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem12;
	private: DevComponents::DotNetBar::Bar^  myFriendListBar;
	private: DevComponents::DotNetBar::ButtonItem^  createFriendGroupButton;
	private: DevComponents::DotNetBar::ButtonItem^  renameFriendGroupButton;
	private: DevComponents::DotNetBar::ButtonItem^  deleteFriendGroupButton;
	private: DevComponents::DotNetBar::ButtonItem^  displayOnlineFriendOnlyButton;
	public: DevComponents::DotNetBar::SuperTabItem^  myFriendListTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel16;
	private: DevComponents::DotNetBar::LabelX^  searchFriendNextPageLabelX;
	private: DevComponents::DotNetBar::LabelX^  searchFriendPreviousPageLabelX;
	private: System::Windows::Forms::RadioButton^  searchFriendNicknameRadioButton;
	private: DevComponents::DotNetBar::ButtonX^  searchFriendAddFriendButton;
	private: DevComponents::DotNetBar::Controls::ListViewEx^  searchFriendResultList;
	private: System::Windows::Forms::ColumnHeader^  searchFriendIDColumn;
	private: System::Windows::Forms::ColumnHeader^  searchFriendInfoColumn;
	private: DevComponents::DotNetBar::LabelX^  labelX5;
	private: DevComponents::DotNetBar::ButtonX^  searchFriendSearchButton;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  searchFriendInputBox;
	private: System::Windows::Forms::RadioButton^  searchFriendEmailRadioButton;
	private: System::Windows::Forms::RadioButton^  searchFriendOuidRadioButton;
	private: DevComponents::DotNetBar::LabelX^  labelX4;
	private: DevComponents::DotNetBar::SuperTabItem^  addFriendTab;
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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {L"tester1", 
				L"tester2", L"tester3333"}, -1));
			this->superTabControl2 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel16 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->searchFriendNextPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFriendPreviousPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFriendNicknameRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->searchFriendAddFriendButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchFriendResultList = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->searchFriendIDColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->searchFriendInfoColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelX5 = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFriendSearchButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->searchFriendInputBox = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->searchFriendEmailRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->searchFriendOuidRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
			this->addFriendTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel17 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->panelEx2 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->sharingFileListPanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->friendShareFileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->friendFileNameColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->friendFileSizeColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->friendFileDescriptionColumnHeader = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node1 = (gcnew DevComponents::AdvTree::Node());
			this->node2 = (gcnew DevComponents::AdvTree::Node());
			this->cell3 = (gcnew DevComponents::AdvTree::Cell());
			this->cell4 = (gcnew DevComponents::AdvTree::Cell());
			this->nodeConnector1 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle1 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->expandableSplitter4 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->personalInformationPanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->myFriendListTabRefreshButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->myFriendListTabEmailLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabEmailTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabCityLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabCityTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabProvinceLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabProvinceTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabCountryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabCountryTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabZodiacLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabZodiacTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabBirthdayLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabBirthdayTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabAgeLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabSexLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabAgeTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabSexTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabPersonalInformationTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabFriendSignatureLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabFriendSignatureTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabFriendOuIDLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->myFriendListTabFriendNicknameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->expandableSplitter3 = (gcnew DevComponents::DotNetBar::ExpandableSplitter());
			this->friendList = (gcnew DevComponents::DotNetBar::SideBar());
			this->myFriendListSideBarPanelItem = (gcnew DevComponents::DotNetBar::SideBarPanelItem());
			this->buttonItem12 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->myFriendListBar = (gcnew DevComponents::DotNetBar::Bar());
			this->createFriendGroupButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->renameFriendGroupButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->deleteFriendGroupButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->displayOnlineFriendOnlyButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->myFriendListTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->friendListContextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->openFriendDlgToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeFriendToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl2))->BeginInit();
			this->superTabControl2->SuspendLayout();
			this->superTabControlPanel16->SuspendLayout();
			this->superTabControlPanel17->SuspendLayout();
			this->panelEx2->SuspendLayout();
			this->sharingFileListPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->friendShareFileListAdvTree))->BeginInit();
			this->personalInformationPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->myFriendListBar))->BeginInit();
			this->friendListContextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// superTabControl2
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl2->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl2->ControlBox->MenuBox->Name = L"";
			this->superTabControl2->ControlBox->MenuBox->Visible = false;
			this->superTabControl2->ControlBox->Name = L"";
			this->superTabControl2->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl2->ControlBox->MenuBox, 
				this->superTabControl2->ControlBox->CloseBox});
			this->superTabControl2->Controls->Add(this->superTabControlPanel16);
			this->superTabControl2->Controls->Add(this->superTabControlPanel17);
			this->superTabControl2->Cursor = System::Windows::Forms::Cursors::Default;
			this->superTabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl2->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl2->Location = System::Drawing::Point(0, 0);
			this->superTabControl2->Name = L"superTabControl2";
			this->superTabControl2->ReorderTabsEnabled = true;
			this->superTabControl2->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl2->SelectedTabIndex = 0;
			this->superTabControl2->Size = System::Drawing::Size(593, 573);
			this->superTabControl2->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl2->TabIndex = 2;
			this->superTabControl2->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->myFriendListTab, 
				this->addFriendTab});
			this->superTabControl2->Text = L"superTabControl2";
			this->superTabControl2->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel16
			// 
			this->superTabControlPanel16->Controls->Add(this->searchFriendNextPageLabelX);
			this->superTabControlPanel16->Controls->Add(this->searchFriendPreviousPageLabelX);
			this->superTabControlPanel16->Controls->Add(this->searchFriendNicknameRadioButton);
			this->superTabControlPanel16->Controls->Add(this->searchFriendAddFriendButton);
			this->superTabControlPanel16->Controls->Add(this->searchFriendResultList);
			this->superTabControlPanel16->Controls->Add(this->labelX5);
			this->superTabControlPanel16->Controls->Add(this->searchFriendSearchButton);
			this->superTabControlPanel16->Controls->Add(this->searchFriendInputBox);
			this->superTabControlPanel16->Controls->Add(this->searchFriendEmailRadioButton);
			this->superTabControlPanel16->Controls->Add(this->searchFriendOuidRadioButton);
			this->superTabControlPanel16->Controls->Add(this->labelX4);
			this->superTabControlPanel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel16->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel16->Name = L"superTabControlPanel16";
			this->superTabControlPanel16->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel16->TabIndex = 0;
			this->superTabControlPanel16->TabItem = this->addFriendTab;
			// 
			// searchFriendNextPageLabelX
			// 
			this->searchFriendNextPageLabelX->AutoSize = true;
			this->searchFriendNextPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFriendNextPageLabelX->BackgroundStyle->Class = L"";
			this->searchFriendNextPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendNextPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchFriendNextPageLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->searchFriendNextPageLabelX->Location = System::Drawing::Point(88, 469);
			this->searchFriendNextPageLabelX->Name = L"searchFriendNextPageLabelX";
			this->searchFriendNextPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchFriendNextPageLabelX->TabIndex = 10;
			this->searchFriendNextPageLabelX->Text = L"下一页";
			// 
			// searchFriendPreviousPageLabelX
			// 
			this->searchFriendPreviousPageLabelX->AutoSize = true;
			this->searchFriendPreviousPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFriendPreviousPageLabelX->BackgroundStyle->Class = L"";
			this->searchFriendPreviousPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendPreviousPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchFriendPreviousPageLabelX->ForeColor = System::Drawing::Color::Gray;
			this->searchFriendPreviousPageLabelX->Location = System::Drawing::Point(36, 469);
			this->searchFriendPreviousPageLabelX->Name = L"searchFriendPreviousPageLabelX";
			this->searchFriendPreviousPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchFriendPreviousPageLabelX->TabIndex = 9;
			this->searchFriendPreviousPageLabelX->Text = L"上一页";
			// 
			// searchFriendNicknameRadioButton
			// 
			this->searchFriendNicknameRadioButton->AutoSize = true;
			this->searchFriendNicknameRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->searchFriendNicknameRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searchFriendNicknameRadioButton->Location = System::Drawing::Point(38, 100);
			this->searchFriendNicknameRadioButton->Name = L"searchFriendNicknameRadioButton";
			this->searchFriendNicknameRadioButton->Size = System::Drawing::Size(107, 16);
			this->searchFriendNicknameRadioButton->TabIndex = 8;
			this->searchFriendNicknameRadioButton->Text = L"输入对方的昵称";
			this->searchFriendNicknameRadioButton->UseVisualStyleBackColor = false;
			// 
			// searchFriendAddFriendButton
			// 
			this->searchFriendAddFriendButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFriendAddFriendButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFriendAddFriendButton->Location = System::Drawing::Point(460, 479);
			this->searchFriendAddFriendButton->Name = L"searchFriendAddFriendButton";
			this->searchFriendAddFriendButton->Size = System::Drawing::Size(75, 23);
			this->searchFriendAddFriendButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFriendAddFriendButton->TabIndex = 7;
			this->searchFriendAddFriendButton->Text = L"添加为好友";
			// 
			// searchFriendResultList
			// 
			// 
			// 
			// 
			this->searchFriendResultList->Border->Class = L"ListViewBorder";
			this->searchFriendResultList->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendResultList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->searchFriendIDColumn, 
				this->searchFriendInfoColumn});
			this->searchFriendResultList->FullRowSelect = true;
			this->searchFriendResultList->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) {listViewItem1});
			this->searchFriendResultList->Location = System::Drawing::Point(37, 182);
			this->searchFriendResultList->MultiSelect = false;
			this->searchFriendResultList->Name = L"searchFriendResultList";
			this->searchFriendResultList->Size = System::Drawing::Size(520, 280);
			this->searchFriendResultList->TabIndex = 6;
			this->searchFriendResultList->UseCompatibleStateImageBehavior = false;
			this->searchFriendResultList->View = System::Windows::Forms::View::Details;
			// 
			// searchFriendIDColumn
			// 
			this->searchFriendIDColumn->Text = L"OuID";
			this->searchFriendIDColumn->Width = 120;
			// 
			// searchFriendInfoColumn
			// 
			this->searchFriendInfoColumn->Text = L"昵称";
			this->searchFriendInfoColumn->Width = 400;
			// 
			// labelX5
			// 
			this->labelX5->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX5->BackgroundStyle->Class = L"";
			this->labelX5->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->labelX5->Location = System::Drawing::Point(36, 158);
			this->labelX5->Name = L"labelX5";
			this->labelX5->Size = System::Drawing::Size(95, 23);
			this->labelX5->TabIndex = 5;
			this->labelX5->Text = L"查询结果：";
			// 
			// searchFriendSearchButton
			// 
			this->searchFriendSearchButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFriendSearchButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFriendSearchButton->Location = System::Drawing::Point(261, 129);
			this->searchFriendSearchButton->Name = L"searchFriendSearchButton";
			this->searchFriendSearchButton->Size = System::Drawing::Size(75, 25);
			this->searchFriendSearchButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFriendSearchButton->TabIndex = 4;
			this->searchFriendSearchButton->Text = L"查  找";
			// 
			// searchFriendInputBox
			// 
			// 
			// 
			// 
			this->searchFriendInputBox->Border->Class = L"TextBoxBorder";
			this->searchFriendInputBox->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendInputBox->Location = System::Drawing::Point(37, 129);
			this->searchFriendInputBox->Name = L"searchFriendInputBox";
			this->searchFriendInputBox->Size = System::Drawing::Size(203, 21);
			this->searchFriendInputBox->TabIndex = 3;
			// 
			// searchFriendEmailRadioButton
			// 
			this->searchFriendEmailRadioButton->AutoSize = true;
			this->searchFriendEmailRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->searchFriendEmailRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searchFriendEmailRadioButton->Location = System::Drawing::Point(37, 76);
			this->searchFriendEmailRadioButton->Name = L"searchFriendEmailRadioButton";
			this->searchFriendEmailRadioButton->Size = System::Drawing::Size(107, 16);
			this->searchFriendEmailRadioButton->TabIndex = 2;
			this->searchFriendEmailRadioButton->Text = L"输入对方E-MAIL";
			this->searchFriendEmailRadioButton->UseVisualStyleBackColor = false;
			// 
			// searchFriendOuidRadioButton
			// 
			this->searchFriendOuidRadioButton->AutoSize = true;
			this->searchFriendOuidRadioButton->BackColor = System::Drawing::Color::Transparent;
			this->searchFriendOuidRadioButton->Checked = true;
			this->searchFriendOuidRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searchFriendOuidRadioButton->Location = System::Drawing::Point(37, 53);
			this->searchFriendOuidRadioButton->Name = L"searchFriendOuidRadioButton";
			this->searchFriendOuidRadioButton->Size = System::Drawing::Size(95, 16);
			this->searchFriendOuidRadioButton->TabIndex = 1;
			this->searchFriendOuidRadioButton->TabStop = true;
			this->searchFriendOuidRadioButton->Text = L"输入对方OuID";
			this->searchFriendOuidRadioButton->UseVisualStyleBackColor = false;
			// 
			// labelX4
			// 
			this->labelX4->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX4->BackgroundStyle->Class = L"";
			this->labelX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX4->Location = System::Drawing::Point(37, 28);
			this->labelX4->Name = L"labelX4";
			this->labelX4->Size = System::Drawing::Size(80, 23);
			this->labelX4->TabIndex = 0;
			this->labelX4->Text = L"输入对方帐号";
			// 
			// addFriendTab
			// 
			this->addFriendTab->AttachedControl = this->superTabControlPanel16;
			this->addFriendTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addFriendTab->GlobalItem = false;
			this->addFriendTab->Name = L"addFriendTab";
			this->addFriendTab->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addFriendTab->TabFont = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->addFriendTab->Text = L"添加好友";
			// 
			// superTabControlPanel17
			// 
			this->superTabControlPanel17->Controls->Add(this->panelEx2);
			this->superTabControlPanel17->Controls->Add(this->expandableSplitter3);
			this->superTabControlPanel17->Controls->Add(this->friendList);
			this->superTabControlPanel17->Controls->Add(this->myFriendListBar);
			this->superTabControlPanel17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel17->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel17->Name = L"superTabControlPanel17";
			this->superTabControlPanel17->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel17->TabIndex = 1;
			this->superTabControlPanel17->TabItem = this->myFriendListTab;
			// 
			// panelEx2
			// 
			this->panelEx2->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx2->Controls->Add(this->sharingFileListPanel);
			this->panelEx2->Controls->Add(this->expandableSplitter4);
			this->panelEx2->Controls->Add(this->personalInformationPanel);
			this->panelEx2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx2->Location = System::Drawing::Point(121, 25);
			this->panelEx2->Name = L"panelEx2";
			this->panelEx2->Size = System::Drawing::Size(472, 506);
			this->panelEx2->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx2->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx2->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx2->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx2->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx2->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx2->Style->GradientAngle = 90;
			this->panelEx2->TabIndex = 6;
			// 
			// sharingFileListPanel
			// 
			this->sharingFileListPanel->CanvasColor = System::Drawing::SystemColors::Control;
			this->sharingFileListPanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->sharingFileListPanel->Controls->Add(this->friendShareFileListAdvTree);
			this->sharingFileListPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sharingFileListPanel->ExpandButtonVisible = false;
			this->sharingFileListPanel->Location = System::Drawing::Point(0, 235);
			this->sharingFileListPanel->Name = L"sharingFileListPanel";
			this->sharingFileListPanel->Size = System::Drawing::Size(472, 271);
			this->sharingFileListPanel->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->sharingFileListPanel->Style->BackColor1->Color = System::Drawing::Color::White;
			this->sharingFileListPanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->sharingFileListPanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->sharingFileListPanel->Style->GradientAngle = 90;
			this->sharingFileListPanel->TabIndex = 2;
			this->sharingFileListPanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->sharingFileListPanel->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->sharingFileListPanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->sharingFileListPanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->sharingFileListPanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->sharingFileListPanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->sharingFileListPanel->TitleStyle->GradientAngle = 90;
			this->sharingFileListPanel->TitleText = L"朋友共享的文件";
			// 
			// friendShareFileListAdvTree
			// 
			this->friendShareFileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->friendShareFileListAdvTree->AllowDrop = true;
			this->friendShareFileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->friendShareFileListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->friendShareFileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->friendShareFileListAdvTree->Columns->Add(this->friendFileNameColumnHeader);
			this->friendShareFileListAdvTree->Columns->Add(this->friendFileSizeColumnHeader);
			this->friendShareFileListAdvTree->Columns->Add(this->friendFileDescriptionColumnHeader);
			this->friendShareFileListAdvTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->friendShareFileListAdvTree->HotTracking = true;
			this->friendShareFileListAdvTree->Location = System::Drawing::Point(0, 26);
			this->friendShareFileListAdvTree->Name = L"friendShareFileListAdvTree";
			this->friendShareFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
			this->friendShareFileListAdvTree->NodesConnector = this->nodeConnector1;
			this->friendShareFileListAdvTree->NodeStyle = this->elementStyle1;
			this->friendShareFileListAdvTree->PathSeparator = L";";
			this->friendShareFileListAdvTree->SelectionBoxStyle = DevComponents::AdvTree::eSelectionStyle::FullRowSelect;
			this->friendShareFileListAdvTree->Size = System::Drawing::Size(472, 245);
			this->friendShareFileListAdvTree->Styles->Add(this->elementStyle1);
			this->friendShareFileListAdvTree->TabIndex = 1;
			this->friendShareFileListAdvTree->Text = L"advTree1";
			// 
			// friendFileNameColumnHeader
			// 
			this->friendFileNameColumnHeader->DisplayIndex = 1;
			this->friendFileNameColumnHeader->Name = L"friendFileNameColumnHeader";
			this->friendFileNameColumnHeader->Text = L"文件名称";
			this->friendFileNameColumnHeader->Width->Absolute = 150;
			// 
			// friendFileSizeColumnHeader
			// 
			this->friendFileSizeColumnHeader->DisplayIndex = 2;
			this->friendFileSizeColumnHeader->Name = L"friendFileSizeColumnHeader";
			this->friendFileSizeColumnHeader->Text = L"文件大小";
			this->friendFileSizeColumnHeader->Width->Absolute = 150;
			// 
			// friendFileDescriptionColumnHeader
			// 
			this->friendFileDescriptionColumnHeader->DisplayIndex = 3;
			this->friendFileDescriptionColumnHeader->Name = L"friendFileDescriptionColumnHeader";
			this->friendFileDescriptionColumnHeader->Text = L"文件描述";
			this->friendFileDescriptionColumnHeader->Width->Absolute = 150;
			// 
			// node1
			// 
			this->node1->Expanded = true;
			this->node1->Name = L"node1";
			this->node1->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node2});
			this->node1->Text = L"文件名1";
			// 
			// node2
			// 
			this->node2->Cells->Add(this->cell3);
			this->node2->Cells->Add(this->cell4);
			this->node2->Name = L"node2";
			this->node2->Text = L"文件名2";
			// 
			// cell3
			// 
			this->cell3->Name = L"cell3";
			this->cell3->StyleMouseOver = nullptr;
			this->cell3->Text = L"文件大小2";
			// 
			// cell4
			// 
			this->cell4->Name = L"cell4";
			this->cell4->StyleMouseOver = nullptr;
			this->cell4->Text = L"文件描述2";
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
			// expandableSplitter4
			// 
			this->expandableSplitter4->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter4->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter4->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter4->Dock = System::Windows::Forms::DockStyle::Top;
			this->expandableSplitter4->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter4->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter4->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter4->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter4->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter4->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter4->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter4->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter4->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter4->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter4->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter4->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter4->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter4->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter4->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter4->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter4->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter4->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter4->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter4->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter4->Location = System::Drawing::Point(0, 230);
			this->expandableSplitter4->Name = L"expandableSplitter4";
			this->expandableSplitter4->Size = System::Drawing::Size(472, 5);
			this->expandableSplitter4->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter4->TabIndex = 1;
			this->expandableSplitter4->TabStop = false;
			// 
			// personalInformationPanel
			// 
			this->personalInformationPanel->CanvasColor = System::Drawing::SystemColors::Control;
			this->personalInformationPanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->personalInformationPanel->Controls->Add(this->myFriendListTabRefreshButtonX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabEmailLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabEmailTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabCityLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabCityTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabProvinceLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabProvinceTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabCountryLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabCountryTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabZodiacLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabZodiacTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabBirthdayLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabBirthdayTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabAgeLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabSexLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabAgeTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabSexTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabPersonalInformationTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabFriendSignatureLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabFriendSignatureTitleLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabFriendOuIDLabelX);
			this->personalInformationPanel->Controls->Add(this->myFriendListTabFriendNicknameLabelX);
			this->personalInformationPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->personalInformationPanel->ExpandButtonVisible = false;
			this->personalInformationPanel->Location = System::Drawing::Point(0, 0);
			this->personalInformationPanel->MinimumSize = System::Drawing::Size(472, 0);
			this->personalInformationPanel->Name = L"personalInformationPanel";
			this->personalInformationPanel->Size = System::Drawing::Size(472, 230);
			this->personalInformationPanel->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->personalInformationPanel->Style->BackColor1->Color = System::Drawing::Color::White;
			this->personalInformationPanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->personalInformationPanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->personalInformationPanel->Style->GradientAngle = 90;
			this->personalInformationPanel->TabIndex = 0;
			this->personalInformationPanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->personalInformationPanel->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->personalInformationPanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->personalInformationPanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->personalInformationPanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->personalInformationPanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->personalInformationPanel->TitleStyle->GradientAngle = 90;
			this->personalInformationPanel->TitleText = L"个人资料";
			// 
			// myFriendListTabRefreshButtonX
			// 
			this->myFriendListTabRefreshButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->myFriendListTabRefreshButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->myFriendListTabRefreshButtonX->Location = System::Drawing::Point(385, 6);
			this->myFriendListTabRefreshButtonX->Name = L"myFriendListTabRefreshButtonX";
			this->myFriendListTabRefreshButtonX->Size = System::Drawing::Size(75, 16);
			this->myFriendListTabRefreshButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->myFriendListTabRefreshButtonX->TabIndex = 22;
			this->myFriendListTabRefreshButtonX->Text = L"刷新";
			// 
			// myFriendListTabEmailLabelX
			// 
			this->myFriendListTabEmailLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabEmailLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabEmailLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabEmailLabelX->Location = System::Drawing::Point(211, 149);
			this->myFriendListTabEmailLabelX->Name = L"myFriendListTabEmailLabelX";
			this->myFriendListTabEmailLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabEmailLabelX->TabIndex = 21;
			this->myFriendListTabEmailLabelX->Text = L"-";
			// 
			// myFriendListTabEmailTitleLabelX
			// 
			this->myFriendListTabEmailTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabEmailTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabEmailTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabEmailTitleLabelX->Location = System::Drawing::Point(161, 149);
			this->myFriendListTabEmailTitleLabelX->Name = L"myFriendListTabEmailTitleLabelX";
			this->myFriendListTabEmailTitleLabelX->Size = System::Drawing::Size(50, 18);
			this->myFriendListTabEmailTitleLabelX->TabIndex = 20;
			this->myFriendListTabEmailTitleLabelX->Text = L"Email：";
			// 
			// myFriendListTabCityLabelX
			// 
			this->myFriendListTabCityLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabCityLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabCityLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabCityLabelX->Location = System::Drawing::Point(405, 168);
			this->myFriendListTabCityLabelX->Name = L"myFriendListTabCityLabelX";
			this->myFriendListTabCityLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabCityLabelX->TabIndex = 19;
			this->myFriendListTabCityLabelX->Text = L"-";
			// 
			// myFriendListTabCityTitleLabelX
			// 
			this->myFriendListTabCityTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabCityTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabCityTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabCityTitleLabelX->Location = System::Drawing::Point(335, 168);
			this->myFriendListTabCityTitleLabelX->Name = L"myFriendListTabCityTitleLabelX";
			this->myFriendListTabCityTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabCityTitleLabelX->TabIndex = 18;
			this->myFriendListTabCityTitleLabelX->Text = L"城    市：";
			// 
			// myFriendListTabProvinceLabelX
			// 
			this->myFriendListTabProvinceLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabProvinceLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabProvinceLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabProvinceLabelX->Location = System::Drawing::Point(237, 168);
			this->myFriendListTabProvinceLabelX->Name = L"myFriendListTabProvinceLabelX";
			this->myFriendListTabProvinceLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabProvinceLabelX->TabIndex = 17;
			this->myFriendListTabProvinceLabelX->Text = L"-";
			// 
			// myFriendListTabProvinceTitleLabelX
			// 
			this->myFriendListTabProvinceTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabProvinceTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabProvinceTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabProvinceTitleLabelX->Location = System::Drawing::Point(161, 168);
			this->myFriendListTabProvinceTitleLabelX->Name = L"myFriendListTabProvinceTitleLabelX";
			this->myFriendListTabProvinceTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabProvinceTitleLabelX->TabIndex = 16;
			this->myFriendListTabProvinceTitleLabelX->Text = L"省    份：";
			// 
			// myFriendListTabCountryLabelX
			// 
			this->myFriendListTabCountryLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabCountryLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabCountryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabCountryLabelX->Location = System::Drawing::Point(93, 168);
			this->myFriendListTabCountryLabelX->Name = L"myFriendListTabCountryLabelX";
			this->myFriendListTabCountryLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabCountryLabelX->TabIndex = 15;
			this->myFriendListTabCountryLabelX->Text = L"-";
			// 
			// myFriendListTabCountryTitleLabelX
			// 
			this->myFriendListTabCountryTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabCountryTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabCountryTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabCountryTitleLabelX->Location = System::Drawing::Point(20, 168);
			this->myFriendListTabCountryTitleLabelX->Name = L"myFriendListTabCountryTitleLabelX";
			this->myFriendListTabCountryTitleLabelX->Size = System::Drawing::Size(74, 18);
			this->myFriendListTabCountryTitleLabelX->TabIndex = 14;
			this->myFriendListTabCountryTitleLabelX->Text = L"国家/地区：";
			// 
			// myFriendListTabZodiacLabelX
			// 
			this->myFriendListTabZodiacLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabZodiacLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabZodiacLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabZodiacLabelX->Location = System::Drawing::Point(93, 149);
			this->myFriendListTabZodiacLabelX->Name = L"myFriendListTabZodiacLabelX";
			this->myFriendListTabZodiacLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabZodiacLabelX->TabIndex = 13;
			this->myFriendListTabZodiacLabelX->Text = L"-";
			// 
			// myFriendListTabZodiacTitleLabelX
			// 
			this->myFriendListTabZodiacTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabZodiacTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabZodiacTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabZodiacTitleLabelX->Location = System::Drawing::Point(20, 149);
			this->myFriendListTabZodiacTitleLabelX->Name = L"myFriendListTabZodiacTitleLabelX";
			this->myFriendListTabZodiacTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabZodiacTitleLabelX->TabIndex = 12;
			this->myFriendListTabZodiacTitleLabelX->Text = L"星    座：";
			// 
			// myFriendListTabBirthdayLabelX
			// 
			this->myFriendListTabBirthdayLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabBirthdayLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabBirthdayLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabBirthdayLabelX->Location = System::Drawing::Point(237, 131);
			this->myFriendListTabBirthdayLabelX->Name = L"myFriendListTabBirthdayLabelX";
			this->myFriendListTabBirthdayLabelX->Size = System::Drawing::Size(44, 18);
			this->myFriendListTabBirthdayLabelX->TabIndex = 11;
			this->myFriendListTabBirthdayLabelX->Text = L"-月-日";
			// 
			// myFriendListTabBirthdayTitleLabelX
			// 
			this->myFriendListTabBirthdayTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabBirthdayTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabBirthdayTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabBirthdayTitleLabelX->Location = System::Drawing::Point(161, 129);
			this->myFriendListTabBirthdayTitleLabelX->Name = L"myFriendListTabBirthdayTitleLabelX";
			this->myFriendListTabBirthdayTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabBirthdayTitleLabelX->TabIndex = 10;
			this->myFriendListTabBirthdayTitleLabelX->Text = L"生    日：";
			// 
			// myFriendListTabAgeLabelX
			// 
			this->myFriendListTabAgeLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabAgeLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabAgeLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabAgeLabelX->Location = System::Drawing::Point(405, 132);
			this->myFriendListTabAgeLabelX->Name = L"myFriendListTabAgeLabelX";
			this->myFriendListTabAgeLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabAgeLabelX->TabIndex = 9;
			this->myFriendListTabAgeLabelX->Text = L"1";
			// 
			// myFriendListTabSexLabelX
			// 
			this->myFriendListTabSexLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabSexLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabSexLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabSexLabelX->Location = System::Drawing::Point(93, 130);
			this->myFriendListTabSexLabelX->Name = L"myFriendListTabSexLabelX";
			this->myFriendListTabSexLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabSexLabelX->TabIndex = 8;
			this->myFriendListTabSexLabelX->Text = L"-";
			// 
			// myFriendListTabAgeTitleLabelX
			// 
			this->myFriendListTabAgeTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabAgeTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabAgeTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabAgeTitleLabelX->Location = System::Drawing::Point(335, 129);
			this->myFriendListTabAgeTitleLabelX->Name = L"myFriendListTabAgeTitleLabelX";
			this->myFriendListTabAgeTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabAgeTitleLabelX->TabIndex = 7;
			this->myFriendListTabAgeTitleLabelX->Text = L"年    龄：";
			// 
			// myFriendListTabSexTitleLabelX
			// 
			this->myFriendListTabSexTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabSexTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabSexTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabSexTitleLabelX->Location = System::Drawing::Point(20, 129);
			this->myFriendListTabSexTitleLabelX->Name = L"myFriendListTabSexTitleLabelX";
			this->myFriendListTabSexTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->myFriendListTabSexTitleLabelX->TabIndex = 6;
			this->myFriendListTabSexTitleLabelX->Text = L"性    别：";
			// 
			// myFriendListTabPersonalInformationTitleLabelX
			// 
			// 
			// 
			// 
			this->myFriendListTabPersonalInformationTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabPersonalInformationTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabPersonalInformationTitleLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->myFriendListTabPersonalInformationTitleLabelX->Location = System::Drawing::Point(20, 99);
			this->myFriendListTabPersonalInformationTitleLabelX->Name = L"myFriendListTabPersonalInformationTitleLabelX";
			this->myFriendListTabPersonalInformationTitleLabelX->Size = System::Drawing::Size(75, 23);
			this->myFriendListTabPersonalInformationTitleLabelX->TabIndex = 5;
			this->myFriendListTabPersonalInformationTitleLabelX->Text = L"基本资料：";
			// 
			// myFriendListTabFriendSignatureLabelX
			// 
			this->myFriendListTabFriendSignatureLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabFriendSignatureLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabFriendSignatureLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabFriendSignatureLabelX->Location = System::Drawing::Point(96, 69);
			this->myFriendListTabFriendSignatureLabelX->Name = L"myFriendListTabFriendSignatureLabelX";
			this->myFriendListTabFriendSignatureLabelX->Size = System::Drawing::Size(99, 16);
			this->myFriendListTabFriendSignatureLabelX->TabIndex = 4;
			this->myFriendListTabFriendSignatureLabelX->Text = L"friendSignature";
			// 
			// myFriendListTabFriendSignatureTitleLabelX
			// 
			// 
			// 
			// 
			this->myFriendListTabFriendSignatureTitleLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabFriendSignatureTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabFriendSignatureTitleLabelX->Location = System::Drawing::Point(20, 69);
			this->myFriendListTabFriendSignatureTitleLabelX->Name = L"myFriendListTabFriendSignatureTitleLabelX";
			this->myFriendListTabFriendSignatureTitleLabelX->Size = System::Drawing::Size(69, 23);
			this->myFriendListTabFriendSignatureTitleLabelX->TabIndex = 3;
			this->myFriendListTabFriendSignatureTitleLabelX->Text = L"个性签名：";
			// 
			// myFriendListTabFriendOuIDLabelX
			// 
			this->myFriendListTabFriendOuIDLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabFriendOuIDLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabFriendOuIDLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabFriendOuIDLabelX->Location = System::Drawing::Point(124, 40);
			this->myFriendListTabFriendOuIDLabelX->Name = L"myFriendListTabFriendOuIDLabelX";
			this->myFriendListTabFriendOuIDLabelX->Size = System::Drawing::Size(31, 16);
			this->myFriendListTabFriendOuIDLabelX->TabIndex = 2;
			this->myFriendListTabFriendOuIDLabelX->Text = L"OuID";
			// 
			// myFriendListTabFriendNicknameLabelX
			// 
			this->myFriendListTabFriendNicknameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->myFriendListTabFriendNicknameLabelX->BackgroundStyle->Class = L"";
			this->myFriendListTabFriendNicknameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->myFriendListTabFriendNicknameLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->myFriendListTabFriendNicknameLabelX->Location = System::Drawing::Point(20, 40);
			this->myFriendListTabFriendNicknameLabelX->Name = L"myFriendListTabFriendNicknameLabelX";
			this->myFriendListTabFriendNicknameLabelX->Size = System::Drawing::Size(13, 16);
			this->myFriendListTabFriendNicknameLabelX->TabIndex = 1;
			this->myFriendListTabFriendNicknameLabelX->Text = L"-";
			// 
			// expandableSplitter3
			// 
			this->expandableSplitter3->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter3->BackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter3->BackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandableSplitter3->ExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter3->ExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter3->ExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter3->ExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter3->GripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter3->GripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter3->GripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter3->GripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter3->HotBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), 
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->expandableSplitter3->HotBackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->expandableSplitter3->HotBackColor2SchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground2;
			this->expandableSplitter3->HotBackColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemPressedBackground;
			this->expandableSplitter3->HotExpandFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter3->HotExpandFillColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter3->HotExpandLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->expandableSplitter3->HotExpandLineColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandableSplitter3->HotGripDarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(101)), 
				static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->expandableSplitter3->HotGripDarkColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandableSplitter3->HotGripLightColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->expandableSplitter3->HotGripLightColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarBackground;
			this->expandableSplitter3->Location = System::Drawing::Point(116, 25);
			this->expandableSplitter3->Name = L"expandableSplitter3";
			this->expandableSplitter3->Size = System::Drawing::Size(5, 506);
			this->expandableSplitter3->Style = DevComponents::DotNetBar::eSplitterStyle::Office2007;
			this->expandableSplitter3->TabIndex = 5;
			this->expandableSplitter3->TabStop = false;
			// 
			// friendList
			// 
			this->friendList->AccessibleRole = System::Windows::Forms::AccessibleRole::ToolBar;
			this->friendList->BorderStyle = DevComponents::DotNetBar::eBorderType::None;
			this->friendList->Dock = System::Windows::Forms::DockStyle::Left;
			this->friendList->ExpandedPanel = this->myFriendListSideBarPanelItem;
			this->friendList->Location = System::Drawing::Point(0, 25);
			this->friendList->MinimumSize = System::Drawing::Size(116, 0);
			this->friendList->Name = L"friendList";
			this->friendList->Panels->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->myFriendListSideBarPanelItem});
			this->friendList->Size = System::Drawing::Size(116, 506);
			this->friendList->Style = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->friendList->TabIndex = 4;
			this->friendList->Text = L"friendListSidebar";
			this->friendList->UsingSystemColors = true;
			// 
			// myFriendListSideBarPanelItem
			// 
			this->myFriendListSideBarPanelItem->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->myFriendListSideBarPanelItem->FontBold = true;
			this->myFriendListSideBarPanelItem->HotFontBold = true;
			this->myFriendListSideBarPanelItem->Name = L"myFriendListSideBarPanelItem";
			this->myFriendListSideBarPanelItem->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->buttonItem12});
			this->myFriendListSideBarPanelItem->Text = L"我的好友";
			// 
			// buttonItem12
			// 
			this->buttonItem12->ImagePosition = DevComponents::DotNetBar::eImagePosition::Top;
			this->buttonItem12->Name = L"buttonItem12";
			this->buttonItem12->Text = L"buttonItem12";
			// 
			// myFriendListBar
			// 
			this->myFriendListBar->AntiAlias = true;
			this->myFriendListBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->myFriendListBar->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->myFriendListBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(4) {this->createFriendGroupButton, 
				this->renameFriendGroupButton, this->deleteFriendGroupButton, this->displayOnlineFriendOnlyButton});
			this->myFriendListBar->Location = System::Drawing::Point(0, 0);
			this->myFriendListBar->Name = L"myFriendListBar";
			this->myFriendListBar->Size = System::Drawing::Size(593, 25);
			this->myFriendListBar->Stretch = true;
			this->myFriendListBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->myFriendListBar->TabIndex = 0;
			this->myFriendListBar->TabStop = false;
			this->myFriendListBar->Text = L"bar2";
			// 
			// createFriendGroupButton
			// 
			this->createFriendGroupButton->FixedSize = System::Drawing::Size(100, 17);
			this->createFriendGroupButton->Name = L"createFriendGroupButton";
			this->createFriendGroupButton->Text = L"创建新分类";
			// 
			// renameFriendGroupButton
			// 
			this->renameFriendGroupButton->FixedSize = System::Drawing::Size(100, 17);
			this->renameFriendGroupButton->Name = L"renameFriendGroupButton";
			this->renameFriendGroupButton->Text = L"重命名分类";
			// 
			// deleteFriendGroupButton
			// 
			this->deleteFriendGroupButton->FixedSize = System::Drawing::Size(100, 17);
			this->deleteFriendGroupButton->Name = L"deleteFriendGroupButton";
			this->deleteFriendGroupButton->Text = L"删除分类";
			// 
			// displayOnlineFriendOnlyButton
			// 
			this->displayOnlineFriendOnlyButton->Name = L"displayOnlineFriendOnlyButton";
			this->displayOnlineFriendOnlyButton->Text = L"只显示在线好友";
			// 
			// myFriendListTab
			// 
			this->myFriendListTab->AttachedControl = this->superTabControlPanel17;
			this->myFriendListTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->myFriendListTab->GlobalItem = false;
			this->myFriendListTab->Name = L"myFriendListTab";
			this->myFriendListTab->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 10.5F));
			this->myFriendListTab->TabFont = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold));
			this->myFriendListTab->Text = L"好友列表";
			// 
			// friendListContextMenuStrip
			// 
			this->friendListContextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->openFriendDlgToolStripMenuItem, 
				this->removeFriendToolStripMenuItem});
			this->friendListContextMenuStrip->Name = L"friendListContextMenuStrip";
			this->friendListContextMenuStrip->Size = System::Drawing::Size(147, 48);
			// 
			// openFriendDlgToolStripMenuItem
			// 
			this->openFriendDlgToolStripMenuItem->Name = L"openFriendDlgToolStripMenuItem";
			this->openFriendDlgToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openFriendDlgToolStripMenuItem->Text = L"发送即时消息";
			// 
			// removeFriendToolStripMenuItem
			// 
			this->removeFriendToolStripMenuItem->AutoToolTip = true;
			this->removeFriendToolStripMenuItem->Name = L"removeFriendToolStripMenuItem";
			this->removeFriendToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->removeFriendToolStripMenuItem->Text = L"删除好友";
			this->removeFriendToolStripMenuItem->ToolTipText = L"移除当前选择的好友";
			// 
			// FriendListTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->Controls->Add(this->superTabControl2);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FriendListTab";
			this->Text = L"FriendListTab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl2))->EndInit();
			this->superTabControl2->ResumeLayout(false);
			this->superTabControlPanel16->ResumeLayout(false);
			this->superTabControlPanel16->PerformLayout();
			this->superTabControlPanel17->ResumeLayout(false);
			this->panelEx2->ResumeLayout(false);
			this->sharingFileListPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->friendShareFileListAdvTree))->EndInit();
			this->personalInformationPanel->ResumeLayout(false);
			this->personalInformationPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->myFriendListBar))->EndInit();
			this->friendListContextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void OpenFriendChatDlg(Object^ sender, EventArgs^ e);

	public: System::Void RemoveTargetFileTransferJob(unsigned srcID, String ^ fileName, String ^ md5, int reason);

	private: System::Void searchFriendOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void searchFriendEmailRadioButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void searchFriendNicknameRadioButton_Click(System::Object^  sender, System::EventArgs^  e) ;
			 /*
			 * this function doing the adding friend request
			 */
	private: System::Void searchFriendAddFriendButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void InitializeFriendListTab(void);


	private: System::Void searchFriendSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void InitializeSearchFriendSearchResult(void);
	private: System::Void searchFriendPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void searchFriendNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void searchFriendResultList_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) ;
	private: System::Void QueryFriendPersonalInfo(System::Object^  sender, System::EventArgs^  e) ;

	private: System::Void removeFriendToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			 System::Void FriendListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 
	private: System::Void FriendButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	public:
			 /* 
			 * This function will be called when there is a response for the request that search specific friend 
			 * This function will dynamic cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
			 * Each Object represent a search result entry. 
			 */
			 System::Void DisplaySearchFriendResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults);

			 /* 
			 * This function will display the friend list in the login in user to UI
			 */

		public:	System::Void UpdateFriendListToUI(void);
				/*
				* This function will be used to find the checked button item in the friend list
			 */
				OusnsFriend^ FindSelectedFriend(void);
				/*
				* This function will be called when there is a response for the request that the login user is querying one of his friends personal information, like the birthday.
				* This function will take ONLY 1 param.
				* ousnsFriend, the type is OusnsFriend. This function will dynamically cast the first element in the param to OusnsFriend type and display this friend personal information in the UI.
				*/
				System::Void DisplayFriendPersonalInfo(LinkedList<Object^>^ params);

	};
}
