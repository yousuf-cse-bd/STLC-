/**
 * @file MaxSizeDeques1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Find max-size from severale C++ data-type using max_size() method
 * @version 0.1
 * @date 2023-03-22
 * @since WednesDay; 11:17 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <deque>
#pragma pack(1)
using namespace std;

void dequeMaxSize(void){
	deque <char> de0{};
	cout<<"Max-Size of <char> deque: "<<de0.max_size()<<endl;
	cout<<endl;
	
	deque <unsigned char> de1{};
	cout<<"Max-Size of <unsigned char> deque: "<<de1.max_size()<<endl;
	cout<<endl;
	
	deque <short> de2{};
	cout<<"Max-Size of <short> deque: "<<de2.max_size()<<endl;
	cout<<endl;
	
	deque <unsigned short> de3{};
	cout<<"Max-Size of <unsigned short> deque: "<<de3.max_size()<<endl;
	cout<<endl;
	
	deque <int> de4{};
	cout<<"Max-Size of <int> deque: "<<de4.max_size()<<endl;
	cout<<endl;
	
	deque <unsigned int> de5{};
	cout<<"Max-Size of <unsigned int> deque: "<<de5.max_size()<<endl;
	cout<<endl;
	
	deque <float> de6{};
	cout<<"Max-Size of <float> deque: "<<de6.max_size()<<endl;
	cout<<endl;
	
	deque <double> de7{};
	cout<<"Max-Size of <double> deque: "<<de7.max_size()<<endl;
	cout<<endl;
	
	deque <long double> de8{};
	cout<<"Max-Size of <long double> deque: "<<de8.max_size()<<endl;
	cout<<endl;
	
	deque <size_t> de9{};
	cout<<"Max-Size of <size_t> deque: "<<de9.max_size()<<endl;
	cout<<endl;
	
	deque <ssize_t> de10{};
	cout<<"Max-Size of <ssize_t> deque: "<<de10.max_size()<<endl;
	cout<<endl;
	
	deque <string> de11{};
	cout<<"Max-Size of <string> deque: "<<de11.max_size()<<endl;
	cout<<endl;
	
	deque <string_view> de12{};
	cout<<"Max-Size of <string_view> dest: "<<de12.max_size()<<endl;
}


int main(int argc, const char *const argv[]){
	
	dequeMaxSize();
	cout<<setw(35)<<"HappyEnding!!!"<<endl;
	return 0;
}