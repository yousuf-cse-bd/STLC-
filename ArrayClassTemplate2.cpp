/**
 * @file ArrayClassTemplate2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Array (int) class template with subsript [] operator overloading
 * @version 0.1
 * @date 2023-03-15
 * @since WednesDay; 06:00 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#pragma pack(1)
using namespace std;

template <size_t N>
class Array{
private:
	friend ostream &operator<< (ostream &cout, const Array<N> &array){
		cout<<"[ ";
		for(const auto &element: array.values){
			cout<<element<<" ";
		}
		cout<<"]";
		return cout;		
	}
	size_t size{N}; /*To need N in compile time*/
	int values[N]; /*Here, Raw array*/
	
public:
	Array(void) = default;
	Array(const int &initValue){
		for(auto &element: values){
			element = initValue;
		}
	}
	
	void setElementBy(const int &value){
		for(auto &element: values){
			element = value;
		}
	}
	
	size_t getSize(void) const {
		return size;
	}
	
	/*Subcript [] operator overloading(int data-type only)*/
	int &operator[] (const int &index){
		return *(values + index); /*Pointer notation is better than array subscript*/
	}
	~Array(void) = default;
};


int main(int argc, const char *const argv[]){
	cout<<setw(2)<<fixed;
	Array<5> array1{};
	cout<<"Size of array1: "<<array1.getSize()<<endl;
	cout<<array1<<endl;
	array1.setElementBy(5);
	
	cout<<"Size of array1: "<<array1.getSize()<<endl;
	cout<<array1<<endl;
	cout<<"---------------------------------------"<<endl;
	Array<9> array2{9};
	cout<<"Size of array2: "<<array2.getSize()<<endl;
	cout<<array2<<endl;
	
	array2[0] = 100;
	array2[5] = 500;
	cout<<"Size of array2: "<<array2.getSize()<<endl;
	cout<<array2<<endl;
	cout<<setw(30)<<right<<"HapyEnding...!"<<endl;
	return 0;
}