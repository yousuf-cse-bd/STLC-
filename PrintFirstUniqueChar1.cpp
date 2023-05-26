/**
 * @file PrintFirstUniqueChar1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Print First Unique Character In A String | C++ Programming Example
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 10:18 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <iomanip>
using namespace std;

void printFirstUnique(const string &line){
	
	const size_t len{line.length()};
	bool foundRepeat{false};
	bool foundUnique{false};
	for(size_t i{0}; i < len; i++){
		foundRepeat = false;
		for(size_t j{0}; j < len; j++){
			if(line.at(i) == line.at(j) && i != j){
				foundRepeat = true;
				break;
			}
		}
		if(!foundRepeat){
			cout<<"First Unique Char: "<<line.at(i)<<endl;
			foundUnique = true;
			break;
		}
	}
	if(!foundUnique){
		cout<<"There is NOT uniqe char..."<<endl;
	}
	return;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const string line {"abcdefghijklmnopabcdefghi"};
//	const string line {"abccba"};
	cout<<"Line: "<<line<<endl;
    
	printFirstUnique(line);
	
	system("pause>0");
    return 0;
}


