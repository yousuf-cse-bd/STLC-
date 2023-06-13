/**
 * @file IsEndWith.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check end with or not | C++ programming example
 * @version 0.1
 * @date 2023-06-13
 * @since SaturDay; 09:25 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

string subString(const string &str, const size_t &index, const size_t &strLength){
	
	string subString{""};
	for(size_t i{index}; i<strLength; i++){
		subString += str.at(i);
	}
	return subString;
}

/*First logic*/
bool isEndWith1(const string &str, const string &endOk){
	const size_t len1{str.length()};
	const size_t len2{endOk.length()};
	
	const size_t index{len1 - len2};
	
	return endOk == subString(str, index, len1);
}

/*Second logic*/
bool isEndWith2(const string &str, const string &endOk){
	const size_t strLen{str.length()};
	const size_t endLen{endOk.length()};
	
	if(strLen < endLen) return false;
	/*Here 1 more variable*/
	for(size_t i{strLen - endLen}, j{0}; i < strLen; i++, j++){
		if(str.at(i) != endOk.at(j)){
			return false;
		}
	}
	
	return true;
}

/*Portfolio Cources's Logic*/
bool isEndWith3(const string &str, const string &endOk){
	const size_t strLen{str.length()};
	const size_t endLen{endOk.length()};
	
	if(strLen < endLen) return false;
	/*Here 1 more operation*/
	for(size_t i{1}; i <= endLen; i++){
		if(str.at(strLen - i) != endOk.at(endLen - i)){
			return false;
		}
	}
	
	return true;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string myString {"Roses is red"};
	const string endOk{"red"};
	
	if(isEndWith1(myString, endOk)){
		cout<<"'"<<myString <<"' is end with: "<<endOk<<endl;
	}
	else{
		cout<<"'"<<myString <<"' is NOT end with: "<<endOk<<endl;
	}
	cout<<"----------------------------------------------"<<endl;
	
	if(isEndWith2(myString, endOk)){
		cout<<"'"<<myString <<"' is end with: "<<endOk<<endl;
	}
	else{
		cout<<"'"<<myString <<"' is NOT end with: "<<endOk<<endl;
	}
	
	cout<<"----------------------------------------------"<<endl;
	
	if(isEndWith3(myString, endOk)){
		cout<<"'"<<myString <<"' is end with: "<<endOk<<endl;
	}
	else{
		cout<<"'"<<myString <<"' is NOT end with: "<<endOk<<endl;
	}
	
    return 0;
}
