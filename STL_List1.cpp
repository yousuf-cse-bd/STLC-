/**
 * @file STL_List1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Basic list with iterators and understanding end()
 * @version 0.1
 * @date 2023-03-28
 * @since TuesDay; 05:33 PM
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
	
	cout<<"List printed forwards: ";
	list <int> :: iterator it {lst.begin()};
	while(it != lst.end()){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	
	cout<<"List printed backwards: ";
	it = lst.end();
	while(it != lst.begin()){
		it--;
		cout<<*it<<" ";
	}
	cout<<endl;	
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
