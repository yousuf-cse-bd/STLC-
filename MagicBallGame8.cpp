/**
 * @file MagicBallGame8.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Magic 8-Ball Game| C++ Programming Example
 * @version 0.1
 * @date 2022-06-09
 * @since Friday; 06:15 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

string magicBallGame8(const string &question){
	srand(time(nullptr));
		
	const vector <string> answers{
		"It is a certain.",
		"It is a decidedly so.",
		"Without a doubt.",
		"Yes definitely.",
		"You may rely on it.",
		"As I see it, yes.",
		"Most likely.",
		"Outlook good.",
		"Yes.",
		"Signs point to yes.",
		"Reply hazy, try again.",
		"Ask again later",
		"Better not tell you now.",
		"Can not predict now.",
		"Concentrate and ask again.",
		"Don't count on it.",
		"My reply is no.",
		"My sources say no.",
		"Outlook not so good.",
		"Very doubtful."
	};
	
	size_t total{0};
	for(const char &x: question){
		total += x;
	}
	
	const size_t size{answers.size()};
	const size_t rotation{rand() % size};
	size_t answerIndex{(total + rotation) % size};
	
	return "\n\tMagic 8-Ball Says: "+answers.at(answerIndex);
}

int main(int argc, const char *const argv[]){
	system("cls");
	
	string question{};
	do{
		cout<<"***** Ask Magic 8-Ball *****\n"<<endl;
		cout<<"Enter [exit] to quit.!"<<endl;
		cout<<"Question?: ";
		
		getline(cin, question);
		
		if(question == "exit"){
			break;
		}
		
		cout<<magicBallGame8(question)<<endl;
		
	}while(true);

	system("pause>0");
    return 0;
}
