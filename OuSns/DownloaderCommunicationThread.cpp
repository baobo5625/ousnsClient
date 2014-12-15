#include "stdafx.h"

//#pragma comment(lib,"..\\lib\\OusnsDownloaderCommunicator.lib")
#include "..\\include\\DownloaderCommunication.h"
//__declspec(dllimport) DownloaderCommunication;
//[DllImport("OusnsDownloaderCommunicator.dll")]
#include "Communication.h"
#include "MessageCreator.h"
//#include "MessageProcessor.h"

/* ----------Downloader Communication functions---------------*/
/* Defined at DownloaderCommunicationThread.cpp*/
/*
* This is the function that start to communicate with the downloader thread
*/

//__declspec(dllimport) DownloaderCommunication *dc;

//DLL_IMPORT DownloaderCommunication *dc;
System::Void Communication::DownloaderCommunicationThread(void){
	//DownloaderCommunication *dc = new DownloaderCommunication();
	DownloaderCommunication *dc =	DownloaderCommunication::GetInstance();
	//dc = new DownloaderCommunication();
	//MessageBox::Show("pause this thread");
	//dc = new DownloaderCommunication();
	//__declspec(dllimport) DownloaderCommunication dc;
	dc->StartDownloader();
	//dc->StartDownloader();
	
	OusnsMessage^ msg;
	while(this->isDownloaderCommunicationThreadRunning){
		if(this->startedMainDlg){
			dc->OusnsDownloaderInfoExchange();
			//dc->AcquireLocalMemLock();
			msg = this->msgCreator->MakeJobEntry(dc);
			//dc->RleaseLocalMemLock();
			this->AddToWorkQueue(msg);

			//Start to check the command line and push the command into the Downloader
			if (this->downloaderCommandQueue->Count > 0) {
				try {
					Threading::Monitor::Enter(downloaderCommandQueueLock);
					msg = this->downloaderCommandQueue->Last->Value;
					this->downloaderCommandQueue->RemoveLast();
					Threading::Monitor::Exit(downloaderCommandQueueLock);
				} 
				catch (ThreadAbortException^ ){
					//Threading::Monitor::Exit(workQueueLock);
				}
				catch (Exception ^ e) {
					if (DEBUG_WORK_THREAD) 
						MessageBox::Show("Exception in lock:downloaderCommandThread: " + e->ToString());
					Threading::Monitor::Exit(downloaderCommandQueueLock);
				}
				//Start processing the message
				try{
					this->ProcessDownloaderCommand(msg,dc);
				}
				catch (Exception ^ e) {
					if (DEBUG_WORK_THREAD) 
						MessageBox::Show("Exception in lock:downloaderCommandThread: " + e->ToString());
					
				}		
			}
			Sleep(1000);

		}
	}
	
	
}

/*
* This is the function that will add the message into workQueue
*/
System::Void Communication::AddToDownloaderCommandQueue(OusnsMessage^ msg){
	try {
		Threading::Monitor::Enter(downloaderCommandQueueLock);
		this->downloaderCommandQueue->AddFirst(msg);
		Threading::Monitor::Exit(downloaderCommandQueueLock);
	} 

	catch (Exception ^ e) {
		if(DEBUG && DEBUG_DOWNLOADER_COMMUNICATION_THREAD)
			MessageBox::Show("Exception in lock:workQueue: " + e->ToString());
		Threading::Monitor::Exit(downloaderCommandQueueLock);
	} 
}


System::Void Communication::ProcessDownloaderCommand(OusnsMessage^ msg, DownloaderCommunication *dc){
	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);
		pugi::xml_node internalMsg = doc.child("INTERNALMSG");
		//pugi::xml_node commandCharNode = internalMsg.first_child();
		std::string command = std::string(internalMsg.child_value("commandChar"));
		char commandChar = atoi(internalMsg.child_value("commandChar"));

		std::string commandTarget = std::string(internalMsg.child_value("commandTarget"));
		std::string magnetURI = std::string(internalMsg.child_value("magnetURI"));
		pugi::xml_node commandParamListNode = internalMsg.child("commandParamList");
		pugi::xml_node commandParamNode = commandParamListNode.first_child();



		vector<std::string> params;
		std::string param;
		
		while(true){
			param = std::string(commandParamNode.value());
			params.push_back(param);
			if(!commandParamNode.next_sibling())
				break;
			commandParamNode = commandParamNode.next_sibling();
		}
		

		//__declspec(dllimport) DownloaderCommunication *dc;
		//dc->SetCommand(commandChar,params,commandTarget,magnetURI);
		//dc->SetCommand(dc,commandChar,params,commandTarget,magnetURI);
		int counter = 0;

		//CommandEntry this->localMem->commandEntry[this->localMem->currentCommand];

		new(&dc->localMem->commandEntry[dc->localMem->currentCommand]) CommandEntry;

		dc->localMem->commandEntry[dc->localMem->currentCommand].commandChar = commandChar;
		if(magnetURI.length() <= MAX_MAGNET_URI)
			strncpy(dc->localMem->commandEntry[dc->localMem->currentCommand].commandMagnetURI,magnetURI.data(),magnetURI.length());
		if(commandTarget.length() <= MAX_PATH)
			strncpy(dc->localMem->commandEntry[dc->localMem->currentCommand].commandTarget,commandTarget.data(),commandTarget.length());

		for each(param in params){
			if(counter < dc->localMem->commandEntry[dc->localMem->currentCommand].CommandParametersLimit &&
				param.length() <= MAX_PATH && param.length() > 0){
					strncpy(dc->localMem->commandEntry[dc->localMem->currentCommand].commandParam[counter],param.data(),param.length());
					counter++;
			}
		}

		dc->localMem->commandEntry[dc->localMem->currentCommand].currentParam = counter;
		dc->localMem->currentCommand++;

	}
	catch (Exception^){

	}

}
