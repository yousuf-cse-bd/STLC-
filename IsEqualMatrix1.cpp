/**
 * @file IsEqualMatrix1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief How To Check For Matrix Equality | C++ Programming Example
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

const void display(const vector<vector<int>> &matrixA, const char *const lebel);

bool isEqualMatrixs(const vector <vector<int>> &matrixA, const vector <vector<int>> &matrixB){
	
	int rowA{static_cast<int> (matrixA.size())};
	int columnA{static_cast<int> (matrixA.at(0).size())};
	
	int rowB{static_cast<int> (matrixB.size())};
	int columnB{static_cast<int> (matrixB.at(0).size())};
	
	if(rowA == rowB && columnA == columnB){
		for(int i{0}; i < rowA; i++){
			for(int j{0}; j < columnA; j++){
				if(matrixA.at(i).at(j) != matrixB.at(i).at(j)){
					return false;
				}
			}
		}
		
		return true;
	}
	
	return false;
}


int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	const int row{3};
	const int column{3};

	vector <vector <int>> matrixA {/*2D vector*/};
		
	/*2D vector: initialized by zero by default*/
	vector <vector <int>> matrixB (row, vector<int>(column)); 
	
	
	cout<<"Load element for matrix A:"<<endl;
	for(int i{0}; i < row; i++){
		vector <int> temp{};
		for(int j{}; j < column; j++){
			cout<<"Enter ["<<i<<", "<<j<<"]: ";
			int element{};
			cin>>element;
			temp.emplace_back(element);
			temp.shrink_to_fit();
		}
		matrixA.emplace_back(temp);
		matrixA.shrink_to_fit();
		temp.clear();
	}
	display(matrixA, "MatrixA");
	cout<<"---------------------------------------------"<<endl;
	cout<<"Load element for matrix B:"<<endl;
	for(size_t i{0}; i < row; i++){
		for(size_t j{0}; j < column; j++){
			cout<<"Enter ["<<i<<", "<<j<<"]: ";
			cin>>matrixB.at(i).at(j);
		}
	}
	
	display(matrixB, "MatrixB");
	cout<<"---------------------------------------------"<<endl;
	if(isEqualMatrixs(matrixA, matrixB)){
		cout<<"\tBoth matrix are equal..."<<endl;
	}
	else{
		cout<<"\tBoth matrix are NOT equal!!!"<<endl;
	}
	cout<<endl;
	display(matrixA, "MatrixA");
	display(matrixB, "MatrixB");
	
    return 0;
}

const void display(const vector<vector<int>> &matrixA, const char *const lebel){
	cout<<lebel<<": "<<endl;
	for(const auto &outer: matrixA){
		for(const int &inner: outer){
			cout<<inner<<" ";
		}
		cout<<endl;
	}
}
