// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
//#include "DownloaderCommunication.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//MessageBox(NULL,L"process attach",L"caption",MB_OK);
		//dc = new DownloaderCommunication();
		break;
	case DLL_THREAD_ATTACH:
		//MessageBox(NULL,L"thread attach",L"caption",MB_OK);
		break;
	case DLL_THREAD_DETACH:
		//MessageBox(NULL,L"process detach",L"caption",MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		//MessageBox(NULL,L"thread detach",L"caption",MB_OK);
		break;
	}
	return TRUE;
}

