#include <iostream>
#include <algorithm>
#pragma pack(1)
using namespace std;

int sumOfPermutation(string &number){
   int sum {stoi(number)};
    while(next_permutation(number.begin(), number.end())){
        sum += stoi(number); /*String to integer*/
    }
    return sum;
}

int main(){
    string number {"123"};
    
    cout<<sumOfPermutation(number)<<endl;

    return 0;
}