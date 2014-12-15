#include "stdafx.h"

#pragma once

/* There are three types of jobs that may be put into the work queue:
   1. Message body: this job is put onto the queue by the main (application) thread
					when the user sends a message to a friend of his/hers.
					To process a message body, wrap it in an XML packet and send it to
					the destination IP end point.
   2. Packet resend: this job is put onto the queue by the time-out stack (thread).
					 To process a packet resend, send the packet directly.
   3. Internet Packet: this job is put onto the queue by the listening thread.
*/

enum job_types {MESSAGE_BODY, RESEND, INTERNET_PACKET, LOGIN_PACKET, LOGIN_RESEND};


namespace OuSns{
public ref class ChatMessage{
public:
	String^ text;
	DateTime^ time;
	unsigned int  srcID;
	unsigned int groupID;
public:
	ChatMessage(String ^ text, unsigned int srcID, DateTime ^ time){
		this->text = text;
		this->srcID = srcID;
		this->time = time;
		this->groupID = 0;
	}
	/* 
	 * This is the constructor used for group chat message
	 */
	ChatMessage(String^ text, unsigned int srcID, unsigned int groupID, DateTime^ time){
		this->text = text;
		this->srcID = srcID;
		this->time = time;
		this->groupID = groupID;
	}
};	

}

public ref class OusnsPacket{
public:
	System::String^ packetID;
	System::String^ messageID;
	IPAddress ^ targetIP;
	unsigned short targetPort;
	
	unsigned short currentPacket;
	unsigned short totalPacket;
	
	int timeSlept;
	int sentCounter;
	array<Byte> ^ packetContent;
	unsigned short packetTimeOutLimit;
	unsigned short packetTimeOutCounterLimit;
	//MessageFunctionCode msgCode;
	//NatType natType;
	//This constructor can setup the time out limit and time out counter limit
	OusnsPacket(String^ messageIDInput, String^ packetIDInput,
		unsigned short currentPacketInput, unsigned short totalPacketInput,array<Byte>^ packetContentInput, 
		IPAddress ^ targetIPInput, unsigned short targetPortInput,
		unsigned short timeOutLimitInput, unsigned short timeOutCounterLimitInput){
		
		this->sentCounter = 0;
		this->packetID = packetIDInput;
		this->messageID = messageIDInput;
		this->packetContent = gcnew array<Byte>(packetContentInput->Length);
		Array::Copy(packetContentInput,0,packetContent,0,packetContentInput->Length);
		this->currentPacket = currentPacketInput;
		this->totalPacket = totalPacketInput;
		this->targetIP = targetIPInput;
		this->targetPort = targetPortInput;
		this->timeSlept = 0;
		this->packetTimeOutLimit = timeOutLimitInput;
		this->packetTimeOutCounterLimit = timeOutCounterLimitInput;
	}

};


ref class OusnsPacket;

public ref class OusnsPartialMessage{
public:
	unsigned short counter;
	unsigned short totalPacketNumber;
	int accessTime;
	unsigned short timeOutLimit;
	unsigned short totalLength;
	array<bool>^ filledArray;
	array<array<Byte>^>^ packetContentArray;
	IPAddress^ destIP;
	unsigned short destPort;
	
	OusnsPartialMessage(unsigned short totalPacketNumber, unsigned short timeOutLimitInput,IPAddress ^ destIP,unsigned short destPort){
		this->counter =0;
		this->accessTime = GetTickCount();
		this->packetContentArray = gcnew array<array<Byte>^>(totalPacketNumber);
		//this->packetArray->Initialize();
		this->filledArray = gcnew array<bool>(totalPacketNumber);
		this->totalPacketNumber = totalPacketNumber;
		this->timeOutLimit = timeOutLimitInput;
		for each(bool b in filledArray)
			b = false;
		this->destIP = destIP;
		this->destPort = destPort;
	}

	System::Void OusnsPartialMessage::AddPacket(OusnsPacket^ receivedPacket){
		if(this->filledArray[receivedPacket->currentPacket] ==  false){
			this->packetContentArray[receivedPacket->currentPacket] = gcnew array<Byte>(receivedPacket->packetContent->Length);
			Array::Copy(receivedPacket->packetContent,0,this->packetContentArray[receivedPacket->currentPacket],0,receivedPacket->packetContent->Length);
			this->counter++;
			this->totalLength  = this->totalLength + receivedPacket->packetContent->Length;
			this->accessTime = GetTickCount();
			this->filledArray[receivedPacket->currentPacket] = true;
		}
	}
};


public ref class DirectTransferFile {
public: String ^ fileName;
		String ^ filePath;
		int fileSize;
		String ^ md5;
		bool isCancelled;
		bool isSender;
		BackgroundWorker ^ worker;

public: DirectTransferFile(String ^ fileName, String ^ filePath, int fileSize, String ^ md5) {
	this->fileName = fileName;
	this->filePath = filePath;
	this->fileSize = fileSize;
	this->md5 = md5;
	this->isSender = true;
	this->isCancelled = false;
}

public: DirectTransferFile(String ^ fileName, int fileSize, String ^ md5) {
	this->fileName = fileName;
	this->fileSize = fileSize;
	this->md5 = md5;
	this->isSender = false;
	this->isCancelled = false;
}

};

// This class is used to pass multiple parameters into the ParameterizedThreadStart delegate.
public ref class ExchangePortInfoParam {
public: String ^ fileName;
		String ^ md5;

		ExchangePortInfoParam(String ^ fileName, String ^ md5){
		
			this->fileName = fileName;
			this->md5 = md5;
		}
};

public ref class FileTransferPort {

public: String ^ fileName;
		String ^ md5;
		bool isSender;
		String ^ localPath;
		int localPort;
		IPAddress ^ peerAddress;
		int peerPort;

		FileTransferPort(String ^ fileName, String ^ md5) {
			this->fileName = fileName;
			this->md5 = md5;
			this->isSender = false;
		}

		FileTransferPort(String ^ fileName, String ^ md5, String ^ localPath) {
			this->fileName = fileName;
			this->md5 = md5;
			this->isSender = true;
			this->localPath = localPath;
		}
};
