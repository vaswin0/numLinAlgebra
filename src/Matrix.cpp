#include <iostream>
#include "Matrix.h"
using namespace std;


Matrix::Matrix(int rows, int cols){

	numRows = rows;
	numCols = cols;

	//double **
	A =  new double *[numRows];

	for (int i = 0; i < numCols; i++) {
		
		A[i] = new double [numCols];

	}

	for (int  i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			
			A[i][j] = 5.5;

		}
	}
	//mtrx = A;
}
/*
void Matrix::shape(){

std::cout << "[" << numRows << "," << numCols << "]" << "\n";

}
*/

std::ostream& operator<<(std::ostream& os, const Matrix & m) {

	for(int i = 0; i< m.numRows; ++i){
		
		for(int j = 0; j < m.numCols; ++j){
			
			os << " " << m.A[i][j] ;
		}
	
		os << "\n";	

	}

	os << "\n";

	return os;


}



Matrix::~Matrix(){
	if (numRows > 0 || numCols > 0){
		for (int i = 0; i < numRows; ++i){
			delete[] A[i];
		}
		delete[] A;
	}

}








