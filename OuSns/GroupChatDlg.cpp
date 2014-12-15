#include "StdAfx.h"
#include "GroupChatDlg.h"
#include "GroupListTab.h"
#include "Communication.h"
#include "MessageCreator.h"
#include "OusnsGroup.h"
#include "OusnsLoginUser.h"

using namespace OuSns;

GroupChatDlg::GroupChatDlg(GroupListTab^ parentInput, OusnsGroup ^ targetGroup, OusnsLoginUser ^ loginUser)
{
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//
	//Common part
	ressrc = L"OuSns.ImageResource";
	execAssem =  System::Reflection::Assembly::GetExecutingAssembly();
	myres = gcnew Resources::ResourceManager(ressrc,execAssem);
	this->isDown = false;
	this->loactionStyle = OuSns::S22_MIDDLECENTER;
	this->sidePanelDisplayed = true;
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
	this->_group = targetGroup;
	this->_loginUser = loginUser;
	this->_parent = parentInput;
	this->Text = this->_group->GroupName;
	this->UpdateGroupMemberList();
	this->groupNicknameLabelX->Text = this->_group->GroupName;
	OusnsMessage^ msg = this->_parent->msgCreator->MakeUpdateGroupMemberStatusMessage(this->_loginUser->UserID,this->_loginUser->SessionID,this->_group->GroupID);
	this->_parent->comm->AddToWorkQueue(msg);
}

System::Void GroupChatDlg::ExtendPanel_Click(System::Object^  sender, System::EventArgs^  e) {

	this->SuspendLayout();

	if (this->WindowState == FormWindowState::Maximized){
		if(this->sidePanelDisplayed == false){
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top ) 
				| System::Windows::Forms::AnchorStyles::Left));
			//this->Size = System::Drawing::Size(this->Size.Width + 200,this->Size.Height);
			//this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width+200,this->panelEx1->Size.Height);

			this->groupChatTabControl->Size = System::Drawing::Size(this->groupChatTabControl->Size.Width - 201,
				this->groupChatTabControl->Size.Height);
			this->panelEx4->Location = System::Drawing::Point(this->groupChatTabControl->Size.Width+1,103);
			this->panelEx4->Size = System::Drawing::Size(200,this->groupChatChattingSplitContainer->Size.Height);
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sidePanelDisplayed = true;
			this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexright_normal")));
		}
		else{
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelEx4->Size = System::Drawing::Size(0,0);

			//this->Size = System::Drawing::Size(this->Size.Width - 200,this->Size.Height);
			//this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width-200,this->panelEx1->Size.Height);
			this->groupChatTabControl->Size = System::Drawing::Size(this->groupChatTabControl->Size.Width + 201,
				this->groupChatTabControl->Size.Height);
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sidePanelDisplayed = false;
			this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexleft_normal")));
		}

	}
	else{
		if(this->sidePanelDisplayed == false){
			//Expanding
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top ) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->Size = System::Drawing::Size(this->Size.Width + 202,this->Size.Height);
			this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width+201,this->panelEx1->Size.Height);

			this->panelEx4->Location = System::Drawing::Point(this->groupChatTabControl->Size.Width+1,103);
			this->panelEx4->Size = System::Drawing::Size(200,this->groupChatChattingSplitContainer->Size.Height);
			//MessageBox::Show(this->friendChatChattingSplitContainer->Size.Height.ToString());
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sidePanelDisplayed = true;
			this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexright_normal")));
		}
		else{
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelEx4->Size = System::Drawing::Size(0,0);

			this->MinimumSize = System::Drawing::Size(this->MinimumSize.Width - 202, this->MinimumSize.Height);
			this->Size = System::Drawing::Size(this->Size.Width - 202,this->Size.Height);

			this->panelEx1->Size = System::Drawing::Size(this->panelEx1->Size.Width-201,this->panelEx1->Size.Height);
			this->groupChatTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sidePanelDisplayed = false;
			this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(myres->GetObject(L"aio_flexleft_normal")));
		}
	}
	this->ResumeLayout();


}


System::Void GroupChatDlg::PushNewMessage(ChatMessage ^msg){
	OusnsUser ^ srcUser = this->_loginUser->FindGroupMember(msg->srcID,msg->groupID);
	//OusnsGroup ^ srcGroup = this->_parent->FindGroup(msg->groupID);
	//this->friendChatDisplay->Text += srcFriend->nickname + " " + SAYS_CHN + "\n" + msg->text + "\n";
	System::Windows::Forms::RichTextBox ^ tempBox = gcnew System::Windows::Forms::RichTextBox();
	tempBox->AppendText(srcUser->nickname + " " + SAYS_CHN);
	String ^ appendString = tempBox->Rtf;
	String ^ chatHeader = ExtractTextFromRTF(appendString);
	String ^ chatContent = ExtractTextFromRTF(msg->text);
	//chatContent = "{\\f1\\cb1\\cf2 " + chatContent + "}";
	AppendTextToChatDisplay(chatHeader + " " + chatContent);
	//this->friendChatDisplay->Rtf = msg->text->Substring(0, msg->text->LastIndexOf("\\fs24") + 5) + " " + srcFriend->nickname + " " + 
	//	SAYS_CHN + "\\par " + msg->text->Substring(msg->text->LastIndexOf("\\fs24") + 5);
	//this->friendChatDisplay->Refresh();

}

System::Void GroupChatDlg::AppendTextToChatDisplay(String ^ content) {

	this->groupChatDisplay->Rtf = this->AppendTextToRTF(this->groupChatDisplay->Rtf, content);
	
	this->groupChatDisplay->SelectionStart = this->groupChatDisplay->Text->Length;
	this->groupChatDisplay->ScrollToCaret();
}
System::String ^ GroupChatDlg::ExtractTextFromRTF(String ^ rtfString) {

	// Extracts and returns the content of an rtf string.
	String ^ pattern = "\\\\fs\\d+";
	System::Text::RegularExpressions::MatchCollection ^ results = System::Text::RegularExpressions::Regex::Matches(rtfString, pattern);
	int cutStartPos = results[results->Count - 1]->Index + results[results->Count - 1]->Length;
	String ^ result = rtfString->Substring(cutStartPos)->Trim();
	result = result->Substring(0, result->Length - 1)->Trim();

	return result;
}


System::String ^ GroupChatDlg::AppendTextToRTF(String ^ rtfString, String ^ text){
	
	int cutPos = rtfString->LastIndexOf("\\par") + 4;

	String ^ newRtfString = rtfString->Substring(0, cutPos) + " " + text + rtfString->Substring(cutPos);

	return newRtfString;
}

System::Void GroupChatDlg::UpdateGroupMemberList(){
	DevComponents::AdvTree::Node^ member;
	OusnsGroupUser^ groupUser;
	this->advTree1->Nodes->Clear();
	for each(groupUser in this->_group->groupMemberArray){
		member = gcnew DevComponents::AdvTree::Node();
		member->Name = groupUser->UserID.ToString();
		member->Text = groupUser->Nickname  + "(" + groupUser->UserID.ToString() + ")" + OuSns::UserStatusIntToString(groupUser->Status);
		this->advTree1->Nodes->Add(member);
	}
	this->advTree1->Refresh();

}

System::Void GroupChatDlg::GroupChatDlg_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	 if (this->_parent->groupChatDlgDict->ContainsKey(this->_group->GroupID)) {
		 this->_parent->groupChatDlgDict->Remove(this->_group->GroupID);
	 } else {
		 MessageBox::Show(L"Error:User was already removed from the active window list.");
	 }
 }

System::Void GroupChatDlg::UpdateGroupMemberStatus(){
	this->UpdateGroupMemberList();
}