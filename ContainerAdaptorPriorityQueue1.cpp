/**
 * @file ContainerAdaptorPriorityQueue1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief top()- access the top element (greatest)
 * @version 0.1
 * @date 2023-03-27
 * @since MonDay; 11:02 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#pragma pack(1)
using namespace std;

class Person{
	friend ostream &operator<< (ostream &cout, const Person &person){
		cout<<person.name<<":"<<person.age;
		return cout;
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
	bool operator== (const Person &rhs) const {
		return ((this->name == rhs.name) && (this->age == rhs.age));
	}
	~Person(void) = default;
};

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}
/*This displays the priority queue by repeatedly topping and popping the priority queue
 * It is being passed by value so we don't modify the priority queue being passed in
 * */

template <typename var>
void display(priority_queue <var> pq){
	cout<<"[ ";
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"]"<<endl;
}

void test1(void){
	headerSection("Test1");
	
	priority_queue <int> pq{};
	for(const int &element: {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7}){
		pq.push(element);
	}
	cout<<"Size of pq: "<<pq.size()<<endl;
	cout<<"Top of pq: "<<pq.top()<<endl;
	display(pq);
	cout<<endl;

	pq.pop();
	display(pq);
	footerSection("Test1");
}

void test2(void){
	headerSection("Test2");
	
	priority_queue <Person> persons{};
	persons.push(Person{"A", 10});
	persons.push(Person{"B", 1});
	persons.push(Person{"C", 14});
	persons.push(Person{"D", 18});
	persons.push(Person{"E", 7});
	persons.push(Person{"F", 27});
	
	display(persons);
	
	footerSection("Test2");
}

int main(int argc, const char *const argv[]){
	system("cls");

	test1();
	test2();
		
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}

