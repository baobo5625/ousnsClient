
#include "stdafx.h"
#include "OusnsFriend.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "Communication.h"
//#include "friendChatDlg.h"
#include "LoginDlg.h"
#include "MainDlg1.h"
#include "FriendListTab.h"
#include "OusnsLoginUser.h"
#include "GroupListTab.h"



System::Void MessageProcessor::ProcessSysReplyAddFriend(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node friendinfo = doc.child("SYSMSG");
		String^ messageID = AnsiToManagedString((char*)(friendinfo.attribute("messageID").value()));
		String^ friendUserID = AnsiToManagedString((char*)friendinfo.child_value("OuID"));
		int decision = System::Convert::ToUInt32(AnsiToManagedString((char*)friendinfo.child_value("replyResult")));

		if (decision == 0) {
			String^ content = friendUserID + "已通过您的好友申请";
			array<String^>^ buttonText = {"确定"};
			NotifyUINonBlocking(OuSns::INFORMATION_DLG, content, buttonText, OuSns::REPLYADDFRIENDNOTIFICATION, messageID, friendUserID, this->comm->serverAddr,this->comm->serverPort, this->comm);

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
			if (!this->loginUser->ExistFriend(ouID)) {
				this->loginUser->AddFriend(f);
				
				FriendListTab::ActionDelegate^ delegateFunction = gcnew FriendListTab::ActionDelegate(this->mainDlg->newFriendListTab, &FriendListTab::UpdateFriendListToUI);
				array<Object ^>^ args = {};
				this->mainDlg->Invoke(delegateFunction, args);

				IPAddress ^ srcIP = this->loginUser->ipAddr;
				int srcPort = this->loginUser->recvPort;
				int destPort = f->recvPort;
				int	srcID = this->loginUser->userID;

				OusnsMessage ^ message = this->comm->msgCreator->MakeChangeStatusPeer(this->loginUser->status, 
					OuSns::OFFLINE, this->loginUser->UserID, this->loginUser->SessionID, 
					this->loginUser->IpAddr, this->loginUser->RecvPort, this->loginUser->NatType, f->IpAddr,f->RecvPort);

				this->comm->AddToWorkQueue(message);
			}
		} else if (result == 1) {
			String^ content = friendUserID + "拒绝了您的好友申请";
			array<String^>^ buttonText = {"确定"};
			NotifyUINonBlocking(OuSns::INFORMATION_DLG, content, buttonText, OuSns::REPLYADDFRIENDNOTIFICATION, messageID, friendUserID, this->comm->serverAddr,this->comm->serverPort, this->comm);
		}
	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}


System::Void MessageProcessor::ProcessSysAddFriend(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node response = doc.child("SYSMSG");
		String^ messageID = AnsiToManagedString((char*)(response.attribute("messageID").value()));
		
		String^ friendUserID = AnsiToManagedString((char*)response.child_value("OuID"));

		String^ content = friendUserID + "请求添加您为好友";
		array<String^>^ buttonText = {"接受", "拒绝", "忽略"};

		NotifyUINonBlocking(OuSns::QUESTION_DLG, content, buttonText, OuSns::ADDFRIENDDECISION, messageID, friendUserID, this->comm->serverAddr,this->comm->serverPort, this->comm);

	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}



System::Void MessageProcessor::ProcessReplyAddFriendNotification(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}
	return;
}

System::Void MessageProcessor::ProcessSysRemoveFriend(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node friendinfo = doc.child("SYSMSG");
			
		unsigned int ouID = System::Convert::ToUInt32(AnsiToManagedString((char*)friendinfo.child_value("OuID")));
		/*
		for each (OusnsFriend ^ f in this->loginUser->friendList) {
			if (f->userID == ouID) {
				this->loginUser->friendList->Remove(f);
			}
		}*/
		this->loginUser->RemoveFriend(ouID);

		OuSns::FriendListTab::ActionDelegate^ delegateFunction = gcnew OuSns::FriendListTab::ActionDelegate(this->mainDlg->newFriendListTab, &OuSns::FriendListTab::UpdateFriendListToUI);
		array<Object ^>^ args = {};
		this->mainDlg->Invoke(delegateFunction, args);

	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}




System::Void MessageProcessor::ProcessSysReplyJoinGroup(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node groupinfo = doc.child("SYSMSG");
		String^ messageID = AnsiToManagedString((char*)(groupinfo.attribute("messageID").value()));
		String^ groupID = AnsiToManagedString((char*)groupinfo.child_value("groupID"));
		int decision = System::Convert::ToUInt32(AnsiToManagedString((char*)groupinfo.child_value("replyResult")));

		if (decision == 0) {
			String^ content = groupID + "管理员已通过您的申请";
			array<String^>^ buttonText = {"确定"};
			NotifyUINonBlocking(OuSns::INFORMATION_DLG, content, buttonText, OuSns::REPLYJOINGROUPNOTIFICATION, messageID, groupID, this->comm->serverAddr,this->comm->serverPort, this->comm);

			// add group

		} else if (result == 1) {
			String^ content = groupID + "管理员拒绝了您的申请";
			array<String^>^ buttonText = {"确定"};
			NotifyUINonBlocking(OuSns::INFORMATION_DLG, content, buttonText, OuSns::REPLYJOINGROUPNOTIFICATION, messageID, groupID, this->comm->serverAddr,this->comm->serverPort, this->comm);
		}
	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}


System::Void MessageProcessor::ProcessSysJoinGroup(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node response = doc.child("SYSMSG");
		String^ messageID = AnsiToManagedString((char*)(response.attribute("messageID").value()));
		
		String^ groupID = AnsiToManagedString((char*)response.child_value("groupID"));
		String^ userID = AnsiToManagedString((char*)response.child_value("OuID"));

		String^ content = userID + "请求加入群" + groupID;
		array<String^>^ buttonText = {"接受", "拒绝", "忽略"};

		NotifyUINonBlocking(OuSns::QUESTION_DLG, content, buttonText, OuSns::JOINGROUPDECISION, messageID, groupID + " " + userID, this->comm->serverAddr,this->comm->serverPort, this->comm);

	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}



System::Void MessageProcessor::ProcessReplyJoinGroupNotification(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}
	return;
}

System::Void MessageProcessor::ProcessSysExitGroup(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node groupinfo = doc.child("SYSMSG");
			
		unsigned int groupID = System::Convert::ToUInt32(AnsiToManagedString((char*)groupinfo.child_value("groupID")));

		this->loginUser->RemoveGroup(groupID);

		OuSns::MainDlg::ActionDelegate^ delegateFunction = gcnew OuSns::MainDlg::ActionDelegate(this->mainDlg->newGroupListTab, &OuSns::GroupListTab::UpdateGroupListToUI);
		array<Object ^>^ args = {};
		this->mainDlg->Invoke(delegateFunction, args);

	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}