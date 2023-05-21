/**
 * @file RotateLeftOnce1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Rotate a vector left once
 * @version 0.1
 * @date 2022-05-21
 * @since SundDay; 10:05 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

// Array before
// Index: 0 1 2 3 4 5
// Array: 3 9 8 1 7 6

// Array After
// Index: 0 1 2 3 4 5
// Array: 9 8 1 7 6 3

const void display(const vector <int> &v, const size_t &vSize, const char *const lebel){
	cout<<lebel<<endl;

	for(size_t i{0}; i < vSize; i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for(const int &x: v){
		cout<<x<<" ";
	}
	cout<<endl;
}

void rotateLeftOnce(vector <int> &v, const size_t &vSize){
	
	const int temp {v.at(0)};
	for(size_t i{0}; i < vSize - 1; i++){
		v.at(i) = v.at(i+1);
	}
	v.at(vSize - 1) = temp;	
}
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
   
	vector <int> v1{3, 9, 8, 1, 7, 6};
	size_t vSize{v1.size()};
	
	display(v1, vSize, "Before Rotate Vector");
	
	rotateLeftOnce(v1, vSize);
	
	display(v1, vSize, "After Rotate Vector");
   
    return 0;
}
