/**
 * @file SplitingFullName1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Split A String At An Index Into Two Strings | C++ Programming Example
 * @version 0.1
 * @date 2022-06-01
 * @since ThursDay; 08:25 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
using namespace std;

void splitString(const string &fullName, const size_t &spliterIndex, 
	vector <char> &firstName, vector <char> &lastName){
	
		const size_t len{fullName.length()};
		
		if(spliterIndex < len){
			for(size_t i{0}; i < spliterIndex; i++){
				firstName.emplace_back(fullName.at(i));
				firstName.shrink_to_fit(); /*Memory optimal*/
			}
			
			for(size_t i{spliterIndex}; i < len; i++){
				lastName.emplace_back(fullName.at(i));
				lastName.shrink_to_fit(); /*Memory optimal*/
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
	
	const string fullName {"Muhammd Yousuf Ali"};
	cout<<"The Full-Name: "<<fullName<<endl;
	
	vector <char> firstName{};
	vector <char> lastName{};
	
	
	splitString(fullName, 15, firstName, lastName);
	
	cout<<"The First-Name: ";
	display(firstName);
	
	cout<<"The Last-Name: ";
	display(lastName);
	
    return 0;
}