#pragma once
#include "stdafx.h"



#ifndef LOGIN_DLG
#define LOGIN_DLG



namespace OuSns {

	/// <summary>
	/// LoginDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	
	ref class MainDlg;
	ref class OusnsDlg;
	ref class MessageCreator;
	ref class OusnsLoginUser;
	ref class MessageProcessor;
	ref class Communication;
	//public ref class LoginDlg : public System::Windows::Forms::Form
	public ref class LoginDlg :DevComponents::DotNetBar::Office2007Form
	{
	public:
		
		
		System::String^ _userID;
		System::String^ _password;
		System::String^ _userIDType;
		Communication^ comm;
		OuSns::MainDlg^ mainDlg;
		// The message processor instance
		MessageProcessor^ msgProcessor;
		bool workThreadStarted;
		bool loggedIn;
		OuSns::NatType userNatType;
		bool newUser;
		LinkedList<String^>^ macAddressArray;


	private: DevComponents::DotNetBar::Controls::TextBoxX^  loginPassword;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  loginType;
	private: DevComponents::DotNetBar::Controls::ComboBoxEx^  loginId;


	private: DevComponents::Editors::ComboItem^  comboItem1;
	private: DevComponents::Editors::ComboItem^  comboItem2;
	private: DevComponents::DotNetBar::Controls::CheckBoxX^  remember;

	private: DevComponents::DotNetBar::ButtonX^  cancelButton;
	private: DevComponents::DotNetBar::LabelX^  rememberLabelX;
	private: DevComponents::DotNetBar::ButtonX^  loginButton;

	public: 

	public: 

	private: 

		private: OuSns::MouseLocationStyle loactionStyle;
	public:
		[DllImport("user32.dll")]
		static bool RelaeseCapture(void);
		[DllImport("user32.dll")]
		static bool SendMessage(IntPtr hwnd, int wMsg, int wParam, int lParam);
		
	 String^ ressrc;
	 System::Reflection::Assembly^ execAssem;
	 Resources::ResourceManager^ myres;

	 private: Point^ downPoint;
	public: bool isDown;
	public: 
		// The message creator instance
		MessageCreator^ msgCreator;

	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	public: 




	private: System::Windows::Forms::Label^  label2;

	private: 

	public: 

	private: 

	public: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::Bar^  rightCornerFunctionBar;
	private: DevComponents::DotNetBar::ButtonItem^  minimizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  maximizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  closeButton;
	public:
		LoginDlg(void);
		
		
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~LoginDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	public: 
		delegate System::Void NotifyUIContinue(OusnsLoginUser^ loginUser);
		delegate System::Void NotifyUIError(String^ notification);
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelEx1 = (gcnew DevComponents::DotNetBar::PanelEx());
			this->loginButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->rememberLabelX = (gcnew DevComponents::DotNetBar::LabelX());
			this->cancelButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->remember = (gcnew DevComponents::DotNetBar::Controls::CheckBoxX());
			this->loginId = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->comboItem1 = (gcnew DevComponents::Editors::ComboItem());
			this->comboItem2 = (gcnew DevComponents::Editors::ComboItem());
			this->loginPassword = (gcnew DevComponents::DotNetBar::Controls::TextBoxX());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loginType = (gcnew DevComponents::DotNetBar::Controls::ComboBoxEx());
			this->rightCornerFunctionBar = (gcnew DevComponents::DotNetBar::Bar());
			this->minimizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->maximizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->closeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelEx1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelEx1
			// 
			this->panelEx1->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->loginButton);
			this->panelEx1->Controls->Add(this->rememberLabelX);
			this->panelEx1->Controls->Add(this->cancelButton);
			this->panelEx1->Controls->Add(this->remember);
			this->panelEx1->Controls->Add(this->loginId);
			this->panelEx1->Controls->Add(this->loginPassword);
			this->panelEx1->Controls->Add(this->label2);
			this->panelEx1->Controls->Add(this->loginType);
			this->panelEx1->Controls->Add(this->rightCornerFunctionBar);
			this->panelEx1->Controls->Add(this->pictureBox1);
			this->panelEx1->Controls->Add(this->label1);
			this->panelEx1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx1->Location = System::Drawing::Point(0, 0);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Size = System::Drawing::Size(287, 628);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground2;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 0;
			this->panelEx1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginDlg::panelEx1_MouseMove);
			this->panelEx1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginDlg::panelEx1_MouseDown);
			this->panelEx1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginDlg::panelEx1_MouseUp);
			// 
			// loginButton
			// 
			this->loginButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->loginButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->loginButton->Location = System::Drawing::Point(25, 459);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(75, 23);
			this->loginButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->loginButton->TabIndex = 3;
			this->loginButton->Text = L"登录";
			this->loginButton->Click += gcnew System::EventHandler(this, &LoginDlg::LoginButton_Click);
			// 
			// rememberLabelX
			// 
			// 
			// 
			// 
			this->rememberLabelX->BackgroundStyle->Class = L"";
			this->rememberLabelX->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->rememberLabelX->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rememberLabelX->Location = System::Drawing::Point(148, 459);
			this->rememberLabelX->Name = L"rememberLabelX";
			this->rememberLabelX->Size = System::Drawing::Size(85, 23);
			this->rememberLabelX->TabIndex = 3;
			this->rememberLabelX->Text = L"记住我的密码";
			this->rememberLabelX->Click += gcnew System::EventHandler(this, &LoginDlg::rememberLabelX_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->cancelButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(25, 501);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"退出";
			this->cancelButton->Click += gcnew System::EventHandler(this, &LoginDlg::CancelButton_Click);
			// 
			// remember
			// 
			// 
			// 
			// 
			this->remember->BackgroundStyle->Class = L"";
			this->remember->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->remember->FocusCuesEnabled = false;
			this->remember->Location = System::Drawing::Point(121, 459);
			this->remember->Name = L"remember";
			this->remember->Size = System::Drawing::Size(21, 22);
			this->remember->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->remember->TabIndex = 5;
			this->remember->CheckedChanged += gcnew System::EventHandler(this, &LoginDlg::remember_CheckedChanged);
			// 
			// loginId
			// 
			this->loginId->DisplayMember = L"Text";
			this->loginId->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->loginId->FormattingEnabled = true;
			this->loginId->ItemHeight = 15;
			this->loginId->Items->AddRange(gcnew cli::array< System::Object^  >(2) {this->comboItem1, this->comboItem2});
			this->loginId->Location = System::Drawing::Point(121, 315);
			this->loginId->Name = L"loginId";
			this->loginId->Size = System::Drawing::Size(135, 21);
			this->loginId->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->loginId->TabIndex = 1;
			this->loginId->SelectedIndexChanged += gcnew System::EventHandler(this, &LoginDlg::loginId_SelectedIndexChanged);
			this->loginId->TextChanged += gcnew System::EventHandler(this, &LoginDlg::loginId_TextChanged);
			// 
			// comboItem1
			// 
			this->comboItem1->Text = L"test1";
			// 
			// comboItem2
			// 
			this->comboItem2->Text = L"test2";
			// 
			// loginPassword
			// 
			// 
			// 
			// 
			this->loginPassword->Border->Class = L"TextBoxBorder";
			this->loginPassword->Border->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->loginPassword->Location = System::Drawing::Point(121, 383);
			this->loginPassword->MaxLength = 16;
			this->loginPassword->Name = L"loginPassword";
			this->loginPassword->PasswordChar = '*';
			this->loginPassword->Size = System::Drawing::Size(135, 21);
			this->loginPassword->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 392);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"密   码：";
			// 
			// loginType
			// 
			this->loginType->DisplayMember = L"Text";
			this->loginType->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->loginType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->loginType->FormattingEnabled = true;
			this->loginType->ItemHeight = 15;
			this->loginType->Location = System::Drawing::Point(34, 315);
			this->loginType->Name = L"loginType";
			this->loginType->Size = System::Drawing::Size(66, 21);
			this->loginType->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->loginType->TabIndex = 0;
			this->loginType->SelectedIndexChanged += gcnew System::EventHandler(this, &LoginDlg::loginType_SelectedIndexChanged);
			// 
			// rightCornerFunctionBar
			// 
			this->rightCornerFunctionBar->AntiAlias = true;
			this->rightCornerFunctionBar->BackColor = System::Drawing::Color::Transparent;
			this->rightCornerFunctionBar->CanDockBottom = false;
			this->rightCornerFunctionBar->CanDockLeft = false;
			this->rightCornerFunctionBar->CanDockRight = false;
			this->rightCornerFunctionBar->CanDockTab = false;
			this->rightCornerFunctionBar->CanDockTop = false;
			this->rightCornerFunctionBar->CanReorderTabs = false;
			this->rightCornerFunctionBar->CanUndock = false;
			this->rightCornerFunctionBar->Dock = System::Windows::Forms::DockStyle::Right;
			this->rightCornerFunctionBar->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->rightCornerFunctionBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(3) {this->minimizeButton, 
				this->maximizeButton, this->closeButton});
			this->rightCornerFunctionBar->Location = System::Drawing::Point(199, 0);
			this->rightCornerFunctionBar->Margin = System::Windows::Forms::Padding(0);
			this->rightCornerFunctionBar->MaximumSize = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->MinimumSize = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->Name = L"rightCornerFunctionBar";
			this->rightCornerFunctionBar->PaddingBottom = 0;
			this->rightCornerFunctionBar->PaddingLeft = 0;
			this->rightCornerFunctionBar->PaddingRight = 0;
			this->rightCornerFunctionBar->PaddingTop = 0;
			this->rightCornerFunctionBar->RoundCorners = false;
			this->rightCornerFunctionBar->SingleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->rightCornerFunctionBar->Size = System::Drawing::Size(88, 18);
			this->rightCornerFunctionBar->Stretch = true;
			this->rightCornerFunctionBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->rightCornerFunctionBar->TabIndex = 16;
			this->rightCornerFunctionBar->TabStop = false;
			this->rightCornerFunctionBar->Text = L"bar1";
			this->rightCornerFunctionBar->Visible = false;
			// 
			// minimizeButton
			// 
			this->minimizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->minimizeButton->ImagePaddingHorizontal = 0;
			this->minimizeButton->ImagePaddingVertical = 0;
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Text = L"小";
			this->minimizeButton->Click += gcnew System::EventHandler(this, &LoginDlg::minimizeButton_Click);
			// 
			// maximizeButton
			// 
			this->maximizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->maximizeButton->ImagePaddingHorizontal = 0;
			this->maximizeButton->ImagePaddingVertical = 0;
			this->maximizeButton->Name = L"maximizeButton";
			this->maximizeButton->Text = L"大";
			this->maximizeButton->Click += gcnew System::EventHandler(this, &LoginDlg::maximizeButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->closeButton->ImagePaddingHorizontal = 0;
			this->closeButton->ImagePaddingVertical = 0;
			this->closeButton->Name = L"closeButton";
			this->closeButton->Text = L"关闭";
			this->closeButton->Click += gcnew System::EventHandler(this, &LoginDlg::closeButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(66, 54);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(151, 140);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(68, 271);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 12);
			this->label1->TabIndex = 7;
			this->label1->Text = L"只要你想。。。无限分享";
			// 
			// LoginDlg
			// 
			this->AcceptButton = this->loginButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(287, 628);
			this->Controls->Add(this->panelEx1);
			this->Name = L"LoginDlg";
			this->Text = L"登录OuSns";
			this->panelEx1->ResumeLayout(false);
			this->panelEx1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginButton_Click(System::Object^  sender, System::EventArgs^  e) ;
			 System::Void LoginDlg::CancelButton_Click(System::Object^  sender, System::EventArgs^  e);

	/*
	 * This function use the regular expression to verify the login information
	 */
	public:
		bool LoginDlg::RegularExpressionVerification(int loginType, String^ pattern);

		System::Void DisableButtons(bool flag);

	/*
	 * This function will start the work thread
	 */
		System::Void LoginDlg::StartWorkThread();

		/*
		 * This funtion will notify the user that there is a login error
		 */
		System::Void LoginDlg::LoginErrorNotification(String^ notification);

		/*
		 * This funtion will continue the login procesure
		 */
		System::Void LoginDlg::ContinueLogin(OusnsLoginUser^ usr);

	/*
	 * This function will return an array of mac address of this computer
	 */
		LinkedList<String^>^ LoginDlg::GetMACAddress(void);

	/*
	 * This function will communicate with the stun server and get the nat type of current user
	 */
	OuSns::NatType LoginDlg::GetNatType();
		

private: System::Void panelEx1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panelEx1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) ;
private: System::Void panelEx1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) ;
private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void maximizeButton_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void minimizeButton_Click(System::Object^  sender, System::EventArgs^  e);
 public:
	 System::Void GetLoginHistory(void);
private: System::Void loginType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->GetLoginHistory();
		 }

public:
	System::Void SaveUserInfoToFile(OusnsLoginUser^ usr);
	System::Void ReadUserInfoFromFile(String^ path);
private: System::Void loginId_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void remember_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(!this->remember->Checked && File::Exists(OUSNS_USER_PATH + "\\" + this->loginId->Text + "\\data"))
				 File::Delete(OUSNS_USER_PATH + "\\" + this->loginId->Text + "\\data");
		 }
private: System::Void rememberLabelX_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->remember->Checked = !this->remember->Checked;
		 }

/*
protected: virtual void WndProc(Message % m) override{
			   //ECRT rc;
			   //HWND hwnd = (HWND)(form->Handle.ToPointer());
			   NCCALCSIZE_PARAMS* pncc;
			   long mLeft,mRight,mTop,mBottom;
			   switch (m.Msg)
			   {

			   case WM_NCPAINT:

				   //System::Windows::Forms::Form::WndProc(m);
				   break;
			   case WM_NCACTIVATE:
				   if((int)m.WParam == 0)
					   m.Result = (IntPtr)1;

				   break;

			   case WM_NCCALCSIZE:

				   //InflateRect(&((NCCALCSIZE_PARAMS* )lParam)->rgrc[0],-50,-50);
				   pncc = (NCCALCSIZE_PARAMS *)m.LParam.ToPointer();
				   //pncc->rgrc[0] is the new rectangle
				   //pncc->rgrc[1] is the old rectangle
				   //pncc->rgrc[2] is the client rectangle

				   //DefWindowProc (hwnd, WM_NCCALCSIZE, (WPARAM)m.WParam.ToPointer(), (LPARAM)m.LParam.ToPointer());

				   mLeft = GetSystemMetrics(SM_CXFRAME);
				   mRight = mLeft;
				   mTop = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME);
				   mBottom = GetSystemMetrics(SM_CYFRAME);


				   pncc->rgrc[0].top = pncc->rgrc[0].top - mTop;
				   //pncc->rgrc[0].top = pncc->rgrc[0].top - mBottom;
				   pncc->rgrc[0].right = pncc->rgrc[0].right + mRight;
				   //pncc->rgrc[0].right = pncc->rgrc[0].right;
				   pncc->rgrc[0].left = pncc->rgrc[0].left - mLeft;
				   //pncc->rgrc[0].left = pncc->rgrc[0].left;
				   pncc->rgrc[0].bottom =  pncc->rgrc[0].bottom + mBottom ;

				   System::Windows::Forms::Form::WndProc(m);

				   break;
				   /*
				   case WM_NCHITTEST:

				   // 分解当前鼠标的坐标
				   nPosX = LOWORD(m.LParam.ToPointer()); 
				   nPosY = HIWORD(m.LParam.ToPointer());
				   if(nPosX >= Left + Width - 3 && nPosY >= Top + Height - 3)
				   {
				   // 鼠标位置在窗体的右下角附近
				   m.Result = IntPtr(HTBOTTOMRIGHT);
				   return;
				   }        
				   else if(nPosX >= Left + Width -3)
				   {
				   // 鼠标位置在窗体右侧
				   m.Result = IntPtr(HTRIGHT);
				   return;
				   }
				   else if(nPosY >= Top + Height - 3)
				   {
				   // 鼠标位置在窗体下方
				   m.Result = IntPtr(HTBOTTOM);
				   return;
				   }
				   // 以上只判断鼠标位置是否在右侧，右下角，下方，所以仅仅当鼠标指针在这三个位置时才会改变成改变大小的形

				   状，拖动后可改变大小。

				   break;
				   
			   default:
				   System::Windows::Forms::Form::WndProc(m);
			   }
			   return;		
		   }

*/

private: System::Void loginId_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) ;
};
}

#endif