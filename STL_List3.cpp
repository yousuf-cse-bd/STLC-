/**
 * @file STL_List3.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Sort a list (ascending & descending ordered)
 * @version 0.1
 * @date 2023-03-29
 * @since WednesDay; 08:32 AM
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

	
	list <int> lst1{}; /*Create an empty list*/
	
	/*Create a list of random integers*/
	for(int i{0}; i < 10; i++){
		lst1.emplace_back(rand());
	}
	
	cout<<"Original contents: ";
	list <int>:: const_iterator cit{lst1.cbegin()};
	while(cit != lst1.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	
	lst1.sort(); /*Ascending order*/
	cout<<"Sorted contents1: ";
	cit = lst1.cbegin();
	while(cit != lst1.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	
	lst1.sort(greater<int>()); /*Descending order*/
	cout<<"Sorted contents2: ";
	cit = lst1.cbegin();
	while(cit != lst1.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
