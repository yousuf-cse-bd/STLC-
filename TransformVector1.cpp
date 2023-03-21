/**
 * @file TransformVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- transform() method for vector container
 * @version 0.1
 * @date 2023-03-21
 * @since TuesDay; 10:58 AM
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

/*Transform vector over 2 ranges*/
void transformVector(void){
	lineBar("Transform Vector");
	
	vector <int> numbers1{1, 2, 3, 4, 5};
	vector <int> numbers2{10, 20, 30, 40, 50};
	vector <int> numbers3{};
	cout<<"Size of numbers3: "<<numbers3.size()<<endl;
	cout<<"Capacity of numbers3: "<<numbers3.capacity()<<endl;
	display(numbers1);
	display(numbers2);
	cout<<endl;
	/*10x1, 2x20, 3x30, 4x40, 5x50 and store the result in numbers3*/
	if(numbers1.size() == numbers2.size()){
		transform(numbers1.cbegin(), numbers1.cend(), numbers2.cbegin(),
		::back_inserter(numbers3),
			[](const int &x, const int &y){
				return(x*y);
			}
		);
		cout<<"Size of numbers3: "<<numbers3.size()<<endl;
		cout<<"Capacity of numbers3: "<<numbers3.capacity()<<endl;
		numbers3.shrink_to_fit();
		cout<<endl;
		
		cout<<"Size of numbers3: "<<numbers3.size()<<endl;
		cout<<"Capacity of numbers3: "<<numbers3.capacity()<<endl;
		
		display(numbers3);
	}
	else{
		cout<<"It generates GARBAGE values...1"<<endl;
	}
}

int main(int argc, const char *const argv[]){
	transformVector();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}

const void lineBar(const char *const title){
	cout<<"---"<<title<<":--------------------------------------"<<endl;
}