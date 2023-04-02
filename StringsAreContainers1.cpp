/**
 * @file StringsAreContainers1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief String manipulation using algorithm
 * @version 0.1
 * @date 2023-04-02
 * @since SunDay; 10:21 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    system("cls");
	
	string str1{"Strings handling is easy in C++"};	
	
	string :: const_iterator cit{str1.cbegin()};
	cout<<"Using iterator: ";
	while(cit != str1.cend()){
		cout<<*cit;
		cit++;
	}
	cout<<endl;
	cout<<"Using loop: ";
	for(size_t i{0}; i < str1.size(); i++){
		cout<<str1.at(i);
	}
	cout<<endl;
	
	cout<<"Count (i): "<<count(str1.cbegin(), str1.cend(), 'i')<<endl;
	
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	cout<<"ToUpper: "<<str1<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	
	system("pause>0");
};