/**
 * @file SwapTwoColumns2DVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Swap Two Columns In A 2D Vector | C++ Programming Example
 * @version 0.1
 * @date 2023-06-20
 * @since TuesDayDay; 08:53 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
 
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

vector <vector <int>> swapColumn(vector <vector <int>> matrixX, const int &column1, const int &column2){
	
	int columns {static_cast<int> (matrixX.at(0).size())};
	if((column1 >= columns || column1 < 0) || (column2 >= columns || column2 < 0)){
		cerr<<"Operation not possible yet!!!"<<endl;
		exit(0);
	}
	
	int rows{static_cast<int> (matrixX.size())};
	
	
	for(int row{0}; row < rows; row++){
		swap(matrixX.at(row).at(column1), matrixX.at(row).at(column2));
	}
	
	return matrixX;
}

const void display(const vector <vector <int>> matrixX){
	for(const auto &rowMatrix: matrixX){
		for(const int &element: rowMatrix){
			cout<<element<<"\t";
		}
		cout<<endl;
	}
}

int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	vector <vector <int>> matrixX {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};
	cout<<"Before Swap Operation"<<endl;
	display(matrixX);
	
	matrixX = swapColumn(matrixX, 3, 0);
	
	cout<<"After Swap Operation"<<endl;
	display(matrixX);
	
    return 0;
}

