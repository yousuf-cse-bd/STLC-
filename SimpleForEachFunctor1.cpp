/**
 * @file SimpleForEachFunctor1.cpp
 * @author your name (you@domain.com)
 * @brief The for_each() functor considers as object of containers elements
 * @version 0.1
 * @date 2023-03-17
 * @since FriDay; 11:58 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

struct SquareFunctor{
	void operator() (const int &x){
		cout<<(x*x)<<" ";
	}
	~SquareFunctor(void){
		cout<<endl;
	}
};

template <typename var>
struct CubicFunctor{
	void operator() (const var &x){
		cout<<(x * x * x)<<" ";
	}
	~CubicFunctor(void){
		cout<<endl;
	}
};

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	SquareFunctor square{};
	const vector <int> numbers1{1, 2, 3, 4, 5};
	for_each(numbers1.cbegin(), numbers1.cend(), square);
	cout<<"------------------------------"<<endl;
	CubicFunctor <double> cubic{};
	const vector <double> numbers2{1.00, 2.00, 3.00, 4.00, 5.00};
	for_each(numbers2.cbegin(), numbers2.cend(), cubic);
	
	cout<<"\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}