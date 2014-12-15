#include "stdafx.h"
#include "..\\Include\\DownloaderCommunication.h"
#pragma comment(lib,"..\\lib\\OusnsDownloaderCommunicator.lib")
#include "MessageCreator.h"
	


OusnsMessage^ MessageCreator::MakeJobEntry(DownloaderCommunication* dc){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;

	String^ messageID = "99999";
	pugi::xml_node root = doc.append_child();
	root.set_name("INTERNALMSG");
	root.append_attribute("actionType").set_value("UPDATEJOB");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));

	int i,j;
	pugi::xml_node jobNode,jobNameNode,jobErrorNode,jobSizeNode,jobPathNode,jobProgressNode,\
		jobDoneNode,jobDownloadRateNode,jobStatusNode,jobPausedNode,jobPeerNode,jobSeedNode,jobDistributedFullCopiesNode,\
		jobDistributedFriactionsNode,jobFileListNode,fileNode,filenameNode,filePathNode,fileSizeNode,fileProgressNode;
	char tempIntToStr[10];
	i = 0;
	//FileEntry fileEntry;
	while(i < dc->localMem->currentJob){
		jobNode = root.append_child(ManagedStringToAnsi("job"+i.ToString()));
		jobNameNode = jobNode.append_child("jobName");
		jobNameNode.append_child(pugi::node_pcdata).set_value(dc->localMem->jobEntry[i].jobName);
		/*
		jobCreatedTimeNode = jobNode.append_child("jobCreatedTime");
		jobCreatedTimeNode.append_child(pugi::node_pcdata).set_value(0);

		jobFinishedTimeNode = jobNode.append_child("jobFinishedTime");
		jobFinishedTimeNode.append_child(pugi::node_pcdata).set_value(0);
		*/
		_itoa_s((int)dc->localMem->jobEntry[i].jobError,tempIntToStr,10,10);
		jobErrorNode = jobNode.append_child("jobError");
		jobErrorNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s((int)dc->localMem->jobEntry[i].jobSize,tempIntToStr,10,10);
		jobSizeNode = jobNode.append_child("jobSize");
		jobSizeNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		jobPathNode = jobNode.append_child("jobPath");
		jobPathNode.append_child(pugi::node_pcdata).set_value(dc->localMem->jobEntry[i].jobPath);


		_itoa_s((int)dc->localMem->jobEntry[i].totalProgress_ppm,tempIntToStr,10,10);
		jobProgressNode = jobNode.append_child("jobProgress");
		jobProgressNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s((int)dc->localMem->jobEntry[i].totalDone,tempIntToStr,10,10);
		jobDoneNode = jobNode.append_child("jobDone");
		jobDoneNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s((int)dc->localMem->jobEntry[i].totalDownloadRate,tempIntToStr,10,10);
		jobDownloadRateNode = jobNode.append_child("jobDownloadRate");
		jobDownloadRateNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		 _itoa_s(dc->localMem->jobEntry[i].jobStatus,tempIntToStr,10,10);
		jobStatusNode = jobNode.append_child("jobStatus");
		jobStatusNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);


		_itoa_s(dc->localMem->jobEntry[i].jobPaused,tempIntToStr,10,10);
		jobPausedNode = jobNode.append_child("jobPaused");
		jobPausedNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		 _itoa_s(dc->localMem->jobEntry[i].peers,tempIntToStr,10,10);
		jobPeerNode = jobNode.append_child("jobPeer");
		jobPeerNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s(dc->localMem->jobEntry[i].seeds,tempIntToStr,10,10);
		jobSeedNode = jobNode.append_child("jobSeed");
		jobSeedNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s(dc->localMem->jobEntry[i].distributed_full_copies,tempIntToStr,10,10);
		jobDistributedFullCopiesNode = jobNode.append_child("jobDistributedFullCopies");
		jobDistributedFullCopiesNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		_itoa_s(dc->localMem->jobEntry[i].distributed_fraction,tempIntToStr,10,10);
		jobDistributedFriactionsNode = jobNode.append_child("jobDistributedFriactions");
		jobDistributedFriactionsNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);

		jobFileListNode = jobNode.append_child("jobFileList");
		j = 0;
		while(j < dc->localMem->jobEntry[i].currentFile){
			fileNode = jobFileListNode.append_child(ManagedStringToAnsi("file"+j.ToString()));
			
			
			filenameNode = fileNode.append_child("filename");
			filenameNode.append_child(pugi::node_pcdata).set_value(dc->localMem->jobEntry[i].files[j].fileName);
			
			filePathNode = fileNode.append_child("filePath");
			filePathNode.append_child(pugi::node_pcdata).set_value(dc->localMem->jobEntry[i].files[j].filePath);

			_itoa_s(dc->localMem->jobEntry[i].files[j].fileSize,tempIntToStr,10,10);
			fileSizeNode = fileNode.append_child("fileSize");
			fileSizeNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);
			
			_itoa_s(dc->localMem->jobEntry[i].files[j].fileProgress,tempIntToStr,10,10);
			fileProgressNode = fileNode.append_child("fileProgress");
			fileProgressNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);
			j++;
		}
		i++;

	}


	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::DOWNLOADERCOMMUNICATOR,OuSns::WORK,OuSns::INTERNALMSG,0,messageID,OuSns::UPDATEJOB, messageContent, this->serverAddr,this->serverPort,false,OuSns::NORMAL);
	return returnMsg;
}


/* Command target is the job name*/
OusnsMessage^ MessageCreator::MakeCommandEntry(char commandChar, String^ commandTarget,String^ magnetURI,LinkedList<String^>^ params){
	OusnsMessage^ returnMsg;
	pugi::xml_document doc;


	String^ messageID = "99999";
	pugi::xml_node root = doc.append_child();
	root.set_name("INTERNALMSG");
	root.append_attribute("actionType").set_value("ADDDOWNLOADERCOMMAND");
	root.append_attribute("messageID").set_value(ManagedStringToAnsi(messageID));

	char tempIntToStr[10];

	String^ param;

	pugi::xml_node commandCharNode,commandTargetNode,magnetURINode,commandParamListNode, commandParamNode;
	_itoa_s((int)commandChar,tempIntToStr,10,10);
	commandCharNode = root.append_child("commandChar");
	commandCharNode.append_child(pugi::node_pcdata).set_value(tempIntToStr);
	
	commandTargetNode = root.append_child("commandTarget");
	commandTargetNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(commandTarget));
	magnetURINode = root.append_child("magnetURI");
	magnetURINode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(magnetURI));

	commandParamListNode = root.append_child("commandParamList");
	int i = 0;
	if(params->Count <= PARAM_LENGTH_LIMIT){
		for each(param in params){
			commandParamNode = commandParamListNode.append_child(ManagedStringToAnsi("commandParam" + i.ToString()));
			commandParamNode.append_child(pugi::node_pcdata).set_value(ManagedStringToAnsi(param));
			i++;
		}
	}

	std::string result;
	pugi::xml_string_writer writer;
	root.print(writer,"\x09",format_raw);
	String^ messageContent = gcnew String(writer.result.c_str());
	returnMsg = gcnew OusnsMessage(OuSns::DOWNLOADERCOMMUNICATOR,OuSns::WORK,OuSns::INTERNALMSG,0,messageID,OuSns::ADDDOWNLOADERCOMMAND, messageContent, this->serverAddr,this->serverPort,false,OuSns::NORMAL);

	return returnMsg;
}

