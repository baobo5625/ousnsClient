/*
 * This class is used for each friend in the friend list
 */


#pragma once
#include "stdafx.h"
//#include "SharedFolder.h"
//#include "gcroot.h"
#include "OusnsUser.h"

namespace OuSns{

	public ref class OusnsFriend :public OuSns::OusnsUser
	{

	public: 
		//This is the local group that this friend belongs to
		System::String^ localGroup;
		System::String^ commentName;
		IPAddress^ ipAddr;
		unsigned short recvPort;
		// The session ID will be filled when login and when get friend list.
		String^ sessionID;

		OuSns::NatType natType;

		OuSns::UserStatus status;

		//The profile the online user are currently using
		String^ profile;



	public:
		//Basic Constructor
		OusnsFriend(unsigned int userID,System::String^ email, String^ nickname,
			String^ signature, String^ displayPictureFilename,
			IPAddress^ ipaddr,unsigned short recvPort, OuSns::NatType natType,
			String^ profile,OuSns::UserStatus status,String^ sessionID):
		OusnsUser(userID,email,nickname, signature,
			displayPictureFilename,0,0,
			L"", L"", L"",L"",
			0,0,1900,1,1)
		{
			//this->friendList = gcnew LinkedList<OusnsFriend ^>();
			//this->groupList = gcnew LinkedList<OusnsGroup^>();
			this->commentName = nickname;
			this->localGroup = L"";
			this->ipAddr = ipAddr;
			this->recvPort = recvPort;
			this->natType = natType;
			this->status = status;
			this->sessionID = sessionID;
			this->profile = profile;
		}

		//Full Constructor

		OusnsFriend(unsigned int userID,System::String^ email, String^ nicknameInput,
			String^ signature, String^ displayPictureFilename,String^ localGroupInput,int exp, 
			unsigned int focusCounter,String^ personalStatement,
			String^ city, String^ province, String^ country,IPAddress^ ipaddr,
			unsigned short recvPort, OuSns::NatType natType,
			int sex,int zodiac,unsigned short birthYear,
			unsigned short birthMonth, unsigned short birthDay, 
			OuSns::UserStatus status,String^ profile, String^ sessionID):
		OusnsUser(userID,email,nicknameInput, signature,
			displayPictureFilename,exp,focusCounter,
			personalStatement, city, province, country,sex,zodiac,birthYear,
			birthMonth,birthDay)
		{
			//this->friendList = gcnew LinkedList<OusnsFriend ^>();
			//this->groupList = gcnew LinkedList<OusnsGroup^>();
			this->commentName = nicknameInput;
			this->localGroup = localGroupInput;
			this->ipAddr = ipAddr;
			this->recvPort = recvPort;
			this->natType = natType;
			this->status = status;
			this->sessionID = sessionID;
			this->profile = profile;
		}

		~OusnsFriend(void){}
		/*
		* The following method was inheriented from parent class OusnsUser
		getDisplayPicture(void);
		*/
		property IPAddress^ IpAddr{
			IPAddress^ get(){
				return this->ipAddr;
			}
			void set(IPAddress^ value){
				this->ipAddr = value;
			}
		}

		property unsigned short RecvPort{
			unsigned short get(){
				return this->recvPort;
			}
			void set(unsigned short value){
				this->recvPort = value;
			}
		}

		property String^ CommentName{
			String^ get(){
				return this->commentName;
			}
			void set(String^ value){
				this->commentName = value;
			}
		}
		property OuSns::UserStatus Status{
			OuSns::UserStatus get(){
				return this->status;
			}
			void set(OuSns::UserStatus value){
				this->status = value;
			}
		}

		property String^ Profile{
			String^ get(){
				return this->profile;
			}
			void set(String^ value){
				this->profile = value;
			}
		}

		property String^ SessionID{
			String^ get(){
				return this->sessionID;
			}
			void set(String^ value){
				this->sessionID = value;
			}
		}
		property OuSns::NatType NatType{
			OuSns::NatType get(){
				return this->natType;
			}
			void set(OuSns::NatType value){
				this->natType = value;
			}
		}
		/* Functions to be completed:
		public: bool getUserInfo(void){}
		public: bool focusUser(void){}
		public: void sendFile(void){}
		public: SharedObject getUserSharedFileRoot(void){}
		*/

	};

}

