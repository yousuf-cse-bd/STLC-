/**
 * @file StandardDeviation1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Compute Standard Deviation | C++ Programming Example
 * @version 0.1
 * @date 2022-05-25
 * @since ThursDay; 06:16 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// sigma = sqrt[{(sum(Xi) - mean}^2/N]
// totat += Xi

double totalAdd(const vector <double> &v){
	double total{0.0};
	for(const double &data: v){
		total += data;
	}
	return total;
}

double stdDeviation(const vector <double> &v, const size_t &N){
	
	double total{totalAdd(v)};
	double mean{total / N};
	double sum {0.0};
	
	for(size_t i{0}; i < N; i++){
		sum += pow((v.at(i) - mean), 2);
	}
		
	return sqrt(sum/N);
}

const void display(const vector <double> &v){
	for(const double &data: v){
		cout<<data<<" ";
	}
	cout<<endl;
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
//	cout<<setprecision(1)<<fixed;
    
	vector <double> population{9.2, 1.5, 6.7, 8.2, 5.5, 7.1};
	cout<<"Population Datas: ";
	display(population);
	
	cout<<"Standard Deviation: "<<stdDeviation(population, population.size())<<endl;
	system("pause>0");
    return 0;
}


