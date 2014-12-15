#include "stdAfx.h"
#include "MainDlg1.h"
#include "friendChatDlg.h"
#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageProcessor.h"
#include "FriendListTab.h"
#include "DownloadingJob.h"
#include "OusnsFriend.h"
#include "OusnsGroup.h"
#include "SearchResult.h"
#include "OusnsLoginUser.h"
#include "DownloadFileTab.h"


/*
* This function will change the users status to the desired one
* This function will change the user status to the desired one.
* This function will take ONLY 2 params:
* OuID, the type is unsigned int, this is the user that will be 
*		changed (This ID will be validated throught the login user friend list.
* Status, type is int, it is the status that will be changed to.
*/
System::Void MainDlg::ChangeUserStatus(LinkedList<Object^>^ params){
	return;
}



/*
* This function will be called when there is a response for the request that search specific group
* This function will dynamically cast the object to the object type SearchResult, in which will contains a dictionary with key as the column header¡¯s name (same as the tags in the XML).
* Each Object represent a search result entry.
*/
System::Void MainDlg::DisplaySearchFileResult(int totalResult, int offset, LinkedList<SearchResult^>^ searchResults){

}


/*
* This function will be called when there is a response for the request that the login user is changing one of his personal information, like the birthday.
* This function will take ONLY 1 param.
* ousnsLoginUser, the type is OusnsLoginUser. This function will dynamically cast the first element in the param to OusnsLoginUser type and display this user¡¯s personal information in the UI.
*/
System::Void MainDlg::DisplayLoginUserPersonalInfo(LinkedList<Object^>^ params){
}


/* 
* This function will be called when there is a response for the request that the login user is querying one of his friends/focus user/ group member¡¯s sharing file list.
* This function will take ONLY 2 params.
* ouID, the type is unisigned int. This function will dynamically cast the first element in the param to the OuID.
* sharedFileList, the type is LinkedList<SharedFile^>^, the function will dynamically cast the second element in the param to LinkedList<SharedFile^>^
* These information will be update in userShareFileList variable kept in the MainDlg, update to the UI if necessary (like when the user is browsing this user¡¯s sharing file list)
*/
System::Void MainDlg::UpdateUserSharingFileList(LinkedList<Object^>^ params){
}

/*
* This function will be called when there is a response for the request that the login user is querying one of his group sharing file list.
* This function will take ONLY 2 params.
*		ouID, the type is unisigned int. This function will dynamically cast the first element in the param to the OuID of the group.
*		sharedFileList, the type is LinkedList<SharedFile^>^, the function will dynamically cast the second element in the param to LinkedList<SharedFile^>^
* These information will be update in groupShareFileList variable kept in the MainDlg, update to the UI if necessary (like when the user is browsing this group¡¯s sharing file list)
*/
System::Void MainDlg::UpdateGroupSharingFileList(LinkedList<Object^>^ params){
}

/*
* This function will be called if the user request log off (send logoff request) or  the network connection was unavailable (like rise the exception ) or the user changed his status to offline.
*/
System::Void MainDlg::SwitchToOffLine(){
	
}






System::Void MainDlg::ModifyDataGridViewRows(LinkedList<Object^>^ params){
	//DataGridView^ gridview,DataGridViewRow^ row,int rowIndex,OuSns::ModifyAction action){
	LinkedListNode<Object^>^ node = params->First;
	DataGridView^ gridview = dynamic_cast<DataGridView^>(node->Value);
	node = node->Next;
	DataGridViewRow^ row = dynamic_cast<DataGridViewRow^>(node->Value);
	node = node->Next;
	int rowIndex = (int)(node->Value);
	node = node->Next;
	OuSns::ModifyAction action = (OuSns::ModifyAction)(int)(node->Value);

	gridview->SuspendLayout();
	switch(action){
		case OuSns::ACTION_ADD:
			gridview->Rows->Insert(rowIndex,row);
			break;
		case OuSns::ACTION_MODIFY:
			gridview->Rows[rowIndex] = row;
			break;
		case OuSns::ACTION_REMOVE:
			gridview->Rows->RemoveAt(rowIndex);
			break;
		default:
			break;
	}
	gridview->ResumeLayout();

}