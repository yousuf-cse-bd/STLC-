/**
 * @file SimpleMinMaxElements1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Find min & max elements from a vector
 * @version 0.1
 * @date 2023-03-30
 * @since ThursDay; 10:41 AM
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
	for(const int &i:{1, 2, 3, 4, 5}){
		v1.emplace_back(i);
	}
	v1.shrink_to_fit();
	
	cout<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	
	cout<<"*Min Element: "<<*min_element(v1.cbegin(), v1.cend())<<endl;
	cout<<"*Max Element: "<<*max_element(v1.begin(), v1.end())<<endl;
	
	int maxElement{v1.at(0)};
	int minElement{v1.at(0)};
	size_t size{v1.size()};
	
	while(--size){
		if(maxElement < v1.at(size)){
			maxElement = v1.at(size);
		}
		if(minElement > v1.at(size)){
			minElement = v1.at(size);
		}
	}
	cout<<"Min Element: "<<minElement<<endl;
	cout<<"Max Element: "<<maxElement<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};