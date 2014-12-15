
/*
 * This class defines a single shared file.
 */
#pragma once

#include "stdafx.h"
#include "SharedObject.h"

namespace OuSns{
	ref class OusnsGroup;
	ref class OusnsFriend;
	public ref class SharedFolder :public SharedObject
	{

	public:
		/*
		* The following variable was inheritant from parent class:
		gcroot<System::String^> objectName;
		//The file tags are seperated by space
		gcroot<System::String^> objectTags;
		gcroot<System::String^> objectPath;
		gcroot<System::String^> objectSize;
		gcroot<System::String^> objectDescription;
		int filePrivilege
		*/

		/* REF VERSION */
		array<SharedObject ^> ^ folderContent;
		array<OusnsFriend ^> ^ allowedFriends;
		array<OusnsGroup^> ^ allowedGroups;


	public:
		SharedFolder(void){}
		~SharedFolder(void){}

	};

}
