#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// SearchUserResultForm 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	ref class MainDlg;
	ref class SearchResult;
	public ref class SearchUserResultForm : public System::Windows::Forms::Form
	{
	public:
		MainDlg^ mainDlg;
		int searchFriendOffSet;
		LinkedList<SearchResult^>^ searchResults;
		String^ columnHeader1;
		String^ columnHeader2;
		String^ columnHeader3;
		SearchUserResultForm(MainDlg^ mainDlgInput);
	private: DevComponents::DotNetBar::LabelX^  searchFriendNextPageLabelX;
	public: 
	private: DevComponents::DotNetBar::LabelX^  searchFriendPreviousPageLabelX;
	private: DevComponents::DotNetBar::ButtonX^  searchFriendAddFriendButton;
			 
		

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~SearchUserResultForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::Controls::ListViewEx^  searchFriendResultList;
	protected: 
	private: System::Windows::Forms::ColumnHeader^  searchFriendIDColumn;
	private: System::Windows::Forms::ColumnHeader^  searchFriendInfoColumn;

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
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {L"tester1", 
				L"tester2", L"tester3333"}, -1));
			this->searchFriendResultList = (gcnew DevComponents::DotNetBar::Controls::ListViewEx());
			this->searchFriendIDColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->searchFriendInfoColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->searchFriendNextPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFriendPreviousPageLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->searchFriendAddFriendButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->SuspendLayout();
			// 
			// searchFriendResultList
			// 
			// 
			// 
			// 
			this->searchFriendResultList->Border->Class = L"ListViewBorder";
			this->searchFriendResultList->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendResultList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->searchFriendIDColumn, 
				this->searchFriendInfoColumn});
			this->searchFriendResultList->FullRowSelect = true;
			this->searchFriendResultList->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) {listViewItem2});
			this->searchFriendResultList->Location = System::Drawing::Point(0, 0);
			this->searchFriendResultList->MultiSelect = false;
			this->searchFriendResultList->Name = L"searchFriendResultList";
			this->searchFriendResultList->Size = System::Drawing::Size(520, 280);
			this->searchFriendResultList->TabIndex = 7;
			this->searchFriendResultList->UseCompatibleStateImageBehavior = false;
			this->searchFriendResultList->View = System::Windows::Forms::View::Details;
			// 
			// searchFriendIDColumn
			// 
			this->searchFriendIDColumn->Text = L"OuID";
			this->searchFriendIDColumn->Width = 120;
			// 
			// searchFriendInfoColumn
			// 
			this->searchFriendInfoColumn->Text = L"昵称";
			this->searchFriendInfoColumn->Width = 400;
			// 
			// searchFriendNextPageLabelX
			// 
			this->searchFriendNextPageLabelX->AutoSize = true;
			this->searchFriendNextPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFriendNextPageLabelX->BackgroundStyle->Class = L"";
			this->searchFriendNextPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendNextPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchFriendNextPageLabelX->ForeColor = System::Drawing::Color::DodgerBlue;
			this->searchFriendNextPageLabelX->Location = System::Drawing::Point(57, 286);
			this->searchFriendNextPageLabelX->Name = L"searchFriendNextPageLabelX";
			this->searchFriendNextPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchFriendNextPageLabelX->TabIndex = 13;
			this->searchFriendNextPageLabelX->Text = L"下一页";
			// 
			// searchFriendPreviousPageLabelX
			// 
			this->searchFriendPreviousPageLabelX->AutoSize = true;
			this->searchFriendPreviousPageLabelX->BackColor = System::Drawing::Color::Transparent;
			// 
			// 
			// 
			this->searchFriendPreviousPageLabelX->BackgroundStyle->Class = L"";
			this->searchFriendPreviousPageLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->searchFriendPreviousPageLabelX->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->searchFriendPreviousPageLabelX->ForeColor = System::Drawing::Color::Gray;
			this->searchFriendPreviousPageLabelX->Location = System::Drawing::Point(5, 286);
			this->searchFriendPreviousPageLabelX->Name = L"searchFriendPreviousPageLabelX";
			this->searchFriendPreviousPageLabelX->Size = System::Drawing::Size(44, 18);
			this->searchFriendPreviousPageLabelX->TabIndex = 12;
			this->searchFriendPreviousPageLabelX->Text = L"上一页";
			// 
			// searchFriendAddFriendButton
			// 
			this->searchFriendAddFriendButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->searchFriendAddFriendButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->searchFriendAddFriendButton->Location = System::Drawing::Point(429, 296);
			this->searchFriendAddFriendButton->Name = L"searchFriendAddFriendButton";
			this->searchFriendAddFriendButton->Size = System::Drawing::Size(75, 23);
			this->searchFriendAddFriendButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->searchFriendAddFriendButton->TabIndex = 11;
			this->searchFriendAddFriendButton->Text = L"添加为好友";
			// 
			// SearchUserResultForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(520, 333);
			this->ControlBox = false;
			this->Controls->Add(this->searchFriendNextPageLabelX);
			this->Controls->Add(this->searchFriendPreviousPageLabelX);
			this->Controls->Add(this->searchFriendAddFriendButton);
			this->Controls->Add(this->searchFriendResultList);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SearchUserResultForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"SearchUserResultForm";
			this->TransparencyKey = System::Drawing::Color::White;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public:
		System::Void SearchUserResultForm::UpdateSearchResultToUI(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults);
		System::Void SearchUserResultForm::SetColumnHeader(String^ header1, String^ header2,String^ header3);
		System::Void SearchUserResultForm::InitializationResult();
#pragma endregion
	};
}
