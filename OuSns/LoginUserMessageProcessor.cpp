
#include "stdafx.h"
#include "MessageProcessor.h"
#include "Communication.h"
//#include "friendChatDlg.h"
#include "LoginDlg.h"
#include "MainDlg1.h"
#include "OusnsLoginUser.h"
#include "OusnsGroup.h"
#include "OusnsFocusUser.h"
#include "OusnsFriend.h"
#include "FriendListTab.h"
#include "MessageCreator.h"
#include "GroupListTab.h"
#include "FocusUserTab.h"


System::Void MessageProcessor::ProcessLoginResponsePacket(OusnsMessage ^ msg){
	//const char buffer = new char[receivedString->Length];
	if(msg->MessageStatus == OuSns::TIMEOUT){
		String^ returnMsg = L"登录超时,服务器无响应";
		OuSns::LoginDlg::NotifyUIError^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIError(dynamic_cast<OuSns::LoginDlg ^>(this->loginDlg),
			&OuSns::LoginDlg::LoginErrorNotification);
		array<Object ^>^ args = {returnMsg};
		this->loginDlg->Invoke(delegateFunction, args);

	}
	else if(msg->MessageStatus == OuSns::RECEIVED){

		try{
			char * buffer = ManagedStringToAnsi(msg->messageContent);
			pugi::xml_document doc;
			pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
			
			//MessageBox::Show(receivedString);
			pugi::xml_node response = doc.child("RESPONSE");
			String^ messageID = AnsiToManagedString((char*)(response.attribute("messageID").value()));
			
			int returnCode = System::Convert::ToInt32(AnsiToManagedString((char*)(response.attribute("returnCode").value())));
			if(returnCode == 0){
				String^ actionType = AnsiToManagedString((char*)(response.attribute("actionType").value()));
				unsigned int ouID = System::Convert::ToUInt32(AnsiToManagedString((char*)response.child_value("OuID")));
				String^ emailID = AnsiToManagedString((char*)response.child_value("emailID"));
				String^ email = AnsiToManagedString((char*)response.child_value("email"));
				String^ nickname = AnsiToManagedString((char*)response.child_value("nickname"));
				String^ profile = AnsiToManagedString((char*)response.child_value("profile"));
				
				String^ signature = AnsiToManagedString((char*)response.child_value("signature"));
				unsigned int focusCounter =  System::Convert::ToUInt32(AnsiToManagedString((char*)response.child_value("focusCounter")));
				//String^ nickname = AnsiToManagedString((char*)response.child_value("signature"));
				unsigned short birthYear=  System::Convert::ToUInt16(AnsiToManagedString((char*)response.child_value("birthYear")));
				unsigned short birthMonth=  System::Convert::ToUInt16(AnsiToManagedString((char*)response.child_value("birthMonth")));
				unsigned short birthDay =  System::Convert::ToUInt16(AnsiToManagedString((char*)response.child_value("birthDay")));
				int sex = 0;
					Int32::TryParse(AnsiToManagedString((char*)response.child_value("sex")),sex);
				String^ dpFilename = AnsiToManagedString((char*)response.child_value("displayPictureFilename"));
				int experience = System::Convert::ToInt32(AnsiToManagedString((char*)response.child_value("experience")));
				String^ personalStatement = AnsiToManagedString((char*)response.child_value("personalStatement"));
				String^ city = AnsiToManagedString((char*)response.child_value("city"));
				String^ province = AnsiToManagedString((char*)response.child_value("province"));
				String^ country = AnsiToManagedString((char*)response.child_value("country"));
				String^ ipaddrString = AnsiToManagedString((char*)response.child_value("ip"));
				String^ sessionID = AnsiToManagedString((char*)response.child_value("sessionID"));
				IPAddress^ ipaddr = IPAddress::Parse(AnsiToManagedString((char*)response.child_value("ip")));
				unsigned short recvPort = System::Convert::ToUInt16(AnsiToManagedString((char*)response.child_value("port")));
				int zodiac = 0;
				OuSns::UserStatus status = OuSns::ONLINE;
				OusnsLoginUser^ usr = gcnew OusnsLoginUser(ouID,emailID,email,nickname,signature, dpFilename,experience,focusCounter,\
					personalStatement, city, province,country,ipaddr, recvPort, this->loginDlg->userNatType, sex,zodiac,birthYear,\
					birthMonth, birthDay,status, profile,sessionID);
				//OuSns::LoginDlg::NotifyUIContinue^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIContinue(dynamic_cast<OuSns::LoginDlg ^>(this->loginDlg),
				//	&OuSns::LoginDlg::ContinueLogin);
				OuSns::LoginDlg::NotifyUIContinue^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIContinue(this->loginDlg,&OuSns::LoginDlg::ContinueLogin);
				array<Object ^>^ args = {usr};
				//MessageBox::Show(L"Ready to start MainDlg");
				//dynamic_cast<OuSns::LoginDlg ^>(this->comm->refDlg)->Invoke(delegateFunction, args);
				this->loginDlg->Invoke(delegateFunction, args);
				
			}
			else{
				String^ returnMsg;
				switch (returnCode){
					case 1:
						returnMsg = L"用户名密码错误";
						break;
					default:
						returnMsg = L"登录失败";
				}
				OuSns::LoginDlg::NotifyUIError^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIError(dynamic_cast<OuSns::LoginDlg ^>(this->loginDlg),
							&OuSns::LoginDlg::LoginErrorNotification);
				array<Object ^>^ args = {returnMsg};
				this->loginDlg->Invoke(delegateFunction, args);
			}
			//this->comm->RemoveFromSendQueue(msg->messageID);
		}
		catch(Exception ^ e){
			MessageBox::Show("Exception in process login response" + e->ToString());
			/*
			 * To be finished
			*/
		}
	}
	return;
}



System::Void MessageProcessor::ProcessHeartBeat(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessHEARTBEAT:"); 
	}
	switch(msg->messageStatus){
		case OuSns::TIMEOUT:
			//Do the log off
			break;
		default:

			//Start to do the log off
			break;
	}
	return;

}



System::Void MessageProcessor::ProcessDownloadList(OusnsMessage ^ msg) {
	if (DEBUG_THREAD) {
		MessageBox::Show("=WORK=\nMessageProcessor::ProcessDownloadFriend: Display the friend list on the main dialogue."); 
	}

	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);

		//MessageBox::Show(receivedString);
		pugi::xml_node response = doc.child("RESPONSE");
		String^ messageID = AnsiToManagedString((char*)(response.attribute("messageID").value()));

		int returnCode = System::Convert::ToInt32(AnsiToManagedString((char*)(response.attribute("returnCode").value())));
		if(returnCode == 0){

			//Start to process the friend part
			LinkedList<OusnsFriend^>^ tempFriendList = gcnew LinkedList<OusnsFriend^>();
			pugi::xml_node friendListInfo = response.first_child();
			pugi::xml_node friendinfo = friendListInfo.first_child();
			while (true && friendinfo) {
				unsigned int ouID = System::Convert::ToUInt32(AnsiToManagedString((char*)friendinfo.child_value("OuID")));
				String^ email = AnsiToManagedString((char*)friendinfo.child_value("email"));
				String^ nickname = AnsiToManagedString((char*)friendinfo.child_value("nickname"));

				String^ signature = AnsiToManagedString((char*)friendinfo.child_value("signature"));
				String^ localGroup = AnsiToManagedString((char*)friendinfo.child_value("localGroup"));

				IPAddress^ friendIP = IPAddress::Parse(AnsiToManagedString((char*)friendinfo.child_value("friendIP")));
				String^ friendIPString = AnsiToManagedString((char*)friendinfo.child_value("friendIP"));
				unsigned short friendPort = System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendPort")));
				String^ friendProfile = AnsiToManagedString((char*)friendinfo.child_value("friendProfile"));
				String^ friendDPFilename = AnsiToManagedString((char*)friendinfo.child_value("friendDPFileName"));
				String^ sessionID = L"";

				int natType = System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendNatType")));
				OuSns::UserStatus status = (OuSns::UserStatus)System::Convert::ToUInt16(AnsiToManagedString((char*)friendinfo.child_value("friendStatus")));
				OusnsFriend^ f = gcnew OusnsFriend(ouID,email,nickname,
					signature, friendDPFilename,friendIP,friendPort, (OuSns::NatType)natType,friendProfile,status,sessionID);
				//this->loginUser->friendList->AddLast(f);
				tempFriendList->AddLast(f);
				if (!friendinfo.next_sibling())
					break;
				friendinfo = friendinfo.next_sibling();
			}
			
			this->loginUser->UpdateFriendArray(tempFriendList);

			OuSns::FriendListTab::ActionDelegate^ delegateFunction = gcnew OuSns::FriendListTab::ActionDelegate(this->mainDlg->newFriendListTab, &OuSns::FriendListTab::UpdateFriendListToUI);
			array<Object ^>^ args = {};
			this->mainDlg->Invoke(delegateFunction, args);

			//Send the change status messages
			IPAddress ^ srcIP = this->loginUser->ipAddr;
			int srcPort = this->loginUser->recvPort;
			OusnsFriend ^ f;
			
			for(int i = 0; i <this->loginUser->friendListArray->Length; i++){
				f = this->loginUser->friendListArray[i];
				if (f->status != OuSns::OFFLINE) {
					//IPAddress ^ destIP = f->ipAddr;
					int destPort = f->recvPort;
					int srcID = this->loginUser->userID;
					//this->comm->SendChangeStatusPeer(status, srcID, destIP, destPort);
					String ^ sessionID = this->loginUser->sessionID;
					OusnsMessage ^ message = this->comm->msgCreator->MakeChangeStatusPeer(this->loginUser->status, 
						OuSns::OFFLINE, this->loginUser->UserID, this->loginUser->SessionID, 
						this->loginUser->IpAddr, this->loginUser->RecvPort, this->loginUser->NatType, f->IpAddr,f->RecvPort);

					this->comm->AddToWorkQueue(message);
				}
			}

			//Start to process Group info
			pugi::xml_node groupListInfo = friendListInfo.next_sibling();
			pugi::xml_node groupInfo = groupListInfo.first_child();
			LinkedList<OusnsGroup^>^ tempGroupList = gcnew LinkedList<OusnsGroup^>();
			while (true && groupInfo) {
				unsigned int groupID = System::Convert::ToUInt32(AnsiToManagedString((char*)groupInfo.child_value("groupID")));
				String^ groupName = AnsiToManagedString((char*)groupInfo.child_value("groupName"));
				unsigned int groupOwnerID = System::Convert::ToUInt32(AnsiToManagedString((char*)groupInfo.child_value("groupOwnerID")));

				Dictionary<unsigned int, unsigned int>^ adminDict = gcnew Dictionary<unsigned int,unsigned int>();
				pugi::xml_node adminListInfo = groupInfo.last_child();
				pugi::xml_node adminInfo = adminListInfo.first_child();
				unsigned int adminID;
				int admin_counter = 1;
				while(true && adminInfo){
					adminID = System::Convert::ToUInt32(AnsiToManagedString((char*)adminInfo.value()));
					adminDict->Add(adminID,0);
					admin_counter++;
					if(!adminInfo.next_sibling())
						break;
					adminInfo = adminInfo.next_sibling();
				}
				

				OusnsGroup^ g = gcnew OusnsGroup(groupID,groupName,"groupDescription","groupCategory","groupAnoucnance",
					groupOwnerID,adminDict);
				//this->loginUser->friendList->AddLast(f);
				tempGroupList->AddLast(g);
				if (!groupInfo.next_sibling())
					break;
				groupInfo = groupInfo.next_sibling();
			}
			this->loginUser->UpdateGroupArray(tempGroupList);	

			OuSns::GroupListTab::ActionDelegate^ delegateFunctionGroup = gcnew OuSns::GroupListTab::ActionDelegate(this->mainDlg->newGroupListTab, &OuSns::GroupListTab::UpdateGroupListToUI);
			this->mainDlg->Invoke(delegateFunctionGroup, args);

			//Start to process Focus info
			pugi::xml_node focusListInfo = groupListInfo.next_sibling();
			pugi::xml_node focusInfo = focusListInfo.first_child();
			LinkedList<OusnsGroup^>^ tempFocusGroupList = gcnew LinkedList<OusnsGroup^>();
			LinkedList<OusnsFocusUser^>^ tempFocusUserList = gcnew LinkedList<OusnsFocusUser^>();
			while (true && focusInfo) {
				pugi::xml_node focusIDNode = focusInfo.child("userID");
				pugi::xml_attribute userIDTypeAttribute = focusIDNode.attribute("userIDType");
				String^ userIDTypeString =  AnsiToManagedString((char*)userIDTypeAttribute.value());
				int userIDTypeInt = 1;
				Int32::TryParse(userIDTypeString,userIDTypeInt);
				UserIDType userIDType = (UserIDType)userIDTypeInt;
				unsigned int userID = System::Convert::ToUInt32(focusIDNode.value());
				String^ focusName = AnsiToManagedString((char*)focusInfo.child_value("nickname"));
				String^ focusDisplayPicFileName = AnsiToManagedString((char*)focusInfo.child_value("displayPicFileName"));
				String^ autoDownloadExtentionString = AnsiToManagedString((char*)focusInfo.child_value("autoDownloadFileExtention"));

				
				if(userIDTypeInt == OUSNS_USER){
					OusnsFocusUser^ f = gcnew OusnsFocusUser(userID,focusName,focusDisplayPicFileName,autoDownloadExtentionString);
					tempFocusUserList->AddLast(f);
				}
				else{
					OusnsGroup^ g = gcnew OusnsGroup(userID,focusName,"groupDescription","groupCategory","groupAnoucnance",0,nullptr);
					tempGroupList->AddLast(g);
				}
				
				if (!groupInfo.next_sibling())
					break;
				groupInfo = groupInfo.next_sibling();
			}
			OuSns::FocusUserTab::ActionDelegate^ delegateFunctionFocusUser = gcnew OuSns::FocusUserTab::ActionDelegate(this->mainDlg->newFocusUserTab, &OuSns::FocusUserTab::UpdateFocusUserListToUI);
			OuSns::FocusUserTab::ActionDelegate^ delegateFunctionFocusGroup = gcnew OuSns::FocusUserTab::ActionDelegate(this->mainDlg->newFocusUserTab, &OuSns::FocusUserTab::UpdateFocusUserListToUI);
			if(tempFocusGroupList->Count){
				this->loginUser->UpdateFocusGroupArray(tempFocusGroupList);
				this->mainDlg->Invoke(delegateFunctionFocusGroup, args);
			}
			if(tempFocusUserList->Count)
				this->loginUser->UpdateFocusUserArray(tempFocusUserList);
			this->mainDlg->Invoke(delegateFunctionFocusUser, args);

		}
		else{
			String^ returnMsg;
			switch (returnCode){
				case 1:
					returnMsg = L"下载好友列表失败";
					break;
				default:
					returnMsg = L"下载好友列表失败";
			}
			OuSns::LoginDlg::NotifyUIError^ delegateFunction = gcnew OuSns::LoginDlg::NotifyUIError(this->loginDlg,&OuSns::LoginDlg::LoginErrorNotification);
			array<Object ^>^ args = {returnMsg};
			this->loginDlg->Invoke(delegateFunction, args);
		}

		//Ousns
		//returnMessage->returnCode=returnCode;
		//returnMessage = gcnew OusnsMessage();
		//returnMessage->returnCode = returnCode;

	}
	catch(Exception ^){
		//Process the expcetion part
	}
	return;

}