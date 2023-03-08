#include <iostream>
#include "Matrix.h"
using namespace std;


Matrix::Matrix(int rows, int cols){

	numRows = rows;
	numCols = cols;

	double **A =  new double *[numRows];

	for (int i = 0; i < numCols; i++) {
		
		A[i] = new double [numCols];

	}

	for (int  i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			
			A[i][j] = 0.0;

		}
	}

}

void Matrix::shape(){

std::cout << "[" << numRows << "," << numCols << "]" << "\n";

}
