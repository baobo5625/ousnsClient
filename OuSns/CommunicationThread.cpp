#include "stdafx.h"
#include "Communication.h"
//#include "LoginDlg.h"
//#include "MessageProcessor.h"



/* This is the communication thread with both listen and send function */
System::Void Communication::CommunicationThread(void){


	//Listen part initialization
	array<Byte> ^ rawPacketContent;
	int available_data;
	unsigned int ouID, messageNumber;
	array<Byte>^ packetContent;
	unsigned short packetTotalNumber, packetCurrentNumber, senderPort;
	IPAddress^ senderIp;
	//array<Byte>^ receiverIp = this->loginUser->ipAddr->GetAddressBytes();
	//array<Byte>^ receiverPort = BitConverter::GetBytes(this->loginUser->recvPort);
	String^ messageID;
	String^ packetID;
	OusnsPacket^ receivedPacket;
	IPEndPoint ^ remoteEp = gcnew IPEndPoint(IPAddress::Any, 0);
	int threadSlept = 0;
	array<Byte>^ senderIPArray = gcnew array<Byte>(4);

	array<Byte>^ ackPacketContent =  gcnew array<Byte>(UDP_PACKET_HEADER_SIZE);
	OusnsPacket^ ackPacket;
	//array<Byte>^ senderPortArray = BitConverter::GetBytes(this->loginUser->recvPort);

	//Send part initialization
	OusnsPacket^ packet;
	IPEndPoint ^ dest;
	int currentPointer;
	String^ msgID;
	Dictionary<String^,String^>^ packetToBeRemoved = gcnew Dictionary<String^,String^>();
	Dictionary<String^, String^>::KeyCollection^ keyColl;
	int totalCounter;

	while(isCommunicationThreadRunning) {

		threadSlept = threadSlept + THREAD_SLEEP_TIME;
		Thread::Sleep(THREAD_SLEEP_TIME);
		//Listen packet function
		available_data = this->listenClient->Available;

		while (available_data > 0) {
			try{
				rawPacketContent = this->listenClient->Receive(remoteEp);
				//If the user is logged in (enableListen = true)
				if(rawPacketContent->Length >= UDP_PACKET_HEADER_SIZE && this->enableListen){
					//This is a data packet
					ouID = BitConverter::ToUInt32(rawPacketContent,2);
					messageNumber = BitConverter::ToUInt32(rawPacketContent,6);
					packetCurrentNumber = BitConverter::ToUInt16(rawPacketContent,10);

					messageID = ouID.ToString() + "-" + messageNumber.ToString();
					packetID = messageID + packetCurrentNumber.ToString();
					packetTotalNumber = BitConverter::ToUInt16(rawPacketContent,12);
					Array::Copy(rawPacketContent,14,senderIPArray,0,4);
					senderIp = gcnew IPAddress(senderIPArray);
					//senderIp = remoteEp->Address;
					String^ ip = remoteEp->Address->ToString();
					senderPort = ntohs(BitConverter::ToUInt16(rawPacketContent,18));

					//Construct the received packet
					packetContent = gcnew array<Byte>(rawPacketContent->Length - UDP_PACKET_HEADER_SIZE);
					Array::Copy(rawPacketContent,UDP_PACKET_HEADER_SIZE,packetContent,0,rawPacketContent->Length - UDP_PACKET_HEADER_SIZE);

					if (rawPacketContent[0] == P2P_SERVER_FORWARD) {
						receivedPacket = gcnew OusnsPacket(messageID,packetID,
							packetCurrentNumber,packetTotalNumber,packetContent,senderIp,senderPort,PARTIAL_MESSAGE_TIMEOUT,1);
					} else {
						receivedPacket = gcnew OusnsPacket(messageID,packetID,
							packetCurrentNumber,packetTotalNumber,packetContent,remoteEp->Address,remoteEp->Port,PARTIAL_MESSAGE_TIMEOUT,1);
					}
					if(packetContent->Length > 0){


						//Send an ack packet
						Array::Copy(rawPacketContent,0,ackPacketContent,0,UDP_PACKET_HEADER_SIZE);
						//put the user's IP in the ack packet in case the packet need to be forwarding
						//Array::Copy(this->userPublicIPArray,0,ackPacketContent,14,4);
						//Array::Copy(this->userPublicPortArray,0,ackPacketContent,18,2);
						

						if(ackPacketContent[0] != OuSns::NORMAL){
							//sending a p2p ack packet Start to check the sender's NatType
							if(ackPacketContent[1] == OuSns::StunTypeOpen ||
								ackPacketContent[1] == OuSns::StunTypeIndependentFilter ||
								ackPacketContent[1] == OuSns::StunTypeDependentFilter ||
								ackPacketContent[1] == OuSns::StunTypePortDependedFilter){
									//Send direct p2p ack packet
									ackPacketContent[0] = OuSns::P2P_NORMAL_ACK;

									ackPacket = gcnew OusnsPacket(messageID,receivedPacket->packetID,0,1,ackPacketContent,
										remoteEp->Address,remoteEp->Port,ACK_PACKET_TIMEOUT,ACK_PACKET_RESEND_TIME);

							}
							else{
								//Sending a server forwarding p2p ack packet
								ackPacketContent[0] = P2P_SERVER_FORWARD_ACK;
								ackPacket = gcnew OusnsPacket(messageID,receivedPacket->packetID,0,1,ackPacketContent,
									this->serverAddr,this->serverPort,
									ACK_PACKET_TIMEOUT,ACK_PACKET_RESEND_TIME);
							}
						}
						else{
							//sending a server response ack packet
							ackPacket = gcnew OusnsPacket(messageID,receivedPacket->packetID,0,1,ackPacketContent,
								remoteEp->Address,remoteEp->Port,
								ACK_PACKET_TIMEOUT,ACK_PACKET_RESEND_TIME);
							Array::Copy(this->serverAddrArray,0,ackPacketContent,14,4);
							Array::Copy(this->serverPortArray,0,ackPacketContent,18,2);
						}
						
						if(DEBUG_PACKET){
							MessageBox::Show("Sending the following ack packet with packetID:" + ackPacket->packetID->ToString()\
								+"\n From IP:" + ackPacket->targetIP->ToString() + "\n From port:" + ackPacket->targetPort.ToString());
							
						}
						


						this->AddToSendPacketQueue(ackPacket);

					}
					else{
						//This is an acknowledge packet, remove the corresponding packet from queue
						if(DEBUG_PACKET){
							MessageBox::Show("Received the following ack packet with packetID:" + packetID->ToString()\
								+"\n From IP:" + remoteEp->Address->ToString() + "\n From port:" + remoteEp->Port.ToString());
						}
						this->RemoveFromSendPacketQueue(packetID);
						//Modify the partial message queue, indicates that the receiver received such packet
					}
					this->AddToReceivedPacketQueue(receivedPacket);
					Array::Clear(rawPacketContent,0,rawPacketContent->Length);
					Array::Clear(ackPacketContent,0,ackPacketContent->Length);
				}

				
			}
			catch(Exception^ ){
				//MessageBox::Show(e->ToString());
			}
			available_data = this->listenClient->Available;
		}
		if(threadSlept > HEARTBEAT_THREASHOLD && this->userLoggedin){
			SendHeartBeat();
			threadSlept = 0;
		}

		//Send packet function
		try{
			Threading::Monitor::Enter(sendPacketQueueLock);
			if(sendPacketQueue->Count){
				//There is element in the queue
				currentPointer = 0;
				totalCounter = sendPacketQueue->Count;
				while(currentPointer < totalCounter){
					packet = sendPacketQueue->Last->Value;
					sendPacketQueue->RemoveLast();
					if((packet->timeSlept == 0 || packet->timeSlept >= packet->packetTimeOutLimit) 
						&& packet->sentCounter <= packet->packetTimeOutCounterLimit){
						//This message need to be sent
						dest = gcnew IPEndPoint(packet->targetIP, packet->targetPort);
						this->listenClient->Send(packet->packetContent, packet->packetContent->Length, dest);
						packet->sentCounter++;
						//Reset the time slept to 0 and plus THREAD_SLEEP_TIME since it will go to sleep THREAD_SLEEP_TIME after this cycle
						packet->timeSlept = THREAD_SLEEP_TIME;
					}
					else{
						packet->timeSlept = packet->timeSlept + THREAD_SLEEP_TIME;
					}

					//Start to check if need to add this packet back to queue
					if (packet->packetContent->Length == UDP_PACKET_HEADER_SIZE){
						//this is an ack packet,remove it
					}
					else if ((packet->sentCounter >= packet->packetTimeOutCounterLimit)
						&&  (packet->timeSlept >= packet->packetTimeOutLimit)){
							//The packet is time out
							//Add to the removed dict, remove all the relative packet with same messageID, mark them as timeout
							if (!this->partialMessageQueue->ContainsKey(packet->messageID)){
								packetToBeRemoved->Add(packet->messageID,L"");
							}
					}
					else{

						sendPacketQueue->AddFirst(packet);
					}
					currentPointer++;
				}
			}
			Threading::Monitor::Exit(sendPacketQueueLock);
		}
		catch (ThreadAbortException^ ){
			//Threading::Monitor::Exit(sendPacketQueueLock);
		}
		catch (Exception ^ e) {
			MessageBox::Show("Exception in SendThread: " + e->ToString());
			Threading::Monitor::Exit(sendPacketQueueLock);
		}

		//Start to process the dictionary that remove all related packet 
		//and notify sendQueue the message is timeout
		if(packetToBeRemoved->Count){
			keyColl = packetToBeRemoved->Keys;
			for each(msgID in keyColl){
				this->RemoveFromSendPacketQueueByMessageID(msgID);
				this->ModifySendQueueMessageStatus(msgID,OuSns::TIMEOUT);
			}
			packetToBeRemoved->Clear();
		}

	}
	return ;

}


/*
 * This is the function that will add the message into sendPacketQueue
 */
System::Void Communication::AddToSendPacketQueue(OusnsPacket^ packet){
	try {
		Threading::Monitor::Enter(sendPacketQueueLock);
		this->sendPacketQueue->AddFirst(packet);
		Threading::Monitor::Exit(sendPacketQueueLock);
	} catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendPacketQueueLock);
	}
}

/*
 * This is the function that will add an array of packet into sendPacketQueue
 */
System::Void Communication::AddToSendPacketQueue(array<OusnsPacket^>^ packetArray){
	try {
		Threading::Monitor::Enter(sendPacketQueueLock);
		for each(OusnsPacket^ i in packetArray){

			this->sendPacketQueue->AddFirst(i);
		}
		Threading::Monitor::Exit(sendPacketQueueLock);
	} 
	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendPacketQueueLock);
	}
}

/*
* This is the function that will remove the packet from the sendPacketQueue
*/
System::Void Communication::RemoveFromSendPacketQueue(String^ packetID){
	OusnsPacket^ packet;
	int currentPtr;
	int totalCounter;
	/*
	if (DEBUG_THREAD) {
	MessageBox::Show("Removing " + packetID + "from the send queue.");
	}*/

	try{
		Threading::Monitor::Enter(sendPacketQueueLock);
		if(sendPacketQueue->Count){
			//There is element in the queue
			currentPtr = 0;
			totalCounter = sendPacketQueue->Count;
			while(currentPtr < totalCounter){
				packet = sendPacketQueue->Last->Value;
				sendPacketQueue->RemoveLast();
				if(packet->packetID->CompareTo(packetID) != 0){
					//not the one, push the message back
					sendPacketQueue->AddFirst(packet);
				}
				else{
					//find the one, just break, so the message has been pop out
					break;
				}
				currentPtr++;
			}
		}
		Threading::Monitor::Exit(sendPacketQueueLock);
	}

	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendPacketQueueLock);
	} 
}

/*
* This is the function that will remove all the packet with same messageID
* from the sendPacketQueue 
*/


System::Void Communication::RemoveFromSendPacketQueueByMessageID(String^ messageID){
	OusnsPacket^ packet;
	int currentPtr;
	int totalCounter;
	try{
		Threading::Monitor::Enter(sendPacketQueueLock);
		if(sendPacketQueue->Count){
			//There is element in the queue
			currentPtr = 0;
			totalCounter = sendPacketQueue->Count;
			while(currentPtr < totalCounter){
				packet = sendPacketQueue->Last->Value;
				sendPacketQueue->RemoveLast();
				if(packet->messageID->CompareTo(messageID) != 0){
					//not the one, push the message back
					sendPacketQueue->AddFirst(packet);

				}
				else{
					//find the one, do not add back
				}
				currentPtr++;
			}
		}
		Threading::Monitor::Exit(sendPacketQueueLock);
	}

	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:sendQueue: " + e->ToString());
		Threading::Monitor::Exit(sendPacketQueueLock);
	} 
}

/*
* This function will add the just received packet into the receievd packet queue
*/
System::Void Communication::AddToReceivedPacketQueue(OusnsPacket ^ packet){
	try {
		Threading::Monitor::Enter(receivedPacketQueueLock);
		this->receivedPacketQueue->AddFirst(packet);
		Threading::Monitor::Exit(receivedPacketQueueLock);
	}
	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock: receivedPacketQueueLock: " + e->ToString());
		Threading::Monitor::Exit(receivedPacketQueueLock);
	} 

}
