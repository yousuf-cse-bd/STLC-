/**
 * @file FindCustomTyped1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Algorithm- find() method with custom typed and (<, ==) overloading
 * @version 0.1
 * @date 2023-03-18
 * @since SaturDay; 09:36 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <algorithm>
#pragma pack(1)
using namespace std;

/**
 * Algorithm- find() with user-defind types
 * Find need to be able to compare objct
 * operator == is used and must be provided by your class
 */
 
struct Player{
    string types{};
    int scores{};
    int position{};

    friend ostream &operator<< (ostream &cout, const Player &player){
        cout<<"["<<player.types<<", "<<player.scores<<", "<<player.position<<"]";
        return cout;
    }
    bool operator < (const Player &rhs) const {
        return (this->position < rhs.position);
    }
    /*Equal (==) operator overloading*/
    bool operator ==(const Player &rhs) const {
        return (this->types == rhs.types && this->scores == rhs.scores && 
        this->position == rhs.position);
    }
};

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	
	vector <Player> team{}; /*Assume initialized*/
	Player p1{"Hero", 100, 12};
	Player p2{"Villain", 80, 11};
	team.push_back(p1);
	team.push_back(p2);
	
	auto location {find(team.cbegin(), team.cend(), p1)};
	if(location != team.cend()){
		cout<<"Found: "<<*location<<endl;
	}
	else{
		cout<<"Not Found...!"<<endl;
	}
	cout<<"\t\t\tHappyEnding!!!"<<endl;
	
    return 0;
}