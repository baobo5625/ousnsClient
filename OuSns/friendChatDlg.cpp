#include "StdAfx.h"
#include "FriendChatDlg.h"
#include "Communication.h"
#include "FriendListTab.h"
#include "MessageCreator.h"
#include "OusnsFriend.h"
#include "OusnsLoginUser.h"

using namespace OuSns;

friendChatDlg::friendChatDlg(FriendListTab ^ parent, OusnsFriend ^ targetFriend, OusnsLoginUser ^ loginUser)
	{

		//Common part
		ressrc = L"OuSns.ImageResource";
		execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
		myres = gcnew Resources::ResourceManager(ressrc,execAssem);
		this->isDown = false;
		this->loactionStyle = OuSns::S22_MIDDLECENTER;

		InitializeComponent();
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
		this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexright_normal")));

		_friend = targetFriend;
		_login_usr = loginUser;
		this->parent = parent;
		//this->pictureBox1->Image = System::Drawing::Image::FromFile(targetFriend->displayPictureFilename);
		this->friendNicknameLabelX->Text = targetFriend->nickname;
		this->friendSignatureLabelX->Text = targetFriend->signature;
		this->fileTransferJobPanelList = gcnew Dictionary<String ^, DirectTransferFile ^>();
		this->fileTransferPortList = gcnew LinkedList<FileTransferPort ^>();

		//
		//TODO: 在此处添加构造函数代码
		//
		
		sidePanelDisplayed = true;
		

		//Make the background as transparent.
		this->LastMoustLocation = Point(0,0);
		this->SetStyle(ControlStyles::UserPaint,true);
		this->SetStyle(ControlStyles::OptimizedDoubleBuffer,true);
		this->SetStyle(ControlStyles::DoubleBuffer,true);
		this->SetStyle(ControlStyles::AllPaintingInWmPaint,true);
		this->Text = _friend->nickname;

		

	}


System::Void friendChatDlg::friendChatDlg_Send(System::Object^  sender, System::EventArgs^  e) {

	if (this->friendMessageEntry->Text == L"") {
		MessageBox::Show(EMPTY_MESSAGE);
		return;
	}
	String ^ text = this->friendMessageEntry->Rtf;
	unsigned int srcID = this->_login_usr->userID;
	IPAddress ^ destIP = this->_friend->ipAddr;
	unsigned short destPort = this->_friend->recvPort;
	//this->parent->comm->SendPeerMessage(text, srcID, destIP, destPort,this->_friend->natType);
	
	String ^ sessionID = this->_login_usr->sessionID;
	OusnsMessage ^ message = this->parent->comm->msgCreator->MakePeerMessage(text, srcID, sessionID, destIP, destPort,
		this->_friend->natType);
	
	this->parent->comm->AddToWorkQueue(message);
	
	// Display the text on the local chat window.
	System::String ^ display_string = this->_login_usr->nickname + L" " + SAYS_CHN + L"\n  " + this->friendMessageEntry->Text + L"\n";
	array<Byte>^ bytes = Encoding::UTF8->GetBytes(display_string);
	String^ unicode_string = Encoding::UTF8->GetString(bytes);
	this->friendChatDisplay->Text += unicode_string;
	
	// Clear the content in the message entry box.
	this->friendMessageEntry->Text = L"";

}

System::Void friendChatDlg::friendChatDlg_OnClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e){
	
	// Reject all incoming file transfer requests and cancel all outgoing file transfer requests.
	
	while (this->panelEx4->Controls->Count > 0) {
		Control ^ c = this->panelEx4->Controls[0];
		DevComponents::DotNetBar::ExpandablePanel^ curPanel = dynamic_cast<DevComponents::DotNetBar::ExpandablePanel^>(c);
		if (this->fileTransferJobPanelList[curPanel->Name]->isSender) {
			this->performCancelFileTransferAction(curPanel->Name);
		} else {
			this->performRejectFileTransferAction(curPanel->Name);
		}
	}

	if (this->parent->friend_chat_dlg_list->ContainsKey(this->_friend->userID)) {
		this->parent->friend_chat_dlg_list->Remove(this->_friend->userID);
	} else {
		MessageBox::Show(L"Error:User was already removed from the active window list.");
	}
}

System::Void friendChatDlg::push_new_message(ChatMessage ^msg){
	OusnsFriend ^ srcFriend = this->_login_usr->FindFriend(msg->srcID);
	//this->friendChatDisplay->Text += srcFriend->nickname + " " + SAYS_CHN + "\n" + msg->text + "\n";
	
	System::Windows::Forms::RichTextBox ^ tempBox = gcnew System::Windows::Forms::RichTextBox();
	tempBox->AppendText(srcFriend->nickname + " " + SAYS_CHN);
	String ^ appendString = tempBox->Rtf;
	
	
	String ^ chatHeader = ExtractTextFromRTF(appendString);

	String ^ chatContent = ExtractTextFromRTF(msg->text);
	//chatContent = "{\\f1\\cb1\\cf2 " + chatContent + "}";
	AppendTextToChatDisplay(chatHeader + " " + chatContent);
	
	//this->friendChatDisplay->Rtf = msg->text->Substring(0, msg->text->LastIndexOf("\\fs24") + 5) + " " + srcFriend->nickname + " " + 
	//	SAYS_CHN + "\\par " + msg->text->Substring(msg->text->LastIndexOf("\\fs24") + 5);
	//this->friendChatDisplay->Refresh();
}

System::Void friendChatDlg::AppendTextToChatDisplay(String ^ content) {

	this->friendChatDisplay->Rtf = this->AppendTextToRTF(this->friendChatDisplay->Rtf, content);
	
	this->friendChatDisplay->SelectionStart = this->friendChatDisplay->Text->Length;
	this->friendChatDisplay->ScrollToCaret();
}
//System::Void friendChatDlg::UpdateFileTransfer
System::Void friendChatDlg::friendChatDlg_OnPressingEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		this->friendChatDlg_Send(sender, e);
		e->Handled = true;
	}
}

System::String ^ friendChatDlg::ExtractTextFromRTF(String ^ rtfString) {

	// Extracts and returns the content of an rtf string.
	String ^ pattern = "\\\\fs\\d+";
	System::Text::RegularExpressions::MatchCollection ^ results = System::Text::RegularExpressions::Regex::Matches(rtfString, pattern);
	int cutStartPos = results[results->Count - 1]->Index + results[results->Count - 1]->Length;
	String ^ result = rtfString->Substring(cutStartPos)->Trim();
	result = result->Substring(0, result->Length - 1)->Trim();

	return result;
}

System::String ^ friendChatDlg::AppendTextToRTF(String ^ rtfString, String ^ text){
	
	int cutPos = rtfString->LastIndexOf("\\par") + 4;

	String ^ newRtfString = rtfString->Substring(0, cutPos) + " " + text + rtfString->Substring(cutPos);

	return newRtfString;
}

System::Void friendChatDlg::Blink(){
	
	HWND a = (HWND)(this->Handle.ToPointer());
	HWND b = ::GetActiveWindow();
	if ((HWND)(this->Handle.ToPointer()) != ::GetActiveWindow()) { 
		FLASHWINFO info;
		::ZeroMemory(&info, sizeof(FLASHWINFO));

		info.cbSize = sizeof(FLASHWINFO);
		info.hwnd = (HWND)this->Handle.ToPointer();
		info.dwFlags = FLASHW_ALL;
		info.uCount = 3;
		::FlashWindowEx(&info);
	}
}

System::Void friendChatDlg::sendFileButton_Click(System::Object^  sender, System::EventArgs^  e) {

	unsigned int srcID = this->_login_usr->userID;
	IPAddress ^ destIP = this->_friend->ipAddr;
	unsigned short destPort = this->_friend->recvPort;
	String ^ sessionID = this->_login_usr->sessionID;
	OuSns::NatType natType = this->_friend->natType;
	
	FileStream ^ fs;
	String ^ fileName = "";
	String ^ filePath = "";
	int fileSize;
	String ^ md5 = "thisIsAFakeMD5CheckSum";
	
	OpenFileDialog ^ chooseFileDialog = gcnew OpenFileDialog();
	chooseFileDialog->Filter = "All files (*.*)|*.*";

	if (chooseFileDialog->ShowDialog() == ::DialogResult::OK) {
		int lastBackSlashPos = chooseFileDialog->FileName->LastIndexOf('\\');
		fileName = chooseFileDialog->FileName->Substring(lastBackSlashPos + 1);
		filePath = chooseFileDialog->FileName->Substring(0, lastBackSlashPos + 1);
		fs = dynamic_cast<FileStream ^> (chooseFileDialog->OpenFile());
		fileSize = (int) fs->Length;
	} else {
		return;
	}
	
	
	AddFileTransferJobPanel(fileName, filePath, fileSize, md5, true);
	OusnsMessage ^ message = this->parent->comm->msgCreator->MakeRequestFileTransfer(srcID, sessionID, 
		fileName, fileSize, md5, destIP, destPort, natType);

	this->parent->comm->AddToWorkQueue(message);
}

System::Void friendChatDlg::AddFileTransferJobPanel(String ^ fileName, String ^ filePath, int fileSize, String ^ md5, 
													bool isSender){


	String ^ fileSizeString;
	if (((float)fileSize / 1024) < 1) {
		fileSizeString = fileSize.ToString("F2") + L"字节";
	} else if ((float)fileSize / 1024 / 1024 < 1) {
		fileSizeString = ((float) fileSize / 1024).ToString("F2") + "KB";
	} else if ((float)fileSize / 1024 / 1024 / 1024 < 1) {
		fileSizeString = ((float) fileSize / 1024 / 1024).ToString("F2") + "MB";
	} else {
		fileSizeString = ((float) fileSize / 1024 / 1024 / 1024).ToString("F2") + "GB";
	}

	DevComponents::DotNetBar::ExpandablePanel^  myExpandablePanel;
	DevComponents::DotNetBar::LabelX^  labelX2;
	DevComponents::DotNetBar::Controls::ProgressBarX^  progressBarX1;
	DevComponents::DotNetBar::LabelX^  labelX3;
	DevComponents::DotNetBar::LabelX^  labelX4;
	DevComponents::DotNetBar::LabelX^  labelX5;

	myExpandablePanel = (gcnew DevComponents::DotNetBar::ExpandablePanel());
	labelX5 = (gcnew DevComponents::DotNetBar::LabelX());
	labelX4 = (gcnew DevComponents::DotNetBar::LabelX());
	labelX2 = (gcnew DevComponents::DotNetBar::LabelX());
	labelX3 = (gcnew DevComponents::DotNetBar::LabelX());
	progressBarX1 = (gcnew DevComponents::DotNetBar::Controls::ProgressBarX());


	// 
	// labelX5
	// 
	labelX5->AutoSize = true;
	// 
	// 
	// 
	labelX5->BackgroundStyle->Class = L"";
	labelX5->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
	labelX5->Cursor = System::Windows::Forms::Cursors::Hand;
	labelX5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	labelX5->ForeColor = System::Drawing::Color::DodgerBlue;
	labelX5->Location = System::Drawing::Point(158, 36);
	labelX5->Name = L"fileTranferCancelButton";
	labelX5->Size = System::Drawing::Size(37, 15);
	labelX5->TabIndex = 5;
	labelX5->Text = L"Cancel";
	labelX5->Click += gcnew System::EventHandler(this, &friendChatDlg::fileTransferCancelButton_Click);
	if (!isSender) {
		labelX5->Visible = false;
	}
	
	// 
	// labelX4
	// 
	// 
	// 
	// 
	labelX4->BackgroundStyle->Class = L"";
	labelX4->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
	labelX4->Location = System::Drawing::Point(4, 73);
	labelX4->Name = L"fileTranferProgressText";
	labelX4->Size = System::Drawing::Size(192, 19);
	labelX4->TabIndex = 4;
	labelX4->Text = L"0/" + fileSizeString;
	labelX4->TextAlignment = System::Drawing::StringAlignment::Far;
	// 
	// labelX2
	// 
	labelX2->AutoSize = true;
	// 
	// 
	// 
	labelX2->BackgroundStyle->Class = L"";
	labelX2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
	labelX2->Cursor = System::Windows::Forms::Cursors::Hand;
	labelX2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	labelX2->ForeColor = System::Drawing::Color::DodgerBlue;
	labelX2->Location = System::Drawing::Point(5, 36);
	labelX2->Name = L"fileTranferAcceptButton";
	labelX2->Size = System::Drawing::Size(36, 15);
	labelX2->TabIndex = 2;
	labelX2->Text = L"Accept";
	labelX2->Click += gcnew System::EventHandler(this, &friendChatDlg::fileTransferAcceptButton_Click);
	if (isSender) {
		labelX2->Visible = false;
	}
	// 
	// labelX3
	// 
	labelX3->AutoSize = true;
	// 
	// 
	
	labelX3->BackgroundStyle->Class = L"";
	labelX3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
	labelX3->Cursor = System::Windows::Forms::Cursors::Hand;
	labelX3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	labelX3->ForeColor = System::Drawing::Color::DodgerBlue;
	labelX3->Location = System::Drawing::Point(47, 36);
	labelX3->Name = L"fileTranferRejectButton";
	labelX3->Size = System::Drawing::Size(34, 15);
	labelX3->TabIndex = 3;
	labelX3->Text = L"Reject";
	labelX3->Click += gcnew System::EventHandler(this, &friendChatDlg::fileTransferRejectButton_Click);
	if (isSender) {
		labelX3->Visible = false;
	}
	// 
	// progressBarX1
	// 
	
	progressBarX1->BackgroundStyle->Class = L"";
	progressBarX1->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
	progressBarX1->Location = System::Drawing::Point(5, 57);
	progressBarX1->Name = L"fileTranferCancelButtonProgressBar";
	progressBarX1->Size = System::Drawing::Size(190, 10);
	progressBarX1->TabIndex = 1;
	progressBarX1->Text = L"progressBarX1";

	myExpandablePanel->SuspendLayout();
	this->panelEx4->Controls->Add(myExpandablePanel);

	myExpandablePanel->CanvasColor = System::Drawing::SystemColors::Control;
	myExpandablePanel->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
	myExpandablePanel->Controls->Add(labelX5);
	myExpandablePanel->Controls->Add(labelX4);
	myExpandablePanel->Controls->Add(labelX2);
	myExpandablePanel->Controls->Add(labelX3);
	myExpandablePanel->Controls->Add(progressBarX1);
	myExpandablePanel->Dock = System::Windows::Forms::DockStyle::Top;
	myExpandablePanel->ExpandOnTitleClick = true;
	myExpandablePanel->Location = System::Drawing::Point(0, 0);
	myExpandablePanel->Name = L"fileTransferExpandablePanel" + this->fileTransferJobPanelList->Count;
	myExpandablePanel->Size = System::Drawing::Size(200, 95);
	myExpandablePanel->Style->Alignment = System::Drawing::StringAlignment::Center;
	myExpandablePanel->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
	myExpandablePanel->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
	myExpandablePanel->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
	myExpandablePanel->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::BarDockedBorder;
	myExpandablePanel->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::ItemText;
	myExpandablePanel->Style->GradientAngle = 90;
	myExpandablePanel->TabIndex = 6;
	myExpandablePanel->TitleHeight = 30;
	myExpandablePanel->TitleStyle->Alignment = System::Drawing::StringAlignment::Center;
	myExpandablePanel->TitleStyle->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
	myExpandablePanel->TitleStyle->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
	myExpandablePanel->TitleStyle->BackgroundImagePosition = DevComponents::DotNetBar::eBackgroundImagePosition::Tile;
	myExpandablePanel->TitleStyle->Border = DevComponents::DotNetBar::eBorderType::RaisedInner;
	myExpandablePanel->TitleStyle->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
	myExpandablePanel->TitleStyle->BorderDashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
	myExpandablePanel->TitleStyle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	myExpandablePanel->TitleStyle->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
	myExpandablePanel->TitleStyle->GradientAngle = 90;
	myExpandablePanel->TitleText = fileName;

	myExpandablePanel->PerformLayout();
	
	if (filePath != nullptr) {
		this->fileTransferJobPanelList[myExpandablePanel->Name] = 
			gcnew DirectTransferFile(fileName, filePath, fileSize, md5);
	} else {
		this->fileTransferJobPanelList[myExpandablePanel->Name] = 
			gcnew DirectTransferFile(fileName, fileSize, md5);
	}
}

System::Void friendChatDlg::fileTransferCancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	DevComponents::DotNetBar::LabelX ^ button = dynamic_cast<DevComponents::DotNetBar::LabelX ^>(sender);
	DevComponents::DotNetBar::ExpandablePanel ^ panel = 
		dynamic_cast<DevComponents::DotNetBar::ExpandablePanel ^> (button->Parent);
	String ^ panelName = panel->Name;
	
	this->performCancelFileTransferAction(panelName);
}

System::Void friendChatDlg::performCancelFileTransferAction(String ^ panelName) {

	if (!this->fileTransferJobPanelList->ContainsKey(panelName)) {
		MessageBox::Show("fileTransferCancelButtonClick: Panel does not exist! (name: " + panelName + ")");
		return;
	}
	String ^ fileName = this->fileTransferJobPanelList[panelName]->fileName;
	int fileSize = this->fileTransferJobPanelList[panelName]->fileSize;
	String ^ md5 = this->fileTransferJobPanelList[panelName]->md5;
	RemoveFileTransferJobPanel(panelName, LOCAL_CANCEL);
	
	IPAddress ^ destIP = this->_friend->ipAddr;
	int destPort = this->_friend->recvPort;
	OuSns::NatType natType = this->_friend->natType;
	String ^ sessionID = this->_login_usr->sessionID;
	unsigned int srcID = this->_login_usr->userID;

	OusnsMessage ^ msg = this->parent->comm->msgCreator->MakeCancelFileTransfer(srcID, sessionID, 
		fileName, fileSize, md5, destIP, destPort, natType);
	this->parent->comm->AddToWorkQueue(msg);

}

System::Void friendChatDlg::fileTransferRejectButton_Click(System::Object^  sender, System::EventArgs^  e) {

	DevComponents::DotNetBar::LabelX ^ button = dynamic_cast<DevComponents::DotNetBar::LabelX ^>(sender);
	DevComponents::DotNetBar::ExpandablePanel ^ panel = 
		dynamic_cast<DevComponents::DotNetBar::ExpandablePanel ^> (button->Parent);
	String ^ panelName = panel->Name;
	
	this->performRejectFileTransferAction(panelName);

}

System::Void friendChatDlg::performRejectFileTransferAction(String ^ panelName) {

	if (!this->fileTransferJobPanelList->ContainsKey(panelName)) {
		MessageBox::Show("fileTransferRejectButtonClick: Panel does not exist! (name: " + panelName + ")");
		return;
	}
	String ^ fileName = this->fileTransferJobPanelList[panelName]->fileName;
	int fileSize = this->fileTransferJobPanelList[panelName]->fileSize;
	String ^ md5 = this->fileTransferJobPanelList[panelName]->md5;
	RemoveFileTransferJobPanel(panelName, LOCAL_REJECT);
	
	IPAddress ^ destIP = this->_friend->ipAddr;
	int destPort = this->_friend->recvPort;
	OuSns::NatType natType = this->_friend->natType;
	String ^ sessionID = this->_login_usr->sessionID;
	unsigned int srcID = this->_login_usr->userID;

	OusnsMessage ^ msg = this->parent->comm->msgCreator->MakeReplyFileTransfer(srcID, sessionID, DECISION_REJECT,
		fileName, fileSize, md5, destIP, destPort, natType);
	this->parent->comm->AddToWorkQueue(msg);

}

System::Void friendChatDlg::RemoveFileTransferJobPanel(String ^ panelName, int reason) {
	
	if (!this->fileTransferJobPanelList->ContainsKey(panelName)) {
		MessageBox::Show("RemoveFileTransferJobPanel: Panel does not exist! (name: " + panelName + ")");
		return;
	}
	String ^ fileName = this->fileTransferJobPanelList[panelName]->fileName;
	switch (reason) {
	case LOCAL_CANCEL:
		this->AppendTextToChatDisplay(LOCAL_USER + CANCEL + HALT_FILE_TRANSFER_ALERT_FIRST_HALF + 
			fileName + HALT_FILE_TRANSFER_ALERT_SECOND_HALF);
		break;
	case LOCAL_REJECT:
		this->AppendTextToChatDisplay(LOCAL_USER + REJECT + HALT_FILE_TRANSFER_ALERT_FIRST_HALF + 
			fileName + HALT_FILE_TRANSFER_ALERT_SECOND_HALF);
		break;
	case REMOTE_REJECT:
		this->AppendTextToChatDisplay(REMOTE_USER + REJECT + HALT_FILE_TRANSFER_ALERT_FIRST_HALF + 
			fileName + HALT_FILE_TRANSFER_ALERT_SECOND_HALF);
		break;
	case REMOTE_CANCEL:
		this->AppendTextToChatDisplay(REMOTE_USER + CANCEL + HALT_FILE_TRANSFER_ALERT_FIRST_HALF + 
			fileName + HALT_FILE_TRANSFER_ALERT_SECOND_HALF);
		break;
	default:
		MessageBox::Show("RemoveFileTransferJobPanel: Unknown reason " + Convert::ToString(reason));
	}
	this->panelEx4->Controls->RemoveByKey(panelName);
	this->fileTransferJobPanelList->Remove(panelName);
}

System::Void friendChatDlg::fileTransferAcceptButton_Click(System::Object^  sender, System::EventArgs^  e) {

	DevComponents::DotNetBar::LabelX ^ button = dynamic_cast<DevComponents::DotNetBar::LabelX ^>(sender);
	button->Visible = false;
	DevComponents::DotNetBar::ExpandablePanel ^ panel = 
		dynamic_cast<DevComponents::DotNetBar::ExpandablePanel ^> (button->Parent);
	String ^ panelName = panel->Name;
	
	if (!this->fileTransferJobPanelList->ContainsKey(panelName)) {
		MessageBox::Show("fileTransferAcceptButtonClick: Panel does not exist! (name: " + panelName + ")");
		return;
	}

	String ^ fileName = this->fileTransferJobPanelList[panelName]->fileName;
	String ^ md5 = this->fileTransferJobPanelList[panelName]->md5;

	/*
	array<String ^> ^ params = {fileName, md5};
	ParameterizedThreadStart ^ exchangePortInfoThreadStart = gcnew ParameterizedThreadStart(this, &friendChatDlg::exchangePortInfo);
	Thread ^ exchangePortInfoThread = gcnew Thread(exchangePortInfoThreadStart);
	exchangePortInfoThread->Name = L"exchangePortInfoThread";
	exchangePortInfoThread->Priority = ThreadPriority::Normal;
	exchangePortInfoThread->Start(params);
	*/
	exchangePortInfo(fileName, md5);

	/*
	BackgroundWorker ^ bw = gcnew BackgroundWorker();
	bw->DoWork += gcnew DoWorkEventHandler(this, &friendChatDlg::backgroundWorkerDoReceive);
	bw->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &friendChatDlg::backgroundWorkerReceiveCompleted);
	bw->ProgressChanged += gcnew ProgressChangedEventHandler(this, &friendChatDlg::backgroundWorkerReceiveProgressChanged);

	bw->RunWorkerAsync(panelName);
	*/
	

}

System::Void friendChatDlg::backgroundWorkerDoReceive(Object ^ sender, DoWorkEventArgs ^ e) {
	BackgroundWorker ^ worker = dynamic_cast<BackgroundWorker ^> (sender);

	e->Result = receiveDirectTransferFile(dynamic_cast<String ^> (e->Argument), worker, e);
}

int friendChatDlg::receiveDirectTransferFile(String ^ panelName,
													  BackgroundWorker ^ worker, DoWorkEventArgs ^ e) {
	UDTSOCKET u = UDT::socket(AF_INET, SOCK_STREAM, 0);
	u = establishP2PConnection(u, panelName);
	return 0;
}

System::Void friendChatDlg::backgroundWorkerReceiveCompleted(Object ^ sender, RunWorkerCompletedEventArgs ^ e) {

}

System::Void friendChatDlg::backgroundWorkerReceiveProgressChanged(Object ^ sender, ProgressChangedEventArgs ^ e) {

}


System::Void friendChatDlg::backgroundWorkerDoSend(Object ^ sender, DoWorkEventArgs ^ e) {
	BackgroundWorker ^ worker = dynamic_cast<BackgroundWorker ^> (sender);

	e->Result = sendDirectTransferFile(dynamic_cast<String ^> (e->Argument), worker, e);
}

int friendChatDlg::sendDirectTransferFile(String ^ panelName,
													  BackgroundWorker ^ worker, DoWorkEventArgs ^ e) {
	UDTSOCKET u = UDT::socket(AF_INET, SOCK_DGRAM, 0);
	u = establishP2PConnection(u, panelName);
	return 0;
}


System::Void friendChatDlg::backgroundWorkerSendCompleted(Object ^ sender, RunWorkerCompletedEventArgs ^ e) {

}

System::Void friendChatDlg::backgroundWorkerSendProgressChanged(Object ^ sender, ProgressChangedEventArgs ^ e) {

}

UDTSOCKET friendChatDlg::establishP2PConnection(UDTSOCKET u, String ^ panelName) {

	String ^ fileName = this->fileTransferJobPanelList[panelName]->fileName;
	String ^ md5 = this->fileTransferJobPanelList[panelName]->md5;

	IPAddress ^ destIP = this->_friend->ipAddr;
	int destPort;
	IPAddress ^ srcIP = IPAddress::Parse("127.0.0.1");
	int srcPort;

	for each (FileTransferPort ^ f in this->fileTransferPortList) {
		if (f->fileName == fileName && f->md5 == md5) {
			destPort = f->peerPort;
			srcPort = f->localPort;
		}
	}

	if (destPort == 0 || srcPort == 0) {
		Diagnostics::Debug::WriteLine("Invalid port info:\ndestPort = " + destPort.ToString() + "\nsrcPort = " + srcPort.ToString() +
			"\nHalt.");
		return (UDTSOCKET) 0;
	}
	
	ULONG destIPLong;
	if (htonl(47) == 47) { // Check endianness and convert the number the same way as the machine does.
		destIPLong = (ULONG)((destIP->GetAddressBytes()[0] << 24) | (destIP->GetAddressBytes()[1] << 16) | 
								   (destIP->GetAddressBytes()[2] << 8) | destIP->GetAddressBytes()[3]);
	} else {
		destIPLong = (ULONG)((destIP->GetAddressBytes()[3] << 24) | (destIP->GetAddressBytes()[2] << 16) | 
								   (destIP->GetAddressBytes()[1] << 8) | destIP->GetAddressBytes()[0]);
	}

	ULONG srcIPLong = (ULONG)((srcIP->GetAddressBytes()[0] << 24) | (srcIP->GetAddressBytes()[1] << 16) | 
							   (srcIP->GetAddressBytes()[2] << 8) | srcIP->GetAddressBytes()[3]);

	

	Diagnostics::Debug::WriteLine("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	Diagnostics::Debug::WriteLine("srcPort: " + srcPort.ToString());
	Diagnostics::Debug::WriteLine("destPort: " + destPort.ToString());
	Diagnostics::Debug::WriteLine("srcPort after htons: " + htons(srcPort).ToString());
	Diagnostics::Debug::WriteLine("destPort after htons: " + htons(destPort).ToString());
	Diagnostics::Debug::WriteLine("destIPLong after htons: " + htonl(destIPLong).ToString());
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_addr.s_addr = INADDR_ANY;
	localAddr.sin_port = htons(srcPort);

	SOCKADDR_IN peerAddr;
	peerAddr.sin_family = AF_INET;
	peerAddr.sin_addr.s_addr = htonl(destIPLong);
	peerAddr.sin_port = htons(destPort);

	Sleep(100);
	

	// TODO: Ideally, This worker needs to sleep for one round-trip time in order to let the ACCEPT FILE TRANSFER 
	// request to arrive at the sender side.
	UDT::startup();
	bool rendezvous = true;
	UDT::setsockopt(u, 0, UDT_RENDEZVOUS, new bool(true), sizeof(bool));
	int bindRetVal =  UDT::bind(u, (SOCKADDR *)&localAddr, sizeof(localAddr));
	if (bindRetVal != 0) {
		MessageBox::Show(AnsiToManagedString((char *) UDT::getlasterror().getErrorMessage()));
	}
	
	int connectRetVal = UDT::connect(u, (SOCKADDR *)&peerAddr, sizeof(peerAddr));
	if (connectRetVal != 0) {
		MessageBox::Show(AnsiToManagedString((char *) UDT::getlasterror().getErrorMessage()));
	} else {
		MessageBox::Show("Connection Successful.");
	}
	UDT::close(u);
	UDT::cleanup();

	return u;
}

System::Void friendChatDlg::StartSendFileThread(String ^ fileName, String ^ md5) {

	String ^ panelName;
	for each (String ^ p in this->fileTransferJobPanelList->Keys) {
		if (this->fileTransferJobPanelList[p]->fileName == fileName &&
			this->fileTransferJobPanelList[p]->md5 == md5) {
			panelName = p;
			break;
		}
	}
	if (panelName == nullptr) {
		MessageBox::Show("StartSendFileThread: Specified file does not exist!\n" +
			"file name: " + fileName + "\nmd5: " + md5);
		return;
	}
	BackgroundWorker ^ bw = gcnew BackgroundWorker();
	bw->DoWork += gcnew DoWorkEventHandler(this, &friendChatDlg::backgroundWorkerDoSend);
	bw->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &friendChatDlg::backgroundWorkerSendCompleted);
	bw->ProgressChanged += gcnew ProgressChangedEventHandler(this, &friendChatDlg::backgroundWorkerSendProgressChanged);

	bw->RunWorkerAsync(panelName);
}

System::Void friendChatDlg::StartReceiveFileThread(String ^ fileName, String ^ md5) {

	String ^ panelName;
	for each (String ^ p in this->fileTransferJobPanelList->Keys) {
		if (this->fileTransferJobPanelList[p]->fileName == fileName &&
			this->fileTransferJobPanelList[p]->md5 == md5) {
			panelName = p;
			break;
		}
	}
	if (panelName == nullptr) {
		MessageBox::Show("StartReceiveFileThread: Specified file does not exist!\n" +
			"file name: " + fileName + "\nmd5: " + md5);
		return;
	}
	BackgroundWorker ^ bw = gcnew BackgroundWorker();
	bw->DoWork += gcnew DoWorkEventHandler(this, &friendChatDlg::backgroundWorkerDoReceive);
	bw->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &friendChatDlg::backgroundWorkerReceiveCompleted);
	bw->ProgressChanged += gcnew ProgressChangedEventHandler(this, &friendChatDlg::backgroundWorkerReceiveProgressChanged);

	bw->RunWorkerAsync(panelName);
}


System::Void friendChatDlg::exchangePortInfo(String ^ fileName, String ^ md5) {
	
	UdpClient ^ client = gcnew UdpClient();

	IPAddress ^ destIP = this->_friend->ipAddr;
	int destPort = this->_friend->recvPort;
	OuSns::NatType natType = this->_friend->natType;
	String ^ sessionID = this->_login_usr->sessionID;
	unsigned int srcID = this->_login_usr->userID;

	bool isSender = false;
	FileTransferPort ^ currentPort;
	for each (FileTransferPort ^ p in this->fileTransferPortList) { 
		if (p->fileName == fileName && p->md5 == md5) {
			// Record created before sending a HOLEPUNCHING request. This indicates that this is
			// the sender side of the file transfer, and therefore the peer port info is already
			// filled in.
			isSender = true;
			currentPort = p;
			break;
		}
	}
	
	OusnsMessage ^ msg;

	// The sender of the file sends out the HOLEPUNCHING response whereas the receiver of the file
	// sends out the HOLEPUNCHING request (after clicking "Accept" on the UI).
	if (isSender) {
		msg = this->parent->comm->msgCreator->MakeHolePunchingResponse(srcID, sessionID,
			fileName, md5, destIP, destPort, natType);
	} else {
		msg = this->parent->comm->msgCreator->MakeHolePunching(srcID, sessionID,
			fileName, md5, destIP, destPort, natType);
	}

	array<OusnsPacket ^> ^ packets = this->parent->comm->SplitOusnsMessageIntoOusnsPacket(msg);
	IPEndPoint ^ destEP = gcnew IPEndPoint(packets[0]->targetIP, packets[0]->targetPort);
	client->Connect(destEP);
	
	if (isSender) {
		System::Diagnostics::Debug::Assert(currentPort != nullptr);
		currentPort->localPort = dynamic_cast<IPEndPoint ^>(client->Client->LocalEndPoint)->Port; // We have address for both side now.
		Diagnostics::Debug::WriteLine("BEFORE SENDING HOLEPUNCHING RESPONSE:\nAdding the following port to fileTransferPortList: " +
			"\nfileName: " + currentPort->fileName +
			"\nmd5: " + currentPort->md5 +
			"\nisSender: " + currentPort->isSender.ToString() +
			"\nlocalPath: " + currentPort->localPath +
			"\nlocalPort: " + currentPort->localPort.ToString() +
			"\npeerAddress: " + currentPort->peerAddress->ToString() +
			"\npeerPort: " + currentPort->peerPort.ToString());

	} else { // This is the receiver side. We fill in the local port now, 
			 // and wait for the hole punching response to give us the peer port info.
		FileTransferPort ^ newPort = gcnew FileTransferPort(fileName, md5);
		newPort->localPath = "";
		newPort->peerAddress = IPAddress::Parse("0.0.0.0");
		newPort->localPort = dynamic_cast<IPEndPoint ^>(client->Client->LocalEndPoint)->Port;
		this->fileTransferPortList->AddLast(newPort);
		Diagnostics::Debug::WriteLine("BEFORE SENDING HOLEPUNCHING REQUEST:\nAdding the following port to fileTransferPortList: " +
			"\nfileName: " + newPort->fileName +
			"\nmd5: " + newPort->md5 +
			"\nisSender: " + newPort->isSender.ToString() +
			"\nlocalPath: " + newPort->localPath +
			"\nlocalPort: " + newPort->localPort.ToString() +
			"\npeerAddress: " + newPort->peerAddress->ToString() +
			"\npeerPort: " + newPort->peerPort.ToString());
	}

	// Send the packets.
	for each (OusnsPacket ^ p in packets) {
		
		if (DEBUG_COMM) {
			MessageBox::Show("exchangePortInfo: sending the following packet" + " to " +
				destEP->ToString() + "\n" + p->packetContent->ToString());
		}
		client->Send(p->packetContent, p->packetContent->Length);
		if (DEBUG_COMM) {
			MessageBox::Show("exchangePortInfo: the udp client has chosen " + 
				client->Client->LocalEndPoint->ToString() + " as the local endpoint.");
		}

	}

	client->Close();
}

System::Void friendChatDlg::ExtendPanel_Click(System::Object^  sender, System::EventArgs^  e) {

	 this->SuspendLayout();

	 if (this->WindowState == FormWindowState::Maximized){
		 if(this->sidePanelDisplayed == false){
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top ) 
				 | System::Windows::Forms::AnchorStyles::Left));
			 //this->Size = System::Drawing::Size(this->Size.Width + 200,this->Size.Height);
			 //this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width+200,this->panelEx1->Size.Height);

			 this->friendChatTabControl->Size = System::Drawing::Size(this->friendChatTabControl->Size.Width - 201,
				 this->friendChatTabControl->Size.Height);
			 this->panelEx4->Location = System::Drawing::Point(this->friendChatTabControl->Size.Width+1,103);
			 this->panelEx4->Size = System::Drawing::Size(200,this->friendChatChattingSplitContainer->Size.Height);
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left) 
				 | System::Windows::Forms::AnchorStyles::Right));
			 this->sidePanelDisplayed = true;
			 this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexright_normal")));
			}
		 else{
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left));
			 this->panelEx4->Size = System::Drawing::Size(0,0);

			 //this->Size = System::Drawing::Size(this->Size.Width - 200,this->Size.Height);
			 //this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width-200,this->panelEx1->Size.Height);
			 this->friendChatTabControl->Size = System::Drawing::Size(this->friendChatTabControl->Size.Width + 201,
				 this->friendChatTabControl->Size.Height);
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left) 
				 | System::Windows::Forms::AnchorStyles::Right));
			 this->sidePanelDisplayed = false;
			 this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexleft_normal")));
			}

		}
	 else{
		 if(this->sidePanelDisplayed == false){
			 //Expanding
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top ) 
				 | System::Windows::Forms::AnchorStyles::Left));
			 this->Size = System::Drawing::Size(this->Size.Width + 202,this->Size.Height);
			 this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width+201,this->panelEx1->Size.Height);

			 this->panelEx4->Location = System::Drawing::Point(this->friendChatTabControl->Size.Width+1,103);
			 this->panelEx4->Size = System::Drawing::Size(200,this->friendChatChattingSplitContainer->Size.Height);
			 //MessageBox::Show(this->friendChatChattingSplitContainer->Size.Height.ToString());
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left) 
				 | System::Windows::Forms::AnchorStyles::Right));
			 this->sidePanelDisplayed = true;
			 this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexright_normal")));
		 }
		 else{
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left));
			 this->panelEx4->Size = System::Drawing::Size(0,0);

			 this->MinimumSize = System::Drawing::Size(this->MinimumSize.Width - 202, this->MinimumSize.Height);
			 this->Size = System::Drawing::Size(this->Size.Width - 202,this->Size.Height);

			 this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width-201,this->panelEx1->Size.Height);
			 this->friendChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				 | System::Windows::Forms::AnchorStyles::Left) 
				 | System::Windows::Forms::AnchorStyles::Right));
			 this->sidePanelDisplayed = false;
			 this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexleft_normal")));
		 }
		}
	 this->ResumeLayout();


 }
