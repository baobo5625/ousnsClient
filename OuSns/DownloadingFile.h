#pragma once
//#include "stdafx.h"
//#include "DownloadingObject.h"

/*
 * This class represents a downloading file
 */
namespace OuSns{


	public ref class DownloadingFile{
	private:

		String^ fileName;
		array<Byte>^ fileNameByte;

		int32_t fileIndex;
		array<Byte>^ fileIndexByte;
		String^ filePath;
		array<Byte>^ filePathByte;
		/*
		* progress_ppm is a value in the range [0, 1000000], that represents 
		* the progress of the torrent's current task. It may be checking files or downloading.
		*/
		int32_t fileProgress;
		array<Byte>^ fileProgressByte;
		/*
		* This is the file size in KB
		*/
		int32_t fileSize;
		array<Byte>^ fileSizeByte;

		/*
		* The status of this job
		* 0 means stop
		* 1 means pause
		* 2 means running
		* 3 means error
		*/
		//char fileStatus;
		int totalByteArrayLength;

		//This is the indicator will be used to check if the structor is successfully created
		//Will be useful when created from a Byte array
		bool createdSuccessful;
	public:
		DownloadingFile(String^ fileName, int fileIndex,String^ filePath, int fileProgress, int fileSize){
			Encoding^ u16LE = Encoding::Unicode;
			this->fileName = fileName;
			this->fileNameByte = gcnew array<Byte>(MAX_PATH);
			u16LE->GetBytes(this->fileName)->CopyTo(this->fileNameByte,0);
			this->fileIndex = fileIndex;
			this->fileIndexByte = gcnew array<Byte>(sizeof(int32_t));
			BitConverter::GetBytes(this->fileIndex)->CopyTo(this->fileIndexByte,0);
			this->filePath = filePath;
			this->filePathByte = gcnew array<Byte>(MAX_PATH);
			u16LE->GetBytes(this->filePath)->CopyTo(this->filePathByte,0);
			this->fileProgress = fileProgress;
			this->fileProgressByte = gcnew array<Byte>(sizeof(int32_t));
			BitConverter::GetBytes(this->fileProgress)->CopyTo(this->fileProgressByte,0);
			this->fileSize = fileSize;
			this->fileSizeByte = gcnew array<Byte>(sizeof(int32_t));
			BitConverter::GetBytes(this->fileSize)->CopyTo(this->fileSizeByte,0);
			this->totalByteArrayLength = OUSNS_DOWNLOADING_FILE_LENGTH;
			this->createdSuccessful = true;
		}

		DownloadingFile(array<Byte>^ byteArray){
			if(byteArray->Length != OUSNS_DOWNLOADING_FILE_LENGTH){
				this->createdSuccessful = false;
			}
			else{
				try{
					Encoding^ u16LE = Encoding::Unicode;
					int byteArrayPtr = 0;
					this->fileNameByte = gcnew array<Byte>(MAX_PATH);
					Array::Copy(byteArray,byteArrayPtr,this->fileNameByte,0,MAX_PATH);
					this->fileName = u16LE->GetString(this->fileNameByte);
					this->filePathByte = gcnew array<Byte>(MAX_PATH);
					byteArrayPtr+=MAX_PATH;

					Array::Copy(byteArray,byteArrayPtr,this->filePathByte,0,MAX_PATH);
					this->filePath = u16LE->GetString(this->filePathByte);
					byteArrayPtr+=MAX_PATH;

					this->fileIndexByte = gcnew array<Byte>(sizeof(int32_t));
					Array::Copy(byteArray,byteArrayPtr,this->fileIndexByte,0,sizeof(int32_t));
					this->fileIndex = BitConverter::ToInt32(this->fileIndexByte,0);
					byteArrayPtr += sizeof(int32_t);

					this->fileSizeByte = gcnew array<Byte>(sizeof(int32_t));
					Array::Copy(byteArray,byteArrayPtr,this->fileSizeByte,0,sizeof(int32_t));
					this->fileSize =  BitConverter::ToInt32(this->fileSizeByte,0);
					byteArrayPtr += sizeof(int32_t);

					this->fileProgressByte = gcnew array<Byte>(sizeof(int32_t));
					Array::Copy(byteArray,byteArrayPtr,this->fileProgressByte,0,sizeof(int32_t));
					this->fileProgress = BitConverter::ToInt32(this->fileProgressByte,0);
					this->totalByteArrayLength = OUSNS_DOWNLOADING_FILE_LENGTH;
					this->createdSuccessful = true;
				}
				catch (Exception ^){
					this->createdSuccessful = false;
				}
			}
		}

		
	public:
		/* 
		 * The file name will not be updated, it will be used to confirm that it is the right file to update
		 */
		bool UpdateParam(String^ fileName,int fileProgress){
			if(fileName->CompareTo(this->fileName) == 0){
				if (fileProgress != this->fileProgress)
					BitConverter::GetBytes(fileProgress)->CopyTo(this->fileSizeByte,0);
				this->fileProgress = fileProgress;
				return true;
			}
			else 
				return false;

		}

		property String^ FileName{
			void set(String^ value){
				this->fileName = value;
			}
			String^ get(){
				return this->fileName;
			}
		}
		property int FileIndex{
			int get(){
				return this->fileIndex;
			}
		}
		property int FileProgress{
			void set(int value){
				this->fileProgress = value;
			}
			int get(){
				return this->fileProgress;
			}
		}
		property String^ FileProgressString{
			String^ get(){
				int32_t tempInt = this->fileProgress/100;
				double returnValue = (double)tempInt/100.0;
				return returnValue.ToString("F2");

			}
		}
		property int FileSize{
			void set(int value){
				this->fileSize = value;
			}
			int get(){
				return this->fileSize;
			}
		}

		property String^ FileSizeString{
			String^ get(){
				double fileSizeDouble;
				//KB
				if (this->fileSize < 1000){
					return this->fileSize.ToString() + "KB";
				}
				//MB
				else if(this->fileSize > 1000 && this->fileSize < 1000000){
					fileSizeDouble = this->fileSize/1000;
					return fileSizeDouble.ToString("F2") + "MB";
				}
				//GB
				else if(this->fileSize > 1000000 && this->fileSize < 1000000000){
					fileSizeDouble = this->fileSize/1000000;
					return fileSizeDouble.ToString("F2") + "GB";
				}
				else{
					fileSizeDouble = this->fileSize/1000000000;
					return fileSizeDouble.ToString("F2") + "TB";
				}
			}
		}

		property int TotalByteArrayLength{
			int get(){
				return this->totalByteArrayLength;
			}
		}

		property bool CreatedSuccessful{
			bool get(){
				return this->createdSuccessful;
			}
		}

		array<Byte>^ GetBytes(){
			array<Byte>^ returnByte = gcnew array<Byte>(this->totalByteArrayLength);
			int arrayPtr = 0;
			this->fileNameByte->CopyTo(returnByte,arrayPtr);
			arrayPtr += this->fileNameByte->Length;
			this->filePathByte->CopyTo(returnByte,arrayPtr);
			arrayPtr += this->filePathByte->Length;
			this->fileIndexByte->CopyTo(returnByte,arrayPtr);
			arrayPtr += this->fileIndexByte->Length;
			this->fileSizeByte->CopyTo(returnByte,arrayPtr);
			arrayPtr += this->fileSizeByte->Length;
			this->fileProgressByte->CopyTo(returnByte,arrayPtr);
			return returnByte;
		}

		



	};

}