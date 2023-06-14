/**
 * @file MoveAllZerosToEnd1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Move All Zeros In An Array To The End | C++ programming example
 * @version 0.1
 * @date 2023-06-13
 * @since WednesDay; 08:12 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <vector>
#include <deque>
#pragma pack(1)
using namespace std;

/*Function template*/
template <typename dataType>
const void display(const deque <dataType> &container){
	for(const auto &x: container){
		cout<<x<<" ";
	}
	cout<<endl;
}

void shiftZeros(const vector <int> &data){
	const size_t sized{data.size()};
	
	deque <int> zerosEnd{};
	
	for(size_t i{0}; i < sized; i++){
		if(data.at(i) == 0){
			zerosEnd.emplace_back(data.at(i));
		}
		else{
			zerosEnd.emplace_front(data.at(i));
		}
	}
	
	display(zerosEnd);
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	//				  {2, 5, 6, 7, 4, 7, 0, 0, 0, 0}
	vector <int> data {2, 0, 5, 6, 0, 0, 7, 0, 4, 7};
	
	shiftZeros(data);
	
	
    return 0;
}
