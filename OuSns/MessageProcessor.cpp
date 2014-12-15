
#include "stdafx.h"
#include "MessageProcessor.h"
#include "Communication.h"
//#include "friendChatDlg.h"
#include "LoginDlg.h"
#include "MainDlg1.h"

#pragma managed

MessageProcessor::MessageProcessor(Communication^ comm){
		//this->msgCreator = gcnew MessageCreator();
		this->comm = comm;
		this->loginDlg = comm->loginDlg;
		this->mainDlg = comm->mainDlg;
		this->loginUser = comm->loginUser;
		this->InitializeActionTypeDict();
}

/*
 * This function will initialize the dictionary of the action type, transform the action
 * type from string to integer.
 * The enum was added in the file OuSns.h
 */
System::Void MessageProcessor::InitializeActionTypeDict(void){
	this->stringToActionTypeDict = gcnew Dictionary<String^,int>();
	this->actionTypeToStringDict = gcnew Dictionary<int,String^>();
	this->stringToActionTypeDict->Add("CHATMESSAGE",OuSns::CHATMESSAGE);
	
	this->stringToActionTypeDict->Add("CHANGESTATUSPEER",OuSns::CHANGESTATUSPEER);
	this->stringToActionTypeDict->Add("LOGIN", OuSns::LOGIN);
	this->stringToActionTypeDict->Add("DOWNLOADLIST", OuSns::DOWNLOADLIST);
	this->stringToActionTypeDict->Add("SEARCHFRIEND", OuSns::SEARCHFRIEND);
	this->stringToActionTypeDict->Add("ADDFRIEND",OuSns::ADDFRIEND);
	this->stringToActionTypeDict->Add("SYSADDFRIEND",OuSns::SYSADDFRIEND);
	this->stringToActionTypeDict->Add("REPLYADDFRIEND", OuSns::REPLYADDFRIEND);
	this->stringToActionTypeDict->Add("SYSREPLYADDFRIEND", OuSns::SYSREPLYADDFRIEND);
	this->stringToActionTypeDict->Add("REMOVEFRIEND",OuSns::REMOVEFRIEND);
	this->stringToActionTypeDict->Add("SYSREMOVEFRIEND",OuSns::SYSREMOVEFRIEND);
	this->stringToActionTypeDict->Add("REQFILETRAN", OuSns::REQFILETRAN);
	this->stringToActionTypeDict->Add("REPFILETRAN", OuSns::REPFILETRAN);
	this->stringToActionTypeDict->Add("CANCELFILETRAN", OuSns::CANCELFILETRAN);
	this->stringToActionTypeDict->Add("HEARTBEAT",  OuSns::HEARTBEATMSG);
	this->stringToActionTypeDict->Add("HOLEPUNCHING", OuSns::HOLEPUNCHING);
	this->stringToActionTypeDict->Add("UPDATEJOB",OuSns::UPDATEJOB);
	this->stringToActionTypeDict->Add("ADDDOWNLOADERCOMMAND",OuSns::ADDDOWNLOADERCOMMAND);
	Dictionary<String^,int>::KeyCollection^ keyColl;
	String^ actionTypeString;
	keyColl = this->stringToActionTypeDict->Keys;
	for each( actionTypeString in keyColl){
		this->actionTypeToStringDict->Add(this->stringToActionTypeDict[actionTypeString],actionTypeString);
	}

}

System::Void MessageProcessor::ProcessMessage(OusnsMessage^ msg){
	switch(msg->messageDestThread){
		case OuSns::LISTEN:
			break;
		case OuSns::UI:
			break;
		case OuSns::SEND:
			this->ProcessSendPacket(msg);
			break;
		case OuSns::WORK:
			switch(msg->actionType){
		case OuSns::CHATMESSAGE:
			this->ProcessChatMessage(msg);
			break;

		case OuSns::CHANGESTATUSPEER:
			this->ProcessChangeStatusPeer(msg);
			break;

		case OuSns::LOGIN:
			this->ProcessLoginResponsePacket(msg);
			break;

		case OuSns::SEARCHFRIEND:
			this->ProcessSearchFriend(msg);
			break;

		case OuSns::DOWNLOADLIST:
			this->ProcessDownloadList(msg);
			break;

		case OuSns::SYSADDFRIEND:
			this->ProcessSysAddFriend(msg);
			break;

		case OuSns::ADDFRIENDDECISION:
			this->ProcessAddFriendDecision(msg);
			break;

		case OuSns::SYSREPLYADDFRIEND:
			this->ProcessSysReplyAddFriend(msg);
			break;

		case OuSns::REPLYADDFRIEND:
			this->ProcessReplyAddFriend(msg);
			break;

		case OuSns::REPLYADDFRIENDNOTIFICATION:
			this->ProcessReplyAddFriendNotification(msg);
			break;

		case OuSns::SYSREMOVEFRIEND:
			this->ProcessSysRemoveFriend(msg);
			break;

		case OuSns::HEARTBEATMSG:
			this->ProcessHeartBeat(msg);
			break;

		case OuSns::REQFILETRAN:
			this->ProcessRequestFileTransfer(msg);
			break;

		case OuSns::REPFILETRAN:
			this->ProcessReplyFileTransfer(msg);
			break;

		case OuSns::CANCELFILETRAN:
			this->ProcessCancelFileTransfer(msg);
			break;

		case OuSns::HOLEPUNCHING:
			this->ProcessHolePunching(msg);
			break;

		case OuSns::UPDATEJOB:
			this->ProcessUpdateJob(msg);
			break;
		case OuSns::ADDDOWNLOADERCOMMAND:
			//this->ProcessDownloaderCommand(msg);
			this->comm->AddToDownloaderCommandQueue(msg);
			break;
		default:
			MessageBox::Show("=WORK=\nUnknown action type!");
			}
			break;
		default:
			break;
	}
}


System::Void MessageProcessor::ProcessSendPacket(OusnsMessage ^ msg) {
	//System::Diagnostics::Debug::Assert(msg->messageType == NONE);
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessSendPacket: Put the packet in the send thread.");
	}

	this->comm->AddToSendQueue(msg);
}


