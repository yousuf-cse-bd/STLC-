/**
 * @file VectorSorting1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Vector sorting examples primitive data and class
 * @version 0.1
 * @date 2023-03-23
 * @since ThursDay; 07:28 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
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
void display(const vector <var> &li){
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


void sortPersonElementsAsc(void){
	headerPrint("Start Sort Asc");
	
	vector <Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17}
	};
	display(stooges);
	cout<<endl;
	/*It depends on operator (<) overloading*/
	sort(stooges.begin(), stooges.end());
	display(stooges);
	
	footerPrint("Sort Asc End ");
}

void sortPersonElementsDesc(void){
	headerPrint("Start Sort Desc");
	
	vector <int> ages{10, 15, 17, 25, 36};
	display(ages);
	cout<<endl;
	
	sort(ages.begin(), ages.end(), greater<int>());
	display(ages);
	
	footerPrint("Sort Desc End");
}

int main(int argc, const char *const argv[]){
	sortPersonElementsAsc();
	sortPersonElementsDesc();
	cout<<setw(50)<<right<<"HappyEnding...!"<<endl;
	return 0;
}
