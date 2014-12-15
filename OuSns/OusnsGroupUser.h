/*
 * This class is used for each friend in the friend list
 */


#pragma once

#include "stdafx.h"
//#include "SharedFolder.h"
//#include "gcroot.h"
#include "OusnsUser.h"
namespace OuSns{
	public ref class OusnsGroupUser: public OuSns::OusnsUser
	{

	public: 
		unsigned int groupID;
		IPAddress^ ipAddr;
		unsigned short recvPort;
		// The session ID will be filled when login and when get friend list.
		String^ sessionID;

		OuSns::NatType natType;

		OuSns::UserStatus status;

		//The profile the online user are currently using
		String^ profile;

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

	public:
		/*
		OusnsGroupUser(unsigned int userID,System::String^ email, String^ nickname,
		String^ signature, String^ displayPictureFilename,int exp, 
		unsigned int focusCounter,String^ personalStatement,
		String^ city, String^ province, String^ country,IPAddress^ ipaddr,
		unsigned short recvPort, OuSns::NatType natType,
		String^ sex,unsigned short birthYear,
		unsigned short birthMonth, unsigned short birthDay, 
		OuSns::UserStatus status,String^ profile, String^ sessionID):
		OusnsUser(userID,email,nickname, signature,
		displayPictureFilename,exp,focusCounter,
		personalStatement, city, province, country,
		ipaddr,recvPort,natType,sex,0,birthYear,
		birthMonth,birthDay, status,profile,sessionID){

		}
		*/
		OusnsGroupUser(unsigned int userID,unsigned int groupID,String^ nickname,
			String^ displayPictureFilename):
		OusnsUser(userID,L"",nickname, L"",
			displayPictureFilename,0,0,
			L"", L"", L"", L"",0,0,1900,1,1){
				this->groupID = groupID;
				this->status = OuSns::OFFLINE;
				this->sessionID = "";
				this->profile = "";
				this->natType = OuSns::StunTypeUnknown;
				this->recvPort = 0;
		}

		System::Void UpdateGroupUserStatus(IPAddress^ ipaddr,unsigned short recvPort, OuSns::NatType natType,
			OuSns::UserStatus status,String^ sessionID){
				this->ipAddr = ipaddr;
				this->recvPort = recvPort;
				this->status = status;
				this->sessionID = sessionID;
				this->natType = natType;

		}


		~OusnsGroupUser(void){}
		/* Functions to be completed:
		bool getUserInfo(void);
		bool focusUser(void);
		void sendFile(void);
		SharedObject getUserSharedFileRoot(void);
		*/

	};


}
