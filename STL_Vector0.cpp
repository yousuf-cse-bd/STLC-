/**
 * @file STL_Vector0.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Accessing a vector through loop
 * @version 0.1
 * @date 2023-03-12
 * @since SunDay; 10:56 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
	constexpr size_t limit{10};
	vector <char> alphabet(limit); /*Create vector of lenght 26*/
	cout<<"Size: "<<alphabet.size()<<endl; 
	for(size_t i{0}; i < limit; i++){
		alphabet.at(i) = i + 'a';
	}
	
	cout<<"Original Contents: ";
	for(size_t i{0}; i < alphabet.size(); i++){
		cout<<alphabet[i]<<" "; /*Vector is like array sub-scripting notation*/
	}
	cout<<endl;
	for(size_t i{alphabet.size()}; i < 26; i++){
		alphabet.push_back(i + 'a');
	}
	cout<<"Expanding vector & now Size: "<<alphabet.size()<<endl;
	cout<<"Current Contents: ";
	for(const auto &letter: alphabet){
		cout<<letter<<" ";
	}
	cout<<endl;
	
	for(auto &letter: alphabet){
		letter = toupper(letter);
	}
	cout<<"Modified Contents: ";
	for(const auto &letter: alphabet){
		cout<<letter<<" ";
	}

	cout<<"\n\t\t\tHapyEnding!!!"<<endl;
	return 0;
}
