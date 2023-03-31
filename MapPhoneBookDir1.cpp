/**
 * @file MapPhoneBookDir1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Use a map to create phonebook directory
 * @version 0.1
 * @date 2023-03-31
 * @since FriDay; 10:46 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>
#pragma pack(1)
using namespace std;

class Interface{
private:
	friend ostream &operator << (ostream &cout, const Interface &interface){
		interface.print(cout);
		return cout;
	}
	virtual void print(ostream &cout) const = 0;
public:
	Interface(void) = default;
	virtual ~Interface(void) = default;
};

class Name : public Interface{
private:
	virtual void print(ostream &cout) const override{
		cout<<name;
	}
	string name{};
	constexpr static const char *const defName{"No Name"};
public:
	Name(const string_view &name = defName):name{name}{}
	string getName(void) const {
		return name;
	}
	
	bool operator < (const Name &rhs) const {
		return (this->name < rhs.name);
	}
	bool operator > (const Name &rhs) const {
		return (this->name > rhs.name);
	}
	
	bool operator <= (const Name &rhs) const {
		return (this->name <= rhs.name);
	}
	bool operator >= (const Name &rhs) const {
		return (this->name >= rhs.name);
	}
	
	bool operator == (const Name &rhs) const {
		return (this->name == rhs.name);
	}
	bool operator != (const Name &rhs) const {
		return (this->name != rhs.name);
	}
	
	virtual ~Name(void) = default;
};

class PhoneNumber : public Interface{
private:
	string number{};
	constexpr static const char *const defNumber{"No Number"};
	
	virtual void print(ostream &cout) const override {
		cout<<number;
	}
public:
	PhoneNumber(const string_view &number = defNumber):number{number}{}
	string getNumber(void) const {
		return number;
	}
	
	bool operator < (const PhoneNumber &rhs) const {
		return (this->number < rhs.number);
	}
	bool operator > (const PhoneNumber &rhs) const {
		return (this->number > rhs.number);
	}
	
	bool operator <= (const PhoneNumber &rhs) const {
		return (this->number <= rhs.number);
	}
	bool operator >= (const PhoneNumber &rhs) const {
		return (this->number >= rhs.number);
	}
	
	bool operator == (const PhoneNumber &rhs) const {
		return (this->number == rhs.number);
	}
	bool operator != (const PhoneNumber &rhs) const {
		return (this->number != rhs.number);
	}
	
	virtual ~PhoneNumber(void) = default;
};

void display(const map <Name, PhoneNumber> &myMap){
	for_each(myMap.cbegin(), myMap.cend(),
		[](const auto &pairs){
			cout<<"[ "<<pairs.first<<" : "<<pairs.second<<" ]"<<endl;
		}
	);
}


int main(int argc, const char *const argv[]){
    system("cls");
	
	map <Name, PhoneNumber> directory{};
	/*Put name & number into map*/
	
	directory.insert(pair<Name, PhoneNumber>("Sumon", "123"));
	directory.insert(pair<Name, PhoneNumber>("Yousuf", "121"));
	directory.insert(pair<Name, PhoneNumber>("Ali", "555"));
	directory.insert(pair<Name, PhoneNumber>("Tameem", "888"));
	directory.insert(pair<Name, PhoneNumber>("Maruf", "0154"));
	directory.insert(pair<Name, PhoneNumber>("Imtiaz", "4784"));
	directory.insert(pair<Name, PhoneNumber>("Istiak", "000"));
	
	display(directory);
	map <Name, PhoneNumber> :: iterator it {};
	
	string name{};
	string number{};
	char option{};
	do{
		cout<<"I - insert()"<<endl;
		cout<<"S - search()"<<endl;
		cout<<"D - Display"<<endl;
		cout<<"R - Remove()"<<endl;
		cout<<"A - AllDelete()"<<endl;
        cout<<"C - ClearConsole()"<<endl;
		cout<<setw(30)<<setfill('-')<<""<<endl;
	
		cout<<"Select your option?: ";
		cin>>option;
		option = toupper(option);
		
		switch(option){
			case 'I': {
				cin.clear();
				cin.ignore();
				cout<<"Enter a name here: ";
				getline(cin, name);
				cout<<"Enter a number here: ";
				cin>>number;
				directory.insert(make_pair(name, number));
				break;
			}
			case 'S':{
				cin.clear();
				cin.ignore();
				cout<<"Enter a name here: ";
				getline(cin, name);	
				
				it = directory.find(Name{name});
				if(it != directory.cend()){
				cout<<it->first<<":"<<it->second<<endl;
				}
				else{
					cout<<name<<" is NOT found..!"<<endl;
				}
				break;
			}
			
			case 'D':{
				display(directory);
				break;
			}
			
			case 'R':{
				cin.clear();
				cin.ignore();
				cout<<"Enter a name here: ";
				getline(cin, name);
				it = directory.find(Name{name});
				if(it != directory.cend()){
					directory.erase(it);
					cout<<"Removed: "<<it->first<<":"<<it->second<<endl;
				}
				else{
					cout<<name<<" is NOT found!!!"<<endl;
				}
				break;
			}
			case 'A': {
                if(!directory.empty()){
                    directory.clear();
                }
                cout<<"Your directory is empty now..!"<<endl;			
				break;
			}
			case 'Q': break;
            case 'C': system("cls"); break;
			default:cout<<"Select the right option..."<<endl;
		}
	}while(option != 'Q');

	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};