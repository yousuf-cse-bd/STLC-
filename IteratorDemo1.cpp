/**
 * @file IteratorDemo1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Some types of iterator with vector, list, set and map
 * @version 0.1
 * @date 2023-03-17
 * @since FriDay; 09:22 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
#include <vector> /*As like array*/
#include <set> /*As like array but not store dulicate element*/
#include <list> /*As like doubly link-list*/
#include <map> /*As like dictionary*/
#pragma pack(1)
using namespace std;

inline const void lineBar(void){
	cout<<"==========================================="<<endl;
}

/*Display any vector of integers using range-based for loop*/
inline const void display(const vector <int> &v){
	cout<<"[ ";
	for(const auto &element: v){
		cout<<element<<" ";
	}
	cout<<"]";
	cout<<endl;
}

inline void test1(void){
	lineBar();
	vector <int> numbers1{10, 20, 30, 40, 50};
	auto it{numbers1.begin()}; /*Point to 0 index*/
	cout<<*it<<endl; /*10*/
	it++; /*Point to 1st index*/
	cout<<*it<<endl; /*20*/
	
	it += 2; /*Point 3rd index*/
	cout<<*it<<endl; /*40*/
	
	it -= 2; /*Point 1st index*/
	cout<<*it<<endl; /*20*/
	
	it = numbers1.end()-1; /*Point to 4th*/
	cout<<*it<<endl; /*50*/
}

inline void test2(void){
	lineBar();
	/*Display all vector elements using iterator*/
	vector <int> numbers1{10, 20, 30, 40, 50};
	vector <int> :: iterator it {numbers1.begin()}; /*Same*/
//	auto it{numbers1.begin()}; /*Same*/
	while(it != numbers1.end()){
		cout<<*it++<<" "; /*Do use pre-increament(pre-fix)*/
	}
	cout<<endl;
	
	/*Change the vector elements*/
	it = numbers1.begin();
	while(it != numbers1.end()){
		*it = 0;
//		cout<<*it<<" "; /*Printable*/
		it++;
	}
	display(numbers1);
}

inline void test3(void){
	lineBar();
	/*Using const-iterator*/
	vector <int> numbers1{10, 20, 30, 40, 50};
//	vector <int> :: const_iterator it1{numbers1.cbegin()}; /*Same*/
	auto it1 {numbers1.cbegin()}; /*Same*/
	while(it1 != numbers1.cend()){
		cout<<*it1++<<" ";
	}
	cout<<endl;
	/*Compiler error when ew try to change element*/
	it1 = numbers1.cbegin(); /*Here does not matter begin() | cbegin()*/
	while(it1 != numbers1.cend()){
//		*it1 = 0; /*Compiler error-read only*/
		it1++;
	}
	/*Therefore, we can not change any element by constant-iterator*/
}

inline void test4(void){
	/*Using reverse iterator*/
	lineBar();
	vector <int> numbers1 {10, 20, 30, 40, 50};
	/*The reverse-iterator over vector of ints start last index by rbegin()*/
	vector <int> :: reverse_iterator it1{numbers1.rbegin()}; /*Must be rbegin()*/
//	auto it1{numbers1.rbegin()};
	while(it1 != numbers1.rend()){
		cout<<*it1++<<" ";
	}
	cout<<endl;
	
	/*The const-reverse-iterator over a list*/
	list <string> names{"Larry","Moe", "Curly"};
	list <string> :: const_reverse_iterator it2{names.crbegin()}; /*Same*/
//	auto it2{names.crbegin()}; /*Same*/
	cout<<*it2<<endl; /*Curly*/
	
	it2++;
	cout<<*it2<<endl; /*Moe*/
	
	/*The iterator over a map*/
	map <string, string> favorites{
		{"Frank", "C++"},
		{"Bill", "Java"},
		{"James", "Haskell"}
	};
	auto it3 {favorites.begin()};
	while(it3 != favorites.end()){ /*Iterator over map of string, string pairs*/
		cout<<it3->first<<" : "<<it3->second<<endl;
		it3++;
	}
}

inline void test5(void){
	/*Iterator over a subset of a container*/
	lineBar();
	vector <int> number1(10);
	cout<<"Main set: ";
	for(size_t i{0}; i < number1.size(); i++){
		number1.at(i) = i+1;
		cout<<number1.at(i)<<" ";
	}
	cout<<"\nSubset: ";
	auto start {number1.cbegin()+2};
	auto stop {number1.cend()-3};
	while(start != stop){
		cout<<*start++<<" ";
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
	cout<<setprecision(2)<<fixed;
	test1();
	test2();
	test3();
	test4();
	test5();
	cout<<setw(30)<<right<<"HappyEnding...!"<<endl;
	return 0;
}
