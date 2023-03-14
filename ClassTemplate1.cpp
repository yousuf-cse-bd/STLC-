/**
 * @file ClassTemplate1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Class template <int>, <double>, <string>, <class>, vector
 * @version 0.1
 * @date 2023-03-14
 * @since TuesDay; 08:00 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#include <memory>
#pragma pack(1)
using namespace std;

template <typename dataType>
class Item{
	friend void operator<<(ostream &cout, const Item &item){
		cout<<"[Name: "<<item.name<<", Value: "<<item.value<<"]\n";
	}
private:
    string name{};
    dataType value{};
public:
    Item(void):Item{"None", 0}{
		
	}
    Item(const string_view &name, const dataType &value):name{name}, value{value}{
        
    }
	
	string getName(void) const{
		return name;
	}
	dataType getValue(void) const {
		return value;
	}
	~Item(void) = default;
};

int main(int argc, const char *const argv[]){
	cout<<fixed;
	cout.precision(2);
	/*Don't print (item0) object, using class member methods*/
	Item <Item<string>> item0{"Frank", {"C++", "Professor"}};
	cout<<"GetName: "<<item0.getName()<<endl;
	cout<<"GetValue: "<<item0.getValue().getName()<<" "
		<<item0.getValue().getValue()<<endl;
	Item <int> item1{"Larry", 1};
	cout<<item1;
	Item <double> item2 {"House", 1000.00};
	cout<<item2;
	Item <string> item3{"Yousuf", "Boss"};
	cout<<item3;
	
	Item <string> *ptrItem = new Item<string>{"PointerItem", "HEAP"};
	if(ptrItem){
		cout<<*ptrItem;
	}
	else{
		cout<<"The memory allocation is NOT done.!!!"<<endl;
	}
	delete ptrItem;
	ptrItem = nullptr;
	unique_ptr <Item<int>> unPtr = make_unique<Item<int>>("UniquePointer", 101);
	cout<<*unPtr;
	shared_ptr <Item<int>> shPtr = make_shared<Item<int>>("SharedPointer", 101);
	cout<<*shPtr;
	cout<<"-----------------------------------------------------------------"<<endl;
	vector <Item<int>> vectorItems{};
	vectorItems.push_back(Item{"Item0", 0});
	vectorItems.push_back(Item{"Item1", 1});
	vectorItems.push_back(Item{"Item2", 2});
	vectorItems.push_back(Item{"Item3", 3});
	vectorItems.push_back(Item{"Item4", 4});
	for(const auto &item: vectorItems){
		cout<<item;
	}
	cout<<"-----------------------------------------------------------------"<<endl;
    return 0;
}


