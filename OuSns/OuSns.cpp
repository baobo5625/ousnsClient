// OuSns.cpp: 主项目文件。
#include "OuSns.h"
#include "stdafx.h"
//#include "DownloaderCommunication.h"
#include "LoginDlg.h"
#include "Communication.h"
#include "SystemMessageErrorInfoDlg.h"
#include "SystemMessageNotificationDlg.h"
#include "NotifyUserDlg.h"
#pragma comment(lib,"..\\lib\\OusnsDownloaderCommunicator.lib")
#include "..\\include\\DownloaderCommunication.h"

//__declspec(dllimport) DownloaderCommunication *dc;
using namespace OuSns;
[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	// 创建主窗口并运行它
	//DownloaderCommunication^ downloaderCommunicate = gcnew DownloaderCommunication();
	//downloaderCommunicate->OusnsDownloaderInfoExtractionStarter();


	if(Directory::Exists(OUSNS_ROOT_PATH) == false){
		Directory::CreateDirectory(OUSNS_ROOT_PATH);
	}
	if(Directory::Exists(OUSNS_DOWNLOAD_PATH) == false){
		Directory::CreateDirectory(OUSNS_DOWNLOAD_PATH);
	}
	if(Directory::Exists(OUSNS_USER_PATH) == false){
		Directory::CreateDirectory(OUSNS_USER_PATH);
	}
	if(Directory::Exists(OUSNS_FILE_PATH) == false){
		Directory::CreateDirectory(OUSNS_FILE_PATH);
	}
	if(Directory::Exists(OUSNS_TORRENT_PATH) == false){
		Directory::CreateDirectory(OUSNS_TORRENT_PATH);
	}
	if(Directory::Exists(OUSNS_DOWNLOAD_PATH) == false){
		Directory::CreateDirectory(OUSNS_DOWNLOAD_PATH);
	}
	/*
	NotifyUserDlg^ dlg = gcnew NotifyUserDlg(OuSns::WARNING_DLG,L"确定");
	DialogResult ddr = dlg->ShowDialog();
	MessageBox::Show(((int)ddr).ToString());
	*/
	
	
	//DownloaderCommunication *dc = new DownloaderCommunication();
	
	LoginDlg^ loginDlg = gcnew LoginDlg();
	Application::Run(loginDlg);
	return 0;
}

OuSns::MouseLocationStyle OuSns::GetLocationStyle(Point^ mouseLocation, Form^ form){
            //左上
            if (mouseLocation->X <= RESIZEBORDERWIDTH &&
                mouseLocation->Y <= RESIZEBORDERWIDTH)
            {

				return OuSns::S11_LEFTTOP;
            }

            //中上
            if (mouseLocation->X > RESIZEBORDERWIDTH &&
                mouseLocation->X <= (form->Width -RESIZEBORDERWIDTH ) &&
                mouseLocation->Y <= RESIZEBORDERWIDTH)
            {
				return OuSns::S12_CENTERTOP;
            }

            //右上
            if (mouseLocation->X > (form->Width - RESIZEBORDERWIDTH) &&
                mouseLocation->Y <= RESIZEBORDERWIDTH)
            {
				return OuSns::S13_RIGHTTOP;
            }

            //左中
            if (mouseLocation->X <= RESIZEBORDERWIDTH &&
                mouseLocation->Y > RESIZEBORDERWIDTH &&
                mouseLocation->Y <= (form->Height - RESIZEBORDERWIDTH))
            {
				return OuSns::S21_MIDDLELEFT;
            }

            //中中
            if (mouseLocation->X > RESIZEBORDERWIDTH &&
                mouseLocation->X <= (form->Width - RESIZEBORDERWIDTH) &&
                mouseLocation->Y > RESIZEBORDERWIDTH &&
                mouseLocation->Y <= (form->Height - RESIZEBORDERWIDTH))
            {
				return OuSns::S22_MIDDLECENTER;
            }

            //右中
            if (mouseLocation->X > (form->Width - RESIZEBORDERWIDTH) &&
                mouseLocation->Y > RESIZEBORDERWIDTH &&
                mouseLocation->Y <= (form->Height - RESIZEBORDERWIDTH))
			{
				//ReleaseCapture();
				//SendMessage((HWND)form->Handle.ToPointer(),WM_SYSCOMMAND, SC_SIZE|WMSZ_RIGHT,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
				return OuSns::S23_MIDDLERIGHT;
            }

            //左下
            if (mouseLocation->X <= RESIZEBORDERWIDTH 
                &&mouseLocation->Y>(form->Height-RESIZEBORDERWIDTH))
            {
				return OuSns::S31_LEFTBOTTOM;
            }

            //中下
            if (mouseLocation->X > RESIZEBORDERWIDTH &&
                mouseLocation->X <= (form->Width - RESIZEBORDERWIDTH) &&
                mouseLocation->Y > (form->Height - RESIZEBORDERWIDTH))
            {
				return OuSns::S32_CENTERBOTTOM;
            }

            //右下
            if (mouseLocation->X > (form->Width - RESIZEBORDERWIDTH)&&
                mouseLocation->Y>(form->Height - RESIZEBORDERWIDTH))
            {
				return OuSns::S33_RIGHTBOTTOM;
            }

			return OuSns::S22_MIDDLECENTER;
		}
	   /// <summary>
        /// 根据鼠标位置类型，返回鼠标光标类型
        /// </summary>
        /// <param name="mouseStyle">鼠标位置类型</param>
        /// <returns>鼠标光标类型</returns>

::Cursor^ OuSns::GetCursorByMouseLocationStyle(MouseLocationStyle mouseStyle)
        {
            switch (mouseStyle)
            {
                case OuSns::S11_LEFTTOP:
					return Cursors::SizeNWSE;
                case OuSns::S12_CENTERTOP:
					return Cursors::SizeNS;
                case OuSns::S13_RIGHTTOP:
					return Cursors::SizeNESW;
                case OuSns::S21_MIDDLELEFT:
					return Cursors::SizeWE;
                case OuSns::S22_MIDDLECENTER:
					return Cursors::Default;
                case OuSns::S23_MIDDLERIGHT:
					return Cursors::SizeWE;
                case OuSns::S31_LEFTBOTTOM:
					return Cursors::SizeNESW;
                case OuSns::S32_CENTERBOTTOM:
					return Cursors::SizeNS;
                case OuSns::S33_RIGHTBOTTOM:
					return Cursors::SizeNWSE;
                default:
					return Cursors::Default;
            }
        }

/*
    * This function will modify the form location and change the size of the form
	*/
System::Void OuSns::ChangeSize(Point mouseLocation, MouseLocationStyle mouseStyle,Form^ form)
        {
			int direction = -1;
            switch (mouseStyle)
            {
				case OuSns::S11_LEFTTOP:
                    //左上
					direction = HTTOPLEFT;
                    form->Location = Point(form->Location.X + mouseLocation.X, form->Location.Y + mouseLocation.Y);
                    break;
                case OuSns::S12_CENTERTOP:
                    //中上
					direction = HTTOP;
                    form->Location = Point(form->Location.X, form->Location.Y + mouseLocation.Y);
                    break;
                case OuSns::S13_RIGHTTOP:
                    //右上
					direction = HTTOPRIGHT;
                    form->Location=Point(form->Location.X,form->Location.Y + mouseLocation.Y);
                    break;
                case OuSns::S21_MIDDLELEFT:
                    //左中
                    //newSize.Width -= mouseLocation.X;
					direction = HTLEFT;
                    form->Location = Point(form->Location.X + mouseLocation.X, form->Location.Y);
                    break;
                case OuSns::S22_MIDDLECENTER:
                    //中中【无需调整】
                    break;
                case OuSns::S23_MIDDLERIGHT:
                    //中右
					direction = HTRIGHT;
                    break;
                case OuSns::S31_LEFTBOTTOM:
                    //左下
					direction = HTBOTTOMLEFT;
                    form->Location = Point(form->Location.X + mouseLocation.X, form->Location.Y);
                    break;
                case OuSns::S32_CENTERBOTTOM:
                    //中下
					direction = HTBOTTOM;
                    break;
                case OuSns::S33_RIGHTBOTTOM:
                    //右下
					direction = HTBOTTOMRIGHT;
                    break;
            }
			ReleaseCapture();
			SendMessage((HWND)form->Handle.ToPointer(), WM_NCLBUTTONDOWN, direction, MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
		
			
        }

DialogResult OuSns::SysMsgNotificationBlocking(String^ contentInput){
	SystemMessageNotificationDlg^ dlg;
	DialogResult ddr = DialogResult::OK;
	dlg = gcnew SystemMessageNotificationDlg(contentInput);
	ddr = dlg->ShowDialog();
	return ddr;
}

System::Void OuSns::SysMsgNotificationNonBlocking(String^ contentInput){
	array<Object ^>^ args = gcnew array<Object^>(1){contentInput};
	Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(OuSns::SysMsgNotificationThread));
	thread->Name = L"SysMsgNotification";
	thread->Start(args);
}

System::Void OuSns::SysMsgNotificationThread(Object^ params){
	array<Object^>^ args = safe_cast<array<Object^>^>(params);
	String^ contentInput = safe_cast<String^>(args[0]);

	SystemMessageNotificationDlg^ dlg;
	DialogResult ddr = DialogResult::OK;
	dlg = gcnew SystemMessageNotificationDlg(contentInput);
	ddr = dlg->ShowDialog();
	return;
}

DialogResult OuSns::SysMsgErrorInfoBlocking(String^ contentInput){
	SystemMessageErrorInfoDlg^ dlg;
	DialogResult ddr = DialogResult::OK;
	dlg = gcnew SystemMessageErrorInfoDlg(contentInput);
	ddr = dlg->ShowDialog();
	return ddr;
}

System::Void OuSns::SysMsgErrorInfoNonBlocking(String^ contentInput){
	array<Object ^>^ args = gcnew array<Object^>(1){contentInput};
	Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(OuSns::SysMsgErrorInfoThread));
	thread->Name = L"SysMsgErrorInfo";
	thread->Start(args);
}

System::Void OuSns::SysMsgErrorInfoThread(Object^ params){
	array<Object^>^ args = safe_cast<array<Object^>^>(params);
	String^ contentInput = safe_cast<String^>(args[0]);

	SystemMessageErrorInfoDlg^ dlg;
	DialogResult ddr = DialogResult::OK;
	dlg = gcnew SystemMessageErrorInfoDlg(contentInput);
	ddr = dlg->ShowDialog();
	return;
}

/*
* This function will pop up a dialog and asking user a question
* the bubtonText array will decide how many buttons will be shown on the dialog
* and also the button texts.
* It will take 1 to 3 buttons, the first butotn is accept button,
* the second button is refuse button and the third button is ignore button.
* the type will decide what does the picture box look like
*/
DialogResult OuSns::NotifyUIBlocking(OuSns::NotifyUIDlgType type,String^ contentInput,array<String^>^ buttonText){
	NotifyUserDlg^ notifyDlg;
	String^ acceptButtonText;
	String^ refuseButtonText;
	String^ ignoreButtonText;
	DialogResult ddr = DialogResult::Ignore;
	switch (buttonText->Length){
		case 1:
			acceptButtonText = buttonText[0];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 2:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[2];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 3:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[2];
			ignoreButtonText = buttonText[3];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,ignoreButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		default:
			break;
	}
	return ddr;

}

/*
* This function will start up a new dialog that does not blocking the current UI thread
* The runningObject 
*/

System::Void OuSns::NewDialogNonBlocking(Object^ runningObject,Object^ args){
	Thread^ dialogThread = gcnew Thread(gcnew ParameterizedThreadStart(OuSns::NotifyUIThread));
	dialogThread->Name = L"NewDialogThread";
	dialogThread->Start(args);
}

/*
* This is the non blocking version of previous function
* This function will insert an INTERNAL message into the work queue
* and the message processor with the correspondent action type
* will process the message (decide if need to continue)
*/
System::Void OuSns::NotifyUINonBlocking(OuSns::NotifyUIDlgType type,String^ contentInput,
			array<String^>^ buttonText, OuSns::ActionType actionType,String^ messageID, 
			String^ messageContent,IPAddress^ destIP, unsigned short destPort,Communication^ comm){

	array<Object ^>^ args = gcnew array<Object^>(9){(int)type,
		contentInput,buttonText,(int)actionType,messageID,messageContent,destIP, destPort,comm};
	//ParameterizedThreadStart ^ notifyUIThreadStart = gcnew ParameterizedThreadStart(comm, &OuSns::NotifyUIThread);
	Thread^ notifyUIThread = gcnew Thread(gcnew ParameterizedThreadStart(OuSns::NotifyUIThread));
	notifyUIThread->Name = L"NotifyUIThread";
	notifyUIThread->Start(args);
}

/*
* This is the running thread for the previous function
*/
System::Void OuSns::NotifyUIThread(Object^ params){
	array<Object^>^ args = safe_cast<array<Object^>^>(params);
	OuSns::NotifyUIDlgType type = (OuSns::NotifyUIDlgType)(safe_cast<int>(args[0]));
	String^ contentInput = safe_cast<String^>(args[1]);
	array<String^>^ buttonText = safe_cast<array<String^>^>(args[2]);
	OuSns::ActionType actionType = (OuSns::ActionType)(safe_cast<int>(args[3]));
	String^ messageID = safe_cast<String^>(args[4]);
	String^ messageContent = safe_cast<String^>(args[5]);
	IPAddress ^ destIP = safe_cast<IPAddress^>(args[6]);
	unsigned short destPort = safe_cast<unsigned short>(args[7]);
	Communication^ comm = safe_cast<Communication^>(args[8]);

	NotifyUserDlg^ notifyDlg;
	String^ acceptButtonText;
	String^ refuseButtonText;
	String^ ignoreButtonText;
	DialogResult ddr = DialogResult::Ignore;
	switch (buttonText->Length){
		case 1:
			acceptButtonText = buttonText[0];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 2:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[1];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 3:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[1];
			ignoreButtonText = buttonText[2];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,ignoreButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		default:
			break;
	}

	OusnsMessage^ msg = gcnew OusnsMessage(OuSns::WORK,OuSns::WORK,
		OuSns::INTERNALMSG, (int) ddr, messageID, actionType, messageContent,
		destIP,destPort,false);
	comm->AddToWorkQueue(msg);
	return;
}


/*
* This is the user status from int to string 
*/
String^ OuSns::UserStatusIntToString(OuSns::UserStatus status){
	switch (status){
		case OuSns::OFFLINE:
			return L"Offline";
		case OuSns::ONLINE:
			return L"Online";
		case OuSns::AWAY:
			return L"Away";
		case OuSns::BUSY:
			return L"Busy";
		case OuSns::INVISIBLE:
			return L"Invisible";
		default:
			return L"Offline";
	}
}
/*
* This is the non blocking version of previous function
* This function will inser the message into work queue if the answer is yes
* This function will take 2 buttons ONLY
*/
System::Void OuSns::NotifyUINonBlockingMsg(OuSns::NotifyUIDlgType type,String^ contentInput,\
	array<String^>^ buttonText,OusnsMessage^ msg,Communication^ comm){
	array<Object ^>^ args = gcnew array<Object^>(5){(int)type,contentInput,buttonText,msg,comm};
	//ParameterizedThreadStart ^ notifyUIThreadStart = gcnew ParameterizedThreadStart(comm, &OuSns::NotifyUIThread);
	Thread^ notifyUIThread = gcnew Thread(gcnew ParameterizedThreadStart(OuSns::NotifyUIThreadMsg));
	notifyUIThread->Name = L"NotifyUIThreadMsg";
	notifyUIThread->Start(args);
}


/*
* This is the running thread for the previous function
*/
System::Void OuSns::NotifyUIThreadMsg(Object^ params){
	array<Object^>^ args = safe_cast<array<Object^>^>(params);
	OuSns::NotifyUIDlgType type = (OuSns::NotifyUIDlgType)(safe_cast<int>(args[0]));
	String^ contentInput = safe_cast<String^>(args[1]);
	array<String^>^ buttonText = safe_cast<array<String^>^>(args[2]);
	OusnsMessage^ msg = safe_cast<OusnsMessage^>(args[3]);
	Communication^ comm = safe_cast<Communication^>(args[4]);

	NotifyUserDlg^ notifyDlg;
	String^ acceptButtonText;
	String^ refuseButtonText;
	String^ ignoreButtonText;
	DialogResult ddr = DialogResult::Ignore;
	switch (buttonText->Length){
		case 1:
			acceptButtonText = buttonText[0];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 2:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[1];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		case 3:
			acceptButtonText = buttonText[0];
			refuseButtonText = buttonText[1];
			ignoreButtonText = buttonText[2];
			notifyDlg = gcnew NotifyUserDlg(type,acceptButtonText,refuseButtonText,ignoreButtonText,contentInput);
			ddr = notifyDlg->ShowDialog();
			break;
		default:
			break;
	}

	if (ddr == ::DialogResult::Yes)
		comm->AddToWorkQueue(msg);
	return;
}