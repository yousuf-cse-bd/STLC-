/**
 * @file UniqueNumberGenerator1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Unique Number Generator | C++ Programming Example
 * @version 0.1
 * @date 2022-05-31
 * @since ThursDay; 08:49 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <deque>
#include <ctime>
using namespace std;

const bool linearSearch(const deque <int> &myDeque, const int &key){
	
	for(const int &x: myDeque){
		if(x == key){
			return true;
		}
	}
	
	return false;
}


int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	srand(time(nullptr));
	const size_t limit{10};
	
	deque <int> uniqueNumbers(limit);
	int element{0};
	
	for(size_t i{0}; i < limit; i++){
		
		do{
			element = rand() % (limit + 1); /*Must remainder > limit*/
			
		}while(linearSearch(uniqueNumbers, element)); /*True->loop again*/
		
		uniqueNumbers.at(i) = element;
	}
	
	for(const int &x: uniqueNumbers){
		cout<<x<<" ";
	}
	cout<<endl;
	
    return 0;
}