/**
 * @file WordCountInLineC1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count The Words In A String | Applicatio of strchr(string, char)
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 08:43 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

 
#include <iostream>
#include <cstring>
using namespace std;
#pragma pack(1)

size_t wordCountFromLine(const char *const line){
	size_t count {0};
	const char *const separator{"\t\n ,;."};
	size_t len{strlen(line)};
	
	for(size_t i{0}; i < len; i++){ /*traverse full line*/
		while(i < len){ /*Word by wowd*/
			if(strchr(separator, *(line + i)) != nullptr) { /* strchr(): Finding first occurence*/
				break;
			}
			i++;
		}
		/*Igonore this figure (word,)*/
		while(i < len){ /*Word by wowd*/
			if(strchr(separator, *(line + i)) == nullptr) {
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

	const char *const line{"This is, the way."};
	
	cout<<wordCountFromLine(line)<<endl;
	
    return 0;
}
