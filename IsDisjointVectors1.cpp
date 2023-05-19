/**
 * @file IsDisjointVectors1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check is Arrays or Vector are disjoint?
 * @version 0.1
 * @date 2022-05-19
 * @since FriDay; 06:22 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

const bool isDisjoint(const vector <int> &v1, const vector <int> &v2){
	
	size_t sizeV1{v1.size()};
	size_t sizeV2{v2.size()};
	
	for(size_t i{0}; i < sizeV1; i++){
		for(size_t j{0}; j < sizeV2; j++){
			if(v1.at(i) == v2.at(j)){
				return false;
			}
		}
	}
	
	return true;
}

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
	
	vector <int> v1{1, 3, 5, 7, 9};
	vector <int> v2{2, 4, 6, 8, 10};
	
	if(isDisjoint(v1, v2)){
		cout<<"Vectors are disjoint..!"<<endl;
	}
	else{
		cout<<"Vectors are NOT disjoint..!"<<endl;
	}

	system("pause>0");
    return 0;
}
