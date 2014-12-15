#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// DownloadFileTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	ref class MessageCreator;
	public ref class DownloadFileTab : public System::Windows::Forms::Form
	{
	public:
		MainDlg^ mainDlg;
	private: DevComponents::DotNetBar::Bar^  bar3;
	public: 
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem14;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem15;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem16;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem17;
	
	public:
		MessageCreator^ msgCreator;
		DownloadFileTab(MainDlg^ mainDlgInput, MessageCreator^ msgCreatorInput);
		delegate System::Void ActionDelegate();
		delegate System::Void ParamActionDelegate(LinkedList<Object^>^ params);
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~DownloadFileTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl9;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel28;
	private: DevComponents::DotNetBar::Bar^  bar2;
	private: DevComponents::DotNetBar::ButtonItem^  fileTransferTabNewJobButton;
	private: DevComponents::DotNetBar::ButtonItem^  fileTransferTabStartJobButton;
	private: DevComponents::DotNetBar::ButtonItem^  fileTransferTabStopJobButton;
	private: DevComponents::DotNetBar::ButtonItem^  fileTransferTabDeleteJobButton;
	public: DevComponents::DotNetBar::Controls::DataGridViewX^  fileTransferDataGridViewX;
	private: 
	private: System::Windows::Forms::DataGridViewImageColumn^  fileStatusDataGridViewImageColumn;
	public: 
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  fileNameDataGridViewLabelXColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  fileSizeDataGridViewLabelXColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  downloadSpeedDataGridViewLabelXColumn;
	private: System::Windows::Forms::DataGridViewImageColumn^  fileProgressDataGridViewImageColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  createdTimeDataGridViewLabelXColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  finishedTimedataGridViewLabelXColumn;
	private: DevComponents::DotNetBar::SuperTabItem^  fileTransferSuperTabItem;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel13;





	public: DevComponents::DotNetBar::Controls::DataGridViewX^  finishedFileTransferDataGridViewX;
	private: 
	private: System::Windows::Forms::DataGridViewImageColumn^  fileTypedataGridViewImageColumn;
	public: 
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  dataGridViewLabelXColumn1;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  dataGridViewLabelXColumn2;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  dataGridViewLabelXColumn5;
	private: DevComponents::DotNetBar::SuperTabItem^  finishedFileSuperTabItem;
	private: DevComponents::DotNetBar::ButtonItem^  AddDownloadingJobButtonItem;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->superTabControl9 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel28 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->bar2 = (gcnew DevComponents::DotNetBar::Bar());
			this->fileTransferTabNewJobButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->fileTransferTabStartJobButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->fileTransferTabStopJobButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->fileTransferTabDeleteJobButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->fileTransferDataGridViewX = (gcnew DevComponents::DotNetBar::Controls::DataGridViewX());
			this->fileStatusDataGridViewImageColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->fileNameDataGridViewLabelXColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->fileSizeDataGridViewLabelXColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->downloadSpeedDataGridViewLabelXColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->fileProgressDataGridViewImageColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->createdTimeDataGridViewLabelXColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->finishedTimedataGridViewLabelXColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->fileTransferSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel13 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->bar3 = (gcnew DevComponents::DotNetBar::Bar());
			this->finishedFileTransferDataGridViewX = (gcnew DevComponents::DotNetBar::Controls::DataGridViewX());
			this->fileTypedataGridViewImageColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->dataGridViewLabelXColumn1 = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->dataGridViewLabelXColumn2 = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->dataGridViewLabelXColumn5 = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->finishedFileSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->AddDownloadingJobButtonItem = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem14 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem15 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem16 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->buttonItem17 = (gcnew DevComponents::DotNetBar::ButtonItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl9))->BeginInit();
			this->superTabControl9->SuspendLayout();
			this->superTabControlPanel28->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileTransferDataGridViewX))->BeginInit();
			this->superTabControlPanel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->finishedFileTransferDataGridViewX))->BeginInit();
			this->SuspendLayout();
			// 
			// superTabControl9
			// 
			this->superTabControl9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl9->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl9->ControlBox->MenuBox->Name = L"";
			this->superTabControl9->ControlBox->MenuBox->Visible = false;
			this->superTabControl9->ControlBox->Name = L"";
			this->superTabControl9->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl9->ControlBox->MenuBox, 
				this->superTabControl9->ControlBox->CloseBox});
			this->superTabControl9->Controls->Add(this->superTabControlPanel28);
			this->superTabControl9->Controls->Add(this->superTabControlPanel13);
			this->superTabControl9->Cursor = System::Windows::Forms::Cursors::Default;
			this->superTabControl9->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl9->Location = System::Drawing::Point(0, 0);
			this->superTabControl9->Name = L"superTabControl9";
			this->superTabControl9->ReorderTabsEnabled = true;
			this->superTabControl9->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl9->SelectedTabIndex = 0;
			this->superTabControl9->Size = System::Drawing::Size(593, 573);
			this->superTabControl9->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl9->TabIndex = 2;
			this->superTabControl9->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->fileTransferSuperTabItem, 
				this->finishedFileSuperTabItem, this->AddDownloadingJobButtonItem});
			this->superTabControl9->Text = L"superTabControl9";
			this->superTabControl9->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel28
			// 
			this->superTabControlPanel28->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::Office2007;
			this->superTabControlPanel28->Controls->Add(this->bar2);
			this->superTabControlPanel28->Controls->Add(this->fileTransferDataGridViewX);
			this->superTabControlPanel28->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel28->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel28->Name = L"superTabControlPanel28";
			this->superTabControlPanel28->Size = System::Drawing::Size(593, 531);
			this->superTabControlPanel28->TabIndex = 0;
			this->superTabControlPanel28->TabItem = this->fileTransferSuperTabItem;
			// 
			// bar2
			// 
			this->bar2->AntiAlias = true;
			this->bar2->Dock = System::Windows::Forms::DockStyle::Top;
			this->bar2->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->bar2->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(4) {this->fileTransferTabNewJobButton, 
				this->fileTransferTabStartJobButton, this->fileTransferTabStopJobButton, this->fileTransferTabDeleteJobButton});
			this->bar2->Location = System::Drawing::Point(0, 0);
			this->bar2->Name = L"bar2";
			this->bar2->Size = System::Drawing::Size(593, 25);
			this->bar2->Stretch = true;
			this->bar2->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar2->TabIndex = 2;
			this->bar2->TabStop = false;
			this->bar2->Text = L"bar2";
			// 
			// fileTransferTabNewJobButton
			// 
			this->fileTransferTabNewJobButton->Name = L"fileTransferTabNewJobButton";
			this->fileTransferTabNewJobButton->Text = L"新建任务";
			this->fileTransferTabNewJobButton->Click += gcnew System::EventHandler(this, &DownloadFileTab::fileTransferTabNewJobButton_Click);
			// 
			// fileTransferTabStartJobButton
			// 
			this->fileTransferTabStartJobButton->Name = L"fileTransferTabStartJobButton";
			this->fileTransferTabStartJobButton->Text = L"开始";
			this->fileTransferTabStartJobButton->Click += gcnew System::EventHandler(this, &DownloadFileTab::fileTransferTabStartJobButton_Click);
			// 
			// fileTransferTabStopJobButton
			// 
			this->fileTransferTabStopJobButton->Name = L"fileTransferTabStopJobButton";
			this->fileTransferTabStopJobButton->Text = L"停止";
			// 
			// fileTransferTabDeleteJobButton
			// 
			this->fileTransferTabDeleteJobButton->Name = L"fileTransferTabDeleteJobButton";
			this->fileTransferTabDeleteJobButton->Text = L"删除任务";
			// 
			// fileTransferDataGridViewX
			// 
			this->fileTransferDataGridViewX->AllowUserToAddRows = false;
			this->fileTransferDataGridViewX->AllowUserToDeleteRows = false;
			this->fileTransferDataGridViewX->AllowUserToOrderColumns = true;
			this->fileTransferDataGridViewX->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->fileTransferDataGridViewX->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->fileTransferDataGridViewX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->fileTransferDataGridViewX->BackgroundColor = System::Drawing::Color::White;
			this->fileTransferDataGridViewX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->fileTransferDataGridViewX->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->fileTransferDataGridViewX->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->fileTransferDataGridViewX->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->fileTransferDataGridViewX->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->fileTransferDataGridViewX->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->fileStatusDataGridViewImageColumn, 
				this->fileNameDataGridViewLabelXColumn, this->fileSizeDataGridViewLabelXColumn, this->downloadSpeedDataGridViewLabelXColumn, 
				this->fileProgressDataGridViewImageColumn, this->createdTimeDataGridViewLabelXColumn, this->finishedTimedataGridViewLabelXColumn});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->fileTransferDataGridViewX->DefaultCellStyle = dataGridViewCellStyle3;
			this->fileTransferDataGridViewX->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->fileTransferDataGridViewX->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)), 
				static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->fileTransferDataGridViewX->HighlightSelectedColumnHeaders = false;
			this->fileTransferDataGridViewX->Location = System::Drawing::Point(0, 23);
			this->fileTransferDataGridViewX->Name = L"fileTransferDataGridViewX";
			this->fileTransferDataGridViewX->ReadOnly = true;
			this->fileTransferDataGridViewX->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->fileTransferDataGridViewX->RowHeadersVisible = false;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			this->fileTransferDataGridViewX->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->fileTransferDataGridViewX->RowTemplate->Height = 23;
			this->fileTransferDataGridViewX->RowTemplate->ReadOnly = true;
			this->fileTransferDataGridViewX->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->fileTransferDataGridViewX->ShowCellErrors = false;
			this->fileTransferDataGridViewX->ShowEditingIcon = false;
			this->fileTransferDataGridViewX->ShowRowErrors = false;
			this->fileTransferDataGridViewX->Size = System::Drawing::Size(593, 508);
			this->fileTransferDataGridViewX->TabIndex = 1;
			this->fileTransferDataGridViewX->SelectionChanged += gcnew System::EventHandler(this, &DownloadFileTab::fileTransferDataGridViewX_SelectionChanged);
			// 
			// fileStatusDataGridViewImageColumn
			// 
			this->fileStatusDataGridViewImageColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->fileStatusDataGridViewImageColumn->FillWeight = 6.74F;
			this->fileStatusDataGridViewImageColumn->HeaderText = L"状态";
			this->fileStatusDataGridViewImageColumn->Name = L"fileStatusDataGridViewImageColumn";
			this->fileStatusDataGridViewImageColumn->ReadOnly = true;
			this->fileStatusDataGridViewImageColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->fileStatusDataGridViewImageColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->fileStatusDataGridViewImageColumn->ToolTipText = L"文件下载的状态";
			this->fileStatusDataGridViewImageColumn->Width = 37;
			// 
			// fileNameDataGridViewLabelXColumn
			// 
			this->fileNameDataGridViewLabelXColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->fileNameDataGridViewLabelXColumn->FillWeight = 30.35F;
			this->fileNameDataGridViewLabelXColumn->HeaderText = L"文件名称";
			this->fileNameDataGridViewLabelXColumn->Name = L"fileNameDataGridViewLabelXColumn";
			this->fileNameDataGridViewLabelXColumn->PaddingLeft = 3;
			this->fileNameDataGridViewLabelXColumn->PaddingRight = 3;
			this->fileNameDataGridViewLabelXColumn->ReadOnly = true;
			this->fileNameDataGridViewLabelXColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->fileNameDataGridViewLabelXColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->fileNameDataGridViewLabelXColumn->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->fileNameDataGridViewLabelXColumn->ToolTipText = L"文件的名称";
			this->fileNameDataGridViewLabelXColumn->WordWrap = true;
			// 
			// fileSizeDataGridViewLabelXColumn
			// 
			this->fileSizeDataGridViewLabelXColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->fileSizeDataGridViewLabelXColumn->FillWeight = 9;
			this->fileSizeDataGridViewLabelXColumn->HeaderText = L"大小";
			this->fileSizeDataGridViewLabelXColumn->Name = L"fileSizeDataGridViewLabelXColumn";
			this->fileSizeDataGridViewLabelXColumn->PaddingLeft = 3;
			this->fileSizeDataGridViewLabelXColumn->PaddingRight = 3;
			this->fileSizeDataGridViewLabelXColumn->ReadOnly = true;
			this->fileSizeDataGridViewLabelXColumn->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->fileSizeDataGridViewLabelXColumn->ToolTipText = L"文件的总大小";
			this->fileSizeDataGridViewLabelXColumn->WordWrap = true;
			// 
			// downloadSpeedDataGridViewLabelXColumn
			// 
			this->downloadSpeedDataGridViewLabelXColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->downloadSpeedDataGridViewLabelXColumn->FillWeight = 10.12F;
			this->downloadSpeedDataGridViewLabelXColumn->HeaderText = L"速度";
			this->downloadSpeedDataGridViewLabelXColumn->Name = L"downloadSpeedDataGridViewLabelXColumn";
			this->downloadSpeedDataGridViewLabelXColumn->PaddingLeft = 3;
			this->downloadSpeedDataGridViewLabelXColumn->PaddingRight = 3;
			this->downloadSpeedDataGridViewLabelXColumn->ReadOnly = true;
			this->downloadSpeedDataGridViewLabelXColumn->Text = L"0KB/s";
			this->downloadSpeedDataGridViewLabelXColumn->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->downloadSpeedDataGridViewLabelXColumn->ToolTipText = L"文件当前下载速度";
			this->downloadSpeedDataGridViewLabelXColumn->WordWrap = true;
			// 
			// fileProgressDataGridViewImageColumn
			// 
			this->fileProgressDataGridViewImageColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->fileProgressDataGridViewImageColumn->FillWeight = 16.86F;
			this->fileProgressDataGridViewImageColumn->HeaderText = L"下载进度";
			this->fileProgressDataGridViewImageColumn->MinimumWidth = 100;
			this->fileProgressDataGridViewImageColumn->Name = L"fileProgressDataGridViewImageColumn";
			this->fileProgressDataGridViewImageColumn->ReadOnly = true;
			this->fileProgressDataGridViewImageColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->fileProgressDataGridViewImageColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// createdTimeDataGridViewLabelXColumn
			// 
			this->createdTimeDataGridViewLabelXColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->createdTimeDataGridViewLabelXColumn->FillWeight = 13.49F;
			this->createdTimeDataGridViewLabelXColumn->HeaderText = L"添加时间";
			this->createdTimeDataGridViewLabelXColumn->Name = L"createdTimeDataGridViewLabelXColumn";
			this->createdTimeDataGridViewLabelXColumn->PaddingLeft = 3;
			this->createdTimeDataGridViewLabelXColumn->PaddingRight = 3;
			this->createdTimeDataGridViewLabelXColumn->ReadOnly = true;
			this->createdTimeDataGridViewLabelXColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->createdTimeDataGridViewLabelXColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->createdTimeDataGridViewLabelXColumn->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->createdTimeDataGridViewLabelXColumn->ToolTipText = L"文件添加到下载列表的时间";
			this->createdTimeDataGridViewLabelXColumn->WordWrap = true;
			// 
			// finishedTimedataGridViewLabelXColumn
			// 
			this->finishedTimedataGridViewLabelXColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->finishedTimedataGridViewLabelXColumn->FillWeight = 13.83F;
			this->finishedTimedataGridViewLabelXColumn->HeaderText = L"完成时间";
			this->finishedTimedataGridViewLabelXColumn->Name = L"finishedTimedataGridViewLabelXColumn";
			this->finishedTimedataGridViewLabelXColumn->PaddingLeft = 3;
			this->finishedTimedataGridViewLabelXColumn->PaddingRight = 3;
			this->finishedTimedataGridViewLabelXColumn->ReadOnly = true;
			this->finishedTimedataGridViewLabelXColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->finishedTimedataGridViewLabelXColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->finishedTimedataGridViewLabelXColumn->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->finishedTimedataGridViewLabelXColumn->ToolTipText = L"文件预计下载完成的时间";
			// 
			// fileTransferSuperTabItem
			// 
			this->fileTransferSuperTabItem->AttachedControl = this->superTabControlPanel28;
			this->fileTransferSuperTabItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fileTransferSuperTabItem->GlobalItem = false;
			this->fileTransferSuperTabItem->Name = L"fileTransferSuperTabItem";
			this->fileTransferSuperTabItem->Text = L"传输中的文件";
			// 
			// superTabControlPanel13
			// 
			this->superTabControlPanel13->Controls->Add(this->bar3);
			this->superTabControlPanel13->Controls->Add(this->finishedFileTransferDataGridViewX);
			this->superTabControlPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel13->Location = System::Drawing::Point(0, 0);
			this->superTabControlPanel13->Name = L"superTabControlPanel13";
			this->superTabControlPanel13->Size = System::Drawing::Size(593, 573);
			this->superTabControlPanel13->TabIndex = 0;
			this->superTabControlPanel13->TabItem = this->finishedFileSuperTabItem;
			// 
			// bar3
			// 
			this->bar3->AntiAlias = true;
			this->bar3->Dock = System::Windows::Forms::DockStyle::Top;
			this->bar3->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->bar3->Location = System::Drawing::Point(0, 0);
			this->bar3->Name = L"bar3";
			this->bar3->Size = System::Drawing::Size(593, 2);
			this->bar3->Stretch = true;
			this->bar3->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->bar3->TabIndex = 4;
			this->bar3->TabStop = false;
			this->bar3->Text = L"bar3";
			// 
			// finishedFileTransferDataGridViewX
			// 
			this->finishedFileTransferDataGridViewX->AllowUserToAddRows = false;
			this->finishedFileTransferDataGridViewX->AllowUserToDeleteRows = false;
			this->finishedFileTransferDataGridViewX->AllowUserToOrderColumns = true;
			this->finishedFileTransferDataGridViewX->AllowUserToResizeRows = false;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->finishedFileTransferDataGridViewX->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle5;
			this->finishedFileTransferDataGridViewX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->finishedFileTransferDataGridViewX->BackgroundColor = System::Drawing::Color::White;
			this->finishedFileTransferDataGridViewX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->finishedFileTransferDataGridViewX->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->finishedFileTransferDataGridViewX->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->finishedFileTransferDataGridViewX->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->finishedFileTransferDataGridViewX->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->finishedFileTransferDataGridViewX->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->fileTypedataGridViewImageColumn, 
				this->dataGridViewLabelXColumn1, this->dataGridViewLabelXColumn2, this->dataGridViewLabelXColumn5});
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->finishedFileTransferDataGridViewX->DefaultCellStyle = dataGridViewCellStyle7;
			this->finishedFileTransferDataGridViewX->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->finishedFileTransferDataGridViewX->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)), 
				static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->finishedFileTransferDataGridViewX->HighlightSelectedColumnHeaders = false;
			this->finishedFileTransferDataGridViewX->Location = System::Drawing::Point(0, 23);
			this->finishedFileTransferDataGridViewX->Name = L"finishedFileTransferDataGridViewX";
			this->finishedFileTransferDataGridViewX->ReadOnly = true;
			this->finishedFileTransferDataGridViewX->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->finishedFileTransferDataGridViewX->RowHeadersVisible = false;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			this->finishedFileTransferDataGridViewX->RowsDefaultCellStyle = dataGridViewCellStyle8;
			this->finishedFileTransferDataGridViewX->RowTemplate->Height = 23;
			this->finishedFileTransferDataGridViewX->RowTemplate->ReadOnly = true;
			this->finishedFileTransferDataGridViewX->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->finishedFileTransferDataGridViewX->ShowCellErrors = false;
			this->finishedFileTransferDataGridViewX->ShowEditingIcon = false;
			this->finishedFileTransferDataGridViewX->ShowRowErrors = false;
			this->finishedFileTransferDataGridViewX->Size = System::Drawing::Size(593, 550);
			this->finishedFileTransferDataGridViewX->TabIndex = 3;
			// 
			// fileTypedataGridViewImageColumn
			// 
			this->fileTypedataGridViewImageColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->fileTypedataGridViewImageColumn->FillWeight = 15;
			this->fileTypedataGridViewImageColumn->HeaderText = L"类型";
			this->fileTypedataGridViewImageColumn->Name = L"fileTypedataGridViewImageColumn";
			this->fileTypedataGridViewImageColumn->ReadOnly = true;
			this->fileTypedataGridViewImageColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->fileTypedataGridViewImageColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->fileTypedataGridViewImageColumn->ToolTipText = L"文件类型";
			this->fileTypedataGridViewImageColumn->Width = 37;
			// 
			// dataGridViewLabelXColumn1
			// 
			this->dataGridViewLabelXColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewLabelXColumn1->FillWeight = 30.35F;
			this->dataGridViewLabelXColumn1->HeaderText = L"文件名称";
			this->dataGridViewLabelXColumn1->Name = L"dataGridViewLabelXColumn1";
			this->dataGridViewLabelXColumn1->PaddingLeft = 3;
			this->dataGridViewLabelXColumn1->PaddingRight = 3;
			this->dataGridViewLabelXColumn1->ReadOnly = true;
			this->dataGridViewLabelXColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewLabelXColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->dataGridViewLabelXColumn1->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->dataGridViewLabelXColumn1->ToolTipText = L"文件的名称";
			this->dataGridViewLabelXColumn1->WordWrap = true;
			// 
			// dataGridViewLabelXColumn2
			// 
			this->dataGridViewLabelXColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewLabelXColumn2->FillWeight = 9;
			this->dataGridViewLabelXColumn2->HeaderText = L"大小";
			this->dataGridViewLabelXColumn2->Name = L"dataGridViewLabelXColumn2";
			this->dataGridViewLabelXColumn2->PaddingLeft = 3;
			this->dataGridViewLabelXColumn2->PaddingRight = 3;
			this->dataGridViewLabelXColumn2->ReadOnly = true;
			this->dataGridViewLabelXColumn2->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->dataGridViewLabelXColumn2->ToolTipText = L"文件的总大小";
			this->dataGridViewLabelXColumn2->WordWrap = true;
			// 
			// dataGridViewLabelXColumn5
			// 
			this->dataGridViewLabelXColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewLabelXColumn5->FillWeight = 13.83F;
			this->dataGridViewLabelXColumn5->HeaderText = L"完成时间";
			this->dataGridViewLabelXColumn5->Name = L"dataGridViewLabelXColumn5";
			this->dataGridViewLabelXColumn5->PaddingLeft = 3;
			this->dataGridViewLabelXColumn5->PaddingRight = 3;
			this->dataGridViewLabelXColumn5->ReadOnly = true;
			this->dataGridViewLabelXColumn5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewLabelXColumn5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->dataGridViewLabelXColumn5->TextLineAlignment = System::Drawing::StringAlignment::Near;
			this->dataGridViewLabelXColumn5->ToolTipText = L"文件预计下载完成的时间";
			// 
			// finishedFileSuperTabItem
			// 
			this->finishedFileSuperTabItem->AttachedControl = this->superTabControlPanel13;
			this->finishedFileSuperTabItem->GlobalItem = false;
			this->finishedFileSuperTabItem->Name = L"finishedFileSuperTabItem";
			this->finishedFileSuperTabItem->Text = L"下载完毕的文件";
			// 
			// AddDownloadingJobButtonItem
			// 
			this->AddDownloadingJobButtonItem->ButtonStyle = DevComponents::DotNetBar::eButtonStyle::ImageAndText;
			this->AddDownloadingJobButtonItem->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->AddDownloadingJobButtonItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddDownloadingJobButtonItem->FontBold = true;
			this->AddDownloadingJobButtonItem->ItemAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			this->AddDownloadingJobButtonItem->Name = L"AddDownloadingJobButtonItem";
			this->AddDownloadingJobButtonItem->Text = L"   添加下载文件";
			// 
			// buttonItem14
			// 
			this->buttonItem14->Name = L"buttonItem14";
			this->buttonItem14->Text = L"新建任务";
			// 
			// buttonItem15
			// 
			this->buttonItem15->Name = L"buttonItem15";
			this->buttonItem15->Text = L"开始";
			// 
			// buttonItem16
			// 
			this->buttonItem16->Name = L"buttonItem16";
			this->buttonItem16->Text = L"停止";
			// 
			// buttonItem17
			// 
			this->buttonItem17->Name = L"buttonItem17";
			this->buttonItem17->Text = L"删除任务";
			// 
			// DownloadFileTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->ControlBox = false;
			this->Controls->Add(this->superTabControl9);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DownloadFileTab";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"DownloadFileTab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl9))->EndInit();
			this->superTabControl9->ResumeLayout(false);
			this->superTabControlPanel28->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileTransferDataGridViewX))->EndInit();
			this->superTabControlPanel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->finishedFileTransferDataGridViewX))->EndInit();
			this->ResumeLayout(false);

		}
private: System::Void fileTransferDataGridViewX_SelectionChanged(System::Object^  sender, System::EventArgs^  e);
		 /* 
		 * This function will auto enable or disable the buttons based on the selection in the 
		 * file transfer datagridview
		 */
	private: System::Void FileTransferSetButtonsBasedOnSelection(void);
			 /*
			 * This function will return the bitmap of the picture for the status
			 */
	public:  Bitmap^ GetJobStatusBitmap(OuSns::DownloadJobStatus status);
			 Bitmap^ GetProgressBarBitmap(double progress,int width);
			 System::Void SaveDownloadingList();
			 System::Void SaveDownloadedList();
			 System::Void LoadDownloadList();

private: System::Void fileTransferTabStartJobButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void fileTransferTabNewJobButton_Click(System::Object^  sender, System::EventArgs^  e);
public:
		 /*
		 * This function will be called when the downloader communication need to update the current file list (some bool is set)
		 */
		 System::Void UpdateUnfinishedJob(void);

		 /*
		 * This will be used when first local the finished job list or 
		 */
		 System::Void UpdateFinishedJob(void);
#pragma endregion
	};
}
