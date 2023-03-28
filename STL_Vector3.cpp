/**
 * @file STL_Vector3.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Converting from Fahrenheit to Centigrade Scale
 * @version 0.1
 * @date 2023-03-28
 * @since TuesDay; 10:24 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 #include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#pragma pack(1)
using namespace std;

class Interface{
	friend ostream &operator<< (ostream &cout, const Interface &interface){
		interface.print(cout);
		return cout;
	}
public:
	Interface(void) = default;
	virtual void print(ostream &cout) const = 0;
	virtual ~Interface(void) = default;
};

class DailyTemps : public Interface{
	virtual void print(ostream &cout) const override {
		cout<<fahrenheitTemp;
	}
private:
	double fahrenheitTemp{};
	
	constexpr static const double defFahrenheitTemp{0.00};
public:
	DailyTemps(const double &fahrenheitTemp = defFahrenheitTemp)
		:fahrenheitTemp{fahrenheitTemp}{}
	DailyTemps operator= (const double &x){
		return (this->fahrenheitTemp = x);
	}
	
	bool operator< (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp < rhs.fahrenheitTemp);
	}
	
	bool operator> (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp > rhs.fahrenheitTemp);
	}
	
	bool operator<= (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp <= rhs.fahrenheitTemp);
	}
	
	bool operator>= (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp >= rhs.fahrenheitTemp);
	}
	
	bool operator== (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp == rhs.fahrenheitTemp);
	}
	
	bool operator!= (const DailyTemps &rhs) const {
		return (this->fahrenheitTemp != rhs.fahrenheitTemp);
	}
	double getFahrenheitTemp(void) const {
		return fahrenheitTemp;
	}
	~DailyTemps(void) = default;
};
template <typename var>
void display(const vector <var> &v){
	cout<<"[ ";
	for_each(v.cbegin(), v.cend(), 
		[](const var &x){
			cout<<x<<" ";
		}
	);
	cout<<"]"<<endl;
}
int main(int argc, const char *const argv[]){
	system("cls");
	cout<<setprecision(2)<<fixed;
	
	constexpr const size_t weekDays{7};
	
	vector <DailyTemps> fahrenheits{};
	for(size_t i{0}; i < weekDays; i++){
		DailyTemps temp{60.0 + rand()%30};
		fahrenheits.emplace_back(temp);
	}
	fahrenheits.shrink_to_fit();
	cout<<"Fahrenheit temperatures: ";
	display(fahrenheits);
	cout<<endl;
	
	/*Converting from Fahrenheit to Centigrade Scale*/
	vector <DailyTemps> centigrades(weekDays);
	for(size_t i{0}; i < weekDays; i++){
		centigrades.at(i) = (fahrenheits.at(i).getFahrenheitTemp()-32)*5/9;
	}
	
	cout<<"Centigrades temperatures: ";
	display(centigrades);
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<":HappyEnding...!"<<endl;
	system("pause>0");
	return 0;
}
