/**
 * @file PrintStringUntilNewLineChar1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Print A String Until The First Newline Character | C++ Programming Example
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 06:30 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
using namespace std;

void printUntilNewLine(const string &line){

	size_t i{0};
	while(line.at(i) != '\0' && line.at(i) != '\n'){
		putchar(line.at(i));
		i++;
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string line {"This is the way.\n Again..."};
	cout<<"Line: "<<line<<endl;
	
	cout<<"Result: ";
	printUntilNewLine(line);
	
	system("pause>0");
    return 0;
}