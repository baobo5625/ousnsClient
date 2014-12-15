#include "stdafx.h"
//Full construction of the Ousns Message


OusnsMessage::OusnsMessage(OuSns::ThreadType messageSourceInput,OuSns::ThreadType messageDestInput,
						   OuSns::MessageType messageTypeInput, int returnCodeInput, 
						   String^ messageIDInput, OuSns::ActionType actionTypeInput, System::String^ messageContentInput, IPAddress ^ destIP,
	unsigned short destPort,bool waitResponseInput){
	
	this->messageSourceThread = messageSourceInput;
	this->messageDestThread = messageDestInput;
	this->messageType=messageTypeInput;
	this->returnCode = returnCodeInput;
	this->messageID = messageIDInput;
	this->actionType = actionTypeInput;
	this->messageContent = messageContentInput;
	this->destIP = destIP;
	this->destPort = destPort;
	this->timeSlept = 0;
	this->messageStatus = OuSns::CREATED;
	this->messageTimeOutLimit = SERVER_TIMEOUT;
	this->messageTimeOutCounterLimit = SERVER_RESEND_TIME;
	this->msgCode = OuSns::NORMAL;
	this->waitResponse = waitResponseInput;
}

//Construction of the Ousns Message with message function code 
OusnsMessage::OusnsMessage(OuSns::ThreadType messageSourceInput,OuSns::ThreadType messageDestInput,
						   OuSns::MessageType messageTypeInput, int returnCodeInput, 
	String^ messageIDInput, OuSns::ActionType actionTypeInput, System::String^ messageContentInput, IPAddress ^ destIP,
	unsigned short destPort,bool waitResponseInput,OuSns::MessageFunctionCode code){
	
	this->messageSourceThread = messageSourceInput;
	this->messageDestThread = messageDestInput;
	this->messageType=messageTypeInput;
	this->returnCode = returnCodeInput;
	this->messageID = messageIDInput;
	this->actionType = actionTypeInput;
	this->messageContent = messageContentInput;
	this->destIP = destIP;
	this->destPort = destPort;
	this->timeSlept = 0;
	this->messageStatus = OuSns::CREATED;
	if( code == OuSns::P2P_NORMAL){
		this->messageTimeOutLimit = P2P_TIMEOUT;
		this->messageTimeOutCounterLimit = P2P_RESEND_TIME;
	}
	else{
		this->messageTimeOutLimit = SERVER_TIMEOUT;
		this->messageTimeOutCounterLimit = SERVER_RESEND_TIME;
	}
	this->msgCode = code;
	this->waitResponse = waitResponseInput;
}


// The constructor will only be called by merge packet to message thread for every packet the listen thread receives.

OusnsMessage::OusnsMessage( System::String^ messageContentInput,IPAddress ^ destIP,unsigned short destPort){
	this->messageSourceThread = OuSns::LISTEN;
	this->messageDestThread = OuSns::WORK;
	this->messageType= OuSns::UNKNOWN;
	this->returnCode = -1;
	this->messageID = "";
	this->actionType = OuSns::LISTENMESSAGE;
	this->messageContent = messageContentInput;
	this->timeSlept = 0;
	this->messageStatus =OuSns::RECEIVED;
	this->messageTimeOutLimit = SERVER_TIMEOUT;
	this->messageTimeOutCounterLimit = SERVER_RESEND_TIME;
	this->msgCode = OuSns::NORMAL;
	this->waitResponse = false;
	this->destPort = destPort;
	this->destIP = destIP;
}
