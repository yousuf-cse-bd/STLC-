/**
 * @file AlgorithmCount1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief The following program demonstrate count() stl method 
 * @version 0.1
 * @date 2023-03-31
 * @since FriDay; 03:32 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#pragma pack(1)
using namespace std;


int main(int argc, const char *const argv[]){
    system("cls");
	
	vector <bool> v1{};
	srand(time(nullptr));
	for(size_t i {0}; i < 10; i++){ /*true-> odd and false -> even*/
		v1.push_back((rand()&1)?true:false);
	}
	
	cout<<boolalpha<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](const bool &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	cout<<"Number of true: "<<count(v1.cbegin(), v1.cend(), true)<<endl;
	cout<<"Number of false: "<<count(v1.cbegin(), v1.cend(), false)<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};