#include <iostream>
/**
 * @file MergingSortedVectors1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Merging two sorted vectors
 * @version 0.1
 * @date 2022-05-22
 * @since MonDay; 07:55 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

const void display(const vector <int> &v);
void merge(const vector <int> &v1, const size_t &lengthV1,
	const vector <int> &v2, const size_t &lengthV2);

void merge(const vector <int> &v1, const size_t &lengthV1,
	const vector <int> &v2, const size_t &lengthV2){
	
	vector <int> result(lengthV1 + lengthV2);
	
	size_t i{0}, j{0}, k{0};
	while((i < lengthV1) && (j < lengthV2)){
		if(v1.at(i) < v2.at(j)){
			result.at(k) = v1.at(i);
			k++, i++;
		}
		else{
			result.at(k) = v2.at(j);
			k++, j++;
		}
	}

	while(i < lengthV1){
		result.at(k) = v1.at(i);
		k++, i++;
	}
	
	while(j < lengthV2){
		result.at(k) = v2.at(j);
		k++, j++;
	}
	
	display(result);
}

const void display(const vector <int> &v){
	for(const int &x: v){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
	
	vector <int> v1{1, 3, 5, 7, 9};
	vector <int> v2{2, 4, 5, 6, 8};
	
	merge(v1, v1.size(), v2, v2.size());
	
	return 0;
}
