#include "stdafx.h"
#include "Communication.h"
//#include "LoginDlg.h"
#include "MessageProcessor.h"
#include "MainDlg1.h"
#include "DownloadFileTab.h"


System::Void Communication::WorkThread() {

	isWorkThreadRunning = true;
	isListenThreadRunning = true;
	isSendThreadRunning = true;
	isCommunicationThreadRunning = true;
	this->isDownloaderCommunicationThreadRunning = true;
	// Start the listening thread.
	ThreadStart ^ listenThreadStart = gcnew ThreadStart(this, &Communication::ListenThread);
	listenThread = gcnew Thread(listenThreadStart);
	listenThread->Name = L"ListenThread";
	listenThread->Priority = ThreadPriority::BelowNormal;
	listenThread->Start();
	ThreadStart^ sendThreadStart = gcnew ThreadStart(this,&Communication::SendThread);
	sendThread = gcnew Thread(sendThreadStart);
	sendThread->Name = L"SendThread";
	sendThread->Start();
	ThreadStart ^ communicationThreadStart = gcnew ThreadStart(this, &Communication::CommunicationThread);
	communicationThread = gcnew Thread(communicationThreadStart);
	communicationThread->Name = L"CommunicationThread";
	communicationThread->Start();
	ThreadStart ^ downloaderCommunicationThreadStart = gcnew ThreadStart(this, &Communication::DownloaderCommunicationThread);
	downloaderCommunicatonThread = gcnew Thread(downloaderCommunicationThreadStart);
	downloaderCommunicatonThread->Name = L"DownloaderCommunicationThread";
	downloaderCommunicatonThread->Start();

	int32_t ioTaskTimeEclipsed = 0;
	OusnsMessage^ currentMsg;
	DateTime currentTime;
	//DateTime^ afterJobTime;
	int timeUsedForJob = 0;
	while (isWorkThreadRunning) {
		Thread::Sleep(THREAD_SLEEP_TIME);
		currentTime = DateTime::Now;
		if (this->workQueue->Count > 0) {
			if (DEBUG_WORK_THREAD) {
				MessageBox::Show("=WORK=\nWork found in queue! Do work.");
			}
			//Get the first element of queue in monitor condition
			try {
				Threading::Monitor::Enter(workQueueLock);
				currentMsg = this->workQueue->Last->Value;
				this->workQueue->RemoveLast();
				Threading::Monitor::Exit(workQueueLock);
			} 
			catch (ThreadAbortException^ ){
				//Threading::Monitor::Exit(workQueueLock);
			}
			catch (Exception ^ e) {
				MessageBox::Show("Exception in lock:WorkThread: " + e->ToString());
				Threading::Monitor::Exit(workQueueLock);
			}
			//Start processing the message
			try{
				this->ProcessMessage(currentMsg);
			}
			catch (Exception ^ e) {
				if (DEBUG_WORK_THREAD) {
					MessageBox::Show("Exception in lock:WorkThread: " + e->ToString());
				}
			}		
		}

		
	
		//Start to do the cron job
		//Do the IO job first
		if(ioTaskTimeEclipsed >= IO_TASK_TIMEOUT &&  this->startedMainDlg){
			ioTaskTimeEclipsed = 0;
			if(this->mainDlg->downloadedJobArrayModified){
				this->mainDlg->newDownloadFileTab->SaveDownloadedList();
				this->mainDlg->downloadedJobArrayModified = false;
			}
			if(this->mainDlg->downloadingJobDictModified){
				this->mainDlg->newDownloadFileTab->SaveDownloadingList();
				this->mainDlg->downloadingJobDictModified =false;
			}
		}

		//Do the time Addings

		timeUsedForJob = (int)(DateTime::Now.Subtract(currentTime).TotalSeconds);
		ioTaskTimeEclipsed += timeUsedForJob + THREAD_SLEEP_TIME;

	}
}


/*
* This is the function that will add the message into workQueue
*/
System::Void Communication::AddToWorkQueue(OusnsMessage^ msg){
	try {
		Threading::Monitor::Enter(workQueueLock);
		this->workQueue->AddFirst(msg);
		Threading::Monitor::Exit(workQueueLock);
	} 

	catch (Exception ^ e) {
		MessageBox::Show("Exception in lock:workQueue: " + e->ToString());
		Threading::Monitor::Exit(workQueueLock);
	} 
}
