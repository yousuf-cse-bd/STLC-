/**
 * @file AlgorithmsDemo1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief There are some STL algorithms example
 * @version 0.1
 * @date 2023-03-18
 * @since SaturDay; 05:46 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#pragma pack(1)
using namespace std;

class Person{
	friend ostream &operator<< (ostream &cout, const Person &person){
		cout<<"["<<person.name<<" : "<<person.age<<"]";
		return cout;
	}
private:
	string name{};
	int age{};
public:
	Person(void):Person{"NoName", 0}{}
	Person(const string_view &name, const int &age):name{name}, age{age}{}
	~Person(void) = default;
	
	bool operator< (const Person &rhs) const {
		return (this->age < rhs.age);
	}
	bool operator == (const Person &rhs) const { /*To need for finding*/
		return ((this->name == rhs.name) && (this->age == rhs.age));
	}
};
const void lineBar(void){
	cout<<"================================================"<<endl;
}
/*Find an element in a container*/
const void findTest1(void){
	lineBar();
	cout<<"Find an element in a primitive container"<<endl;
	vector <int> numbers1{10, 20, 30, 40, 50};
	auto location {find(numbers1.cbegin(), numbers1.cend(), 50)};
	if(location != numbers1.cend()){
		cout<<"\tFound the number: "<<*location<<endl;
	}
	else{
		cout<<"\tCoultn't find the number...!"<<endl;
	}
}

const void findTest2(void){
	lineBar();
	cout<<"Find an element in custom container"<<endl;
	list <Person> players{
		{"Larry", 18},
		{"Moe", 20},
		{"Curly", 21}
	};
	auto location {find(players.cbegin(), players.cend(), Person{"Moe", 20})};
	if(location != players.cend()){
		cout<<"\tFound Moe, "<<*location<<endl;
	}
	else{
		cout<<"\tMoe not found..!"<<endl;
	}
}

const void countTest1(void){
	lineBar();
	cout<<"Count the number of elements in a container"<<endl;
	vector <int> numbers1{1, 2, 3, 4, 5, 1, 2, 1};
	for(const auto &element: numbers1){
		cout<<element<<" ";
	}
	cout<<endl;
	ssize_t counter {count(numbers1.cbegin(), numbers1.cend(), 1)};
	cout<<"1 occurrences "<<counter<<" times."<<endl;
}

/*Count the number of occurences of an element in a container
		based on a predicate using a lambda expression*/
const void countIfTest1(void){
	lineBar();
	vector <int> numbers1{1, 2, 3, 4, 5, 1, 2, 1, 100};
	for(const auto &element: numbers1){
		cout<<element<<" ";
	}
	cout<<endl;
	ssize_t counter = count_if(numbers1.cbegin(), numbers1.cend(), 
		[](const int &x){ /*Lambda expression*/
//			return  (x % 2 != 0); /*Modulus operator*/
			return (x & 1); /*bit-wise and*/
		}
	); 
	cout<<counter<<" odd number found..."<<endl;
	
	/*How can we determine how many element in numbers1 >= 5*/
	counter = count_if(numbers1.cbegin(), numbers1.cend(),
		[](const int &x){ /*Lambda expression*/
			return (x >= 5);
		}
	);
	cout<<counter<<" is >= 5"<<endl;
}
const void replaceTest1(void){
	lineBar();
	cout<<"Replace occurrences of elements in a container"<<endl;
	vector <int> numbers1{1, 2, 3, 4, 5, 1, 2, 1};
	cout<<"Before replaced: ";
	for(auto it{numbers1.cbegin()}; it != numbers1.cend(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	
	replace(numbers1.begin(), numbers1.end(), 1, 100); /*whome: 1, by what: 100*/
	
	cout<<"After replaced: ";
	for(auto it{numbers1.cbegin()}; it != numbers1.cend(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}
/*If all elements are satisfing condition then return true
 other wise false*/
const void allOfTest1(void){
	lineBar();
	vector <int> numbers1{1, 3, 5, 7, 9, 1, 13, 19, 5};
	if(all_of(numbers1.cbegin(), numbers1.cend(),[](const int &x){return (x > 10);})){
		cout<<"All the elements are > 10"<<endl;
	}
	else{
		cout<<"NOT all the elements are > 10"<<endl;
	}
	
	if(all_of(numbers1.cbegin(), numbers1.cend(), [](const int &x){return (x < 20);})){
		cout<<"All of elements are < 20"<<endl;
	}
	else{
		cout<<"NOT all elements are < 20"<<endl;
	}
}
/*Trasnform elements in a container - string in this example*/
const void stringTransformTest1(void){
	lineBar();
	string str1 {"This is a test"};
	cout<<"Before transform: "<<str1<<endl;
	
	transform(str1.begin(), str1.end(), str1.begin(),::toupper);
	cout<<"After transform(toupper): "<<str1<<endl;
	
	transform(str1.begin(), str1.end(), str1.begin(),::tolower);
	cout<<"After transform(tolower): "<<str1<<endl;
}
int main(int argc, const char *const argv[]){
	findTest1();
	findTest2();
	countTest1();
	countIfTest1();
	replaceTest1();
	allOfTest1();
	stringTransformTest1();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}
