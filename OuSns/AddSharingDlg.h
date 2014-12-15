#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// AddSharingDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class AddSharingDlg : public System::Windows::Forms::Form
	{
	public:
		AddSharingDlg(void)
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
		~AddSharingDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl1;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel1;
	private: DevComponents::DotNetBar::SuperTabItem^  AddSharingFileSuperTabItem;
	private: DevComponents::DotNetBar::Controls::TextBoxX^  textBoxX1;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel2;
	private: DevComponents::DotNetBar::SuperTabItem^  AddSharingLinkSuperTabItem;


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
			this->superTabControl1 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel1 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->AddSharingFileSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->AddSharingLinkSuperTabItem = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel2 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->textBoxX1 = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->BeginInit();
			this->superTabControl1->SuspendLayout();
			this->superTabControlPanel1->SuspendLayout();
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
			this->superTabControl1->ControlBox->Name = L"";
			this->superTabControl1->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl1->ControlBox->MenuBox, 
				this->superTabControl1->ControlBox->CloseBox});
			this->superTabControl1->ControlBox->Visible = false;
			this->superTabControl1->Controls->Add(this->superTabControlPanel1);
			this->superTabControl1->Controls->Add(this->superTabControlPanel2);
			this->superTabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl1->FixedTabSize = System::Drawing::Size(120, 50);
			this->superTabControl1->Location = System::Drawing::Point(0, 0);
			this->superTabControl1->Name = L"superTabControl1";
			this->superTabControl1->ReorderTabsEnabled = true;
			this->superTabControl1->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl1->SelectedTabIndex = 0;
			this->superTabControl1->Size = System::Drawing::Size(492, 373);
			this->superTabControl1->TabAlignment = DevComponents::DotNetBar::eTabStripAlignment::Left;
			this->superTabControl1->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl1->TabIndex = 0;
			this->superTabControl1->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->AddSharingFileSuperTabItem, 
				this->AddSharingLinkSuperTabItem});
			this->superTabControl1->Text = L"superTabControl1";
			// 
			// superTabControlPanel1
			// 
			this->superTabControlPanel1->Controls->Add(this->textBoxX1);
			this->superTabControlPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel1->Location = System::Drawing::Point(122, 0);
			this->superTabControlPanel1->Name = L"superTabControlPanel1";
			this->superTabControlPanel1->Size = System::Drawing::Size(370, 373);
			this->superTabControlPanel1->TabIndex = 1;
			this->superTabControlPanel1->TabItem = this->AddSharingFileSuperTabItem;
			// 
			// AddSharingFileSuperTabItem
			// 
			this->AddSharingFileSuperTabItem->AttachedControl = this->superTabControlPanel1;
			this->AddSharingFileSuperTabItem->GlobalItem = false;
			this->AddSharingFileSuperTabItem->Name = L"AddSharingFileSuperTabItem";
			this->AddSharingFileSuperTabItem->Text = L"分享本地文件";
			// 
			// AddSharingLinkSuperTabItem
			// 
			this->AddSharingLinkSuperTabItem->AttachedControl = this->superTabControlPanel2;
			this->AddSharingLinkSuperTabItem->GlobalItem = false;
			this->AddSharingLinkSuperTabItem->Name = L"AddSharingLinkSuperTabItem";
			this->AddSharingLinkSuperTabItem->Text = L"分享文件链接";
			// 
			// superTabControlPanel2
			// 
			this->superTabControlPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel2->Location = System::Drawing::Point(122, 0);
			this->superTabControlPanel2->Name = L"superTabControlPanel2";
			this->superTabControlPanel2->Size = System::Drawing::Size(370, 373);
			this->superTabControlPanel2->TabIndex = 0;
			this->superTabControlPanel2->TabItem = this->AddSharingLinkSuperTabItem;
			// 
			// textBoxX1
			// 
			// 
			// 
			// 
			this->textBoxX1->Border->Class = L"TextBoxBorder";
			this->textBoxX1->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->textBoxX1->Location = System::Drawing::Point(28, 26);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(276, 21);
			this->textBoxX1->TabIndex = 0;
			// 
			// AddSharingDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 373);
			this->Controls->Add(this->superTabControl1);
			this->Name = L"AddSharingDlg";
			this->Text = L"AddSharingDlg";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl1))->EndInit();
			this->superTabControl1->ResumeLayout(false);
			this->superTabControlPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
};
}
