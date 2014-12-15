#pragma once
//#include "stdafx.h"
#include "DownloadingFile.h"
/*
 * This class is the parent class of DownloadingFolder and DownloadingFile.
 * It represents the files/folders in the DownloadJob
 */

namespace OuSns{
	//ref class DownloadingFile;
	public ref class DownloadingJob{

	private:
		//This is the key to recognize the job from the torrent file
		String^ jobName;
		array<Byte>^ jobNameByte;

		/* 
		* This is the index for the job that in the download list
		* The index will starts from 0, the one in the top of the 
		* download list will have a larger index value
		* The bottom one has value 0
		*/

		int32_t jobIndex;
		array<Byte>^ jobIndexByte;

		// The path that relative to the downloadjob
		System::String^ jobPath;
		array<Byte>^ jobPathByte;

		System::String^ torrentFileName;
		array<Byte>^ torrentFileNameByte;

		int32_t magnetURILength;
		array<Byte>^ magnetURILengthByte;

		System::String^ magnetURI;
		array<Byte>^ magnetURIByte;



		/*
		* progress_ppm is a value in the range [0, 1000000], that represents 
		* the progress of the torrent's current task. It may be checking files or downloading.
		*/
		int32_t totalProgress_ppm;
		array<Byte>^ totalProgress_ppmByte;

		/*
		* the total number of KB of the file(s) that we have. All this does not necessarily has to be downloaded during this session (that's total_payload_download).
		*/
		int32_t totalDone;
		array<Byte>^ totalDoneByte;
		/*
		* The download rate is Bytes per second
		*/
		int32_t totalDownloadRate;

		/*
		* This is the total file size in KB
		*/
		int32_t jobSize;
		array<Byte>^ jobSizeByte;

		/* this is related to the libtorrent error code in the api file */
		int32_t jobError;

		/*
		* The status of this job
		enum the following:
		queued_for_checking,
		checking_files,
		downloading_metadata,
		downloading,
		finished,
		seeding,
		allocating,
		checking_resume_data
		*/
		int32_t jobLibtorrentStatus;
		int32_t jobPaused;
		int32_t peers;
		int32_t seeds;

		/*
		* the number of distributed copies of the torrent. Note that one copy may be spread out among many peers. It tells how many copies there are currently of the rarest piece(s) among the peers this client is connected to
		*/
		int32_t distributed_full_copies;

		/*
		*the share of pieces that have more copies than the rarest piece(s). Divide this number by 1000 to get the fraction
		*/
		int32_t distributed_fraction;
		/*
		*For example, if distributed_full_copies is 2 and distrbuted_fraction is 500, it means that the rarest pieces have only 2 copies among the peers this torrent is connected to, and that 50% of all the pieces have more than two copies.

		If we are a seed, the piece picker is deallocated as an optimization, and piece availability is no longer tracked. In this case the distributed copies members are set to -1.
		*/


		DateTime^ createdTime;
		array<Byte>^ createdTimeByte;

		DateTime^ finishedTime;
		array<Byte>^ finishedTimeByte;

		OuSns::DownloadJobStatus jobOuSnsStatus;

		bool createdSuccessful;

		int totalByteArrayLength;
	public:

		array<DownloadingFile^>^ files;
		array<Byte>^ filesByte;


	public:
		/* 
		* the download file array must be sorted based on the fileIndex
		*/
		//	DownloadingJob(String^ jobName, String^ jobPath,String^ torrentFileName, int magnetURILength,String^ magnetURI,int32_t jobError, int32_t jobSize,int32_t totalProgress_ppm,int32_t totalDownloadRate,
		DownloadingJob::DownloadingJob(String^ jobName, String^ jobPath,int32_t jobError, int32_t jobSize,int32_t totalProgress_ppm,int32_t totalDownloadRate,\
			int32_t totalDone,int32_t jobLibtorrentStatus,int32_t jobPaused,int32_t peers,int32_t seeds, int32_t distributed_full_copies, \
			int32_t distributed_fraction,LinkedList<DownloadingFile^>^ filesInput);
		/*
		* This is used to rebuild the downloading job dict from the download list file
		*/
		DownloadingJob(array<Byte>^ byteArray,int offset);
	public:
		void UpdateFinishedTime();
	public:
		void UpdateParams(int32_t jobError,int32_t totalProgress_ppm,int32_t totalDone,int32_t totalDownloadRate, int32_t jobLibtorrentStatus, int32_t jobPaused, int32_t jobPeer,\
			int32_t jobSeed, int32_t jobDistributedFullCopies, int32_t jobDistributedFriactions, LinkedList<DownloadingFile^>^ filesInput);
		void UpdateIndex(int jobIndex);
	public:
		property String^ JobName{
			String^ get(){
				return this->jobName;
			}
		}
		property String^ JobPath{
			String^ get(){
				return this->jobPath;
			}
		}
		property int32_t TotalDownloadRate{
			int32_t get(){
				return this->totalDownloadRate;
			}
		}
		property String^ TotalDownloadRateString{
			String^ get(){
				return this->SizeIntToString(double(this->totalDownloadRate)/1000) + "/s";
			}
		}

		property int32_t TotalDone{
			int32_t get(){
				return this->totalDone;
			}
		}
		property int32_t TotalProgress_ppm{
			int32_t get(){
				return this->totalProgress_ppm;
			}
		}
		property String^ JobTotalProgressString{
			String^ get(){
				int32_t tempInt = this->totalProgress_ppm/100;
				double returnValue = (double)tempInt/100.0;
				return returnValue.ToString("F2");

			}
		}
		property double JobTotalProgress{
			double get(){
				int32_t tempInt = this->totalProgress_ppm/100;
				double returnValue = (double)tempInt/100.0;
				return returnValue;
			}
		}

		property int32_t Seeds{
			int32_t get(){
				return this->seeds;
			}
		}
		property int32_t Peers{
			int32_t get(){
				return this->peers;
			}
		}
		property int32_t Distributed_fraction{
			int32_t get(){
				return this->distributed_fraction;
			}
		}
		property int32_t Distributed_full_copies{
			int32_t get(){
				return this->distributed_full_copies;
			}
		}
		property DateTime^ CreatedTime{
			DateTime^ get(){
				return this->createdTime;
			}
		}
		property String^ CreateTimeString{
			String^ get(){
				return this->createdTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
			}
		}
		property DateTime^ FinishedTime{
			DateTime^ get(){
				return this->finishedTime;
			}
			void set(DateTime^ value){
				this->finishedTime = value;
			}
		}
		property String^ FinishedTimeString{
			String^ get(){
				return this->finishedTime->ToString(System::Globalization::CultureInfo::CurrentCulture);
			}
		}
		property int JobLibtorrentStatus{
			int get(){
				return this->jobLibtorrentStatus;
			}
		}
		property int JobPaused{
			int get(){
				return this->jobPaused;
			}
		}
		property OuSns::DownloadJobStatus JobOuSnsStatus{
			OuSns::DownloadJobStatus get(){
				return this->jobOuSnsStatus;
			}
			void set(OuSns::DownloadJobStatus value){
				this->jobOuSnsStatus = value;
			}
		}

		property String^ JobOuSnsStatusString{
			String^ get(){
				switch (this->jobOuSnsStatus){
				case OuSns::JOB_RUNNING:
					return "任务下载中";
				case OuSns::JOB_PAUSED:
					return "Paused";
				case OuSns::JOB_STOPPED:
					return "任务停止";
				case OuSns::JOB_FINISHED:
					return "任务完成";
				case OuSns::JOB_WAITING:
					return "等待中";
				case OuSns::JOB_ERROR:
					return "任务错误";
				default:
					return "任务停止";
				}
			}
		}

		property int32_t JobSize{
			int32_t get(){
				return this->jobSize;
			}
		}

		property String^ JobSizeString{
			String^ get(){
				return this->SizeIntToString(this->jobSize);
			}
		}
		property int JobError{
			int get(){
				return this->jobError;
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

		String^ SizeIntToString(double inputValue);

		/* better to be called by the work thread */
		array<Byte>^ DownloadingJob::GetBytes();

	};

}
