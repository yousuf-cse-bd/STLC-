/**
 * @file STL_List4.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Merging- left list will be load & right list will be empty
 * @version 0.1
 * @date 2023-03-29
 * @since WednesDay; 08:54 AM
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
	list <int> lst2{}; /*Create an empty list*/
	
	for(int i{0}; i < 10; i++){
		(i & 1)?lst1.emplace_back(i):lst2.emplace_back(i);
	}
	
	cout<<"List1 contents(odd): ";
	list <int>:: const_iterator cit{lst1.cbegin()};
	while(cit != lst1.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	
	cout<<"List2 contents(even): ";
	cit = lst2.cbegin();
	while(cit != lst2.cend()){
		cout<<*cit<<" ";
		cit++;
	}
	cout<<endl;
	
	lst1.merge(lst2);
	
	cout<<"IsEmpty(lst2): "<<boolalpha<<lst2.empty()<<endl;	
	cout<<"Contents of lst1 after merge"<<endl;
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
