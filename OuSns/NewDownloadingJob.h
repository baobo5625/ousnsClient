#include "stdafx.h"
#include "MainDlg1.h"
#pragma once

namespace OuSns {

	/// <summary>
	/// NewDownloadingJob ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
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
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
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
			this->NewDownloadongJobDownloadTitle->Text = L"����������URL: (֧��OuSns����,emule�ʹ������ӣ�";
			// 
			// NewDownloadingJobAddTorrentFileLabelX
			// 
			this->NewDownloadingJobAddTorrentFileLabelX->AutoSize = true;
			// 
			// 
			// 
			this->NewDownloadingJobAddTorrentFileLabelX->BackgroundStyle->Class = L"";
			this->NewDownloadingJobAddTorrentFileLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->NewDownloadingJobAddTorrentFileLabelX->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Underline, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->NewDownloadingJobAddTorrentFileLabelX->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->NewDownloadingJobAddTorrentFileLabelX->Location = System::Drawing::Point(21, 188);
			this->NewDownloadingJobAddTorrentFileLabelX->Name = L"NewDownloadingJobAddTorrentFileLabelX";
			this->NewDownloadingJobAddTorrentFileLabelX->Size = System::Drawing::Size(93, 18);
			this->NewDownloadingJobAddTorrentFileLabelX->TabIndex = 2;
			this->NewDownloadingJobAddTorrentFileLabelX->Text = L"��BT�����ļ�";
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
			this->NewDownloadingJobContinueButtonX->Text = L"����";
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
			this->NewDownloadingJobCancelButtonX->Text = L"ȡ��";
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
			this->Text = L"�½���������";
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
