#include "stdafx.h"
#include "MessageCreator.h"

/* 
* This function will return a Join group information message (3.1)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeJoinGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID, String^ reason){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("JOINGROUP");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node groupIDNode = root.append_child();
	groupIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupID.ToString()));
	groupIDNode.set_name("groupID");

	pugi::xml_node joinGroupReason = root.append_child();
	joinGroupReason.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(reason));
	joinGroupReason.set_name("joinGroupReason");

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::JOINGROUP, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}


/*
 * The reply join group request (3.3)
 */
OusnsMessage^ MessageCreator::MakeReplyJoinGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID, unsigned int targetUserID, int decision, unsigned int sysMsgID){
	OusnsMessage^ returnMsg;

	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("REPLYJOINGROUP");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node groupIDNode = root.append_child();
	groupIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupID.ToString()));
	groupIDNode.set_name("groupID");

	pugi::xml_node targetUserIDNode = root.append_child();
	targetUserIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(targetUserID.ToString()));
	targetUserIDNode.set_name("userID");

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
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::REPLYJOINGROUP, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);
	return returnMsg;
}


/* 
* This function will return a Query group information message (3.5)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeQueryGroupInformationMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}
/*
* This function will return an exit group message (3.7)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeExitGroupMessage(unsigned int userIDInt, String^ sessionID, unsigned int groupID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}


/*
* This function will return an download group list message (3.11)
* (removed)
*/
OusnsMessage^ MessageCreator::MakeDownloadGroupListMessage(unsigned int userIDInt, \
		String ^ sessionID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}


/*
* This function will return an search group message (3.13)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeSearchGroupMessage(unsigned int userIDInt, \
		String^ sessionID,	int searchUserIDType, String^ keyword, int offset, int searchLimit){
	OusnsMessage^ returnMsg;
	return returnMsg;
}

/*
* This function will return a update group member status mesage (3.15)
* (incompleted)
*/
OusnsMessage^ MessageCreator::MakeUpdateGroupMemberStatusMessage(unsigned int userIDInt, String^ sessionID,unsigned int groupID){
	OusnsMessage^ returnMsg;
	return returnMsg;
}


/*
* This function will make a create group message (3.17)
*/
OusnsMessage^ MessageCreator::MakeCreateGroupMessage(unsigned int userIDInt, String^ sessionID, String^ groupName,\
	String^ groupDescription, String^ groupCategory, String^ groupAnounancement, String^ groupTag, LinkedList<unsigned int>^ memberList){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;
	String^ messageID  = this->GetMessageID(userIDInt.ToString(),"OuID");
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("CREATEGROUP");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userIDInt.ToString()));
	userIDNode.set_name("OuID");

	pugi::xml_node groupNameNode = root.append_child();
	groupNameNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupName));
	groupNameNode.set_name("groupName");

	pugi::xml_node groupDescriptionNode = root.append_child();
	groupDescriptionNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupDescription));
	groupDescriptionNode.set_name("groupDescription");

	pugi::xml_node groupAnounancementNode = root.append_child();
	groupAnounancementNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupAnounancement));
	groupAnounancementNode.set_name("groupAnounancement");

	pugi::xml_node groupTagNode = root.append_child();
	groupTagNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupTag));
	groupTagNode.set_name("groupTag");

	pugi::xml_node groupCategoryNode = root.append_child();
	groupCategoryNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(groupCategory));
	groupCategoryNode.set_name("groupCategory");

	pugi::xml_node groupMemberListNode = root.append_child();
	groupMemberListNode.set_name("groupMemberList");

	int counter = 0;
	for each(unsigned int userID in memberList){
		counter++;
		pugi::xml_node memberOuIDNode = groupMemberListNode.append_child();
		memberOuIDNode.set_name(ManagedStringToAnsi(L"memberOuID"+ counter.ToString()));
		memberOuIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(userID.ToString()));
	}

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST,0,messageID,OuSns::CREATEGROUP, messageContent, this->serverAddr,this->serverPort,OuSns::NORMAL);

	return returnMsg;
}