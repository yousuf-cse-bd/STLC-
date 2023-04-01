/**
 * @file AlgorithmReverse1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Demonstrate reverse() stl method
 * @version 0.1
 * @date 2023-04-01
 * @since SuturDay; 05:04 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    system("cls");
	
	vector <int> v1{};
	for(size_t i{0}; i < 10; i++){
		v1.emplace_back(i);
	}
	
	v1.shrink_to_fit();
	cout<<"Initial: [ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	reverse(v1.begin(), v1.end());
	
	cout<<"Reverse: [ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};