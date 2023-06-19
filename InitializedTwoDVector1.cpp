/**
 * @file InitializedTwoDVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief This creates a 2D vector vec with 3 rows and 3 columns, where all elements are initialized to -1.
 * @version 0.1
 * @date 2023-06-19
 * @since MonDayDay; 10:15 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

int main(int argc, const char *const argv[]){

    const int rows{3};
    const int columns{3};
    
    vector <vector <int>> twoDimentionalVetor(rows, vector <int>(columns, -1));

    /*Must using auto keyword*/
    for(const auto &outerVector: twoDimentionalVetor){
        for(const int &innerElement: outerVector){
            cout<<innerElement<<" ";
        }
        cout<<endl;
    }

    return 0;
}