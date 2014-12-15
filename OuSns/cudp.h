/********************************************************************
	
	File name -> UdpSocket.h

	Description:

		The header file for the class "CUdpSocket".
		CUdpSocket is a class which encapsulate the common
	functions to send and receive UDP packet. It provides the
	functions in common use and overridable functions such 
	as "OnXxxxXx".
		To set more attributes for the socket, please call
	setsockopt() with the return value of GetSenderSocket()
	and GetReceiverSocket().

	Author:		tief@mail.eastcomtd.com
	Created date:	2002/10/30 14:00 PM

	ATTENTION:

		(1)To use the class in WIN32 program, please link to 
	ws2_32.lib.
		(2)To use the class  in  VxWorks, please find the 
	statement  "#define BUILD_FOR_VXWORKS"   and  make  it 
	effective.

********************************************************************/

// #define BUILD_FOR_VXWORKS

#ifdef BUILD_FOR_VXWORKS

	#define VXWORKS
	// If you want to build the debug version
	#define _DEBUG

#endif

#ifndef _TIEF_UDP_VER1_
#define _TIEF_UDP_VER1_

#ifdef WIN32

	//#include <winsock2.h>

#endif

#ifdef VXWORKS

	#include <hostLib.h>
	#include <sockLib.h>

#endif

#ifdef WIN32

	typedef long STATUS ;

#endif

// Declare common error codes

#ifndef OK

	#define OK 0

#endif

#define SOCKET_CALL_FAILD 1001
#define BIND_CALL_FAILD 1002
#define THREAD_CALL_FAILD 1003

#define NOT_INITIALIZED -1001
#define CANNOT_SETMODE -1002
#define RECV_TIMEOUT -1003

// The class declaration.

// To get the detail information, please read UDPSOCKET.PDF or
// contact tief@mail.eastcomtd.com.

class CUdpSocket
{

public:

	// Enum possable work modes	
	
	enum workmode { auto_receive,user_receive } ;

	// Public functions for common operation

	// Constructures
	// -------------------------------------------------------------

	CUdpSocket() ;
	STATUS SetWorkMode(workmode wm = user_receive) ;
	STATUS Init(int localport,const char * targetip,int remoteport) ;

	// -------------------------------------------------------------

	// Common operation
	// -------------------------------------------------------------

	STATUS Send(int buflen,void * buf,sockaddr_in * addr = NULL) ;
	STATUS Recv(int buflen,void * buf,
		int timeout,sockaddr_in * addr = NULL) ;

	// -------------------------------------------------------------

	// Setting and getting attributes
	// -------------------------------------------------------------

	void SetRemoteAddr(const char * targetip,int port) ;
	const char * GetRemoteIp() ;
	int GetRemotePort() ;
	int GetLocalPort() ;
	STATUS SetSenderBufferSize(int size) ;
	int GetSenderBufferSize() ;
	STATUS SetReceiverBufferSize(int size) ;
	int GetReceiverBufferSize() ;
	int GetSenderSocket() ;
	int GetReceiverSocket() ;

	// -------------------------------------------------------------

	// Destruction
	// -------------------------------------------------------------

	virtual ~CUdpSocket() ;

	// -------------------------------------------------------------

	// Public functions for override
	// -------------------------------------------------------------

	virtual void OnInitComplete(STATUS status) ;
	virtual void OnBeforeSend(int buflen,void * buf) ;
	virtual void OnSendComplete(STATUS status) ;
	virtual void OnBeforeReceive
		(int buflen,void * buf,sockaddr_in * addr) ;
	virtual void OnReceive
		(int buflen,void * buf,sockaddr_in * addr) ;

private:

#ifdef WIN32

	HANDLE m_hThread ;

#endif

	static unsigned long recvsrv(void * pt) ;

#ifdef VXWORKS

	int m_hTask ; // VxWorks does not support threads

#endif

protected:

	bool m_bReady ;	int m_sockSender, m_sockReceiver ;
	sockaddr_in m_addrRemote, m_addrLocal, m_addrRecv ;
	timeval m_tvDelay ;	fd_set m_fdSel ;
	workmode m_wm ;

} ;

#endif // End of the file ...