/**
 * @file LotteryNumberGenerator1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Lottery Number Generator  | C++ Programming Example
 * @version 0.1
 * @date 2022-05-31
 * @since ThursDay; 08:49 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const bool linearSearch(const vector <int> &myVector, const int &key){
	
	for(const int &x: myVector){
		if(x == key){
			return true;
		}
	}
	
	return false;
}

const void display(const vector <int> &myVector){
	for(const int &x: myVector){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	srand(time(nullptr));
	const size_t limit{10};
	
	vector <int> uniqueNumbers(limit);
	int element{0};
	
	for(size_t i{0}; i < limit; i++){
		
		do{
			element = rand() % 50; /*Must remainder(1~49) > limit*/
			
		}while(linearSearch(uniqueNumbers, element)); /*True->loop again*/
		
		uniqueNumbers.at(i) = element;
	}
	
	display(uniqueNumbers);

    return 0;
}