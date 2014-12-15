#include "stdafx.h"
#include "Communication.h"
//#include "LoginDlg.h"
#include "MessageProcessor.h"

System::Void Communication::ListenThread() {
	if (DEBUG_THREAD) {
		MessageBox::Show("=LISTEN=\nStart listen thread.");
	}
	OusnsPacket^ receivedPacket;
	while(isListenThreadRunning) {
		Thread::Sleep(THREAD_SLEEP_TIME);
		//Start to check if the received packet queue exist any packet
		try {
			Threading::Monitor::Enter(receivedPacketQueueLock);
			while(this->receivedPacketQueue->Count){
				receivedPacket = receivedPacketQueue->Last->Value;
				receivedPacketQueue->RemoveLast();
				this->AddToPartialMessageQueue(receivedPacket);
			}	
			Threading::Monitor::Exit(receivedPacketQueueLock);
		}
		catch (ThreadAbortException^ ){
			//Threading::Monitor::Exit(receivedPacketQueueLock);
		}
		catch (Exception ^ e) {
			MessageBox::Show("Exception in lock:receivedPacketQueueLock: " + e->ToString());
			Threading::Monitor::Exit(receivedPacketQueueLock);
		}
		//Start to check if there is any received partial message needs to be clean up
		if(this->partialMessageQueue->Count){
			this->CheckPartialMessage();
		}

	}
}

/*
* This function will be called by the sendPacketThread and add 
*/
System::Void Communication::AddToPartialMessageQueue(OusnsPacket^ receivedPacket){

	OusnsPartialMessage^ partialMsg;
	OusnsPacket^ temp = receivedPacket;
	//String^ messageID = receivedPacket->messageID;
	if (!this->partialMessageQueue->ContainsKey(receivedPacket->messageID)){
		partialMsg = gcnew OusnsPartialMessage(receivedPacket->totalPacket,PARTIAL_MESSAGE_TIMEOUT,receivedPacket->targetIP,receivedPacket->targetPort);
		this->partialMessageQueue->Add(receivedPacket->messageID,partialMsg);
	}
	else{ 
		partialMsg = this->partialMessageQueue[receivedPacket->messageID];
	}
	partialMsg->AddPacket(receivedPacket);
}


OusnsMessage^ Communication::MergePacketToMessage(OusnsPartialMessage^ partialMsg){
	OusnsMessage^ msg;
	array<Byte>^ messageContent = gcnew array<Byte>(partialMsg->totalLength);
	int messageContentPointer = 0;
	unsigned short i;
	for( i= 0; i < partialMsg->packetContentArray->Length;i++){
		Array::Copy(partialMsg->packetContentArray[i],0,messageContent,messageContentPointer,partialMsg->packetContentArray[i]->Length);
		messageContentPointer = messageContentPointer + partialMsg->packetContentArray[i]->Length;

	}
	msg = gcnew OusnsMessage(Encoding::UTF8->GetString(messageContent),partialMsg->destIP,partialMsg->destPort);

	return msg;
}

/*
* This function will check and remove the partial message if the partial message was
* not receive any more packet
*/
System::Void Communication::CheckPartialMessage(){
	Dictionary<String^, OusnsPartialMessage^>::KeyCollection^ keyColl;
	OusnsPartialMessage^ partialMsg;
	OusnsMessage^ msg;
	LinkedList<String^>^ msgToBeRemoved = gcnew LinkedList<String^>();
	String^ messageID;
	DWORD currentTime;

	keyColl = this->partialMessageQueue->Keys;
	for each(messageID in keyColl){
		partialMsg = partialMessageQueue[messageID];
		currentTime = GetTickCount();

		if (partialMsg->counter == partialMsg->totalPacketNumber){
			msg = MergePacketToMessage(partialMsg);
			//Remove this from the partial message queue
			msgToBeRemoved->AddLast(messageID);
			if(msg->messageContent->Length){
				if (DEBUG_COMM) {
					MessageBox::Show("=LISTEN=: Received the Following Message from ***, add to Work Queue:\n" + msg->messageContent->ToString());
				}	
				OusnsMessage ^ parsedMsg = this->ProcessListenMessage(msg);
				if(parsedMsg->messageType == OuSns::RESPONSE)
					this->RemoveFromSendQueue(parsedMsg->messageID);
				this->AddToWorkQueue(parsedMsg);
			}
			else{
				//this is an ack packets constructed message
				if (DEBUG_PACKET) {
					MessageBox::Show("=LISTEN=: Removing the following message id from send message queue:\n" + messageID);
				}	
				this->ModifySendQueueMessageStatus(messageID,OuSns::SENT);
			}
		}
		else if ((GetTickCount() - partialMsg->accessTime) >partialMsg->timeOutLimit){
			//Remove this message if the message is time out
			msgToBeRemoved->AddLast(messageID);
		}
	}
	while(msgToBeRemoved->Count){
		messageID = msgToBeRemoved->Last->Value;
		partialMessageQueue->Remove(messageID);
		msgToBeRemoved->RemoveLast();
	}
}



OusnsMessage^ Communication::ProcessListenMessage(OusnsMessage ^ msg) {

	OusnsMessage ^ newMsg;
	if (DEBUG_THREAD) {
		MessageBox::Show("=Listen=\nMessageProcessor::ProcessReceivePacket: Parse the received packet into a message," +
			" and put it into the Work thread."); 
	}
	char * buffer = ManagedStringToAnsi(msg->messageContent);
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_buffer(buffer, msg->messageContent->Length);

	OuSns::MessageType messageType;
	int returnCode = 0;
	OuSns::ActionType actionType;

	String ^ messageTypeString = AnsiToManagedString((char*)(doc.first_child().name()));

	if (messageTypeString == "REQUEST") {
		messageType = OuSns::REQUEST;
	} else if (messageTypeString == "RESPONSE") {
		messageType = OuSns::RESPONSE;
		returnCode = System::Convert::ToInt32(AnsiToManagedString((char*)(doc.first_child().attribute("returnCode").value())));
	} else if (messageTypeString == "SYSMSG"){
		messageType = OuSns::SYSMSG;
	}
	else {
		MessageBox::Show("ProcessListenMessage:\nUnhandled message type." + messageTypeString);
	}
	String^ actionTypeString = AnsiToManagedString((char*)(doc.first_child().attribute("actionType").value()));
	try{
		actionType =(OuSns::ActionType) this->msgProcessor->stringToActionTypeDict[actionTypeString];
		String^ messageID = AnsiToManagedString((char*)(doc.first_child().attribute("messageID").value()));
		newMsg = gcnew OusnsMessage(OuSns::WORK,OuSns::WORK, messageType, returnCode, messageID, actionType, msg->messageContent, msg->destIP, msg->destPort,false);
		newMsg->MessageStatus = OuSns::RECEIVED;
		if (DEBUG_THREAD) {
			MessageBox::Show("ProcessListenMessage:\nReceived packet is " + actionTypeString + " " + messageTypeString + ". Process the " +
				"new message again.");
		}
	}
	catch (Exception^ ){
		MessageBox::Show("ProcessListenMessage:\nUnhandled action type.");
	}
	return newMsg;
}

