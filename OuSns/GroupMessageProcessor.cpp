
#include "stdafx.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "Communication.h"
//#include "friendChatDlg.h"
//#include "LoginDlg.h"
//#include "MainDlg1.h"
#include "OusnsLoginUser.h"




System::Void MessageProcessor::ProcessJoinGroupDecision(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		int idx = msg->messageContent->IndexOf(" ");
		unsigned int groupID = System::Convert::ToUInt32(msg->messageContent->Substring(0, idx));
		unsigned int userID = System::Convert::ToUInt32(msg->messageContent->Substring(idx + 1));
		unsigned int sysMsgID = System::Convert::ToUInt32(msg->messageID);
		if (msg->returnCode == (int)System::Windows::Forms::DialogResult::Yes) {
			OusnsMessage^ message = this->comm->msgCreator->MakeReplyJoinGroupMessage(this->loginUser->userID,this->loginUser->sessionID, groupID, userID, 0, sysMsgID);
			this->comm->AddToWorkQueue(message);
		} else if (msg->returnCode == (int)System::Windows::Forms::DialogResult::No) {
			OusnsMessage^ message = this->comm->msgCreator->MakeReplyJoinGroupMessage(this->loginUser->userID,this->loginUser->sessionID, groupID, userID, 1, sysMsgID);
			this->comm->AddToWorkQueue(message);
		}
	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}


System::Void MessageProcessor::ProcessReplyJoinGroup(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		
		//MessageBox::Show(receivedString);
		pugi::xml_node groupinfo = doc.child("RESPONSE");
			
		unsigned int groupID = System::Convert::ToUInt32(AnsiToManagedString((char*)groupinfo.child_value("groupID")));
		String^ groupName = AnsiToManagedString((char*)groupinfo.child_value("groupName"));
		String^ groupDescription = AnsiToManagedString((char*)groupinfo.child_value("groupDescription"));
		String^ groupCategory = AnsiToManagedString((char*)groupinfo.child_value("groupCategory"));
		String^ groupAnnouncement = AnsiToManagedString((char*)groupinfo.child_value("groupAnnouncement"));
		unsigned int groupOwnerID = System::Convert::ToUInt32(AnsiToManagedString((char*)groupinfo.child_value("groupOwnerID")));
		String^ groupTag = AnsiToManagedString((char*)groupinfo.child_value("groupTag"));

		// add group

	}
	catch(Exception ^ ){
		//Process the expcetion part
	}
	return;
}
