/**
 * @file RemovingAllOccurances1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Removing all occurrences of a character from a string
 * @version 0.1
 * @date 2023-05-17
 * @since WednesDay; 09:38 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

void removeChar(char *line, const char &x){
	size_t position{0};
	while(*(line+position) != '\0'){
		if(*(line + position) == x){
			size_t newPosition {position};
			while(*(line + newPosition) != '\0'){
				*(line + newPosition) = *(line + newPosition + 1);
				newPosition++;
			} 
		}
		else{
			position++;
		}
	} 
}

int main(int argc, const char *const argv[]){
    system("cls");

    char line[] {"Yousuf"};

    cout<<"Original line: "<<line<<endl;
    removeChar(line, 'u');
    
    cout<<"After removed ('u'): "<<line<<endl;

    return 0;
}