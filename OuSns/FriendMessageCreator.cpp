#include "stdafx.h"
#include "MessageCreator.h"


/*
* This function will return an add friend message (2.1)
*/
OusnsMessage^ MessageCreator::MakeAddFriendMessage(unsigned int userIDInt, String^ sessionID,unsigned int targetUserID, String^ reason){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("ADDFRIEND");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node friendUserIDNode = root.append_child();
	friendUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(targetUserID.ToString()));
	friendUserIDNode.set_name("friendUserID");

	pugi::xml_node addFriendReason = root.append_child();
	addFriendReason.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(reason));
	addFriendReason.set_name("addFriendReason");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::ADDFRIEND, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}

/*
 * The reply add friend request (2.3)
 */
OusnsMessage^ MessageCreator::MakeReplyAddFriendMessage(unsigned int userIDInt, String^ sessionID,unsigned int targetUserID, int decision, unsigned int sysMsgID){
	OusnsMessage^ returnMsg;

	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("REPLYADDFRIEND");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node friendUserIDNode = root.append_child();
	friendUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(targetUserID.ToString()));
	friendUserIDNode.set_name("friendUserID");

	pugi::xml_node resultNode = root.append_child();
	resultNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(decision.ToString()));
	resultNode.set_name("replyResult");

	pugi::xml_node msgNode = root.append_child();
	msgNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(sysMsgID.ToString()));
	msgNode.set_name("sysMsgID");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::REPLYADDFRIEND, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);
	return returnMsg;
}


/*
 * This function will make a remove friend message (2.5)
 */
OusnsMessage^ MessageCreator::MakeRemoveFriendMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetFriendID){
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

	pugi::xml_node friendUserIDNode = root.append_child();
	friendUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(targetFriendID.ToString()));
	friendUserIDNode.set_name("friendUserID");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::REMOVEFRIEND, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}



/*
 * This funtion will make a message that to get the friend list (2.7)
 */





/*
* This function will send a search friend message (2.9)
*/
OusnsMessage^ MessageCreator::MakeSearchFriendMessage(unsigned int userIDInt, String^ sessionID,int searchUserIDType, String^ keyword, int offset, int searchLimit){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("SEARCHFRIEND");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node searchUserIDTypeNode = root.append_child();
	searchUserIDTypeNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(searchUserIDType.ToString()));
	searchUserIDTypeNode.set_name("searchUserIDType");

	pugi::xml_node searchKeywordNode = root.append_child();
	searchKeywordNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(keyword));
	searchKeywordNode.set_name("searchKeyword");

	pugi::xml_node searchOffsetNode = root.append_child();
	searchOffsetNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(offset.ToString()));
	searchOffsetNode.set_name("searchOffset");

	pugi::xml_node searchLimitNode = root.append_child();
	searchLimitNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(searchLimit.ToString()));
	searchLimitNode.set_name("searchLimit");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::SEARCHFRIEND, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}



/*
 * This function will return an query user information message (2.11)
 * (incompleted)
 */
OusnsMessage^ MessageCreator::MakeQueryUserInfoMessage(unsigned int userIDInt, String^ sessionID, unsigned int targetUserID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}


/*
* This function will return the get offline message (2.13)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeGetOfflineMessage(unsigned int userIDInt, String^ sessionID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}

/*
* This function will return the send offline message (2.15)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeSendOfflineMessage(unsigned int userIDInt, String^ sessionID,unsigned int targetUserID, unsigned int groupID,String^ textMessage){
	OusnsMessage^ returnMsg;
	return returnMsg;
}

/*
* This fucntion will return the clear offline message (2.17)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeClearOfflineMessage(unsigned int userIDInt, String^ sessionID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}