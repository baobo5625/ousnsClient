//#include "stdafx.h"

/*namespace boost;
class boost::interprocess::windows_shared_memory;
class boost::interprocess::mapped_region;
class boost::mutex;
*/

class __declspec(dllexport) DownloaderCommunication
//class DownloaderCommunication
{
public:
	shared_memory_log *localMem ;
	windows_shared_memory shm;
	//shared_memory_object shm;
	windows_shared_memory shmLock;
	mapped_region region;
	mapped_region regionLock;
	void * addr;
	void * addr2;
	int initMem;
	//vector<JobEntry*>* jobEntryVector;
	//boost::mutex * localMemLock;
	//interprocess_mutex* localMemLock;
	//HANDLE localMemlock;

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
	static void DownloaderCommunication::SetCommand(DownloaderCommunication* dc, char command,vector<std::string> params, std::string commandTarget,std::string magnetURI);

	shared_memory_log * DownloaderCommunication::GetLocalMem();

	static DownloaderCommunication * GetInstance();
};

