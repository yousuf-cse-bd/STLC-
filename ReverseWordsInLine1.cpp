/**
 * @file ReverseWordsInLine1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Reverse The Words In A String | C Programming Example
 * @version 0.1
 * @date 2022-05-24
 * @since WedDay; 10:13 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#pragma pack(1)
using namespace std;

int main(int argc, char const *argv[]){
    /* code */
    system("cls");

	string line{"This is the way."};
	
	cout<<"Original: "<<line<<endl;
	
	ssize_t lineLength {static_cast<ssize_t>(line.length())};
	char word[lineLength + 1];
	ssize_t i{}, j{};
	for(i = 0; i < lineLength; i++){
		for(j = 0; i < lineLength; j++, i++){
			if(line.at(i) == ' ' || line.at(i) == '.') {break;}
			*(word + j) = line.at(i);
		}
		word[j] = '\0'; /*Optional I think*/

		/*Manually string reverse*/
		while (j > 0){
			j--;
			line.at(i - j - 1) = *(word + j);
		}
	}
	
	cout<<"Revirse: "<<line<<endl;

    return 0;
}
