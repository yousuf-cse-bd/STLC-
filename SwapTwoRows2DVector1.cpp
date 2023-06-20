/**
 * @file SwapTwoRows2DVector1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Swap Two Rows In A 2D Array | C++ Programming Example
 * @version 0.1
 * @date 2023-06-20
 * @since TuesDayDay; 10:15 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

 
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

vector <vector <int>> swapRows(vector <vector <int>> matrixX, const int &row1, const int &row2){
	int rows {static_cast<int> (matrixX.size())};
	if((row1 >= rows || row1 < 0) || (row2 >= rows || row2 < 0)){
		cerr<<"Operation not possible yet!!!"<<endl;
		exit(0);
	}
	
	int colums{static_cast<int> (matrixX.at(0).size())};
	for(int column{0}; column < colums; column++){
		swap(matrixX.at(row1).at(column), matrixX.at(row2).at(column));
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
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4},
		{5, 5, 5, 5}
	};
	cout<<"Before Swap"<<endl;
	display(matrixX);
	
	matrixX = swapRows(matrixX, 0, 4);
	
	cout<<"After Swap"<<endl;
	display(matrixX);
	
    return 0;
}

