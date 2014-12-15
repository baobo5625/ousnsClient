#include "StdAfx.h"

/*
 * This class defines a return message basic structure
 */

public ref class ResponseMessage{

public:
	// The return Code of this message
	int returnCode;


	// The message ID that ge
	String ^ messageID;
	System::Object^ messageContent;
	//xml_node messageNode;

};