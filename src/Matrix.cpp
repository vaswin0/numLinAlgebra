#include <iostream>
#include "Matrix.h"
using namespace std;


Matrix::Matrix(int rows, int cols){

	numRows = rows;
	numCols = cols;

	
	A =  new double *[numRows];

	for (int i = 0; i < numCols; i++) {
		
		A[i] = new double [numCols];

	}

	for (int  i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			
			A[i][j] = 5.5;

		}
	}
	
}

Matrix::Matrix(){
	
	numRows = 0;
	numCols = 0;

	A =  NULL;


}

Matrix & Matrix::operator=(const Matrix & obj) {

	








void Matrix::shape(){

std::cout << "[" << numRows << "," << numCols << "]" << "\n";

}


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

Matrix::Matrix( const Matrix & obj){
	
	numCols = obj.numCols;
	numRows = obj.numRows;

	A  = new double *[numRows];

	for(int i = 0; i < numRows ; ++i){
		A[i] =  new double[numCols];

	}

	for(int i = 0; i < numRows; i++){
		
		for(int j = 0; j < numCols;j++){

			
			A[i][j] = obj.A[i][j];
		}

	}

cout << " copy ctor invoked" << endl;
}




Matrix::~Matrix(){
	if (numRows > 0 || numCols > 0){
		for (int i = 0; i < numRows; ++i){
			delete[] A[i];
		}
		delete[] A;
	}

}







Matrix Matrix::transpose(){

	Matrix T(this->numCols, this->numRows);

	T.A[0][0] =  this->A[0][0];

	cout << T.A[0][0];


	for(int i = 0; i < T.numRows; i++) {
		
		for(int j = 0; j <T.numCols; j++) {

			T.A[i][j] = this->A[j][i];

		}

	}

	cout << T;

	return T;
}



	

	






	
