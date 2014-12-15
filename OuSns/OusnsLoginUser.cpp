#include "stdafx.h"
#include "OusnsGroup.h"
#include "OusnsFriend.h"
#include "OusnsLoginUser.h"
#include "OusnsFocusUser.h"
/*
* This function will update the friend list array
*/
System::Void OusnsLoginUser::UpdateFriendArray(array<OusnsFriend^>^ ousnsFriendInput){
	this->friendListArray = gcnew array<OusnsFriend^>(ousnsFriendInput->Length);
	ousnsFriendInput->CopyTo(this->friendListArray,0);
}

System::Void OusnsLoginUser::UpdateFriendArray(LinkedList<OusnsFriend^>^ ousnsFriendInput){
	array<OusnsFriend^>^ tempFriendArray =gcnew array<OusnsFriend^>(ousnsFriendInput->Count);
	OusnsFriend^ tempFriend;
	int i = 0;
	for each(tempFriend in ousnsFriendInput){
		tempFriendArray[i] = tempFriend;
		i++;
	}
	this->UpdateFriendArray(tempFriendArray);
}
/*
* This function will update the group list array
*/
System::Void OusnsLoginUser::UpdateGroupArray(array<OusnsGroup^>^ ousnsGroupInput){
	this->groupListArray = gcnew array<OusnsGroup^>(ousnsGroupInput->Length);
	ousnsGroupInput->CopyTo(this->groupListArray,0);
}

System::Void OusnsLoginUser::UpdateGroupArray(LinkedList<OusnsGroup^>^ ousnsGroupInput){
	array<OusnsGroup^>^ tempGroupArray =gcnew array<OusnsGroup^>(ousnsGroupInput->Count);
	OusnsGroup^ tempGroup;
	int i = 0;
	for each(tempGroup in ousnsGroupInput){
		tempGroupArray[i] = tempGroup;
		i++;
	}
	this->UpdateGroupArray(tempGroupArray);
}



/*
* This function will update the focus user list array
*/
System::Void OusnsLoginUser::UpdateFocusUserArray(array<OusnsFocusUser^>^ ousnsFocusInput){
	this->focusUserListArray =  gcnew array<OusnsFocusUser^>(ousnsFocusInput->Length);
	ousnsFocusInput->CopyTo(this->focusUserListArray,0);
}
System::Void OusnsLoginUser::UpdateFocusUserArray(LinkedList<OusnsFocusUser^>^ ousnsFocusInput){
	array<OusnsFocusUser^>^ tempFocusArray =gcnew array<OusnsFocusUser^>(ousnsFocusInput->Count);
	OusnsFocusUser^ tempFocus;
	int i = 0;
	for each(tempFocus in ousnsFocusInput){
		tempFocusArray[i] = tempFocus;
		i++;
	}
	this->UpdateFocusUserArray(tempFocusArray);
}


/*
* This function will update the focus group list array
*/
System::Void OusnsLoginUser::UpdateFocusGroupArray(array<OusnsGroup^>^ ousnsFocusInput){
	this->focusGroupListArray =  gcnew array<OusnsGroup^>(ousnsFocusInput->Length);
	ousnsFocusInput->CopyTo(this->focusGroupListArray,0);
}

System::Void OusnsLoginUser::UpdateFocusGroupArray(LinkedList<OusnsGroup^>^ ousnsFocusInput){
	array<OusnsGroup^>^ tempFocusArray =gcnew array<OusnsGroup^>(ousnsFocusInput->Count);
	OusnsGroup^ tempGroup;
	int i = 0;
	for each(tempGroup in ousnsFocusInput){
		tempFocusArray[i] = tempGroup;
		i++;
	}
	this->UpdateFocusGroupArray(tempFocusArray);
}


/*
* This function will add the ousns friend into friend list 
* if the friend was not in the list
*/
System::Void OusnsLoginUser::AddFriend(OusnsFriend^ friendInput){
	if(!this->ExistFriend(friendInput->UserID)){
		array<OusnsFriend^>^ tempArray = gcnew array<OusnsFriend^>(this->friendListArray->Length +1);
		Array::Copy(this->friendListArray,tempArray,this->friendListArray->Length);
		tempArray[tempArray->Length - 1] = friendInput;
		this->friendListArray = tempArray;
	}
}

/*
* This function will add the ousns group into group list 
* if the group was not in the list
*/
System::Void OusnsLoginUser::AddGroup(OusnsGroup^ groupInput){
	if(!this->ExistGroup(groupInput->GroupID)){
		array<OusnsGroup^>^ tempArray = gcnew array<OusnsGroup^>(this->groupListArray->Length +1);
		Array::Copy(this->groupListArray,tempArray,this->groupListArray->Length);
		tempArray[tempArray->Length - 1] = groupInput;
		this->groupListArray = tempArray;
	}
}

/*
* This function will add the focus user into focus list 
* if the user was not in the list
*/
System::Void OusnsLoginUser::AddFocus(OusnsFocusUser^ focusInput){
	if(!this->ExistFocusUser(focusInput->UserID)){
		array<OusnsFocusUser^>^ tempArray = gcnew array<OusnsFocusUser^>(this->focusUserListArray->Length +1);
		Array::Copy(this->focusUserListArray,tempArray,this->focusUserListArray->Length);
		tempArray[tempArray->Length - 1] = focusInput;
		this->focusUserListArray = tempArray;
	}
}
System::Void OusnsLoginUser::AddFocus(OusnsGroup^ focusInput){
	if(!this->ExistFocusGroup(focusInput->GroupID)){
		array<OusnsGroup^>^ tempArray = gcnew array<OusnsGroup^>(this->focusUserListArray->Length +1);
		Array::Copy(this->focusUserListArray,tempArray,this->focusUserListArray->Length);
		tempArray[tempArray->Length - 1] = focusInput;
		this->focusGroupListArray = tempArray;
	}
}
/*
* This function will remove the ousns friend into friend list 
* if the friend was in the list
*/
System::Void OusnsLoginUser::RemoveFriend(unsigned int friendIDInput){

}

/*
* This function will remove the ousns group into group list 
* if the group was in the list
*/
System::Void OusnsLoginUser::RemoveGroup(unsigned int groupIDInput){

}


/*
* This function will remove the focus user into focus list 
* if the user was in the list
*/
System::Void OusnsLoginUser::RemoveFocus(unsigned int focusIDInput){

}

/*
* This function will check if such friend is exist in the friend list
*/
bool OusnsLoginUser::ExistFriend(unsigned int friendID){
	bool returnValue = false;
	OusnsFriend^ tempFriend;
	for each(tempFriend in this->friendListArray){
		if (tempFriend->UserID == friendID){
			returnValue = true;
		}
	}
	return returnValue;
}


/*
* This function will check if such group is exist in the group list
*/
bool OusnsLoginUser::ExistGroup(unsigned int groupID){
	bool returnValue = false;
	OusnsGroup^ tempGroup;
	for each(tempGroup in this->groupListArray){
		if (tempGroup->GroupID == groupID){
			returnValue = true;
		}
	}
	return returnValue;
}

/*
* This function will check if such focus user is exist in the focus list
*/
bool OusnsLoginUser::ExistFocusUser(unsigned int focusUserID){
	bool returnValue = false;
	OusnsFocusUser^ tempUser;
	for each(tempUser in this->focusUserListArray){
		if (tempUser->UserID == focusUserID){
			returnValue = true;
		}
	}
	return returnValue;
}

/*
* This function will check if such focus user is exist in the focus list
*/
bool OusnsLoginUser::ExistFocusGroup(unsigned int focusGroupID){
	bool returnValue = false;
	OusnsGroup^ tempGroup;
	for each(tempGroup in this->focusGroupListArray){
		if (tempGroup->GroupID == focusGroupID){
			returnValue = true;
		}
	}
	return returnValue;
}
/*
*
* This function will find the ousns friend with such ID
* If the friend does not exist, return null ptr
*/
OusnsFriend ^ OusnsLoginUser::FindFriend(unsigned int id) {
	int i;
	for(i = 0; i <this->friendListArray->Length; i++){
		if (this->friendListArray[i]->UserID == id) {
			return this->friendListArray[i];
		}
	}

	return nullptr;
}

/*
* This function will find the ousns group with such ID
* If the group does not exist, return null ptr
*/
OusnsGroup^ OusnsLoginUser::FindGroup(unsigned int id)
{
	int i;
	for( i = 0; i < this->groupListArray->Length; i++){
		if (this->groupListArray[i]->GroupID == id) {
			return this->groupListArray[i];
		}
	}
	return nullptr;
}

/*
* This function will be used when find the group member within the 
* specific group and with the userID
* If such user does not exist, return nullptr
*/
OusnsUser^ OusnsLoginUser::FindGroupMember(unsigned int groupID, unsigned int userID){

	OusnsGroup^ srcGroup = this->FindGroup(groupID);
	if(srcGroup != nullptr){
		int i;
		for (i = 0; i <  srcGroup->groupMemberArray->Length; i++){
			if(srcGroup->groupMemberArray[i]->UserID == userID){
				return srcGroup->groupMemberArray[i];
			}
		}
	}
	return nullptr;
}


/*
* This function will be used for find such focus user
* if such user does not exist, return nullptr
*/
OusnsFocusUser^ OusnsLoginUser::FindFocusUser(unsigned int userID){
	int i;
	for(i = 0; i <this->focusUserListArray->Length; i++){
		if (this->focusUserListArray[i]->UserID == userID) {
			return this->focusUserListArray[i];
		}
	}

	return nullptr;
}


/*
* This function will be used for find such focus group
* if such user does not exist, return nullptr
*/
OusnsGroup^ OusnsLoginUser::FindFocusGroup(unsigned int groupID){
	int i;
	for(i = 0; i <this->focusGroupListArray->Length; i++){
		if (this->focusGroupListArray[i]->GroupID == groupID) {
			return this->focusGroupListArray[i];
		}
	}

}