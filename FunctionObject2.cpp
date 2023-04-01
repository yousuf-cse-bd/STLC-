/**
 * @file FunctionObject2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Transform a list using a binary function object
 * @version 0.1
 * @date 2023-04-01
 * @since SaturDay; 08:03 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <functional> /*divides<double>(), binary function object*/
#pragma pack(1)
using namespace std;

template <typename var>
void display(const list <var> &myList){
	cout<<"[ ";
	for_each(myList.cbegin(), myList.cend(),
		[](const auto &x){
			cout<<x<<" ";
		}
	); 
	cout<<"]"<<endl;
}

int main(int argc, const char *const argv[]){
    system("cls");
	cout<<setprecision(2)<<fixed;
	
	list <double> list1{};
	list <double> divisors(10, 3.00); /*10's elements are 3.00*/
	
	for(size_t i{10}; i < 100; i+= 10){
		list1.emplace_back(static_cast<double>(i));
	}
	
	cout<<"Original contents: ";
	display(list1);
	cout<<endl;
	
	transform(list1.begin(), list1.end(), divisors.begin(), list1.begin(), divides<double>());
	
	cout<<"Divides contents: ";
	display(list1);
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};