#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// tester 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class tester : public System::Windows::Forms::Form
	{
	public:
		tester(void)
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
		~tester()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::ItemPanel^  itemPanel1;
	protected: 
	private: DevComponents::DotNetBar::ItemContainer^  itemContainer1;
	private: DevComponents::DotNetBar::ButtonItem^  buttonItem1;
	private: DevComponents::DotNetBar::ComboBoxItem^  comboBoxItem1;
	private: DevComponents::DotNetBar::LabelItem^  labelItem1;
	private: DevComponents::DotNetBar::ColorPickerDropDown^  colorPickerDropDown1;
	private: DevComponents::DotNetBar::ProgressBarItem^  progressBarItem1;

	protected: 





















	private: System::ComponentModel::IContainer^  components;

	protected: 



	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->itemPanel1 = (gcnew DevComponents::DotNetBar::ItemPanel());
			this->buttonItem1 = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->itemContainer1 = (gcnew DevComponents::DotNetBar::ItemContainer());
			this->comboBoxItem1 = (gcnew DevComponents::DotNetBar::ComboBoxItem());
			this->labelItem1 = (gcnew DevComponents::DotNetBar::LabelItem());
			this->colorPickerDropDown1 = (gcnew DevComponents::DotNetBar::ColorPickerDropDown());
			this->progressBarItem1 = (gcnew DevComponents::DotNetBar::ProgressBarItem());
			this->SuspendLayout();
			// 
			// itemPanel1
			// 
			// 
			// 
			// 
			this->itemPanel1->BackgroundStyle->Class = L"ItemPanel";
			this->itemPanel1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->itemPanel1->ContainerControlProcessDialogKey = true;
			this->itemPanel1->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(6) {this->itemContainer1, this->buttonItem1, 
				this->comboBoxItem1, this->labelItem1, this->colorPickerDropDown1, this->progressBarItem1});
			this->itemPanel1->LayoutOrientation = DevComponents::DotNetBar::eOrientation::Vertical;
			this->itemPanel1->Location = System::Drawing::Point(134, 215);
			this->itemPanel1->Name = L"itemPanel1";
			this->itemPanel1->Size = System::Drawing::Size(421, 108);
			this->itemPanel1->TabIndex = 0;
			this->itemPanel1->Text = L"itemPanel1";
			// 
			// buttonItem1
			// 
			this->buttonItem1->Name = L"buttonItem1";
			this->buttonItem1->Text = L"buttonItem1";
			// 
			// itemContainer1
			// 
			// 
			// 
			// 
			this->itemContainer1->BackgroundStyle->Class = L"";
			this->itemContainer1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->itemContainer1->Name = L"itemContainer1";
			// 
			// comboBoxItem1
			// 
			this->comboBoxItem1->DropDownHeight = 106;
			this->comboBoxItem1->ItemHeight = 16;
			this->comboBoxItem1->Name = L"comboBoxItem1";
			// 
			// labelItem1
			// 
			this->labelItem1->Name = L"labelItem1";
			this->labelItem1->Text = L"labelItem1";
			// 
			// colorPickerDropDown1
			// 
			this->colorPickerDropDown1->Name = L"colorPickerDropDown1";
			this->colorPickerDropDown1->Text = L"colorPickerDropDown1";
			// 
			// progressBarItem1
			// 
			// 
			// 
			// 
			this->progressBarItem1->BackStyle->Class = L"";
			this->progressBarItem1->BackStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->progressBarItem1->ChunkGradientAngle = 0;
			this->progressBarItem1->MenuVisibility = DevComponents::DotNetBar::eMenuVisibility::VisibleAlways;
			this->progressBarItem1->Name = L"progressBarItem1";
			this->progressBarItem1->RecentlyUsed = false;
			// 
			// tester
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 611);
			this->Controls->Add(this->itemPanel1);
			this->Name = L"tester";
			this->Text = L"tester";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
