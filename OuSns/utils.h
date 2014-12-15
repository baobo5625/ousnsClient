#include "stdafx.h"


//Convert System::String to string
static char* ManagedStringToAnsi (System::String^ str)
{
	return static_cast< char*>(Marshal::StringToHGlobalAnsi(str).ToPointer());
}

static System::String^ AnsiToManagedString (char * str)
{
	return Marshal::PtrToStringAnsi(static_cast<IntPtr>(str));
}

