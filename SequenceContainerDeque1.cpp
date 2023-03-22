/**
 * @file SequenceContainerDeque1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief SLT algorithm experiment with deque container
 * @version 0.1
 * @date 2023-03-22
 * @since WednesDay; 12:17 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#pragma pack(1)
using namespace std;

const void headerPrint(const char *const header){
	cout<<"---"<<header<<":--------------------------------------"<<endl;
}

const void footerPrint(const char *const footer){
	cout<<"----------------------------------------"<<footer<<":---\n"<<endl;
}

/*Template function to display any deque*/\
template <typename var>
void display(const deque <var> &d){
	cout<<"[ ";
	for_each(d.cbegin(), d.cend(),
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

void test1(void){
	headerPrint("Start Test1");
	deque <int> d1{1, 2, 3, 4, 5};
	display(d1);
	cout<<endl;
	
	d1 = {2, 4, 5, 6};
	display(d1);
	cout<<endl;
	deque <int> d2 (10, 100); /*Ten 100s in the deque*/
	display(d1);
	
	d1[0] = 100;
	d1.at(1) = 200;
	display(d1);
	footerPrint("Test1 End");
}

void test2(void){
	/*push ad pop*/
	headerPrint("Start Test2");
	
	deque <int> d1{0, 0, 0};
	display(d1);
	cout<<endl;
	d1.emplace_back(10);
	d1.emplace_back(20);
	display(d1);
	cout<<endl;
	d1.emplace_front(100);
	d1.emplace_front(200);
	display(d1);
	cout<<"Front of d1: "<<d1.front()<<endl;
	cout<<"Back of d1: "<<d1.back()<<endl;
	cout<<"Size of d1: "<<d1.size()<<endl;
//	cout<<"Capacity of d1: "<<d1.capacity()<<endl; /*capacity() is not member of deque*/
	cout<<"Max-Size of d1: "<<d1.max_size()<<endl;
	cout<<endl;
	
	d1.pop_front();
	d1.pop_back();
	display(d1);
	footerPrint("Test2 End");
}

void test3(void){
	/*Insert all even numbers into the back of deque all all
	 odd numbers into the front*/
	headerPrint("Start Test3");
	vector <int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](int const &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	deque <int> d1{};
	for(auto it{v1.cbegin()}; it != v1.cend(); it++){
		if((*it & 1)){
			d1.emplace_front(*it); /*push_front(ODD)*/
		}
		else{
			d1.emplace_back(*it); /*push_back(EVEN)*/
		}
	}
	display(d1);
	footerPrint("Test3 End");
}

void test4(void){
	/*Push front VS back ordering*/
	headerPrint("Start Test4");
	
	vector <int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](int const &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	deque <int> d1{};
	for(auto it{v1.cbegin()}; it != v1.cend(); it++){
		d1.emplace_front(*it); /*Reverse order*/
	}
	display(d1);
	
	d1.clear();
	
	for(auto it{v1.cbegin()}; it != v1.cend(); it++){
		d1.emplace_back(*it);
	}
	display(d1);
	
	footerPrint("Test4 End");
}

void test5(void){
	/*Same as test4() using copy()*/
	headerPrint("Start Test5");
	
	vector <int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"[ ";
	for_each(v1.cbegin(), v1.cend(), 
		[](int const &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
	
	deque <int> d1{};
	copy(v1.cbegin(), v1.cend(), ::front_inserter(d1));
	display(d1);
	
	d1.clear();
	
	copy(v1.cbegin(), v1.cend(), :: back_inserter(d1));
	display(d1);
	
	d1.clear();
	
	copy_if(v1.cbegin(), v1.cend(),:: back_inserter(d1),
		[](const int &x){
			return ((x & 1)); /*Only odd number*/
		}
	);
	display(d1);
	
	footerPrint("Test5 End");
}

int main(int argc, const char *const argv[]){
	test1();
	test2();
	test3();
	test4();
	test5();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}
