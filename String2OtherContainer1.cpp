/**
 * @file String2OtherContainer1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Use a map of strings to create a phone directory
 * @version 0.1
 * @date 2023-04-02
 * @since SunDay; 10:42 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
#pragma pack(1)
using namespace std;

void displayMap(const map <string, string> &myMap){
	for_each(myMap.cbegin(), myMap.cend(),
		[](const auto &pairs){
			cout<<"[ "<<pairs.first<<" : "<<pairs.second<<" ]"<<endl;
		}
	);
}

int main(int argc, const char *const argv[]){
    system("cls");
	cout<<setprecision(2)<<fixed;
	
	map <string, string> directory{};
	
	directory.insert(make_pair("Tom", "555-4533"));
	directory.insert(pair <string, string>("Chris", "555-9778"));
	directory.insert(make_pair("John", "555-8195"));
	directory.insert(pair <string, string>("Rachel", "555-0809"));
	
	displayMap(directory);
	cout<<setw(50)<<setfill('-')<<""<<endl;
	
	string name{"John"};
	auto it{directory.find(name)};
	if(it != directory.end()){
		cout<<"Name: "<<it->first<<"\t"<<"PhoneNumber: "<<it->second<<endl;
	}
	else{
		cout<<"John NOT found...!"<<endl;
	}
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	
	system("pause>0");
};