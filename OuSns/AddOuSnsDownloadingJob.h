#pragma once
#include "stdafx.h"
#include "SystemSetting.h"

namespace OuSns {

	/// <summary>
	/// AddOuSnsDownloadingJob ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	ref class MainDlg;
	ref class DownloadingJob;
	public ref class AddOuSnsDownloadingJob : DevComponents::DotNetBar::Office2007Form
	{
		DownloadingJob^ addingJob;
		bool validPath;
		//The available space for the drive in MB
		int availableSpace;

		MainDlg^ mainDlg;
	public:
		AddOuSnsDownloadingJob(DownloadingJob^ job,SystemSetting^ sysSetting, MainDlg^ mainDlg);

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~AddOuSnsDownloadingJob()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  fileIconPictureBox;
	private: DevComponents::DotNetBar::LabelX^  jobNameLabelX;
	private: DevComponents::DotNetBar::LabelX^  jobSizeLabelX;
	private: DevComponents::DotNetBar::Controls::ComboTree^  jobPathComboTree;
	private: DevComponents::DotNetBar::ButtonX^  selectFolderButtonX;
	protected: 

	protected: 




	private: DevComponents::DotNetBar::SuperTabControl^  DownloadingJobFileListSuperTab;


	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel1;
	private: DevComponents::DotNetBar::SuperTabItem^  superTabItem1;
	private: DevComponents::AdvTree::AdvTree^  fileListAdvTree;



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
	private: DevComponents::DotNetBar::LabelX^  folderAvailableSpaceLabelX;
	private: DevComponents::DotNetBar::LabelX^  availableSpaceTitleLabelX;
	private: DevComponents::AdvTree::Node^  node2;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->fileIconPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->jobNameLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->jobSizeLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->jobPathComboTree = (gcnew DevComponents::DotNetBar::Controls::ComboTree());
			this->node2 = (gcnew DevComponents::AdvTree::Node());
			this->selectFolderButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->DownloadingJobFileListSuperTab = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel1 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->labelX5 = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
			this->labelX3 = (gcnew DevComponents::DotNetBar::LabelX());
			this->fileListAdvTree = (gcnew DevComponents::AdvTree::AdvTree());
			this->node1 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector1 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle1 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->superTabItem1 = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->addJobButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->cancelAddJobButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->comboBoxEx1 = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->fileCategoryLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->folderAvailableSpaceLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->availableSpaceTitleLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileIconPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DownloadingJobFileListSuperTab))->BeginInit();
			this->DownloadingJobFileListSuperTab->SuspendLayout();
			this->superTabControlPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileListAdvTree))->BeginInit();
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
			this->jobSizeLabelX->Size = System::Drawing::Size(75, 16);
			this->jobSizeLabelX->TabIndex = 2;
			this->jobSizeLabelX->Text = L"jobCategory";
			// 
			// jobPathComboTree
			// 
			this->jobPathComboTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->jobPathComboTree->BackgroundStyle->Class = L"TextBoxBorder";
			this->jobPathComboTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->jobPathComboTree->ButtonDropDown->Visible = true;
			this->jobPathComboTree->Location = System::Drawing::Point(13, 76);
			this->jobPathComboTree->Margin = System::Windows::Forms::Padding(0);
			this->jobPathComboTree->Name = L"jobPathComboTree";
			this->jobPathComboTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node2});
			this->jobPathComboTree->Size = System::Drawing::Size(386, 23);
			this->jobPathComboTree->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->jobPathComboTree->TabIndex = 3;
			this->jobPathComboTree->SelectedIndexChanged += gcnew System::EventHandler(this, &AddOuSnsDownloadingJob::jobPathComboTree_SelectedIndexChanged);
			this->jobPathComboTree->Leave += gcnew System::EventHandler(this, &AddOuSnsDownloadingJob::jobPathComboTree_Leave);
			// 
			// node2
			// 
			this->node2->Checked = true;
			this->node2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->node2->Name = L"node2";
			this->node2->Text = L"node2";
			// 
			// selectFolderButtonX
			// 
			this->selectFolderButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->selectFolderButtonX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->selectFolderButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->selectFolderButtonX->Location = System::Drawing::Point(399, 76);
			this->selectFolderButtonX->Margin = System::Windows::Forms::Padding(0);
			this->selectFolderButtonX->Name = L"selectFolderButtonX";
			this->selectFolderButtonX->Size = System::Drawing::Size(23, 23);
			this->selectFolderButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->selectFolderButtonX->TabIndex = 4;
			this->selectFolderButtonX->Text = L"folder";
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
			this->DownloadingJobFileListSuperTab->Location = System::Drawing::Point(13, 115);
			this->DownloadingJobFileListSuperTab->Name = L"DownloadingJobFileListSuperTab";
			this->DownloadingJobFileListSuperTab->ReorderTabsEnabled = true;
			this->DownloadingJobFileListSuperTab->SelectedTabFont = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Bold));
			this->DownloadingJobFileListSuperTab->SelectedTabIndex = 0;
			this->DownloadingJobFileListSuperTab->Size = System::Drawing::Size(400, 225);
			this->DownloadingJobFileListSuperTab->TabFont = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
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
			this->superTabControlPanel1->Controls->Add(this->fileListAdvTree);
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
			// fileListAdvTree
			// 
			this->fileListAdvTree->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->fileListAdvTree->AllowDrop = true;
			this->fileListAdvTree->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->fileListAdvTree->BackgroundStyle->Class = L"TreeBorderKey";
			this->fileListAdvTree->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->fileListAdvTree->Location = System::Drawing::Point(2, 4);
			this->fileListAdvTree->Name = L"fileListAdvTree";
			this->fileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
			this->fileListAdvTree->NodesConnector = this->nodeConnector1;
			this->fileListAdvTree->NodeStyle = this->elementStyle1;
			this->fileListAdvTree->PathSeparator = L";";
			this->fileListAdvTree->Size = System::Drawing::Size(394, 169);
			this->fileListAdvTree->Styles->Add(this->elementStyle1);
			this->fileListAdvTree->TabIndex = 0;
			this->fileListAdvTree->Text = L"advTree1";
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
			// superTabItem1
			// 
			this->superTabItem1->AttachedControl = this->superTabControlPanel1;
			this->superTabItem1->GlobalItem = false;
			this->superTabItem1->Name = L"superTabItem1";
			this->superTabItem1->Text = L"�ļ��б�";
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
			this->addJobButtonX->Text = L"�������";
			this->addJobButtonX->Click += gcnew System::EventHandler(this, &AddOuSnsDownloadingJob::addJobButtonX_Click);
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
			this->cancelAddJobButtonX->Text = L"ȡ��";
			this->cancelAddJobButtonX->Click += gcnew System::EventHandler(this, &AddOuSnsDownloadingJob::cancelAddJobButtonX_Click);
			// 
			// comboBoxEx1
			// 
			this->comboBoxEx1->DisplayMember = L"Text";
			this->comboBoxEx1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
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
			this->fileCategoryLabelX->Text = L"�ļ����";
			// 
			// folderAvailableSpaceLabelX
			// 
			this->folderAvailableSpaceLabelX->AutoSize = true;
			// 
			// 
			// 
			this->folderAvailableSpaceLabelX->BackgroundStyle->Class = L"";
			this->folderAvailableSpaceLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->folderAvailableSpaceLabelX->Location = System::Drawing::Point(84, 100);
			this->folderAvailableSpaceLabelX->Name = L"folderAvailableSpaceLabelX";
			this->folderAvailableSpaceLabelX->Size = System::Drawing::Size(81, 18);
			this->folderAvailableSpaceLabelX->TabIndex = 14;
			this->folderAvailableSpaceLabelX->Text = L"Ӳ�̿��ô�С";
			// 
			// availableSpaceTitleLabelX
			// 
			this->availableSpaceTitleLabelX->AutoSize = true;
			// 
			// 
			// 
			this->availableSpaceTitleLabelX->BackgroundStyle->Class = L"";
			this->availableSpaceTitleLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->availableSpaceTitleLabelX->Location = System::Drawing::Point(13, 100);
			this->availableSpaceTitleLabelX->Margin = System::Windows::Forms::Padding(0);
			this->availableSpaceTitleLabelX->Name = L"availableSpaceTitleLabelX";
			this->availableSpaceTitleLabelX->Size = System::Drawing::Size(68, 18);
			this->availableSpaceTitleLabelX->TabIndex = 13;
			this->availableSpaceTitleLabelX->Text = L"ʣ��ռ䣺";
			// 
			// AddOuSnsDownloadingJob
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 373);
			this->Controls->Add(this->folderAvailableSpaceLabelX);
			this->Controls->Add(this->availableSpaceTitleLabelX);
			this->Controls->Add(this->fileCategoryLabelX);
			this->Controls->Add(this->comboBoxEx1);
			this->Controls->Add(this->cancelAddJobButtonX);
			this->Controls->Add(this->addJobButtonX);
			this->Controls->Add(this->DownloadingJobFileListSuperTab);
			this->Controls->Add(this->selectFolderButtonX);
			this->Controls->Add(this->jobPathComboTree);
			this->Controls->Add(this->jobSizeLabelX);
			this->Controls->Add(this->jobNameLabelX);
			this->Controls->Add(this->fileIconPictureBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddOuSnsDownloadingJob";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"���OuSns��������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileIconPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DownloadingJobFileListSuperTab))->EndInit();
			this->DownloadingJobFileListSuperTab->ResumeLayout(false);
			this->superTabControlPanel1->ResumeLayout(false);
			this->superTabControlPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileListAdvTree))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelAddJobButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
			 System::Void CalculateDiskAvailableSpace(String^ path){
				 this->folderAvailableSpaceLabelX->Text = "";
				 this->availableSpace = 0;
				// this->mainDlg->msgCreator->MakeCommandEntry()

			 }
private: System::Void addJobButtonX_Click(System::Object^  sender, System::EventArgs^  e){}
private: System::Void jobPathComboTree_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			this->ValidateDirectory();
		 }
private: System::Void jobPathComboTree_Leave(System::Object^  sender, System::EventArgs^  e) {
			this->ValidateDirectory();
		 }
private: System::Void ValidateDirectory(){
			 if(Directory::Exists(this->jobPathComboTree->SelectedNode->Text)){
				 this->CalculateDiskAvailableSpace(this->jobPathComboTree->SelectedNode->Text);
				 this->validPath = true;
			 }
			 else{
				 this->folderAvailableSpaceLabelX->Text = "";
				 this->availableSpace = 0;
				 this->validPath = false;
			 }
		 }
};
}
