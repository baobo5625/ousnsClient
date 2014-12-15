
#include "stdafx.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "Communication.h"

#include "friendChatDlg.h"
#include "LoginDlg.h"
#include "MainDlg1.h"
#include "FriendListTab.h"
#include "OusnsFriend.h"
#include "SearchResult.h"
#include "OusnsLoginUser.h"



System::Void MessageProcessor::ProcessAddFriendDecision(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		unsigned int friendUserID = System::Convert::ToUInt32(msg->messageContent);
		unsigned int sysMsgID = System::Convert::ToUInt32(msg->messageID);
		if (msg->returnCode == (int)System::Windows::Forms::DialogResult::Yes) {
			OusnsMessage^ message = this->comm->msgCreator->MakeReplyAddFriendMessage(this->loginUser->userID,this->loginUser->sessionID, friendUserID, 0, sysMsgID);
			this->comm->AddToWorkQueue(message);
		} else if (msg->returnCode == (int)System::Windows::Forms::DialogResult::No) {
			OusnsMessage^ message = this->comm->msgCreator->MakeReplyAddFriendMessage(this->loginUser->userID,this->loginUser->sessionID, friendUserID, 1, sysMsgID);
			this->comm->AddToWorkQueue(message);
		}
	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}

System::Void MessageProcessor::ProcessReplyAddFriend(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node friendinfo = doc.child("RESPONSE");
			
		unsigned int ouID = System::Convert::ToUInt32(AnsiToManagedString((char*)friendinfo.child_value("OuID")));
		String^ email = AnsiToManagedString((char*)friendinfo.child_value("email"));
		String^ nickname = AnsiToManagedString((char*)friendinfo.child_value("nickname"));
		String^ signature = AnsiToManagedString((char*)friendinfo.child_value("signature"));

		IPAddress^ friendIP = IPAddress::Parse(AnsiToManagedString((char*)friendinfo.child_value("friendIP")));
		String^ friendIPString = AnsiToManagedString((char*)friendinfo.child_value("friendIP"));
		unsigned short friendPort = System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendPort")));
		String^ friendProfile = AnsiToManagedString((char*)friendinfo.child_value("friendProfile"));
		String^ friendDPFilename = AnsiToManagedString((char*)friendinfo.child_value("friendDPFileName"));
		String^ sessionID = L"";
		int natType = System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendNatType")));
		OuSns::UserStatus status = (OuSns::UserStatus)System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendStatus")));
		OusnsFriend^ f = gcnew OusnsFriend(ouID,email,nickname,
			signature, friendDPFilename,
			friendIP,friendPort, (OuSns::NatType)natType,friendProfile,status,sessionID);
		bool exist = false;
		if (!this->loginUser->ExistFriend(ouID)) {
			this->loginUser->AddFriend(f);
			OuSns::FriendListTab::ActionDelegate^ delegateFunction = gcnew OuSns::FriendListTab::ActionDelegate(this->mainDlg->newFriendListTab, &OuSns::FriendListTab::UpdateFriendListToUI);
			array<Object ^>^ args = {};
			this->mainDlg->Invoke(delegateFunction, args);

			IPAddress ^ srcIP = this->loginUser->ipAddr;
			int srcPort = this->loginUser->recvPort;
			int destPort = f->recvPort;
			int srcID = this->loginUser->userID;

			OusnsMessage ^ message = this->comm->msgCreator->MakeChangeStatusPeer(this->loginUser->status, 
				OuSns::OFFLINE, this->loginUser->UserID, this->loginUser->SessionID, 
				this->loginUser->IpAddr, this->loginUser->RecvPort, this->loginUser->NatType, f->IpAddr,f->RecvPort);

			this->comm->AddToWorkQueue(message);
		}
	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}



System::Void MessageProcessor::ProcessSearchFriend(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node response = doc.child("RESPONSE");
		String^ messageID = AnsiToManagedString((char*)(response.attribute("messageID").value()));
		
		int returnCode = System::Convert::ToInt32(AnsiToManagedString((char*)(response.attribute("returnCode").value())));
		if(returnCode == 0){
			
			int searchTotalResult = System::Convert::ToInt32(AnsiToManagedString((char*)response.child_value("searchTotalResult")));
			int searchOffset = System::Convert::ToInt32(AnsiToManagedString((char*)response.child_value("searchOffset")));

			LinkedList<SearchResult^>^ results = gcnew LinkedList<SearchResult^>();

			for (int i = 1; i <= searchTotalResult; i++) {
				pugi::xml_node searchResult = response.child(ManagedStringToAnsi("searchResult" + i));
				String^ ouID = AnsiToManagedString((char*)searchResult.child_value("targetUserID"));
				String^ emailID = AnsiToManagedString((char*)searchResult.child_value("emailID"));
				String^ nickname = AnsiToManagedString((char*)searchResult.child_value("nickname"));
			
				SearchResult^ result = gcnew SearchResult();
				result->Set("targetUserID", ouID);
				result->Set("email", emailID);
				result->Set("nickname", nickname);
				results->AddLast(result);
			}

			OuSns::FriendListTab::SearchActionDelegate^ delegateFunction = gcnew OuSns::FriendListTab::SearchActionDelegate(this->mainDlg->newFriendListTab, &OuSns::FriendListTab::DisplaySearchFriendResult);
			array<Object ^>^ args = {searchTotalResult, searchOffset, results};
			this->mainDlg->Invoke(delegateFunction, args);

		}
		else{
			String^ returnMsg;
			switch (returnCode){
				case 1:
					returnMsg = L"²éÕÒºÃÓÑÊ§°Ü";
					break;
				default:
					returnMsg = L"²éÕÒºÃÓÑÊ§°Ü";
			}
			OuSns::LoginDlg::NotifyUIError^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIError(this->loginDlg,&OuSns::LoginDlg::LoginErrorNotification);
			array<Object ^>^ args = {returnMsg};
			this->loginDlg->Invoke(delegateFunction, args);
		}
		
		//Ousns
		//returnMessage->returnCode=returnCode;
		//returnMessage = gcnew OusnsMessage();
		//returnMessage->returnCode = returnCode;

	}
	catch(Exception ^){
		//Process the expcetion part
	}
	return;

}
