/**
 * @file FunctionTemplate1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Function template, structure and operator overloading (<, <<)
 * @version 0.1
 * @date 2023-03-14
 * @since TuesDay; 05:50 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

template <typename dataType>
dataType minValue(dataType var1, dataType var2){
    return ((var1 < var2)?var1:var2);
}
/*We can value assign within structure*/
struct Person{
    string name{};
    int age{};
    /*Comparing according to age but we can also name*/
    bool operator< (const Person &rhs) const {
        return (this->age) < (rhs.age);
    }
    friend ostream &operator<< (ostream &cout, const Person &person){
        cout<<"[Name: "<<person.name<<", Age: "<<person.age<<"]";
        return cout;
    }
};

template <typename dataType1, typename dataType2>
void showDatas(dataType1 var1, dataType2 var2){
    cout<<var1<<"\t"<<var2<<endl;
}

int main(int argc, const char *const argv[]){
    cout<<minValue(10, 5)<<endl;
    cout<<minValue('a', 'A')<<endl;

    Person p1{"Larry", 50};
    Person p2{"Moe", 30};
    Person p3{minValue(p1, p2)};
    cout<<p3.name<<" is younger."<<endl;

    cout<<"------------------------------------------"<<endl;
    /*This is normal logic may be not efficient*/
    if(p1.age < p2.age){
        cout<<p1.name<<" is younger than "<<p2.name<<endl;
    }
    else{
        cout<<p2.name<<" is younger than "<<p1.name<<endl;
    }
    cout<<"-------------------------------------------"<<endl;
    showDatas(p1, p2);
    return 0;
}