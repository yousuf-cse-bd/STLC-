/**
 * @file PrintUniqueElement1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Print Unique Elements Of a Vector | C++ Programming Example
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 05:44 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printUniqe(vector <int> &v, const size_t &vSize);

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    vector <int> listInt {1, 2, 3, 4, 5, 6, 3, 4, 1, 8, 9, 7, 8};
	cout<<"Original elements: ";
	for(const int &x: listInt){
		cout<<x<<" ";
	}
	cout<<endl;
	
	printUniqe(listInt, listInt.size());
	
	system("pause>0");
    return 0;
}

void printUniqe(vector <int> &v, const size_t &vSize){
	size_t uniqueCount{0};
	cout<<"These elements are absolutely unique: ";
	for(size_t i{0}; i < vSize; i++){
		bool matchStatus {false};
		for(size_t j{0}; j < vSize; j++){
			if(v.at(i) == v.at(j) && i != j){
				matchStatus = true;
				break;
			}
		}
		
		if(!matchStatus){
			uniqueCount++;
			cout<<v.at(i)<<" ";
		}
	}
	cout<<"\n"<<uniqueCount<<" Times."<<endl;
	return;
}
