/**
 * @file CountDuplicates.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count duplicate chars from string | C++ Programming Example
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 05:36 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <iomanip>
using namespace std;

void countDuplicates(const string &line){
	
	const size_t len{line.length()};
	size_t countRepeatingChar{0};
	bool foundRepeat{false};
	
	for(size_t i{0}; i < len; i++){
		foundRepeat = false;
		
		for(size_t j{0}; j < len; j++){
			if(line.at(i) == line.at(j) && i != j){
				foundRepeat = true;
				break;
			}
		}
		
		if(foundRepeat){
			cout<<"Repeating["<<i<<"] = "<<line.at(i)<<endl;
			countRepeatingChar++;
		}
	}
	
	if(!foundRepeat){
		cout<<"There is NOT Repeating char..."<<endl;
	}
	else{
		cout<<"Total Repeating "<<((countRepeatingChar > 1 )?"Chars: ":"Char: ")
			<<countRepeatingChar<<endl;
	}
	return;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string line {"abcdefghijklmnopabcdefabcab"};
	cout<<"Line: "<<line<<endl;
	
	countDuplicates(line);
	
	system("pause>0");
    return 0;
}


