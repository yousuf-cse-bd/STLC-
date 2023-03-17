/**
 * @file SimpleFindVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief The find algorithm tries to loacre the first occurremce of an element in a container
 * @version 0.1
 * @date 2023-03-17
 * @since FriDay; 10:50 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

/**
 * Algorithm: find() with primitive types
 * The find algorithm tries to locate the first occurrence of an element in a container
 * Lots of variations
 * Return an iterator pointing to the located element or end()
 */


int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	vector <int> number1{1, 2, 3};
	
	auto location {find(number1.cbegin(), number1.cend(), 3)};
	if(location != number1.cend()){
		cout<<"Found: "<<*location<<endl;
	}
	else{
		cout<<"Not found..!"<<endl;
	}
	
	cout<<"\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}