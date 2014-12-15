#include "stdafx.h"
#include "NewDownloadingJob.h"
#include "Communication.h"
#include "MessageCreator.h"


System::Void NewDownloadingJob::NewDownloadingJobContinueButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	for each (String^ line in this->NewDownloadingJobInputTextBoxX->Lines){
		String^ title = line->Substring(0,5);
		title = title->ToUpper();
		if(title->CompareTo("OUSNS") == 0){
			//This is the ousns entry
		}
		if(title->CompareTo("MAGNE") == 0){
			//This is the magnet uri entry
			LinkedList<String^>^ params = gcnew LinkedList<String^>();
			/*params->AddLast("");
			params->AddLast("");
			params->AddLast("");
			params->AddLast("");
			*/
			OusnsMessage^ msg = this->mainDlg->msgCreator->MakeCommandEntry(OuSns::DOWNLOADER_ADD_JOB,"",line,params);
			this->mainDlg->comm->AddToWorkQueue(msg);
		}
	}
	this->Close();
}