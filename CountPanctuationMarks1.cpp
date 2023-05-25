/**
 * @file CountPanctuationMarks1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count The Punctuation Marks In A String | C++ Programming Example
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 06:34 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
using namespace std;

size_t punctuationCount1(const string &line){
	size_t puncCount{0};
	for(const char &x: line){
		if(!isalnum(x) && x != ' '){
//			if(x == ' ') continue;
			puncCount++;
		}
	}
	
	return puncCount;
}


size_t punctuationCount2(const string &line){
	size_t puncCount{0};
	for(const char &x: line){
		if(ispunct(x)){
			puncCount++;
		}
	}
	
	return puncCount;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
    
	const string line{"#Apple, pear, orange; something...!"};
	
	cout<<punctuationCount1(line)<<endl;
	cout<<punctuationCount2(line)<<endl;
	
	system("pause>0");
    return 0;
}
