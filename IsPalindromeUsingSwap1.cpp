/**
 * @file IsPalindromeUsingSwap1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief String reverse using swaping technique | C++ programming example
 * @version 0.1
 * @date 2023-06-13
 * @since TuesDay; 06:36 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#pragma pack(1)
using namespace std;

string stringReverseUsingSwaping(string line){
	
	size_t len{line.length()};
	const size_t middlePosition{len/2};
	
	for(size_t i{0}; i < middlePosition; i++){
		swap(line.at(i), line.at(--len)); /*(len - i - 1)->OK*/
	}
	
	return line;
}

bool isPalindrome(const string &originalStr, const string &reverseStr){
	if(originalStr == reverseStr){
		return true;
	}
	else{
		return false;
	}
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const string line{"MADAM"};
	
	if(isPalindrome(line, stringReverseUsingSwaping(line))){
		cout<<"That line is palindrome."<<endl;
	}
	else{
		cout<<"That line is NOT palindrome."<<endl;
	}
	
    return 0;
}
