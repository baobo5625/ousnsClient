#pragma once
#include "stdafx.h"


#ifndef FRIEND_DLG
#define FRIEND_DLG


namespace OuSns {


	/// <summary>
	/// friendChatDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	ref class FriendListTab;
	ref class OusnsLoginUser;
	ref class OusnsFriend;
	public ref class friendChatDlg : public System::Windows::Forms::Form
	//public ref class friendChatDlg : OusnsDlg
	{
	public: OusnsFriend ^ _friend;
	public:  OusnsLoginUser ^ _login_usr;

	public: delegate System::Void AddFileTransferJobDelegate(String ^ fileName, String ^ filePath, int fileSize, String ^ md5, bool isSender);
	public: delegate System::Void RemoveFileTransferJobDelegate(String ^ panelName, int reason);
	public: delegate System::Void StartDirectFileTransferDelegate(String ^ fileName, String ^ md5);
	

	// A dictionary that stores the BackgroundWorker instances for all the panels on the UI.
	// key: panel name
	// value: BackgroundWorker instance
	public: Dictionary<String ^, DirectTransferFile ^> ^ fileTransferJobPanelList;
			LinkedList<FileTransferPort ^> ^ fileTransferPortList;

	private: bool sidePanelDisplayed;


	private: System::Windows::Forms::SplitContainer^  friendChatChattingSplitContainer;
	private: System::Windows::Forms::RichTextBox^  friendChatDisplay;
	private: DevComponents::DotNetBar::PanelEx^  panelEx3;
	private: DevComponents::DotNetBar::PanelEx^  panelEx2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;
	private: System::Windows::Forms::RichTextBox^  friendMessageEntry;
	private: DevComponents::DotNetBar::PanelEx^  panelEx4;
	private: DevComponents::DotNetBar::ButtonX^  buttonX3;
	private: DevComponents::DotNetBar::ButtonX^  sendFileButton;
	private: DevComponents::DotNetBar::ButtonX^  expandButton;
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	private: DevComponents::DotNetBar::TabControlPanel^  friendChatSendFileTabControlPanel;
	private: DevComponents::DotNetBar::TabItem^  tabItem1;
	private: DevComponents::DotNetBar::TabControlPanel^  sharedFileTabPanel;
	private: DevComponents::DotNetBar::LabelX^  friendNicknameLabelX;
	private: DevComponents::DotNetBar::LabelX^  friendSignatureLabelX;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::Bar^  rightCornerFunctionBar;
	private: DevComponents::DotNetBar::ButtonItem^  minimizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  maximizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  closeButton;
	private: DevComponents::DotNetBar::TabControl^  friendChatTabControl;
	private: DevComponents::DotNetBar::TabControlPanel^  chatTabPanel;
	private: DevComponents::DotNetBar::TabItem^  chatTab;
	private: DevComponents::DotNetBar::TabControlPanel^  tabControlPanel3;
	private: DevComponents::DotNetBar::TabItem^  tabItem3;
	private: DevComponents::DotNetBar::TabControlPanel^  tabControlPanel1;
	private: DevComponents::DotNetBar::TabItem^  checkShareFileTab;


	// common part
	public:
		String^ ressrc;
		System::Reflection::Assembly^ execAssem;
		Resources::ResourceManager^ myres;
		bool isDown;
		OuSns::MouseLocationStyle loactionStyle;
		Point LastMoustLocation;

	public:
		[DllImport("user32.dll")]
		static bool RelaeseCapture(void);
		[DllImport("user32.dll")]
		static bool SendMessage(IntPtr hwnd, int wMsg, int wParam, int lParam);
	public:
		friendChatDlg(FriendListTab ^ parent, OusnsFriend ^ targetFriend, OusnsLoginUser ^ loginUser);
			

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~friendChatDlg()
		{
			if (components)
			{
				delete components;
			}
		}


	public:  FriendListTab^ parent;
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
			this->panelEx1 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->panelEx4 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->friendChatTabControl = (gcnew DevComponents::DotNetBar::TabControl());
			this->chatTabPanel = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->expandButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->friendChatChattingSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->friendChatDisplay = (gcnew System::Windows::Forms::RichTextBox());
			this->panelEx3 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->buttonX3 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->sendFileButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->panelEx2 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->friendMessageEntry = (gcnew System::Windows::Forms::RichTextBox());
			this->chatTab = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->tabControlPanel1 = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->checkShareFileTab = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->tabControlPanel3 = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->tabItem3 = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->friendNicknameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->friendSignatureLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->rightCornerFunctionBar = (gcnew DevComponents::DotNetBar::Bar());
			this->minimizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->maximizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->closeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->sharedFileTabPanel = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->panelEx1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->friendChatTabControl))->BeginInit();
			this->friendChatTabControl->SuspendLayout();
			this->chatTabPanel->SuspendLayout();
			this->friendChatChattingSplitContainer->Panel1->SuspendLayout();
			this->friendChatChattingSplitContainer->Panel2->SuspendLayout();
			this->friendChatChattingSplitContainer->SuspendLayout();
			this->panelEx3->SuspendLayout();
			this->panelEx2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelEx1
			// 
			this->panelEx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx1->CanvasColor = System::Drawing::Color::Transparent;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->panelEx4);
			this->panelEx1->Controls->Add(this->friendChatTabControl);
			this->panelEx1->Controls->Add(this->friendNicknameLabelX);
			this->panelEx1->Controls->Add(this->friendSignatureLabelX);
			this->panelEx1->Controls->Add(this->pictureBox1);
			this->panelEx1->Controls->Add(this->rightCornerFunctionBar);
			this->panelEx1->Location = System::Drawing::Point(0, 0);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Padding = System::Windows::Forms::Padding(4, 1, 4, 4);
			this->panelEx1->Size = System::Drawing::Size(549, 524);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 3;
			this->panelEx1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &friendChatDlg::friendChatDlg_MouseMove);
			this->panelEx1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &friendChatDlg::panelEx1_MouseDoubleClick);
			this->panelEx1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &friendChatDlg::MoveDialog_MouseDown);
			this->panelEx1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &friendChatDlg::friendChatDlg_MouseUp);
			// 
			// panelEx4
			// 
			this->panelEx4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx4->AutoScroll = true;
			this->panelEx4->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx4->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx4->Cursor = System::Windows::Forms::Cursors::Default;
			this->panelEx4->Location = System::Drawing::Point(343, 104);
			this->panelEx4->Margin = System::Windows::Forms::Padding(0);
			this->panelEx4->Name = L"panelEx4";
			this->panelEx4->Size = System::Drawing::Size(200, 417);
			this->panelEx4->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx4->Style->BackColor1->Color = System::Drawing::Color::White;
			this->panelEx4->Style->BackColor2->Color = System::Drawing::Color::White;
			this->panelEx4->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx4->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx4->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx4->Style->GradientAngle = 90;
			this->panelEx4->TabIndex = 14;
			// 
			// friendChatTabControl
			// 
			this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->friendChatTabControl->BackColor = System::Drawing::Color::Transparent;
			this->friendChatTabControl->CanReorderTabs = false;
			this->friendChatTabControl->ColorScheme->TabBackground = System::Drawing::Color::Transparent;
			this->friendChatTabControl->ColorScheme->TabBackground2 = System::Drawing::Color::Transparent;
			this->friendChatTabControl->ColorScheme->TabItemBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), 
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(249))), 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), 
				static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(248))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), 
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(245))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), 
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(247))), 
				1))});
			this->friendChatTabControl->ColorScheme->TabItemHotBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(235))), 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(168))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(89))), 0.45F)), 
				(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(141))), 
				1))});
			this->friendChatTabControl->ColorScheme->TabItemSelectedBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::White, 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				1))});
			this->friendChatTabControl->Controls->Add(this->chatTabPanel);
			this->friendChatTabControl->Controls->Add(this->tabControlPanel1);
			this->friendChatTabControl->Controls->Add(this->tabControlPanel3);
			this->friendChatTabControl->Cursor = System::Windows::Forms::Cursors::Default;
			this->friendChatTabControl->FixedTabSize = System::Drawing::Size(100, 30);
			this->friendChatTabControl->Location = System::Drawing::Point(2, 71);
			this->friendChatTabControl->Margin = System::Windows::Forms::Padding(0);
			this->friendChatTabControl->MinimumSize = System::Drawing::Size(340, 450);
			this->friendChatTabControl->Name = L"friendChatTabControl";
			this->friendChatTabControl->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->friendChatTabControl->SelectedTabIndex = 0;
			this->friendChatTabControl->Size = System::Drawing::Size(341, 450);
			this->friendChatTabControl->Style = DevComponents::DotNetBar::eTabStripStyle::Office2007Dock;
			this->friendChatTabControl->TabIndex = 13;
			this->friendChatTabControl->TabLayoutType = DevComponents::DotNetBar::eTabLayoutType::FixedWithNavigationBox;
			this->friendChatTabControl->Tabs->Add(this->chatTab);
			this->friendChatTabControl->Tabs->Add(this->checkShareFileTab);
			this->friendChatTabControl->Tabs->Add(this->tabItem3);
			// 
			// chatTabPanel
			// 
			this->chatTabPanel->Controls->Add(this->expandButton);
			this->chatTabPanel->Controls->Add(this->friendChatChattingSplitContainer);
			this->chatTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatTabPanel->Location = System::Drawing::Point(0, 33);
			this->chatTabPanel->Name = L"chatTabPanel";
			this->chatTabPanel->Padding = System::Windows::Forms::Padding(1);
			this->chatTabPanel->Size = System::Drawing::Size(341, 417);
			this->chatTabPanel->Style->BackColor1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->chatTabPanel->Style->BackColor2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(157)), 
				static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->chatTabPanel->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->chatTabPanel->Style->BorderColor->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->chatTabPanel->Style->BorderSide = static_cast<DevComponents::DotNetBar::eBorderSide>(((DevComponents::DotNetBar::eBorderSide::Left | DevComponents::DotNetBar::eBorderSide::Right) 
				| DevComponents::DotNetBar::eBorderSide::Bottom));
			this->chatTabPanel->Style->GradientAngle = 90;
			this->chatTabPanel->TabIndex = 1;
			this->chatTabPanel->TabItem = this->chatTab;
			// 
			// expandButton
			// 
			this->expandButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->expandButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->expandButton->Dock = System::Windows::Forms::DockStyle::Right;
			this->expandButton->FocusCuesEnabled = false;
			this->expandButton->Location = System::Drawing::Point(334, 1);
			this->expandButton->Name = L"expandButton";
			this->expandButton->Shape = (gcnew DevComponents::DotNetBar::RoundRectangleShapeDescriptor());
			this->expandButton->Size = System::Drawing::Size(6, 415);
			this->expandButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->expandButton->TabIndex = 4;
			this->expandButton->Click += gcnew System::EventHandler(this, &friendChatDlg::ExtendPanel_Click);
			// 
			// friendChatChattingSplitContainer
			// 
			this->friendChatChattingSplitContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->friendChatChattingSplitContainer->BackColor = System::Drawing::Color::White;
			this->friendChatChattingSplitContainer->Cursor = System::Windows::Forms::Cursors::Default;
			this->friendChatChattingSplitContainer->Location = System::Drawing::Point(4, 1);
			this->friendChatChattingSplitContainer->Margin = System::Windows::Forms::Padding(0);
			this->friendChatChattingSplitContainer->Name = L"friendChatChattingSplitContainer";
			this->friendChatChattingSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// friendChatChattingSplitContainer.Panel1
			// 
			this->friendChatChattingSplitContainer->Panel1->BackColor = System::Drawing::Color::White;
			this->friendChatChattingSplitContainer->Panel1->Controls->Add(this->friendChatDisplay);
			// 
			// friendChatChattingSplitContainer.Panel2
			// 
			this->friendChatChattingSplitContainer->Panel2->Controls->Add(this->panelEx3);
			this->friendChatChattingSplitContainer->Panel2->Controls->Add(this->panelEx2);
			this->friendChatChattingSplitContainer->Panel2->Controls->Add(this->friendMessageEntry);
			this->friendChatChattingSplitContainer->Size = System::Drawing::Size(328, 415);
			this->friendChatChattingSplitContainer->SplitterDistance = 208;
			this->friendChatChattingSplitContainer->SplitterWidth = 1;
			this->friendChatChattingSplitContainer->TabIndex = 3;
			// 
			// friendChatDisplay
			// 
			this->friendChatDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->friendChatDisplay->BackColor = System::Drawing::SystemColors::Window;
			this->friendChatDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->friendChatDisplay->BulletIndent = 4;
			this->friendChatDisplay->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->friendChatDisplay->Location = System::Drawing::Point(9, 10);
			this->friendChatDisplay->Margin = System::Windows::Forms::Padding(0);
			this->friendChatDisplay->Name = L"friendChatDisplay";
			this->friendChatDisplay->ReadOnly = true;
			this->friendChatDisplay->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->friendChatDisplay->Size = System::Drawing::Size(308, 194);
			this->friendChatDisplay->TabIndex = 11;
			this->friendChatDisplay->Text = L"";
			// 
			// panelEx3
			// 
			this->panelEx3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx3->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx3->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx3->Controls->Add(this->buttonX3);
			this->panelEx3->Controls->Add(this->sendFileButton);
			this->panelEx3->Cursor = System::Windows::Forms::Cursors::Default;
			this->panelEx3->Location = System::Drawing::Point(-1, 161);
			this->panelEx3->Name = L"panelEx3";
			this->panelEx3->Size = System::Drawing::Size(329, 46);
			this->panelEx3->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx3->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx3->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx3->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx3->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx3->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx3->Style->GradientAngle = 90;
			this->panelEx3->TabIndex = 16;
			// 
			// buttonX3
			// 
			this->buttonX3->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX3->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX3->Location = System::Drawing::Point(248, 9);
			this->buttonX3->Name = L"buttonX3";
			this->buttonX3->Size = System::Drawing::Size(75, 23);
			this->buttonX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX3->TabIndex = 1;
			this->buttonX3->Text = L"发送";
			this->buttonX3->Click += gcnew System::EventHandler(this, &friendChatDlg::friendChatDlg_Send);
			// 
			// sendFileButton
			// 
			this->sendFileButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->sendFileButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->sendFileButton->Location = System::Drawing::Point(96, 11);
			this->sendFileButton->Name = L"sendFileButton";
			this->sendFileButton->Size = System::Drawing::Size(75, 23);
			this->sendFileButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->sendFileButton->TabIndex = 0;
			this->sendFileButton->Text = L"发送文件";
			this->sendFileButton->Click += gcnew System::EventHandler(this, &friendChatDlg::sendFileButton_Click);
			// 
			// panelEx2
			// 
			this->panelEx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx2->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx2->Controls->Add(this->buttonX1);
			this->panelEx2->Cursor = System::Windows::Forms::Cursors::Default;
			this->panelEx2->Location = System::Drawing::Point(-5, -4);
			this->panelEx2->Name = L"panelEx2";
			this->panelEx2->Size = System::Drawing::Size(333, 26);
			this->panelEx2->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx2->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx2->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx2->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx2->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx2->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx2->Style->GradientAngle = 90;
			this->panelEx2->TabIndex = 15;
			// 
			// buttonX1
			// 
			this->buttonX1->AccessibleRole = System::Windows::Forms::AccessibleRole::Graphic;
			this->buttonX1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->buttonX1->FocusCuesEnabled = false;
			this->buttonX1->Location = System::Drawing::Point(83, 3);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(20, 20);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 1;
			this->buttonX1->Click += gcnew System::EventHandler(this, &friendChatDlg::ExtendPanel_Click);
			// 
			// friendMessageEntry
			// 
			this->friendMessageEntry->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->friendMessageEntry->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->friendMessageEntry->BulletIndent = 4;
			this->friendMessageEntry->EnableAutoDragDrop = true;
			this->friendMessageEntry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->friendMessageEntry->Location = System::Drawing::Point(9, 23);
			this->friendMessageEntry->Margin = System::Windows::Forms::Padding(10);
			this->friendMessageEntry->Name = L"friendMessageEntry";
			this->friendMessageEntry->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->friendMessageEntry->Size = System::Drawing::Size(305, 134);
			this->friendMessageEntry->TabIndex = 13;
			this->friendMessageEntry->Text = L"";
			this->friendMessageEntry->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &friendChatDlg::friendChatDlg_OnPressingEnter);
			// 
			// chatTab
			// 
			this->chatTab->AttachedControl = this->chatTabPanel;
			this->chatTab->Name = L"chatTab";
			this->chatTab->Text = L"聊  天";
			// 
			// tabControlPanel1
			// 
			this->tabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlPanel1->Location = System::Drawing::Point(0, 33);
			this->tabControlPanel1->Name = L"tabControlPanel1";
			this->tabControlPanel1->Padding = System::Windows::Forms::Padding(1);
			this->tabControlPanel1->Size = System::Drawing::Size(341, 417);
			this->tabControlPanel1->Style->BackColor1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->tabControlPanel1->Style->BackColor2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(157)), 
				static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->tabControlPanel1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->tabControlPanel1->Style->BorderColor->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->tabControlPanel1->Style->BorderSide = static_cast<DevComponents::DotNetBar::eBorderSide>(((DevComponents::DotNetBar::eBorderSide::Left | DevComponents::DotNetBar::eBorderSide::Right) 
				| DevComponents::DotNetBar::eBorderSide::Bottom));
			this->tabControlPanel1->Style->GradientAngle = 90;
			this->tabControlPanel1->TabIndex = 2;
			this->tabControlPanel1->TabItem = this->checkShareFileTab;
			// 
			// checkShareFileTab
			// 
			this->checkShareFileTab->AttachedControl = this->tabControlPanel1;
			this->checkShareFileTab->Name = L"checkShareFileTab";
			this->checkShareFileTab->Text = L"查看共享";
			this->checkShareFileTab->Click += gcnew System::EventHandler(this, &friendChatDlg::checkShareFileTab_Click);
			// 
			// tabControlPanel3
			// 
			this->tabControlPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlPanel3->Location = System::Drawing::Point(0, 33);
			this->tabControlPanel3->Name = L"tabControlPanel3";
			this->tabControlPanel3->Padding = System::Windows::Forms::Padding(1);
			this->tabControlPanel3->Size = System::Drawing::Size(341, 417);
			this->tabControlPanel3->Style->BackColor1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->tabControlPanel3->Style->BackColor2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(157)), 
				static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->tabControlPanel3->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->tabControlPanel3->Style->BorderColor->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->tabControlPanel3->Style->BorderSide = static_cast<DevComponents::DotNetBar::eBorderSide>(((DevComponents::DotNetBar::eBorderSide::Left | DevComponents::DotNetBar::eBorderSide::Right) 
				| DevComponents::DotNetBar::eBorderSide::Bottom));
			this->tabControlPanel3->Style->GradientAngle = 90;
			this->tabControlPanel3->TabIndex = 3;
			this->tabControlPanel3->TabItem = this->tabItem3;
			// 
			// tabItem3
			// 
			this->tabItem3->AttachedControl = this->tabControlPanel3;
			this->tabItem3->Name = L"tabItem3";
			this->tabItem3->Text = L"查看更新记录";
			// 
			// friendNicknameLabelX
			// 
			this->friendNicknameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->friendNicknameLabelX->BackgroundStyle->Class = L"";
			this->friendNicknameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->friendNicknameLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->friendNicknameLabelX->Location = System::Drawing::Point(70, 8);
			this->friendNicknameLabelX->Name = L"friendNicknameLabelX";
			this->friendNicknameLabelX->SingleLineColor = System::Drawing::SystemColors::ButtonHighlight;
			this->friendNicknameLabelX->Size = System::Drawing::Size(76, 20);
			this->friendNicknameLabelX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->friendNicknameLabelX->TabIndex = 10;
			this->friendNicknameLabelX->Text = L"nickname";
			// 
			// friendSignatureLabelX
			// 
			this->friendSignatureLabelX->AutoSize = true;
			// 
			// 
			// 
			this->friendSignatureLabelX->BackgroundStyle->Class = L"";
			this->friendSignatureLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->friendSignatureLabelX->Location = System::Drawing::Point(70, 37);
			this->friendSignatureLabelX->Name = L"friendSignatureLabelX";
			this->friendSignatureLabelX->Size = System::Drawing::Size(62, 16);
			this->friendSignatureLabelX->TabIndex = 11;
			this->friendSignatureLabelX->Text = L"signature";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(10, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(54, 60);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// rightCornerFunctionBar
			// 
			this->rightCornerFunctionBar->AntiAlias = true;
			this->rightCornerFunctionBar->BackColor = System::Drawing::Color::Transparent;
			this->rightCornerFunctionBar->CanDockBottom = false;
			this->rightCornerFunctionBar->CanDockLeft = false;
			this->rightCornerFunctionBar->CanDockRight = false;
			this->rightCornerFunctionBar->CanDockTab = false;
			this->rightCornerFunctionBar->CanDockTop = false;
			this->rightCornerFunctionBar->CanReorderTabs = false;
			this->rightCornerFunctionBar->CanUndock = false;
			this->rightCornerFunctionBar->Dock = System::Windows::Forms::DockStyle::Right;
			this->rightCornerFunctionBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->minimizeButton, 
				this->maximizeButton, this->closeButton});
			this->rightCornerFunctionBar->Location = System::Drawing::Point(457, 1);
			this->rightCornerFunctionBar->Margin = System::Windows::Forms::Padding(0);
			this->rightCornerFunctionBar->MaximumSize = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->MinimumSize = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->Name = L"rightCornerFunctionBar";
			this->rightCornerFunctionBar->PaddingBottom = 0;
			this->rightCornerFunctionBar->PaddingLeft = 0;
			this->rightCornerFunctionBar->PaddingRight = 0;
			this->rightCornerFunctionBar->PaddingTop = 0;
			this->rightCornerFunctionBar->RoundCorners = false;
			this->rightCornerFunctionBar->SingleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->rightCornerFunctionBar->Size = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->Stretch = true;
			this->rightCornerFunctionBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->rightCornerFunctionBar->TabIndex = 12;
			this->rightCornerFunctionBar->TabStop = false;
			this->rightCornerFunctionBar->Text = L"bar1";
			// 
			// minimizeButton
			// 
			this->minimizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->minimizeButton->ImagePaddingHorizontal = 0;
			this->minimizeButton->ImagePaddingVertical = 0;
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Text = L"小";
			this->minimizeButton->Click += gcnew System::EventHandler(this, &friendChatDlg::minimizeButton_Click);
			// 
			// maximizeButton
			// 
			this->maximizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->maximizeButton->ImagePaddingHorizontal = 0;
			this->maximizeButton->ImagePaddingVertical = 0;
			this->maximizeButton->Name = L"maximizeButton";
			this->maximizeButton->Text = L"大";
			this->maximizeButton->Click += gcnew System::EventHandler(this, &friendChatDlg::maximizeButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->closeButton->ImagePaddingHorizontal = 0;
			this->closeButton->ImagePaddingVertical = 0;
			this->closeButton->Name = L"closeButton";
			this->closeButton->Text = L"关闭";
			this->closeButton->Click += gcnew System::EventHandler(this, &friendChatDlg::closeButton_Click);
			// 
			// sharedFileTabPanel
			// 
			this->sharedFileTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sharedFileTabPanel->Location = System::Drawing::Point(0, 33);
			this->sharedFileTabPanel->Name = L"sharedFileTabPanel";
			this->sharedFileTabPanel->Padding = System::Windows::Forms::Padding(1);
			this->sharedFileTabPanel->Size = System::Drawing::Size(396, 423);
			this->sharedFileTabPanel->Style->BackColor1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->sharedFileTabPanel->Style->BackColor2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(157)), 
				static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->sharedFileTabPanel->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->sharedFileTabPanel->Style->BorderColor->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->sharedFileTabPanel->Style->BorderSide = static_cast<DevComponents::DotNetBar::eBorderSide>(((DevComponents::DotNetBar::eBorderSide::Left | DevComponents::DotNetBar::eBorderSide::Right) 
				| DevComponents::DotNetBar::eBorderSide::Bottom));
			this->sharedFileTabPanel->Style->GradientAngle = 90;
			this->sharedFileTabPanel->TabIndex = 2;
			// 
			// friendChatDlg
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(549, 522);
			this->ControlBox = false;
			this->Controls->Add(this->panelEx1);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(557, 530);
			this->Name = L"friendChatDlg";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &friendChatDlg::friendChatDlg_OnClosing);
			this->panelEx1->ResumeLayout(false);
			this->panelEx1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->friendChatTabControl))->EndInit();
			this->friendChatTabControl->ResumeLayout(false);
			this->chatTabPanel->ResumeLayout(false);
			this->friendChatChattingSplitContainer->Panel1->ResumeLayout(false);
			this->friendChatChattingSplitContainer->Panel2->ResumeLayout(false);
			this->friendChatChattingSplitContainer->ResumeLayout(false);
			this->panelEx3->ResumeLayout(false);
			this->panelEx2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void friendChatDlg_Send(System::Object^  sender, System::EventArgs^  e);

	private: System::Void friendChatDlg_OnClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

	public: System::Void push_new_message(ChatMessage ^ msg);

			System::Void AppendTextToChatDisplay(String ^ content);

	private: System::Void friendChatDlg_OnPressingEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

			 System::String ^ friendChatDlg::ExtractTextFromRTF(String ^ rtfString);
			 System::String ^ friendChatDlg::AppendTextToRTF(String ^ rtfString, String ^ text);
	public: System::Void friendChatDlg::Blink();


	private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void maximizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 ReleaseCapture();
				 if(IsZoomed((HWND)this->Handle.ToPointer())){
					 SendMessage(this->Handle,WM_SYSCOMMAND, SC_RESTORE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
					 this->SuspendLayout();
					 this->maximizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_highlight")));
					 this->maximizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_normal")));
					 this->maximizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_down")));

					 this->ResumeLayout(false);
				 }
				 else{
					 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MAXIMIZE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
					 this->SuspendLayout();
					 this->maximizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_highlight")));
					 this->maximizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_normal")));
					 this->maximizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_down")));
					 this->ResumeLayout(false);
					 //Invalidate();
				 }
			 }
	private: System::Void minimizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 ReleaseCapture();
				 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MINIMIZE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
				 //Invalidate();
			 }


	private: System::Void MoveDialog_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 Point mouseLocation = Point(Control::MousePosition.X - this->Location.X, Control::MousePosition.Y - this->Location.Y);
				 isDown = true;
				 if (this->Cursor != ::Cursors::Default){
					 OuSns::ChangeSize(mouseLocation, this->loactionStyle,this);
				 } 
			 }

	private: System::Void friendChatDlg_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				
				Point mouseLocation = Point(Control::MousePosition.X - this->Location.X, Control::MousePosition.Y - this->Location.Y);
				this->loactionStyle = OuSns::GetLocationStyle(mouseLocation,this);
				this->Cursor = OuSns::GetCursorByMouseLocationStyle(this->loactionStyle);
				 if(this->isDown){
					 ReleaseCapture();
					 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MOVE+HTCAPTION,0);
				 }
				 
			 }
	private: System::Void friendChatDlg_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 //调用窗体移动的方法

				 this->loactionStyle = OuSns::S22_MIDDLECENTER;
				 this->Cursor = ::Cursors::Default;
				 this->isDown = false;
			 }

	

	private: System::Void panelEx1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(e->Button == ::MouseButtons::Left){
					 this->maximizeButton_Click(sender,e);
				 }
			 }
	private: System::Void ExtendPanel_Click(System::Object^  sender, System::EventArgs^  e);


private: System::Void sendFileButton_Click(System::Object^  sender, System::EventArgs^  e);

		 // Functions for delegates
public: System::Void AddFileTransferJobPanel(String ^ fileName, String ^ filePath, int fileSize, String ^ md5, bool isSender);

		System::Void RemoveFileTransferJobPanel(String ^ panelName, int reason);

		System::Void StartSendFileThread(String ^ fileName, String ^ md5);

		System::Void StartReceiveFileThread(String ^ fileName, String ^ md5);

		// END functions for delegates

private: System::Void fileTransferCancelButton_Click(System::Object^  sender, System::EventArgs^  e);

		 System::Void performCancelFileTransferAction(String ^ panelName);

		 System::Void fileTransferRejectButton_Click(System::Object^  sender, System::EventArgs^  e);

		 System::Void performRejectFileTransferAction(String ^ panelName);

		 System::Void fileTransferAcceptButton_Click(System::Object^  sender, System::EventArgs^  e);

		 

		 System::Void backgroundWorkerDoReceive(Object ^ sender, DoWorkEventArgs ^ e);

		 int receiveDirectTransferFile(String ^ panelName,
												BackgroundWorker ^ worker, DoWorkEventArgs ^ e);

		 System::Void backgroundWorkerReceiveCompleted(Object ^ sender, RunWorkerCompletedEventArgs ^ e);

		 System::Void backgroundWorkerReceiveProgressChanged(Object ^ sender, ProgressChangedEventArgs ^ e);

		 System::Void backgroundWorkerDoSend(Object ^ sender, DoWorkEventArgs ^ e);

		 int sendDirectTransferFile(String ^ panelName,
												BackgroundWorker ^ worker, DoWorkEventArgs ^ e);

		 System::Void backgroundWorkerSendCompleted(Object ^ sender, RunWorkerCompletedEventArgs ^ e);

		 System::Void backgroundWorkerSendProgressChanged(Object ^ sender, ProgressChangedEventArgs ^ e);

		 UDTSOCKET establishP2PConnection(UDTSOCKET u, String ^ panelName);

		 /* Function for exchangePortInfo thread. This thread sends a packet to its peer using a different
		    port than the listening port and wait for its own listening port to receive the peer's exchange
			port info packet. After the listening thread processes the exchange port info packet, the listening thread
		    will notify the exchangePortInfo thread and the exchangePortInfo thread will then dispatch a background worker
		    to setup the UDT connection.
			
			Parameters: String ^ fileName, String ^ md5
		  */
public:	 System::Void exchangePortInfo(String ^ fileName, String ^ md5);

		 protected: virtual void WndProc(Message % m) override{
						//RECT rc;
						//HWND hwnd = (HWND)(form->Handle.ToPointer());
						NCCALCSIZE_PARAMS* pncc;
						long caption = 1;
						long bottom = 0;
						long border = 0;
						long mLeft,mRight,mTop,mBottom;
						switch (m.Msg)
						{

						case WM_NCPAINT:

							//System::Windows::Forms::Form::WndProc(m);
							break;
						case WM_NCACTIVATE:
							if((int)m.WParam == 0)
								m.Result = (IntPtr)1;

							break;

						case WM_NCCALCSIZE:

							//InflateRect(&((NCCALCSIZE_PARAMS* )lParam)->rgrc[0],-50,-50);
							pncc = (NCCALCSIZE_PARAMS *)m.LParam.ToPointer();
							//pncc->rgrc[0] is the new rectangle
							//pncc->rgrc[1] is the old rectangle
							//pncc->rgrc[2] is the client rectangle

							//DefWindowProc (hwnd, WM_NCCALCSIZE, (WPARAM)m.WParam.ToPointer(), (LPARAM)m.LParam.ToPointer());

							mLeft = GetSystemMetrics(SM_CXFRAME);
							mRight = mLeft;
							mTop = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME);
							mBottom = GetSystemMetrics(SM_CYFRAME);


							pncc->rgrc[0].top = pncc->rgrc[0].top - mTop;
							pncc->rgrc[0].right = pncc->rgrc[0].right + mRight;
							//pncc->rgrc[0].right = pncc->rgrc[0].right;
							pncc->rgrc[0].left = pncc->rgrc[0].left - mLeft;
							//pncc->rgrc[0].left = pncc->rgrc[0].left;
							pncc->rgrc[0].bottom =  pncc->rgrc[0].bottom + mBottom ;

							System::Windows::Forms::Form::WndProc(m);

							break;
							/*
							case WM_NCHITTEST:

							// 分解当前鼠标的坐标
							nPosX = LOWORD(m.LParam.ToPointer()); 
							nPosY = HIWORD(m.LParam.ToPointer());
							if(nPosX >= Left + Width - 3 && nPosY >= Top + Height - 3)
							{
							// 鼠标位置在窗体的右下角附近
							m.Result = IntPtr(HTBOTTOMRIGHT);
							return;
							}        
							else if(nPosX >= Left + Width -3)
							{
							// 鼠标位置在窗体右侧
							m.Result = IntPtr(HTRIGHT);
							return;
							}
							else if(nPosY >= Top + Height - 3)
							{
							// 鼠标位置在窗体下方
							m.Result = IntPtr(HTBOTTOM);
							return;
							}
							// 以上只判断鼠标位置是否在右侧，右下角，下方，所以仅仅当鼠标指针在这三个位置时才会改变成改变大小的形

							状，拖动后可改变大小。
							break;
							*/
						default:
							System::Windows::Forms::Form::WndProc(m);
						}
						return;		
					}

private: System::Void checkShareFileTab_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->sidePanelDisplayed){
				this->ExtendPanel_Click(sender,e);
			 }
		 }
};

}
#endif
