#include "stdafx.h"
#include "MessageCreator.h"


/*
 *	Make an OusnsMessage that contains a Peer Message and put it onto the work queue.
 */
OusnsMessage ^ MessageCreator::MakePeerMessage(String ^ text, int srcID, String ^ sessionID, 
											   IPAddress ^ destIP, int destPort, OuSns::NatType natType) {
	
	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	
	DateTime ^ send_time = DateTime::Now;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("CHATMESSAGE");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(text));
	textNode.set_name("text");

	pugi::xml_node timeNode = root.append_child();
	timeNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(send_time->ToUniversalTime().ToString()));
	timeNode.set_name("time");
	
	
	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());
	
	
	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;
	
	
	
	if(natType == OuSns::StunTypeOpen ||
	   natType == OuSns::StunTypeIndependentFilter ||
	   natType == OuSns::StunTypeDependentFilter ||
	   natType == OuSns::StunTypePortDependedFilter){
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST, 0, 
			messageID, OuSns::CHATMESSAGE, temp, destIP, destPort,false, OuSns::P2P_NORMAL);
	} else {
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST, 0, 
			messageID, OuSns::CHATMESSAGE, temp, destIP, destPort,false, OuSns::P2P_SERVER_FORWARD);
	}
	/*
	ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND,OuSns::REQUEST, 0, 
		messageID, OuSns::CHATMESSAGE, temp, destIP, destPort,false, P2P_SERVER_FORWARD);
	*/	
	return ousnsMsg;
}


OusnsMessage ^ MessageCreator::MakeChangeStatusPeer(int status, int prevStatus, int srcID, String ^ sessionID, 
													IPAddress ^ srcIP, int srcPort, OuSns::NatType natType, 
													IPAddress ^ destIP, int destPort) {

	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	
	DateTime ^ send_time = DateTime::Now;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("CHANGESTATUSPEER");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(status)));
	textNode.set_name("userStatus");
	
	if (prevStatus == OFFLINE) {

		pugi::xml_node ipNode = root.append_child();
		ipNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(srcIP->ToString()));
		ipNode.set_name("ip");
		pugi::xml_node portNode = root.append_child();
		portNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcPort)));
		portNode.set_name("port");
		pugi::xml_node natTypeNode = root.append_child();
		natTypeNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString((int) natType)));
		natTypeNode.set_name("natType");
	}

	
	
	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());
	
	
	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;
	if(natType == OuSns::StunTypeOpen ||
	   natType == OuSns::StunTypeIndependentFilter ||
	   natType == OuSns::StunTypeDependentFilter ||
	   natType == OuSns::StunTypePortDependedFilter){
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 0, messageID, OuSns::CHANGESTATUSPEER, temp, destIP, destPort,false, P2P_NORMAL);
	} else {
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 0, messageID, OuSns::CHANGESTATUSPEER, temp, destIP, destPort,false, P2P_SERVER_FORWARD);
	}
	
	return ousnsMsg;
}


OusnsMessage ^ MessageCreator::MakeRequestFileTransfer(int srcID, String ^ sessionID, 
													   String ^ fileName, int fileSize, String ^ md5, 
													   IPAddress ^ destIP, int destPort, OuSns::NatType natType) {

	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("REQFILETRAN");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.set_name("file");
	textNode.append_attribute("fileName").set_value(ManagedStringToAnsi(fileName));
	textNode.append_attribute("fileSize").set_value(ManagedStringToAnsi(Convert::ToString(fileSize)));
	textNode.append_attribute("fileMD5CheckSum").set_value(ManagedStringToAnsi(md5));
	
	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());

	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;
	if(natType == OuSns::StunTypeOpen ||
	   natType == OuSns::StunTypeIndependentFilter ||
	   natType == OuSns::StunTypeDependentFilter ||
	   natType == OuSns::StunTypePortDependedFilter){
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::REQFILETRAN, temp, destIP, destPort, false, P2P_NORMAL);
	} else {
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::REQFILETRAN, temp, destIP, destPort, false, P2P_SERVER_FORWARD);
	}
	return ousnsMsg;
}

OusnsMessage ^ MessageCreator::MakeReplyFileTransfer(int srcID, String ^ sessionID, int decision, 
													  String ^ fileName, int fileSize, String ^ md5, 
													  IPAddress ^ destIP, int destPort, OuSns::NatType natType) {
	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("REPFILETRAN");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node decisionNode = root.append_child();
	decisionNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(decision)));
	decisionNode.set_name("decision");

	pugi::xml_node textNode = root.append_child();
	textNode.set_name("file");
	textNode.append_attribute("fileName").set_value(ManagedStringToAnsi(fileName));
	textNode.append_attribute("fileSize").set_value(ManagedStringToAnsi(Convert::ToString(fileSize)));
	textNode.append_attribute("fileMD5CheckSum").set_value(ManagedStringToAnsi(md5));
	
	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());

	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;
	if(natType == OuSns::StunTypeOpen ||
	   natType == OuSns::StunTypeIndependentFilter ||
	   natType == OuSns::StunTypeDependentFilter ||
	   natType == OuSns::StunTypePortDependedFilter){
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::REPFILETRAN, temp, destIP, destPort, false, P2P_NORMAL);
	} else {
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::REPFILETRAN, temp, destIP, destPort, false, P2P_SERVER_FORWARD);
	}
	return ousnsMsg;
}

OusnsMessage ^ MessageCreator::MakeCancelFileTransfer(int srcID, String ^ sessionID,
													  String ^ fileName, int fileSize, String ^ md5, 
													  IPAddress ^ destIP, int destPort,OuSns::NatType natType) {
	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("CANCELFILETRAN");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.set_name("file");
	textNode.append_attribute("fileName").set_value(ManagedStringToAnsi(fileName));
	textNode.append_attribute("fileSize").set_value(ManagedStringToAnsi(Convert::ToString(fileSize)));
	textNode.append_attribute("fileMD5CheckSum").set_value(ManagedStringToAnsi(md5));
	
	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());

	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;
	if(natType == OuSns::StunTypeOpen ||
	   natType == OuSns::StunTypeIndependentFilter ||
	   natType == OuSns::StunTypeDependentFilter ||
	   natType == OuSns::StunTypePortDependedFilter){
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::CANCELFILETRAN, temp, destIP, destPort, false, P2P_NORMAL);
	} else {
		ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::CANCELFILETRAN, temp, destIP, destPort, false, P2P_SERVER_FORWARD);
	}
	return ousnsMsg;
}

OusnsMessage ^ MessageCreator::MakeHolePunching(int srcID, String ^ sessionID,
												String ^ fileName, String ^ md5, 
												IPAddress ^ destIP, int destPort, OuSns::NatType natType) {
	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	;
	pugi::xml_node root = doc.append_child();
	root.set_name("REQUEST");
	root.append_attribute("actionType").set_value("HOLEPUNCHING");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.set_name("file");
	textNode.append_attribute("fileName").set_value(ManagedStringToAnsi(fileName));
	textNode.append_attribute("fileMD5CheckSum").set_value(ManagedStringToAnsi(md5));

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());

	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;

	ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::REQUEST, 
			0, messageID, OuSns::HOLEPUNCHING, temp, destIP, destPort, false, P2P_SERVER_FORWARD);

	return ousnsMsg;
}

OusnsMessage ^ MessageCreator::MakeHolePunchingResponse(int srcID, String ^ sessionID,
												String ^ fileName, String ^ md5, 
												IPAddress ^ destIP, int destPort, OuSns::NatType natType) {
	pugi::xml_document doc;
	
	String^ messageID = Convert::ToString(srcID) + "-" + Convert::ToString(nextMsgID);
	;
	pugi::xml_node root = doc.append_child();
	root.set_name("RESPONSE");
	root.append_attribute("actionType").set_value("HOLEPUNCHING");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));
	root.append_attribute("returnCode").set_value(ManagedStringToAnsi("0"));
	root.append_attribute("sessionID").set_value(ManagedStringToAnsi(sessionID));

	pugi::xml_node userIDNode = root.append_child();
	userIDNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(Convert::ToString(srcID)));
	userIDNode.set_name("OuID");

	pugi::xml_node textNode = root.append_child();
	textNode.set_name("file");
	textNode.append_attribute("fileName").set_value(ManagedStringToAnsi(fileName));
	textNode.append_attribute("fileMD5CheckSum").set_value(ManagedStringToAnsi(md5));

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ temp = gcnew String(writer.result.c_str());

	nextMsgID ++;
	OusnsMessage ^ ousnsMsg;

	ousnsMsg = gcnew OusnsMessage(OuSns::UI,OuSns::SEND, OuSns::RESPONSE, 
			0, messageID, OuSns::HOLEPUNCHING, temp, destIP, destPort, false, P2P_SERVER_FORWARD);

	return ousnsMsg;
}