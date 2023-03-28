/**
 * @file AllComparedOperatorsWithList1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief There are all types of compared operator overloading with sorting
 * @version 0.1
 * @date 2023-03-28
 * @since TuesDay; 09:02 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <iomanip>
#pragma pack(1)
using namespace std;

class Interface{
	friend ostream &operator<< (ostream &cout, const Interface &interface){
		interface.print(cout);
		return cout;
	}
public:
	Interface(void) = default;
	virtual void print(ostream &cout) const = 0;
	virtual ~Interface(void) = default;
};

class Person: public Interface{
	virtual void print(ostream &cout) const override{
		cout<<name<<":"<<age;
	}
private:
	string name{};
	int age{};
	
	constexpr static const char *const defName{"Unknown"};
	constexpr static const int defAge{0};
	
public:
	Person(const string_view &name = defName, const int &age = defAge):
		name{name}, age{age}{}
		
	bool operator< (const Person &rhs) const {
		return (this->age < rhs.age);
	}	
	
	bool operator<= (const Person &rhs) const {
		return (this->age <= rhs.age);
	}
	
	bool operator> (const Person &rhs) const {
		return (this->age > rhs.age);
	}
	bool operator>= (const Person &rhs) const {
		return (this->age >= rhs.age);
	}
	bool operator== (const Person &rhs) const {
		return ((this->name == rhs.name) && (this->age == rhs.age));
	}
	
	bool operator!= (const Person &rhs) const {
		return ((this->name != rhs.name) && (this->age != rhs.age));
	}
	virtual ~Person(void) = default;
};

template <typename var>
void display(const list <var> &myList){
	for_each(myList.cbegin(), myList.cend(), 
		[](const auto &x){
			cout<<"[ "<<x<<" ]"<<endl;
		}
	);
}

int main(int argc, const char *const argv[]){
	system("cls");
	
	list <Person> stooges{
		{"Larry", 21},
		{"Moe", 25},
		{"Curly", 18}
	};
	
	display(stooges);
	cout<<endl;
	
	stooges.sort();
	display(stooges);
	cout<<endl;
	
	stooges.sort(greater<Person>());
	display(stooges);
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
