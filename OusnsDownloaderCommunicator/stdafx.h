// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件:
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



// TODO: 在此处引用程序需要的其他头文件
