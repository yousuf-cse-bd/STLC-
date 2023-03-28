/**
 * @file STL_List0.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Basic list with iterators
 * @version 0.1
 * @date 2023-03-28
 * @since TuesDay; 05:19 PM
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
	
	list <int> lst{}; /*Create an empty list*/
	for(int i{0}; i < 10; i++){
		lst.emplace_back(i);
	}
	
	cout<<"Size of lst: "<<lst.size()<<endl;
	
	cout<<"Contents: ";
//	list <int> :: const_iterator it{lst.cbegin()};
	auto it{lst.begin()};
	while(it != lst.end()){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	
	/*Change contents of the list*/
	it = lst.begin();
	while(it != lst.end()){
		*it += 100;
		it++;
	}
	
	cout<<"Contents modified: ";
	it = lst.begin();
	while(it != lst.end()){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	
	cout<<"Reverse order1: ";
	auto it1 = lst.rbegin();
	while(it1 != lst.rend()){ /*This is good practice*/
		cout<<*it1<<" ";
		it1++;
	}
	cout<<endl;
	
	cout<<"Reverse order2: ";
	it = lst.end();
	it--;
	while(true){ /*This is not good practice*/
		if(it == lst.begin()){
			cout<<*it<<" ";
			break;
		}
		cout<<*it<<" ";
		it--;
	}
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
