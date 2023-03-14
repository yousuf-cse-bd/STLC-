/**
 * @file SumRealImaginary1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Sum of real and imaginary numbers
 * @version 0.1
 * @date 2023-03-14
 * @since TuesDay; 10:25 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

template <typename dataType1, typename dataType2>
struct MyPair{
	dataType1 term1{};
	dataType2 term2{};
	friend ostream &operator<< (ostream &cout, const MyPair &myPair){
		cout<<"["<<myPair.term1<<" : "<<myPair.term2<<"i]";
		return cout;
	}
	
	MyPair operator + (const MyPair &rhs){
		MyPair tempPair;
		tempPair.term1 = term1 + rhs.term1;
		tempPair.term2 = term2 + rhs.term2;
		return tempPair;
	}
};

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	MyPair <double, double> pair1{10, 5};
	MyPair <double, double> pair2{20, 5};
	cout<<pair1<<endl;
	cout<<pair2<<endl;
	cout<<"--------------------"<<endl;
	MyPair <double, double> sum{pair1 + pair2};
	cout<<sum<<endl;
	
    return 0;
}
