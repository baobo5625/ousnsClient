#pragma once
#include "stdafx.h"

namespace OuSns{

	public ref class SharedObject
	{

		/* REF VERSION */
		System::String^ objectName;
		//The file tags are seperated by space
		System::String^ objectTags;
		System::String^ objectPath;
		System::String^ objectSize;
		System::String^ objectDescription;
		int filePrivilege;

		//Indicated if the current file is exist on this computer
		bool exist;
	};
}
