#include "stdafx.h"
#include "MessageCreator.h"



/*
* This function will return a focus message (4.1)
*/
OusnsMessage^ MessageCreator::MakeFocusUserMessage(unsigned int userIDInt, String^ sessionID,unsigned int userID, String^ userIDType, String^ extensions){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("FOCUSUSER");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node focusUserIDNode = root.append_child();
	focusUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID.ToString()));
	focusUserIDNode.set_name("focusUserID");
	focusUserIDNode.append_attribute("userIDType").set_value(ManagedStringToAnsi(userIDType));

	pugi::xml_node extensionNode = root.append_child();
	extensionNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(extensions));
	extensionNode.set_name("autoDownloadFileExtension");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::FOCUSUSER, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}

/*
* This function will make a get focus people list message (4.3)
*/
/*

OusnsMessage^ MessageCreator::MakeGetFocusPeopleList(unsigned int userIDInt, String^ sessionID){

	pugi::xml_document doc;
	String^ userID =  userIDInt.ToString();
	String^ messageID  = this->GetMessageID(userID,"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("GETFOCUSLIST");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));
	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID));
	userIDNode.set_name("OuID");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	OusnsMessage^ returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID, OuSns::GETFOCUSLIST, messageContent, ipAddress,destPort,true);

	return returnMsg;
}
*/
/*
 * This function will make a remove friend message (4.5)
 */
OusnsMessage^ MessageCreator::MakeRemoveFocusUserMessage(unsigned int userIDInt, String^ sessionID, unsigned int userID, String^ userIDType){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("REMOVEFRIEND");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node focusUserIDNode = root.append_child();
	focusUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID.ToString()));
	focusUserIDNode.set_name("focusUserID");
	focusUserIDNode.append_attribute("userIDType").set_value(ManagedStringToAnsi(userIDType));

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::REMOVEFOCUSUSER, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}
