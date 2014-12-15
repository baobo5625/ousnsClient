#include "stdafx.h"
//#include "LoginDlg.h"
//#include "MessageProcessor.h"


#pragma managed

// A connection that listens a port for UDP packets.



//ref class OusnsLoginUser;
//class DownloaderCommunication;
class DownloaderCommunication;

namespace OuSns{
	ref class LoginDlg;
	ref class MessageProcessor;
	ref class MessageCreator;
	ref class MainDlg;
	ref class OusnsLoginUser;
	public ref class Communication
	{

	public: IPAddress^ serverAddr;
			array<Byte>^ serverAddrArray;
			unsigned short serverPort;
			array<Byte>^ serverPortArray;

			UdpClient^ listenClient;
			//UdpClient^ sendClient;

			Thread ^ workThread;
			Thread ^ listenThread;
			Thread^ sendThread;
			Thread ^ communicationThread;
			Thread ^ downloaderCommunicatonThread;

			bool isWorkThreadRunning;
			bool isListenThreadRunning;
			bool isSendThreadRunning;
			bool isCommunicationThreadRunning;
			bool isDownloaderCommunicationThreadRunning;
			/*
			* This is the flag that controled by the UI button.
			* When the user clicked the login button, this flag will be set to true.
			* When the user clicked the cancel button, this flag will be set to false;
			*/

			bool enableListen;

			bool userLoggedin;

			bool startedMainDlg;

			//OuSns::LoginDlg ^ _loginDlg;
			//OuSns::MainDlg ^ _mainDlg;
			LoginDlg ^ loginDlg;
			MainDlg^ mainDlg;

			OusnsLoginUser^ loginUser;

			IPAddress^ userPublicIP;
			array<Byte>^ userPublicIPArray;

			unsigned short userPublicPort;
			array<Byte>^ userPublicPortArray;

			OuSns::NatType userNatType;


			System::Collections::Generic::LinkedList<OusnsMessage ^> ^ workQueue;
			System::Collections::Generic::LinkedList<OusnsMessage ^> ^ sendQueue;
			System::Collections::Generic::LinkedList<OusnsPacket ^> ^ sendPacketQueue;
			System::Collections::Generic::Dictionary<String^,OusnsPartialMessage^> ^ partialMessageQueue;
			System::Collections::Generic::LinkedList<OusnsPacket^> ^ receivedPacketQueue;

			System::Collections::Generic::LinkedList<OusnsMessage ^> ^ downloaderCommandQueue;


			MessageProcessor^ msgProcessor;
			MessageCreator^ msgCreator;


			// Used for the listen thread to resend login packet.


			static System::Object ^ workQueueLock = gcnew System::Object();
			static System::Object ^ sendQueueLock = gcnew System::Object();
			static System::Object ^ sendPacketQueueLock = gcnew System::Object();
			//static System::Object ^ PartialMessageQueueLock = gcnew System::Object();
			static System::Object ^ receivedPacketQueueLock = gcnew System::Object();
			static System::Object ^ splitPacketLock = gcnew System::Object();
			static System::Object ^ downloaderCommandQueueLock = gcnew System::Object();

			bool sendHeartBeatFlag;
			OusnsMessage^ heartBeatMessage;
			//DownloaderCommunication *dc;
			//__declspec(dllimport) DownloaderCommunication *dc;

	public:
		Communication(LoginDlg^ dialog);
		~Communication(void);


		/*
		* This function will turn some flags if the user is login/logoff
		*/

		System::Void Communication::UserLoginLogoff(bool loginFlag);

		/*
		* Call this function when successfully logged in to start send heart beat function
		*/
		System::Void Communication::InitializeHeartBeat(void);

		/*
		* This is the function that will send the heart beat to server, called by the listen thread
		*/
		System::Void Communication::SendHeartBeat(void);


		/*
		* This function will be called to sort the message to its correct processor
		*/
		System::Void Communication::ProcessMessage(OusnsMessage^ msg);

		/*
		* This function will enable or disable the listen function (not stopping the thread)
		*/
		System::Void Communication::EnableListenFunction(bool flag);



		/* --------------Work Thread Functions ---------------*/
		/* Defined at WorkThread.cpp*/

		/* Constantly process jobs in the work queue. */
		System::Void Communication::WorkThread(void);

		/*
		* This is the function that will add the message into workQueue
		*/
		System::Void Communication::AddToWorkQueue(OusnsMessage^ msg);

		/* --------------Communication (Receive packet and Send packet) Thread Functions ---------------*/
		/* Defined at CommunicationThread.cpp*/

		/* This is the communication thread with both listen and send function */
		System::Void Communication::CommunicationThread(void);


		/*
		* This is the function that will add the packet into sendPacketQueue
		*/
		System::Void Communication::AddToSendPacketQueue(OusnsPacket^ packet);

		/*
		* This is the function that will add an array of packet into sendPacketQueue
		*/
		System::Void Communication::AddToSendPacketQueue(array<OusnsPacket^>^ packetArray);


		/*
		* This is the function that will remove the packet from the sendPacketQueue
		*/
		System::Void Communication::RemoveFromSendPacketQueue(String^ packetID);

		/*
		* This is the function that will remove all the packet with same messageID
		* from the sendPacketQueue 
		*/
		System::Void Communication::RemoveFromSendPacketQueueByMessageID(String^ messageID);

		/*
		* This function will add the just received packet into the received packet queue
		*/
		System::Void Communication::AddToReceivedPacketQueue(OusnsPacket^ packet);



		/* --------------Listen Thread Functions ---------------*/
		/* Defined at ListenThread.cpp*/

		/* 
		* This thread will monitor the PartialMessageQueue, when there is any fully filled message, push
		* this message into work queue
		*/
		System::Void Communication::ListenThread(void);

		/*
		* This function will be called by the sendPacketThread and add 
		*/
		System::Void Communication::AddToPartialMessageQueue(OusnsPacket^ packet);

		/*
		* This function will take an array of packet and make it to a message
		*/
		OusnsMessage^ Communication::MergePacketToMessage(OusnsPartialMessage^ partialMsg);


		/*
		* This function will check and remove the partial message if the partial message was
		* not receive any more packet
		*/
		System::Void Communication::CheckPartialMessage(void);

		/*
		* This function will parse the received message (it was in the message processor function)
		*/
		OusnsMessage^ Communication::ProcessListenMessage(OusnsMessage ^ msg);



		/* --------------Send Thread Functions ---------------*/
		/* Defined at SendThread.cpp*/

		/*
		* This is the function that start to monitor the send queue, if there is any message
		* call the AddToSendPacketQueue 
		*/
		System::Void Communication::SendThread(void);


		/*
		* This function will take a OusnsMessage and split it into an array of OusnsPacket
		*/
		array<OusnsPacket^>^ Communication::SplitOusnsMessageIntoOusnsPacket(OusnsMessage^ msg);

		/*
		* This is the function that will add the message into sendQueue
		*/
		System::Void Communication::AddToSendQueue(OusnsMessage^ msg);

		/*
		* This is the function that will remove such message with the messageID from sendQueue
		*/
		System::Void Communication::RemoveFromSendQueue(String^ messageID);

		/*
		* The send packet queue thread and listen packet queue thread
		* can modify the message status in the sendQueue  to timeout or to filled
		*/
		System::Void Communication::ModifySendQueueMessageStatus(String^ messageID, OuSns::MessageStatus messageStatus);





		/* ----------Client-Client Communication functions------------ */
		/* Defined at PeerCommunication.cpp*/

		/*
		* This is the function that will send file to the other client, it will called by the SendThread
		* using the threadpool
		*/
		System::Void Communication::SendFile(void);

		/* ----------Downloader Communication functions---------------*/
		/* Defined at DownloaderCommunicationThread.cpp*/
		/*
		* This is the function that start to communicate with the downloader thread
		*/
		System::Void Communication::DownloaderCommunicationThread(void);

		System::Void Communication::AddToDownloaderCommandQueue(OusnsMessage^ msg);

		System::Void Communication::ProcessDownloaderCommand(OusnsMessage^ msg, DownloaderCommunication *dc);

	};

}
