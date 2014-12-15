#include "stdafx.h"
#include "doc_anonymous_mutex_shared_data.hpp"
//[DllImport("OusnsDownloaderCommunicator.dll")]
//__declspec(dllimport) DownloaderCommunication
//__declspec(dllimport)

//class windows_shared_memory;
//class mapped_region;
 class  DownloaderCommunication
{

public:
	shared_memory_log * localMem;
	//windows_shared_memory shm;
	//shared_memory_object shm;
	//mapped_region region;
	//void * addr;
	//bool initMem;
	//vector<JobEntry*>* jobEntryVector;
	//boost::mutex * localMemLock;

public:
	DownloaderCommunication(void);
protected:
	~DownloaderCommunication(void){}



	/*
	* This function will start the downloader function
	*/
public:
	void DownloaderCommunication::StartDownloader(void);

	/*
	* This function will extract the downloading information from the 
	* Ousns downloader and update the download list by sending 
	* a list of Download struct to the information process function
	*/
public:
	void DownloaderCommunication::OusnsDownloaderInfoExchange(void);

	/*
	* This function will take a command char as well as a vector of string as command parameters
	*/
	void DownloaderCommunication::SetCommand(char command,vector<std::string> params, std::string commandTarget,std::string magnetURI);

	//Acquire the local memory lock,called by the client thread, will block the thread
	void DownloaderCommunication::AcquireLocalMemLock(void);

	//Release the local memory lock, called by the client thread
	void DownloaderCommunication::RleaseLocalMemLock(void);

	shared_memory_log * DownloaderCommunication::GetLocalMem();
};

