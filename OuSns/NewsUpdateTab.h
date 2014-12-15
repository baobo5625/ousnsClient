#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// NewsUpdateTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class NewsUpdateTab : public System::Windows::Forms::Form
	{
	public:
		NewsUpdateTab(void)
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
		~NewsUpdateTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl1;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel12;
	private: DevComponents::DotNetBar::Controls::DataGridViewX^  newsDataGridView;
	private: DevComponents::DotNetBar::SuperTabItem^  newsTab;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel14;
	private: DevComponents::DotNetBar::Controls::ListViewEx^  logListView;
	private: System::Windows::Forms::ColumnHeader^  logTimeColumn;
	private: System::Windows::Forms::ColumnHeader^  logActionColumn;
	private: DevComponents::DotNetBar::Bar^  logTitleBar;
	private: DevComponents::DotNetBar::ButtonItem^  logDayButton;
	private: DevComponents::DotNetBar::ButtonItem^  logWeekButton;
	private: DevComponents::DotNetBar::ButtonItem^  logMonthButton;
	private: DevComponents::DotNetBar::SuperTabItem^  logTab;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  updateTimeColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  contentColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn^  comeFromColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewButtonXColumn^  downloadButtonColumn;
	private: DevComponents::DotNetBar::Controls::DataGridViewButtonXColumn^  checkDetailButtonColumn;

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
			this->superTabControl1 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel12 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->newsDataGridView = (gcnew DevComponents::DotNetBar::Controls::DataGridViewX());
			this->newsTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel14 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->logListView = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->logTimeColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->logActionColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->logTitleBar = (gcnew DevComponents::DotNetBar::Bar());
			this->logDayButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->logWeekButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->logMonthButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->logTab = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->updateTimeColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->contentColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->comeFromColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXColumn());
			this->downloadButtonColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewButtonXColumn());
			this->checkDetailButtonColumn = (gcnew DevComponents::DotNetBar::Controls::DataGridViewButtonXColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->BeginInit();
			this->superTabControl1->SuspendLayout();
			this->superTabControlPanel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->newsDataGridView))->BeginInit();
			this->superTabControlPanel14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logTitleBar))->BeginInit();
			this->SuspendLayout();
			// 
			// superTabControl1
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl1->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl1->ControlBox->MenuBox->Name = L"";
			this->superTabControl1->ControlBox->MenuBox->Visible = false;
			this->superTabControl1->ControlBox->Name = L"";
			this->superTabControl1->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl1->ControlBox->MenuBox, 
				this->superTabControl1->ControlBox->CloseBox});
			this->superTabControl1->Controls->Add(this->superTabControlPanel12);
			this->superTabControl1->Controls->Add(this->superTabControlPanel14);
			this->superTabControl1->Cursor = System::Windows::Forms::Cursors::Default;
			this->superTabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl1->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl1->Location = System::Drawing::Point(0, 0);
			this->superTabControl1->Name = L"superTabControl1";
			this->superTabControl1->ReorderTabsEnabled = true;
			this->superTabControl1->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl1->SelectedTabIndex = 0;
			this->superTabControl1->Size = System::Drawing::Size(593, 572);
			this->superTabControl1->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl1->TabIndex = 1;
			this->superTabControl1->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->newsTab, this->logTab});
			this->superTabControl1->Text = L"superTabControl1";
			this->superTabControl1->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel12
			// 
			this->superTabControlPanel12->Controls->Add(this->newsDataGridView);
			this->superTabControlPanel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel12->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel12->Name = L"superTabControlPanel12";
			this->superTabControlPanel12->Size = System::Drawing::Size(593, 530);
			this->superTabControlPanel12->TabIndex = 1;
			this->superTabControlPanel12->TabItem = this->newsTab;
			// 
			// newsDataGridView
			// 
			this->newsDataGridView->AllowUserToDeleteRows = false;
			this->newsDataGridView->ColumnHeadersHeight = 18;
			this->newsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->newsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->updateTimeColumn, 
				this->contentColumn, this->comeFromColumn, this->downloadButtonColumn, this->checkDetailButtonColumn});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->newsDataGridView->DefaultCellStyle = dataGridViewCellStyle1;
			this->newsDataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->newsDataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)), 
				static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->newsDataGridView->Location = System::Drawing::Point(0, 0);
			this->newsDataGridView->Name = L"newsDataGridView";
			this->newsDataGridView->ReadOnly = true;
			this->newsDataGridView->RowHeadersVisible = false;
			this->newsDataGridView->RowTemplate->Height = 23;
			this->newsDataGridView->Size = System::Drawing::Size(593, 530);
			this->newsDataGridView->TabIndex = 1;
			// 
			// newsTab
			// 
			this->newsTab->AttachedControl = this->superTabControlPanel12;
			this->newsTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->newsTab->GlobalItem = false;
			this->newsTab->Name = L"newsTab";
			this->newsTab->Text = L"最新动态";
			// 
			// superTabControlPanel14
			// 
			this->superTabControlPanel14->Controls->Add(this->logListView);
			this->superTabControlPanel14->Controls->Add(this->logTitleBar);
			this->superTabControlPanel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel14->Location = System::Drawing::Point(0, 0);
			this->superTabControlPanel14->Name = L"superTabControlPanel14";
			this->superTabControlPanel14->Size = System::Drawing::Size(593, 572);
			this->superTabControlPanel14->TabIndex = 0;
			this->superTabControlPanel14->TabItem = this->logTab;
			// 
			// logListView
			// 
			// 
			// 
			// 
			this->logListView->Border->Class = L"ListViewBorder";
			this->logListView->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->logListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->logTimeColumn, 
				this->logActionColumn});
			this->logListView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->logListView->FullRowSelect = true;
			this->logListView->GridLines = true;
			this->logListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->logListView->LabelWrap = false;
			this->logListView->Location = System::Drawing::Point(0, 60);
			this->logListView->MultiSelect = false;
			this->logListView->Name = L"logListView";
			this->logListView->ShowGroups = false;
			this->logListView->Size = System::Drawing::Size(593, 512);
			this->logListView->Sorting = System::Windows::Forms::SortOrder::Descending;
			this->logListView->TabIndex = 3;
			this->logListView->UseCompatibleStateImageBehavior = false;
			this->logListView->View = System::Windows::Forms::View::Details;
			// 
			// logTimeColumn
			// 
			this->logTimeColumn->Text = L"时间";
			this->logTimeColumn->Width = 112;
			// 
			// logActionColumn
			// 
			this->logActionColumn->Text = L"行为";
			this->logActionColumn->Width = 532;
			// 
			// logTitleBar
			// 
			this->logTitleBar->AccessibleDescription = L"bar1 (bar1)";
			this->logTitleBar->AccessibleName = L"bar1";
			this->logTitleBar->AccessibleRole = System::Windows::Forms::AccessibleRole::ToolBar;
			this->logTitleBar->AntiAlias = true;
			this->logTitleBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->logTitleBar->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->logTitleBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->logDayButton, this->logWeekButton, 
				this->logMonthButton});
			this->logTitleBar->Location = System::Drawing::Point(0, 0);
			this->logTitleBar->Name = L"logTitleBar";
			this->logTitleBar->Size = System::Drawing::Size(593, 23);
			this->logTitleBar->Stretch = true;
			this->logTitleBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->logTitleBar->TabIndex = 2;
			this->logTitleBar->TabStop = false;
			this->logTitleBar->Text = L"bar1";
			this->logTitleBar->Visible = false;
			// 
			// logDayButton
			// 
			this->logDayButton->FixedSize = System::Drawing::Size(40, 20);
			this->logDayButton->Name = L"logDayButton";
			this->logDayButton->Text = L"今天";
			// 
			// logWeekButton
			// 
			this->logWeekButton->FixedSize = System::Drawing::Size(40, 20);
			this->logWeekButton->Name = L"logWeekButton";
			this->logWeekButton->Text = L"本周";
			// 
			// logMonthButton
			// 
			this->logMonthButton->FixedSize = System::Drawing::Size(40, 20);
			this->logMonthButton->Name = L"logMonthButton";
			this->logMonthButton->Text = L"本月";
			// 
			// logTab
			// 
			this->logTab->AttachedControl = this->superTabControlPanel14;
			this->logTab->Cursor = System::Windows::Forms::Cursors::Hand;
			this->logTab->GlobalItem = false;
			this->logTab->Name = L"logTab";
			this->logTab->Text = L"日志记录";
			// 
			// updateTimeColumn
			// 
			this->updateTimeColumn->HeaderText = L"更新时间";
			this->updateTimeColumn->Name = L"updateTimeColumn";
			this->updateTimeColumn->ReadOnly = true;
			this->updateTimeColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->updateTimeColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->updateTimeColumn->TextAlignment = System::Drawing::StringAlignment::Center;
			// 
			// contentColumn
			// 
			this->contentColumn->HeaderText = L"内容";
			this->contentColumn->Name = L"contentColumn";
			this->contentColumn->ReadOnly = true;
			this->contentColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->contentColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->contentColumn->TextAlignment = System::Drawing::StringAlignment::Center;
			this->contentColumn->Width = 257;
			// 
			// comeFromColumn
			// 
			this->comeFromColumn->HeaderText = L"来自";
			this->comeFromColumn->Name = L"comeFromColumn";
			this->comeFromColumn->ReadOnly = true;
			this->comeFromColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->comeFromColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->comeFromColumn->TextAlignment = System::Drawing::StringAlignment::Center;
			// 
			// downloadButtonColumn
			// 
			this->downloadButtonColumn->HeaderText = L"下载";
			this->downloadButtonColumn->Name = L"downloadButtonColumn";
			this->downloadButtonColumn->ReadOnly = true;
			this->downloadButtonColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->downloadButtonColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->downloadButtonColumn->Text = nullptr;
			this->downloadButtonColumn->Width = 67;
			// 
			// checkDetailButtonColumn
			// 
			this->checkDetailButtonColumn->HeaderText = L"查看详情";
			this->checkDetailButtonColumn->Name = L"checkDetailButtonColumn";
			this->checkDetailButtonColumn->ReadOnly = true;
			this->checkDetailButtonColumn->Text = nullptr;
			this->checkDetailButtonColumn->Width = 66;
			// 
			// NewsUpdateTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(593, 573);
			this->Controls->Add(this->superTabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"NewsUpdateTab";
			this->Text = L"NewsUpdateTab";
			this->DoubleBuffered = true;
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->EndInit();
			this->superTabControl1->ResumeLayout(false);
			this->superTabControlPanel12->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->newsDataGridView))->EndInit();
			this->superTabControlPanel14->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logTitleBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
