/**
 * @file STL_List2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Different between emplace_back() & emplace_front() in STL list
 * @version 0.1
 * @date 2023-03-28
 * @since TuesDay; 06:00 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <iomanip>
#pragma pack(1)
using namespace std;


int main(int argc, const char *const argv[]){
	system("cls");
	cout<<setprecision(2)<<fixed;
	
	list <int> lst1{}; /*Create an empty list, lst1*/
	list <int> lst2{}; /*Create an empty list, lst2*/
	for(int i{0}; i < 10; i++){
		lst1.emplace_back(i);
		lst2.emplace_front(i);
	}
	
	list <int>:: const_iterator cit{lst1.cbegin()};
	cout<<"Contents of lst1: ";
	while(cit != lst1.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	cout<<"------------------------------------------"<<endl;
	cit = lst2.begin();
	cout<<"Contents of lst2: ";
	while(cit != lst2.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
