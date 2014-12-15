
namespace OuSns{
/*
 * form class defines a return message basic structure
 */
	ref class OusnsMessage;
	ref class Communication;

public enum ActionType {LISTENMESSAGE, CHATMESSAGE, CHANGESTATUSPEER, LOGIN, LOGOFF, CHANGESTATUS, DOWNLOADLIST,
	REMOVEFRIEND, ADDFRIEND, REPLYADDFRIEND, SEARCHFRIEND, 
	SYSREMOVEFRIEND,SYSADDFRIEND, SYSREPLYADDFRIEND, ADDFRIENDDECISION, REPLYADDFRIENDNOTIFICATION, 
	CREATEGROUP, EXITGROUP, JOINGROUP, REPLYJOINGROUP,
	SYSJOINGROUP, SYSREPLYJOINGROUP, JOINGROUPDECISION, REPLYJOINGROUPNOTIFICATION,
	FOCUSUSER, REMOVEFOCUSUSER,
	HEARTBEATMSG, REQFILETRAN, REPFILETRAN, CANCELFILETRAN, HOLEPUNCHING,UPDATEJOB,ADDDOWNLOADERCOMMAND};

public enum UserIDType{OUSNS_USER=1,OUSNS_GROUP=2};
public enum LoginIDType{OUSNS_ID,OUSNS_EMAIL};
public enum UpdateEntryType{FILE_ENTRY,GROUP_CRAETE_ENTRY,JOIN_GROUP_ENTRY};
public enum DownloadJobStatus{JOB_RUNNING, JOB_PAUSED,JOB_STOPPED, JOB_FINISHED,JOB_WAITING,JOB_ERROR,JOB_UPLOADING};

public enum ThreadType {UI, WORK, LISTEN, SEND,DOWNLOADERCOMMUNICATOR};
public enum NotifyUIDlgType{QUESTION_DLG,INFORMATION_DLG,WARNING_DLG,ERROR_DLG};

public enum MessageType {REQUEST, RESPONSE, SYSMSG,INTERNALMSG, UNKNOWN};
public enum MessageStatus{SENDING,TIMEOUT,CREATED,SENT,REMOVE,PARTIAL,RECEIVED,FAILED};
public enum MouseLocationStyle{S11_LEFTTOP,S12_CENTERTOP,S13_RIGHTTOP,S21_MIDDLELEFT,S22_MIDDLECENTER,S23_MIDDLERIGHT,S31_LEFTBOTTOM,S32_CENTERBOTTOM,S33_RIGHTBOTTOM};
public enum UserStatus {OFFLINE, ONLINE, AWAY, BUSY, INVISIBLE};
public enum MessageFunctionCode{NORMAL,HEARTBEAT,P2P_NORMAL,P2P_NORMAL_ACK,P2P_SERVER_FORWARD,P2P_SERVER_FORWARD_ACK};
public enum FileTransferHaltReason {LOCAL_CANCEL, REMOTE_CANCEL, LOCAL_REJECT, REMOTE_REJECT, SUCCESS};
public enum Decision {DECISION_ACCEPT, DECISION_REJECT, DECISION_IGNORE};
public enum ModifyAction{ACTION_ADD,ACTION_MODIFY,ACTION_REMOVE};
public enum DownloaderCommand{DOWNLOADER_ADD_JOB = 97};
public enum NatType{
   StunTypeUnknown=0,
   StunTypeFailure,
   StunTypeOpen,
   StunTypeBlocked,

   StunTypeIndependentFilter,
   StunTypeDependentFilter,
   StunTypePortDependedFilter,
   StunTypeDependentMapping,

   //StunTypeConeNat,
   //StunTypeRestrictedNat,
   //StunTypePortRestrictedNat,
   //StunTypeSymNat,
   
   StunTypeFirewall,
};

public enum DownloadingFileState
{
	queued_for_checking,
	checking_files,
	downloading_metadata,
	downloading,
	finished,
	seeding,
	allocating,
	checking_resume_data
};

public enum FilePrivilege{FILE_PRIVILEGE_EVERYONE,FILE_PRIVILEGE_FOCUS,FILE_PRIVILEGE_FRIEND};

	/*
	 * form is the function that will return the mouse localtion style based on the 
	 * mouse location in the form
	 */
  MouseLocationStyle GetLocationStyle(Point^ mouseLocation, Form^ form);

  	   /// <summary>
        /// 根据鼠标位置类型，返回鼠标光标类型
        /// </summary>
        /// <param name="mouseStyle">鼠标位置类型</param>
        /// <returns>鼠标光标类型</returns>

   ::Cursor^ GetCursorByMouseLocationStyle(MouseLocationStyle mouseStyle);
   /*
    * This function will modify the form location and change the size of the form
	*/
   System::Void ChangeSize(Point mouseLocation, MouseLocationStyle mouseStyle, Form^ form);

	/*
	 * This function will process the click on the maximize/restore button
	 */
	System::Void MaximizeWindowButtonClick(Form^ form);

	/*
	 * This function will start up a new dialog that does not blocking the current UI thread
	 * The runningObject is the methods/constructor will be called, 
	 * args is the parameters will be passed into the methods/constructor
	 * The methods/constructor must have (Object^ args) as argument
	 * The dialog will add ousns message to work thread if necessary
	 */
	System::Void NewDialogNonBlocking(Object^ runningObject,Object^ args);

	/*
	 * This function will pop up a dialog and asking user a question
	 * the bubtonText array will decide how many buttons will be shown on the dialog
	 * and also the button texts.
	 * It will take 1 to 3 buttons, the first butotn is accept button,
	 * the second button is refuse button and the third button is ignore button.
	 * the type will decide what does the picture box look like
	 */
DialogResult NotifyUIBlocking(OuSns::NotifyUIDlgType type,String^ contentInput,array<String^>^ buttonText);

DialogResult SysMsgNotificationBlocking(String^ contentInput);

DialogResult SysMsgErrorInfoBlocking(String^ contentInput);

System::Void SysMsgNotificationNonBlocking(String^ contentInput);

System::Void SysMsgErrorInfoNonBlocking(String^ contentInput);

System::Void SysMsgNotificationThread(Object^ params);

System::Void SysMsgErrorInfoThread(Object^ params);

	/*
	 * This is the non blocking version of previous function
	 * This function will insert an INTERNAL message into the work queue
	 * and the message processor with the correspondent anction type
	 * will process the message (decide if need to continue)
	 */
 System::Void NotifyUINonBlocking(OuSns::NotifyUIDlgType type,String^ contentInput,
			array<String^>^ buttonText, OuSns::ActionType actionType, String^ messageID,
			String^ messageContent,IPAddress^ destIP, unsigned short destPort,Communication^ comm);


 /*
 * This is the non blocking version of previous function
 * This function will inser the message into work queue if the answer is yes
 * This function will take 2 buttons ONLY
 */
 System::Void NotifyUINonBlockingMsg(OuSns::NotifyUIDlgType type,String^ contentInput,\
	 array<String^>^ buttonText,OusnsMessage^ msg,Communication^ comm);


/*
* This is the running thread for the previous function
*/
System::Void NotifyUIThread(Object^ params);

/*
 * This is the user status from int to string 
 */
String^ UserStatusIntToString(OuSns::UserStatus status);


/*
* This is the running thread for the previous function
*/
System::Void NotifyUIThreadMsg(Object^ params);


}

