/**
 * @file WordCountInLineCPP1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count The Words In A String Using Linear Search Algorithm
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 09:15 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;
#pragma pack(1)

const bool isSeparator(const char &c){
	
	const char *const separator{"\t\n ,;."};
	size_t i{0};
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
	
	for(size_t i{0}; i < len; i++){ /*traverse full line*/
		while(i < len){ /*Word by wowd*/
			if(isSeparator(line.at(i))) { /* strchr(): Finding first occurence*/
				break;
			}
			i++;
		}
		/*Igonore this figure (word,)*/
		while(i < len){ /*Word by wowd*/
			if(!isSeparator(line.at(i))) {
				break;
			}
			i++;
		}
		count++;
	}
	return count;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");

	const string line{"This is, the way...."};
	
	cout<<"The line: "<<line<<endl;
	size_t count{wordCountFromLine(line)};
	
	cout<<"There are "<<count<<" Words."<<endl;
	
    return 0;
}
