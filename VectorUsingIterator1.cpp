/**
 * @file VectorUsingIterator1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Simple example for iterator with vector travarsing
 * @version 0.1
 * @date 2023-03-16
 * @since ThursDay; 09:11 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){
    vector <int> v1{10, 20, 30};
    vector <int> :: iterator it1{v1.begin()};

    while(it1 != v1.end()){
        cout<<*it1<<" ";
        it1++;
    }
    cout<<"\n---------------------"<<endl;
    /*We can declare an iterator using auto key-word*/
    auto it2{v1.begin()};
    while(it2 != v1.end()){
        cout<<*it2<<" ";
        ++it2;
    }
    return 0;
}