/**
 * @file STL_Vector2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Uses of insert() & erase() methods
 * @version 0.1
 * @date 2023-03-13
 * @since MonDay; 05:35 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <iomanip>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
	constexpr size_t limit{10};
	vector <char> v1(limit);
	vector <char> v2{};
	const char *const str {"<vector>"};
	/*Initialize of v1*/
	for(size_t i{0}; i < limit; i++){
		v1.at(i) = i + 'a';
	}
	cout<<"Orginal contents of v1: ";
	for(const auto &x: v1){
		cout<<x<<" ";
	}
	cout<<endl;
	
	/*Copy characters in str into v2*/
	for(size_t i{0}; *(str + i) != '\0'; i++){
		v2.push_back(*(str + i));
	}
	/*Dispaly v2*/
	cout<<"v2 = ";
	for(const auto &x: v2){
		cout<<x<<" ";
	}
	cout<<endl;
	vector <char> :: iterator p{v1.begin()};
	p += 2; // Pointing to 3rd position
	v1.insert(p, 10, 'x'); //10 times of X
	cout<<"Size after inserting X's = "<<v1.size()<<endl;
	cout<<"Contents after insert: ";
	for(const auto &x: v1){
		cout<<x<<" ";
	}
	cout<<endl;
	
	/*Remove those elements*/
	p = v1.begin();
	p +=2;
	v1.erase(p, p+10); //Removed next 10 elements
	cout<<"Size after erased: "<<v1.size()<<endl;
	cout<<"Contents after erased: ";
	for(const auto &x: v1){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	p = v1.begin();
	p += 2;
	v1.insert(p, v2.begin(), v2.end()); /*This is interesting way*/
	cout<<"Size after insertion of v1: "<<v1.size()<<endl;
	cout<<"Contents after insertion: ";
	for(const auto &x: v1){
		cout<<x<<" ";
	}
	cout<<endl;
	v1.clear();
	v2.clear();
    cout<<boolalpha;
    cout<<v1.empty()<<endl;
    cout<<v2.empty()<<endl;
	cout<<"\t\t\tHapyEnding!!!"<<endl;
	return 0;
}
