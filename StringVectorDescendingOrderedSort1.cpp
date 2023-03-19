/**
 * @file StringVectorDescendingOrderedSort1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief There are two types of string vector sorted example
 * @version 0.1
 * @date 2023-03-19
 * @since SunDay; 08:00 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <vector>
#pragma pack(1)
using namespace std;

void lineBar(const char *const title){
	cout<<"\n---"<<title<<":----------------------------"<<endl;
}

void display(const vector<string> &stooges){
	cout<<"[ ";
	for_each(stooges.cbegin(), stooges.cend(),
		[](const string_view &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

void descendingOrderSortType1(vector <string> stooges){
	cout<<"Before sorted: ";
	display(stooges);
	sort(stooges.begin(), stooges.end());
	reverse(stooges.begin(), stooges.end());
	cout<<"After sorted: ";
	display(stooges);
}

void descendingOrderSortType2(vector <string> stooges){
	cout<<"Before sorted: ";
	display(stooges);
	
	sort(stooges.begin(), stooges.end(), greater<string>());
	
	cout<<"After sorted: ";
	display(stooges);
}


int main(int argc, const char *const argv[]){
	
	vector <string> stooges {"Larry", "Moe", "Curly"};
	lineBar("Type1");
	descendingOrderSortType1(stooges);
	
	
	lineBar("Type2");
	descendingOrderSortType2(stooges);
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}