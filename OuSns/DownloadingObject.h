#pragma once
#include "stdafx.h"

/*
 * This class is the parent class of DownloadingFolder and DownloadingFile.
 * It represents the files/folders in the DownloadJob
 */
public ref class DownloadingObject{
	System::String^ objectName;

	// The path that relative to the downloadjob
	System::String^ objectPath;

	/*
	 * progress_ppm is a value in the range [0, 1000000], that represents 
	 * the progress of the torrent's current task. It may be checking files or downloading.
	 */
	int progressPpm;
	bool completed;
	
	
};