/**
 * @file BinarySearchAlgBuiltIn.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief The binary search algorithm - in different STL containers
 * @version 0.1
 * @date 2023-04-08
 * @since SaturDay; 05:55 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <deque>
#pragma pack(1)
using namespace std;


int main(int argc, const char *const argv[]){
    system("cls");
	cout<<setprecision(2)<<fixed;
	cout<<"In vector"<<endl;
	vector <int> v1{1, 4, 5, 5, 6, 7, 6, 9, 10, 4};
	if(binary_search(v1.cbegin(), v1.cend(), 4)){
		cout<<"4 is Found"<<endl;
	}
	else{
		cout<<"4 id NOT found"<<endl;
	}
	
	cout<<"In list"<<endl;
	list <int> l1{1, 4, 5, 5, 6, 7, 6, 9, 10, 4};
	if(binary_search(l1.cbegin(), l1.cend(), 4)){
		cout<<"4 is Found"<<endl;
	}
	else{
		cout<<"4 id NOT found"<<endl;
	}
	cout<<"In deque"<<endl;
	deque <int> d1{1, 4, 5, 5, 6, 7, 6, 9, 10, 4};
	if(binary_search(d1.cbegin(), d1.cend(), 4)){
		cout<<"4 is found"<<endl;
	}
	else{
		cout<<"4 is NOT found"<<endl;
	}
	
	cout<<"In set"<<endl;
	set <int> s1{1, 4, 5, 5, 6, 7, 6, 9, 10, 4};
	if(binary_search(s1.cbegin(), s1.cend(), 4)){
		cout<<"4 is found"<<endl;
	}
	else{
		cout<<"4 is NOT found"<<endl;
	}
	constexpr const char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	
	system("pause>0");
};