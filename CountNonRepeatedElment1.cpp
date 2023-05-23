/**
 * @file CountNonRepeatedElment1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count Non-Repeating Array Elements
 * @version 0.1
 * @date 2022-05-23
 * @since TuesDay; 07:53 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

const void display(const vector <int> &v);

size_t countNonRepeatingVector(const vector <int> &v, const size_t &vSize){
	size_t count{0};
	size_t i{0}, j{0};
	for(i = 0; i < vSize; i++){
		for(j = 0; j < vSize; j++){
			if(v.at(i) == v.at(j) && i!=j) {break;}
		}
		if(j == vSize){count++;}
	}
	return count;
}


int main(int argc, const char *const argv[]){
	
	vector <int> numbers{1, 3, 5, 7, 3, 7, 6, 6, 4, 2, 9};
	
	display(numbers);
	const size_t length{numbers.size()};
	
	cout<<"Non-repeating element Number: "<<countNonRepeatingVector(numbers, length)<<endl;

	return 0;
}

const void display(const vector <int> &v){
	
	for(const int &x: v){
		cout<<x<<" ";
	}
	cout<<endl;
}