
#ifndef MAIN_DLG
#define MAIN_DLG

#include "stdafx.h"

//#include "FriendListTab.h"
//#include "Communication.h"

//#include "FriendChatDlg.h"
//#include "OusnsLoginUser.h"


//ref class NewsUpdateTab;

namespace OuSns {

	/// <summary>
	/// MainDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class friendChatDlg;
	ref class GroupChatDlg;
	ref class FriendListTab;
	ref class DownloadingJob;
	ref class MessageCreator;
	ref class OusnsLoginUser;
	ref class SharedFolder;
	ref class OusnsGroup;
	ref class SharedObject;
	ref class SearchResult;
	ref class Communication;
	//The tabs
	ref class NewsUpdateTab;
	ref class PersonalSettingTab;
	ref class GroupListTab;
	ref class FocusUserTab;
	ref class RecommendFocusTab;
	ref class DownloadFileTab;
	ref class ShareFileListTab;
	ref class SearchUserResultForm;
	//public ref class MainDlg : public System::Windows::Forms::Form
	public ref class MainDlg : DevComponents::DotNetBar::Office2007Form
	{

	public:
		MainDlg(OusnsLoginUser ^ usr, Communication^ comm);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MainDlg()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 



		// BEGIN Parameters added manually
		//Common part
	public:
		String^ ressrc;
		System::Reflection::Assembly^ execAssem;
		Resources::ResourceManager^ myres;
		bool isDown;
		OuSns::MouseLocationStyle loactionStyle;
		Point LastMoustLocation;
	public: 
		// The currently login user information
		OusnsLoginUser ^ loginUser;


		int pending_msg_total;



		//The Tabs:
		NewsUpdateTab^ newNewsUpdateTab;

		FriendListTab^ newFriendListTab;
		PersonalSettingTab^ newPersonalSettingTab;
		GroupListTab^ newGroupListTab;
		RecommendFocusTab^ newRecommendFocusTab;
		DownloadFileTab^ newDownloadFileTab;
		FocusUserTab^ newFocusUserTab;
		ShareFileListTab^ newShareFileListTab;

		Form^ currentActivePage;

		SearchUserResultForm^ searchUserResultForm;

		MessageCreator^ msgCreator;



		delegate System::Void NewMessageDelegate(ChatMessage ^ msg);
		delegate System::Void UpdateInfoDelegate(unsigned int srcID);
		delegate System::Void ActionDelegate();
		delegate System::Void ParamActionDelegate(LinkedList<Object^>^ params);
		delegate System::Void SearchActionDelegate(int totalResult, int offset, LinkedList<SearchResult^>^ searchResult);


		// The communication instance passed from LoginDlg
		Communication^ comm;

		/*
		* The current files shared by the login user, the root is the virtual root.
		* When the user add a file into the sharing list, it will add to the root
		* Problem to be solved here: When the user add a subfolder that already exist 
		* in the sharing file list.
		*/
		SharedFolder^ shareRoot;


		/*
		* The system setting, fill this variable when open the MainDlg
		*/
		Dictionary<Object^, Object^> systemSetting;

		/*
		* Can use this to store the search result
		*/
		Dictionary<String^, String^> searchResultDic;

		/*
		* This will be used to display the friend sharing file list
		*/
		LinkedList<SharedObject^>^ friendSharedFileLinkedList;




		bool friendListTabInitiated;

		//Dictionary<String^,DownloadingJob^>^ downloadedJobDict;
	public:
		LinkedList<DownloadingJob^>^ downloadedJobArray;
		bool downloadedJobArrayModified;
		Dictionary<String^,DownloadingJob^>^ downloadingJobDict;
		bool downloadingJobDictModified;


		//END

	private: DevComponents::DotNetBar::LabelX^  signatureLabel;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControl^  mainTabWindow;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel2;
	private: DevComponents::DotNetBar::SuperTabItem^  newUpdatesTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel6;
	private: DevComponents::DotNetBar::SuperTabItem^  focusUserTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel7;
	private: DevComponents::DotNetBar::SuperTabItem^  recommendFocusTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel8;
	private: DevComponents::DotNetBar::SuperTabItem^  personalSettingTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel9;
	private: DevComponents::DotNetBar::SuperTabItem^  systemSettingTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel11;
	private: DevComponents::DotNetBar::SuperTabItem^  checkUpdates;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel10;
	private: DevComponents::DotNetBar::SuperTabItem^  downloadFileTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel5;
	private: DevComponents::DotNetBar::SuperTabItem^  shareFileListTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel3;
	public: DevComponents::DotNetBar::SuperTabItem^  friendListTab;
	private: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel4;
	public: 
	public: DevComponents::DotNetBar::SuperTabItem^  groupListTab;
	private: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: 
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  statusComboBoxEx;
	private: DevComponents::Editors::ComboItem^  statusOfflineComboItem;
	private: DevComponents::Editors::ComboItem^  statusOnlineComboItem;
	private: DevComponents::Editors::ComboItem^  statusAwayComboItem;
	private: DevComponents::Editors::ComboItem^  statusBusyComboItem;
	private: DevComponents::Editors::ComboItem^  statusInvisibleComboItem;
	private: DevComponents::DotNetBar::Controls::ProgressBarX^  experienceProgressBar;
	private: DevComponents::DotNetBar::LabelX^  ouIDLabel;
	private: DevComponents::DotNetBar::LabelX^  nicknameLabel;
	private: System::Windows::Forms::PictureBox^  displayPictureBox;
	private: DevComponents::DotNetBar::LabelItem^  labelItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem2;
	private: DevComponents::DotNetBar::LabelItem^  labelItem3;
	private: DevComponents::DotNetBar::LabelItem^  labelItem4;
	private: DevComponents::DotNetBar::LabelItem^  labelItem5;


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
			this->signatureLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->mainTabWindow = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel2 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->newUpdatesTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel10 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->downloadFileTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel11 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->checkUpdates = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel9 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->systemSettingTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel8 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->personalSettingTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel7 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->recommendFocusTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel6 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->focusUserTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel5 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->shareFileListTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel4 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->groupListTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel3 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->friendListTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->statusComboBoxEx = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->statusOfflineComboItem = (gcnew DevComponents::Editors::ComboItem());
			this->statusOnlineComboItem = (gcnew DevComponents::Editors::ComboItem());
			this->statusAwayComboItem = (gcnew DevComponents::Editors::ComboItem());
			this->statusBusyComboItem = (gcnew DevComponents::Editors::ComboItem());
			this->statusInvisibleComboItem = (gcnew DevComponents::Editors::ComboItem());
			this->experienceProgressBar = (gcnew DevComponents::DotNetBar::Controls::ProgressBarX());
			this->ouIDLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->nicknameLabel = (gcnew DevComponents::DotNetBar::LabelX());
			this->displayPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->labelItem1 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem2 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem3 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem4 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->labelItem5 = (gcnew DevComponents::DotNetBar::LabelItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainTabWindow))->BeginInit();
			this->mainTabWindow->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->displayPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// signatureLabel
			// 
			this->signatureLabel->AutoSize = true;
			// 
			// 
			// 
			this->signatureLabel->BackgroundStyle->Class = L"";
			this->signatureLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->signatureLabel->Location = System::Drawing::Point(6, 107);
			this->signatureLabel->Name = L"signatureLabel";
			this->signatureLabel->Size = System::Drawing::Size(62, 16);
			this->signatureLabel->TabIndex = 5;
			this->signatureLabel->Text = L"signature";
			// 
			// mainTabWindow
			// 
			this->mainTabWindow->CloseButtonOnTabsAlwaysDisplayed = false;
			// 
			// 
			// 
			// 
			// 
			// 
			this->mainTabWindow->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->mainTabWindow->ControlBox->MenuBox->Name = L"";
			this->mainTabWindow->ControlBox->MenuBox->Visible = false;
			this->mainTabWindow->ControlBox->Name = L"";
			this->mainTabWindow->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->mainTabWindow->ControlBox->MenuBox, 
				this->mainTabWindow->ControlBox->CloseBox});
			this->mainTabWindow->Controls->Add(this->superTabControlPanel2);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel10);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel11);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel9);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel8);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel7);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel6);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel5);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel4);
			this->mainTabWindow->Controls->Add(this->superTabControlPanel3);
			this->mainTabWindow->Controls->Add(this->groupBox1);
			this->mainTabWindow->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mainTabWindow->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainTabWindow->FixedTabSize = System::Drawing::Size(197, 35);
			this->mainTabWindow->Location = System::Drawing::Point(0, 0);
			this->mainTabWindow->Name = L"mainTabWindow";
			this->mainTabWindow->ReorderTabsEnabled = false;
			this->mainTabWindow->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->mainTabWindow->SelectedTabIndex = 6;
			this->mainTabWindow->Size = System::Drawing::Size(792, 573);
			this->mainTabWindow->TabAlignment = DevComponents::DotNetBar::eTabStripAlignment::Left;
			this->mainTabWindow->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->mainTabWindow->TabIndex = 2;
			this->mainTabWindow->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(15) {this->labelItem1, this->labelItem2, 
				this->labelItem3, this->labelItem4, this->newUpdatesTab, this->friendListTab, this->groupListTab, this->shareFileListTab, this->downloadFileTab, 
				this->labelItem5, this->focusUserTab, this->recommendFocusTab, this->personalSettingTab, this->systemSettingTab, this->checkUpdates});
			this->mainTabWindow->Text = L"superTabControl1";
			this->mainTabWindow->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel2
			// 
			this->superTabControlPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel2->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel2->Name = L"superTabControlPanel2";
			this->superTabControlPanel2->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel2->TabIndex = 2;
			this->superTabControlPanel2->TabItem = this->newUpdatesTab;
			this->superTabControlPanel2->Visible = false;
			// 
			// newUpdatesTab
			// 
			this->newUpdatesTab->AttachedControl = this->superTabControlPanel2;
			this->newUpdatesTab->CanCustomize = false;
			this->newUpdatesTab->CloseButtonVisible = false;
			this->newUpdatesTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->newUpdatesTab->GlobalItem = false;
			this->newUpdatesTab->Name = L"newUpdatesTab";
			this->newUpdatesTab->Text = L"最新动态";
			this->newUpdatesTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel10
			// 
			this->superTabControlPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel10->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel10->Name = L"superTabControlPanel10";
			this->superTabControlPanel10->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel10->TabIndex = 10;
			this->superTabControlPanel10->TabItem = this->downloadFileTab;
			// 
			// downloadFileTab
			// 
			this->downloadFileTab->AttachedControl = this->superTabControlPanel10;
			this->downloadFileTab->CanCustomize = false;
			this->downloadFileTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->downloadFileTab->GlobalItem = false;
			this->downloadFileTab->Name = L"downloadFileTab";
			this->downloadFileTab->Text = L"文件下载";
			this->downloadFileTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel11
			// 
			this->superTabControlPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel11->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel11->Name = L"superTabControlPanel11";
			this->superTabControlPanel11->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel11->TabIndex = 11;
			this->superTabControlPanel11->TabItem = this->checkUpdates;
			// 
			// checkUpdates
			// 
			this->checkUpdates->AttachedControl = this->superTabControlPanel11;
			this->checkUpdates->CanCustomize = false;
			this->checkUpdates->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkUpdates->GlobalItem = false;
			this->checkUpdates->Name = L"checkUpdates";
			this->checkUpdates->Text = L"检查升级";
			this->checkUpdates->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel9
			// 
			this->superTabControlPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel9->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel9->Name = L"superTabControlPanel9";
			this->superTabControlPanel9->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel9->TabIndex = 9;
			this->superTabControlPanel9->TabItem = this->systemSettingTab;
			// 
			// systemSettingTab
			// 
			this->systemSettingTab->AttachedControl = this->superTabControlPanel9;
			this->systemSettingTab->CanCustomize = false;
			this->systemSettingTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->systemSettingTab->GlobalItem = false;
			this->systemSettingTab->Name = L"systemSettingTab";
			this->systemSettingTab->Text = L"系统设置";
			this->systemSettingTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel8
			// 
			this->superTabControlPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel8->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel8->Name = L"superTabControlPanel8";
			this->superTabControlPanel8->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel8->TabIndex = 8;
			this->superTabControlPanel8->TabItem = this->personalSettingTab;
			// 
			// personalSettingTab
			// 
			this->personalSettingTab->AttachedControl = this->superTabControlPanel8;
			this->personalSettingTab->CanCustomize = false;
			this->personalSettingTab->CloseButtonVisible = false;
			this->personalSettingTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->personalSettingTab->GlobalItem = false;
			this->personalSettingTab->Name = L"personalSettingTab";
			this->personalSettingTab->Text = L"个人设置";
			this->personalSettingTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel7
			// 
			this->superTabControlPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel7->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel7->Name = L"superTabControlPanel7";
			this->superTabControlPanel7->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel7->TabIndex = 7;
			this->superTabControlPanel7->TabItem = this->recommendFocusTab;
			// 
			// recommendFocusTab
			// 
			this->recommendFocusTab->AttachedControl = this->superTabControlPanel7;
			this->recommendFocusTab->CanCustomize = false;
			this->recommendFocusTab->CloseButtonVisible = false;
			this->recommendFocusTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recommendFocusTab->GlobalItem = false;
			this->recommendFocusTab->Name = L"recommendFocusTab";
			this->recommendFocusTab->Text = L"推荐关注";
			this->recommendFocusTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel6
			// 
			this->superTabControlPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel6->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel6->Name = L"superTabControlPanel6";
			this->superTabControlPanel6->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel6->TabIndex = 6;
			this->superTabControlPanel6->TabItem = this->focusUserTab;
			// 
			// focusUserTab
			// 
			this->focusUserTab->AttachedControl = this->superTabControlPanel6;
			this->focusUserTab->CanCustomize = false;
			this->focusUserTab->CloseButtonVisible = false;
			this->focusUserTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->focusUserTab->GlobalItem = false;
			this->focusUserTab->Name = L"focusUserTab";
			this->focusUserTab->Text = L"我的关注";
			this->focusUserTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel5
			// 
			this->superTabControlPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel5->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel5->Name = L"superTabControlPanel5";
			this->superTabControlPanel5->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel5->TabIndex = 5;
			this->superTabControlPanel5->TabItem = this->shareFileListTab;
			// 
			// shareFileListTab
			// 
			this->shareFileListTab->AttachedControl = this->superTabControlPanel5;
			this->shareFileListTab->CanCustomize = false;
			this->shareFileListTab->CloseButtonVisible = false;
			this->shareFileListTab->GlobalItem = false;
			this->shareFileListTab->Name = L"shareFileListTab";
			this->shareFileListTab->Text = L"共享文件";
			this->shareFileListTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel4
			// 
			this->superTabControlPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel4->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel4->Name = L"superTabControlPanel4";
			this->superTabControlPanel4->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel4->TabIndex = 4;
			this->superTabControlPanel4->TabItem = this->groupListTab;
			// 
			// groupListTab
			// 
			this->groupListTab->AttachedControl = this->superTabControlPanel4;
			this->groupListTab->CanCustomize = false;
			this->groupListTab->CloseButtonVisible = false;
			this->groupListTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->groupListTab->GlobalItem = false;
			this->groupListTab->Name = L"groupListTab";
			this->groupListTab->Text = L"我的群组";
			this->groupListTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// superTabControlPanel3
			// 
			this->superTabControlPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel3->Location = System::Drawing::Point(199, 0);
			this->superTabControlPanel3->Name = L"superTabControlPanel3";
			this->superTabControlPanel3->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel3->TabIndex = 3;
			this->superTabControlPanel3->TabItem = this->friendListTab;
			// 
			// friendListTab
			// 
			this->friendListTab->AttachedControl = this->superTabControlPanel3;
			this->friendListTab->CanCustomize = false;
			this->friendListTab->CloseButtonVisible = false;
			this->friendListTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->friendListTab->GlobalItem = false;
			this->friendListTab->Name = L"friendListTab";
			this->friendListTab->Text = L"我的好友";
			this->friendListTab->Click += gcnew System::EventHandler(this, &MainDlg::Tab_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->signatureLabel);
			this->groupBox1->Controls->Add(this->statusComboBoxEx);
			this->groupBox1->Controls->Add(this->experienceProgressBar);
			this->groupBox1->Controls->Add(this->ouIDLabel);
			this->groupBox1->Controls->Add(this->nicknameLabel);
			this->groupBox1->Controls->Add(this->displayPictureBox);
			this->groupBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 136);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// statusComboBoxEx
			// 
			this->statusComboBoxEx->DisplayMember = L"Text";
			this->statusComboBoxEx->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->statusComboBoxEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->statusComboBoxEx->FormattingEnabled = true;
			this->statusComboBoxEx->ItemHeight = 15;
			this->statusComboBoxEx->Items->AddRange(gcnew cli::array< System::Object^  >(5) {this->statusOfflineComboItem, this->statusOnlineComboItem, 
				this->statusAwayComboItem, this->statusBusyComboItem, this->statusInvisibleComboItem});
			this->statusComboBoxEx->Location = System::Drawing::Point(89, 81);
			this->statusComboBoxEx->Name = L"statusComboBoxEx";
			this->statusComboBoxEx->Size = System::Drawing::Size(65, 21);
			this->statusComboBoxEx->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->statusComboBoxEx->TabIndex = 4;
			this->statusComboBoxEx->SelectedIndexChanged += gcnew System::EventHandler(this, &MainDlg::ChangeOnlineStatus);
			// 
			// statusOfflineComboItem
			// 
			this->statusOfflineComboItem->Text = L"离线";
			// 
			// statusOnlineComboItem
			// 
			this->statusOnlineComboItem->Text = L"在线";
			// 
			// statusAwayComboItem
			// 
			this->statusAwayComboItem->Text = L"离开";
			// 
			// statusBusyComboItem
			// 
			this->statusBusyComboItem->Text = L"忙碌";
			// 
			// statusInvisibleComboItem
			// 
			this->statusInvisibleComboItem->Text = L"隐身";
			// 
			// experienceProgressBar
			// 
			// 
			// 
			// 
			this->experienceProgressBar->BackgroundStyle->Class = L"";
			this->experienceProgressBar->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->experienceProgressBar->Location = System::Drawing::Point(89, 65);
			this->experienceProgressBar->Name = L"experienceProgressBar";
			this->experienceProgressBar->Size = System::Drawing::Size(90, 10);
			this->experienceProgressBar->TabIndex = 3;
			this->experienceProgressBar->Text = L"progressBarX1";
			this->experienceProgressBar->Value = 30;
			// 
			// ouIDLabel
			// 
			this->ouIDLabel->AutoSize = true;
			// 
			// 
			// 
			this->ouIDLabel->BackgroundStyle->Class = L"";
			this->ouIDLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->ouIDLabel->Location = System::Drawing::Point(89, 41);
			this->ouIDLabel->Name = L"ouIDLabel";
			this->ouIDLabel->Size = System::Drawing::Size(68, 16);
			this->ouIDLabel->TabIndex = 2;
			this->ouIDLabel->Text = L"OuID label";
			// 
			// nicknameLabel
			// 
			this->nicknameLabel->AutoSize = true;
			// 
			// 
			// 
			this->nicknameLabel->BackgroundStyle->Class = L"";
			this->nicknameLabel->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->nicknameLabel->Location = System::Drawing::Point(89, 13);
			this->nicknameLabel->Name = L"nicknameLabel";
			this->nicknameLabel->Size = System::Drawing::Size(56, 16);
			this->nicknameLabel->TabIndex = 1;
			this->nicknameLabel->Text = L"nickname";
			// 
			// displayPictureBox
			// 
			this->displayPictureBox->Location = System::Drawing::Point(3, 12);
			this->displayPictureBox->Name = L"displayPictureBox";
			this->displayPictureBox->Size = System::Drawing::Size(80, 80);
			this->displayPictureBox->TabIndex = 0;
			this->displayPictureBox->TabStop = false;
			// 
			// labelItem1
			// 
			this->labelItem1->Enabled = false;
			this->labelItem1->Name = L"labelItem1";
			// 
			// labelItem2
			// 
			this->labelItem2->Enabled = false;
			this->labelItem2->Name = L"labelItem2";
			// 
			// labelItem3
			// 
			this->labelItem3->Enabled = false;
			this->labelItem3->Name = L"labelItem3";
			// 
			// labelItem4
			// 
			this->labelItem4->Enabled = false;
			this->labelItem4->Name = L"labelItem4";
			// 
			// labelItem5
			// 
			this->labelItem5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->labelItem5->Enabled = false;
			this->labelItem5->Name = L"labelItem5";
			// 
			// MainDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 573);
			this->Controls->Add(this->mainTabWindow);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MainDlg";
			this->Text = L"MainDlg";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainDlg::MainDlg_FormClosed);
			this->ResizeEnd += gcnew System::EventHandler(this, &MainDlg::MainDlg_ResizeEnd);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainTabWindow))->EndInit();
			this->mainTabWindow->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->displayPictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	public: System::Void MainDlg::PushChatMessageToUI(ChatMessage ^ msg);
			System::Void MainDlg::PushStatusChangeToUI(int srcID, int status);
			System::Void MainDlg::DisplayUnreadCount(unsigned int srcID);
	private:System::Void MainDlg::ChangeOnlineStatus(Object^ sender, EventArgs^ e);
	private: System::Void LogoffProcedure();
	private: System::Void MainDlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) ;
			 /*
			 *	Define the behaviour of close button. When the close button is clicked, the application is shut down
			 *  before sending a change status request (offline).
			 */

	public:
		System::Void MainDlg::CloseButtonClick(Object^ sender, EventArgs^ e);
		/*-------------------------------MainDlgUIAPI.cpp------------------------------------*/


		/*
		* This function will change the users status to the desired one
		* This function will change the user status to the desired one.
		* This function will take ONLY 2 params:
		* OuID, the type is unsigned int, this is the user that will be 
		*		changed (This ID will be validated throught the login user friend list.
		* Status, type is int, it is the status that will be changed to.
		*/
		System::Void MainDlg::ChangeUserStatus(LinkedList<Object^>^ params);

		/*
		* This function will be called when there is a response for the request that search specific group
		* This function will dynamic cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
		* Each Object represent a search result entry. 
		*/
		//System::Void MainDlg::DisplaySearchGroupResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults);

		/*
		* This function will be called when there is a response for the request that search specific group
		* This function will dynamically cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header’s name (same as the tags in the XML).
		* Each Object represent a search result entry.
		*/
		System::Void MainDlg::DisplaySearchFileResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults);

		/*
		* This function will be called when there is a response for the request that the login user is querying one of his friends personal information, like the birthday.
		* This function will take ONLY 1 param.
		* ousnsFriend, the type is OusnsFriend. This function will dynamically cast the first element in the param to OusnsFriend type and display this friend personal information in the UI.
		*/
		//System::Void MainDlg::DisplayFriendPersonalInfo(LinkedList<Object^>^ params);

		/*
		* This function will be called when there is a response for the request that the login user is changing one of his personal information, like the birthday.
		* This function will take ONLY 1 param.
		* ousnsLoginUser, the type is OusnsLoginUser. This function will dynamically cast the first element in the param to OusnsLoginUser type and display this user’s personal information in the UI.
		*/
		System::Void MainDlg::DisplayLoginUserPersonalInfo(LinkedList<Object^>^ params);

		/* 
		*  This function will be called when there is a response for the request that the login user is querying one of his joined group information, like the group announcement.
		* This function will take ONLY 1 param 
		* ousnsGroup, the type is OusnsGroup. This function will dynamically cast the first element in the param to OusnsGroup type and display this group information in the UI.
		*/
		//System::Void MainDlg::DisplayGroupInfo(LinkedList<Object^>^ params);


		/* 
		* This function will be called when there is a response for the request that the login user is querying one of his friends/focus user/ group member’s sharing file list.
		* This function will take ONLY 2 params.
		* ouID, the type is unisigned int. This function will dynamically cast the first element in the param to the OuID.
		* sharedFileList, the type is LinkedList<SharedFile^>^, the function will dynamically cast the second element in the param to LinkedList<SharedFile^>^
		* These information will be update in userShareFileList variable kept in the MainDlg, update to the UI if necessary (like when the user is browsing this user’s sharing file list)
		*/
		System::Void MainDlg::UpdateUserSharingFileList(LinkedList<Object^>^ params);

		/*
		* This function will be called when there is a response for the request that the login user is querying one of his group sharing file list.
		* This function will take ONLY 2 params.
		*		ouID, the type is unisigned int. This function will dynamically cast the first element in the param to the OuID of the group.
		*		sharedFileList, the type is LinkedList<SharedFile^>^, the function will dynamically cast the second element in the param to LinkedList<SharedFile^>^
		* These information will be update in groupShareFileList variable kept in the MainDlg, update to the UI if necessary (like when the user is browsing this group’s sharing file list)
		*/
		System::Void MainDlg::UpdateGroupSharingFileList(LinkedList<Object^>^ params);

		/*
		* This function will be called if the user request log off (send logoff request) or  the network connection was unavailable (like rise the exception ) or the user changed his status to offline.
		*/
		System::Void MainDlg::SwitchToOffLine(void);

		//System::Void MainDlg::UpdateGroupListToUI();

		/*
		* This function will be called when the other thread need to update the gridview content
		* This function will take ONLY 4 params.
		*		datagridview, the gridview will be modified
		*		datagridviewrow, the row will be modified, added or deleted, this can be nullptr if the action is delete
		*		rowIndex, the index of the row
		*		action, the type of action in OuSns::ModifyAction
		* These information will be update in groupShareFileList variable kept in the MainDlg, update to the UI if necessary (like when the user is browsing this group’s sharing file list)
		*/
		System::Void ModifyDataGridViewRows(LinkedList<Object^>^ params);




		/*-------------------------------MainDlgFriendTab.cpp------------------------------------*/

	public: System::Void MainDlg::ListClickAutoCheck(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) ;
			/*
			private: System::Void MainDlg::OpenFriendChatDlg(Object^ sender, EventArgs^ e);

			public: System::Void MainDlg::RemoveTargetFileTransferJob(unsigned srcID, String ^ fileName, String ^ md5, int reason);

			private: System::Void searchFriendOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) ;
			private: System::Void searchFriendEmailRadioButton_Click(System::Object^  sender, System::EventArgs^  e);
			private: System::Void searchFriendNicknameRadioButton_Click(System::Object^  sender, System::EventArgs^  e) ;
			*/
			/*
			* this function doing the adding friend request
			*/
			/*	private: System::Void searchFriendAddFriendButton_Click(System::Object^  sender, System::EventArgs^  e);

			private: System::Void InitializeFriendListTab(void);



			private: System::Void searchFriendSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
			private: System::Void InitializeSearchFriendSearchResult(void);
			private: System::Void searchFriendPreviousPageLabelX_Click(System::Object^  sender, System::EventArgs^  e);

			private: System::Void searchFriendNextPageLabelX_Click(System::Object^  sender, System::EventArgs^  e) ;
			private: System::Void searchFriendResultList_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) ;
			private: System::Void QueryFriendPersonalInfo(System::Object^  sender, System::EventArgs^  e) ;

			private: System::Void removeFriendToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void MainDlg::FriendListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			public: System::Void MainDlg::ListClickAutoCheck(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) ;
			*/
			/*
			* This function will be used to find the checked button item in the friend list
			*/
			/*		 OusnsFriend^ MainDlg::FindSelectedFriend(void);
			private: System::Void FriendButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			*/
			/*-------------------------------MainDlgPersonalInfoTab.cpp------------------------------------*/

	//private: System::Void personalSettingTab_Click(System::Object^  sender, System::EventArgs^  e) ;

			 /*-------------------------------MainDlgGroupTab.cpp------------------------------------*/

			 /*
			 System::Void MainDlg::InitializeSearchGroupSearchResult(void);
			 System::Void joinGroupTab_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void searchGroupOuidRadioButton_Click(System::Object^  sender, System::EventArgs^  e) ;
			 System::Void searchGroupKeywordRadioButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void MainDlg::GroupListRightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 */
			 /*
			 * This function will be used when double click the group item button and open the group dialog
			 */
			 /*
			 System::Void MainDlg::OpenGroupChatDlg(Object^ sender, EventArgs^ e);
			 private: System::Void createGroupTabGroupTagTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void createGroupSuperTabItem_Click(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void InitializeCreateGroupTab(void);
			 private: System::Void createGroupTabSearchContactTextBoxX_Enter(System::Object^  sender, System::EventArgs^  e);

			 private: System::Void createGroupTabSearchContactTextBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) ;
			 private: System::Void UpdateCreateGroupTabContactList(void);
			 System::Void createGroupTabAddMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void createGroupTabRemoveMemberButtonX_Click(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void createGroupTabCreateGroupButtonX_Click(System::Object^  sender, System::EventArgs^  e);
			 */
			 //This function will set the controls in the create Group tab to the flag value;
			 /*		 System::Void createGroupTabEnableControls(bool flag);
			 private: System::Void exitGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 */
			 /*
			 * This function will be used to find the checked button item in the friend list
			 */
			 /*		 OusnsGroup^ MainDlg::FindSelectedGroup(void);
			 private: System::Void createGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void GroupButtonItem_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			 private: System::Void myGroupListTabRefreshButtonX_Click(System::Object^  sender, System::EventArgs^  e) ;
			 private: System::Void deleteGroupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 */
			 /*-------------------------------MainDlgFileTab.cpp------------------------------------*/
			 //private: System::Void fileTransferDataGridViewX_SelectionChanged(System::Object^  sender, System::EventArgs^  e);
			 /* 
			 * This function will auto enable or disable the buttons based on the selection in the 
			 * file transfer datagridview
			 */
			 //private: System::Void FileTransferSetButtonsBasedOnSelection(void);
			 /*
			 * This function will return the bitmap of the picture for the status
			 */
			 //public:  Bitmap^ GetJobStatusBitmap(OuSns::DownloadJobStatus status);
			 //		 Bitmap^ GetProgressBarBitmap(double progress,int width);
			 /*System::Void SaveDownloadingList();
			 System::Void SaveDownloadedList();
			 System::Void LoadDownloadList();
			 */
	private: System::Void Tab_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void MainDlg_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
			 //this->currentActivePage->WindowState = FormWindowState::Maximized;
		 }
};
}
#endif