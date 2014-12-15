#include "stdAfx.h"
#include "DownloaderCommunication.h"
#include "DownloadJob.h"
//#include <boost/interprocess/windows_shared_memory.hpp>
//#include <boost/interprocess/mapped_region.hpp>

System::Void DownloaderCommunication::onCreatePipe(){
	/*
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = true;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	HANDLE   hSTDINWrite,hSTDINRead,hSTDINWriteup;   //用于重定向子进程输入的句柄 
	HANDLE   hSTDOUTWrite,hSTDOUTRead,   hSTDOUTReadup;   //用于重定向子进程输出的句柄 

	//创建子进程输出匿名管道 
	HANDLE tempRead,tempWrite;
	if(!CreatePipe(&hSTDOUTRead,   &hSTDOUTWrite,   &sa,0)   ) 
	//if(!CreatePipe(&hSTDOUTRead, &hSTDOUTWrite, &sa,0))
	{
		MessageBox::Show(L"Create   STDOUT   pipe   failed ");
		return;
	}
	//if (!DuplicateHandle(::GetCurrentProcess(), tempSTDOUTRead, ::GetCurrentProcess(),&tempRead,0,false,DUPLICATE_SAME_ACCESS))
	if (!DuplicateHandle(::GetCurrentProcess(), hSTDOUTRead,   ::GetCurrentProcess(),&hSTDOUTReadup,0,false,DUPLICATE_SAME_ACCESS))

	{
		MessageBox::Show(L"Duplicate Handle failed ");
		return ;
	}
	::CloseHandle(hSTDOUTRead);
	
	if(!CreatePipe(&hSTDINRead,   &hSTDINWrite,   &sa,0)   )
	{
		MessageBox::Show(L"Create   STDIN   pipe   failed ");
		return;
	}
	//if(!DuplicateHandle(::GetCurrentProcess(),tempSTDINWrite,::GetCurrentProcess(),&tempWrite,0,false,DUPLICATE_SAME_ACCESS))
	if(!DuplicateHandle(::GetCurrentProcess(),hSTDINWrite,   ::GetCurrentProcess(),   &hSTDINWriteup,0,false,DUPLICATE_SAME_ACCESS))
	{
		MessageBox::Show(L"Duplicate Handle failed ");
		return ;
	}
	::CloseHandle(hSTDINWrite);

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si,sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFillAttribute = STARTF_USESTDHANDLES;
	//si.hStdInput = m_hRead;
	//si.hStdOutput = m_hWrite;
	si.hStdInput = hSTDINRead;
	si.hStdOutput = hSTDOUTWrite;
	si.wShowWindow = SW_HIDE;
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	if(!::CreateProcessA(NULL,".\\OusnsDownloader.exe",NULL, NULL, TRUE,  NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi)){
		MessageBox::Show(L"Can not start downloader");
		CloseHandle(m_hRead);
		CloseHandle(m_hWrite);
	}
	
	else{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		MessageBox::Show(L"Closed sub process handler");
	}
	*/


}
System::String^ DownloaderCommunication::onPipeRead(DWORD bufferSize){
	/*
	char * buf = new char[bufferSize];
	
	DWORD dwRead;
	if(!ReadFile(this->m_hRead,&buf,bufferSize,&dwRead,NULL)){
		return L"";
	}
	else{
		System::String^ return_string = gcnew System::String(buf);
		return return_string;
	}
	*/
	return L"";
}
/*
 * This function will initiate the background worker that start the 
 * OusnsDownloaderInfoExtraction function
 */
System::Void DownloaderCommunication::OusnsDownloaderInfoExtractionStarter(){


	System::ComponentModel::BackgroundWorker ^ bgworker = gcnew BackgroundWorker();
	bgworker->DoWork += gcnew DoWorkEventHandler( this, &DownloaderCommunication::OusnsDownloaderInfoExtraction );
    bgworker->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler( this, &DownloaderCommunication::stopOusnsDownloaderInfoExtraction );
    bgworker->ProgressChanged += gcnew ProgressChangedEventHandler( this, &DownloaderCommunication::OusnsDownloaderInfoProcessing);
	bgworker->WorkerReportsProgress = true;
	bgworker->WorkerSupportsCancellation= true;
//	bgworker->RunWorkerAsync();
	DownloadJob^ e = gcnew DownloadJob();
	bgworker->RunWorkerAsync(e);
}


/*
 * This function will extract the downloading information from the 
 * Ousns downloader and update the download list by sending 
 * a list of Download struct to the information process function
 */
System::Void DownloaderCommunication::OusnsDownloaderInfoExtraction(Object^ sender, DoWorkEventArgs^ e){
	/*
	BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
	
	using namespace boost::interprocess;
	
	STARTUPINFO si;
	memset(&si,0,sizeof(STARTUPINFO));
	ZeroMemory(&si,sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFillAttribute = STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi;
	memset(&pi,0,sizeof(PROCESS_INFORMATION));
	wchar_t cmd[20] = L"OusnsDownloader.exe";
	if(!::CreateProcess(NULL,cmd,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi))
	{
		MessageBox::Show(L"Can not start downloader");
	}
	else{
		MessageBox::Show(L"started the downloader");
	}
	Sleep(1000);
	windows_shared_memory shm (open_only, "MySharedMemory", read_only);
	mapped_region region(shm, read_only);
	//std::memset(region.get_address(), 1, region.get_size());
	char *mem = static_cast<char*>(region.get_address());
	*/
    /*
	for(std::size_t i = 0; i < region.get_size(); ++i)
       if(*mem++ != 1)
			 MessageBox::Show(L"checking memeory error");
	MessageBox::Show(L"finished checking memory");
	*/
	/*
	int counter = 0;

	*mem++;
	while (counter < 3){
		
		MessageBox::Show(AnsiToManagedString(mem));
		Sleep(1001);
		*/
		/*
		 * run but have several problems
		 * how to detect the process ended
		 * what happened if opened 2 processes (must be prohibited)
		 */
	/*
		counter++;
	}
	e->Cancel = true;
	*/

}

/*
 * This function will process the struct that sent from downloader information
 * extraction function
 */
System::Void DownloaderCommunication::OusnsDownloaderInfoProcessing(Object^ sender, ProgressChangedEventArgs^ e){
}

/*
 * This function will end the thread that extract the downloading information
 */
System::Void DownloaderCommunication::stopOusnsDownloaderInfoExtraction(System::Object ^,System::ComponentModel::RunWorkerCompletedEventArgs ^ e){
}
