#pragma once
#include "stdafx.h"
#include "DownloadingObject.h"



ref class DownloadJob :public SharedObject
{

	/*
	The following variables was inherited from parent class
	System::String^ objectName;
	//The file tags are seperated by space
	System::String^ objectTags;
	System::String^ objectPath;
    System::String^ objectSize;
	System::String^ objectDescription;
	int filePrivilege
	*/

	/*
	 * progress_ppm is a value in the range [0, 1000000], that represents 
	 * the progress of the torrent's current task. It may be checking files or downloading.
	 */
public:
	int progress_ppm;

	/*
	 * The download rate is Bytes per second
	 */
	int downloadRate;

	/*
	 * The download rate in string version with unit
	 */
	System::String^ downloadRateString;
	/*
	 * The file status including the following statues:
	 * queued_for_checking,
	 * checking_files,
	 * downloading_metadata,
	 * downloading,
	 * finished,
	 * seeding,
	 * allocating,
	 * checking_resume_data
	 */
	System::String^ fileStatus;
	
	// The downloading object, could be either file or folder
	DownloadingObject^ contentObject;
	DownloadJob(void){
		progress_ppm = 0;
		downloadRate = 0;
		downloadRateString = L"";
		fileStatus = L"";
	}
};