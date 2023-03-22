/**
 * @file DequeChallenge1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check palindrome string using deque <char> from vector <string>
 * @version 0.1
 * @date 2023-03-22
 * @since WednesDay; 10:56 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
#pragma pack(1)
using namespace std;

string onlyAlphabets(const string &str){
	string alphabets{};
	for(size_t i{0}; i < str.length(); i++){
		if(isalpha(str.at(i))){
			alphabets.push_back(toupper(str.at(i)));
		}
	}
	alphabets.shrink_to_fit();
	return alphabets;
}

bool isPalindrome(const string &str){
//	string originStr{onlyAlphabets(str)};
//	/*String reverse using string class constructor with reverse iterators*/
//	string reverseStr{string{originalStr.rbegin(), originalStr.rend()}};
//	
//	cout<<"\n\tSize: "<<d1.size()<<endl;
//	if(originalStr == reverseStr){
//		return true;
//	}
//	else{
//		return false;
//	}
	string alphaStr{onlyAlphabets(str)};
	deque <char> d1{};
	for(const auto &x: alphaStr){
		d1.emplace_back(x);
	}
	
	deque <char> d2{};
	copy(d1.cbegin(), d1.cend(), ::front_inserter(d2));
	d1.shrink_to_fit();
	d2.shrink_to_fit();
	
	for(size_t i{0}; i < d1.size(); i++){
		if(d1.at(i) != d2.at(i)){
			return false;
		}
	}
	return true;
}



int main(int argc, const char *const argv[]){

	const char *const str0 {"a"};
	const char *const str1 {"aa"};
	const char *const str2 {"aba"};
	const char *const str3 {"abba"};
	const char *const str4 {"abbcbba"};
	const char *const str5 {"ab"};
	const char *const str6 {"abc"};
	const char *const str7 {"radar"};
	const char *const str8 {"bob"};
	const char *const str9 {"ana"};
	const char *const str10 {"avid diva"};
	const char *const str11 {"Amore"};
	const char *const str12 {"Roma"};
	const char *const str13 {"A Toyota's a toyota"};
	const char *const str14 {"A Santa at NASA"};
	const char *const str15 {"C++"};
	const char *const str16 {"A man, a plan, a cat, a ham, a yam, a hat, a canal-panama!"};
	const char *const str17 {"This is a palindrome"};
	const char *const str18 {"Palindrome"};
	
	vector <string> testStrings{str0, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10,
			str11, str12, str13, str14, str15, str16, str17, str18};
			
	cout<<"Given strings:"<<endl;
	for_each(testStrings.cbegin(), testStrings.cend(),
		[](const string_view &x){
			cout<<x<<endl;
		}
	);
	cout<<endl;
	cout<<setw(8)<<left<<"Result"<<"String"<<endl;
	cout<<"------------------------------------------"<<endl;
	for(const string &str: testStrings){
		cout<<boolalpha<<setw(8)<<left<<isPalindrome(str)<<str<<endl;
	}
	cout<<setw(50)<<right<<"HappyEnding...!"<<endl;
	return 0;
}
