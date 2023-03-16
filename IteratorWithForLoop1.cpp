/**
 * @file IteratorWithForLoop1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief STL iterator using for loop and auto typed
 * @version 0.1
 * @date 2023-03-16
 * @since ThursDay; 05:27 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <set>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    vector <int> v1{10, 20, 30};
    for(auto it{v1.begin()}; it != v1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    set <char> s1 {'A', 'E', 'I', 'O', 'U'};

    for(auto it{s1.begin()}; it != s1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n\t\tHappyEnding"<<endl;
    return 0;
}