/**
 * @file MoveAllZerosToEnd2.cpp
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
#pragma pack(1)
using namespace std;

/*Own method*/
vector <int> shiftingZeros1(const vector <int> &data){
	const size_t sized{data.size()};
	
	vector <int> zeros{};
	vector <int> nonZeros{};
	
	for(size_t i{0}; i < sized; i++){
		if(data.at(i) == 0){
			zeros.emplace_back(data.at(i));
			zeros.shrink_to_fit();
		}
		else{
			nonZeros.emplace_back(data.at(i));
			nonZeros.shrink_to_fit();
		}
	}
	
	vector <int> shiftedZeros(sized);
	size_t i{0};
	for(const int &nonZero: nonZeros){
		shiftedZeros.at(i++) = nonZero;
	}
	
	for(const int &zero: zeros){
		shiftedZeros.at(i++) = zero;
	}
	
	return shiftedZeros;
}

/*Portfolio Courses*/
template <typename dataType>
vector <dataType> shiftingZeros2(const vector <dataType> &data){
	const size_t sized{data.size()};
	size_t count{0};
	
	vector <dataType> shiftedZeros(sized);
	/*Fill by non-zeros*/
	for(size_t i{0}; i < sized; i++){
		if(data.at(i) != 0){
			shiftedZeros.at(count) = data.at(i);
			count++;
		}
	}
	/*Fill by zeros*/
	for(size_t i{count}; i < sized; i++){
		shiftedZeros.at(i) = 0;
	}
	
	return shiftedZeros;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	//				  {2, 5, 6, 7, 4, 7, 0, 0, 0, 0}
	const vector <int> data {2, 0, 5, 6, 0, 0, 7, 0, 4, 7};
	
	vector <int> shiftedZeros1 {shiftingZeros1(data)};
	
	for(const int &x: shiftedZeros1){
		cout<<x<<" ";
	}
	cout<<endl;
	
	cout<<"---------------------------------------"<<endl;
	
	vector <int> shiftedZeros2 {shiftingZeros2(data)};
	
	for(const int &x: shiftedZeros2){
		cout<<x<<" ";
	}
	cout<<endl;

    return 0;
}
