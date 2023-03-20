/**
 * @file SequenceContainerVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief SLT algorithm experiment with vector container
 * @version 0.1
 * @date 2023-03-20
 * @since MonDay; 10:59 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <algorithm>
#include <vector>
#pragma pack(1)
using namespace std;

const void lineBar(const char *const title);

class Person{
private:
	string name{};
	int age{};
	friend ostream &operator<< (ostream &cout, const Person &person){
		cout<<person.name<<":"<<person.age;
		return cout;
	}
public:
	Person(void):Person{"No Name", 0}{} /*Delegating constructor*/
	Person(const string_view &name, const int &age):name{name}, age{age}{}
	/*Remember when we're using our own classes with the STL
	 always always overload (<, ==) operators*/
	bool operator< (const Person &rhs)const{
		return (this->age < rhs.age);
	}
	
	bool operator== (const Person &rhs)const{
		return ((this->name == rhs.name) && (this->age == rhs.age));
	}
	~Person(void) = default;
};

/*Template function to display any vector*/
template <typename var>
void display1(const vector <var> &v){
	cout<<"[ ";
	for(const auto &element: v){
		cout<<element<<" ";
	}
	cout<<"]"<<endl;
}

/*Use for_each() and a lambda expression to display vector elements*/
void display2(const vector <int> &v){
	cout<<"[ ";
	for_each(v.cbegin(), v.cend(),
		[](const int &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}

void test1(void){
	lineBar("Test1");
	vector <int> numbers1{1, 2, 3, 4, 5};
	display1(numbers1);
	
	numbers1 = {2, 4, 5, 6};
	display1(numbers1);
	
	vector <int> numbers2(10, 100);/*Ten 100s in the vector*/
	display2(numbers2);
}

void test2(void){
	lineBar("Tes2");
	vector <int> numbers1 {1, 2, 3, 4, 5};
	display1(numbers1);
	cout<<endl;
	
	cout<<"Vector size: "<<numbers1.size()<<endl;
	cout<<"Vector max size: "<<numbers1.max_size()<<endl;
	cout<<"Vector capacity: "<<numbers1.capacity()<<endl;
	cout<<endl;
	
	numbers1.push_back(6); 
	display1(numbers1);
	cout<<"Vector size: "<<numbers1.size()<<endl;
	cout<<"Vector capaity: "<<numbers1.capacity()<<endl;
	cout<<endl;
	
	numbers1.shrink_to_fit(); /*C++ 11*/
	display2(numbers1);
	cout<<"Vector size: "<<numbers1.size()<<endl;
	cout<<"Vector capaity: "<<numbers1.capacity()<<endl;
	cout<<endl;
	
	numbers1.reserve(100);
	display1(numbers1);
	cout<<"Vector size: "<<numbers1.size()<<endl;
	cout<<"Vector capaity: "<<numbers1.capacity()<<endl;
	cout<<"Vector max size: "<<numbers1.max_size()<<endl;
}

void test3(void){
	lineBar("Test3");
	vector <int> numbers1{1, 2, 3, 4, 5};
	display1(numbers1);
	numbers1[0] = 100; /*It does NOT check array bounds*/
	numbers1.at(1) = 200; /*It checks array bounds*/
	
	display1(numbers1);
}

void test4(void){
	lineBar("Test4");
	vector <Person> stooges{};
	Person p1{"Larry", 18};
	display1(stooges);
	
	stooges.push_back(p1);
	display1(stooges);
	
	stooges.push_back(Person{"Moe", 25}); /*Using move semantics*/
	display1(stooges);
//	Person p2 {"Yousuf", 26};
//	stooges.emplace_back(p2);
	stooges.emplace_back("Curly", 30); /*Use emplace_back*/
	display1(stooges);
}

void test5(void){
	lineBar("Test5");
	vector <Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 30}
	};
	display1(stooges);
	cout<<"Front: "<<stooges.front()<<endl;
	cout<<"Back: "<<stooges.back()<<endl;
	stooges.pop_back();
	display1(stooges);
}

void test6(void){
	lineBar("Test6");
	vector <int> numbers1{1, 2, 3, 4, 5};
	display2(numbers1);
	numbers1.clear(); /*Removed all elements*/
	display2(numbers1);
	
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display2(numbers1);
	
	numbers1.erase(numbers1.cbegin(), numbers1.cbegin() + 2);
	display2(numbers1);
	
	numbers1.clear();
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display2(numbers1);
	/*erase all even number*/
	auto it {numbers1.cbegin()};
	while(it != numbers1.cend()){
		if(*it & 1){ /*Odd*/
			it++; /*Only increment if not erased*/
		}
		else{ /*Even*/
			numbers1.erase(it);
		}
	}
	display2(numbers1);
	numbers1.clear();
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display2(numbers1);
	/*erase all odd number*/
	it = numbers1.cbegin();
	while(it != numbers1.cend()){
		if(*it & 1){
			numbers1.erase(it);
		}
		else{
			it++;
		}
	}
	display2(numbers1);
}

void test7(void){
	lineBar("Test7");
	vector <int> numbers1 {1, 2, 3, 4, 5};
	vector <int> numbers2{10, 20, 30, 40, 50};
	
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
//	swap(numbers1, numbers2); /*Type1*/
	numbers1.swap(numbers2); /*Type2*/
	display2(numbers1);
	display2(numbers2);
}

void test8(void){
	lineBar("Test8");
	vector <int> numbers1{1, 21, 3, 40, 12, 11};
	display2(numbers1);
	sort(numbers1.begin(), numbers1.end(), greater <int>()); /*Descending order*/
	display2(numbers1);
}

void test9(void){
	/*
	 * back_inserter contructs a back-insert iterator that inserts new elements
	 * at the end of the container it applied to.
	 * It's a special output iterator.
	 * It's awesome!!! and very efficient.
	 * There is also a front_inserter we can use with deques and lists.
	 * Copy one list to another using an iterator and back_inserter
	 */
	lineBar("Test9");
	vector <int> numbers1{1, 2, 3, 4, 5};
	vector <int> numbers2{10, 20};
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
	copy(numbers1.cbegin(), numbers1.cend(), back_inserter(numbers2));
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
	numbers1.clear();
	numbers1.clear();
	/*Copy-if the element is even*/
	numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	numbers2 = {10, 20};
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
	copy_if(numbers1.cbegin(), numbers1.cend(), back_inserter(numbers2),
		[](const int &x){
			return(!(x & 1)); /*if x is even*/
		}
	);
	display2(numbers1);
	display2(numbers2);
}

void test10(void){
	lineBar("Test10");
	/*Transform over 2 ranges*/
	vector <int> numbers1 {1, 2, 3, 4, 5};
	vector <int> numbers2 {10, 20, 30, 40, 50};
	vector <int> numbers3 {};
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
	/*10x1, 2x20, 3x30, 4x40, 5x50 and store the result in numbers3*/
	if(numbers1.size() == numbers2.size()){
		transform(numbers1.cbegin(), numbers1.cend(), numbers2.cbegin(),
		:: back_inserter(numbers3),
			[](const int &x, const int &y){
				return(x*y);
			}
		);
		
		display2(numbers3);
	}
	else{
		cout<<"Output will be GARBAGE value..!";
	}
	
}

void test11(void){
	lineBar("Test11");
	/*Insert vector2 into vector1 before the 5*/
	vector <int> numbers1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> numbers2 {100, 200, 300, 400};
	
	display2(numbers1);
	display2(numbers2);
	cout<<endl;
	
	auto it{find(numbers1.cbegin(), numbers1.cend(), 5)};
	if(it != numbers1.cend()){
		cout<<"Inserting..."<<endl;
		numbers1.insert(it, numbers2.cbegin(), numbers2.cend());
	}
	else{
		cout<<"Soryy, 5 is not found...!"<<endl;
	}
	display2(numbers1);
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
	test10();
	test11();
	cout<<"\t\tHappyEnding...!"<<endl;
	return 0;
}

const void lineBar(const char *const title){
	cout<<"---"<<title<<":--------------------------------------"<<endl;
}