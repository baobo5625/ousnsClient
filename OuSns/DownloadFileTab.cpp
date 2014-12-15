#include "StdAfx.h"
#include "DownloadFileTab.h"
#include "MainDlg1.h"
#include "Communication.h"
//#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "NewDownloadingJob.h"
#include "DownloadingJob.h"
#include "OusnsLoginUser.h"

DownloadFileTab::DownloadFileTab(MainDlg^ mainDlgInput, MessageCreator^ msgCreatorInput)
{
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//
	this->mainDlg = mainDlgInput;
	this->msgCreator = msgCreatorInput;
	this->UpdateUnfinishedJob();
	this->UpdateFinishedJob();
	this->LoadDownloadList();
}



System::Void DownloadFileTab::fileTransferDataGridViewX_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {

}

/* 
* This function will auto enable or disable the buttons based on the selection in the 
* file transfer datagridview
*/
System::Void DownloadFileTab::FileTransferSetButtonsBasedOnSelection(void){
	bool startJob = false,stopJob = false,deleteJob = false,openJob = false,openJobFolder = false;
	if(this->fileTransferDataGridViewX->SelectedRows->Count){
		openJobFolder = true;
		deleteJob = true;
		DataGridViewRow^ row;
		for each (row in this->fileTransferDataGridViewX->SelectedRows){

		}

	}
}


/*
* This function will return the bitmap of the picture for the status
*/
Bitmap^ DownloadFileTab::GetJobStatusBitmap(OuSns::DownloadJobStatus status){
	Image^ jobStatusImage = (cli::safe_cast<System::Drawing::Image^  >(this->mainDlg->myres->GetObject(L"jobstatus_icon")));
	Bitmap^ icon = gcnew Bitmap(18,18);
	System::Drawing::Rectangle origRect;
	int unit = 19;
	switch (status){
		case OuSns::JOB_RUNNING:
			origRect = System::Drawing::Rectangle(unit,0,18,18);
			break;
		case OuSns::JOB_FINISHED:
			origRect = System::Drawing::Rectangle(0,0,18,18);
			break;
		case OuSns::JOB_STOPPED:
			origRect = System::Drawing::Rectangle(unit * 2,0,18,18);
			break;
		case OuSns::JOB_UPLOADING:
			origRect = System::Drawing::Rectangle(unit * 4,0,18,18);
			break;
		case OuSns::JOB_ERROR:
			origRect = System::Drawing::Rectangle(unit * 3,0,18,18);
			break;
		case OuSns::JOB_WAITING:
			origRect = System::Drawing::Rectangle(unit * 5,0,18,18);
			break;
	}
	//origRect = gcnew System::Drawing::Rectangle(drawingPoint,drawingSize);
	Graphics^ statusGraphics = Graphics::FromImage(icon);
	statusGraphics->DrawImage(jobStatusImage,0,0,origRect,GraphicsUnit::Pixel);
	return icon;
}

Bitmap^ DownloadFileTab::GetProgressBarBitmap(double progress,int width){
	Bitmap^ progressBarBitmap = gcnew Bitmap(width,18);
	DevComponents::DotNetBar::Controls::ProgressBarX^  progressBar = gcnew DevComponents::DotNetBar::Controls::ProgressBarX();
	progressBar->TextVisible = true;
	progressBar->Text = progress.ToString("F2") + "%";
	progressBar->Value= progress;
	progressBar->Size = System::Drawing::Size(100,18);
	progressBar->DrawToBitmap(progressBarBitmap,System::Drawing::Rectangle(0,0,width,18));
	return progressBarBitmap;
}

System::Void DownloadFileTab::SaveDownloadingList(){
	DownloadingJob^ job;
	FileStream^ fs;

	/*if(!File::Exists(this->loginUser->DownloadedFileListPath)){
	fs = File::Create(this->loginUser->DownloadedFileListPath);
	}
	else{*/
	fs = File::OpenWrite(this->mainDlg->loginUser->DownloadingFileListPath);
	//}
	array<Byte>^ totalCountByteArray = BitConverter::GetBytes((int32_t)this->mainDlg->downloadingJobDict->Count);

	fs->Write(totalCountByteArray,0,totalCountByteArray->Length);
	array<Byte>^ jobNodeByte;
	array<Byte>^ jobNodeLengthByte;
	String^ jobName;
	for each(jobName in this->mainDlg->downloadingJobDict->Keys){
		job = this->mainDlg->downloadingJobDict[jobName];
		jobNodeByte = job->GetBytes();
		jobNodeLengthByte = BitConverter::GetBytes((int32_t)(jobNodeByte->Length));
		fs->Write(jobNodeLengthByte,0,jobNodeLengthByte->Length);
		fs->Write(jobNodeByte,0,jobNodeByte->Length);
		//jobNode = jobNode->Next;
	}
	fs->Close();

}

System::Void DownloadFileTab::SaveDownloadedList(){
	DownloadingJob^ job;
	FileStream^ fs;

	/*if(!File::Exists(this->loginUser->DownloadedFileListPath)){
	fs = File::Create(this->loginUser->DownloadedFileListPath);
	}
	else{*/
	fs = File::OpenWrite(this->mainDlg->loginUser->DownloadedFileListPath);
	//}
	array<Byte>^ totalCountByteArray = BitConverter::GetBytes((int32_t)this->mainDlg->downloadedJobArray->Count);
	LinkedListNode<DownloadingJob^>^ jobNode = this->mainDlg->downloadedJobArray->First;
	fs->Write(totalCountByteArray,0,totalCountByteArray->Length);
	array<Byte>^ jobNodeByte;
	array<Byte>^ jobNodeLengthByte;
	while(jobNode != nullptr){
		job = jobNode->Value;
		jobNodeByte = job->GetBytes();
		jobNodeLengthByte = BitConverter::GetBytes((int32_t)(jobNodeByte->Length));
		fs->Write(jobNodeLengthByte,0,jobNodeLengthByte->Length);
		fs->Write(jobNodeByte,0,jobNodeByte->Length);
		jobNode = jobNode->Next;
	}
	fs->Close();
}
System::Void DownloadFileTab::LoadDownloadList(){
	DownloadingJob^ job;
	//Load downloading list

	if(File::Exists(this->mainDlg->loginUser->DownloadingFileListPath)){
		array<Byte>^ totalByteArray = File::ReadAllBytes(this->mainDlg->loginUser->DownloadingFileListPath);
		int totalJobCount = 0;
		if(totalByteArray->Length > sizeof(int32_t)){
			totalJobCount = BitConverter::ToInt32(totalByteArray,0);
		}
		int currPtr = sizeof(int32_t);
		int jobSize = 0;
		while(true){
			if((totalJobCount > 0) && (totalByteArray->Length - currPtr - sizeof(int32_t)> 0)){
				jobSize = BitConverter::ToInt32(totalByteArray,currPtr);
				currPtr += sizeof(int32_t);
			}	
			else{
				break;
			}

			if(totalByteArray->Length >= (currPtr + jobSize)){
				job = gcnew DownloadingJob(totalByteArray,currPtr);
				currPtr += jobSize;
				this->mainDlg->downloadingJobDict[job->JobName] = job;
				totalJobCount--;
			}
			else{
				break;
			}
		}
	}

	//Load downloaded list
	if(File::Exists(this->mainDlg->loginUser->DownloadedFileListPath)){
		array<Byte>^ totalByteArray = File::ReadAllBytes(this->mainDlg->loginUser->DownloadedFileListPath);
		int totalJobCount = 0;
		if(totalByteArray->Length > sizeof(int32_t)){
			totalJobCount = BitConverter::ToInt32(totalByteArray,0);
		}
		int currPtr = sizeof(int32_t);
		int jobSize = 0;
		while(true){
			if((totalJobCount > 0) && (totalByteArray->Length - currPtr - sizeof(int32_t)> 0)){
				jobSize = BitConverter::ToInt32(totalByteArray,currPtr);
				currPtr += sizeof(int32_t);
			}	
			else{
				break;
			}

			if(totalByteArray->Length >= (currPtr + jobSize)){
				job = gcnew DownloadingJob(totalByteArray,currPtr);
				currPtr += jobSize;
				this->mainDlg->downloadedJobArray->AddLast(job);
			}
			else{
				break;
			}
		}
	}
	this->UpdateFinishedJob();
	this->UpdateUnfinishedJob();

}


System::Void DownloadFileTab::fileTransferTabStartJobButton_Click(System::Object^  sender, System::EventArgs^  e) {
	DataGridViewRow^ row;
	String^ jobName;
	DownloadingJob^ job;
	OusnsMessage^ msg;
	LinkedList<String^>^ params;
	for each(row in this->fileTransferDataGridViewX->SelectedRows){
		jobName = safe_cast<String^>(row->Cells[1]->Value);
		job = this->mainDlg->downloadingJobDict[jobName];
		params = gcnew LinkedList<String^>();
		//params->AddLast(")
		msg = this->mainDlg->msgCreator->MakeCommandEntry('a',jobName,"",params);
	}

}

System::Void DownloadFileTab::fileTransferTabNewJobButton_Click(System::Object^  sender, System::EventArgs^  e){
	NewDownloadingJob^ newDownloadingJob = gcnew NewDownloadingJob(this->mainDlg);
	//newDownloadingJob->Parent = this;
	//newDownloadingJob->TopMost = false;
	newDownloadingJob->ShowDialog();
}



/*
* This function will be called when the downloader communication need to update the current file list (some bool is set)
*/
System::Void DownloadFileTab::UpdateUnfinishedJob(void){
	DownloadingJob ^ job;
	this->fileTransferDataGridViewX->SuspendLayout();
	//this->fileTransferDataGridViewX->Rows->Clear();
	DataGridViewRow^ row;
	String^ jobName;
	for each (jobName in this->mainDlg->downloadingJobDict->Keys){
		job = this->mainDlg->downloadingJobDict[jobName];
		bool jobExist = false;
		bool isMetaData = false;
		for each (row in this->fileTransferDataGridViewX->Rows){
			if(job->JobName->CompareTo(dynamic_cast<String^>(row->Cells[1]->Value)) == 0){
				//Update such entry in the datagridview
				row->Cells[0]->ToolTipText = job->JobOuSnsStatusString;
				row->Cells[0]->Value = this->GetJobStatusBitmap(job->JobOuSnsStatus);
				row->Cells[2]->Value = job->JobSizeString;
				if(job->JobOuSnsStatus == OuSns::JOB_RUNNING)
					row->Cells[3]->Value = job->TotalDownloadRateString;
				else
					row->Cells[3]->Value = "";
				row->Cells[4]->Value = this->GetProgressBarBitmap(job->JobTotalProgress,row->Cells[4]->Size.Width);
				row->Cells[4]->ToolTipText = job->JobTotalProgressString + "%";
				row->Cells[5]->Value = job->CreateTimeString;
				if(job->JobOuSnsStatus == OuSns::JOB_RUNNING)
					row->Cells[6]->Value = job->FinishedTimeString;
				else
					row->Cells[6]->Value = "";
				jobExist = true;
			}
		} 

		if (jobExist == false){
			DataGridViewRow^ tempRow = gcnew DataGridViewRow();
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::PowderBlue;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			//tempRow->DefaultCellStyle = dataGridViewCellStyle1;
			//DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobStatus = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			DataGridViewImageCell^ jobStatus = gcnew DataGridViewImageCell();
			jobStatus->ToolTipText = job->JobOuSnsStatusString;
			jobStatus->Value = this->GetJobStatusBitmap(job->JobOuSnsStatus);
			//jobStatus->Style = dataGridViewCellStyle1;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobName = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobName->ToolTipText = L"文件名称";
			jobName->Value = job->JobName;
			//jobName->Style = dataGridViewCellStyle1;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobSize = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobSize->ToolTipText = L"文件大小";
			jobSize->Value = job->JobSizeString;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobDownloadSpeed = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			if(job->JobOuSnsStatus == OuSns::JOB_RUNNING)
				jobDownloadSpeed->Value = job->TotalDownloadRate.ToString() + "/s";
			else
				jobDownloadSpeed->Value = "";
			jobDownloadSpeed->ToolTipText = L"文件当前下载速度";
			DataGridViewImageCell^ jobProgress = gcnew DataGridViewImageCell();
			jobProgress->Value = this->GetProgressBarBitmap(job->JobTotalProgress,this->fileProgressDataGridViewImageColumn->Width);
			jobProgress->ToolTipText = job->JobTotalProgressString + "%";
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobCreatedTime = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobCreatedTime->Value = job->CreatedTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
			jobCreatedTime->ToolTipText = L"文件添加到下载列表的时间";
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobFinishingTime = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			if(job->JobOuSnsStatus == OuSns::JOB_RUNNING)
				jobFinishingTime->Value = job->FinishedTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
			else
				jobFinishingTime->Value = "";
			jobFinishingTime->ToolTipText = L"文件预计下载完成时间";
			tempRow->Cells->AddRange(gcnew array<DataGridViewCell^>{jobStatus,jobName,jobSize,jobDownloadSpeed,jobProgress,jobCreatedTime,jobFinishingTime});
			this->fileTransferDataGridViewX->Rows->Add(tempRow);
		}
	}


	fileTransferDataGridViewX->ResumeLayout();

}

System::Void DownloadFileTab::UpdateFinishedJob(void){
	DownloadingJob ^ job;
	this->finishedFileTransferDataGridViewX->SuspendLayout();
	//this->finishedFileTransferDataGridViewX->Rows->Clear();
	DataGridViewRow^ row;
	String^ jobName;
	//for each (jobName in this->mainDlg->downloadingJobDict->Keys){
	//job = this->mainDlg->downloadingJobDict[jobName];
	LinkedListNode<DownloadingJob^>^ jobNode = this->mainDlg->downloadedJobArray->First;
	while(jobNode != nullptr){
		job = dynamic_cast<DownloadingJob^>(jobNode->Value);
		bool jobExist = false;
		if (jobExist == false){
			DataGridViewRow^ tempRow = gcnew DataGridViewRow();
			DataGridViewImageCell^ jobStatus = gcnew DataGridViewImageCell();
			jobStatus->ToolTipText = job->JobOuSnsStatusString;
			jobStatus->Value = this->GetJobStatusBitmap(job->JobOuSnsStatus);
			//jobStatus->Style = dataGridViewCellStyle1;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobName = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobName->ToolTipText = L"文件名称";
			jobName->Value = job->JobName;
			//jobName->Style = dataGridViewCellStyle1;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobSize = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobSize->ToolTipText = L"文件大小";
			jobSize->Value = job->JobSizeString;
			DevComponents::DotNetBar::Controls::DataGridViewLabelXCell^ jobFinishingTime = gcnew DevComponents::DotNetBar::Controls::DataGridViewLabelXCell();
			jobFinishingTime->Value = job->FinishedTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
			jobFinishingTime->ToolTipText = L"文件预计下载完成时间";
			tempRow->Cells->AddRange(gcnew array<DataGridViewCell^>{jobStatus,jobName,jobSize,jobFinishingTime});
			this->finishedFileTransferDataGridViewX->Rows->Add(tempRow);
		}
		jobNode = jobNode->Next;
	}


	finishedFileTransferDataGridViewX->ResumeLayout();

}



