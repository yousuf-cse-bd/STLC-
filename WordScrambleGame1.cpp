/**
 * @file WordScrambleGame1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Word Scramble Game | C++ Programming Example
 * @version 0.1
 * @date 2022-06-07
 * @since WednesDay; 07:20 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

void wordScrambleGame(string &str){
	
	const size_t len{str.length()};
	for(size_t i{0}; i < len; i++){
		str.at(i) = tolower(str.at(i));
	}
	
	if(len == 1) {return;}
	else if(len == 2){
		swap(str.at(0), str.at(1));
		return;
	}

	const string original{str};
	
	double difference{0.0};
	bool sameStart{false};
	bool sameEnd{false};
	
	size_t timeStuck{0};
	
	do{
		
		size_t i{0};
		while(i < len){
			size_t pos1{static_cast <size_t>(rand()) % len};
			size_t pos2{static_cast <size_t>(rand()) % len};
			
			if(pos1 != pos2){
				swap(str.at(pos1), str.at(pos2));
				i++;
			}
		}
		
		size_t diffCount {0};
		for(size_t j{0}; j < len; j++){
			if(original.at(j) != str.at(j)){
				diffCount++;
			}
		}
		
		difference = static_cast<double>(diffCount)/len;
		
		sameStart = str.at(0) == original.at(0); /*True || False*/
		sameEnd = str.at(len - 1) == original.at(len-1); /*True || False*/
		
		timeStuck++;
		
	}while(((sameStart && sameEnd)  && (timeStuck < 100)) || (difference < 0.5)); /*If true->continue*/
}

int main(int argc, const char *const argv[]){
	system("cls");
	srand(time(nullptr));
	
	const string original{"alright"};
	string scrambled{original};
	string answer{};
	
	wordScrambleGame(scrambled);

	bool gameOver{false};
	
	do{
		cout<<"Unscramble the word: "<<scrambled<<endl;
		cout<<"Answer: ";
		cin>>answer;
		
		if(answer == original){
			cout<<"You got it.\n"<<endl;
			gameOver = true;
		}
		else{
			cout<<"Try again...!"<<endl;
		}
	}while(!gameOver);
	
	
	system("pause>0");
	
    return 0;
}
