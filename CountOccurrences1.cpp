/**
 * @file CountOccurence1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Count Occurrences Of Each Character In A String | C++ Programming Example
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 06:00 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void countOccurrencesOfEach(const string &line){
	
	const size_t len{line.length()};
	constexpr size_t alphabetSize{26};
	
	vector <size_t> frequencies(alphabetSize);
	
	for(size_t i{0}; i < len; i++){
		int lower{tolower(line.at(i))};
		frequencies[lower - 'a']++;
	}
	char ch{'a'};
	for(unsigned int i{0}; i < alphabetSize; i++){
		
		if(frequencies.at(i) != 0){
			cout<<ch++<<" -> "<<frequencies.at(i);
			cout<<((frequencies.at(i)>1)? " Times." : " Time.")<<endl;
		}
		else{ /*0 Frequency*/
			ch++;
		}		
	}	
	
	return;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const string line {"abcdefghijklmnopabcdefabcabpppp"};
	cout<<"Line: "<<line<<endl;
	
	countOccurrencesOfEach(line);
	
	system("pause>0");
    return 0;
}


