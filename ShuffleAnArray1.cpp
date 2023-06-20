/**
 * @file ShuffleAnArray1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Cards shuffle using random number & swap | C++ Programming Example
 * @version 0.1
 * @date 2023-06-20
 * @since TuesDayDay; 10:43 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <vector>
#include <ctime>
#pragma pack(1)
using namespace std;

void suffleVector(vector <int> &card, const int &deckSize = 52){ /*Default parameter*/

	srand(time(nullptr));
	for(int i{0}; i < deckSize; i++){
		swap(card.at(i), card.at(rand()%deckSize));
	}
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const int deckSize{52};
	
	vector <int> cards(deckSize);
	
	for(size_t i{0}; i < deckSize; i++){
		cards.at(i) = i+1;
	}
	
	
	suffleVector(cards, deckSize);
	
	for(int i{0}; i < deckSize; i++){
		cout<<"["<<(i+1)<<"] = "<<cards.at(i)<<endl;
	}
	
	system("pause>0");
    return 0;
}

