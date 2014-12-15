
/*
 * This class defines a single shared file.
 */
#pragma once

#include "stdafx.h"
#include "SharedObject.h"


namespace OuSns{
	ref class OusnsFriend;
	ref class OusnsGroup;
	public ref class SharedFile :public OuSns::SharedObject
	{

	public:

		/* REF VERSION */

		System::String^ fileDescriptionLink;

		array<OusnsFriend^ > ^ allowedFriends;
		array<OusnsGroup^ > ^ allowedGroups;

	public:
		SharedFile(void){}
		~SharedFile(void){}

	};

}
