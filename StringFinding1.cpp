/**
 * @file StringFinding1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief String finding using find(), rfind()
 * @version 0.1
 * @date 2023-04-02
 * @since SunDay; 04:52 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#pragma pack(1)
using namespace std;


int main(int argc, const char *const argv[]){
    system("cls");
	cout<<setprecision(2)<<fixed;

	string s1{"Quick of mind, Strong body, Pure of heart"};
	string s2{};
	
	size_t index {s1.find("Quick")};
	if(index != string :: npos){
		cout<<"Match found ('Quick') at: "<<index<<endl;
		cout<<"Remaining string: ";
		s2.assign(s1, index, s1.size());
		cout<<s2<<endl;
	}
	else{
		cout<<"Match NOT found!"<<endl;
	}
	cout<<endl;
	
	
	index = s1.find("Strong");
	if(index != string :: npos){
		cout<<"Match found ('Strong') at: "<<index<<endl;
		s2.assign(s1, index, s1.size());
		cout<<"Remaning string: "<<s2<<endl;
	}
	else{
		cout<<"Match NOT found!"<<endl;
	}
	cout<<endl;
	
	index = s1.find("Pure");
	if(index != string :: npos){
		cout<<"Match found ('Pure') at: "<<index<<endl;
		s2.assign(s1, index, s1.size());
		cout<<"Remaning string: "<<s2<<endl;
	}
	else{
		cout<<"Match NOT found!"<<endl;
	}
	cout<<endl;
	
	cout<<setw(50)<<setfill('-')<<""<<endl;
	cout<<endl;
	
	index = s1.rfind("of");
	if(index != string :: npos){
		cout<<"Match found ('of') at: "<<index<<endl;
		s2.assign(s1, index, s1.size());
		cout<<"Remaning string: "<<s2<<endl;
	}
	else{
		cout<<"Match NOT found!"<<endl;
	}
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};