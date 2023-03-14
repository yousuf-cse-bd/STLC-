/**
 * @file MakePairUsingTemplateClass.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Create custom pair using structure and class template
 * @version 0.1
 * @date 2023-03-14
 * @since TuesDay; 10:02 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

template <typename dataType1, typename dataType2>
struct MyPair{
	dataType1 term1{};
	dataType2 term2{};
	friend void operator<< (ostream &cout, const MyPair &myPair){
		cout<<"["<<myPair.term1<<" : "<<myPair.term2<<"]\n";
	}
};

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	MyPair <string, int> p0{"Yousuf", 101};
	cout<<p0;
	MyPair <int, double> p1{124, 3.14159};
	cout<<p1;
	MyPair <string, string> p2{"Youauf", "Ali"};
	cout<<p2;
	
    return 0;
}