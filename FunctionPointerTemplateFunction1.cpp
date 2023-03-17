/**
 * @file FunctionPointerTemplateFunction1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Template function and function pointer
 * @version 0.1
 * @date 2023-03-17
 * @since FriDay; 10:53 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

template <typename var>
const void add(const var x){
	cout<<"TypeID: "<<typeid(x).name()<<" = ";
	cout<<(x + x)<<endl;
}


int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	const void (*ptrFunction0)(const double) = add;
	(*ptrFunction0)(5);
	
	const void (*ptrFunction1)(const int) = add;
	(ptrFunction1)(10);
	
	const void (*ptrFunction2)(const string) = add;
	(*ptrFunction2)("Yousuf");
	
	cout<<"\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}