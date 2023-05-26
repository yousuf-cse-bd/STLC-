/**
 * @file IsAnagramUsingSort1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check words ANAGRAM using sorting technique
 * @version 0.1
 * @date 2022-05-27
 * @since FriDay; 05:46 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(const string &str1, const string &str2){
	
	const size_t len1{str1.length()};
	const size_t len2{str2.length()};
	
	if(len1 == len2){
		vector <char> v1(len1); /*We can write len2*/
		vector <char> v2(len2); /*We can write len1*/
		
		for(size_t i{0}; i < len1; i++){
			v1.at(i) = tolower(str1.at(i));
			v2.at(i) = tolower(str2.at(i));
		}
		
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		/*Checking each element equal or not*/
		/*Is equal-> Anagram; Not equalt -> Not Anagram*/
		for(size_t i{0}; i < len1; i++){
			if(v1.at(i) != v2.at(i)){
				return false;
			}
		}
		return true;
	}
	
	return false;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string str1{"Listen"};
	const string str2{"Silent"};

    cout<<"First word: "<<str1<<endl;
    cout<<"Next Word: "<<str2<<endl;
	
	cout<<"There are"<<(isAnagram(str1, str2)?" ": " NOT ")<<"Anagram."<<endl;
	
	system("pause>0");
    return 0;
}