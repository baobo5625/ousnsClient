#include "stdAfx.h"
#include "DownloaderCommunication.h"
//#include <dos.h>
//#include <stdio.h>



DownloaderCommunication::DownloaderCommunication(){
		
	//char* appPath = getenv("APPDATA");
	this->initMem = 0;	
	this->localMem =(shared_memory_log*) malloc(sizeof(shared_memory_log));
	this->localMem = new (this->localMem) shared_memory_log;
	//this->localMem = new shared_memory_log;
	//this->localMemLock = new boost::mutex();
	//this->localMemLock->initialize();
	//this->localMemLock = new interprocess_mutex();
	//this->localMemlock = CreateMutex(NULL,FALSE,L"localMemlock");
	//this->StartDownloader();
	
}

/*
* This function will start the downloader function
*/
 void DownloaderCommunication::StartDownloader(void){
	//this->initMem = 0;	
	/*this->localMem =(shared_memory_log*) malloc(sizeof(shared_memory_log));
	this->localMem = new (this->localMem) shared_memory_log;
	this->localMemLock = new boost::mutex();
	this->localMemLock->initialize();
	*/
	try{
		this->shm = windows_shared_memory 
			(open_only               //only open
			,"ousns shared memory"          //name
			,read_write   //read-write mode
			);
		this->shmLock = windows_shared_memory 
			(open_only               //only open
			,"ousns shared memory lock"          //name
			,read_write   //read-write mode
			);
		this->region = mapped_region(shm, read_write);
		this->regionLock = mapped_region(shmLock,read_write);
		//std::memset(region.get_address(), 1, region.get_size());
		this->addr = region.get_address();
		this->addr2 = regionLock.get_address();
		this->initMem = 1;
	}
	catch(exception){

		STARTUPINFO si;
		memset(&si,0,sizeof(STARTUPINFO));
		ZeroMemory(&si,sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);
		si.dwFillAttribute = STARTF_USESTDHANDLES;
		si.wShowWindow = SW_HIDE;
		PROCESS_INFORMATION pi;
		memset(&pi,0,sizeof(PROCESS_INFORMATION));
		//wchar_t cmd[20] = L"OusnsDownloader.exe";
		wchar_t cmd[33] = L"OusnsDownloader.exe test.torrent";
		//wchar_t param[12] = L"test.torrent";
		if(!::CreateProcess(NULL,cmd,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi)){
			/*if(DEBUG_DOWNLOADER){
				MessageBox(NULL,L"Can not start downloader",L"caption",MB_OK);
			}*/
		}
		else{
			/*if(DEBUG_DOWNLOADER){
				MessageBox(NULL,L"started the downloader",L"caption",MB_OK);
			}*/
		}
	}

	
}




/*
* This function will extract the downloading information from the 
* Ousns downloader and update the download list by sending 
* a list of Download struct to the information process function
*/
void DownloaderCommunication::OusnsDownloaderInfoExchange(void){
	
	//BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

	if(this->initMem == 0){
		bool keepWhile = true;
		while(keepWhile){

			try{
				this->shm = windows_shared_memory 
					(open_only               //only open
					,"ousns shared memory"          //name
					,read_write   //read-write mode
					);
				this->shmLock = windows_shared_memory 
					(open_only               //only open
					,"ousns shared memory lock"          //name
					,read_write   //read-write mode
					);
				this->region = mapped_region(shm, read_write);
				this->regionLock = mapped_region(shmLock,read_write);
				//std::memset(region.get_address(), 1, region.get_size());
				this->addr = region.get_address();
				this->addr2 = regionLock.get_address();
				//AfxMessageBox::Show(L"finished checking memory");
				
				this->initMem = 1;
				keepWhile = false;
			}
			catch (exception){
				Sleep(500);
				//MessageBox(NULL,L"exception in the downloader info exchange",L"caption",MB_OK);
			}
		}
	}
	
	

	//Get the lock for this shared memory 
	//named_mutex mutex(open_or_create, "ousns_downloader_mutex");
	interprocess_mutex* mutex = static_cast<interprocess_mutex*>(this->addr2);
	shared_memory_log * data = static_cast<shared_memory_log*>( this->addr);
	//shared_memory_log * data = (shared_memory_log*)(this->addr);

	//vector<std::string> param(1);
	//string test = "test.torrent";
	//param[0] = test.c_str();
	//this->SetCommand(1,param);


	//Acquire the local mem lock

	//this->localMemLock->lock();

	/*DWORD dwWaitResult = WaitForSingleObject( 
		this->localMemlock,    // handle to mutex
		INFINITE);
		*/
	//data->mutex.lock();
	mutex->lock();
	//Set the command 
	bool set = false;
	memcpy(data->commandEntry,this->localMem->commandEntry, sizeof(CommandEntry )* this->localMem->currentCommand);
	data->currentCommand = this->localMem->currentCommand;
	//data->currentCommand = 0;
	this->localMem->currentCommand = 0;
	//Start to copy the output
	memcpy(this->localMem->jobEntry,data->jobEntry,sizeof(JobEntry) * data->currentJob);
	this->localMem->currentJob = data->currentJob;
	//data->currentJob = 0;
	//data->mutex.unlock();
	mutex->unlock();


	//this->localMemLock->unlock();
	//ReleaseMutex(this->localMemlock);
	/*if(DEBUG_DOWNLOADER)
		MessageBox(NULL,L"finished Exchange",L"caption",MB_OK);
	*/
	


}

/*
* This function will take a command char as well as a vector of string as command parameters
*/
void DownloaderCommunication::SetCommand(DownloaderCommunication* dc, char command,vector<std::string> params, std::string commandTarget,std::string magnetURI){
	/*
	string param;
	int counter = 0;

	//CommandEntry this->localMem->commandEntry[this->localMem->currentCommand];
	
	new(&this->localMem->commandEntry[this->localMem->currentCommand]) CommandEntry;
	
	this->localMem->commandEntry[this->localMem->currentCommand].commandChar = command;
	if(magnetURI.length() <= MAX_MAGNET_URI)
		strncpy(this->localMem->commandEntry[this->localMem->currentCommand].commandMagnetURI,magnetURI.data(),magnetURI.length());
	if(commandTarget.length() <= MAX_PATH)
		strncpy(this->localMem->commandEntry[this->localMem->currentCommand].commandTarget,commandTarget.data(),commandTarget.length());
	
	for each(param in params){
		if(counter < this->localMem->commandEntry[this->localMem->currentCommand].CommandParametersLimit &&
			param.length() <= MAX_PATH){
			strncpy(this->localMem->commandEntry[this->localMem->currentCommand].commandParam[counter],param.data(),param.length());
			counter++;
		}
	}
	
	this->localMem->commandEntry[this->localMem->currentCommand].currentParam = counter;
	this->localMem->currentCommand++;
	*/

	//this->localMemLock->unlock();
	//ReleaseMutex(this->localMemlock);
}


__declspec(dllexport) shared_memory_log * DownloaderCommunication::GetLocalMem(){
	return this->localMem;
}


//__declspec(dllexport) DownloaderCommunication *dc = new DownloaderCommunication();

DownloaderCommunication * DownloaderCommunication::GetInstance(){
	DownloaderCommunication * dc = new DownloaderCommunication();
	return dc;

}