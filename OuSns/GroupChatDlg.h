#pragma once
#include "stdafx.h"


namespace OuSns {

	/// <summary>
	/// GroupChatDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class GroupListTab;
	ref class OusnsLoginUser;
	ref class OusnsGroup;
	public ref class GroupChatDlg : public System::Windows::Forms::Form
	{


	public:
		String^ ressrc;
		System::Reflection::Assembly^ execAssem;
		Resources::ResourceManager^ myres;
		bool isDown;
		OuSns::MouseLocationStyle loactionStyle;
		Point LastMoustLocation;
	private: DevComponents::DotNetBar::ExpandablePanel^  expandablePanel1;
	private: DevComponents::DotNetBar::ExpandablePanel^  expandablePanel2;
	private: DevComponents::AdvTree::AdvTree^  advTree1;
	private: DevComponents::AdvTree::Node^  node1;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector1;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle1;
	public: 
		bool sidePanelDisplayed;
		GroupListTab^ _parent;
		OusnsGroup ^ _group;
		OusnsLoginUser ^ _loginUser;

	public:
		[DllImport("user32.dll")]
		static bool RelaeseCapture(void);
		[DllImport("user32.dll")]
		static bool SendMessage(IntPtr hwnd, int wMsg, int wParam, int lParam);
		delegate System::Void ActionDelegate(String^ notification);
	public:
		GroupChatDlg(GroupListTab^ parentInput, OusnsGroup ^ targetGroup, OusnsLoginUser ^ loginUser);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~GroupChatDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::LabelX^  groupNicknameLabelX;
	protected: 

	protected: 
	private: DevComponents::DotNetBar::PanelEx^  panelEx3;
	private: DevComponents::DotNetBar::ButtonX^  buttonX3;
	private: DevComponents::DotNetBar::ButtonX^  sendFileButton;
	private: DevComponents::DotNetBar::TabItem^  tabItem2;
	private: DevComponents::DotNetBar::TabControlPanel^  tabControlPanel1;
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	private: DevComponents::DotNetBar::PanelEx^  panelEx4;
	private: DevComponents::DotNetBar::TabControl^  groupChatTabControl;
	private: DevComponents::DotNetBar::TabControlPanel^  chatTabPanel;
	private: DevComponents::DotNetBar::ButtonX^  expandButton;
	private: System::Windows::Forms::SplitContainer^  groupChatChattingSplitContainer;
	private: System::Windows::Forms::RichTextBox^  groupChatDisplay;
	private: DevComponents::DotNetBar::PanelEx^  panelEx2;
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;
	private: System::Windows::Forms::RichTextBox^  groupMessageEntry;
	private: DevComponents::DotNetBar::TabItem^  chatTab;
	private: DevComponents::DotNetBar::TabControlPanel^  tabControlPanel3;
	private: DevComponents::DotNetBar::TabItem^  tabItem3;
	private: DevComponents::DotNetBar::LabelX^  groupCategoryLabelX;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::Bar^  rightCornerFunctionBar;
	private: DevComponents::DotNetBar::ButtonItem^  minimizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  maximizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  closeButton;
	private: DevComponents::DotNetBar::TabControlPanel^  sharedFileTabPanel;
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
			this->groupNicknameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->panelEx3 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->buttonX3 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->sendFileButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->tabItem2 = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->tabControlPanel1 = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->panelEx1 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->panelEx4 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->expandablePanel2 = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->advTree1 = (gcnew DevComponents::AdvTree::AdvTree());
			this->node1 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector1 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle1 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->expandablePanel1 = (gcnew DevComponents::DotNetBar::ExpandablePanel());
			this->groupChatTabControl = (gcnew DevComponents::DotNetBar::TabControl());
			this->chatTabPanel = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->expandButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->groupChatChattingSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->groupChatDisplay = (gcnew System::Windows::Forms::RichTextBox());
			this->panelEx2 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->groupMessageEntry = (gcnew System::Windows::Forms::RichTextBox());
			this->chatTab = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->tabControlPanel3 = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->tabItem3 = (gcnew DevComponents::DotNetBar::TabItem(this->components));
			this->groupCategoryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->rightCornerFunctionBar = (gcnew DevComponents::DotNetBar::Bar());
			this->minimizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->maximizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->closeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->sharedFileTabPanel = (gcnew DevComponents::DotNetBar::TabControlPanel());
			this->panelEx3->SuspendLayout();
			this->panelEx1->SuspendLayout();
			this->panelEx4->SuspendLayout();
			this->expandablePanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groupChatTabControl))->BeginInit();
			this->groupChatTabControl->SuspendLayout();
			this->chatTabPanel->SuspendLayout();
			this->groupChatChattingSplitContainer->Panel1->SuspendLayout();
			this->groupChatChattingSplitContainer->Panel2->SuspendLayout();
			this->groupChatChattingSplitContainer->SuspendLayout();
			this->panelEx2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->BeginInit();
			this->SuspendLayout();
			// 
			// groupNicknameLabelX
			// 
			this->groupNicknameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->groupNicknameLabelX->BackgroundStyle->Class = L"";
			this->groupNicknameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupNicknameLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupNicknameLabelX->Location = System::Drawing::Point(70, 8);
			this->groupNicknameLabelX->Name = L"groupNicknameLabelX";
			this->groupNicknameLabelX->SingleLineColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupNicknameLabelX->Size = System::Drawing::Size(85, 20);
			this->groupNicknameLabelX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->groupNicknameLabelX->TabIndex = 10;
			this->groupNicknameLabelX->Text = L"groupName";
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
			this->panelEx3->Location = System::Drawing::Point(-1, 167);
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
			this->buttonX3->Location = System::Drawing::Point(228, 11);
			this->buttonX3->Name = L"buttonX3";
			this->buttonX3->Size = System::Drawing::Size(75, 23);
			this->buttonX3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX3->TabIndex = 1;
			this->buttonX3->Text = L"发送";
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
			// 
			// tabItem2
			// 
			this->tabItem2->AttachedControl = this->tabControlPanel1;
			this->tabItem2->Name = L"tabItem2";
			this->tabItem2->Text = L"查看共享";
			// 
			// tabControlPanel1
			// 
			this->tabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlPanel1->Location = System::Drawing::Point(0, 33);
			this->tabControlPanel1->Name = L"tabControlPanel1";
			this->tabControlPanel1->Padding = System::Windows::Forms::Padding(1);
			this->tabControlPanel1->Size = System::Drawing::Size(341, 429);
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
			this->tabControlPanel1->TabItem = this->tabItem2;
			// 
			// panelEx1
			// 
			this->panelEx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx1->CanvasColor = System::Drawing::Color::Transparent;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->panelEx4);
			this->panelEx1->Controls->Add(this->groupChatTabControl);
			this->panelEx1->Controls->Add(this->groupNicknameLabelX);
			this->panelEx1->Controls->Add(this->groupCategoryLabelX);
			this->panelEx1->Controls->Add(this->pictureBox1);
			this->panelEx1->Controls->Add(this->rightCornerFunctionBar);
			this->panelEx1->Location = System::Drawing::Point(0, 0);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Padding = System::Windows::Forms::Padding(4, 1, 4, 4);
			this->panelEx1->Size = System::Drawing::Size(549, 536);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 5;
			this->panelEx1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GroupChatDlg::GroupChatDlg_MouseMove);
			this->panelEx1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GroupChatDlg::panelEx1_MouseDoubleClick);
			this->panelEx1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GroupChatDlg::MoveDialog_MouseDown);
			this->panelEx1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GroupChatDlg::GroupChatDlg_MouseUp);
			// 
			// panelEx4
			// 
			this->panelEx4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx4->AutoScroll = true;
			this->panelEx4->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx4->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx4->Controls->Add(this->expandablePanel2);
			this->panelEx4->Controls->Add(this->expandablePanel1);
			this->panelEx4->Cursor = System::Windows::Forms::Cursors::Default;
			this->panelEx4->Location = System::Drawing::Point(343, 104);
			this->panelEx4->Margin = System::Windows::Forms::Padding(0);
			this->panelEx4->Name = L"panelEx4";
			this->panelEx4->Size = System::Drawing::Size(200, 429);
			this->panelEx4->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx4->Style->BackColor1->Color = System::Drawing::Color::White;
			this->panelEx4->Style->BackColor2->Color = System::Drawing::Color::White;
			this->panelEx4->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx4->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx4->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx4->Style->GradientAngle = 90;
			this->panelEx4->TabIndex = 14;
			// 
			// expandablePanel2
			// 
			this->expandablePanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->expandablePanel2->CanvasColor = System::Drawing::SystemColors::Control;
			this->expandablePanel2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->expandablePanel2->Controls->Add(this->advTree1);
			this->expandablePanel2->Location = System::Drawing::Point(-1, 216);
			this->expandablePanel2->Margin = System::Windows::Forms::Padding(0);
			this->expandablePanel2->Name = L"expandablePanel2";
			this->expandablePanel2->Size = System::Drawing::Size(200, 212);
			this->expandablePanel2->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel2->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandablePanel2->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->expandablePanel2->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->expandablePanel2->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->expandablePanel2->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandablePanel2->Style->GradientAngle = 90;
			this->expandablePanel2->TabIndex = 1;
			this->expandablePanel2->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel2->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandablePanel2->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->expandablePanel2->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->expandablePanel2->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandablePanel2->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->expandablePanel2->TitleStyle->GradientAngle = 90;
			this->expandablePanel2->TitleText = L"群成员";
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
			this->advTree1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->advTree1->Location = System::Drawing::Point(0, 26);
			this->advTree1->Name = L"advTree1";
			this->advTree1->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
			this->advTree1->NodesConnector = this->nodeConnector1;
			this->advTree1->NodeStyle = this->elementStyle1;
			this->advTree1->PathSeparator = L";";
			this->advTree1->Size = System::Drawing::Size(200, 186);
			this->advTree1->Styles->Add(this->elementStyle1);
			this->advTree1->TabIndex = 1;
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
			// expandablePanel1
			// 
			this->expandablePanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->expandablePanel1->CanvasColor = System::Drawing::SystemColors::Control;
			this->expandablePanel1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->expandablePanel1->Location = System::Drawing::Point(0, 0);
			this->expandablePanel1->Margin = System::Windows::Forms::Padding(0);
			this->expandablePanel1->Name = L"expandablePanel1";
			this->expandablePanel1->Size = System::Drawing::Size(200, 216);
			this->expandablePanel1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandablePanel1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->expandablePanel1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->expandablePanel1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
			this->expandablePanel1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
			this->expandablePanel1->Style->GradientAngle = 90;
			this->expandablePanel1->TabIndex = 0;
			this->expandablePanel1->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
			this->expandablePanel1->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->expandablePanel1->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->expandablePanel1->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
			this->expandablePanel1->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->expandablePanel1->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->expandablePanel1->TitleStyle->GradientAngle = 90;
			this->expandablePanel1->TitleText = L"群动态";
			// 
			// groupChatTabControl
			// 
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupChatTabControl->BackColor = System::Drawing::Color::Transparent;
			this->groupChatTabControl->CanReorderTabs = false;
			this->groupChatTabControl->ColorScheme->TabBackground = System::Drawing::Color::Transparent;
			this->groupChatTabControl->ColorScheme->TabBackground2 = System::Drawing::Color::Transparent;
			this->groupChatTabControl->ColorScheme->TabItemBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), 
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(249))), 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), 
				static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(248))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), 
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(245))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), 
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(247))), 
				1))});
			this->groupChatTabControl->ColorScheme->TabItemHotBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(235))), 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(168))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(89))), 0.45F)), 
				(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(141))), 
				1))});
			this->groupChatTabControl->ColorScheme->TabItemSelectedBackgroundColorBlend->AddRange(gcnew cli::array< DevComponents::DotNetBar::BackgroundColorBlend^  >(4) {(gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::White, 
				0)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				0.45F)), (gcnew DevComponents::DotNetBar::BackgroundColorBlend(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), 
				static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(254))), 
				1))});
			this->groupChatTabControl->Controls->Add(this->chatTabPanel);
			this->groupChatTabControl->Controls->Add(this->tabControlPanel1);
			this->groupChatTabControl->Controls->Add(this->tabControlPanel3);
			this->groupChatTabControl->Cursor = System::Windows::Forms::Cursors::Default;
			this->groupChatTabControl->FixedTabSize = System::Drawing::Size(100, 30);
			this->groupChatTabControl->Location = System::Drawing::Point(2, 71);
			this->groupChatTabControl->Margin = System::Windows::Forms::Padding(0);
			this->groupChatTabControl->MinimumSize = System::Drawing::Size(340, 450);
			this->groupChatTabControl->Name = L"groupChatTabControl";
			this->groupChatTabControl->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->groupChatTabControl->SelectedTabIndex = 0;
			this->groupChatTabControl->Size = System::Drawing::Size(341, 462);
			this->groupChatTabControl->Style = DevComponents::DotNetBar::eTabStripStyle::Office2007Dock;
			this->groupChatTabControl->TabIndex = 13;
			this->groupChatTabControl->TabLayoutType = DevComponents::DotNetBar::eTabLayoutType::FixedWithNavigationBox;
			this->groupChatTabControl->Tabs->Add(this->chatTab);
			this->groupChatTabControl->Tabs->Add(this->tabItem2);
			this->groupChatTabControl->Tabs->Add(this->tabItem3);
			// 
			// chatTabPanel
			// 
			this->chatTabPanel->Controls->Add(this->expandButton);
			this->chatTabPanel->Controls->Add(this->groupChatChattingSplitContainer);
			this->chatTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatTabPanel->Location = System::Drawing::Point(0, 33);
			this->chatTabPanel->Name = L"chatTabPanel";
			this->chatTabPanel->Padding = System::Windows::Forms::Padding(1);
			this->chatTabPanel->Size = System::Drawing::Size(341, 429);
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
			this->expandButton->Size = System::Drawing::Size(6, 427);
			this->expandButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->expandButton->TabIndex = 4;
			// 
			// groupChatChattingSplitContainer
			// 
			this->groupChatChattingSplitContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupChatChattingSplitContainer->BackColor = System::Drawing::Color::White;
			this->groupChatChattingSplitContainer->Cursor = System::Windows::Forms::Cursors::Default;
			this->groupChatChattingSplitContainer->Location = System::Drawing::Point(4, 1);
			this->groupChatChattingSplitContainer->Margin = System::Windows::Forms::Padding(0);
			this->groupChatChattingSplitContainer->Name = L"groupChatChattingSplitContainer";
			this->groupChatChattingSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// groupChatChattingSplitContainer.Panel1
			// 
			this->groupChatChattingSplitContainer->Panel1->BackColor = System::Drawing::Color::White;
			this->groupChatChattingSplitContainer->Panel1->Controls->Add(this->groupChatDisplay);
			// 
			// groupChatChattingSplitContainer.Panel2
			// 
			this->groupChatChattingSplitContainer->Panel2->Controls->Add(this->panelEx3);
			this->groupChatChattingSplitContainer->Panel2->Controls->Add(this->panelEx2);
			this->groupChatChattingSplitContainer->Panel2->Controls->Add(this->groupMessageEntry);
			this->groupChatChattingSplitContainer->Size = System::Drawing::Size(328, 426);
			this->groupChatChattingSplitContainer->SplitterDistance = 213;
			this->groupChatChattingSplitContainer->SplitterWidth = 1;
			this->groupChatChattingSplitContainer->TabIndex = 3;
			// 
			// groupChatDisplay
			// 
			this->groupChatDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupChatDisplay->BackColor = System::Drawing::SystemColors::Window;
			this->groupChatDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->groupChatDisplay->BulletIndent = 4;
			this->groupChatDisplay->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupChatDisplay->Location = System::Drawing::Point(9, 10);
			this->groupChatDisplay->Margin = System::Windows::Forms::Padding(0);
			this->groupChatDisplay->Name = L"groupChatDisplay";
			this->groupChatDisplay->ReadOnly = true;
			this->groupChatDisplay->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->groupChatDisplay->Size = System::Drawing::Size(308, 199);
			this->groupChatDisplay->TabIndex = 11;
			this->groupChatDisplay->Text = L"";
			// 
			// panelEx2
			// 
			this->panelEx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelEx2->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx2->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx2->Controls->Add(this->buttonX1);
			this->panelEx2->Cursor = System::Windows::Forms::Cursors::Default;
			this->panelEx2->Location = System::Drawing::Point(-5, -1);
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
			this->buttonX1->Location = System::Drawing::Point(53, 4);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(20, 20);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 1;
			// 
			// groupMessageEntry
			// 
			this->groupMessageEntry->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupMessageEntry->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->groupMessageEntry->BulletIndent = 4;
			this->groupMessageEntry->EnableAutoDragDrop = true;
			this->groupMessageEntry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupMessageEntry->Location = System::Drawing::Point(9, 29);
			this->groupMessageEntry->Margin = System::Windows::Forms::Padding(10);
			this->groupMessageEntry->Name = L"groupMessageEntry";
			this->groupMessageEntry->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->groupMessageEntry->Size = System::Drawing::Size(305, 134);
			this->groupMessageEntry->TabIndex = 13;
			this->groupMessageEntry->Text = L"";
			// 
			// chatTab
			// 
			this->chatTab->AttachedControl = this->chatTabPanel;
			this->chatTab->Name = L"chatTab";
			this->chatTab->Text = L"聊  天";
			// 
			// tabControlPanel3
			// 
			this->tabControlPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlPanel3->Location = System::Drawing::Point(0, 33);
			this->tabControlPanel3->Name = L"tabControlPanel3";
			this->tabControlPanel3->Padding = System::Windows::Forms::Padding(1);
			this->tabControlPanel3->Size = System::Drawing::Size(341, 429);
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
			// groupCategoryLabelX
			// 
			this->groupCategoryLabelX->AutoSize = true;
			// 
			// 
			// 
			this->groupCategoryLabelX->BackgroundStyle->Class = L"";
			this->groupCategoryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->groupCategoryLabelX->Location = System::Drawing::Point(70, 37);
			this->groupCategoryLabelX->Name = L"groupCategoryLabelX";
			this->groupCategoryLabelX->Size = System::Drawing::Size(56, 16);
			this->groupCategoryLabelX->TabIndex = 11;
			this->groupCategoryLabelX->Text = L"category";
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
			this->minimizeButton->Click += gcnew System::EventHandler(this, &GroupChatDlg::minimizeButton_Click);
			// 
			// maximizeButton
			// 
			this->maximizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->maximizeButton->ImagePaddingHorizontal = 0;
			this->maximizeButton->ImagePaddingVertical = 0;
			this->maximizeButton->Name = L"maximizeButton";
			this->maximizeButton->Text = L"大";
			this->maximizeButton->Click += gcnew System::EventHandler(this, &GroupChatDlg::maximizeButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->closeButton->ImagePaddingHorizontal = 0;
			this->closeButton->ImagePaddingVertical = 0;
			this->closeButton->Name = L"closeButton";
			this->closeButton->Text = L"关闭";
			this->closeButton->Click += gcnew System::EventHandler(this, &GroupChatDlg::closeButton_Click);
			// 
			// sharedFileTabPanel
			// 
			this->sharedFileTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sharedFileTabPanel->Location = System::Drawing::Point(0, 0);
			this->sharedFileTabPanel->Name = L"sharedFileTabPanel";
			this->sharedFileTabPanel->Padding = System::Windows::Forms::Padding(1);
			this->sharedFileTabPanel->Size = System::Drawing::Size(550, 536);
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
			this->sharedFileTabPanel->TabIndex = 4;
			// 
			// GroupChatDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(550, 536);
			this->ControlBox = false;
			this->Controls->Add(this->panelEx1);
			this->Controls->Add(this->sharedFileTabPanel);
			this->MinimumSize = System::Drawing::Size(450, 536);
			this->Name = L"GroupChatDlg";
			this->Text = L"GroupChatDlg";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GroupChatDlg::GroupChatDlg_FormClosing);
			this->panelEx3->ResumeLayout(false);
			this->panelEx1->ResumeLayout(false);
			this->panelEx1->PerformLayout();
			this->panelEx4->ResumeLayout(false);
			this->expandablePanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groupChatTabControl))->EndInit();
			this->groupChatTabControl->ResumeLayout(false);
			this->chatTabPanel->ResumeLayout(false);
			this->groupChatChattingSplitContainer->Panel1->ResumeLayout(false);
			this->groupChatChattingSplitContainer->Panel2->ResumeLayout(false);
			this->groupChatChattingSplitContainer->ResumeLayout(false);
			this->panelEx2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:System::Void GroupChatDlg::ExtendPanel_Click(System::Object^  sender, System::EventArgs^  e);

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

	private: System::Void GroupChatDlg_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 Point mouseLocation = Point(Control::MousePosition.X - this->Location.X, Control::MousePosition.Y - this->Location.Y);
				 this->loactionStyle = OuSns::GetLocationStyle(mouseLocation,this);
				 this->Cursor = OuSns::GetCursorByMouseLocationStyle(this->loactionStyle);
				 if(this->isDown){
					 ReleaseCapture();
					 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MOVE+HTCAPTION,0);
				 }

			 }
	private: System::Void GroupChatDlg_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
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
		
	public: System::Void PushNewMessage(ChatMessage ^ msg);

			System::Void AppendTextToChatDisplay(String ^ content);
			
			System::String ^ ExtractTextFromRTF(String ^ rtfString);
			System::String ^ AppendTextToRTF(String ^ rtfString, String ^ text);
			System::Void UpdateGroupMemberList();
private: System::Void GroupChatDlg_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
		 System::Void UpdateGroupMemberStatus();
};
}
