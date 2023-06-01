/**
 * @file SplitString1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Split A String At An Index Into Two Strings | C++ Programming Example
 * @version 0.1
 * @date 2022-06-01
 * @since ThursDay; 08:07 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <vector>
using namespace std;

void splitString(const string &str, const size_t &index, 
	vector <char> &firstStr,vector <char> &lastStr){
	
		const size_t len{str.length()};
		
		if(index < len){
			for(size_t i{0}; i < index; i++){
				firstStr.emplace_back(str.at(i));
				firstStr.shrink_to_fit(); /*Memory optimal*/
			}
			
			for(size_t i{index}; i < len; i++){
				lastStr.emplace_back(str.at(i));
				lastStr.shrink_to_fit(); /*Memory optimal*/
			}
		}
		else{
			cerr<<"Split operation NOT possible..!"<<endl;
		}
}

const void display(const vector <char> &v){
	for(const char &x: v){
		cout<<x;
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const string str {"I've got one hand in my pocket."};
	cout<<"Given line: "<<str<<endl;
	
	vector <char> firstStr{};
	vector <char> lastStr{};
	
	splitString(str, 13, firstStr, lastStr);
	
	cout<<"First str: ";
	display(firstStr);
	
	cout<<"Last str: ";
	display(lastStr);

    return 0;
}