/**
 * @file NextPermutation1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Three numbers permutation | C++ Programming Example
 * @version 0.1
 * @date 2022-06-09
 * @since Friday; 06:15 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <algorithm>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){

    string number{"123"};
    while(next_permutation(number.begin(), number.end())){
        cout<<number<<endl;
    }
    return 0;
}