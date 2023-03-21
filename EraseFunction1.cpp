/**
 * @file EraseFunction1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- erase() method for vector container
 * @version 0.1
 * @date 2023-03-21
 * @since  WednesDay; 09:51 AM
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

void eraseVector(void){
    lineBar("Erase Vector Elements");
	vector <int> numbers1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"Size of numbers1: "<<numbers1.size()<<endl;
	cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
	display(numbers1);
	cout<<endl;
	
	numbers1.erase(numbers1.cbegin(), numbers1.cbegin() + 2);
	cout<<"Size of numbers1: "<<numbers1.size()<<endl;
	cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
	display(numbers1);
	numbers1.clear();
	cout<<endl;
	
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"Size of numbers1: "<<numbers1.size()<<endl;
	cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
	display(numbers1);
	cout<<endl;
	/*Erase all even numbers*/
	auto it {numbers1.cbegin()};
	while(it != numbers1.cend()){
		if(!(*it & 1)){
			numbers1.erase(it);
		}
		else{
			it++;
		}
	}
	cout<<"Size of numbers1: "<<numbers1.size()<<endl;
	cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
	display(numbers1);
	cout<<endl;
	cout<<"If you call erase() you have to call also shrink_to_fit()"<<endl;
	numbers1.shrink_to_fit(); /*C++ 11*/
	cout<<"Size of numbers1: "<<numbers1.size()<<endl;
	cout<<"Capacity of numbers1: "<<numbers1.capacity()<<endl;
}


int main(int argc, const char *const argv[]){
	eraseVector();
	
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}

const void lineBar(const char *const title){
	cout<<"---"<<title<<":--------------------------------------"<<endl;
}