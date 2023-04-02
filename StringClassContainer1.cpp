/**
 * @file StringClassContainer1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief String class container with insert(), erase() & replace() methods
 * @version 0.1
 * @date 2023-04-02
 * @since SunDay; 04:23 PM
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
	cout<<setprecision(2)<<fixed;

	string str1{"string handling C++ style"};
	string str2{"STL Power"};
	
	cout<<"Initial strings"<<endl;
	cout<<"str1: "<<str1<<endl;
	cout<<"str2: "<<str2<<endl;
	
	/*Demonstrate insert()*/
	cout<<"Insert str2 into str1"<<endl;
	str1.insert(7, str2);
	cout<<"str1: "<<str1<<endl;
	
	/*Demonstrate erase()*/
	cout<<"Remove 9 characters from str1"<<endl;
	str1.erase(7, 9);
	cout<<"str1: "<<str1<<endl;
	
	/*Demonstrate replace()*/
	cout<<"Replace 8 characters in str1 with str2"<<endl;
	str1.replace(7, 8, str2);
	cout<<"str1: "<<str1<<endl;
	
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};