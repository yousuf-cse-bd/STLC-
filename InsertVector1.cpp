/**
 * @file InsertVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- insert(), find() method for vector container
 * @version 0.1
 * @date 2023-03-21
 * @since TuesDay; 11:17 AM
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
/*Insert a full vector into another vector*/
void insertVectorIntoVector(void){
	lineBar("Inserting Vector Into Vector");
	vector <int> numbers1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	vector <int> numbers2 {100, 200, 300, 400};
	/*Insert numbers2 into numbers1 before the 5*/
	auto it {find(numbers1.cbegin(), numbers1.cend(), 5)};
	if(it != numbers1.cend()){
		cout<<"Inserting...."<<endl;
		numbers1.insert(it, numbers2.cbegin(), numbers2.cend());
		cout<<"Size of numbers1: "<<numbers1.size()<<endl;
		cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
		cout<<endl;
		
		numbers1.shrink_to_fit(); /*It deletes unused memory spaces*/
		
		cout<<"Size of numbers1: "<<numbers1.size()<<endl;
		cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;		
		display(numbers1);
	}
	else{
		cout<<"The 5 is not found...!"<<endl;
	}
	
}

int main(int argc, const char *const argv[]){
	insertVectorIntoVector();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}

const void lineBar(const char *const title){
	cout<<"---"<<title<<":--------------------------------------"<<endl;
}