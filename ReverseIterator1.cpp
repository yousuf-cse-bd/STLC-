/**
 * @file ReverseIterator1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Last element is the frist and frist element is the last
 * @version 0.1
 * @date 2023-03-16
 * @since ThursDay; 05:37 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

 /*
    Works in reverse: ++ moves backword, --moves forword
 */
#include <bits/stdc++.h>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    vector <int> v1{10, 20, 30};
    vector <int> :: reverse_iterator it1 {v1.rbegin()};
    while(it1 != v1.rend()){
        cout<<*it1++<<" ";
    }
    cout<<endl;
    set <char> s1 {'A', 'E', 'I', 'O', 'U'};
    set <char> :: reverse_iterator it2 {s1.rbegin()};
    while(it2 != s1.rend()){
        cout<<*it2++<<" ";
    }
    cout<<"\n\t\tHappyEnding"<<endl;
    return 0;
}