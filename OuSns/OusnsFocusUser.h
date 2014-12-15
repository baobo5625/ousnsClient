
#include "OusnsUser.h"
namespace OuSns{
	public ref class OusnsFocusUser: public OuSns::OusnsUser
	{
	public:
		array<String^>^ autoDownloadFileExtentions;
		OusnsFocusUser(unsigned int userID,String^ nickname,String^ displayPictureFilename,
			String^ autoDownloadFileExtentionString):
		OusnsUser(userID,"",nickname,"",displayPictureFilename,0,0,"","","","",0,0,1900,1,1){
			this->autoDownloadFileExtentions = displayPictureFilename->Split(gcnew array<Char>(1){'|'},StringSplitOptions::RemoveEmptyEntries);
		}

	};
}