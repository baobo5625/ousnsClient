#pragma once
#include "stdafx.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// OuSnsJobInfoDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class DownloadingJob;
	public ref class OuSnsJobInfoDlg : DevComponents::DotNetBar::Office2007Form
	{
	public:
		OuSnsJobInfoDlg(DownloadingJob^ job);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~OuSnsJobInfoDlg()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  fileIconPictureBox;
	private: DevComponents::DotNetBar::LabelX^  jobNameLabelX;
	private: DevComponents::DotNetBar::LabelX^  jobSizeLabelX;

	protected: 

	protected: 




	private: DevComponents::DotNetBar::SuperTabControl^  DownloadingJobFileListSuperTab;


	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel1;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem1;
	private: DevComponents::AdvTree::AdvTree^  downloadingFileListAdvTree;



	private: DevComponents::AdvTree::Node^  node1;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector1;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle1;
	private: DevComponents::DotNetBar::LabelX^  labelX5;
	private: DevComponents::DotNetBar::LabelX^  labelX4;
	private: DevComponents::DotNetBar::LabelX^  labelX3;
	private: DevComponents::DotNetBar::ButtonX^  addJobButtonX;
	private: DevComponents::DotNetBar::ButtonX^  cancelAddJobButtonX;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  comboBoxEx1;
	private: DevComponents::DotNetBar::LabelX^  fileCategoryLabelX;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  jobPathTextBoxX;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader1;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader2;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader3;
	private: DevComponents::AdvTree::Cell^  cell2;

	private: DevComponents::AdvTree::Cell^  cell3;
















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
			this->fileIconPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->jobNameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->jobSizeLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->DownloadingJobFileListSuperTab = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel1 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->labelX5 = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX3 = (gcnew DevComponents::DotNetBar::LabelX());
			this->downloadingFileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->columnHeader1 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader2 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader3 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node1 = (gcnew DevComponents::AdvTree::Node());
			this->cell2 = (gcnew DevComponents::AdvTree::Cell());
			this->cell3 = (gcnew DevComponents::AdvTree::Cell());
			this->nodeConnector1 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle1 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->superTabItem1 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->addJobButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->cancelAddJobButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->comboBoxEx1 = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->fileCategoryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->jobPathTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileIconPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DownloadingJobFileListSuperTab))->BeginInit();
			this->DownloadingJobFileListSuperTab->SuspendLayout();
			this->superTabControlPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->downloadingFileListAdvTree))->BeginInit();
			this->SuspendLayout();
			// 
			// fileIconPictureBox
			// 
			this->fileIconPictureBox->Location = System::Drawing::Point(13, 13);
			this->fileIconPictureBox->Name = L"fileIconPictureBox";
			this->fileIconPictureBox->Size = System::Drawing::Size(60, 60);
			this->fileIconPictureBox->TabIndex = 0;
			this->fileIconPictureBox->TabStop = false;
			// 
			// jobNameLabelX
			// 
			this->jobNameLabelX->AutoSize = true;
			// 
			// 
			// 
			this->jobNameLabelX->BackgroundStyle->Class = L"";
			this->jobNameLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->jobNameLabelX->Location = System::Drawing::Point(80, 23);
			this->jobNameLabelX->Name = L"jobNameLabelX";
			this->jobNameLabelX->Size = System::Drawing::Size(50, 16);
			this->jobNameLabelX->TabIndex = 1;
			this->jobNameLabelX->Text = L"jobName";
			// 
			// jobSizeLabelX
			// 
			this->jobSizeLabelX->AutoSize = true;
			// 
			// 
			// 
			this->jobSizeLabelX->BackgroundStyle->Class = L"";
			this->jobSizeLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->jobSizeLabelX->Location = System::Drawing::Point(80, 53);
			this->jobSizeLabelX->Name = L"jobSizeLabelX";
			this->jobSizeLabelX->Size = System::Drawing::Size(50, 16);
			this->jobSizeLabelX->TabIndex = 2;
			this->jobSizeLabelX->Text = L"jobSize";
			// 
			// DownloadingJobFileListSuperTab
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->DownloadingJobFileListSuperTab->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->DownloadingJobFileListSuperTab->ControlBox->MenuBox->Name = L"";
			this->DownloadingJobFileListSuperTab->ControlBox->Name = L"";
			this->DownloadingJobFileListSuperTab->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->DownloadingJobFileListSuperTab->ControlBox->MenuBox, 
				this->DownloadingJobFileListSuperTab->ControlBox->CloseBox});
			this->DownloadingJobFileListSuperTab->ControlBox->Visible = false;
			this->DownloadingJobFileListSuperTab->Controls->Add(this->superTabControlPanel1);
			this->DownloadingJobFileListSuperTab->Location = System::Drawing::Point(13, 116);
			this->DownloadingJobFileListSuperTab->Name = L"DownloadingJobFileListSuperTab";
			this->DownloadingJobFileListSuperTab->ReorderTabsEnabled = true;
			this->DownloadingJobFileListSuperTab->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->DownloadingJobFileListSuperTab->SelectedTabIndex = 0;
			this->DownloadingJobFileListSuperTab->Size = System::Drawing::Size(400, 225);
			this->DownloadingJobFileListSuperTab->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->DownloadingJobFileListSuperTab->TabIndex = 5;
			this->DownloadingJobFileListSuperTab->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(1) {this->superTabItem1});
			this->DownloadingJobFileListSuperTab->Text = L"superTabControl1";
			// 
			// superTabControlPanel1
			// 
			this->superTabControlPanel1->Controls->Add(this->labelX5);
			this->superTabControlPanel1->Controls->Add(this->labelX4);
			this->superTabControlPanel1->Controls->Add(this->labelX3);
			this->superTabControlPanel1->Controls->Add(this->downloadingFileListAdvTree);
			this->superTabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel1->Location = System::Drawing::Point(0, 28);
			this->superTabControlPanel1->Name = L"superTabControlPanel1";
			this->superTabControlPanel1->Size = System::Drawing::Size(400, 197);
			this->superTabControlPanel1->TabIndex = 1;
			this->superTabControlPanel1->TabItem = this->superTabItem1;
			// 
			// labelX5
			// 
			this->labelX5->AutoSize = true;
			this->labelX5->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX5->BackgroundStyle->Class = L"";
			this->labelX5->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX5->Location = System::Drawing::Point(117, 178);
			this->labelX5->Name = L"labelX5";
			this->labelX5->Size = System::Drawing::Size(50, 16);
			this->labelX5->TabIndex = 2;
			this->labelX5->Text = L"labelX5";
			// 
			// labelX4
			// 
			this->labelX4->AutoSize = true;
			this->labelX4->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX4->BackgroundStyle->Class = L"";
			this->labelX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX4->Location = System::Drawing::Point(61, 178);
			this->labelX4->Name = L"labelX4";
			this->labelX4->Size = System::Drawing::Size(50, 16);
			this->labelX4->TabIndex = 2;
			this->labelX4->Text = L"labelX4";
			// 
			// labelX3
			// 
			this->labelX3->AutoSize = true;
			this->labelX3->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->labelX3->BackgroundStyle->Class = L"";
			this->labelX3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX3->Location = System::Drawing::Point(5, 178);
			this->labelX3->Name = L"labelX3";
			this->labelX3->Size = System::Drawing::Size(50, 16);
			this->labelX3->TabIndex = 1;
			this->labelX3->Text = L"labelX3";
			// 
			// downloadingFileListAdvTree
			// 
			this->downloadingFileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->downloadingFileListAdvTree->AllowDrop = true;
			this->downloadingFileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->downloadingFileListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->downloadingFileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->downloadingFileListAdvTree->Columns->Add(this->columnHeader1);
			this->downloadingFileListAdvTree->Columns->Add(this->columnHeader2);
			this->downloadingFileListAdvTree->Columns->Add(this->columnHeader3);
			this->downloadingFileListAdvTree->ExpandWidth = 0;
			this->downloadingFileListAdvTree->Indent = 0;
			this->downloadingFileListAdvTree->Location = System::Drawing::Point(2, 4);
			this->downloadingFileListAdvTree->Margin = System::Windows::Forms::Padding(0);
			this->downloadingFileListAdvTree->Name = L"downloadingFileListAdvTree";
			this->downloadingFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
			this->downloadingFileListAdvTree->NodesConnector = this->nodeConnector1;
			this->downloadingFileListAdvTree->NodeStyle = this->elementStyle1;
			this->downloadingFileListAdvTree->PathSeparator = L";";
			this->downloadingFileListAdvTree->Size = System::Drawing::Size(396, 169);
			this->downloadingFileListAdvTree->Styles->Add(this->elementStyle1);
			this->downloadingFileListAdvTree->TabIndex = 0;
			this->downloadingFileListAdvTree->Text = L"advTree1";
			// 
			// columnHeader1
			// 
			this->columnHeader1->MinimumWidth = 290;
			this->columnHeader1->Name = L"columnHeader1";
			this->columnHeader1->Text = L"文件名";
			this->columnHeader1->Width->Absolute = 290;
			// 
			// columnHeader2
			// 
			this->columnHeader2->MinimumWidth = 50;
			this->columnHeader2->Name = L"columnHeader2";
			this->columnHeader2->Text = L"大小";
			this->columnHeader2->Width->Absolute = 50;
			// 
			// columnHeader3
			// 
			this->columnHeader3->MinimumWidth = 40;
			this->columnHeader3->Name = L"columnHeader3";
			this->columnHeader3->Text = L"进度";
			this->columnHeader3->Width->Absolute = 40;
			// 
			// node1
			// 
			this->node1->Cells->Add(this->cell2);
			this->node1->Cells->Add(this->cell3);
			this->node1->CheckBoxVisible = true;
			this->node1->Expanded = true;
			this->node1->Name = L"node1";
			this->node1->Text = L"node1";
			// 
			// cell2
			// 
			this->cell2->Name = L"cell2";
			this->cell2->StyleMouseOver = nullptr;
			this->cell2->Text = L"cell2";
			// 
			// cell3
			// 
			this->cell3->Name = L"cell3";
			this->cell3->StyleMouseOver = nullptr;
			this->cell3->Text = L"cell3";
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
			// superTabItem1
			// 
			this->superTabItem1->AttachedControl = this->superTabControlPanel1;
			this->superTabItem1->GlobalItem = false;
			this->superTabItem1->Name = L"superTabItem1";
			this->superTabItem1->Text = L"文件列表";
			// 
			// addJobButtonX
			// 
			this->addJobButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->addJobButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->addJobButtonX->Location = System::Drawing::Point(236, 346);
			this->addJobButtonX->Name = L"addJobButtonX";
			this->addJobButtonX->Size = System::Drawing::Size(75, 23);
			this->addJobButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->addJobButtonX->TabIndex = 6;
			this->addJobButtonX->Text = L"确定";
			this->addJobButtonX->Click += gcnew System::EventHandler(this, &OuSnsJobInfoDlg::addJobButtonX_Click);
			// 
			// cancelAddJobButtonX
			// 
			this->cancelAddJobButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->cancelAddJobButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->cancelAddJobButtonX->Location = System::Drawing::Point(324, 346);
			this->cancelAddJobButtonX->Name = L"cancelAddJobButtonX";
			this->cancelAddJobButtonX->Size = System::Drawing::Size(75, 23);
			this->cancelAddJobButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->cancelAddJobButtonX->TabIndex = 7;
			this->cancelAddJobButtonX->Text = L"取消";
			this->cancelAddJobButtonX->Click += gcnew System::EventHandler(this, &OuSnsJobInfoDlg::cancelAddJobButtonX_Click);
			// 
			// comboBoxEx1
			// 
			this->comboBoxEx1->DisplayMember = L"Text";
			this->comboBoxEx1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxEx1->Enabled = false;
			this->comboBoxEx1->FormattingEnabled = true;
			this->comboBoxEx1->ItemHeight = 15;
			this->comboBoxEx1->Location = System::Drawing::Point(252, 23);
			this->comboBoxEx1->Name = L"comboBoxEx1";
			this->comboBoxEx1->Size = System::Drawing::Size(121, 21);
			this->comboBoxEx1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->comboBoxEx1->TabIndex = 8;
			// 
			// fileCategoryLabelX
			// 
			this->fileCategoryLabelX->AutoSize = true;
			// 
			// 
			// 
			this->fileCategoryLabelX->BackgroundStyle->Class = L"";
			this->fileCategoryLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->fileCategoryLabelX->Location = System::Drawing::Point(182, 23);
			this->fileCategoryLabelX->Name = L"fileCategoryLabelX";
			this->fileCategoryLabelX->Size = System::Drawing::Size(68, 18);
			this->fileCategoryLabelX->TabIndex = 9;
			this->fileCategoryLabelX->Text = L"文件类别：";
			// 
			// jobPathTextBoxX
			// 
			// 
			// 
			// 
			this->jobPathTextBoxX->Border->Class = L"TextBoxBorder";
			this->jobPathTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->jobPathTextBoxX->Enabled = false;
			this->jobPathTextBoxX->Location = System::Drawing::Point(13, 80);
			this->jobPathTextBoxX->Name = L"jobPathTextBoxX";
			this->jobPathTextBoxX->Size = System::Drawing::Size(400, 21);
			this->jobPathTextBoxX->TabIndex = 10;
			// 
			// OuSnsJobInfoDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 373);
			this->Controls->Add(this->jobPathTextBoxX);
			this->Controls->Add(this->fileCategoryLabelX);
			this->Controls->Add(this->comboBoxEx1);
			this->Controls->Add(this->cancelAddJobButtonX);
			this->Controls->Add(this->addJobButtonX);
			this->Controls->Add(this->DownloadingJobFileListSuperTab);
			this->Controls->Add(this->jobSizeLabelX);
			this->Controls->Add(this->jobNameLabelX);
			this->Controls->Add(this->fileIconPictureBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"OuSnsJobInfoDlg";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"下载任务资料";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileIconPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DownloadingJobFileListSuperTab))->EndInit();
			this->DownloadingJobFileListSuperTab->ResumeLayout(false);
			this->superTabControlPanel1->ResumeLayout(false);
			this->superTabControlPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->downloadingFileListAdvTree))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelAddJobButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void addJobButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
