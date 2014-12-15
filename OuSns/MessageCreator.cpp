#include "stdafx.h"
#include "MessageCreator.h"



MessageCreator::MessageCreator(void){
	this->serverAddr = IPAddress::Parse(SERVER_ADDRESS);
	this->serverPort = SERVER_PORT;
}

/*
 * This function will return an unique message ID for any MESSAGE that to be sent
 * this is not applied for the packet
 */
String^ MessageCreator::GetMessageID(String^ userID,String^ userIDType){
	this->nextMsgID++;
	if(userIDType->CompareTo(L"Email") == 0)
		return "9999" + "-" + this->nextMsgID.ToString();
	else
		return userID + "-" + this->nextMsgID.ToString();

}




