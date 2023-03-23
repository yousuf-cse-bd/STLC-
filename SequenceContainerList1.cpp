/**
 * @file SequenceContainerList1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief SLT common algorithm experiment with list container
 * @version 0.1
 * @date 2023-03-23
 * @since ThursDay; 06:15 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <list> /*Link-list*/
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
public:
	Person(void):Person{"Unknown", 0}{}
	Person(const string_view &name, const int &age):name{name}, age{age}{}
	bool operator< (const Person &rhs)const{
		return (this->age < rhs.age);
	}
	
	bool operator== (const Person &rhs)const{
		return ((this->name == rhs.name) && (this->age == rhs.age));
	}
	~Person(void) = default;
};

template <typename var>
void display(const list <var> &li){
	cout<<"[ ";
	for_each(li.cbegin(), li.cend(),
		[](const var &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

const void headerPrint(const char *const header){
	cout<<"---"<<header<<":--------------------------------------"<<endl;
}

const void footerPrint(const char *const footer){
	cout<<"----------------------------------------"<<footer<<":---\n"<<endl;
}

void test1(void){
	headerPrint("Start Test1");
	
	list <int> li1{1, 2, 3, 4, 5};
	display(li1);
	cout<<endl;
	
	list <string> li2{};
	li2.emplace_back("Back");
	li2.emplace_front("Front");
	display(li2);
	cout<<endl;
	
	list <int> li3{};
	li3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(li3);
	cout<<endl;
	
	list <int> li4(5, 10); /*Size 5, all elements are 10*/
	display(li4);
	
	footerPrint("Test1 End");
}


void test2(void){
	headerPrint("Start Test2");
	
	list <int> li1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(li1);
	cout<<"Size: "<<li1.size()<<endl;
	cout<<"Front: "<<li1.front()<<endl;
	cout<<"Back: "<<li1.back()<<endl;
	li1.clear();
	display(li1);
	cout<<"Size: "<<li1.size()<<endl;
	cout<<"IsEmpty: "<<boolalpha<<li1.empty()<<endl;
	
	footerPrint("Test2 End"); 
}

void test3(void){
	headerPrint("Start Test3");
	
	list <int> li1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(li1);
	
	li1.resize(5);
	display(li1);
	
	li1.resize(10);
	display(li1);
	cout<<endl;
	
	list <Person> personsList1(5);
	display(personsList1); /*Unknown:0 5times*/
	cout<<endl;
	
	list <Person> personsList2{};
	personsList2.resize(5); /*Used the Person default constructor*/
	display(personsList2);
	
	footerPrint("Test3 End");
}

void test4(void){
	headerPrint("Start Test4");
	
	list <int> li1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(li1);
	cout<<endl;
	
	auto it{find(li1.cbegin(), li1.cend(), 5)};
	if(it != li1.cend()){
		cout<<"Inserting an element [100]..."<<endl;
		li1.insert(it, 100);
	}
	else{
		cout<<"The 5 is not found..!"<<endl;
	}
	display(li1);
	cout<<endl;
	
	list <int> li2{1000, 2000, 3000};
	cout<<"Iterator points to: "<<*it<<endl;
	cout<<"Inserting a list..."<<endl;
	li1.insert(it, li2.cbegin(), li2.cend());
	display(li1);
	cout<<endl;
	
	cout<<"Iterator points to: "<<*it<<endl;
	advance(it, -4); /*Points to the 100*/
	cout<<"Iterator points to: "<<*it<<endl;
	
	li1.erase(it); /*Remove the 100 - iterator becomes invalid*/
	display(li1);
	
	footerPrint("Test4 End");
}

void test5(void){
	headerPrint("Start Test5");
	
	list <Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17}};
	display(stooges);
	cout<<endl;
	
	string name{};
	int age{};
	cout<<"Enter the name of the next stooge: ";
	getline(cin, name);
	
	cout<<"Enter his age: ";
	cin>>age;
	
	stooges.emplace_back(name, age);
	display(stooges);
	cout<<endl;
	
	/*Insert Frank before Moe*/
	auto it{find(stooges.cbegin(), stooges.cend(), Person{"Moe", 25})};
	if(it != stooges.cend()){
		cout<<"\tInserting [Frank, 28]..."<<endl;
		stooges.insert(it, {"Frank", 28});
	}
	else{
		cout<<"{\"Moe\", 25} is NOT found...!"<<endl;
	}
	display(stooges);
	footerPrint("Test5 End");
}

void test6(void){
	headerPrint("Start Test6");
	
	list <Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17}
	};
	display(stooges);
	cout<<endl;
	
	stooges.sort();
	display(stooges);
	
	footerPrint("Test6 End");
}

int main(int argc, const char *const argv[]){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	cout<<setw(50)<<right<<"HappyEnding...!"<<endl;
	return 0;
}
