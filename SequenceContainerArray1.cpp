/**
 * @file SequenceContainerArray1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm for STL of array class, it's better than raw array
 * @version 0.1
 * @date 2023-03-18
 * @since SaturDay; 11:25 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> /*accumulate(, ,)*/
#pragma pack(1)
using namespace std;

void lineBar(const char *const funcName){
	cout<<funcName<<": =========================================="<<endl;
}

/*Display the array -- note the size MUST be included*/
void display(const array<int, 5> &numbers){
	cout<<"[ ";
	for(const auto &num: numbers){
		cout<<num<<" ";
	}
	cout<<"]"<<endl;
}

void test1(void){
	lineBar("Test1");
	array <int, 5> numbers1{1, 2, 3, 4, 5};
	array <int, 5> numbers2; /*Elements are not initialized (contains [garbase]*/
	display(numbers1);
	display(numbers2);
	
	numbers2 = {10, 20, 30, 40, 50};
	display(numbers1);
	display(numbers2);
	
	cout<<"Size of (array1) numbers1: "<<numbers1.size()<<endl; /*5*/
	cout<<"Size of (array2) numbers2: "<<numbers2.size()<<endl; /*5*/
	
	numbers1[0] = 1000;
	numbers1.at(1) = 2000;
	display(numbers1);
	
	cout<<"Front of (array2) numbers2: "<<numbers2.front()<<endl; /*10*/
	cout<<"Back of (array2) numbers2: "<<numbers2.back()<<endl; /*50*/
}

void test2(){
	lineBar("Test2");
	array <int, 5> array1{1, 2, 3, 4, 5};
	array <int, 5> array2{10, 20, 30, 40, 50};
	display(array1);
	display(array2);
	
	array1.fill(0);
	display(array1);
	display(array2);
	
	array1.swap(array2);
//	array2.swap(array1);
//	swap(array1, array2);
//	swap(array2, array1);
	
	display(array1);
	display(array2);
}

void test3(void){
	lineBar("Test3");
	array <int, 5> array1{1, 2, 3, 4, 5};
	display(array1);
	int *ptr {array1.data()};
	cout<<"ptr: "<<ptr<<endl;
	cout<<"*ptr: "<<*ptr<<endl; /*We can access row array using pointer notation*/
	cout<<"ptr[0]: "<<ptr[0]<<endl; /*We can access row array using array subscript notation*/
	*(ptr + 1) = 100;
	display(array1);
}

void test4(void){
	lineBar("Test4");
	array <int, 5> array1 {2, 1, 4, 5, 3};
	display(array1);
	/*Ascending order*/
	sort(array1.begin(), array1.end());
	display(array1);
	/*Descending order*/
	sort(array1.begin(), array1.end(), greater<int>());
	display(array1);
}

void test5(void){
	lineBar("Test5");
	array <int, 5> array1{2, 1, 4, 5, 3};
	display(array1);
	array <int, 5> :: iterator minNumber1 {min_element(array1.begin(), array1.end())};
	
	auto maxNumber1{max_element(array1.begin(), array1.end())};
	cout<<"Min Element: "<<*minNumber1<<", Max Element: "<<*maxNumber1<<endl;
}

void test6(void){
	lineBar("Test6");
	array <int, 5> array1{2, 1, 3, 3, 5};
	display(array1);
	
	auto adjacent {adjacent_find(array1.cbegin(), array1.cend())};
	if(adjacent != array1.cend()){
		cout<<"Adjacent element found with value: "<<*adjacent<<endl;
	}
	else{
		cout<<"No adjacent elements found..!"<<endl;
	}
}

void test7(void){
	lineBar("Test7");
	/*Accumulate is from #include <numeric>*/
	array <int, 5> array1{1, 2, 3, 4, 5}; 
	display(array1);
	ssize_t sum{accumulate(array1.cbegin(), array1.cend(), 0)}; /*I think size_t were best*/
	cout<<"Sum of the elements in array1 is: "<<sum<<endl;
}

void test8(void){
	lineBar("Test8");
	array <int, 10> array1{1, 2, 3, 1, 2, 3, 3, 3, 3, 3};
	cout<<"[ ";
	for_each(array1.cbegin(), array1.cend(),[](const int &x){cout<<x<<" ";});
	cout<<"]"<<endl;
	
	ssize_t counter {count(array1.begin(), array1.end(), 3)}; /*I think size_t were best*/
	cout<<"Found 3: "<<counter<<" times"<<endl;
}

void test9(void){
	lineBar("Test9");
	array <int, 10> array1 {1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
	cout<<"[ ";
	for_each(array1.cbegin(), array1.cend(),[](const int &x){cout<<x<<" ";});
	cout<<"]"<<endl;
	/*Find how many numbers are between 10 and 200 -> 50, 60, 70, 80*/
	ssize_t counter {count_if(array1.cbegin(), array1.cend(),
		[](const int &x){
			return (x > 10 && x < 200);
		}
	)};
	cout<<"[ ";
	for_each(array1.cbegin(), array1.cend(),
		[](const int &x){
			if(x>10 && x <200){
				cout<<x<<" ";
			}
		}
	);
	cout<<"]";
	cout<<"Found "<<counter<<" matches"<<endl;
}

int main(int argc, const char *const argv[]){
	test1();
	test2(); 
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}