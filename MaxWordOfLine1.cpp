/**
 * @file MaxWordOfLine1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Find Length Of Longest Word In A String
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 09:15 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#pragma pack(1)
using namespace std;

const bool isSeparator(const char &c){
	
	const char *const separator{"\t\n ,;."};
	unsigned int i{0};
	while(*(separator + i++) != '\0'){ /*Linear searching*/
		if(*(separator + i) == c){
			return true;
		}
	}
	return false;
}

size_t wordCountFromLine(const string &line){
	size_t count {0};
	
	size_t len{line.length()};
	
	size_t maxLen{0};
	
	for(size_t i{0}; i < len; i++){ /*traverse full line*/
		count = 0;
		while(i < len){ /*Word by wowd*/
			if(isSeparator(line.at(i))) { /* strchr(): Finding first occurence*/
				break;
			}
			i++;
			count++;
		}
		maxLen = max(maxLen, count);
	}
	return maxLen;
}


int main(int argc, const char *const argv[]){
    /* code */
    system("cls");

	const string line{"1 22 4444 333, 55555,"};
//	const string line = "This is, treres the way. Again...";
	
	cout<<"The line: "<<line<<endl;
	size_t maxLen{wordCountFromLine(line)};
	
	cout<<"Max Length Word: "<<maxLen<<endl; 
	
    return 0;
}
