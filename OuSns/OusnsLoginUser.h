
#ifndef OUSNSLOGINUSER_H_
#define OUSNSLOGINUSER_H_

/*
 * This class defines a child class of users
 */
#pragma managed

#include "stdafx.h"
#include "OusnsUser.h"


namespace OuSns{

	ref class OusnsFriend;
	ref class OusnsGroup;
	ref class OusnsFocusUser;
	public ref class OusnsLoginUser: public OuSns::OusnsUser
	{

	public:

		//LinkedList<OusnsFriend^> ^ friendList;

		array<OusnsFriend^> ^ friendListArray;

		array<OusnsGroup^>^ groupListArray;

		array<OusnsFocusUser^>^ focusUserListArray;
		array<OusnsGroup^>^ focusGroupListArray;

		/*
		* This variable contains the recent update list for the recent updates
		* Recent Updates including updates files, user status updates (to be discussed)
		* The variable type can be changed or defined individually.The user may require an
		* earlier timeframe of the updates, when get from the server, just append to the 
		* previous linked list.
		*/ 
		LinkedList<String^>^ recentUpdateLinkedList;
		String^ emailID;
		unsigned int loginTimeStamp;
		String^ localProfilePath;

		IPAddress^ ipAddr;
		unsigned short recvPort;
		// The session ID will be filled when login and when get friend list.
		String^ sessionID;

		OuSns::NatType natType;

		OuSns::UserStatus status;

		//The profile the online user are currently using
		String^ profile;



	public:
		OusnsLoginUser(unsigned int userID,String^ emailID,String^ email, String^ nickname,
			String^ signature, String^ displayPictureFilename,int exp, 
			unsigned int focusCounter,String^ personalStatement,
			String^ city, String^ province, String^ country,IPAddress^ ipaddr,
			unsigned short recvPort, OuSns::NatType natType, int sex,int zodiac,unsigned short birthYear,
			unsigned short birthMonth, unsigned short birthDay, 
			OuSns::UserStatus status,String^ profile, String^ sessionID) :
		OusnsUser(userID,email, nickname, signature, displayPictureFilename,exp,
			focusCounter, personalStatement, city,province, country, sex,zodiac, 
			birthYear,birthMonth, birthDay){
				this->emailID = emailID;
				this->localProfilePath = OUSNS_USER_PATH + "\\" + this->userID.ToString() + "\\" + this->profile;
				this->friendListArray = gcnew array<OusnsFriend^>(0);
				this->groupListArray = gcnew array<OusnsGroup^>(0);
				this->focusUserListArray =  gcnew array<OusnsFocusUser^>(0);
				this->focusGroupListArray = gcnew array<OusnsGroup^>(0);
				this->loginTimeStamp = 0;
				this->ipAddr = ipaddr;
				this->recvPort = recvPort;
				this->natType = natType;
				this->status = status;
				this->profile = profile;
				this->sessionID = sessionID;

				
		}
	public:
		~OusnsLoginUser(void){
		}


	public:
		property String^ LocalProfilePath{
			String^ get(){
				return this->localProfilePath;
			}
			void set(String^ value){
				this->localProfilePath = value;
			}
		}

		property String^ EmailID{
			String^ get(){
				return this->emailID;
			}
		}

		property unsigned int LoginTimeStamp{
			void set(unsigned int value){
				this->loginTimeStamp = value;
			}
			unsigned int get(){
				return this->loginTimeStamp;
			}
		}

		property String^ DownloadingFileListPath{
			String^ get(){
				return OUSNS_USER_PATH + "\\" + this->userID.ToString() + "\\" + OUSNS_DOWNLOADING_LIST_FILENAME;
			}
		}
		property String^ DownloadedFileListPath{
			String^ get(){
				return OUSNS_USER_PATH + "\\" + this->userID.ToString() + "\\" + OUSNS_DOWNLOADED_LIST_FILENAME;
			}
		}
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
		* This function will update the friend list array
		*/
		System::Void OusnsLoginUser::UpdateFriendArray(array<OusnsFriend^>^ ousnsFriendInput);

		System::Void OusnsLoginUser::UpdateFriendArray(LinkedList<OusnsFriend^>^ ousnsFriendInput);

		/*
		* This function will update the group list array
		*/
		System::Void OusnsLoginUser::UpdateGroupArray(array<OusnsGroup^>^ ousnsGroupInput);

		System::Void OusnsLoginUser::UpdateGroupArray(LinkedList<OusnsGroup^>^ ousnsGroupInput);

		/*
		* This function will update the focus list array
		*/
		System::Void OusnsLoginUser::UpdateFocusUserArray(array<OusnsFocusUser^>^ ousnsFocusInput);
		System::Void OusnsLoginUser::UpdateFocusUserArray(LinkedList<OusnsFocusUser^>^ ousnsFocusInput);

		/*
		* This function will update the focus list array
		*/
		System::Void OusnsLoginUser::UpdateFocusGroupArray(array<OusnsGroup^>^ ousnsFocusInput);
		System::Void OusnsLoginUser::UpdateFocusGroupArray(LinkedList<OusnsGroup^>^ ousnsFocusInput);




		/*
		* This function will add the ousns friend into friend list 
		* if the friend was not in the list
		*/
		System::Void OusnsLoginUser::AddFriend(OusnsFriend^ friendInput);

		/*
		* This function will add the ousns group into group list 
		* if the group was not in the list
		*/
		System::Void OusnsLoginUser::AddGroup(OusnsGroup^ groupInput);

		/*
		* This function will add the focus user into focus list 
		* if the user was not in the list
		*/
		System::Void OusnsLoginUser::AddFocus(OusnsFocusUser^ focusUserInput);
		/*
		* This function will add the focus user into focus list 
		* if the user was not in the list
		*/
		System::Void OusnsLoginUser::AddFocus(OusnsGroup^ focusGroupInput);
		/*
		* This function will remove the ousns friend into friend list 
		* if the friend was in the list
		*/
		System::Void OusnsLoginUser::RemoveFriend(unsigned int friendIDInput);

		/*
		* This function will remove the ousns group into group list 
		* if the group was in the list
		*/
		System::Void OusnsLoginUser::RemoveGroup(unsigned int groupIDInput);

		/*
		* This function will remove the focus user into focus list 
		* if the user was in the list
		*/
		System::Void OusnsLoginUser::RemoveFocus(unsigned int focusIDInput);



		/*
		* This function will check if such friend is exist in the friend list
		*/
		bool OusnsLoginUser::ExistFriend(unsigned int friendID);

		/*
		* This function will check if such group is exist in the group list
		*/
		bool OusnsLoginUser::ExistGroup(unsigned int groupID);

		/*
		* This function will check if such focus user is exist in the focus list
		*/
		bool OusnsLoginUser::ExistFocusUser(unsigned int focusUserID);

		/*
		* This function will check if such focus user is exist in the focus list
		*/
		bool OusnsLoginUser::ExistFocusGroup(unsigned int focusGroupID);

		/*
		* This function will find the ousns friend with such ID
		* If the friend does not exist, return null ptr
		*/
		OusnsFriend ^ OusnsLoginUser::FindFriend(unsigned int id);

		/*
		* This function will find the ousns group with such ID
		* If the group does not exist, return null ptr
		*/
		OusnsGroup^ OusnsLoginUser::FindGroup(unsigned int id);

		/*
		* This function will be used when find the group member within the 
		* specific group and with the userID
		* If such user does not exist, return nullptr
		*/

		OusnsUser^ OusnsLoginUser::FindGroupMember(unsigned int groupID, unsigned int userID);

		/*
		* This function will be used for find such focus user
		* if such user does not exist, return nullptr
		*/
		OusnsFocusUser^ OusnsLoginUser::FindFocusUser(unsigned int userID);


		/*
		* This function will be used for find such focus group
		* if such user does not exist, return nullptr
		*/
		OusnsGroup^ OusnsLoginUser::FindFocusGroup(unsigned int groupID);


	};
}


#endif