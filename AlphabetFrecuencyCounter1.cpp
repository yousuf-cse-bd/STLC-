/**
 * @file AlphabetFrecuencyCounter1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Making a histogram using map container
 * @version 0.1
 * @date 2023-03-26
 * @since SunDay; 11:45 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#pragma pack(1)
using namespace std;

void display(const map <char, size_t> &myMap);

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

string makeCharString(const string &text){
	string line{};
	for(const char &charWise: text){
		if(isalpha(charWise)){
			line += toupper(charWise);
		}
	}
	return line;
}

void alphabeticHistogram(void){
	headerSection("Histogram");
	
	string text{"Muhammad Yousuf Ali, Imtiaz Ahmad Maruf, Tofayel Ahmad Tamim"};
	cout<<"Given Text: "<<text<<endl; 
	text = makeCharString(text);
	cout<<"Clean Text: "<<text<<endl;
	
	map <char, size_t> alphbets{};
	for(const char &letter: text){
		alphbets[letter]++; /*Application of sub-script operator[]*/
	}
	display(alphbets);
	
	footerSection("Histogram");
}

void display(const map <char, size_t> &myMap){
	cout<<setw(10)<<left<<"Letters"<<setw(20)<<right<<"Count"<<endl;
	cout<<setw(30)<<setfill('-')<<""<<endl;
	for(const auto &element: myMap){
		if(element.second == 1){
			cout<<element.first<<":"<<setw(22)<<right<<setfill('.')<<element.second<<" Time"<<endl;
		}
		else{
			cout<<element.first<<":"<<setw(22)<<right<<setfill('.')<<element.second<<" Times"<<endl;
		}
	}
	cout<<setfill(' ');
}

int main(int argc, const char *const argv[]){
    system("cls");
	constexpr char smilee{2};
	alphabeticHistogram();
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};