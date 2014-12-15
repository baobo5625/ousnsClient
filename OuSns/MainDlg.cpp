#include "stdAfx.h"
#include "MainDlg1.h"
#include "friendChatDlg.h"
#include "GroupChatDlg.h"
#include "Communication.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "DownloadingJob.h"
#include "OusnsFriend.h"
#include "OusnsGroup.h"
#include "NewsUpdateTab.h"
#include "FriendListTab.h"
#include "DownloadFileTab.h"
#include "FocusUserTab.h"
#include "RecommendFocusTab.h"
#include "GroupListTab.h"
#include "PersonalSettingTab.h"
#include "ShareFileListTab.h"
#include "OusnsLoginUser.h"
#include "SearchUserResultForm.h"


#define BUFFER_SIZE 1024

using namespace OuSns;

MainDlg::MainDlg(OusnsLoginUser ^ usr, Communication^ comm) {
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//

	//Common part
	ressrc = L"OuSns.ImageResource";
	execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
	myres = gcnew Resources::ResourceManager(ressrc,execAssem);
	this->isDown = false;
	this->loactionStyle = OuSns::S22_MIDDLECENTER;

	this->comm = comm;
	this->loginUser = usr;
	this->msgCreator = comm->msgCreator;
	this->comm->loginUser = usr;
	this->comm->mainDlg = this;
	this->comm->msgProcessor->mainDlg = this;
	this->comm->msgProcessor->loginUser = this->loginUser;
	
	this->pending_msg_total = 0;
	
	
	
	
	//this->downloadedJobDict = gcnew Dictionary<String^,DownloadingJob^>();
	this->downloadedJobArray = gcnew LinkedList<DownloadingJob^>();
	this->downloadedJobArrayModified = false;
	this->downloadingJobDict = gcnew Dictionary<String^,DownloadingJob^>();
	this->downloadingJobDictModified = false;




	this->comm->startedMainDlg = true;
	this->comm->UserLoginLogoff(true);

	this->statusComboBoxEx->SelectedIndex = this->loginUser->Status;



	this->newNewsUpdateTab = gcnew NewsUpdateTab();
	this->newNewsUpdateTab->TopLevel = false;
	this->newNewsUpdateTab->Parent = this;
	
	this->superTabControlPanel2->Controls->Add(this->newNewsUpdateTab);
	//this->newNewsUpdateTab->Show();

	this->newFriendListTab = gcnew OuSns::FriendListTab(this,this->comm,this->loginUser);
	this->newFriendListTab->TopLevel = false;
	this->newFriendListTab->Parent = this;
	this->superTabControlPanel3->Controls->Add(this->newFriendListTab);
	//this->newFriendListTab->Show();
	this->newGroupListTab = gcnew OuSns::GroupListTab(this,this->comm,this->loginUser,this->msgCreator);
	this->newGroupListTab->TopLevel = false;
	this->newGroupListTab->Parent = this;
	this->superTabControlPanel4->Controls->Add(this->newGroupListTab);
	
	this->newPersonalSettingTab = gcnew OuSns::PersonalSettingTab(this);
	this->newPersonalSettingTab->TopLevel = false;
	this->newPersonalSettingTab->Parent = this;
	this->superTabControlPanel8->Controls->Add(this->newPersonalSettingTab);

	
	this->newRecommendFocusTab = gcnew OuSns::RecommendFocusTab();
	this->newRecommendFocusTab->TopLevel = false;
	this->newRecommendFocusTab->Parent = this;
	this->superTabControlPanel7->Controls->Add(this->newRecommendFocusTab);

	this->newDownloadFileTab = gcnew OuSns::DownloadFileTab(this,this->msgCreator);
	this->newDownloadFileTab->TopLevel = false;
	this->newDownloadFileTab->Parent = this;
	this->superTabControlPanel10->Controls->Add(this->newDownloadFileTab);

	this->newFocusUserTab = gcnew OuSns::FocusUserTab(this,this->loginUser);
	this->newFocusUserTab->TopLevel = false;
	this->newFocusUserTab->Parent = this;
	this->superTabControlPanel6->Controls->Add(this->newFocusUserTab);
	
	this->newShareFileListTab = gcnew OuSns::ShareFileListTab();
	this->newShareFileListTab->TopLevel = false;
	this->newShareFileListTab->Parent = this;
	this->superTabControlPanel5->Controls->Add(this->newShareFileListTab);
	


	this->searchUserResultForm = gcnew OuSns::SearchUserResultForm(this);
	this->searchUserResultForm->TopLevel = false;



	//Complete the followings:
	/*OusnsMessage^ getFriendListMsg = this->msgCreator->\
		MakeGetFriendListMessage(this->loginUser->userID, this->loginUser->sessionID, this->comm->serverAddr,this->comm->serverPort);
	this->comm->AddToWorkQueue(getFriendListMsg);

	OusnsMessage^ getGroupListMsg = this->msgCreator->MakeDownloadGroupListMessage(this->loginUser->UserID, this->loginUser->SessionID);
	this->comm->AddToWorkQueue(getGroupListMsg);
	*/
	OusnsMessage^ downloadListMsg = this->msgCreator->MakeDownloadListMessage(this->loginUser->userID, this->loginUser->sessionID, this->comm->serverAddr,this->comm->serverPort);
	OusnsMessage^ getOfflineMsg = this->msgCreator->MakeGetOfflineMessage(this->loginUser->UserID,this->loginUser->SessionID);
	this->comm->AddToWorkQueue(getOfflineMsg);

	this->mainTabWindow->SelectedTab = this->newUpdatesTab;
	
	this->newNewsUpdateTab->Show();
	this->currentActivePage = safe_cast<Form^>(this->newNewsUpdateTab);

	




}

System::Void MainDlg::PushChatMessageToUI(ChatMessage ^ msg) {
	
	OusnsFriend ^ target_friend = this->loginUser->FindFriend(msg->srcID);
	if (target_friend == nullptr) {
		MessageBox::Show("No such friend exists! Who is this guy?\nText: " + msg->text);
		return;
	}
	
	
	if (this->newFriendListTab->friend_chat_dlg_list->ContainsKey(msg->srcID)) { // Push the received message into the corresponding
																		  // active window.
		NewMessageDelegate ^ msg_delegate = gcnew NewMessageDelegate(this->newFriendListTab->friend_chat_dlg_list[target_friend->userID], 
			&friendChatDlg::push_new_message);
		array<Object ^>^ args = {msg};
		this->Invoke(msg_delegate, args);

		ActionDelegate ^ windowBlinkDelegate = gcnew ActionDelegate(this->newFriendListTab->friend_chat_dlg_list[target_friend->userID], &friendChatDlg::Blink);
		this->Invoke(windowBlinkDelegate); 
		
	} else { // Display an unread message count on the corresponding user icon and the friend list panel/tab.
		if (this->newFriendListTab->msgs_by_user->ContainsKey(target_friend)) {
			this->newFriendListTab->msgs_by_user[target_friend]->AddLast(msg);
		} else {
			this->newFriendListTab->msgs_by_user[target_friend] = gcnew LinkedList<ChatMessage^>();
			this->newFriendListTab->msgs_by_user[target_friend]->AddLast(msg);
		}
		if (this->newFriendListTab->pending_counts_by_user->ContainsKey(target_friend)) {
			this->newFriendListTab->pending_counts_by_user[target_friend] += 1;
		} else {
			this->newFriendListTab->pending_counts_by_user[target_friend] = 1;
		}

		this->pending_msg_total += 1;

		// Since this function will be called from the Work Thread, we need a delegate to update the UI.
		UpdateInfoDelegate ^ updateUnreadCountDelegate = gcnew UpdateInfoDelegate(this, &MainDlg::DisplayUnreadCount);
		array<Object ^>^ args = {msg->srcID};
		this->Invoke(updateUnreadCountDelegate, args);
		
	}

}

System::Void MainDlg::PushStatusChangeToUI(int srcID, int status) {

}




/* Delegate function. Used for main thread to update the UI when receiving a message when the friend chat
 * window is inactive.
 */
System::Void MainDlg::DisplayUnreadCount(unsigned int srcID) {
	
	
	OusnsFriend ^ target_friend = this->loginUser->FindFriend(srcID);

	for each(DevComponents::DotNetBar::ButtonItem^ i in this->newFriendListTab->myFriendListSideBarPanelItem->SubItems){
		if (i->Name->Substring(13) == target_friend->userID.ToString()) {
			i->Text = target_friend->nickname + L"(" + this->newFriendListTab->pending_counts_by_user[target_friend] + ")";
			this->newFriendListTab->myFriendListSideBarPanelItem->Refresh();
			break;
		}
		
	}
	this->friendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
	this->newFriendListTab->myFriendListTab->Text = "我的好友" + L"(" + pending_msg_total.ToString() + ")";
}

System::Void MainDlg::ChangeOnlineStatus(Object^ sender, EventArgs^ e) {
	OuSns::UserStatus status = (OuSns::UserStatus)this->statusComboBoxEx->SelectedIndex;
	int prevStatus = this->loginUser->status;
	this->loginUser->status = status;

	//LinkedList <OusnsFriend ^> ^ friends = this->loginUser->friendList;
	IPAddress ^ srcIP = this->loginUser->ipAddr;
	unsigned int srcPort = this->loginUser->recvPort;
	OusnsFriend ^ f;
	int i;
	for(i = 0; i <this->loginUser->friendListArray->Length; i++){
		f = this->loginUser->friendListArray[i];
	//for each (OusnsFriend ^ f in this->loginUser->friendList) {
		if (f->status != OuSns::OFFLINE) {
			IPAddress ^ destIP = f->ipAddr;
			int destPort = f->recvPort;
			int srcID = this->loginUser->userID;
			//this->comm->SendChangeStatusPeer(status, srcID, destIP, destPort);
			String ^ sessionID = this->loginUser->sessionID;
			OusnsMessage ^ message = this->comm->msgCreator->MakeChangeStatusPeer(status, 
				prevStatus, srcID, sessionID, srcIP, srcPort, this->loginUser->natType, destIP, destPort);

			this->comm->AddToWorkQueue(message);
		}
	}
	// TODO: Send CHANGESTATUS request to server.
	OusnsMessage^ msg = this->comm->msgCreator->MakeChangeStatusMessage(this->loginUser->UserID, this->loginUser->SessionID, status);
	this->comm->AddToWorkQueue(msg);
}

System::Void MainDlg::CloseButtonClick(Object^ sender, EventArgs^ e) {
	Application::Exit();
}




System::Void MainDlg::LogoffProcedure(){
	int prevStatus = this->loginUser->status;
	this->loginUser->status = OFFLINE;

	IPAddress ^ srcIP = this->loginUser->ipAddr;
	unsigned short srcPort = this->loginUser->recvPort;
	OusnsFriend ^ f;
	int i;
	for(i = 0; i <this->loginUser->friendListArray->Length; i++){
		f = this->loginUser->friendListArray[i];
	//for each (OusnsFriend ^ f in this->loginUser->friendList) {
		if (f->status != OuSns::OFFLINE) {
			IPAddress ^ destIP = f->ipAddr;
			int destPort = f->recvPort;
			int srcID = this->loginUser->userID;
			//this->comm->SendChangeStatusPeer(status, srcID, destIP, destPort);
			String ^ sessionID = this->loginUser->sessionID;
			OusnsMessage ^ message = this->msgCreator->MakeChangeStatusPeer(OuSns::OFFLINE, 
				prevStatus, srcID, sessionID, srcIP, srcPort, this->loginUser->natType, destIP, destPort);

			this->comm->AddToWorkQueue(message);
		}
	}
	OusnsMessage^ msg = this->msgCreator->MakeLogoffMessage(this->loginUser->userID, this->loginUser->sessionID);
	this->comm->AddToWorkQueue(msg);
	//OusnsMessage^ logoffMsg = this->msgCreator->
	this->comm->UserLoginLogoff(false);
	this->comm->startedMainDlg = false;
	this->Hide();

	while(this->comm->workQueue->Count || this->comm->sendQueue->Count||\
		this->comm->sendPacketQueue->Count || this->comm->receivedPacketQueue->Count ||\
		this->comm->partialMessageQueue->Count){
			Sleep(10);
	}

	if (this->comm->workThread != nullptr) {
		this->comm->isListenThreadRunning = false;
		this->comm->listenThread->Join(1000);
		this->comm->isWorkThreadRunning = false;
		this->comm->workThread->Join(1000);
		this->comm->isSendThreadRunning = false;
		this->comm->sendThread->Join(1000);
		this->comm->isCommunicationThreadRunning = false;
		this->comm->communicationThread->Join(1000);
		this->comm->isDownloaderCommunicationThreadRunning = false;
		this->comm->downloaderCommunicatonThread->Join(1000);

	}

	Application::Exit();
 }



System::Void MainDlg::MainDlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	 this->LogoffProcedure();
 }


System::Void MainDlg::ListClickAutoCheck(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){

	DevComponents::DotNetBar::ButtonItem^ button = dynamic_cast<DevComponents::DotNetBar::ButtonItem^>(sender);

	DevComponents::DotNetBar::SideBarPanelItem^ buttonParent = \
		dynamic_cast<DevComponents::DotNetBar::SideBarPanelItem^> (button->Parent);
	DevComponents::DotNetBar::ButtonItem^ eachButton;
	//this->superTabControl2->SuspendLayout();
	for each( eachButton in buttonParent->SubItems){
		if(eachButton->Checked)
			eachButton->Checked = false;
	}
	if(e->Button ==::MouseButtons::Right)
		button->Checked = true;
	//this->superTabControl2->ResumeLayout();
}


System::Void MainDlg::Tab_Click(System::Object^  sender, System::EventArgs^  e) {
	this->currentActivePage->Hide();
	switch(this->mainTabWindow->SelectedTabIndex){
				 case 4:
					 this->newNewsUpdateTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newNewsUpdateTab);
					 break;
				 case 5:
					 this->newFriendListTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newFriendListTab);
					 break;
				 case 6:
					 this->newGroupListTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newGroupListTab);
					 break;
				 case 7:
					 this->newShareFileListTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newShareFileListTab);
					 break;
				 case 8:
					 this->newDownloadFileTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newDownloadFileTab);
					 break;
				 case 10:
					 this->newFocusUserTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newFocusUserTab);
					 break;
				 case 11:
					 this->newRecommendFocusTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newRecommendFocusTab);
					 break;
				 case 12:
					 this->newPersonalSettingTab->Show();
					 this->currentActivePage = safe_cast<Form^>(this->newPersonalSettingTab);
					 break;
				 default:
					 this->currentActivePage->Show();
	}
}