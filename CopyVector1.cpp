/**
 * @file CopyVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- copy(), copy_if() method for vector container
 * @version 0.1
 * @date 2023-03-21
 * @since TuesDay; 10:40 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <vector>
#pragma pack(1)
using namespace std;

const void lineBar(const char *const title);

/*Use for_each() and a lambda expression to display vector elements*/
void display(const vector <int> &v){
	cout<<"[ ";
	for_each(v.cbegin(), v.cend(),
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

void copyVector(void){
	lineBar("Copy Vector");
	
	vector <int> numbers1 {1, 2, 3, 4, 5};
	vector <int> numbers2 {10, 20};
	
	display(numbers1);
	display(numbers2);
	cout<<endl;
	
	copy(numbers1.cbegin(), numbers1.cend(), back_inserter(numbers2));
	display(numbers1);
	display(numbers2);

	numbers2.shrink_to_fit();

	cout<<"Size & Capacity: "<<((numbers2.size() == numbers2.capacity())?"Equal":"Not Equal")<<endl;
	cout<<endl;
	
	numbers1.clear();
	numbers2.clear();
	
	/*Copy-if the elements are even*/
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	numbers2 = {10, 20};
	copy_if(numbers1.cbegin(), numbers1.cend(), back_inserter(numbers2),
		[](const int &x){
			return(!(x & 1)); /*If x is even*/
		}
	);
	display(numbers1);
	display(numbers2);
	numbers2.shrink_to_fit();
	cout<<"Size & Capacity: "<<((numbers2.size() == numbers2.capacity())?"Equal":"Not Equal")<<endl;
	cout<<endl;
}

int main(int argc, const char *const argv[]){
	copyVector();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}

const void lineBar(const char *const title){
	cout<<"---"<<title<<":--------------------------------------"<<endl;
}