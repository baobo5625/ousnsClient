// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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


// TODO: 在此处引用程序需要的其他头文件
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
//服务器信息：
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




//信息提示：
//登录类
#define LOGIN_INFORMATION_INCOMPLETED L"请输入您的登录信息"
#define LOGIN_INFORMATION_FORMAT_INCORRECT L"您输入的信息不是正确的格式"
#define LOGOFF_FAILED L"登出失败"
#define LOGIN_TYPE1 L"E-MAIL:"
#define LOGIN_TYPE2 L"Ou号码:"
#define NONEXISTENT_USERNAME L"您输入的用户名不存在"
#define LOCAL_USER L"您"
#define REMOTE_USER L"对方用户"
#define REJECT L"拒绝"
#define CANCEL L"取消"
#define HALT_FILE_TRANSFER_ALERT_FIRST_HALF L"了文件 "
#define HALT_FILE_TRANSFER_ALERT_SECOND_HALF L" 的发送。"

//网络类
#define CAN_NOT_CREATE_SOCKET L"错误：无法建立连接"
#define CAN_NOT_CONNECT_SERVER L"错误：无法连接到服务器"
#define SERVER_TIME_OUT L"错误：连接服务器超时"
#define CAN_NOT_PARSE_SERVER_RESPONSE L"错误:无法解析服务器响应"

//聊天窗口
#define EMPTY_MESSAGE L"输入信息为空，请重新输入"
#define SAYS_CHN L"说："
#define SAYS_ENG L"says:"


//窗口上标题
#define TITLE_MENU1 L"文件"
#define TITLE_MENU2 L"编辑"
#define TITLE_MENU3 L"工具"
#define TITLE_MENU4 L"帮助"

#define SEARCH_ERROR_NOTIFICATION L"请输入搜索关键字"

//好友列表标签
#define FRIEND_LIST_REMOVE_FRIEND L"您确定要删除以下联系人吗？"

//群组列表标签
#define GROUP_LIST_DELETE_GROUP L"您确定要解散以下群组吗？"
#define GROUP_LIST_EXIT_GROUP L"您确定要退出以下群组吗？"
//建立群组标签
#define CREATE_GROUP_GROUP_NAME_ERROR L"请填写群组名称"
#define CREATE_GROUP_GROUP_DESCRIPTION_ERROR L"请填写群组描述"
#define CREATE_GROUP_DEFAULT_GROUP_ANOUNANCEMENT L"欢迎大家加入"


//好友个人信息页
#define FRIEND_PERSONAL_INFO_BIRTHDAY_LABEL L"日"
#define FRIEND_PERSONAL_INFO_BIRTHMONTH_LABEL L"月"
#define SEX_MALE L"男"
#define SEX_FEMALE L"女"
#define SEX_UNKNOWN L"-"
#define ZODIAC_UNKNOWN L"-"
#define ZODIAC_ARIES L"白羊座"
#define ZODIAC_TAURUS L"金牛座"
#define ZODIAC_GEMINI L"双子座"
#define ZODIAC_CANCER L"巨蟹座"
#define ZODIAC_LEO L"狮子座"
#define ZODIAC_VIRGO L"处女座"
#define ZODIAC_LIBRA L"天秤座"
#define ZODIAC_SCORPIO L"天蝎座"
#define ZODIAC_SAGITTARIUS L"射手座"
#define ZODIAC_CAPRICORN L"摩羯座"
#define ZODIAC_AQUARIUS L"水瓶座"
#define ZODIAC_PISCES L"双鱼座"


//下载器类
#define DOWNLOADER_INVALID_PATH L"不是合法的路径，或者目标目录不存在"
#define DOWNLOADER_NOT_ENOUGH_SPACE L"目标目录没有足够的硬盘空间来存放下载文件"



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