#include "stdafx.h"
#include "Communication.h"
#include "LoginDlg.h"
//#include "MainDlg1.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "OusnsLoginUser.h"



Communication::Communication(OuSns::LoginDlg^ dialog)
{
	// Start the listening thread.
	workQueue = gcnew System::Collections::Generic::LinkedList<OusnsMessage ^>();
	sendQueue = gcnew System::Collections::Generic::LinkedList<OusnsMessage ^>();
	sendPacketQueue = gcnew System::Collections::Generic::LinkedList<OusnsPacket ^>();
	receivedPacketQueue = gcnew System::Collections::Generic::LinkedList<OusnsPacket^>();
	partialMessageQueue = gcnew System::Collections::Generic::Dictionary<String^, OusnsPartialMessage^>();
	downloaderCommandQueue = gcnew System::Collections::Generic::LinkedList<OusnsMessage ^>();
	loginDlg = dialog;
	msgProcessor = gcnew MessageProcessor(this);
	msgCreator = gcnew MessageCreator();
	this->sendHeartBeatFlag = false;
	this->userLoggedin = false;

	this->startedMainDlg = false;
	this->userPublicIP = IPAddress::Parse("0.0.0.0");
	this->userPublicIPArray = this->userPublicIP->GetAddressBytes();
	this->userPublicPort = 0;
	this->userPublicPortArray = BitConverter::GetBytes(this->userPublicPort);
	this->userNatType = OuSns::StunTypeUnknown;
	try{	
		listenClient = gcnew UdpClient();
		this->serverAddr = IPAddress::Parse(SERVER_ADDRESS);
		this->serverPort = SERVER_PORT;
		this->serverAddrArray = this->serverAddr->GetAddressBytes();
		this->serverPortArray = BitConverter::GetBytes(this->serverPort);
		this->enableListen = false;
		this->listenClient->EnableBroadcast = true;
	}
	catch(Exception^ e){
		Console::WriteLine(  "Exception caught!!!" );
		Console::Write(  "Source : " );
		Console::WriteLine( e->Source );
		Console::Write(  "Message : " );
		Console::WriteLine( e->Message );
		this->enableListen = false;
	}
	
}

Communication::~Communication(void)
{
}

/*
 * This function is called by the Work thread, and it calls a different function in the message processor depending
 * on the action type of the message.
 */ 
System::Void Communication::ProcessMessage(OusnsMessage^ msg){
	if(msg == nullptr){
		return;
	}
	else{
		this->msgProcessor->ProcessMessage(msg);
	}
}




/*
 * This is the function that will send the heart beat to server, called by the listen thread
 */
System::Void Communication::SendHeartBeat(){
	this->heartBeatMessage->messageStatus = OuSns::CREATED;
	this->heartBeatMessage->timeSlept = 0;
	this->AddToSendQueue(this->heartBeatMessage);

}

/*
 * This is the function that will send file to the other client, it will called by the SendThread
 * using the thread pool
 */
System::Void Communication::SendFile(){
}


/*
 * This function will enable or disable the listen function (not stopping the thread)
 */
System::Void Communication::EnableListenFunction(bool flag){
	this->enableListen = flag;
}


/*
 * Call this function when successfully logged in to start send heart beat function
 */
System::Void Communication::InitializeHeartBeat(void){

	this->heartBeatMessage =  this->msgCreator->MakeHeartBeatMessage(this->loginUser->userID,this->loginUser->sessionID);
	this->sendHeartBeatFlag = true;
	return;
}

/*
 * This function will turn some flags if the user is login/logoff
 */
	
System::Void Communication::UserLoginLogoff(bool loginFlag){
	this->userLoggedin = loginFlag;
	if(loginFlag){
		//login operation
		
		this->userPublicIP = this->loginUser->ipAddr;
		this->userPublicIPArray = this->userPublicIP->GetAddressBytes();
		this->userPublicPort = this->loginUser->recvPort;
		this->userPublicPortArray = BitConverter::GetBytes(this->userPublicPort);
		this->userNatType = this->loginUser->natType;
		this->InitializeHeartBeat();
	}
	else{
		this->sendHeartBeatFlag = false;
	}
}