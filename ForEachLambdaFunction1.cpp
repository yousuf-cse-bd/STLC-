/**
 * @file ForEachLambdaFunction1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- for_each() using a lambda expression
 * @version 0.1
 * @date 2023-03-18
 * @since SaturDay; 09:17 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	vector <int> numbers1{1, 2, 3, 4, 5};
	for_each(numbers1.cbegin(), numbers1.cend(), 
	[](const int &x){cout<<(x*x)<<" ";});
	
	cout<<"\n\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}