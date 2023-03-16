#include <iostream>
#include "Matrix.h"
using namespace std;

//custom non-default ctor
Matrix::Matrix(int rows, int cols){

	numRows = rows;
	numCols = cols;

	
	A =  new double *[numRows];

	for (int i = 0; i < numRows; i++) {
		
		A[i] = new double [numCols];

	}

	for (int  i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			
			A[i][j] = 5.5;

		}
	}
	
}
//custom default ctor
Matrix::Matrix(){
	
	numRows = 0;
	numCols = 0;

	A =  NULL;


}
//copy assignment
Matrix & Matrix::operator=(const Matrix & obj) {

	if ( this == & obj) return *this;

	else {
	
		delete [] A;
		A = new double *[obj.numRows];
		numCols = obj.numCols;
		numRows =  obj.numRows;

		A = new double *[numRows];


		for(int i = 0; i < numRows ; ++i){
			A[i] =  new double[numCols];

		}

		for(int i = 0; i < numRows; i++){
		
			for(int j = 0; j < numCols;j++){

			
				A[i][j] = obj.A[i][j];
			}

		}

	}
	return *this;
}
	


//overloaded <<

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
//custom copy constructor
Matrix::Matrix( const Matrix & obj){
	
	numCols = obj.numCols;
	numRows = obj.numRows;

	A  = new double *[numRows];

	//A(new double *[numRows])

	for(int i = 0; i < numRows ; ++i){
		A[i] =  new double[numCols];

	}

	for(int i = 0; i < numRows; i++){
		
		for(int j = 0; j < numCols;j++){

			
			A[i][j] = obj.A[i][j];
		}

	}

//cout << " copy ctor invoked" << endl;
}



//custom destructor
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

	


	for(int i = 0; i < T.numRows; i++) {
		
		for(int j = 0; j <T.numCols; j++) {

			T.A[i][j] = this->A[j][i];

		}

	}
	

	return T;
}

void Matrix::shape(){

std::cout << "[" << numRows << "," << numCols << "]" << "\n";

}



void Matrix::initMatrix(){

cout << "input the matrix elements" << endl;	

	for(int i = 0; i < this->numRows; i++){
		for( int j = 0; j < this->numCols; j++){

			cin >> this->A[i][j];

		}
	}

}

//matrix addition

Matrix operator+(Matrix &M, Matrix &N) {

	int rows = M.numRows;
	int cols = M.numCols;
	
	Matrix sum(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++) {

			sum.A[i][j] = M.A[i][j] + N.A[i][j];

		}
	}

	

	return sum;

}



//matrix subtraction

Matrix operator-(Matrix &M, Matrix &N) {

	int rows = M.numRows;
	int cols = M.numCols;
	
	Matrix diff(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++) {

			diff.A[i][j] = M.A[i][j] - N.A[i][j];

		}
	}

	

	return diff;

}


//matrix multiplication

Matrix operator*(Matrix &M, Matrix &N) {

	int Rows = M.numRows;
	int Cols = N.numCols;
	
	Matrix prod(Rows, Cols);

	for(int i = 0; i < Rows; i++){
		for(int j = 0; j < Cols; j++) {

			float sumprod = 0;

			for(int k = 0; k < M.numCols; k++){

				sumprod =  sumprod + M.A[i][k]*N.A[k][j];
			}

			prod.A[i][j] = sumprod;

		}
	}

	

	return prod;

}


Matrix operator*(const double &c, Matrix &M){

	int rows = M.numRows;
	int cols = M.numCols;
	
	Matrix prod(rows, cols);
	
	for(int i = 0; i < rows; i++){
		for( int j = 0; j < cols; j++){
			
				prod.A[i][j] =  c*M.A[i][j];

		}

	}


	return prod;
}






	



























	
	

	






	
