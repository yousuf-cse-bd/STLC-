/**
 * @file FunctionObject1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Transform a list using unary function object
 * @version 0.1
 * @date 2023-04-01
 * @since SaturDay; 07:40 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <functional> /*negate<double>(), unary function object*/
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
	
	list <double> list1{}; /*This is an empty list-> list1*/
	for(size_t i{1}; i < 10; i ++){
		list1.emplace_back(static_cast<double>(i));
	}
	
	cout<<"Orginal contenst: ";
	display(list1);
	cout<<endl;
	
	transform(list1.begin(), list1.end(), list1.begin(), negate<double>());
	cout<<"Negated contenst: ";
	display(list1);
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};