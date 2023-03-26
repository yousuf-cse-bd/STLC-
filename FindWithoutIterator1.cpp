/**
 * @file FindWithoutIterator1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief In associative container need not iterator to use find() method
 * @version 0.1
 * @date 2023-03-26
 * @since SunDay; 07:56 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#pragma pack(1)
using namespace std;

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

void testSet(void){
	headerSection("Test Set");

	set <int> s1{1, 3, 4, 5, 3};
	cout<<"[ ";
	for_each(s1.cbegin(), s1.cend(),
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	if(s1.find(5) != s1.cend()){
		cout<<"The 5 is found."<<endl;
	}
	else{
		cout<<"The 5 is NOT found"<<endl;
	}

	footerSection("Test Set");
}

void testMap(void){
	headerSection("Test Map");
	map <string, string> m1{
		{"Bob", "Butcher"},
		{"Anne", "Baker"},
		{"George", "Candlestick maker"}
	};
	
	if(m1.find("Bob") != m1.cend()){
		cout<<"Bob is found."<<endl;
	}
	else{
		cout<<"Bob is not found."<<endl;
	}
	
	footerSection("Test Map");
}

int main(int argc, const char *const argv[]){
    system("cls");
	testSet();
	testMap();
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};;