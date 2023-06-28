/**
 * @file WordCountInLineC++2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count The Words In A String | C++ program example
 * @version 0.1
 * @date 2022-06-28
 * @since WednesDay; 10:54 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

size_t wordCount(const string &text){
	
	size_t wordCount {0};
	if(!text.empty()){
		char seperator {' '};
		const size_t len{text.size()};
		for(size_t i{0}; i < len; i++){
			if(text.at(i) == seperator && text.at(i+1) != seperator){
//				if(text.at(i+1) != ' '){
				wordCount++;
//				}
			}
		}
		
		++wordCount; /*word += 1*/
	}

	return wordCount;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const string text {"Counting Occurrences Of A Word In A String"};
	cout<<"Text: "<<text<<endl;
	
	cout<<"Count: "<<wordCount(text)<<endl;
	
    return 0;
}
