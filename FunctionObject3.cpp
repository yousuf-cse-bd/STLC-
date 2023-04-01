/**
 * @file FunctionObject3.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Transform a list using a binary function object
 * @version 0.1
 * @date 2023-04-01
 * @since SaturDay; 08:56 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <functional> /*multiplies<data-type>(), binary function object*/
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
	
	list <unsigned int> list1{10 ,20, 30, 40, 50};
	list <unsigned int> mulipliers{1, 2, 3, 4, 5};
	
	cout<<"Original contents: ";
	display(list1);
	cout<<endl;
	
	cout<<"Multiplier contents: ";
	display(mulipliers);
	cout<<endl;
	
	/*10x1, 2x20, 3x30, 4x40, 5x50 and store the result in numbers3*/
	transform(list1.begin(), list1.end(), mulipliers.begin(), list1.begin(), multiplies<unsigned int>());
	
	cout<<"Product contents: ";
	display(list1);
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};