/**
 * @file ContanerAdaptorStack1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Standard Template Library Stack [LIFO]
 * @version 0.1
 * @date 2023-03-26
 * @since SunDay; 05:54 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#pragma pack(1)
using namespace std;

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

/*This function displays a stack of by repeatedly topping and poping the stack*/
/*Not that the stack is passed in value so we don't affect the passed in stack*/

template <typename var>
void display(stack <var> myStack){
	cout<<"[ ";
	while(!myStack.empty()){
		cout<<myStack.top()<<" ";
		myStack.pop();  
	}
	cout<<"]"<<endl;
}


int main(int argc, const char *const argv[]){
    system("cls");
	headerSection("Stack");
	
	stack <int> s1{};
	stack <int, vector<int>> s2{};
	stack <int, list<int>> s3{};
	stack <int, deque<int>> s4{};
	
	for(const int &i: {1, 2, 3, 4, 5}){
		s1.push(i);
	}
	display(s1);
	cout<<endl;
	
	s1.emplace(100);
	display(s1);
	cout<<endl;
	
	s1.pop();
	s1.pop();
	display(s1);
	cout<<endl;
	
	while(!s1.empty()){
		s1.pop();
	}
	display(s1);
	
	s1.push(10);
	cout<<endl;
	
	display(s1);
	cout<<endl;
	
	s1.top() = 100;
	display(s1);

	footerSection("Stack");
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};