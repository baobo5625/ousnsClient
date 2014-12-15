#pragma once
#include "stdafx.h"
#include "DownloadingObject.h"

/*
 * This class represents a downloading folder
 */
public ref class DownloadingFolder: public DownloadingObject{
	/*
	 The following variables inherted from parent class:
	System::String^ objectName;
	System::String^ objectPath;
	int progress_ppm;
	bool completed;
	*/
	bool isDirectory = true;

	/*
	 * The list of object,they could be either file or folder
	 */
	LinkedList<DownloadingObject^>^ contentObject;
};