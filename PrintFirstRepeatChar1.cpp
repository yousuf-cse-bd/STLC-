/**
 * @file PrintFirstRepeatChar1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Print First Repeating Character In A String
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 03:30 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
using namespace std;

void printFirstRepeatingChar(const string &line){
	const size_t len{line.length()};
	bool foundRepeat{false};
	
	for(size_t i {0}; i < len; i++){
		foundRepeat = false;
		for(size_t j{0}; j < len; j++){
			if(line.at(i) == line.at(j) && i != j){
				foundRepeat = true;
				break;
			}
		}
		if(foundRepeat){
			cout<<"First REPEATING char: "<<line.at(i)<<endl;
			break;
		}
	}
	if(!foundRepeat){
		cout<<"There is no REPEATING char..."<<endl;
	}
	return;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string line {"abcdefghijklmnopjklmnop"};
	cout<<"Line: "<<line<<endl;
	
	printFirstRepeatingChar(line);
	
	system("pause>0");
    return 0;
}


