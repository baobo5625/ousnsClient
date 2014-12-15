#include "stdafx.h"
#include "DownloadingJob.h"

//DownloadingJob::DownloadingJob(String^ jobName, String^ jobPath,String^ torrentFileName,  int magnetURILength,String^ magnetURI,int32_t jobError, int32_t jobSize,int32_t totalProgress_ppm,int32_t totalDownloadRate,
DownloadingJob::DownloadingJob(String^ jobName, String^ jobPath,int32_t jobError, int32_t jobSize,int32_t totalProgress_ppm,int32_t totalDownloadRate,\
   int32_t totalDone,int32_t jobLibtorrentStatus,int32_t jobPaused,int32_t peers,int32_t seeds, int32_t distributed_full_copies, \
   int32_t distributed_fraction, LinkedList<DownloadingFile^>^ filesInput){
	Encoding^ u16LE = Encoding::Unicode;
	this->jobName = jobName;
	this->jobNameByte = gcnew array<Byte>(MAX_PATH);
	this->jobIndex = 0;
	this->jobIndexByte = gcnew array<Byte>(sizeof(int32_t));
	BitConverter::GetBytes(this->jobIndex)->CopyTo(this->jobIndexByte,0);
	u16LE->GetBytes(this->jobName)->CopyTo(this->jobNameByte,0);
	this->jobPath = jobPath;
	this->jobPathByte = gcnew array<Byte>(MAX_PATH);
	u16LE->GetBytes(this->jobPath)->CopyTo(this->jobPathByte,0);

/*
	this->torrentFileName = torrentFileName;
	this->torrentFileNameByte = gcnew array<Byte>(MAX_PATH);
	u16LE->GetBytes(this->torrentFileName)->CopyTo(this->torrentFileNameByte,0);


	this->magnetURILength = magnetURILength;
	this->magnetURILengthByte = gcnew array<Byte>(sizeof(int32_t));
	BitConverter::GetBytes(this->magnetURILength)->CopyTo(this->magnetURILengthByte,0);


	this->magnetURI = magnetURI;
	this->magnetURIByte = gcnew array<Byte>(this->magnetURILength);
	u16LE->GetBytes(this->magnetURI)->CopyTo(this->magnetURIByte,0);
*/
	this->jobError = jobError;
	this->totalDownloadRate = totalDownloadRate;
	this->totalDone = totalDone;
	this->totalDoneByte = gcnew array<Byte>(sizeof(int32_t));
	BitConverter::GetBytes(this->totalDone)->CopyTo(this->totalDoneByte,0);
	this->totalProgress_ppm = totalProgress_ppm;
	this->totalProgress_ppmByte = gcnew array<Byte>(sizeof(int32_t));
	BitConverter::GetBytes(this->totalProgress_ppm)->CopyTo(this->totalProgress_ppmByte,0);
	this->jobLibtorrentStatus = jobLibtorrentStatus;
	this->jobPaused  = jobPaused;
	/*
	if(this->jobLibtorrentStatus != -1){
	   if(this->jobPaused == 0){
		   //Job not paused
		   //When the job has status finished or seeding
		   if(this->jobLibtorrentStatus == 4 ||this->jobLibtorrentStatus == 5)
			   this->jobOuSnsStatus = OuSns::JOB_FINISHED;
		   else
			   this->jobOuSnsStatus = OuSns::JOB_RUNNING;
	   }
	   else{
		   this->jobOuSnsStatus = OuSns::JOB_PAUSED;
	   }
   }
   else if(this->totalProgress_ppm == 1000000){
	   this->jobOuSnsStatus = OuSns::JOB_FINISHED;
   }
   else{
	   this->jobOuSnsStatus = OuSns::JOB_STOPPED;
   }*/
	switch(this->jobLibtorrentStatus){
		case 0:
			this->jobOuSnsStatus = OuSns::JOB_WAITING;
			break;
		case 1:
			this->jobOuSnsStatus = OuSns::JOB_WAITING;
			break;
		case 2:
			this->jobOuSnsStatus = OuSns::JOB_RUNNING;
			break;
		case 3:
			this->jobOuSnsStatus = OuSns::JOB_RUNNING;
			break;
		case 4:
			this->jobOuSnsStatus = OuSns::JOB_FINISHED;
			break;
		case 5:
			this->jobOuSnsStatus = OuSns::JOB_UPLOADING;
			break;
		case 6:
			this->jobOuSnsStatus = OuSns::JOB_WAITING;
			break;
		case 7:
			this->jobOuSnsStatus = OuSns::JOB_WAITING;
			break;
		default:
			this->jobOuSnsStatus = OuSns::JOB_ERROR;
	}
   this->peers = peers;
   this->seeds = seeds;
   this->distributed_fraction = distributed_fraction;
   this->distributed_full_copies = distributed_full_copies;
   this->files = gcnew array<DownloadingFile^>(filesInput->Count);
   //Array::Copy(filesInput,this->files,filesInput->Length);
   //filesInput->CopyTo(this->files,0);
   DownloadingFile^ file;
   for each(file in filesInput){
	   this->files[file->FileIndex] = file;
   }
   this->jobSize = jobSize;
   this->jobSizeByte = gcnew array<Byte>(sizeof(int32_t));
   BitConverter::GetBytes(this->jobSize)->CopyTo(this->jobSizeByte,0);
   this->createdTime = DateTime::Now;
   if(this->totalDownloadRate)
	   this->finishedTime = this->createdTime->AddSeconds((this->jobSize - this->totalDone)/this->totalDownloadRate);
   else
	   this->finishedTime = this->createdTime->AddSeconds((this->jobSize - this->totalDone)/1);
   this->createdTimeByte = gcnew array<Byte>(sizeof(int64_t));
   int64_t tempCreatedTimeInt = this->createdTime->ToBinary();
   BitConverter::GetBytes(this->createdTime->ToBinary())->CopyTo(this->createdTimeByte,0);
   this->finishedTimeByte = gcnew array<Byte>(sizeof(int64_t));
   BitConverter::GetBytes(this->finishedTime->ToBinary())->CopyTo(this->finishedTimeByte,0);
   this->totalByteArrayLength = OUSNS_DOWNLOADING_JOB_LENGTH + (OUSNS_DOWNLOADING_FILE_LENGTH) * this->files->Length + 4;
}
/*
 * This is used to rebuild the downloading job dict from the download list file
 */
DownloadingJob::DownloadingJob(array<Byte>^ byteArray,int offset){
	try{
		Encoding^ u16LE = Encoding::Unicode;
		int byteArrayPtr = offset;
		this->jobNameByte = gcnew array<Byte>(MAX_PATH);
		Array::Copy(byteArray,byteArrayPtr,this->jobNameByte,0,MAX_PATH);
		this->jobName = u16LE->GetString(this->jobNameByte);
		byteArrayPtr += MAX_PATH;

		this->jobPathByte =  gcnew array<Byte>(MAX_PATH);
		Array::Copy(byteArray, byteArrayPtr, this->jobPathByte,0,MAX_PATH);
		this->jobPath = u16LE->GetString(this->jobPathByte);
		byteArrayPtr += MAX_PATH;

		/*
		this->torrentFileNameByte = gcnew array<Byte>(MAX_PATH);
		Array::Copy(byteArray,byteArrayPtr,this->torrentFileNameByte,0,MAX_PATH);
		this->torrentFileName = u16LE->GetString(this->torrentFileNameByte);
		byteArrayPtr += MAX_PATH;

		//this->magnetURI = gcnew array<Byte>
		this->magnetURILengthByte = gcnew array<Byte>(sizeof(int32_t));
		Array::Copy(byteArray,byteArrayPtr,this->magnetURILengthByte,0,sizeof(int32_t));
		this->magnetURILength = BitConverter::ToInt32(this->magnetURILengthByte,0);
		byteArrayPtr += sizeof(int32_t);

		this->magnetURIByte = gcnew array<Byte>(this->magnetURILength);
		Array::Copy(byteArray,byteArrayPtr,this->magnetURIByte,0,this->magnetURILength);
		this->magnetURILength = BitConverter::ToInt32(this->magnetURIByte,0);
		byteArrayPtr += this->magnetURILength;
*/


		this->jobIndexByte = gcnew array<Byte>(sizeof(int32_t));
		Array::Copy(byteArray,byteArrayPtr, this->jobIndexByte,0,sizeof(int32_t));
		this->jobIndex = BitConverter::ToInt32(this->jobIndexByte,0);
		byteArrayPtr += sizeof(int32_t);

		this->totalProgress_ppmByte = gcnew array<Byte>(sizeof(int32_t));
		Array::Copy(byteArray,byteArrayPtr,this->totalProgress_ppmByte,0,sizeof(int32_t));
		this->totalProgress_ppm = BitConverter::ToInt32(this->totalProgress_ppmByte,0);
		byteArrayPtr += sizeof(int32_t);

		this->totalDoneByte = gcnew array<Byte>(sizeof(int32_t));
		Array::Copy(byteArray,byteArrayPtr,this->totalDoneByte,0,sizeof(int32_t));
		this->totalDone = BitConverter::ToInt32(this->totalDoneByte,0);
		byteArrayPtr += sizeof(int32_t);

		this->jobSizeByte = gcnew array<Byte>(sizeof(int32_t));
		Array::Copy(byteArray,byteArrayPtr,this->jobSizeByte,0,sizeof(int32_t));
		this->jobSize = BitConverter::ToInt32(this->jobSizeByte,0);
		byteArrayPtr += sizeof(int32_t);

		this->createdTimeByte = gcnew array<Byte>(sizeof(int64_t));
		Array::Copy(byteArray,byteArrayPtr,this->createdTimeByte,0,sizeof(int64_t));
		//int64_t tempInt = BitConverter::ToInt64(this->createdTimeByte,0);
		this->createdTime = DateTime::FromBinary(BitConverter::ToInt64(this->createdTimeByte,0));
		byteArrayPtr += sizeof(int64_t);

		this->finishedTimeByte = gcnew array<Byte>(sizeof(int64_t));
		Array::Copy(byteArray,byteArrayPtr,this->finishedTimeByte,0,sizeof(int64_t));
		this->finishedTime = DateTime::FromBinary(BitConverter::ToInt64(this->finishedTimeByte,0));
		byteArrayPtr += sizeof(int64_t);

		int fileArrayLength = BitConverter::ToInt32(byteArray,byteArrayPtr);
		byteArrayPtr += sizeof(int32_t);

		this->files = gcnew array<DownloadingFile^>(fileArrayLength);
		array<Byte>^ tempFileArray = gcnew array<Byte>(OUSNS_DOWNLOADING_FILE_LENGTH);

		for (int i = 0; i < fileArrayLength;i++){
			Array::Copy(byteArray,byteArrayPtr,tempFileArray,0,OUSNS_DOWNLOADING_FILE_LENGTH);
			this->files[i] = gcnew DownloadingFile(tempFileArray);
			byteArrayPtr += OUSNS_DOWNLOADING_FILE_LENGTH;
		}
		

		this->jobError = 0;
		this->totalDownloadRate = 0;

		this->jobLibtorrentStatus = 0;
		this->jobPaused  = 0;
		if(this->totalProgress_ppm == 1000000)
			this->jobOuSnsStatus = OuSns::JOB_FINISHED;
		else
			this->jobOuSnsStatus = OuSns::JOB_STOPPED;
		this->peers = 0;
		this->seeds = 0;
		this->distributed_fraction = 0;
		this->distributed_full_copies = 0;

		this->totalByteArrayLength = OUSNS_DOWNLOADING_JOB_LENGTH + (OUSNS_DOWNLOADING_FILE_LENGTH) * this->files->Length + 4;


		this->createdSuccessful = true;
	}
	catch (Exception ^){
		this->createdSuccessful = false;
	}


		

}

void DownloadingJob::UpdateFinishedTime(){
	DateTime^ currentTime = DateTime::Now;
	if(this->totalDownloadRate)
		this->finishedTime = this->createdTime->AddSeconds((this->jobSize - this->totalDone)/this->totalDownloadRate);
	else
		this->finishedTime = this->createdTime->AddSeconds((this->jobSize - this->totalDone)/1);
	BitConverter::GetBytes(this->finishedTime->ToBinary())->CopyTo(this->finishedTimeByte,0);
}

void DownloadingJob::UpdateParams(int32_t jobError,int32_t totalProgress_ppm,int32_t totalDone,int32_t totalDownloadRate, int32_t jobLibtorrentStatus, int32_t jobPaused, int32_t jobPeer,\
				  int32_t jobSeed, int32_t jobDistributedFullCopies, int32_t jobDistributedFriactions, LinkedList<DownloadingFile^>^ filesInput){
	  this->jobError = jobError;
	  this->totalDownloadRate = totalDownloadRate;
	  if(this->totalDone != totalDone)
		BitConverter::GetBytes(totalDone)->CopyTo(this->totalDoneByte,0);
	  this->totalDone = totalDone;
	  if(this->totalProgress_ppm != totalProgress_ppm)
		BitConverter::GetBytes(totalProgress_ppm)->CopyTo(this->totalProgress_ppmByte,0);
	  this->totalProgress_ppm = totalProgress_ppm;
	  this->jobLibtorrentStatus = jobLibtorrentStatus;
	  this->jobPaused  = jobPaused;
	  if(this->jobLibtorrentStatus != -1){
		  if(this->jobPaused == 0){
			  //Job not paused
			  //When the job has status finished or seeding
			  if(this->jobLibtorrentStatus == 4 ||this->jobLibtorrentStatus == 5)
				  this->jobOuSnsStatus = OuSns::JOB_FINISHED;
			  else
				  this->jobOuSnsStatus = OuSns::JOB_RUNNING;
		  }
		  else{
			  this->jobOuSnsStatus = OuSns::JOB_PAUSED;
		  }
	  }
	  else if(this->totalProgress_ppm == 1000000){
		  this->jobOuSnsStatus = OuSns::JOB_FINISHED;
	  }
	  else{
		  this->jobOuSnsStatus = OuSns::JOB_STOPPED;
	  }
	  this->peers = peers;
	  this->seeds = seeds;
	  this->distributed_fraction = distributed_fraction;
	  this->distributed_full_copies = distributed_full_copies;
	  this->jobOuSnsStatus = jobOuSnsStatus;
	  //this->files = gcnew array<DownloadingFile^>(filesInput->Count);
	  //Array::Copy(filesInput,this->files,filesInput->Length);
	  //filesInput->CopyTo(this->files,0);
	  DownloadingFile^ file;
	  for each (file in filesInput){
		this->files[file->FileIndex]->UpdateParam(file->FileName,file->FileProgress);
	  }
	  this->UpdateFinishedTime();
}




String^ DownloadingJob::SizeIntToString(double inputValue){
	double doubleInputValue;
	if (inputValue <= 1024){
		return inputValue.ToString("F2") + "KB";
	}
	//MB
	else if(inputValue > 1024 && inputValue <= 1048576){
		doubleInputValue = inputValue/double(1024);
		//return doubleInputValue.ToString("F2",System::Globalization::CultureInfo::CreateSpecificCulture("en-US")) + "MB";
		return doubleInputValue.ToString("F2") + "MB";
	}
	//GB
	else if(inputValue > 1048576 && inputValue <= 1073741824){
		doubleInputValue = inputValue/double(1048576);
		//return doubleInputValue.ToString("F",System::Globalization::CultureInfo::CreateSpecificCulture("en-US")) + "GB";
		return doubleInputValue.ToString("F2") + "GB";
	}
	else{
		doubleInputValue = inputValue/double(1073741824);
		//return doubleInputValue.ToString("F",System::Globalization::CultureInfo::CreateSpecificCulture("en-US")) + "TB";
		return doubleInputValue.ToString("F2") + "TB";
	}
}

array<Byte>^ DownloadingJob::GetBytes(){
	array<Byte>^ returnByte = gcnew array<Byte>(this->totalByteArrayLength);
	int arrayPtr = 0;
	this->jobNameByte->CopyTo(returnByte,arrayPtr);
	arrayPtr+=this->jobNameByte->Length;
	this->jobPathByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->jobPathByte->Length;
	/*
	this->torrentFileNameByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->torrentFileName->Length;
	this->magnetURILengthByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->magnetURILengthByte->Length;
	this->magnetURIByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->magnetURIByte->Length;
	*/
	this->jobIndexByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->jobIndexByte->Length;
	this->totalProgress_ppmByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->totalProgress_ppmByte->Length;
	this->totalDoneByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->totalDoneByte->Length;
	this->jobSizeByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->jobSizeByte->Length;
	this->createdTimeByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->createdTimeByte->Length;
	this->finishedTimeByte->CopyTo(returnByte,arrayPtr);
	arrayPtr += this->finishedTimeByte->Length;
	if(this->files->Length != 0)
		int32_t fileArrayLength = this->files[0]->TotalByteArrayLength * this->files->Length + 4;
	else
		int32_t fileArrayLength = 4;
	BitConverter::GetBytes(this->files->Length)->CopyTo(returnByte,arrayPtr);
	arrayPtr += sizeof(int32_t);
	/*DownloadingFile^ file;
	for each (file in this->files){
		Array::Copy(file->GetBytes(),0,returnByte,arrayPtr);
		arrayPtr += file->TotalByteArrayLength;
	}*/
	for (int i = 0; i < this->files->Length; i++){
		Array::Copy(this->files[i]->GetBytes(),0,returnByte,arrayPtr,this->files[i]->TotalByteArrayLength);
		arrayPtr += this->files[i]->TotalByteArrayLength;
	}
	return returnByte;
}


void DownloadingJob::UpdateIndex(int jobIndex){
	if (this->jobIndex != jobIndex){
		BitConverter::GetBytes(this->jobIndex)->CopyTo(this->jobIndexByte,0);
	}
}