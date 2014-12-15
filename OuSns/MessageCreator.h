#include "stdafx.h"

#ifndef MESSAGECREATOR_H_
#define MESSAGECREATOR_H_

#pragma managed

/*
 * This is a class will generate the OusnsMessage
 * Each thread will have their own creator instance.
 */

class DownloaderCommunication;

namespace OuSns{
	ref class OusnsLoginUser;
	public ref class MessageCreator{

	public:
		static int nextMsgID = 1;
		IPAddress^ serverAddr;
		unsigned short serverPort;

	public:
		MessageCreator(void);

	protected:
		~MessageCreator(void){}

	public:

		/*1
		* This function will return an unique message ID for any MESSAGE that to be sent
		* this is not applied for the packet
		*/
		String^ MessageCreator::GetMessageID(String^ userID,String^ userIDType);

		/*------------------------------------------LoginUserMessageCreator.cpp----------------------------------------------*/

		/*
		* This function will generate the login packet (1.1)
		*/
	public: OusnsMessage ^ MessageCreator::MakeLoginMessage(String ^ userID, String ^ password, String ^ userIDType,
				IPAddress^ ipAddress, unsigned short destPort, LinkedList<String^>^macAddressArray, 
				int userStatus, OuSns::NatType natType);

			/*
			* This function will generate the logoff message (1.3)
			*/
			OusnsMessage^ MessageCreator::MakeLogoffMessage(unsigned int userIDInt, String^ sessionID);


			/*
			* This function will make a message that to change the user status (1.4)1
			*/
			OusnsMessage^ MessageCreator::MakeChangeStatusMessage(unsigned int userIDInt, String^ sessionID, OuSns::UserStatus status);


			/*
			* This function will return an update personal information message (1.6)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeUpdatePersonalInformationMessage(OusnsLoginUser^ usr);

			/*
			* This function will make a message that to get the recent update events (1.8)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeGetRecentUpdateMessage(void);


			/*
			* This function will return the heart beat message (1.10)
			*/
			OusnsMessage^ MessageCreator::MakeHeartBeatMessage(unsigned int userIDInt, String^ sessionID);

			/*
			 * This function will return the make download list message (1.12)
			 */
			OusnsMessage^ MessageCreator::MakeDownloadListMessage(unsigned int userIDInt, String ^ sessionID, IPAddress^ ipAddress, unsigned short destPort);

			/*------------------------------------------------FriendMessageCreator.cpp--------------------------------------------*/

			/*
			* This function will return an add friend message (2.1)
			*/
			OusnsMessage^ MessageCreator::MakeAddFriendMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetUserID, String^ reason);


			/*
			* The reply add friend request (2.3)
			*/
			OusnsMessage^ MessageCreator::MakeReplyAddFriendMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetUserID, int decision, unsigned int sysMsgID);


			/*
			* This function will make a remove friend message (2.5)
			*/
			OusnsMessage^ MessageCreator::MakeRemoveFriendMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetFriendID);

			/*
			* This function will make a message that to get the friend list (2.7)
			*/

			// Rmoved OusnsMessage^ MessageCreator::MakeGetFriendListMessage(unsigned int userIDInt, String ^ sessionID, IPAddress^ ipAddress, unsigned short destPort);

			/*
			* This function will return a search friend message (2.9)
			*/
			OusnsMessage^ MessageCreator::MakeSearchFriendMessage(unsigned int userIDInt, String^ sessionID,
				int searchUserIDType, String^ keyword, int offset, int searchLimit);



			/*
			* This function will return a query user information message (2.11)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeQueryUserInfoMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetUserID);

			/*
			* This function will return the get offline message (2.13)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeGetOfflineMessage(unsigned int userIDInt, String^ sessionID);

			/*
			* This function will return the send offline message (2.15)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeSendOfflineMessage(unsigned int userIDInt, String^ sessionID,unsigned int targetUserID, unsigned int groupID,String^ textMessage);

			/*
			* This fucntion will return the clear offline message (2.17)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeClearOfflineMessage(unsigned int userIDInt, String^ sessionID);


			/*-----------------------------------------GroupMessageCreator.cpp-----------------------------------------------*/
			/* 
			* This function will return a Join group message (3.1)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeJoinGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID, String^ reason);

			/* 
			* This function will return a reply Join group message (3.3)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeReplyJoinGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID, unsigned int userID, int decision, unsigned int sysMsgID);

			/* 
			* This function will return a Query group information message (3.5)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeQueryGroupInformationMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID);
			/*
			* This function will return an exit group message (3.7)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeExitGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID);
			/*
			* This function will return a download group list message (3.11)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeDownloadGroupListMessage(unsigned int userIDInt, String ^ sessionID);

			/*
			* This function will return a search group message (3.13)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeSearchGroupMessage(unsigned int userIDInt, String^ sessionID,	int searchUserIDType, String^ keyword, int offset, int searchLimit);


			/*
			* This function will return a update group member status mesage (3.15)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeUpdateGroupMemberStatusMessage(unsigned int userIDInt, String^ sessionID,unsigned int groupID);
			/*
			* This function will make a create group message (3.17)
			* (incompleted)
			*/
			OusnsMessage^ MessageCreator::MakeCreateGroupMessage(unsigned int userID, String^ sessionID, String^ groupName,\
				String^ groupDescription, String^ groupCategory, String^ groupAnounancement, String^ groupTag, LinkedList<unsigned int>^ memberList);

			/*-----------------------------------------FocusMessageCreator.cpp-----------------------------------------------*/
			/*
			* This function will make a focus user message (4.1)
			*/
			OusnsMessage^ MessageCreator::MakeFocusUserMessage(unsigned int userIDInt, String^ sessionID,unsigned int userID, String^ userIDType, String^ extensions);
			/*
			* This function will make a get focus people list message (4.3)
			*/
			//OusnsMessage^ MessageCreator::MakeGetFocusPeopleList(unsigned int userIDInt, String^ sessionID);
			/*
			* This function will make a remove focus user message (4.5)
			*/
			OusnsMessage^ MessageCreator::MakeRemoveFocusUserMessage(unsigned int userIDInt, String^ sessionID, unsigned int userID, String^ userIDType);

			/*----------------------------------PeerMessageCreator.cpp---------------------------------------*/
			OusnsMessage ^ MessageCreator::MakePeerMessage(String ^ text, int srcID, String ^ sessionID, 
				IPAddress ^ dest_ip, int port,OuSns::NatType natType);


			OusnsMessage ^ MessageCreator::MakeChangeStatusPeer(int status, int prevStatus, int srcID, 
				String ^ sessionID, IPAddress ^ srcIP, int srcPort, OuSns::NatType natType, IPAddress ^ destIP, int destPort);

			OusnsMessage ^ MessageCreator::MakeRequestFileTransfer(int srcID, String ^ sessionID, 
				String ^ fileName, int fileSize, String ^ md5, IPAddress ^ destIP, int destPort, OuSns::NatType natType);

			OusnsMessage ^ MessageCreator::MakeReplyFileTransfer(int srcID, String ^ sessionID, int decision,
				String ^ fileName, int fileSize, String ^ md5, IPAddress ^ destIP, int destPort, OuSns::NatType natType);

			OusnsMessage ^ MessageCreator::MakeCancelFileTransfer(int srcID, String ^ sessionID,
				String ^ fileName, int fileSize, String ^ md5, IPAddress ^ destIP, int destPort, OuSns::NatType natType);

			OusnsMessage ^ MessageCreator::MakeHolePunching(int srcID, String ^ sessionID,
				String ^ fileName, String ^ md5, IPAddress ^ destIP, int destPort, OuSns::NatType natType);

			OusnsMessage ^ MessageCreator::MakeHolePunchingResponse(int srcID, String ^ sessionID,
				String ^ fileName, String ^ md5, IPAddress ^ destIP, int destPort, OuSns::NatType natType);

			/* ----------------------------------DownloaderMessageCreator.cpp--------------------------------*/
			OusnsMessage^ MessageCreator::MakeJobEntry(DownloaderCommunication* dc);

			OusnsMessage^ MessageCreator::MakeCommandEntry(char commandChar, String^ commandTarget,String^ magnetURI,LinkedList<String^>^ params);

	};
}
#endif
