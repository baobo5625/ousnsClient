#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for SystemMessageNotificationDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SystemMessageNotificationDlg : public System::Windows::Forms::Form
	{
	public:
		SystemMessageNotificationDlg(String^ contentInput)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->content->Text = contentInput;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SystemMessageNotificationDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::ButtonX^  buttonOK;
	protected: 

	private: DevComponents::DotNetBar::LabelX^  content;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOK = (gcnew DevComponents::DotNetBar::ButtonX());
			this->content = (gcnew DevComponents::DotNetBar::LabelX());
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonOK->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonOK->Location = System::Drawing::Point(103, 106);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonOK->TabIndex = 0;
			this->buttonOK->Text = L"È·¶¨";
			this->buttonOK->Click += gcnew System::EventHandler(this, &SystemMessageNotificationDlg::buttonOK_Click);
			// 
			// content
			// 
			// 
			// 
			// 
			this->content->BackgroundStyle->Class = L"";
			this->content->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->content->Location = System::Drawing::Point(12, 13);
			this->content->Name = L"content";
			this->content->Size = System::Drawing::Size(259, 87);
			this->content->TabIndex = 2;
			this->content->Text = L"labelX1";
			// 
			// SystemMessageNotificationDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 149);
			this->Controls->Add(this->content);
			this->Controls->Add(this->buttonOK);
			this->Name = L"SystemMessageNotificationDlg";
			this->Text = L"SystemMessageNotificationDlg";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->DialogResult = ::DialogResult::OK;
				 this->Close();
			 }
	};
}
