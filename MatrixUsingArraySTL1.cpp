/**
 * @file MatrixUsingArraySTL1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Two dimentional STL array [matrix]
 * @version 0.1
 * @date 2023-03-19
 * @since SaturDay; 11:23 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <array>
#pragma pack(1)
using namespace std;


int main(int argc, const char *const argv[]){
	constexpr size_t rowSize {3};
	constexpr size_t columnSize {4};
	/*Make sure inner matrix size must be column-wised
	 Outer matrix size must be row-wised*/
	array <array<int, columnSize>, rowSize> matrix{
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12
		};
	cout<<"Normal for loop:"<<endl;
	for(size_t i{0}; i < rowSize; i++){
		for(size_t j{0}; j < columnSize; j++){
			cout<<matrix.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Using range-based for loop:"<<endl;
	for(const auto &rows: matrix){
		for(const auto &columns: rows){
			cout<<columns<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}