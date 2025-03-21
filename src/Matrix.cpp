#include <iostream>
#include "Matrix.h"
#include <cstdlib>
#include <tuple>
#include <ctime>
#include <math.h>

using namespace std;

//custom non-default ctor
Matrix::Matrix(int rows, int cols){

	numRows = rows;
	numCols = cols;

	
	A =  new double *[numRows];

	for (int i = 0; i < numRows; i++) {
		
		A[i] = new double [numCols](); //initialize to zero
						

	}

	/*for (int  i = 0; i < numRows; i++){
		for (int j = 0; j < numCols; j++){
			
			A[i][j] = 0.0;

		}
	}*/
	
}
//custom default ctor
Matrix::Matrix(){
	
	numRows = 0;
	numCols = 0;

	A =  NULL;


}

Matrix::Matrix(const std::vector<std::vector<double>>& mat) {
    // Get the dimensions from the input vector
    numRows = mat.size();
    numCols = mat[0].size();

    // Allocate memory for the 2D array
    A = new double*[numRows];
    for (int i = 0; i < numRows; i++) {
        A[i] = new double[numCols];
        for (int j = 0; j < numCols; j++) {
            A[i][j] = mat[i][j];  // Copy values from the vector
        }
    }
}







double& Matrix::operator()(int i, int j){

	return A[i][j];
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




Matrix Matrix::identity(int n){

	Matrix I(n,n);

	for(int i = 0; i < n; i++){
		

			I.A[i][i] = 1.0;

		}
	return I;

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


void Matrix::initRand(int rows, int cols){

	srand( time(NULL));

	
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			this->A[i][j] = rand();

			}

		}



	}



Matrix randd(int  rows, int cols){

	Matrix random(rows, cols);

	for(int i =  0 ; i< rows; ++i){


		for (int j = 0 ; j < cols; ++j){
			


			random.A[i][j] = rand();
		}
	}


	return random;
}



Matrix ones(int  rows, int cols){

	Matrix one(rows, cols);

	for(int i =  0 ; i< rows; ++i){


		for (int j = 0 ; j < cols; ++j){
			


			one.A[i][j] = 1.;
		}
	}


	return one;
}


Matrix zeros(int  rows, int cols){

	Matrix zero(rows, cols);

	for(int i =  0 ; i< rows; ++i){


		for (int j = 0 ; j < cols; ++j){
			


			zero.A[i][j] = 0;
		}
	}


	return zero;
}




Matrix eye(int  rows, int cols){

	Matrix I(rows, cols);

	for(int i =  0 ; i< rows; ++i){


		for (int j = 0 ; j < cols; ++j){
			


			if(i ==j) I.A[i][j] = 1.;
			else I.A[i][j] = 0;
		}
	}


	return I;
}



















//matrix addition (friend)

Matrix operator+(const Matrix &M, const Matrix &N) {

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

//matrix addition (member fn)


Matrix Matrix::operator+(const Matrix &N) {
    Matrix result(this->numRows, this->numCols);
    for (int i = 0; i < this->numRows; ++i) {
        for (int j = 0; j < this->numCols; ++j) {
            result.A[i][j] = this->A[i][j] + N.A[i][j];
        }
    }
    return result;
}






//matrix subtraction

Matrix operator-(const Matrix &M, const Matrix &N) {

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

Matrix operator*(const Matrix &M, const  Matrix &N) {

	if (M.numCols != N.numRows){
	throw std::invalid_argument("Matrix dimension do not match for multiplication");

	}

	size_t Rows = M.numRows;
	size_t Cols = N.numCols;
	size_t K = M.numCols;
	
	Matrix prod(Rows, Cols);

	for(size_t i = 0; i < Rows; ++i){
		for(size_t k = 0; k < K; ++k) {

			double M_ik = M.A[i][k] ;

			for(size_t j = 0; j < Cols; ++j){

				prod.A[i][j] +=  M_ik*N.A[k][j];
			
			}

		}
	}

	

	return prod;

}



Matrix operator*(const double &c, const Matrix &M){

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



double trace(const Matrix &M){

	int rows =   M.numRows;
	double tr = 0;

	for(int i = 0; i < rows; i++){
		
		tr = tr + M.A[i][i];
		

	}

	return tr;

}

double norm(const Matrix &M){

	int rows = M.numRows;
	int cols = M.numCols;
	double norm = 0;
	for(int i =  0; i < rows; ++i){

		for (int j = 0 ; j < cols; ++j){

			norm += pow(abs(M.A[i][j]),2);
			


		}

	}
	
	return sqrt(norm);



}














Matrix Matrix::swapRows(int m, int n){

	//Matrix swapped(this->numRows, this->numCols);

	//swapped = *this ;

	double temp = 0;

	for ( int j = 0; j < numCols; j++){
		
		

		temp = this->A[m][j];
		this->A[m][j] = this->A[n][j];
		this->A[n][j] =  temp;

		}

	return *this;

	}

			
Matrix Matrix::scaleRow(double k, int m){

	for ( int j = 0; j < this->numCols; j++){

		this->A[m][j] = k*this->A[m][j];

		}

	return *this;


		}



Matrix Matrix::subtractRows(int m, int n, double scalefac){

	for(int j = 0; j < this->numCols; j++){

		this->A[m][j] = this->A[m][j] -  scalefac*this->A[n][j];


	}

	return *this;

	}

		

Matrix Matrix::gaussEli(){

	bool findaswap = false;

	for( int i = 0; i < this->numRows; i++){
	
		if (this->A[i][i] == 0){

			for( int n = i + 1; n < this->numRows; n++){
				if (this->A[n][i] != 0) {
					findaswap = true;
					this->swapRows(i, n);

					break;
					}
				if (findaswap == false){
					cout<< "elimination not possible" << endl;

					return *this;
					}
				}
			}
		

		if(this->A[i][i] != 0) scaleRow((1/this->A[i][i]),i);

		for(int k = i + 1; k < this->numRows; k++){
					
				subtractRows(k, i, this->A[k][i]);
			}
	}
	return *this;
	
	}
			
			

 Matrix gaussEli( Matrix & M){

	bool findaswap = false;

	for( int i = 0; i < M.numRows; i++){
	
		if (M.A[i][i] == 0){

			for( int n = i + 1; n < M.numRows; n++){
				if (M.A[n][i] != 0) {
					findaswap = true;
					M.swapRows(i, n);

					break;
					}
				if (findaswap == false){
					cout<< "elimination not possible" << endl;

					return M;
					}
				}
			}

		for(int k = i + 1; k < M.numRows; k++){
			M.subtractRows(k, i, M.A[k][i]/M.A[i][i]);
			}
	}
	return M;
	}

Matrix Matrix::cholesky(){

	Matrix L = *this;
	int n = this->numRows;

	for(int j = 0; j < n; j++){
		
		L.A[j][j] = sqrt(L.A[j][j]);

		for(int i = j + 1; i < n; i++){
			
			L.A[i][j] = L.A[i][j]/L.A[j][j];
			}
		for( int k = j+1; k < n ; k++){

			for(int i = k; i < k; i++){
				
				L.A[i][k] = L.A[i][k] - L.A[i][j]*L.A[k][j];
			}

		}
	}

	return L;
	
}















/*			
std::tuple<Matrix, Matrix, Matrix, Matrix> lu( Matrix & M){



	int n =  M.numRows;
	Matrix U = M;
	Matrix L = Matrix::identity(n);
	Matrix P = Matrix::identity(n);

	

	for(int j = 0; j < n-1; j++){

		int idx = 0 ;
		double temp ; 

		for( int p = 0; p < n; p++){

			if(abs(U.A[p][j]) > abs(U.A[idx][j])){
				idx = p;}

			}

	if(idx >=j){
		U = partialSwap(U, idx, j, j, n);
		L = partialSwap(L, idx, j, 1, j-1);
		P = partialSwap(P, idx, j, 0, n);

		}


	for(int i = j+1; i < n; i++){
		L.A[i][j] =  U.A[i][j]/U.A[j][j];

		for(int k = j; k < n; k++){

			U.A[i][k] = U.A[i][k] - L.A[i][j]*U.A[j][k];

			}

		}

	}
	std::tuple <Matrix, Matrix,Matrix, Matrix> matrices(P, L, U, P*L*U);
	return matrices;


	}
*/
