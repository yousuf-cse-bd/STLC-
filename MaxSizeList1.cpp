/**
 * @file MaxSizeList1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Find max-size from severale C++ data-type using max_size() method
 * @version 0.1
 * @date 2023-03-22
 * @since WednesDay; 10:49 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#pragma pack(1)
using namespace std;

void listMaxSize(void){
	list <char> li0{};
	cout<<"Max-Size of <char> list: "<<li0.max_size()<<endl;
	cout<<endl;
	
	list <unsigned char> li1{};
	cout<<"Max-Size of <unsigned char> list: "<<li1.max_size()<<endl;
	cout<<endl;
	
	list <short> li2{};
	cout<<"Max-Size of <short> list: "<<li2.max_size()<<endl;
	cout<<endl;
	
	list <unsigned short> li3{};
	cout<<"Max-Size of <unsigned short> list: "<<li3.max_size()<<endl;
	cout<<endl;
	
	list <int> li4{};
	cout<<"Max-Size of <int> list: "<<li4.max_size()<<endl;
	cout<<endl;
	
	list <unsigned int> li5{};
	cout<<"Max-Size of <unsigned int> list: "<<li5.max_size()<<endl;
	cout<<endl;
	
	list <float> li6{};
	cout<<"Max-Size of <float> list: "<<li6.max_size()<<endl;
	cout<<endl;
	
	list <double> li7{};
	cout<<"Max-Size of <double> list: "<<li7.max_size()<<endl;
	cout<<endl;
	
	list <long double> li8{};
	cout<<"Max-Size of <long double> list: "<<li8.max_size()<<endl;
	cout<<endl;
	
	list <size_t> li9{};
	cout<<"Max-Size of <size_t> list: "<<li9.max_size()<<endl;
	cout<<endl;
	
	list <ssize_t> li10{};
	cout<<"Max-Size of <ssize_t> list: "<<li10.max_size()<<endl;
	cout<<endl;
	
	list <string> li11{};
	cout<<"Max-Size of <string> list: "<<li11.max_size()<<endl;
	cout<<endl;
	
	list <string_view> li12{};
	cout<<"Max-Size of <string_view> list: "<<li12.max_size()<<endl;
}

/*Driver code*/
int main(int argc, const char *const argv[]){
	
	listMaxSize();
	cout<<setw(35)<<"HappyEnding!!!"<<endl;
	return 0;
}