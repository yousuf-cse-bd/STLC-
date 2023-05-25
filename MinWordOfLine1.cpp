/**
 * @file MinWordOfLine1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Find Length Of Smallest Word In A String | C Programming Example
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 09:15 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#pragma pack(1)
using namespace std;

const bool isSeparator(const char &x){
	const char *const separator{"\t\n ,;."};
	unsigned int i{0};
	while(*(separator + i++)){
		if(*(separator + i) == x){
			return true;
		}
	}
	return false;
}


size_t minLengthOfWordFromLine(const string &line){
	size_t wordLength {0};
	
	size_t len{line.length()};
	
	size_t minLen{SIZE_MAX};
	size_t i{0};
	while(i < len){ /*traverse full line*/
		wordLength = 0;
		while(i < len){ /*Word by wowd*/
			if(isSeparator(line.at(i))) {
				break;
			}
			i++;
			++wordLength;
		}
		
		while(i < len){
			if(!isSeparator(line.at(i))){
				break;
			}
			i++;
		}
		minLen = min(minLen, wordLength);
	}
	return minLen;
}


int main(int argc, const char *const argv[]){
    /* code */
    system("cls");

	const string line {"This is, the way. Again..."};
	
	cout<<"The line: "<<line<<endl;
	size_t minLen {minLengthOfWordFromLine(line)};
	
	cout<<"Min Length Word: "<<minLen<<endl; 
	
    return 0;
}
