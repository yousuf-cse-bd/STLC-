/**
 * @file SimpleSortVectorAsc.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief STL a simple example - sort a vector
 * @version 0.1
 * @date 2023-03-14
 * @since TuesDay; 11:30 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    constexpr size_t limit {10};
	vector <size_t> v1(limit);
	srand(time(nullptr));
	cout<<"Vector elements: ";
	for(size_t i{0}; i < limit; i++){
		v1.at(i) = (rand()%limit);
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;
	
	sort(v1.begin(), v1.end()); /*Using iterators*/
	cout<<"Sorted elements: ";
	for(const size_t &element: v1){
		cout<<element<<" ";
	}
	cout<<endl;
	
    cout<<"\t\tHappyEnding...!"<<endl;
    return 0;
}
