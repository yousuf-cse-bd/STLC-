/**
 * @file AlgorithmTransform1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Demonstrate transform() stl method
 * @version 0.1
 * @date 2023-04-01
 * @since SaturDay; 05:35 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#pragma pack(1)
using namespace std;

constexpr double reciprocal(const int &i){
	return 1.0/i;
}

int main(int argc, const char *const argv[]){
    system("cls");
	cout<<setprecision(2)<<fixed;
	list <double> lst1{};
	for(int i{1}; i < 10; i++){
		lst1.emplace_back(static_cast<double>(i));
	}
	
	cout<<"Original contents: [ ";
	for_each(lst1.cbegin(), lst1.cend(),
		[](const double &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	transform(lst1.begin(), lst1.end(), lst1.begin(), reciprocal);
	
	cout<<"Transform contents: [ ";
	for(auto it{lst1.cbegin()}; it != lst1.cend(); it++){
		cout<<*it<<" ";
	}
	cout<<"]"<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};