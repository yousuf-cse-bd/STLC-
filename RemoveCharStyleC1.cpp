/**
 * @file RemoveCharStyleC1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Remove a character from a string at a specified position | C++ Programming Example
 * @version 0.1
 * @date 2022-05-28
 * @since SaturDay; 10:59 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <cstring>
using namespace std;

const bool charRemove(char s[], const size_t &position){
	const size_t len{strlen(s)};
	if(position >= len){
		return false;
	}
	
	for(size_t i{position}; i < len; i++){
		*(s + i) = *(s + i + 1);
	}
	return true;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	char s[]{"12345-12345"};
	cout<<"Before Remove: "<<s<<endl;
	
	
	if(charRemove(s, 5)){
		cout<<"Remove done: "<<s<<endl;
	}
	else{
		cout<<"Remove NOT done: "<<s<<endl;
	}
	
	system("pause>0");
    return 0;
}