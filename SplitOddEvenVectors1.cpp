/**
 * @file SplitOddEvenVectors1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Split Even And Odd Values Of An Vector Into Two Vectors | C++ programming example
 * @version 0.1
 * @date 2023-06-14
 * @since WednesDay; 11:04 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

const void display(const vector <int> &v);
void splitVectorOddEven(const vector <int> &data, vector <int> &odds, vector <int> &evens);

void splitVectorOddEven(const vector <int> &data, vector <int> &odds, vector <int> &evens){
	
    for(const int &x: data){
		if(x & 1){
			odds.emplace_back(x);
			odds.shrink_to_fit();
		}
		else{
			evens.emplace_back(x);
			evens.shrink_to_fit();
		}
	}
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const vector <int> data {1, 2, 3, 4, 5, 6, 7, 9, 10};
	vector <int> oddList{};
	vector <int> evenList{};
	
	splitVectorOddEven(data, oddList, evenList);
	
	cout<<"Odd List: ";
	display(oddList);
	
	cout<<"Even List: ";
	display(evenList);

    return 0;
}

const void display(const vector <int> &v){
	
    for(const int &x: v){
		cout<<x<<" ";
	}

	cout<<endl;
}
