#include "StdAfx.h"
#include "DownloadingJob.h"
#include "OuSnsJobInfoDlg.h"

OuSnsJobInfoDlg::OuSnsJobInfoDlg(DownloadingJob^ job)
//OuSnsJobInfoDlg(void)
{
	InitializeComponent();
	this->jobNameLabelX->Text = job->JobName;
	this->jobSizeLabelX->Text = job->JobSizeString;

	//this->downloadingFileListAdvTree->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node1});
	this->downloadingFileListAdvTree->Nodes->Clear();

	DevComponents::AdvTree::Node^ fileNode;
	DevComponents::AdvTree::Cell^ fileSize;
	DevComponents::AdvTree::Cell^ fileProgress;

	DownloadingFile^ file;
	int counter = 0;
	for each(file in job->files){
		fileNode = gcnew DevComponents::AdvTree::Node();
		fileSize = gcnew DevComponents::AdvTree::Cell();
		fileProgress =  gcnew DevComponents::AdvTree::Cell();
		fileSize->Name = L"fileSizeCell" + counter.ToString();
		fileSize->Text = file->FileSizeString;

		fileProgress->Name = L"fileProgressCell" + counter.ToString();
		fileProgress->Text = file->FileProgressString + "%";
		fileNode->Cells->Add(fileSize);	
		this->downloadingFileListAdvTree->Nodes->Add(fileNode);
	}



	//
	//TODO: 在此处添加构造函数代码
	//
}