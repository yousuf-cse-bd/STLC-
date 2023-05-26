/**
 * @file IsAnagramFrequency.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check words ANAGRAM using letter frequency technique
 * @version 0.1
 * @date 2022-05-26
 * @since FriDay; 07:48 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool isAnagram(string word1, string word2){
	
	const size_t len1{word1.length()};
	const size_t len2{word2.length()};
	
	if(len1 == len2){
		
		const unsigned int alphabetNumber{26};
		vector <unsigned int> frequencyWord1(alphabetNumber);
		vector <unsigned int> frequencyWord2(alphabetNumber);
		
		for(unsigned int i{0}; i < len1; i++){
			int lower {tolower(word1.at(i))};
			frequencyWord1[lower - 'a']++;
			
			lower = tolower(word2.at(i));
			frequencyWord2[lower - 'a']++;
		}
		
		for(unsigned int i{0}; i < alphabetNumber; i++){

			if(frequencyWord1.at(i) != frequencyWord2.at(i)){
				return false;
			}
		}
		return true;
	}
	return false;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
    
	string word1 {"Listen"};
	string word2 {"Silent"};
	
	cout<<boolalpha;
	cout<<word1<<" and "<<word2<<" are ANAGRAM: "<<isAnagram(word1, word2)<<endl;
	
	system("pause>0");
    return 0;
}


