/**
 * @file AlgorithmCopyRemoveReplace1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Demonstrate remove_copy() and replace_copy() stl function
 * @version 0.1
 * @date 2023-04-01
 * @since SaturDay; 04:50 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    system("cls");
	
	const char *const str {"The STL is power programming"};
	cout<<"Original string: "<<str<<endl;
	vector <char> v1{}; /*v1 is empty vector and size 0*/
	vector <char> v2(30); /*v1 is empty vector and size 30*/
	
	for(size_t i{0}; *(str + i); i++){
		v1.emplace_back(*(str + i));
	}
	
	v1.shrink_to_fit();
	
	/*Demonstrate remove copy*/
	remove_copy(v1.begin(), v1.end(), v2.begin(), ' ');
	cout<<"Result after removing space: ";
	for_each(v2.cbegin(), v2.cend(),
		[](const char &x){
			cout<<x;
		}
	);
	cout<<endl;
	
	v2.shrink_to_fit();
	/*Now demonstrate replace copy*/
	
	for(size_t i{0}; *(str + i); i++){
		v1.emplace_back(*(str + i));
	}
	
	/*Replace space with colon*/
	replace_copy(v1.begin(), v1.end(), v2.begin(), ' ', ':');
	cout<<"Result after replace space: ";
	for_each(v2.cbegin(), v2.cend(),
		[](const char &x){
			cout<<x;
		}
	);
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};