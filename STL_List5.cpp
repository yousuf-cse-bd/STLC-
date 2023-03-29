/**
 * @file STL_List5.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Storing class objects in a list, (<,>, <=, >=, ==, !=) overloading
 * @version 0.1
 * @date 2023-03-29
 * @since WednesDay; 09:55 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <iomanip>
#pragma pack(1)
using namespace std;

class Inteface{
private:
	friend ostream &operator<< (ostream &cout, const Inteface &interface){
		interface.print(cout);
		return cout;
	}
	
	virtual void print(ostream &cout) const = 0;
public:
	Inteface(void) = default;
	virtual ~Inteface(void) = default;
};

class MyClass: public Inteface{
private:
	virtual void print(ostream &cout) const override {
		cout<<sum;
	}
	int term1{};
	int term2{};
	ssize_t sum{};
public: /*Delegating constructors without this pointer*/
	MyClass(void): MyClass{0, 0}{}
	MyClass(const int &term1):MyClass{term1, 0}{}
	MyClass(const int &term1, const int term2):term1{term1}, term2{term2}{
		sum = term1 + term2;
	}
	bool operator< (const MyClass &rhs) const {
		return (this->term1 < rhs.term2);
	}
	bool operator> (const MyClass &rhs) const {
		return (this->term1 > rhs.term2);
	}
	
	bool operator<= (const MyClass &rhs) const {
		return (this->term1 <= rhs.term2);
	}
	bool operator>= (const MyClass &rhs) const {
		return (this->term1 >= rhs.term2);
	}
	
	bool operator== (const MyClass &rhs) const {
		return (this->term1 == rhs.term2);
	}
	bool operator!= (const MyClass &rhs) const {
		return (this->term1 != rhs.term2);
	}
	
	virtual ~MyClass(void) = default;
};

template <typename var>
void display(const list <var> &myList){
	cout<<"[ ";
	for_each(myList.cbegin(), myList.cend(), 
		[](const var &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

int main(int argc, const char *const argv[]){
	system("cls");
	cout<<setprecision(2)<<fixed;
	
	list <MyClass> lst1{};
	list <MyClass> lst2{};
	
	for(int i{0}; i < 10; i++){
		lst1.emplace_back(i, i);
		lst2.emplace_back(i*2, i*3);
	}
	cout<<"Frist list: ";
	display(lst1);
	cout<<endl;
	cout<<setw(50)<<setfill('-')<<""<<endl;
	
	cout<<"Second list: ";
	display(lst2);
	cout<<endl;
	cout<<setw(50)<<setfill('-')<<""<<endl;
	
	lst1.merge(lst2);
	cout<<"After merging both of lists"<<endl;
	cout<<boolalpha<<"IsEmpty(lst2)?: "<<lst2.empty()<<" & size(lst1): "<<lst1.size()<<endl;
	display(lst1);
	cout<<endl;
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
