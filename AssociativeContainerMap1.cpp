/**
 * @file AssociativeContainerMap1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Map- similar to dictionary & perfrom algorithms with map
 * @version 0.1
 * @date 2023-03-26
 * @since SunDay; 09:10 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#pragma pack(1)
using namespace std;

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

template <typename var1, typename var2>
void display(const map <var1, var2> &myMap){
	cout<<"MAP"<<endl;
	cout<<"[ ";
	for(const auto &element: myMap){
		cout<<element.first<<":"<<element.second<<" ";
	}
	cout<<"]"<<endl;
}

void mapTest1(void){
	headerSection("Map Test1");
	map <string, int> m1{
		{"Larry", 3},
		{"Moe", 1},
		{"Curly", 2}
	};
	display(m1);
	cout<<endl;
	
	m1.insert({"Yousuf", 26});
	display(m1);
	cout<<endl;
	
	m1.insert(pair <string, int> {"Anna", 10});
	display(m1);
	cout<<endl;
	
	m1.insert(make_pair("Joe", 5));
	display(m1);
	cout<<endl;
	
	m1["Frank"] = 18;
	display(m1);
	cout<<endl;
	
	m1["Frank"] += 10; /*18 + 10 = 28*/
	display(m1);
	cout<<endl;
	
	m1.erase("Frank");
	display(m1);
	cout<<endl;
	
	cout<<"Count for Joe: "<<m1.count("Joe")<<endl;
	cout<<"Count fo Frank: "<<m1.count("Frank")<<endl;
	cout<<endl;
	
	/*Finding using an ITERATOR*/
	auto it{m1.find("Larry")};
	if(it != m1.cend()){
		cout<<"Fount = "<<it->first<<":"<<it->second<<endl;
	}
	else{
		cout<<"NOT found!!!"<<endl;
	}
	cout<<endl;
	
	/*Check exist or not without any ITEARTOR*/
	if(m1.find("Larry") != m1.cend()){
		cout<<"Larry is found."<<endl;
	}
	else{
		cout<<"Larry is NOT found..!"<<endl;
	}
	cout<<endl;
	
	m1.clear();
	display(m1);
	cout<<"IsEmpty(m1): "<<boolalpha<<m1.empty()<<endl;
	footerSection("Map Test1");
}

void display(const map <string, set<int>> &myMap){
	cout<<"MAP & SET"<<endl;
	
	for(const auto &mapElement: myMap){
		cout<<"[ "<<mapElement.first<<": [";
		for(const auto &setElemrnt: mapElement.second){
			cout<<setElemrnt<<" ";
		}
		cout<<"]";
		cout<<" ]"<<endl;
	}
}

void mapTest2(void){
	headerSection("Map Test2");
//	key: string and values int and ds. set
	map<string, set<int>> grades{
		{"Larry", {100, 90}},
		{"Moe", {94}},
		{"Curly", {80, 89, 100}}
	};	
	display(grades);
	cout<<endl;
	
	grades["Larry"].insert(95);
	display(grades);
	cout<<endl;
	
	auto it{grades.find("Moe")};
	if(it != grades.cend()){
		it->second.insert(1000);
	}
	display(grades);

	footerSection("Map Test2");
}

int main(int argc, const char *const argv[]){
    system("cls");
	mapTest1();
	mapTest2();
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};