#include "stdafx.h"
#include "MessageCreator.h"
	/*
	 * This function will generate the login packet (1.1)
	 */
OusnsMessage ^ MessageCreator::MakeLoginMessage(String ^ userID, String ^ password, String ^ userIDType,IPAddress^ ipAddress, unsigned short destPort, LinkedList<String^>^ macAddressLinkedList,int userStatus, OuSns::NatType natType){
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userID,userIDType);
	pugi::xml_node root = doc.append_child("REQUEST");
	root.append_attribute("actionType").set_value("LOGIN");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("communicationVersion").set_value(COMM_VERSION);
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID));
	userIDNode.set_name("userID");
	userIDNode.append_attribute("userIDType").set_value(ManagedStringToAnsi(userIDType));
	pugi::xml_node passwordNode = root.append_child();
	passwordNode.set_name("password");
	passwordNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(password));
	pugi::xml_node userStatusNode = root.append_child();
	userStatusNode.set_name("userStatus");
	userStatusNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userStatus.ToString()));
	//userStatusNode.append_child(pugi::node_pcdata).set_value(userStatus);

	pugi::xml_node natTypeNode = root.append_child("natType");
	natTypeNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(((int)natType).ToString()));

	pugi::xml_node macAddressList = root.append_child("macAddressList");
	pugi::xml_node macAddressListNode;
	int counter = 0;
	
	for each(String^ s in macAddressLinkedList){
		counter++;
		macAddressListNode = macAddressList.append_child();
		macAddressListNode.set_name(ManagedStringToAnsi(L"macAddress"+ counter.ToString()));
		macAddressListNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(s));
	}

	
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	OusnsMessage^ msg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID, OuSns::LOGIN, messageContent, ipAddress,destPort,true);
	return msg;
}

/*
 * This function will generate the logoff message (1.3)
 */

OusnsMessage^ MessageCreator::MakeLogoffMessage(unsigned int userIDInt, String^ sessionID){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("LOGOFF");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::LOGOFF, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}

/*
 * This function will make a message that to change the user status (1.4)
 */

OusnsMessage^ MessageCreator::MakeChangeStatusMessage(unsigned int userIDInt, String^ sessionID, OuSns::UserStatus status){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ userID = userIDInt.ToString();
	String^ statusString = ((int)status).ToString();
	String^ messageID  = this->GetMessageID(userID,"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("CHANGESTATUS");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID));
	userIDNode.set_name("OuID");
	pugi::xml_node statusNode = root.append_child();
	statusNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(statusString));
	statusNode.set_name("userStatus");

	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::CHANGESTATUS, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}

/*
* This function will return an update personal information message (1.6)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeUpdatePersonalInformationMessage(OusnsLoginUser^ usr){
	OusnsMessage^ returnMsg;
	return returnMsg;
}


/*
 * This function will make a message that to get the recent update events (1.8)
 * (incompleted)
 */
OusnsMessage^ MessageCreator::MakeGetRecentUpdateMessage(void){
	OusnsMessage^ returnMsg;
	return returnMsg;
}

/*
 * This function will return the heart beat message (1.10)
 */
OusnsMessage^ MessageCreator::MakeHeartBeatMessage(unsigned int userIDInt, String^ sessionID){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ userID = userIDInt.ToString();
	String^ messageID  = this->GetMessageID(userID,"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("HEARTBEAT");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID));
	userIDNode.set_name("OuID");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::HEARTBEATMSG, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}
/*
* This function will return the make download list message (1.12)
*/
OusnsMessage^ MessageCreator::MakeDownloadListMessage(unsigned int userIDInt, String ^ sessionID, IPAddress^ ipAddress, unsigned short destPort){

	pugi::xml_document doc;
	String^ userID =  userIDInt.ToString();
	String^ messageID  = this->GetMessageID(userID,"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("DOWNLOADLIST");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID));
	userIDNode.set_name("OuID");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	OusnsMessage^ returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID, OuSns::DOWNLOADLIST, messageContent, ipAddress,destPort,true);

	return returnMsg;
}