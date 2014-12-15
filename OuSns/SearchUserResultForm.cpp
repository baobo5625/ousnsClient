#include "StdAfx.h"
#include "SearchUserResultForm.h"
#include "MainDlg1.h"
#include "SearchResult.h"

SearchUserResultForm::SearchUserResultForm(MainDlg^ mainDlgInput)
{
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//
	this->mainDlg = mainDlgInput;
	this->searchFriendOffSet = 0;
	this->searchResults = gcnew LinkedList<SearchResult^>();
}


void SearchUserResultForm::UpdateSearchResultToUI(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults){
	this->searchResults = searchResults;
	if(totalResult > offset + SEARCH_RESULT_PAGE_LIMIT){
		this->searchFriendNextPageLabelX->Enabled = true;
		this->searchFriendNextPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchFriendNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchFriendNextPageLabelX->Enabled = false;
		this->searchFriendNextPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchFriendNextPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}
	if(offset > SEARCH_RESULT_PAGE_LIMIT){
		this->searchFriendPreviousPageLabelX->Enabled = true;
		this->searchFriendPreviousPageLabelX->ForeColor =System::Drawing::Color::DodgerBlue;
		this->searchFriendPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	else{
		this->searchFriendPreviousPageLabelX->Enabled = false;
		this->searchFriendPreviousPageLabelX->ForeColor =System::Drawing::Color::Gray;
		this->searchFriendPreviousPageLabelX->Cursor = System::Windows::Forms::Cursors::Default;
	}

	SearchResult^ searchResult;
	System::Windows::Forms::ListViewItem^  listViewItem;
	this->searchFriendOffSet = offset;
	for each (searchResult in searchResults){
		listViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {searchResult->Get(this->columnHeader1), 
			searchResult->Get(this->columnHeader2), searchResult->Get(this->columnHeader3)}, -1));
		this->searchFriendResultList->Items->Add(listViewItem);

	}

	return;
}

void SearchUserResultForm::SetColumnHeader(String^ header1, String^ header2,String^ header3){
	this->searchFriendIDColumn->Text = header1;
	this->searchFriendInfoColumn->Text = header2;
	this->columnHeader1 = header1;
	this->columnHeader2 = header2;
	this->columnHeader3 = header3;

}
void SearchUserResultForm::InitializationResult(){
	this->searchFriendResultList->Items->Clear();
}