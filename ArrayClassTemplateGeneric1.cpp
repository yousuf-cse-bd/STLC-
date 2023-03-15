/**
 * @file ArrayClassTemplateGeneric1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Creating a generic array template class with subcript operator overloading applied
 * @version 0.1
 * @date 2023-03-15
 * @since WednesDay; 07:45 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
 /*Note: Since C++ 11 the STL has array which is template-based array class*/
/*Use array instead of RAW arrays whenever possible*/
#include <iostream>
#include <iomanip>
#pragma pack(1)
using namespace std;

template <typename var, size_t N>
class Array{
private:
	friend ostream &operator<< (ostream &cout, const Array<var ,N> &array){
		cout<<"[ ";
		for(const auto &element: array.values){
			cout<<element<<" ";
		}
		cout<<"]";
		return cout;		
	}
	size_t size{N}; /*To need N in compile time*/
	var values[N]; /*Here, Raw array*/
	
public:
	Array(void) = default;
	Array(const var &initValue){
		for(auto &element: values){
			element = initValue;
		}
	}
	
	void setElementBy(const var &value){
		for(auto &element: values){
			element = value;
		}
	}
	
	size_t getSize(void) const {
		return size;
	}
	
	/*Subcript [] operator overloading(int data-type only)*/
	var &operator[] (const int &index){
		return *(values + index); /*Pointer notation is better than array subscript*/
	}
	~Array(void) = default;
};

/*We have to use of size of array constant value*/
int main(int argc, const char *const argv[]){
	cout<<setprecision(2)<<fixed;
	constexpr size_t size{5}; /*Only const/constexpr*/
	Array <char, size> array0;
	cout<<"Size of array0: "<<array0.getSize()<<endl;
	cout<<array0<<endl;
	cout<<"----------------------------------------"<<endl;
	Array<int, 5> array1{};
	cout<<"Size of array1: "<<array1.getSize()<<endl;
	cout<<array1<<endl;
	array1.setElementBy(5);
	
	cout<<"Size of array1: "<<array1.getSize()<<endl;
	cout<<array1<<endl;
	cout<<"----------------------------------------"<<endl;
	Array<double ,9> array2{9.00};
	cout<<"Size of array2: "<<array2.getSize()<<endl;
	cout<<array2<<endl;
	
	array2[0] = 100;
	array2[5] = 500;
	cout<<"Size of array2: "<<array2.getSize()<<endl;
	cout<<array2<<endl;
	cout<<"------------------------------------------"<<endl;
	Array <string, 3> array3{"Yousuf"};
	cout<<"Size of array3: "<<array3.getSize()<<endl;
	cout<<array3<<endl;
	array3[0] = "Muhamad";
	array3[2] = "Ali";
	cout<<array3<<endl;
	array3.setElementBy("X");
	cout<<array3<<endl;
	cout<<setw(30)<<right<<"HappyEnding...!"<<endl;
	return 0;
}
