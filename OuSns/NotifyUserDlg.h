
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// NotifyUserDlg 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	//public ref class NotifyUserDlg : public OuSns::OusnsDlg
	public ref class NotifyUserDlg : public System::Windows::Forms::Form
	{
	public:
		//common part
		[DllImport("user32.dll")]
		static bool RelaeseCapture(void);
		[DllImport("user32.dll")]
		static bool SendMessage(IntPtr hwnd, int wMsg, int wParam, int lParam);
		String^ ressrc;
		System::Reflection::Assembly^ execAssem;
		bool isDown;

	public: 


	public: 
		Resources::ResourceManager^ myres;
	public:
		/*
		 * This dialog will ONLY return 3 dialog results
		 * 1. ::DialogResult::Yes, ::DialogResult::No, ::DialogResult::Ignore
		 */
		NotifyUserDlg(OuSns::NotifyUIDlgType type,String^ acceptButtonText, String^ contentInput)
		{
			//common part
			ressrc = L"OuSns.ImageResource";
			execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
			myres = gcnew Resources::ResourceManager(ressrc,execAssem);
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			this->SuspendLayout();

			this->InitializePictureBox(type);
			this->acceptButton->Text = acceptButtonText;
			
			/*
			//To Be Processed
			this->acceptButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_highlight")));
			this->acceptButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->acceptButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_down")));
			*/
			this->acceptButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->acceptButton->Location = System::Drawing::Point(140, 140);
			this->refuseButton->Visible = false;
			this->refuseButton->Enabled = false;
			this->ignoreButton->Visible = false;
			this->ignoreButton->Enabled = false;
			this->initiateNonClientButtons();
			this->closeButton->Enabled = false;
			this->ResumeLayout(false);
			isDown = false;
			this->content->Text =  contentInput;
		}

	public:
		NotifyUserDlg(OuSns::NotifyUIDlgType type,String^ acceptButtonText, String^ refuseButtonText,String^ contentInput)
		{
			ressrc = L"OuSns.ImageResource";
			execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
			myres = gcnew Resources::ResourceManager(ressrc,execAssem);
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			this->panelEx1->SuspendLayout();
			this->InitializePictureBox(type);
			this->acceptButton->Text = acceptButtonText;
			this->refuseButton->Text = refuseButtonText;
			/*
			//To Be Processed
			this->acceptButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_highlight")));
			this->acceptButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->acceptButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_down")));
			
			this->refuseButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_highlight")));
			this->refuseButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->refuseButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_down")));
			*/
			this->acceptButton->Location = System::Drawing::Point(80, 140);
			this->refuseButton->Location = System::Drawing::Point(200, 140);
			this->ignoreButton->Visible = false;
			this->ignoreButton->Enabled = false;
			this->initiateNonClientButtons();
			this->closeButton->Enabled = false;
			this->panelEx1->ResumeLayout(false);
			isDown = false;
			this->content->Text =  contentInput;
		}
	public:
		NotifyUserDlg(OuSns::NotifyUIDlgType type,String^ acceptButtonText, String^ refuseButtonText,String^ ignoreButtonText,String^ contentInput)
		{

			ressrc = L"OuSns.ImageResource";
			execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
			myres = gcnew Resources::ResourceManager(ressrc,execAssem);
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			this->panelEx1->SuspendLayout();

			this->InitializePictureBox(type);
			this->acceptButton->Text = acceptButtonText;
			this->refuseButton->Text = refuseButtonText;
			this->ignoreButton->Text = ignoreButtonText;

			/*
			//To Be Processed
			this->acceptButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_highlight")));
			this->acceptButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->acceptButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_down")));

			this->refuseButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_highlight")));
			this->refuseButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_normal")));
			this->refuseButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_down")));
			*/

			this->acceptButton->Location = System::Drawing::Point(35, 140);
			this->refuseButton->Location = System::Drawing::Point(130, 140);
			this->ignoreButton->Location = System::Drawing::Point(225, 140);

			this->initiateNonClientButtons();
			this->panelEx1->ResumeLayout(false);
			isDown = false;
			this->content->Text =  contentInput;
		}
		// Initial some local variables

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~NotifyUserDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::PanelEx^  panelEx1;
	private: DevComponents::DotNetBar::Bar^  rightCornerFunctionBar;
	private: DevComponents::DotNetBar::ButtonItem^  minimizeButton;
	private: DevComponents::DotNetBar::ButtonItem^  closeButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: DevComponents::DotNetBar::LabelX^  content;

	private: DevComponents::DotNetBar::ButtonX^  acceptButton;
	private: DevComponents::DotNetBar::ButtonX^  ignoreButton;

	private: DevComponents::DotNetBar::ButtonX^  refuseButton;

	protected: 

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
			this->ignoreButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->refuseButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->content = (gcnew DevComponents::DotNetBar::LabelX());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->rightCornerFunctionBar = (gcnew DevComponents::DotNetBar::Bar());
			this->minimizeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->closeButton = (gcnew DevComponents::DotNetBar::ButtonItem());
			this->acceptButton = (gcnew DevComponents::DotNetBar::ButtonX());
			this->panelEx1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelEx1
			// 
			this->panelEx1->CanvasColor = System::Drawing::SystemColors::Control;
			this->panelEx1->ColorSchemeStyle = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->panelEx1->Controls->Add(this->ignoreButton);
			this->panelEx1->Controls->Add(this->refuseButton);
			this->panelEx1->Controls->Add(this->content);
			this->panelEx1->Controls->Add(this->pictureBox1);
			this->panelEx1->Controls->Add(this->rightCornerFunctionBar);
			this->panelEx1->Controls->Add(this->acceptButton);
			this->panelEx1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelEx1->Location = System::Drawing::Point(0, 0);
			this->panelEx1->Name = L"panelEx1";
			this->panelEx1->Size = System::Drawing::Size(342, 153);
			this->panelEx1->Style->Alignment = System::Drawing::StringAlignment::Center;
			this->panelEx1->Style->BackColor1->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBackground;
			this->panelEx1->Style->BackColor2->Color = System::Drawing::Color::White;
			this->panelEx1->Style->Border = DevComponents::DotNetBar::eBorderType::SingleLine;
			this->panelEx1->Style->BorderColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelBorder;
			this->panelEx1->Style->ForeColor->ColorSchemePart = DevComponents::DotNetBar::eColorSchemePart::PanelText;
			this->panelEx1->Style->GradientAngle = 90;
			this->panelEx1->TabIndex = 0;
			// 
			// ignoreButton
			// 
			this->ignoreButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->ignoreButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->ignoreButton->Location = System::Drawing::Point(248, 132);
			this->ignoreButton->Name = L"ignoreButton";
			this->ignoreButton->Size = System::Drawing::Size(69, 21);
			this->ignoreButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->ignoreButton->TabIndex = 18;
			this->ignoreButton->Text = L"忽略";
			this->ignoreButton->Click += gcnew System::EventHandler(this, &NotifyUserDlg::ignoreButton_Click);
			// 
			// refuseButton
			// 
			this->refuseButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->refuseButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->refuseButton->Location = System::Drawing::Point(31, 129);
			this->refuseButton->Name = L"refuseButton";
			this->refuseButton->Size = System::Drawing::Size(69, 21);
			this->refuseButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->refuseButton->TabIndex = 17;
			this->refuseButton->Text = L"拒绝";
			this->refuseButton->Click += gcnew System::EventHandler(this, &NotifyUserDlg::refuseButton_Click);
			// 
			// content
			// 
			// 
			// 
			// 
			this->content->BackgroundStyle->Class = L"";
			this->content->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->content->Font = (gcnew System::Drawing::Font(L"华文中宋", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->content->Location = System::Drawing::Point(80, 34);
			this->content->Name = L"content";
			this->content->Size = System::Drawing::Size(237, 75);
			this->content->TabIndex = 15;
			this->content->Text = L"abcde\ndfer";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(21, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(40, 40);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
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
			this->rightCornerFunctionBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->rightCornerFunctionBar->DockSide = DevComponents::DotNetBar::eDockSide::Document;
			this->rightCornerFunctionBar->Items->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->minimizeButton, 
				this->closeButton});
			this->rightCornerFunctionBar->Location = System::Drawing::Point(0, 0);
			this->rightCornerFunctionBar->Margin = System::Windows::Forms::Padding(0);
			this->rightCornerFunctionBar->MinimumSize = System::Drawing::Size(67, 18);
			this->rightCornerFunctionBar->Name = L"rightCornerFunctionBar";
			this->rightCornerFunctionBar->PaddingBottom = 0;
			this->rightCornerFunctionBar->PaddingLeft = 283;
			this->rightCornerFunctionBar->PaddingRight = 0;
			this->rightCornerFunctionBar->PaddingTop = 0;
			this->rightCornerFunctionBar->RoundCorners = false;
			this->rightCornerFunctionBar->SingleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->rightCornerFunctionBar->Size = System::Drawing::Size(342, 18);
			this->rightCornerFunctionBar->Stretch = true;
			this->rightCornerFunctionBar->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->rightCornerFunctionBar->TabIndex = 13;
			this->rightCornerFunctionBar->TabStop = false;
			this->rightCornerFunctionBar->Text = L"bar1";
			this->rightCornerFunctionBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &NotifyUserDlg::friendChatDlg_MouseUp);
			this->rightCornerFunctionBar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &NotifyUserDlg::friendChatDlg_MouseMove);
			this->rightCornerFunctionBar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &NotifyUserDlg::MoveDialog_MouseDown);
			// 
			// minimizeButton
			// 
			this->minimizeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->minimizeButton->ImagePaddingHorizontal = 0;
			this->minimizeButton->ImagePaddingVertical = 0;
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Text = L"小";
			this->minimizeButton->Click += gcnew System::EventHandler(this, &NotifyUserDlg::minimizeButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->ColorTable = DevComponents::DotNetBar::eButtonColor::Blue;
			this->closeButton->ImagePaddingHorizontal = 0;
			this->closeButton->ImagePaddingVertical = 0;
			this->closeButton->Name = L"closeButton";
			this->closeButton->Text = L"关闭";
			this->closeButton->Click += gcnew System::EventHandler(this, &NotifyUserDlg::closeButton_Click);
			// 
			// acceptButton
			// 
			this->acceptButton->AccessibleRole = System::Windows::Forms::AccessibleRole::PushButton;
			this->acceptButton->ColorTable = DevComponents::DotNetBar::eButtonColor::OrangeWithBackground;
			this->acceptButton->FocusCuesEnabled = false;
			this->acceptButton->Location = System::Drawing::Point(135, 115);
			this->acceptButton->Name = L"acceptButton";
			this->acceptButton->ShowSubItems = false;
			this->acceptButton->Size = System::Drawing::Size(69, 21);
			this->acceptButton->Style = DevComponents::DotNetBar::eDotNetBarStyle::StyleManagerControlled;
			this->acceptButton->TabIndex = 16;
			this->acceptButton->Text = L"接受";
			this->acceptButton->Click += gcnew System::EventHandler(this, &NotifyUserDlg::acceptButton_Click);
			// 
			// NotifyUserDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(342, 153);
			this->Controls->Add(this->panelEx1);
			this->MinimumSize = System::Drawing::Size(350, 180);
			this->Name = L"NotifyUserDlg";
			this->Text = L"NotifyUserDlg";
			this->TransparencyKey = System::Drawing::Color::White;
			this->panelEx1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rightCornerFunctionBar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void acceptButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = ::DialogResult::Yes;
			 this->Close();
		 }
private: System::Void refuseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = ::DialogResult::No;
			 this->Close();
		 }
private: System::Void ignoreButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = ::DialogResult::Ignore;
			 this->Close();
		 }

private: System::Void minimizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ReleaseCapture();
			 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MINIMIZE,MAKELPARAM(Control::MousePosition.X, Control::MousePosition.Y));
			 //Invalidate();
		 }
private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = ::DialogResult::Ignore;
			 this->Close();
		 }
private: System::Void initiateNonClientButtons(void){
			 this->minimizeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_highlight")));
			 this->minimizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_normal")));
			 this->minimizeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_mini_down")));
			 this->closeButton->HoverImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_highlight")));
			 this->closeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_normal")));
			 this->closeButton->PressedImage = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"btn_close_down")));
		 }
		
private:
	System::Void InitializePictureBox(OuSns::NotifyUIDlgType type){
		switch(type){

			case OuSns::WARNING_DLG:
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"sysmessagebox_warningFile")));
				break;
			case OuSns::INFORMATION_DLG:
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"sysmessagebox_inforFile")));
				break;
			case OuSns::QUESTION_DLG:
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"sysmessagebox_questionFile")));
				break;
			case OuSns::ERROR_DLG:
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"sysmessagebox_errorFile")));
				break;
			default:
				this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"sysmessagebox_errorFile")));

		}

		return;
	}

 protected: virtual void WndProc(Message % m) override{
				//RECT rc;
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
					*/
				default:
					System::Windows::Forms::Form::WndProc(m);
				}
				return;		
			}



	private: System::Void MoveDialog_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 isDown = true;
				 
			 }

	private: System::Void friendChatDlg_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(this->isDown){
					 ReleaseCapture();
					 SendMessage(this->Handle,WM_SYSCOMMAND, SC_MOVE+HTCAPTION,0);
				 }
			 }
	private: System::Void friendChatDlg_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 this->isDown = false;
			 }

};
}
