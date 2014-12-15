#include "stdafx.h"

/*
 * This is the system setting file, added necessary variable when needed
 */

public ref class SystemSetting
{

public: 
	unsigned int userID;
	//This is the history of the path that the user has been user recently
	//Limit size by 5
	LinkedList<System::String^>^ savingPathHistory;

	// This is the default saving path for the user
	String^ defaultSavingPath;


	SystemSetting(unsigned int userID, String^ settingFilePath){

		this->userID = userID;
		this->savingPathHistory = gcnew LinkedList<System::String^>();
		if(File::Exists(settingFilePath)){
			//defaultSavingPath =
		}
		else{
			defaultSavingPath = OUSNS_DOWNLOAD_PATH;
		}
	}

	array<Byte>^ GetBytes(){
		array<Byte>^ returnByte;
		array<Byte>^ userIDByte = gcnew array<Byte>(sizeof(unsigned int));
		return returnByte;
	}




};