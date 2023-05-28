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





std::tuple< Matrix, Matrix, Matrix> luCrout( Matrix & M){

	int N = M.numRows;
	Matrix U(N,N); //beta
	Matrix L = Matrix::identity(N); //alpha

	for(int j = 0; j < N; j++){
		
		for(int i  = 0; i < N; i++) {

			if(i <= j) {

				float sum  = 0;
				
				for(int k = 0; k <= i-1; k++){
					
					sum += L.A[i][k]*U.A[k][j];
					}

				U.A[i][j] = M.A[i][j] - sum;

				}

			if(i >j){
				float sum = 0;
				
				for(int k = 0; k <= j -1; k++){
					
					sum += L.A[i][k]*U.A[k][j];
					}



				L.A[i][j] = (M.A[i][j] - sum)/U.A[j][j];

				}


			}

		}


	std::tuple < Matrix,Matrix, Matrix> matrices( L, U,L*U);

	return matrices;

	}


					
					


























	



	
