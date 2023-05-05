#include "Matrix.h"

std::tuple<Matrix, Matrix, Matrix, Matrix> lu( Matrix & M){



	int n =  M.numRows;
	Matrix U = M;
	Matrix L = Matrix::identity(n);
	Matrix P = Matrix::identity(n);

	

	for(int j = 0; j < n-1; j++){

		int idx = 0 ;
		 

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






