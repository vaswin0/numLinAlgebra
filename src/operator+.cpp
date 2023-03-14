#include "Matrix.h"

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
