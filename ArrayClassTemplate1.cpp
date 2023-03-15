/**
 * @file ArrayClassTemplate1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Array class template with subsript [] operator overloading
 * @version 0.1
 * @date 2023-03-15
 * @since WednesDay; 05:35 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

template <size_t N>
class Array{
private:
	friend ostream &operator<< (ostream &cout, const Array<N> &array){
		cout<<"[ ";
		for(const auto &element: array.valuse){
			cout<<element<<" ";
		}
		cout<<"]";
		return cout;
	}
	size_t size{N}; /*How do we get the N???*/
	int valuse[N]; /*The N need to known at compile-time*/
public:
	Array(void) = default;
	Array(const int &initValue){
		for(auto &element: valuse){
			element = initValue;
		}
	}
	void fill(const int &value){
		for(auto &element : valuse){
			element = value;
		}
	}
	size_t getSize(void) const {
		return size;
	}
	/*Overload subscript operator for easy to use*/
	int &operator[] (const int &index){
		return *(valuse + index); /*[] alter pointer notation*/
	}
	~Array(void) = default;
};


int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	Array<5> nums{};
	cout<<"The size of nums is: "<<nums.getSize()<<endl;
	cout<<nums<<endl;
	
	nums.fill(1);
	cout<<"The size of nums is: "<<nums.getSize()<<endl;
	cout<<nums<<endl;
	
	nums.fill(10);
	cout<<nums<<endl;
	
	nums[0] = 101;
	nums[3] = 103;
//	*(nums + 4) = 105; /*Not support pointer notation here*/
	cout<<nums<<endl;
	
	Array<10> numbs2{1};
	cout<<"The size of nums2 is: "<<numbs2.getSize()<<endl;
	cout<<numbs2<<endl;
	
	cout<<"\t\t\tHapyEnding!!!"<<endl;
    return 0;
}