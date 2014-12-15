//#include "stdafx.h"

/*
 * This is a list of all the action types of ousns messages. Each action type has its own process function.
 * SENDMESSAGE and RECEIVEMESSAGE are the two special action types:
 *
 * 1. SENDMESSAGE message asks the work thread to put the packet in the send thread without any other operation.
 *	  This action type is used for any UI-generated packet.
 * 2. RECEIVEMESSAGE message asks the work thread to parse the received packet from the listen thread, check the action
 *	  type of the received packet, and call ProcessMessage AGAIN on the parsed message.
 */

//using namespace OuSns;
namespace OuSns{

	public ref class OusnsMessage{

	public:
		/*
		*  The message Source, depends on which thread to created the message. 
		*  The UI thread create message with source 1,
		*  The work thread created message with source 2
		*  The listen thread created message with source 3
		*  The send thread created message with source 4 
		*/
		OuSns::ThreadType messageSourceThread;

		OuSns::ThreadType messageDestThread;
		/*
		* the message type, 1 means REQUEST, 2 means REPONSE, 3 means SYSMSG, 4 means Unknown
		*/
		OuSns::MessageType messageType;
		// The return Code of this message if the message is a reponse message
		// Otherwise it is 0
		int returnCode;
		// The message ID that generated at the client side
		String ^ messageID;

		/*
		* The action type of the message, defines in the file ActionType.h
		*/
		OuSns::ActionType actionType;

		int timeSlept;
		IPAddress ^ destIP;
		unsigned short destPort;
		/*
		* The message Content, should be XML
		*/
		System::String^ messageContent;

		OuSns::MessageStatus messageStatus;

		unsigned short messageTimeOutLimit;

		unsigned short messageTimeOutCounterLimit;


		OuSns::MessageFunctionCode msgCode;


		bool waitResponse;

		//Full construction of the Ousns Message
		OusnsMessage(OuSns::ThreadType messageSourceInput,OuSns::ThreadType messageDestInput,
			OuSns::MessageType messageTypeInput, int returnCodeInput, 
			String^ messageIDInput, OuSns::ActionType actionTypeInput, System::String^ messageContentInput, IPAddress ^ destIP,
			unsigned short destPort,bool waitResponseInput);

		//Construction of the Ousns Message with message function code 
		OusnsMessage(OuSns::ThreadType messageSourceInput,OuSns::ThreadType messageDestInput,
			OuSns::MessageType messageTypeInput, int returnCodeInput, 
			String^ messageIDInput, OuSns::ActionType actionTypeInput, System::String^ messageContentInput, IPAddress ^ destIP,
			unsigned short destPort,bool waitResponseInput,OuSns::MessageFunctionCode code);

		// The constructor will only be called by merge packet to message thread for every packet the listen thread receives.

		OusnsMessage(System::String^ messageContentInput,IPAddress ^ destIP,unsigned short destPort);

	protected: ~OusnsMessage(void){}
	public:
		property OuSns::MessageStatus MessageStatus{
			void set(OuSns::MessageStatus value){
				this->messageStatus = value;
			}
			OuSns::MessageStatus get(){
				return this->messageStatus;
			}
		}
	};

}

