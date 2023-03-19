/**
 * @file STLArrayInClass1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief We have to use STL array instead RawArray
 * @version 0.1
 * @date 2023-03-19
 * @since SunDay; 04:57 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <array>
#include <algorithm>
#pragma pack(1)
using namespace std;

class Test{
private:
	constexpr static size_t sizeArray{5};
	array <int, sizeArray> array1 {};
public:
	Test(void) = default;
	void showArrayElements(void)const{
		cout<<"[ ";
		for(const int &element: array1){
			cout<<element<<" ";
		}
		cout<<"]"<<endl;
	}
	
	void fillArrayBy(const int &x){
		array1.fill(x);
	}
	
	~Test(void) = default;
};

class Demo{
private:
	int rowArray[5]; /*By default initialized by zero*/
public:
    Demo(void) = default;
	void showArrayElements(void) const {
		
		cout<<"{ ";
		for(const int &element: rowArray){
			cout<<element<<" ";
		}
		cout<<"}"<<endl;
	}

    void fillArrayBy(const int &x){
        for(int &element: rowArray){
            element = x;
        }
    }
    ~Demo(void) = default;
};

int main(int argc, const char *const argv[]){
	Test t{};
	t.showArrayElements();
	t.fillArrayBy(9);
	t.showArrayElements();
    cout<<"------------------------------"<<endl;
	Demo d{};
	d.showArrayElements();
    d.fillArrayBy(9);
    d.showArrayElements();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}