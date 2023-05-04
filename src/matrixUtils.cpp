#include "Matrix.h"

Matrix partialSwap(Matrix & M, int i, int j, int fromCol, int toCol){
	
	double temp;

	for(int k = fromCol; k < toCol; k++){
		
		temp = M.A[i][k];
		M.A[i][k] = M.A[j][k];
		M.A[j][k] = temp;

		}
	return M;
	}
	

