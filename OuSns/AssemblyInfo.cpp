#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// �йس��򼯵ĳ�����Ϣͨ���������Լ�
// ���ơ�������Щ����ֵ���޸�
// ����򼯹�������Ϣ��
//
[assembly:AssemblyTitleAttribute("OuSns")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("China")];
[assembly:AssemblyProductAttribute("OuSns")];
[assembly:AssemblyCopyrightAttribute("Copyright (c) China 2011")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//
// ���򼯵İ汾��Ϣ�������ĸ�ֵ���:
//
//      ���汾
//      �ΰ汾
//      �ڲ��汾��
//      �޶���
//
// ������ָ������ֵ��Ҳ��ʹ�á��޶��š��͡��ڲ��汾�š���Ĭ��ֵ��
// �����ǰ�������ʾʹ�á�*��:

[assembly:AssemblyVersionAttribute("1.0.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

[assembly:SecurityPermission(SecurityAction::RequestMinimum, UnmanagedCode = true)];