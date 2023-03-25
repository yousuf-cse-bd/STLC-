/**
 * @file AssociativeContainerSet1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Set- similar to mathematical set & perfrom algorithms with set
 * @version 0.1
 * @date 2023-03-25
 * @since SaturDay; 12:10 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>
#include <set>
#include <limits>
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

template <typename var>
void display(const set <var> &mySet){
	cout<<"[ ";
	for_each(mySet.cbegin(), mySet.cend(),
		[](const var &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

void test1(void){
	headerSection("Test1");
	
	set <int> s1{1, 4, 3, 5, 2};
	display(s1); /*1 2 3 4 5*/
	cout<<endl;
	
	s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5}; /*Duplicates are NOT allowed in set*/
	display(s1); /*1 2 3 4 5*/
	cout<<endl;
	
	s1.insert(0);
	s1.insert(10);
	
	display(s1); /*0 1 2 3 4 5 10*/
	cout<<endl;
	
	auto isCount{s1.count(100)}; /*size_t == 8 Bytes*/
	cout<<"Is-Count(100): "<<isCount<<" and sizeof(isCount): "<<sizeof(isCount)<<" Bytes"<<endl;
	if(s1.count(10)){
		cout<<"10 is in the set."<<endl;
	}
	else{
		cout<<"10 is NOT in the set."<<endl;
	}
	
	auto it{find(s1.cbegin(), s1.cend(), 5)};
	if(it != s1.cend()){
		cout<<"The 5 is found."<<endl;
	}
	else{
		cout<<"The 5 is NOT found...!"<<endl;
	}
	cout<<endl;
	s1.clear();
	display(s1);
	cout<<"IsEmpty(s1): "<<boolalpha<<s1.empty()<<" the size(s1): "<<s1.size()<<endl;
	footerSection("Test1");
}

void test2(void){
	headerSection("Test2");
	
	set <Person> stooges{
		{"Larry", 1},
		{"Moe", 2},
		{"Curly", 3}
	};
	
	display(stooges); /*Note the order of display! operator<*/
	cout<<endl;
	
	stooges.emplace("James", 50);
	display(stooges);
	cout<<endl;
	
	stooges.emplace("Frank", 50); /*NO -- 50 already exists*/
	display(stooges);
	cout<<endl;
	
	auto it{find(stooges.cbegin(), stooges.cend(), Person{"Moe", 2})};
	if(it != stooges.cend()){
		cout<<"{Moe, 2} is found"<<endl;
	}
	else{
		cout<<"{Moe, 2} is NOT found"<<endl;
	}
	cout<<endl;
	it = stooges.find(Person{"Mew", 2});
	if(it != stooges.cend()){
		cout<<"{Moe, 2} is found"<<endl;
	}
	else{
		cout<<"{Moe, 2} is NOT found"<<endl;
	}
	
	it = stooges.find(Person{"James", 50});
	if(it != stooges.cend()){
		cout<<"Person{\"James\", 50} is found and aresed it."<<endl;
		stooges.erase(it);
	}
	else{
		cout<<"Person{\"James\", 50} is NOT found"<<endl;
	}
	display(stooges);  
	cout<<endl;
	
	it = stooges.find(Person{"XXX", 1}); /*Will remove Larry!!! uses operator<*/
	if(it != stooges.cend()){
		stooges.erase(it);
	}
	display(stooges);
	footerSection("Test2");
}

void test3(void){
	headerSection("Test3");
	
	set <string> s1 {"A", "B", "C"};
	display(s1);
	cout<<endl;
	
	auto result {s1.insert("D")};
	display(s1);
	cout<<endl;

	cout<<boolalpha;
	cout<<"First: "<<*(result.first)<<endl;
	cout<<"Second: "<<(result.second)<<endl;
	cout<<endl;
	
	result = s1.insert("A");
	display(s1);
	cout<<"First: "<<*(result.first)<<endl;
	cout<<"Second: "<<(result.second)<<endl;
	
	footerSection("Test3");
	
}

int main(int argc, const char *const argv[]){
	system("cls");
	
	test1();
	test2();
	test3();

	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
