#include "stdafx.h"
//#include "Communication.h"
#include "friendChatDlg.h"
//#include "LoginDlg.h"
#include "MainDlg1.h"
#include "MessageProcessor.h"
#include "FriendListTab.h"
#include "OusnsFriend.h"
#include "OusnsLoginUser.h"


System::Void MessageProcessor::ProcessChatMessage(OusnsMessage ^ msg) {
	if (msg->messageStatus == OuSns::TIMEOUT) {
		return;
	}
	else{
		if (msg->messageType == OuSns::REQUEST) {
			
			if (DEBUG_THREAD) {
				MessageBox::Show("=WORK=\nMessageProcessor::ProcessChatMessage: Display the received message in the UI.");
			}
			String ^ packet = msg->messageContent;
			char * buffer = ManagedStringToAnsi(packet);
			String ^ text;
			DateTime ^ time;
			int srcID;
			String ^ msgID;
			try {
				pugi::xml_document doc;
				pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
				
				srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));
				text = AnsiToManagedString((char*)(doc.first_child().child_value("text")));
				time = DateTime::Parse(AnsiToManagedString((char*)(doc.first_child().child_value("time"))));
				msgID = AnsiToManagedString((char *) doc.first_child().attribute("messageID").value());
			
			} catch (Exception ^ e) {
				MessageBox::Show("ProcessChatMessage: exception during parsing: " + e->ToString());
				return;
			}

			ChatMessage ^ newMsg = gcnew ChatMessage(text, srcID, time);
			OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);
			this->mainDlg->PushChatMessageToUI(newMsg);

			//this->comm->SendSimpleResponse(OuSns::CHATMESSAGE,"CHATMESSAGE", msgID, srcFriend->ipAddr, srcFriend->recvPort);
		}
		else {
			MessageBox::Show("ProcessChatMessage: unknown message type: " + ((int)msg->messageType).ToString());
		}
	}
}

System::Void MessageProcessor::ProcessChangeStatusPeer(OusnsMessage ^ msg) {
	
	if (msg->messageStatus == OuSns::TIMEOUT) {
		return;
	}
	else if( msg->messageStatus == OuSns::RECEIVED){
		if (msg->messageType == OuSns::REQUEST) {
		
			if (DEBUG_THREAD) {
				MessageBox::Show("=WORK=\nMessageProcessor::ProcessChangeStatusPeer: " + 
					"Reflect the change in status on the target friend (chat window & main dialogue).");
			}

			String ^ packet = msg->messageContent;
			char * buffer = ManagedStringToAnsi(packet);
			OuSns::UserStatus status;
			int srcID;
			String ^ msgID;
			try {
			pugi::xml_document doc;
			pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
			
			srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));

			status = (OuSns::UserStatus)Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("userStatus"))));

			msgID = AnsiToManagedString((char *) doc.first_child().attribute("messageID").value());
			
			pugi::xml_node ipNode = doc.first_child().child("ip");
			if (ipNode != NULL) {
				int srcPort = Convert::ToInt32(AnsiToManagedString((char *) doc.first_child().child_value("port")));
				OuSns::NatType natType = (OuSns::NatType) Convert::ToInt32(AnsiToManagedString((char *) doc.first_child().child_value("natType")));
				IPAddress ^ srcIP = IPAddress::Parse(AnsiToManagedString((char *)ipNode.child_value()));
				OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);
				if (srcFriend != nullptr) {
					srcFriend->IpAddr = srcIP;
					srcFriend->RecvPort = srcPort;
					srcFriend->NatType = natType;
				} else {
					MessageBox::Show("ChangeStatusPeer: Friend does not exist.");
				}
			}
			OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);
			if (srcFriend != nullptr) {
				srcFriend->status = status;
			}
			
			//mainDlg->PushStatusChangeToUI(srcID, status);
			OuSns::FriendListTab::ActionDelegate^ delegateFunction = gcnew OuSns::FriendListTab::ActionDelegate(mainDlg->newFriendListTab, &OuSns::FriendListTab::UpdateFriendListToUI);
			array<Object ^>^ args = {};
			this->mainDlg->Invoke(delegateFunction, args);

			//this->comm->SendSimpleResponse(OuSns::CHANGESTATUSPEER,"CHANGESTATUSPEER", msgID, srcFriend->ipAddr, srcFriend->recvPort);

			} catch (Exception ^ e) {
				MessageBox::Show("ProcessChangeStatusPeer: exception during parsing: " + e->ToString());
				return;
			}
			
		}
		 else{
			MessageBox::Show("ProcessChangeStatusPeer: unknown message type: " + ((int)msg->messageType).ToString());
		}
	}
}
/*
System::Void MessageProcessor::ProcessSimpleResponse(OusnsMessage ^ msg) {

	if (DEBUG_THREAD) {
		MessageBox::Show("=Work=\nReceived a RESPONSE message:\nType: " + 
			this->actionTypeToStringDict[msg->actionType] + "\nMessage ID: " + msg->messageID + 
			" Remove the corresponding message from the send queue.");
	}
	this->comm->RemoveFromSendQueue(msg->messageID);
}
*/

System::Void MessageProcessor::ProcessRequestFileTransfer(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=Work=\nReceived a REQFILETRAN message. Prompt the user for action.");
	}
	
	String ^ packet = msg->messageContent;
	char * buffer = ManagedStringToAnsi(packet);

	int srcID;
	String ^ fileName;
	int fileSize;
	String ^ md5;
	
	String ^ sessionID;

	try {
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
		
		srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));
		fileName = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileName").value()));
		fileSize = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileSize").value())));
		md5 = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileMD5CheckSum").value()));
		sessionID = AnsiToManagedString((char *)(doc.first_child().attribute("sessionID").value()));
	} catch (Exception ^ e) {
		MessageBox::Show("ProcessRequestFileTransfer: exception during parsing: " + e->ToString());
		return;
	}
	
	OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);

	if (srcFriend == nullptr) {
		MessageBox::Show("ProcessRequestFileTransfer: Unknown friend ID: " + srcID.ToString());
		return;
	}

	if (this->mainDlg->newFriendListTab->friend_chat_dlg_list->ContainsKey(srcID)) { // If the chat window is open
		
		// Add a new file transfer job to the chat window.
		OuSns::friendChatDlg::AddFileTransferJobDelegate^ delegateFunction = 
			gcnew OuSns::friendChatDlg::AddFileTransferJobDelegate(this->mainDlg->newFriendListTab->friend_chat_dlg_list[srcID], 
			&OuSns::friendChatDlg::AddFileTransferJobPanel);
		array<Object ^>^ args = {fileName, nullptr, fileSize, md5, false};
		this->mainDlg->Invoke(delegateFunction, args);
		
		// Blink the window.
		OuSns::MainDlg::ActionDelegate ^ windowBlinkDelegate = 
			gcnew OuSns::MainDlg::ActionDelegate(this->mainDlg->newFriendListTab->friend_chat_dlg_list[srcID], &friendChatDlg::Blink);
		this->mainDlg->Invoke(windowBlinkDelegate); 
	} else {
		
		// Add the file transfer job in the mainDlg storage so that it can be displayed in the chat window
		// the next time the chat window is open.
		DirectTransferFile ^ newFile = gcnew DirectTransferFile(fileName, fileSize, md5);
		if (!(this->mainDlg->newFriendListTab->transferFilesByUser->ContainsKey(srcFriend))) {
			this->mainDlg->newFriendListTab->transferFilesByUser[srcFriend] = gcnew LinkedList<DirectTransferFile ^>();
		}
		this->mainDlg->newFriendListTab->transferFilesByUser[srcFriend]->AddLast(newFile);

		// Update the unread message count.
		if ( !(this->mainDlg->newFriendListTab->pending_counts_by_user->ContainsKey(srcFriend)) ) {
			this->mainDlg->newFriendListTab->pending_counts_by_user[srcFriend] = 1;
		} else {
			this->mainDlg->newFriendListTab->pending_counts_by_user[srcFriend] += 1;
		}
		this->mainDlg->pending_msg_total += 1;
		
		// Display the new unread message count.
		OuSns::MainDlg::UpdateInfoDelegate ^ updateUnreadCountDelegate = gcnew OuSns::MainDlg::UpdateInfoDelegate(this->mainDlg, &MainDlg::DisplayUnreadCount);
		array<Object ^>^ args = {(unsigned int)srcID};
		this->mainDlg->Invoke(updateUnreadCountDelegate, args);
	}
	
}
System::Void MessageProcessor::ProcessCancelFileTransfer(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=Work=\nReceived a CANCELFILETRAN message. Prompt the user for action.");
	}
		
	String ^ packet = msg->messageContent;
	char * buffer = ManagedStringToAnsi(packet);

	int srcID;
	String ^ fileName;
	int fileSize;
	String ^ md5;
	
	String ^ sessionID;

	try {
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
		
		srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));
		fileName = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileName").value()));
		fileSize = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileSize").value())));
		md5 = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileMD5CheckSum").value()));
		sessionID = AnsiToManagedString((char *)(doc.first_child().attribute("sessionID").value()));
	} catch (Exception ^ e) {
		MessageBox::Show("ProcessCancelFileTransfer: exception during parsing: " + e->ToString());
		return;
	}
	
	OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);

	if (srcFriend == nullptr) {
		MessageBox::Show("ProcessCancelFileTransfer: Unknown friend ID: " + srcID.ToString());
		return;
	}
	

	if (this->mainDlg->newFriendListTab->friend_chat_dlg_list->ContainsKey(srcID)) { // If the chat window is open

		// Remove the requested panel from the window;
		
		this->mainDlg->newFriendListTab->RemoveTargetFileTransferJob(srcID, fileName, md5, REMOTE_CANCEL);
		
	} else { // if the chat window is closed.

		// Find the requested file record in mainDlg. If found, set its status to "CANCELLED".
		for each (DirectTransferFile ^ f in this->mainDlg->newFriendListTab->transferFilesByUser[srcFriend]) {
			if (f->fileName == fileName && f->md5 == md5) {
				System::Diagnostics::Debug::Assert(!f->isSender);
				f->isCancelled = true;
				break;
			}
		}
	}
}

System::Void MessageProcessor::ProcessReplyFileTransfer(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=Work=\nReceived a REPFILETRAN message. Right not the only possible decision is" +
				" REJECT, and therefore this request is treated as a REJECTFILETRANSFER request.");
	}
		
	String ^ packet = msg->messageContent;
	char * buffer = ManagedStringToAnsi(packet);

	int srcID;
	int decision;
	String ^ fileName;
	int fileSize;
	String ^ md5;
	
	String ^ sessionID;

	try {
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
		
		srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));
		decision = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("decision"))));
		fileName = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileName").value()));
		fileSize = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileSize").value())));
		md5 = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileMD5CheckSum").value()));
		sessionID = AnsiToManagedString((char *)(doc.first_child().attribute("sessionID").value()));
	} catch (Exception ^ e) {
		MessageBox::Show("ProcessReplyFileTransfer: exception during parsing: " + e->ToString());
		return;
	}
	
	OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);

	if (srcFriend == nullptr) {
		MessageBox::Show("ProcessReplyFileTransfer: Unknown friend ID: " + srcID.ToString());
		return;
	}
	// If we receive a reply file transfer message while the chat window is closed, it means that
	// The file transfer is cancelled; therefore we should ignore such request.
	if (!this->mainDlg->newFriendListTab->friend_chat_dlg_list->ContainsKey(srcID)) {
		return;
	}
		
	if (decision == DECISION_ACCEPT) {// NOT USED
		/*
		OuSns::friendChatDlg::StartDirectFileTransferDelegate^ delegateFunction = 
			gcnew OuSns::friendChatDlg::StartDirectFileTransferDelegate(this->mainDlg->friend_chat_dlg_list[srcID], 
			&OuSns::friendChatDlg::StartDirectFileTransfer);
		array<Object ^>^ args = {fileName, md5};
		this->mainDlg->Invoke(delegateFunction, args);
		*/
	} else {
		this->mainDlg->newFriendListTab->RemoveTargetFileTransferJob(srcID, fileName, md5, REMOTE_REJECT);
	}
		
}

System::Void MessageProcessor::ProcessHolePunching(OusnsMessage ^ msg) {

	if (DEBUG_THREAD) {
		MessageBox::Show("=Work=\nReceived a HOLEPUNCHING message. Obtain the public IP of the new port.");
	}
	
	String ^ packet = msg->messageContent;
	char * buffer = ManagedStringToAnsi(packet);

	int srcID;
	int decision;
	String ^ fileName;
	String ^ localPath;
	int fileSize;
	String ^ md5;
	
	String ^ sessionID;

	try {
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer, packet->Length);
		
		srcID = Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().child_value("OuID"))));
		fileName = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileName").value()));
		md5 = AnsiToManagedString((char*)(doc.first_child().child("file").attribute("fileMD5CheckSum").value()));
		sessionID = AnsiToManagedString((char *)(doc.first_child().attribute("sessionID").value()));
	} catch (Exception ^ e) {
		MessageBox::Show("ProcessReplyFileTransfer: exception during parsing: " + e->ToString());
		return;
	}
	
	// This header has been replaced with the public IP of the source when received at the packet level.
	IPAddress ^ peerIP = msg->destIP;
	int peerPort = msg->destPort;

	OusnsFriend ^ srcFriend = this->loginUser->FindFriend(srcID);

	if (srcFriend == nullptr) {
		MessageBox::Show("ProcessReplyFileTransfer: Unknown friend ID: " + srcID.ToString());
		return;
	}
	friendChatDlg ^ curDlg = this->mainDlg->newFriendListTab->friend_chat_dlg_list[srcID];



	if (msg->messageType == OuSns::REQUEST) {

		
		for each (DirectTransferFile ^ f in curDlg->fileTransferJobPanelList->Values) {
			if (f->fileName == fileName && f->md5 == md5) {
				localPath = f->filePath;
				break;
			}
		}
		System::Diagnostics::Debug::Assert(localPath != nullptr);

		// Create a new record for the port that will be used for this file transfer.
		// Fill in the PEER port info right now.
		// The LOCAL port info will be filled out by the exchangeInfo thread later.
		FileTransferPort ^ newPort = gcnew FileTransferPort(fileName, md5, localPath);

		newPort->peerAddress = peerIP;
		newPort->peerPort = peerPort;
		curDlg->fileTransferPortList->AddLast(newPort);
		Diagnostics::Debug::WriteLine("ON RECEIVING HOLEPUNCHING REQUEST:\nAdding the following port to fileTransferPortList: " +
			"\nfileName: " + newPort->fileName +
			"\nmd5: " + newPort->md5 +
			"\nisSender: " + newPort->isSender.ToString() +
			"\nlocalPath: " + newPort->localPath +
			"\nlocalPort: " + newPort->localPort.ToString() +
			"\npeerAddress: " + newPort->peerAddress->ToString() +
			"\npeerPort: " + newPort->peerPort.ToString());


		
		/*
		array<String ^> ^ params = {fileName, md5};
		ParameterizedThreadStart ^ exchangePortInfoThreadStart = gcnew ParameterizedThreadStart(curDlg, &friendChatDlg::exchangePortInfo);
		Thread ^ exchangePortInfoThread = gcnew Thread(exchangePortInfoThreadStart);
		exchangePortInfoThread->Name = L"exchangePortInfoThread";
		exchangePortInfoThread->Priority = ThreadPriority::Normal;
		exchangePortInfoThread->Start(params);
		*/

		curDlg->exchangePortInfo(fileName, md5);

		curDlg->StartSendFileThread(fileName, md5);

	} else {
		
		// This is the receiver side, and we already have the local port info filled in earlier when
		// we send the hole-punching request. After this step, we will have port info about both sides.
		for each (FileTransferPort ^ p in curDlg->fileTransferPortList) {
			if (p->fileName == fileName && p->md5) {
				p->peerAddress = peerIP;
				p->peerPort = peerPort;
				Diagnostics::Debug::WriteLine("ON RECEIVING HOLEPUNCHING RESPONSE:\nModifying the following port in fileTransferPortList: " +
					"\nfileName: " + p->fileName +
					"\nmd5: " + p->md5 +
					"\nisSender: " + p->isSender.ToString() +
					"\nlocalPath: " + p->localPath +
					"\nlocalPort: " + p->localPort.ToString() +
					"\npeerAddress: " + p->peerAddress->ToString() +
					"\npeerPort: " + p->peerPort.ToString());
				break;
			}
		}

		curDlg->StartReceiveFileThread(fileName, md5);
	}


}