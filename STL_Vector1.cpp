/**
 * @file STL_Vector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Accessing a vector through an iterator
 * @version 0.1
 * @date 2023-03-12
 * @since SunDay; 12:25 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
	constexpr size_t limit{26};
	vector <char> alphabet(limit); /*Create vector of lenght 26*/
	vector <char> :: iterator p; /*Create an iteratior*/
	p = alphabet.begin();
	size_t i{0};
	while(p != alphabet.end()){
		*p = i + 'A';
		i++;
		p++;
	}
	/*Display contents of vector by iterrator*/
	cout<<"Original Contents: ";
	p = alphabet.begin();
	while(p != alphabet.end()){
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;
	
	/*Change the vector elements toUpper*/
	p = alphabet.begin();
	while(p != alphabet.end()){
		*p = toupper(*p);
		p++;
	}
	
	/*Display constents of vector by range-based for loop [DONE]*/
	cout<<"Modified Contents: ";
	for(const auto letter: alphabet){
		cout<<letter<<" ";
	}
	return 0;
}