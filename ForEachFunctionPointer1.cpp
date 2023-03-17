/**
 * @file ForEachFunctionPointer1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- for_each() - using function pointer with template function 
 * @version 0.1
 * @date 2023-03-17
 * @since FriDay; 10:26 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;
/*Stand-alone method*/
const void square(const int &x){
	cout<<(x*x)<<" ";
}
/*Template function*/
template <typename var>
const void cubicFunctor(const var x){
	cout<<(x * x * x)<<" ";
}

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	const vector <int> numbers1{1, 2, 3, 4, 5};
	for_each(numbers1.cbegin(), numbers1.cend(), square); /*Implicite function pointer*/
	cout<<"\n------------------------------"<<endl;

	const vector <double> numbers2{1.00, 2.00, 3.00, 4.00, 5.00};
	const void (*ptrCubic)(const double) = cubicFunctor; /*Function pointer*/
	for_each(numbers2.cbegin(), numbers2.cend(),ptrCubic);
	cout<<"\n\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}