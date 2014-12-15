#pragma once

#include "stdafx.h"
#include "MessageProcessor.h"
#include "MessageCreator.h"
#include "LoginDlg.h"
#include "MainDlg1.h"
//#include "friendChatDlg.h"
#include "Communication.h"
//#include "OuSnsJobInfoDlg.h"
#include "AddOuSnsDownloadingJob.h"
#include "OusnsUserInfo.h"
#include "OusnsLoginUser.h"


using namespace OuSns;


LoginDlg::LoginDlg(){
	//
	//TODO: 在此处添加构造函数代码
	//
	//OuSnsJobInfoDlg^ jobInfo = gcnew OuSnsJobInfoDlg();
	//jobInfo->Show();
	//AddOuSnsDownloadingJob^ addJob = gcnew AddOuSnsDownloadingJob();
	//addJob->ShowDialog();
	//OusnsUserInfo^ infoDlg = gcnew OusnsUserInfo();
	//infoDlg->ShowDialog();
	ressrc = L"OuSns.ImageResource";
	execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
	myres = gcnew Resources::ResourceManager(ressrc,execAssem);
	InitializeComponent();
	_userID = L"";
	_password = L"";
	_userIDType = L"";
	this->loginType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {LOGIN_TYPE1, LOGIN_TYPE2});
	this->loginType->SelectedIndex=0;

	this->comm = gcnew Communication(this);
	this->msgProcessor = this->comm->msgProcessor;
	this->workThreadStarted = false;
	loggedIn = false;
	isDown = false;
	this->loactionStyle = OuSns::S22_MIDDLECENTER;
	//this->LastMoustLocation = Point(0,0);
	/* 
	 * Initial the images
	 */
	this->minimizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_highlight")));
	this->minimizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_normal")));
	this->minimizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_down")));
	this->maximizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_highlight")));
	this->maximizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_normal")));
	this->maximizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_down")));
	this->closeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_highlight")));
	this->closeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_normal")));
	this->closeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_down")));

	this->newUser = false;
	this->macAddressArray = this->GetMACAddress();
	//this->GetLoginHistory();

}
/*
 * This function will verify the input information.
 */
bool LoginDlg::RegularExpressionVerification(int loginType, String^ pattern)
{
	//用正则表达式检测
	
	if (this->loginType->SelectedIndex == 0){
		 //create the email match pattern
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^([0-9a-zA-Z]([-\\.\\w]*[0-9a-zA-Z])*@([0-9a-zA-Z][-\\w]*[0-9a-zA-Z]\\.)+[a-zA-Z]{2,9})$");
		System::Text::RegularExpressions::Match^ match = regex->Match(pattern);
		return match->Success;
	}
	else{
		 //Create the OuID match pattern
		 
		 System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^([0-9a-zA-Z])+$");
		 System::Text::RegularExpressions::Match^ match = regex->Match(pattern);
		 return match->Success;
	}
	
}

/*
 * Start the login process
 * This function will first initiate a communication instance,
 * then it will send the login information and wait for the response.
 * If the response is timeout, then send the request again.
 * Then the funtion will initiate 3 new thread that working on 3 different
 * functions in the communication class.
 */
System::Void LoginDlg::LoginButton_Click(System::Object^  sender, System::EventArgs^  e) {
	DisableButtons(false);
	
	if (this->loginType->Text == LOGIN_TYPE1){

	}
	this->cancelButton->Text = L"取消";
	if(this->loginId->Text->Length == 0 || this->loginPassword->Text->Length == 0){
		MessageBox::Show(LOGIN_INFORMATION_INCOMPLETED);
		 DisableButtons(true);
		 this->cancelButton->Text = L"退出";
	 }
	else if (!this->RegularExpressionVerification(this->loginType->SelectedIndex,this->loginId->Text)){
		MessageBox::Show(LOGIN_INFORMATION_FORMAT_INCORRECT);
		DisableButtons(true);
		this->cancelButton->Text = L"退出";
	}
	else{
		 if (this->loginType->Text == LOGIN_TYPE1){
			 _userIDType = L"Email";
		 }
		 else{
			 _userIDType = L"OuID";
		 }
		  _userID = this->loginId->Text;
		 _password = this->loginPassword->Text;

		try{
			
			this->userNatType = this->GetNatType();
			//this->comm = gcnew Communication(this);
			if(this->workThreadStarted == false)
				StartWorkThread();
			
			this->comm->EnableListenFunction(true);
			
			OusnsMessage^ loginMsg = this->comm->msgCreator->
				MakeLoginMessage(_userID,_password,_userIDType,this->comm->serverAddr,this->comm->serverPort,macAddressArray,OuSns::ONLINE,this->userNatType);
			this->comm->AddToWorkQueue(loginMsg);

		} catch (Exception ^ e) {
			 MessageBox::Show(e->ToString());
		}
	 }
 }

 System::Void LoginDlg::CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

	 if (this->cancelButton->Text == L"取消") {
		//this->backgroundWorker1->CancelAsync();
		 this->comm->EnableListenFunction(true);
		 DisableButtons(true);
		this->cancelButton->Text = L"退出";
	 } else {
		 if (this->workThreadStarted ) {
			 this->comm->isListenThreadRunning = false;
			 this->comm->listenThread->Join(1000);
			 this->comm->isWorkThreadRunning = false;
			 this->comm->workThread->Join(1000);
			 this->comm->isSendThreadRunning = false;
			 this->comm->sendThread->Join(1000);
			 this->comm->isCommunicationThreadRunning = false;
			 this->comm->communicationThread->Join(1000);
			 this->comm->isDownloaderCommunicationThreadRunning = false;
			 this->comm->downloaderCommunicatonThread->Join(1000);
		 }
		 Application::Exit();
	 }
 }


void LoginDlg::DisableButtons(bool flag){
	this->panelEx1->SuspendLayout();
	this->loginType->Enabled = flag;
	this->loginId->Enabled = flag;
	this->loginPassword->Enabled = flag;
	this->remember->Enabled = flag;
	this->loginButton->Enabled = flag;
	this->panelEx1->ResumeLayout();
	this->panelEx1->PerformLayout();
}

System::Void LoginDlg::StartWorkThread(){

	
	ThreadStart^ workThreadStart = gcnew ThreadStart(this->comm,&Communication::WorkThread);
	this->comm->workThread = gcnew Thread(workThreadStart);
	this->comm->workThread->Name = L"Work Thread";
	this->comm->workThread->Priority = ThreadPriority::AboveNormal;
	this->comm->workThread->Start();
	this->workThreadStarted = true;
}

System::Void LoginDlg::LoginErrorNotification(String^ notification){
	MessageBox::Show(notification);
	this->DisableButtons(true);
	this->cancelButton->Text = L"退出";
}


/*
 * This funtion will continue the login procesure
 */
System::Void LoginDlg::ContinueLogin(OusnsLoginUser^ usr){
	try{

		if(!this->loggedIn){
			this->loggedIn = true;
			if(!Directory::Exists(usr->localProfilePath)){
				Directory::CreateDirectory(usr->localProfilePath);
			}
			if(this->remember->Checked){
				this->SaveUserInfoToFile(usr);
			}

			OuSns::MainDlg^ mainDlg = gcnew OuSns::MainDlg(usr, this->comm);
			//this->mainDlg = mainDlg;
			this->Hide();
			//this->mainDlg->Show();
			//OuSns::MainDlg^ mainDlg = gcnew OuSns::MainDlg();
			//this->mainDlg = mainDlg;
			this->Hide();
			mainDlg->Show();
			//this->mainDlg->Show();
		}
		
	 } 
	catch (KeyNotFoundException ^) {
		MessageBox::Show(NONEXISTENT_USERNAME);
		DisableButtons(true);
		this->cancelButton->Text = L"退出";
	}
}

LinkedList<String^>^ LoginDlg::GetMACAddress(void){
	LinkedList<String^>^ returnList = gcnew LinkedList<String^>();

	IP_ADAPTER_INFO *info = nullptr, *pos;
	DWORD error_code,size = 0;
	//PULONG size=0;
	GetAdaptersInfo(info,&size);
	info = (IP_ADAPTER_INFO *)malloc(size);
	error_code = GetAdaptersInfo(info,&size);
	if(error_code == ERROR_BUFFER_OVERFLOW){
		MessageBox::Show(L"buffer over flow");
	}
	else if (error_code == ERROR_INVALID_DATA){
		MessageBox::Show(L"buffer invalid data");
	}
	else if (error_code == ERROR_INVALID_PARAMETER){
		MessageBox::Show(L"buffer invalid parameter");
	}
	else if (error_code == ERROR_NO_DATA){
		MessageBox::Show(L"no data ");
	}
	else if (error_code == ERROR_NOT_SUPPORTED){
		MessageBox::Show(L"not supported");
	}
	String^ tempAddress;
	char* srNo = (char *)malloc(sizeof(info->Address[0]) * info->AddressLength);
	for(pos = info;pos!= NULL; pos = pos->Next){
		//tempAddress = gcnew String(pos->Address);
		tempAddress = "";
		for(UINT i = 0; i < pos->AddressLength;i++){
			
			sprintf(srNo,"%.2X",(int)pos->Address[i]);
			tempAddress = tempAddress +  AnsiToManagedString (srNo);
		}
		
		//BitConverter::ToString(pos->Address,0,(int)pos->AddressLength);

		returnList->AddLast(tempAddress);
	}
	free(info);
	free(srNo);

	return returnList;
}
/*
 * This function will communicate with the stun server and get the nat type of current user
 */
OuSns::NatType LoginDlg::GetNatType(){
	initNetwork();

	StunAddress4 stunServerAddr;
	stunServerAddr.addr=0;
	char* serverAddr = STUN_SERVER_ADDRESS;
	stunParseServerName(serverAddr, stunServerAddr);
	StunAddress4 sAddr[1];
	int srcPort = stunRandomPort();

	StunNatType stype;
	bool presPort=false;
	bool hairpin=false;
	bool verbose = false;

	sAddr[0].addr=0; 
	sAddr[0].port=srcPort;
	 
	stype = stunNatType( stunServerAddr, verbose, &presPort, &hairpin, 
                                      srcPort, &sAddr[0]);
	switch (stype)
         {
            case StunTypeFailure:
				return OuSns::StunTypeFailure;
            case StunTypeUnknown:
				return OuSns::StunTypeUnknown;
            case StunTypeOpen:
				return OuSns::StunTypeOpen;
            case StunTypeIndependentFilter:
				return OuSns::StunTypeIndependentFilter;
            case StunTypeDependentFilter:
				return OuSns::StunTypeDependentFilter;
            case StunTypePortDependedFilter:
				return OuSns::StunTypePortDependedFilter;
            case StunTypeDependentMapping:
				return OuSns::StunTypeDependentMapping;
            case StunTypeFirewall:
				return OuSns::StunTypeFirewall;
            case StunTypeBlocked:
				return OuSns::StunTypeBlocked;
            default:
				return OuSns::StunTypeUnknown;
         }
	return OuSns::StunTypeUnknown;
}

System::Void LoginDlg::GetLoginHistory(void){
	array<String^>^ subDirs = Directory::GetDirectories(OUSNS_USER_PATH);
	String^ subDir;
	this->loginId->Items->Clear();
	DevComponents::Editors::ComboItem^  comboItem;
	for each(subDir in subDirs){
		array<String^>^ splitResult = subDir->Split(gcnew array<wchar_t>{'\\'});
		String^ tempID = splitResult[splitResult->Length -1];
		if(this->RegularExpressionVerification(this->loginType->SelectedIndex,tempID)){
			comboItem = (gcnew DevComponents::Editors::ComboItem());
			comboItem->Text = tempID;
			this->loginId->Items->Add(comboItem);
		}
	}
	if (this->loginId->Items->Count){
		this->loginId->SelectedIndex = 0;
	}

	
}

System::Void LoginDlg::SaveUserInfoToFile(OusnsLoginUser^ usr){
	//Can use byte to represent string
	
	if(!Directory::Exists(usr->localProfilePath)){
		Directory::CreateDirectory(usr->localProfilePath);
	}
	if(File::Exists(usr->localProfilePath + "\\data"))
		File::Delete(usr->localProfilePath + "\\data");
	FileStream^ fs = File::Create(usr->localProfilePath + "\\data");
	
	String^ writeContent =  ((int)usr->userID).ToString() + " " + usr->email + " " + this->_password;
	array<Byte>^writeContentArray = (gcnew UTF8Encoding( true ))->GetBytes(writeContent);
	fs->Write(writeContentArray,0,writeContentArray->Length);
	fs->Close();
	return;
}

System::Void LoginDlg::ReadUserInfoFromFile(String^ path){
	if(Directory::Exists(path)){
		
		/*
		array<String^>^ subDirs = Directory::GetDirectories(path);
		String^ subDir;
		String^ latestDir;
		DateTime^ accessTime = gcnew DateTime(DateTime::MinValue.Ticks);
		DateTime^ currentAccessTime;
		for each(subDir in subDirs){
			currentAccessTime = Directory::GetLastAccessTime(subDir);
			if (currentAccessTime->CompareTo(accessTime) > 0){
				latestDir = subDir;
				accessTime = currentAccessTime;
			}

		}
		*/
		String^ filePath = path+ "\\data";
		if(File::Exists(filePath)){
			StreamReader^ sr = File::OpenText(path+"\\data");
			String^ fileContent = sr->ReadLine();
			array<String^>^ splitResult = fileContent->Split(gcnew array<wchar_t>{' '});
			if(this->loginType->SelectedIndex == 0){
				//Put on the email address
				this->loginId->Text = splitResult[1];
			}
			else{
				this->loginId->Text = splitResult[0];
			}
			this->loginPassword->Text = splitResult[2];
			this->remember->Checked = true;
			sr->Close();
			this->newUser = false;
		}

	}
}

System::Void LoginDlg::panelEx1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	 Point mouseLocation = Point(Control::MousePosition.X - this->Location.X, Control::MousePosition.Y - this->Location.Y);
	 isDown = true;
	 if (this->Cursor != ::Cursors::Default){
		 //int direction = OuSns::ChangeSize(mouseLocation, this->loactionStyle,this);
		 OuSns::ChangeSize(mouseLocation, this->loactionStyle,this);
	 } 
 }

System::Void LoginDlg::panelEx1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	 Point mouseLocation = Point(Control::MousePosition.X - this->Location.X, Control::MousePosition.Y - this->Location.Y);
	 this->loactionStyle = OuSns::GetLocationStyle(mouseLocation,this);
	 this->Cursor = OuSns::GetCursorByMouseLocationStyle(this->loactionStyle);
	 if(this->isDown &&  (Control::MousePosition.Y - this->Location.Y < 30) ){
		 ReleaseCapture();
		 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MOVE+HTCAPTION,0);
	 }
}

System::Void LoginDlg::panelEx1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	 this->loactionStyle = OuSns::S22_MIDDLECENTER;
	 this->Cursor = ::Cursors::Default;
	 this->isDown = false;
}

System::Void LoginDlg::closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

System::Void LoginDlg::maximizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 ReleaseCapture();
	 if(IsZoomed((HWND)this->Handle.ToPointer())){
		 SendMessage(this->Handle,WM_SYSCOMMAND, SC_RESTORE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
		 this->SuspendLayout();
		 this->maximizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_highlight")));
		 this->maximizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_normal")));
		 this->maximizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_max_down")));
		 this->ResumeLayout(false);
	 }
	 else{
		 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MAXIMIZE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
		 this->SuspendLayout();
		 this->maximizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_highlight")));
		 this->maximizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_normal")));
		 this->maximizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_restore_down")));
		 this->ResumeLayout(false);
		 //Invalidate();
	 }
 }

System::Void LoginDlg::minimizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	 ReleaseCapture();
	 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MINIMIZE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
	 //Invalidate();
 }


System::Void LoginDlg::loginId_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->ReadUserInfoFromFile(OUSNS_USER_PATH + "\\" + this->loginId->Text);
	
}

System::Void LoginDlg::loginId_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	 if(!this->newUser){
		this->loginPassword->Text = L"";
		this->newUser = true;
	 }
	 this->ReadUserInfoFromFile(OUSNS_USER_PATH + "\\" + this->loginId->Text);
 }