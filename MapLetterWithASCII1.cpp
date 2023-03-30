/**
 * @file MapLetterWithASCII1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief A simple STL map demostraction
 * @version 0.1
 * @date 2023-03-30
 * @since ThursDay; 05:14 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#pragma pack(1)
using namespace std;

template <typename var1, typename var2>
void display(const map <var1, var2> &myMap){
	cout<<setw(15)<<left<<"Letters"<<setw(15)<<right<<"ASCII Codes"<<endl;
	cout<<setw(30)<<setfill('-')<<""<<endl;
	for(const auto &pairs: myMap){
		cout<<setw(15)<<left<<setfill('.')<<pairs.first<<setw(15)<<right<<pairs.second<<endl;
	}
	cout<<setfill(' ');
}

int main(int argc, const char *const argv[]){
    system("cls");
	
	map <char, int> upperCaseLetters{};
	for(char letter{'A'}; letter <= 'Z'; letter++){
		upperCaseLetters.insert(pair <char, int>(letter, toascii(letter)));
	}
	
	display(upperCaseLetters);
	cout<<endl;
	
	map <char, int> lowerCaseLetter{};
	for(int i{0}; i < 26; i++){ /*static_cast<char> optional here*/
		lowerCaseLetter.insert(make_pair(static_cast<char>('a'+i), (i+toascii('a'))));
	}
	display(lowerCaseLetter);
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};