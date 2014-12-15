// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
#pragma once


#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>

#include <string>
//#include <exception>         // For exception class
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
//#include <winsock.h>         // For socket(), connect(), send(), and recv()
#include <algorithm>
#include <float.h>
#include <ctype.h>
#include <iostream>
#include <setjmp.h>
#include <wchar.h>
#include <vector>


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "udp.h"
#include "stun.h"
#include <udt.h>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;




#ifndef PUGIXML_NO_XPATH
#	include <math.h>
#	include <float.h>
#endif

#ifndef PUGIXML_NO_STL
#	include <istream>
#	include <ostream>
#endif
#include "pugixml.hpp"
using namespace pugi;
using namespace std;


#define DEBUG 0
#define DEBUG_DOWNLOADER_COMMUNICATION_THREAD 0
#define DEBUG_WORK_THREAD 0
#define DEBUG_COMMUNICATION_THREAD 0
#define DEBUG_SEND_THREAD 0
#define DEBUG_LISTEN_THREAD 0

//DLL import 
#define DLL_IMPORT __declspec(dllimport);
//��������Ϣ��
#define PORT_NUMBER 6000

#define UDP_RECV_PORT 11000
#define UDP_SEND_PORT 11001
//#define SERVER_ADDRESS L"project.koonooidc.com"
#define SERVER_ADDRESS L"50.23.110.101"
#define STUN_SERVER_ADDRESS "stunserver.org"
#define OUSNSDOWNLOADERPATH ".\\downloader.exe"
#define SERVER_PORT 50000
#define DEBUG_COMM 0
#define DEBUG_THREAD 0
#define DEBUG_PACKET 0
#define TIMEOUT_THRESHOLD 1500
#define RESEND_TIMES 3
#define HEARTBEAT_THREASHOLD 15000
#define THREAD_SLEEP_TIME 25

//define user folders
#define OUSNS_ROOT_PATH Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData)+"\\OuSns"
#define OUSNS_USER_PATH OUSNS_ROOT_PATH + "\\Users"
#define OUSNS_FILE_PATH OUSNS_ROOT_PATH + "\\FileCache"
#define OUSNS_TORRENT_PATH OUSNS_ROOT_PATH + "\\TorrentCache"
#define OUSNS_DOWNLOAD_PATH "C:\\OusnsDownload"
#define OUSNS_DOWNLOADING_LIST_FILENAME "OusnsDownloading.lst"
#define OUSNS_DOWNLOADED_LIST_FILENAME "OusnsDownloaded.lst"

//This does not include the length of file array and the files byte length
#define OUSNS_DOWNLOADING_JOB_LENGTH  2 * MAX_PATH + 4 * sizeof(int32_t) + 2* sizeof(int64_t)
#define OUSNS_DOWNLOADING_FILE_LENGTH 2 * MAX_PATH + 3 * sizeof(int32_t)

#define PARTIAL_MESSAGE_TIMEOUT 5000
#define P2P_TIMEOUT 1500
#define P2P_RESEND_TIME 1
#define SERVER_TIMEOUT 1500
#define SERVER_RESEND_TIME 3

#define ACK_PACKET_TIMEOUT 1000
#define ACK_PACKET_RESEND_TIME 1
#define IO_TASK_TIMEOUT 6000

#define COMM_VERSION "68"
#define RESIZEBORDERWIDTH 3

//Packet Related

//#define UDP_PACKET_HEADER_SIZE 14
#define PACKET_FUNCTION 1
#define CLIENT_NAT_TYPE 1
#define USERID_LENGTH 4
#define MESSAGE_NUMBER_LENGTH 4
#define CURRENT_PACKET_NUMBER_LENGTH 2
#define TOTAL_PACKET_NUMBER_LENGTH 2
#define RECEIVER_IPV4_LENGTH 4
#define RECEIVER_PORT_NUMBER_LENGTH 2

#define UDP_PACKET_HEADER_SIZE 20
#define UDP_PACKET_SIZE_LIMIT 492
#define SEARCH_RESULT_PAGE_LIMIT 20

#define CREATE_GROUP_LIMIT 5




//��Ϣ��ʾ��
//��¼��
#define LOGIN_INFORMATION_INCOMPLETED L"���������ĵ�¼��Ϣ"
#define LOGIN_INFORMATION_FORMAT_INCORRECT L"���������Ϣ������ȷ�ĸ�ʽ"
#define LOGOFF_FAILED L"�ǳ�ʧ��"
#define LOGIN_TYPE1 L"E-MAIL:"
#define LOGIN_TYPE2 L"Ou����:"
#define NONEXISTENT_USERNAME L"��������û���������"
#define LOCAL_USER L"��"
#define REMOTE_USER L"�Է��û�"
#define REJECT L"�ܾ�"
#define CANCEL L"ȡ��"
#define HALT_FILE_TRANSFER_ALERT_FIRST_HALF L"���ļ� "
#define HALT_FILE_TRANSFER_ALERT_SECOND_HALF L" �ķ��͡�"

//������
#define CAN_NOT_CREATE_SOCKET L"�����޷���������"
#define CAN_NOT_CONNECT_SERVER L"�����޷����ӵ�������"
#define SERVER_TIME_OUT L"�������ӷ�������ʱ"
#define CAN_NOT_PARSE_SERVER_RESPONSE L"����:�޷�������������Ӧ"

//���촰��
#define EMPTY_MESSAGE L"������ϢΪ�գ�����������"
#define SAYS_CHN L"˵��"
#define SAYS_ENG L"says:"


//�����ϱ���
#define TITLE_MENU1 L"�ļ�"
#define TITLE_MENU2 L"�༭"
#define TITLE_MENU3 L"����"
#define TITLE_MENU4 L"����"

#define SEARCH_ERROR_NOTIFICATION L"�����������ؼ���"

//�����б��ǩ
#define FRIEND_LIST_REMOVE_FRIEND L"��ȷ��Ҫɾ��������ϵ����"

//Ⱥ���б��ǩ
#define GROUP_LIST_DELETE_GROUP L"��ȷ��Ҫ��ɢ����Ⱥ����"
#define GROUP_LIST_EXIT_GROUP L"��ȷ��Ҫ�˳�����Ⱥ����"
//����Ⱥ���ǩ
#define CREATE_GROUP_GROUP_NAME_ERROR L"����дȺ������"
#define CREATE_GROUP_GROUP_DESCRIPTION_ERROR L"����дȺ������"
#define CREATE_GROUP_DEFAULT_GROUP_ANOUNANCEMENT L"��ӭ��Ҽ���"


//���Ѹ�����Ϣҳ
#define FRIEND_PERSONAL_INFO_BIRTHDAY_LABEL L"��"
#define FRIEND_PERSONAL_INFO_BIRTHMONTH_LABEL L"��"
#define SEX_MALE L"��"
#define SEX_FEMALE L"Ů"
#define SEX_UNKNOWN L"-"
#define ZODIAC_UNKNOWN L"-"
#define ZODIAC_ARIES L"������"
#define ZODIAC_TAURUS L"��ţ��"
#define ZODIAC_GEMINI L"˫����"
#define ZODIAC_CANCER L"��з��"
#define ZODIAC_LEO L"ʨ����"
#define ZODIAC_VIRGO L"��Ů��"
#define ZODIAC_LIBRA L"�����"
#define ZODIAC_SCORPIO L"��Ы��"
#define ZODIAC_SAGITTARIUS L"������"
#define ZODIAC_CAPRICORN L"Ħ����"
#define ZODIAC_AQUARIUS L"ˮƿ��"
#define ZODIAC_PISCES L"˫����"


//��������
#define DOWNLOADER_INVALID_PATH L"���ǺϷ���·��������Ŀ��Ŀ¼������"
#define DOWNLOADER_NOT_ENOUGH_SPACE L"Ŀ��Ŀ¼û���㹻��Ӳ�̿ռ�����������ļ�"



#include "OuSns.h"
//#include "doc_anonymous_mutex_shared_data.hpp"
//#include "DownloadingFile.h"
//#include "DownloadingJob.h"
//#include "SystemSetting.h"
#include "utils.h"
//#include "OusnsUser.h"
//#include "SharedObject.h"
//#include "SearchResult.h"

//#include "OusnsFriend.h"
//#include "OusnsGroupUser.h"
//#include "OusnsGroup.h"
//#include "OusnsLoginUser.h"
//#include "SharedFolder.h"
//#include "SharedFile.h"

#include "misc.h"

#include "OusnsMessage.h"
//#include "MessageCreator.h"
//#include "OusnsLoginUserSetting.h"
//#include "MessageProcessor.h"

//#include "friendChatDlg.h"
//#include "LoginDlg.h"
//#include "MainDlg1.h"
//#include "Communication.h"
//#include "PeerCommunication.h"



#include "ImageResource.h"
//#include "NotifyUserDlg.h"

using namespace OuSns;
//__declspec(dllimport) DownloaderCommunication *dc;