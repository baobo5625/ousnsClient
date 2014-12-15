/*
 * This class is used for each group in the group list
 */
#pragma once

#include "stdafx.h"
#include "OusnsGroupUser.h"
namespace OuSns{
	public ref class OusnsGroup{

	private:

		unsigned int groupID;
		System::String^ groupName;
		System::String^ groupDescription;

		//Recently Added
		System::String^ groupCategory;
		System::String^ groupAnnounancement;
		//The OuID of the owner for this group
		unsigned int groupOwnerID;

		OusnsGroupUser^ groupOwner;
		System::String^ localGroup;
		//The list of groupAdmins
	public:
		Dictionary<unsigned int,unsigned int>^ groupAdmin;
		array<OusnsGroupUser^>^ groupMemberArray;

	public:
		OusnsGroup(unsigned int groupID, String^ groupName, String^ groupDescription, 
			String^ groupCategory, String^ groupAnnounancement, unsigned int groupOwner,
			Dictionary<unsigned int,unsigned int>^ groupAdminInput, array<OusnsGroupUser^>^ groupMemberArrayInput){
				this->groupID = groupID;
				this->groupName = groupName;
				this->groupDescription = groupDescription;
				this->groupCategory = groupCategory;
				this->groupAnnounancement = groupAnnounancement;
				//this->groupAdmin = gcnew array<unsigned int>(groupAdmin->Length);
				this->groupOwnerID = groupOwner;
				this->groupAdmin = gcnew Dictionary<unsigned int, unsigned int>();
				Dictionary<unsigned int, unsigned int>::KeyCollection^ keyColl = groupAdminInput->Keys;
				unsigned int adminOuID;
				for each(adminOuID in keyColl){
					this->groupAdmin->Add(adminOuID,0);
				}

				this->groupMemberArray = gcnew array<OusnsGroupUser^>(groupMemberArrayInput->Length);
				groupMemberArrayInput->CopyTo(this->groupMemberArray,0);
				OusnsGroupUser^ tempUser;
				for each (tempUser in this->groupMemberArray){
					if(groupOwner == tempUser->UserID){
						this->groupOwner = tempUser;
						break;
					}
				}
				this->localGroup = L"";
		}
		OusnsGroup(unsigned int groupID, String^ groupName, String^ groupDescription, 
			String^ groupCategory, String^ groupAnnounancement, unsigned int groupOwner,
			Dictionary<unsigned int,unsigned int>^ groupAdminInput){
				this->groupID = groupID;
				this->groupName = groupName;
				this->groupDescription = groupDescription;
				this->groupCategory = groupCategory;
				this->groupAnnounancement = groupAnnounancement;
				//this->groupAdmin = gcnew array<unsigned int>(groupAdmin->Length);
				this->groupOwnerID = groupOwner;
				this->groupAdmin = gcnew Dictionary<unsigned int, unsigned int>();
				Dictionary<unsigned int, unsigned int>::KeyCollection^ keyColl = groupAdminInput->Keys;
				unsigned int adminOuID;
				for each(adminOuID in keyColl){
					this->groupAdmin->Add(adminOuID,0);
				}

				this->groupMemberArray = gcnew array<OusnsGroupUser^>(0);
				
				this->localGroup = L"";
		}
		
	protected: ~OusnsGroup(void){}

	public:
		void UpdateGroupInfo( String^ groupName, String^ groupDescription, 
			String^ groupCategory, String^ groupAnnounancement, unsigned int groupOwner){
				this->groupName = groupName;
				this->groupDescription = groupDescription;
				this->groupAnnounancement = groupAnnounancement;
				this->groupCategory = groupCategory;
				//this->groupAdmin = gcnew array<unsigned int>(groupAdmin->Length);
				this->groupOwnerID = groupOwner;
		}
	public:
		property unsigned int GroupID{
			unsigned int get(){
				return this->groupID;
			}
		}
		property String^ GroupName{
			String^ get(){
				return this->groupName;
			}
			void set(String^ value){
				this->groupName = value;
			}
		}

		property String^ GroupAnnounancement{
			String^ get(){
				return this->groupAnnounancement;
			}
			void set(String^ value){
				this->groupAnnounancement = value;
			}
		}
		property String^ GroupDescription{
			String^ get(){
				return this->groupDescription;
			}
			void set(String^ value){
				this->groupDescription = value;
			}
		}

		property String^ GroupCategory{
			String^ get(){
				return this->groupDescription;
			}
			void set(String^ value){
				this->groupDescription = value;
			}
		}
		property unsigned int GroupOwnerID{
			unsigned int get(){
				return this->groupOwnerID;
			}
			void set(unsigned int value){
				this->groupOwnerID = value;
			}
		}
		property OusnsGroupUser^ GroupOwner{
			OusnsGroupUser^ get(){
				return this->groupOwner;
			}
		}
	public: 
		OusnsGroupUser^ FindGroupUser(unsigned int userID){
			int i;
			for (i = 0; i < this->groupMemberArray->Length;i++){
				if(this->groupMemberArray[i]->UserID == userID){
					return this->groupMemberArray[i];
				}
			}
			return nullptr;
		}

		bool IsAdmin(unsigned int userID){
			return this->groupAdmin->ContainsKey(userID);
		}


	};

}
