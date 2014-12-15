#include "stdafx.h"
#include "Communication.h"
//#include "LoginDlg.h"
//#include "MessageProcessor.h"



/*
* This thread will sleep 0.1s for every cycle
*/
System::Void Communication::SendThread() {
	OusnsMessage^ msg;
	int currentPointer;
	int totalCounter;
	//This is the message that to be processed
	LinkedList<OusnsMessage^>^ msgToBeSent = gcnew LinkedList<OusnsMessage^>();
	LinkedList<OusnsMessage^>^ msgToBeTimeOut = gcnew LinkedList<OusnsMessage^>();
	while(isSendThreadRunning){
		Sleep(THREAD_SLEEP_TIME);
		try{
			Threading::Monitor::Enter(sendQueueLock);
			if(sendQueue->Count){
				//There is element in the queue
				currentPointer = 0;
				totalCounter = sendQueue->Count;
				while(currentPointer < totalCounter){
					msg = sendQueue->Last->Value;
					sendQueue->RemoveLast();
					//Reached the start message
					if (msg->timeSlept > (msg->messageTimeOutLimit * msg->messageTimeOutCounterLimit))
						msg->messageStatus = OuSns::TIMEOUT;
					switch (msg->messageStatus){
						case OuSns::CREATED:
							//Add this message into the array that to be processed
							msgToBeSent->AddLast(msg);
							if (msg->messageType != OuSns::RESPONSE) {
								// Resend unless it is a RESPONSE packet.
								msg->messageStatus = OuSns::SENDING;
								msg->timeSlept = 0;
								if (DEBUG_COMM) {
									MessageBox::Show("=SEND=: Start send a message to (" + msg->destIP->ToString() + ":" + msg->destPort.ToString() + "): \n" + msg->messageContent->ToString());
								}	

								sendQueue->AddFirst(msg);
							}		
							break;
						case OuSns::SENDING:
							//The message still waiting for a response
							msg->timeSlept = msg->timeSlept + THREAD_SLEEP_TIME;

							sendQueue->AddFirst(msg);
							break;
						case OuSns::SENT:
							//The message has been sent, check if it is waiting for response
							if(msg->waitResponse){
								sendQueue->AddFirst(msg);
							}
							break;
						case OuSns::TIMEOUT:
							//Process the timeout function
							if (DEBUG_THREAD) {
								MessageBox::Show("=SEND=: The Following Message Was Timeout:" + msg->messageContent->ToString());
							}	
							if (msg->msgCode == OuSns::P2P_NORMAL){
								msg->msgCode = OuSns::P2P_SERVER_FORWARD;
								msg->messageTimeOutLimit = SERVER_TIMEOUT;
								msg->messageTimeOutCounterLimit = SERVER_RESEND_TIME;
								msg->messageStatus = OuSns::CREATED ;
								//msg->destIP = this->serverAddr;
								//msg->destPort = this->serverPort;
								msg->timeSlept = 0;
								sendQueue->AddFirst(msg);
							}
							else{
								//report the message to work queue if it is not a response message
								if (msg->messageType != OuSns::RESPONSE) {
									msg->messageStatus = OuSns::TIMEOUT;
									msg->messageDestThread = OuSns::WORK;
									msgToBeTimeOut ->AddFirst(msg);
								}
							}
							break;
						case OuSns::PARTIAL:

							break;
						case OuSns::RECEIVED:
							//This belongs to the received Message Queue
							break;
						case OuSns::REMOVE:
							//This should not appear here
							break;
						case OuSns::FAILED:
							break;

						default: 
							break;
					}
					currentPointer ++;
				}

			}
			Threading::Monitor::Exit(sendQueueLock);

		}
		catch (ThreadAbortException^ ){
			//Threading::Monitor::Exit(sendQueueLock);
		}
		catch (Exception ^ e) {
			MessageBox::Show("Exception in SendThread: " + e->ToString());
			Threading::Monitor::Exit(sendQueueLock);
		}
		//Start to process those message
		array<OusnsPacket^>^ tempArray;
		for each (OusnsMessage^ i in msgToBeSent){
			tempArray = this->SplitOusnsMessageIntoOusnsPacket(i);
			this->AddToSendPacketQueue(tempArray);
		}
		msgToBeSent->Clear();

		for each (OusnsMessage^ i in msgToBeTimeOut){
			this->AddToWorkQueue(i);
		}
		msgToBeTimeOut->Clear();

	}
	return ;
}



array<OusnsPacket^>^ Communication::SplitOusnsMessageIntoOusnsPacket(OusnsMessage^ msg){

	array<OusnsPacket^>^ returnPacket;

	try{
		Threading::Monitor::Enter(splitPacketLock);

		//The messageID was composed by OuID-MessageNumber
		array<String^>^ splitResult = msg->messageID->Split(gcnew array<wchar_t>{'-'});
		Byte packetFunction = msg->msgCode;
		Byte senderNatType = this->userNatType;
		array<Byte>^ ouID = BitConverter::GetBytes(Int32::Parse(splitResult[0]));
		array<Byte>^ messageNumber = BitConverter::GetBytes(Int32::Parse(splitResult[1]));
		array<Byte>^ messageContent = Encoding::UTF8->GetBytes(msg->messageContent);
		unsigned short packetTotalNumber = unsigned short(min(int(ceil(double(msg->messageContent->Length) / UDP_PACKET_SIZE_LIMIT)),255));
		array<Byte>^ packetTotalNumberArray = BitConverter::GetBytes(packetTotalNumber);
		unsigned short packetCurrentNumber = 0;
		array<Byte>^ packetCurrentNumberArray;
		array<Byte>^ ip = msg->destIP->GetAddressBytes();
		array<Byte>^ recvPort = BitConverter::GetBytes(htons(msg->destPort));
		//array<Byte>^ recvPort2 = BitConverter::GetBytes(msg->destPort);
		array<Byte>^ packetContent = gcnew array<Byte>( UDP_PACKET_SIZE_LIMIT + UDP_PACKET_HEADER_SIZE);

		returnPacket = gcnew array<OusnsPacket^>(min(int(ceil(double(msg->messageContent->Length) / UDP_PACKET_SIZE_LIMIT)),255));
		int leftBytesInMessage = msg->messageContent->Length;
		for (unsigned short i = 0; i < packetTotalNumber; i++){
			if(leftBytesInMessage <= UDP_PACKET_SIZE_LIMIT){
				packetContent = gcnew array<Byte>(leftBytesInMessage + UDP_PACKET_HEADER_SIZE);
				Array::Clear(packetContent,0,leftBytesInMessage + UDP_PACKET_HEADER_SIZE);
			}
			else{
				Array::Clear(packetContent,0, UDP_PACKET_SIZE_LIMIT + UDP_PACKET_HEADER_SIZE);
			}
			packetCurrentNumberArray = BitConverter::GetBytes(i);
			packetContent[0] = packetFunction;
			packetContent[1] = senderNatType;
			Array::Copy(ouID,0,packetContent,2,4);
			Array::Copy(messageNumber,0,packetContent,6,4);

			Array::Copy(packetCurrentNumberArray,0,packetContent,10,2);
			Array::Copy(packetTotalNumberArray,0,packetContent,12,2);
			Array::Copy(ip,0,packetContent,14,4);
			Array::Copy(recvPort,0,packetContent,18,2);


			Array::Copy(messageContent,i*UDP_PACKET_SIZE_LIMIT,packetContent,UDP_PACKET_HEADER_SIZE,min(leftBytesInMessage,UDP_PACKET_SIZE_LIMIT));
			if(packetFunction == OuSns::P2P_SERVER_FORWARD){
				//If this is the packet need the server to forward
				returnPacket[i] = gcnew OusnsPacket(msg->messageID,msg->messageID + (packetCurrentNumber.ToString()),\
					i,packetTotalNumber,
					packetContent,this->serverAddr,this->serverPort,msg->messageTimeOutLimit,msg->messageTimeOutCounterLimit);
			}
			else{
				returnPacket[i] = gcnew OusnsPacket(msg->messageID,msg->messageID+ (packetCurrentNumber.ToString()),\
					i,packetTotalNumber,
					packetContent,msg->destIP,msg->destPort,msg->messageTimeOutLimit,msg->messageTimeOutCounterLimit);
			}

		}
		return returnPacket;
	} catch (Exception ^ ) {

		return returnPacket;

	} finally {
		Threading::Monitor::Exit(splitPacketLock);
	}
}


/*
* This is the function that will add the message into sendQueue
*/
System::Void Communication::AddToSendQueue(OusnsMessage^ msg){
	try {
		Threading::Monitor::Enter(sendQueueLock);
		this->sendQueue->AddFirst(msg);
		Threading::Monitor::Exit(sendQueueLock);
	} 
	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendQueueLock);
	} 
}

/*
* This is the function that will remove such message with the messageID from sendQueue
*/
System::Void Communication::RemoveFromSendQueue(String^ messageID){

	ModifySendQueueMessageStatus(messageID,OuSns::REMOVE);
	if (DEBUG_THREAD) {
		MessageBox::Show("Removed " + messageID + "from the send queue.");
	}
}


/*
* The send packet queue thread and listen packet queue thread
* can modify the message status in the sendQueue  to timeout or to filled
*/
System::Void Communication::ModifySendQueueMessageStatus(String^ messageID, OuSns::MessageStatus messageStatus){
	OusnsMessage^ msg;
	int totalCounter;
	int currentPointer;

	try{
		Threading::Monitor::Enter(sendQueueLock);
		if(sendQueue->Count){
			currentPointer = 0;
			totalCounter = sendQueue->Count;
			//There is element in the queue
			while(currentPointer < totalCounter){
				msg = sendQueue->Last->Value;
				sendQueue->RemoveLast();

				if(msg->messageID->CompareTo(messageID) != 0){
					//not the one, push the message back
					sendQueue->AddFirst(msg);
				}
				else{
					if (messageStatus != OuSns::REMOVE){
						msg->messageStatus = messageStatus;
						sendQueue->AddFirst(msg);
					}
					else{
						if (DEBUG_THREAD) {
							MessageBox::Show(L"Removed the message:"+ msg->messageContent->ToString());
						}
					}
					//if the message needs to be removed, then do not need to insert into the send message queue again
				}
				currentPointer++;
			}
		}
		Threading::Monitor::Exit(sendQueueLock);
	}
	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendQueueLock);
	} 
}