#include "stdafx.h"
//#include "OusnsLoginUser.h"
#include "SharedFolder.h"


#pragma managed

/*
 * This is a class will parse the received message
 * Each thread will have their own processor instance.
 */

//ref class LoginDlg;
//ref class MainDlg;


namespace OuSns{
	ref class OusnsLoginUser;
	ref class SharedFolder;
	ref class Communication;
	ref class LoginDlg;
	ref class MainDlg;
	public ref class MessageProcessor{

	public:
		// This will be used for response P2P message.
		//MessageCreator^ msgCreator;
		//The communication instance, can be used to call RemoveFromSendQueue function etc
		Communication^ comm;
		Dictionary<String^,int>^ stringToActionTypeDict;
		Dictionary<int,String^>^ actionTypeToStringDict;
		OuSns::LoginDlg^ loginDlg;
		OuSns::MainDlg^ mainDlg;
		OusnsLoginUser^ loginUser;

	public:
		MessageProcessor(Communication^ comm);
	protected:
		~MessageProcessor(void){}
	public:

		/*
		* This function will initialize the dictionary of the action type, transform the action
		* type from string to integer.
		*/
		System::Void MessageProcessor::InitializeActionTypeDict(void);

		System::Void MessageProcessor::ProcessSendPacket(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessMessage(OusnsMessage^ msg);

		/*-----------------------------------LoginUserMessageProcessor.cpp----------------------------------*/



		/*
		* This function will process the returned login packet and 
		* construct the response message (1.2)
		*/
		System::Void MessageProcessor::ProcessLoginResponsePacket(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessHeartBeat(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessDownloadList(OusnsMessage ^ msg);
		/*-----------------------------------FriendMessageProcessor.cpp---------------------------------------*/

		System::Void MessageProcessor::ProcessAddFriendDecision(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessReplyAddFriend(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSearchFriend(OusnsMessage ^ msg);

		//Removed System::Void MessageProcessor::ProcessDownloadFriend(OusnsMessage ^ msg);

		/*-----------------------------------GroupMessageProcessor.cpp---------------------------------------*/

		System::Void MessageProcessor::ProcessJoinGroupDecision(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessReplyJoinGroup(OusnsMessage ^ msg);

		/*-----------------------------------FocusMessageProcessor.cpp---------------------------------------*/

		
		/*--------------------------------------SystemMessageProcessor.cpp-----------------------------*/

		System::Void MessageProcessor::ProcessSysAddFriend(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSysReplyAddFriend(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSysRemoveFriend(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessReplyAddFriendNotification(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSysJoinGroup(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSysReplyJoinGroup(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessSysExitGroup(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessReplyJoinGroupNotification(OusnsMessage ^ msg);

		/*---------------------------------------PeerMessageProcessor.cpp------------------------------*/

		System::Void MessageProcessor::ProcessChatMessage(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessChangeStatusPeer(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessCancelFileTransfer(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessHolePunching(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessRequestFileTransfer(OusnsMessage ^ msg);

		System::Void MessageProcessor::ProcessReplyFileTransfer(OusnsMessage ^ msg);


		// Use this function to process all responses that require no actions other than removing the message from the send
		// queue.
		//System::Void MessageProcessor::ProcessSimpleResponse(OusnsMessage ^ msg);


		/* --------------------------------DownloaderMessageProcessor.cpp-------------------------*/
		System::Void MessageProcessor::ProcessUpdateJob(OusnsMessage^ msg);

		System::Void MessageProcessor::ProcessDownloaderCommand(OusnsMessage^ msg);

	};



}
