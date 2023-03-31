/**
 * @file AlgorithmCountIf1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief The following program demonstrate count_if() stl method
 * @version 0.1
 * @date 2023-03-31
 * @since FriDay; 04:59 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

bool dividedBy3(const size_t &number){
	return ((number % 3 == 0)?true:false);
}

int main(int argc, const char *const argv[]){
    system("cls");
	
	vector <int> v1{};
	for(size_t i {1}; i <= 20; i++){
		v1.push_back(i);
	}
	
	v1.shrink_to_fit(); /*Optimized memory state*/
	
	cout<<boolalpha<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	ssize_t count {count_if(v1.cbegin(), v1.cend(), dividedBy3)};
	
	cout<<count<<" numbers divisible by 3"<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};