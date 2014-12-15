#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// Summary for SystemMessageConfirmationDlg
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SystemMessageConfirmationDlg : public System::Windows::Forms::Form
	{
	public:
		SystemMessageConfirmationDlg(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SystemMessageConfirmationDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::LabelX^  labelX1;
	protected: 
	private: DevComponents::DotNetBar::ButtonX^  buttonX1;

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
			this->labelX1 = (gcnew DevComponents::DotNetBar::LabelX());
			this->buttonX1 = (gcnew DevComponents::DotNetBar::ButtonX());
			this->SuspendLayout();
			// 
			// labelX1
			// 
			// 
			// 
			// 
			this->labelX1->BackgroundStyle->Class = L"";
			this->labelX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->labelX1->Location = System::Drawing::Point(13, 13);
			this->labelX1->Name = L"labelX1";
			this->labelX1->Size = System::Drawing::Size(259, 87);
			this->labelX1->TabIndex = 4;
			this->labelX1->Text = L"labelX1";
			// 
			// buttonX1
			// 
			this->buttonX1->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->buttonX1->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->buttonX1->Location = System::Drawing::Point(104, 106);
			this->buttonX1->Name = L"buttonX1";
			this->buttonX1->Size = System::Drawing::Size(75, 23);
			this->buttonX1->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->buttonX1->TabIndex = 3;
			this->buttonX1->Text = L"È·¶¨";
			// 
			// SystemMessageConfirmationDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 143);
			this->Controls->Add(this->labelX1);
			this->Controls->Add(this->buttonX1);
			this->Name = L"SystemMessageConfirmationDlg";
			this->Text = L"SystemMessageConfirmationDlg";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
