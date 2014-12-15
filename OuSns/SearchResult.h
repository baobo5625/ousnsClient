#include "stdafx.h"
namespace OuSns{

	public ref class SearchResult{
	private:Dictionary<String^, String^>^ searchResult;
	public:
		SearchResult(){
			this->searchResult = gcnew Dictionary<String^,String^>();
		}
		~SearchResult(){}
		String^ Get(String^ key){
			return this->searchResult[key];
		}
		void Set(String^ key, String^ value){
			this->searchResult[key] = value;
		}
	};

}