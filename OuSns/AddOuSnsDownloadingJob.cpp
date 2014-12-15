#include "stdafx.h"
#include "AddOuSnsDownloadingJob.h"
#include "DownloadingJob.h"

AddOuSnsDownloadingJob::AddOuSnsDownloadingJob(DownloadingJob^ job,SystemSetting^ sysSetting, MainDlg^ mainDlg)
//AddOuSnsDownloadingJob(void)
{

	InitializeComponent();
	addingJob = job;
	this->jobNameLabelX->Text = job->JobName;
	this->jobSizeLabelX->Text = job->JobSizeString;

	validPath = false;
	this->jobPathComboTree->Nodes->Clear();
	//this->jobPathComboTree->SelectedNode = this->node2;
	DevComponents::AdvTree::Node^ node = gcnew DevComponents::AdvTree::Node();
	node->Text = sysSetting->defaultSavingPath;
	if(Directory::Exists(sysSetting->defaultSavingPath)){
		validPath = true;
	}
	this->jobPathComboTree->Nodes->Add(node);
	this->jobPathComboTree->SelectedNode = node;
	String^ filePath;
	for each(filePath in sysSetting->savingPathHistory){
		node = gcnew DevComponents::AdvTree::Node();
		node->Text = filePath;
		this->jobPathComboTree->Nodes->Add(node);
	}
	this->mainDlg = mainDlg;

	//
	//TODO: 在此处添加构造函数代码
	//
}

/*
System::Void AddOuSnsDownloadingJob::addJobButtonX_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->validPath && this->availableSpace > (this->addingJob->JobSize/1024)){
	 this->addingJob->JobPath = this->jobPathComboTree->Text;
	 this->mainDlg->downloadingJobDict[this->addingJob->jobName] = this->addingJob;
	 this->mainDlg->downloadingJobDictModified = true;
	 LinkedList<String^>^ params = gcnew LinkedList<String^>();
	 param->AddLast(this->addingJob->jobName);
	 //this->mainDlg->msgCreator->
	}
	else{
		if(this->validPath == false)
			MessageBox::Show(DOWNLOADER_INVALID_PATH);
		else
			MessageBox::Show(DOWNLOADER_NOT_ENOUGH_SPACE);
	}
}
*/

