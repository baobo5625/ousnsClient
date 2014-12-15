

/*
 * This class defines a parent class of users
 */
#pragma once

//#include "stdafx.h"


namespace OuSns{
	public ref class OusnsUser
	{
		//Use this after version 0.6.6
	public:
		OusnsUser(unsigned int userID,System::String^ email, 
			String^ nickname, String^ signature, String^ displayPictureFilename,
			int exp, unsigned int focusCounter,
			String^ personalStatement, String^ city, String^ province, 
			String^ country,
			int sex,int zodiac,unsigned short birthYear,
			unsigned short birthMonth, unsigned short birthDay){
				this->userID = userID;
				this->email = email;
				this->nickname = nickname;
				this->signature = signature;
				this->displayPictureFilename = displayPictureFilename;
				this->exp = exp;
				//	this->sharedNumberOfFiles = sharedNumberOfFiles;
				this->focusCounter = focusCounter;
				this->personalStatement = personalStatement;
				this->city = city;
				this->province = province;
				this->country = country;
				//this->ipAddr = ipaddr;
				//this->recvPort = recvPort;
				this->sex = sex;
				this->birthYear = birthYear;
				this->birthMonth = birthMonth;
				this->birthDay = birthDay;
				this->zodiac = zodiac;
		}

	public:
		~OusnsUser(void){}

	public:

		unsigned int userID;
		System::String^ email;

		System::String^ nickname;
		System::String^ signature;
		System::String^ displayPictureFilename;

		int exp;
		//unsigned int sharedNumberOfFiles;
		unsigned int focusCounter;
		System::String^ personalStatement;

		System::String^ city;
		System::String^ province;
		System::String^ country;

		//user ip address information
		
		//unsigned short sendPort;
		int sex;
		//Use this to calculate 
		unsigned short birthYear;
		unsigned short birthMonth;
		unsigned short birthDay;

		int zodiac;

		
	



	public:
		/*
		* This function will connect to the server and get their user DP
		*/
		void GetDisplayPicture(void){}

		void UpdateUserInformation(System::String^ email, 
			String^ nickname, String^ signature, String^ displayPictureFilename,
			int exp, unsigned int focusCounter,
			String^ personalStatement, String^ city, String^ province, 
			String^ country,
			int sex,int zodiac,unsigned short birthYear,
			unsigned short birthMonth, unsigned short birthDay){
				this->email = email;
				this->nickname = nickname;
				this->signature = signature;
				this->displayPictureFilename = displayPictureFilename;
				this->exp = exp;
				//	this->sharedNumberOfFiles = sharedNumberOfFiles;
				this->focusCounter = focusCounter;
				this->personalStatement = personalStatement;
				this->city = city;
				this->province = province;
				this->country = country;
				//this->ipAddr = ipaddr;
				//this->recvPort = recvPort;
				this->sex = sex;
				this->birthYear = birthYear;
				this->birthMonth = birthMonth;
				this->birthDay = birthDay;
				this->zodiac = zodiac;
		}

		property unsigned int UserID{
			unsigned int get(){
				return this->userID;
			}
		}

		property String^ Email{
			String^ get(){
				return this->email;
			}
			Void set(String^ email){
				this->email = email;
			}
		}

		property String^ Nickname{
			String^ get(){
				return this->nickname;
			}
			Void set(String^ nickname){
				this->nickname = nickname;
			}
		}

		property String^ Signature{
			String^ get(){
				return this->signature;
			}
			void set (String^ value){
				this->signature = value;
			}
		}

		property String^ DisplayPictureFilename{
			String^ get(){
				return this->displayPictureFilename;
			}
			void set(String^ value){
				this->displayPictureFilename = value;
			}
		}

		property int Exp{
			int get(){
				return this->exp;
			}
			void set(int value){
				this->exp = value;
			}
		}

		property int FocusCounter{
			int get(){
				return this->focusCounter;
			}
			void set (int value){
				this->focusCounter = value;
			}
		}

		property String^ PersonalStatement{
			String^ get(){
				return this->personalStatement;
			}
			void set(String^ value){
				this->personalStatement = value;
			}
		}

		property String^ City{
			String^ get(){
				return this->city;
			}
			void set(String^ value){
				this->city = value;
			}
		}

		property String^ Province{
			String^ get(){
				return this->province;
			}
			void set(String^ value){
				this->province = value;
			}
		}

		property String^ Country{
			String^ get(){
				return this->country;
			}
			void set(String^ value){
				this->country = value;
			}
		}

		
		property String^ Sex{
			String ^ get(){
				switch (this->sex){
				case 0:
					return SEX_UNKNOWN;
					break;
				case 1:
					return SEX_MALE;
					break;
				case 2:
					return SEX_FEMALE;
					break;
				default:
					return SEX_UNKNOWN;

				}
			}

		}
		property int SexInt{
			int get(){
				return this->sex;
			}
			void set(int value){
				this->sex = value;
			}
		}

		property unsigned short BirthYear{
			unsigned short get(){
				return this->birthYear;
			}
			void set (unsigned short value){
				this->birthYear = value;
			}
		}

		property unsigned short BirthMonth{
			unsigned short get(){
				return this->birthMonth;
			}
			void set(unsigned short value){
				this->birthMonth = value;
			}
		}

		property unsigned short BirthDay{
			unsigned short get(){
				return this->birthDay;
			}
			void set(unsigned short value){
				this->birthDay = value;
			}
		}
		property String^ Zodiac{
			String^ get(){
				switch (this->zodiac){
				case 1:
					return ZODIAC_ARIES;
					break;
				case 2:
					return ZODIAC_TAURUS;
					break;
				case 3:
					return ZODIAC_GEMINI;
					break;
				case 4:
					return ZODIAC_CANCER;
					break;
				case 5:
					return ZODIAC_LEO;
					break;
				case 6:
					return ZODIAC_VIRGO;
					break;
				case 7:
					return ZODIAC_LIBRA;
					break;
				case 8:
					return ZODIAC_SCORPIO;
					break;
				case 9:
					return ZODIAC_SAGITTARIUS;
					break;
				case 10:
					return ZODIAC_CAPRICORN;
					break;
				case 11:
					return ZODIAC_AQUARIUS;
					break;
				case 12:
					return ZODIAC_PISCES;
					break;
				default:
					return ZODIAC_UNKNOWN;
				}
			}

		}

		property int ZodiacInt{
			int get(){
				return this->zodiac;
			}
			void set(int value){
				this->zodiac = value;
			}
		}

	};

}
