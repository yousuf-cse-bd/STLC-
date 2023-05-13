/**
 * @file DotProduct1.cpp
 * @author: Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Simple vector dot(.) product
 * @version 0.1
 * @date 2023-05-13
 * @since SaturDay; 06:57 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include  <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

ssize_t dotProduct(const vector <int> &v1, const vector <int> &v2){
    const size_t lengthV1 {v1.size()};
    const size_t lengthV2 {v2.size()};

    ssize_t sum {0};
    if(lengthV1 == lengthV2){
        for(size_t i{0}; i < lengthV1; i++){
            sum += v1.at(i) * v2.at(i);
        }
    }

    return sum;
}

int main(int argc, const char *const argv[]){
    system("cls");
    vector <int> v1 {2, 5, 4};
    vector <int> v2 {3, 2, 1};

    cout<<"Dot product: "<<dotProduct(v1, v2)<<endl;

    return 0;
}