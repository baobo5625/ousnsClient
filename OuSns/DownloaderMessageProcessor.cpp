#include "stdafx.h"
//#include "Communication.h"
//#include "friendChatDlg.h"
//#include "LoginDlg.h"
#include "MainDlg1.h"
#include "MessageProcessor.h"
#include "DownloadingJob.h"
#include "DownloadFileTab.h"


System::Void MessageProcessor::ProcessUpdateJob(OusnsMessage^ msg){
	try{
		char * buffer = ManagedStringToAnsi(msg->messageContent);
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_buffer(buffer,msg->messageContent->Length);

		//MessageBox::Show(receivedString);
		pugi::xml_node internalMsg = doc.child("INTERNALMSG");
		String^ jobName,^jobPath;
		int jobError,jobSize,jobProgress,jobDone,jobDownloadRate,jobStatus,jobPaused,jobPeer,jobSeed,jobDistributedFullCopies, jobDistributedFriactions;
		DownloadingJob^ tempJob;
		LinkedList<DownloadingFile^>^tempFiles = gcnew LinkedList<DownloadingFile^>();
		DownloadingFile^ tempFile;
		pugi::xml_node jobFileList,fileNode;
		String^ filename, ^filePath;
		int fileSize,fileProgress;
		//OuSns::DownloadJobStatus tempStatus;
		pugi::xml_node jobNode = internalMsg.first_child();
		bool updateDownloadingList = false;
		bool updateDownloadedList = false;
		OuSns::MainDlg::ActionDelegate^ delegateFunction;
		OuSns::MainDlg::ParamActionDelegate^ paramDelegateFunction;
		array<Object ^>^ args;
		while(jobNode){
			jobName =  AnsiToManagedString((char*)jobNode.child_value("jobName"));
			jobError = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobError")));
			jobSize = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobSize")));
			jobPath = AnsiToManagedString((char*)jobNode.child_value("jobPath"));
			jobProgress = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobProgress")));
			jobDone = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobDone")));
			jobDownloadRate = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobDownloadRate")));
			jobStatus = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobStatus")));
			jobPaused = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobPaused")));
			jobPeer = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobPeer")));
			jobSeed = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobSeed")));
			jobDistributedFullCopies = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobDistributedFullCopies")));
			jobDistributedFriactions = System::Convert::ToInt32(AnsiToManagedString((char*)jobNode.child_value("jobDistributedFriactions")));
			jobFileList = jobNode.child("jobFileList");
			tempFiles->Clear();
			fileNode = jobFileList.first_child();
			int fileCounter = 0;
			while(true && fileNode){
				filename =  AnsiToManagedString((char*)fileNode.child_value("filename"));
				filePath =  AnsiToManagedString((char*)fileNode.child_value("filePath"));
				fileSize = System::Convert::ToInt32(AnsiToManagedString((char*)fileNode.child_value("fileSize")));
				fileProgress = System::Convert::ToInt32(AnsiToManagedString((char*)fileNode.child_value("fileProgress")));
				tempFile = gcnew DownloadingFile(filename,fileCounter,filePath,fileProgress,fileSize);
				tempFiles->AddLast(tempFile);
				if(!fileNode.next_sibling())
					break;
				fileNode = fileNode.next_sibling();
				fileCounter++;
			}
			// From now, the job must be appear in the dict first, then goes to the downloader
			// If the dict does not have it, then does not add it
			// The job will be added throught add new file (the ui/work thread)
			// Since it is unable to retrieve the job name for some job, the job will be added through
			// the downloader as well
			if(this->mainDlg->downloadingJobDict->ContainsKey(jobName)){
				tempJob = this->mainDlg->downloadingJobDict[jobName];
				tempJob->UpdateParams(jobError,jobProgress,jobDone,jobDownloadRate,jobStatus,jobPaused,jobPeer,jobSeed,jobDistributedFullCopies,jobDistributedFriactions,tempFiles);

				this->mainDlg->downloadingJobDict[jobName] = tempJob;
			}
			else{
				tempJob = gcnew DownloadingJob(jobName, jobPath,jobError,jobSize,jobProgress,jobDownloadRate,jobDone,jobStatus,jobPaused,jobPeer,jobSeed,jobDistributedFullCopies,jobDistributedFriactions,tempFiles);
				this->mainDlg->downloadingJobDict[jobName] = tempJob;
			}


			if((tempJob->JobOuSnsStatus == OuSns::JOB_FINISHED || \
				tempJob->JobOuSnsStatus == OuSns::JOB_UPLOADING) && this->mainDlg->downloadingJobDict->ContainsKey(jobName)){
					//This is the situation that downloading just finished
					//Remove it from the downloading list to the finished list

				this->mainDlg->downloadedJobArray->AddFirst(tempJob);
				int rowIndex = 0;
				DataGridViewRow^ row;
				for each (row in this->mainDlg->newDownloadFileTab->fileTransferDataGridViewX->Rows){
					if(tempJob->JobName->CompareTo(dynamic_cast<String^>(row->Cells[1]->Value)) == 0){
						break;
					}
					rowIndex++;
				}

				//Remove the entry from the data gridview
				paramDelegateFunction =  gcnew OuSns::MainDlg::ParamActionDelegate(this->mainDlg,&OuSns::MainDlg::ModifyDataGridViewRows);
				LinkedList<Object^>^ tempargs = gcnew LinkedList<Object^>();
				tempargs->AddLast(dynamic_cast<Object^>(this->mainDlg->newDownloadFileTab->fileTransferDataGridViewX));
				//This is not necessary for delete action
				tempargs->AddLast(safe_cast<Object^>(row));
				tempargs->AddLast(safe_cast<Object^>(rowIndex));
				tempargs->AddLast(safe_cast<Object^>((int)OuSns::ACTION_REMOVE));
				args = gcnew array<Object^>{dynamic_cast<Object^>(tempargs)};
				this->mainDlg->Invoke(paramDelegateFunction, args);
				//updateDownloadedList = true;
				//Add the job to the finished data grid view

				DataGridViewRow^ tempRow = gcnew DataGridViewRow();
				DataGridViewImageCell^ jobStatus = gcnew DataGridViewImageCell();
				jobStatus->ToolTipText = tempJob->JobOuSnsStatusString;
				jobStatus->Value = this->mainDlg->newDownloadFileTab->GetJobStatusBitmap(tempJob->JobOuSnsStatus);
				//jobStatus->Style = dataGridViewCellStyle1;
				DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobName = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
				jobName->ToolTipText = L"文件名称";
				jobName->Value = tempJob->JobName;
				//jobName->Style = dataGridViewCellStyle1;
				DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobSize = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
				jobSize->ToolTipText = L"文件大小";
				jobSize->Value = tempJob->JobSizeString;
				DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobFinishingTime = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
				jobFinishingTime->Value = tempJob->FinishedTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
				jobFinishingTime->ToolTipText = L"文件预计下载完成时间";
				tempRow->Cells->AddRange(gcnew array<DataGridViewCell^>{jobStatus,jobName,jobSize,jobFinishingTime});

				tempargs = gcnew LinkedList<Object^>();
				tempargs->AddLast(dynamic_cast<Object^>(this->mainDlg->newDownloadFileTab->finishedFileTransferDataGridViewX));
				//This is not necessary for delete action
				tempargs->AddLast(safe_cast<Object^>(tempRow));
				tempargs->AddLast(safe_cast<Object^>(0));
				tempargs->AddLast(safe_cast<Object^>((int)OuSns::ACTION_ADD));
				args = gcnew array<Object^>{dynamic_cast<Object^>(tempargs)};
				this->mainDlg->Invoke(paramDelegateFunction, args);
				//Start to update downloaded list
				
				


				//Remove the entry from dictionary
				this->mainDlg->downloadingJobDict->Remove(tempJob->JobName);
				this->mainDlg->downloadingJobDictModified = true;
				//Add the entry to the job array
				this->mainDlg->downloadedJobArray->AddFirst(tempJob);
				this->mainDlg->downloadedJobArrayModified = true;

			}
			else if (tempJob->JobOuSnsStatus != OuSns::JOB_FINISHED &&\
				tempJob->JobOuSnsStatus != OuSns::JOB_UPLOADING){
			//else{
				this->mainDlg->downloadingJobDict[jobName] = tempJob;
				this->mainDlg->downloadingJobDictModified = true;
				updateDownloadingList = true;
			}
			
			
			if(!jobNode.next_sibling())
				break;
			jobNode = jobNode.next_sibling();
		}
		if(updateDownloadingList){
			delegateFunction = gcnew OuSns::MainDlg::ActionDelegate(this->mainDlg->newDownloadFileTab, &OuSns::DownloadFileTab::UpdateUnfinishedJob);
			//LinkedList<Object^>^ tempLinkedList = gcnew LinkedList<Object^>();
			//tempLinkedList->Add(this->mainDlg->downloadingJobDict);
			args = gcnew array<Object^>{};
			this->mainDlg->Invoke(delegateFunction, args);
		}
		/*
		if(updateDownloadedList){
			delegateFunction = gcnew OuSns::MainDlg::ActionDelegate(this->mainDlg, &OuSns::MainDlg::UpdateFinishedJob);
			//LinkedList<Object^>^ tempLinkedList = gcnew LinkedList<Object^>();
			//tempLinkedList->Add(this->mainDlg->downloadingJobDict);
			args = gcnew array<Object^>{};
			this->mainDlg->Invoke(delegateFunction, args);
		}*/
	}
	catch(Exception^ e){
		MessageBox::Show(e->ToString());
	}

}

System::Void MessageProcessor::ProcessDownloaderCommand(OusnsMessage^ msg){
	
	/*
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
		//this->mainDlg->comm->dc->SetCommand(commandChar,params,commandTarget,magnetURI);


	}
	catch (Exception^){

	}*/

	
}