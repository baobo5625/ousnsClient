// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�:
#include <windows.h>
#include <iostream>
#include <boost/interprocess/windows_shared_memory.hpp>
//#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
//#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/thread/mutex.hpp>
#include "doc_anonymous_mutex_shared_data.hpp"

using namespace std;
using namespace boost::interprocess;


#define DLL_EXPORT  __declspec(dllexport)

#define DEBUG_DOWNLOADER false



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
