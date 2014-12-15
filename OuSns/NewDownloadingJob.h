#include "stdafx.h"
#include "MainDlg1.h"
#pragma once

namespace OuSns {

	/// <summary>
	/// NewDownloadingJob 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class NewDownloadingJob :  DevComponents::DotNetBar::Office2007Form
	{

	MainDlg^ mainDlg;
	public:
		NewDownloadingJob(MainDlg^ mainDlg)
		{
			InitializeComponent();
			this->mainDlg = mainDlg;
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~NewDownloadingJob()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::Controls::TextBoxX^  NewDownloadingJobInputTextBoxX;
	protected: 

	private: DevComponents::DotNetBar::LabelX^  NewDownloadongJobDownloadTitle;
	private: DevComponents::DotNetBar::LabelX^  NewDownloadingJobAddTorrentFileLabelX;
	private: DevComponents::DotNetBar::ButtonX^  NewDownloadingJobContinueButtonX;
	private: DevComponents::DotNetBar::ButtonX^  NewDownloadingJobCancelButtonX;

	protected: 

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
			this->NewDownloadingJobInputTextBoxX = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->NewDownloadongJobDownloadTitle = (gcnew DevComponents::DotNetBar::LabelX());
			this->NewDownloadingJobAddTorrentFileLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->NewDownloadingJobContinueButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->NewDownloadingJobCancelButtonX = (gcnew DevComponents::DotNetBar::ButtonX());
			this->SuspendLayout();
			// 
			// NewDownloadingJobInputTextBoxX
			// 
			// 
			// 
			// 
			this->NewDownloadingJobInputTextBoxX->Border->Class = L"TextBoxBorder";
			this->NewDownloadingJobInputTextBoxX->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->NewDownloadingJobInputTextBoxX->Location = System::Drawing::Point(21, 33);
			this->NewDownloadingJobInputTextBoxX->Margin = System::Windows::Forms::Padding(0);
			this->NewDownloadingJobInputTextBoxX->Multiline = true;
			this->NewDownloadingJobInputTextBoxX->Name = L"NewDownloadingJobInputTextBoxX";
			this->NewDownloadingJobInputTextBoxX->Size = System::Drawing::Size(400, 150);
			this->NewDownloadingJobInputTextBoxX->TabIndex = 0;
			// 
			// NewDownloadongJobDownloadTitle
			// 
			this->NewDownloadongJobDownloadTitle->AutoSize = true;
			// 
			// 
			// 
			this->NewDownloadongJobDownloadTitle->BackgroundStyle->Class = L"";
			this->NewDownloadongJobDownloadTitle->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->NewDownloadongJobDownloadTitle->Location = System::Drawing::Point(21, 7);
			this->NewDownloadongJobDownloadTitle->Margin = System::Windows::Forms::Padding(0);
			this->NewDownloadongJobDownloadTitle->Name = L"NewDownloadongJobDownloadTitle";
			this->NewDownloadongJobDownloadTitle->Size = System::Drawing::Size(297, 18);
			this->NewDownloadongJobDownloadTitle->TabIndex = 1;
			this->NewDownloadongJobDownloadTitle->Text = L"请输入下载URL: (支持OuSns链接,emule和磁力链接）";
			// 
			// NewDownloadingJobAddTorrentFileLabelX
			// 
			this->NewDownloadingJobAddTorrentFileLabelX->AutoSize = true;
			// 
			// 
			// 
			this->NewDownloadingJobAddTorrentFileLabelX->BackgroundStyle->Class = L"";
			this->NewDownloadingJobAddTorrentFileLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->NewDownloadingJobAddTorrentFileLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->NewDownloadingJobAddTorrentFileLabelX->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->NewDownloadingJobAddTorrentFileLabelX->Location = System::Drawing::Point(21, 188);
			this->NewDownloadingJobAddTorrentFileLabelX->Name = L"NewDownloadingJobAddTorrentFileLabelX";
			this->NewDownloadingJobAddTorrentFileLabelX->Size = System::Drawing::Size(93, 18);
			this->NewDownloadingJobAddTorrentFileLabelX->TabIndex = 2;
			this->NewDownloadingJobAddTorrentFileLabelX->Text = L"打开BT种子文件";
			// 
			// NewDownloadingJobContinueButtonX
			// 
			this->NewDownloadingJobContinueButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->NewDownloadingJobContinueButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->NewDownloadingJobContinueButtonX->Location = System::Drawing::Point(243, 188);
			this->NewDownloadingJobContinueButtonX->Name = L"NewDownloadingJobContinueButtonX";
			this->NewDownloadingJobContinueButtonX->Size = System::Drawing::Size(75, 23);
			this->NewDownloadingJobContinueButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->NewDownloadingJobContinueButtonX->TabIndex = 3;
			this->NewDownloadingJobContinueButtonX->Text = L"继续";
			this->NewDownloadingJobContinueButtonX->Click += gcnew System::EventHandler(this, &NewDownloadingJob::NewDownloadingJobContinueButtonX_Click);
			// 
			// NewDownloadingJobCancelButtonX
			// 
			this->NewDownloadingJobCancelButtonX->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->NewDownloadingJobCancelButtonX->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->NewDownloadingJobCancelButtonX->Location = System::Drawing::Point(338, 188);
			this->NewDownloadingJobCancelButtonX->Name = L"NewDownloadingJobCancelButtonX";
			this->NewDownloadingJobCancelButtonX->Size = System::Drawing::Size(75, 23);
			this->NewDownloadingJobCancelButtonX->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->NewDownloadingJobCancelButtonX->TabIndex = 4;
			this->NewDownloadingJobCancelButtonX->Text = L"取消";
			this->NewDownloadingJobCancelButtonX->Click += gcnew System::EventHandler(this, &NewDownloadingJob::NewDownloadingJobCancelButtonX_Click);
			// 
			// NewDownloadingJob
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 223);
			this->Controls->Add(this->NewDownloadingJobCancelButtonX);
			this->Controls->Add(this->NewDownloadingJobContinueButtonX);
			this->Controls->Add(this->NewDownloadingJobAddTorrentFileLabelX);
			this->Controls->Add(this->NewDownloadongJobDownloadTitle);
			this->Controls->Add(this->NewDownloadingJobInputTextBoxX);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"NewDownloadingJob";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"新建下载任务";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NewDownloadingJobContinueButtonX_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NewDownloadingJobCancelButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};

}
