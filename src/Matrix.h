#pragma once
#include<iostream>
#include<tuple>
#include<vector>



class Matrix{
	protected:
		double **A;
		int numRows, numCols;
		
	public:
		Matrix();
		Matrix(int rows, int cols);
		Matrix(const std::vector<std::vector<double>>& mat); //from vector of vector
		Matrix(const Matrix & obj); // custom copy ctor
		Matrix & operator= (const Matrix & obj);
		void initMatrix();
		

		void initRand(int , int);


		friend Matrix randd(int, int);
		friend Matrix eye (int, int);
		friend Matrix ones(int, int);
		friend Matrix  zeros(int, int);
		
		
		
		void shape();
		Matrix transpose();

		~Matrix();
		
		double& operator()(int i, int j);
   		
		friend std::ostream& operator<<(std::ostream & os, const  Matrix & m);
	    friend Matrix operator+( const Matrix &M, const Matrix & N);
   		Matrix operator+( const Matrix & N);
		friend Matrix operator-(const Matrix &M, const Matrix &N);
		friend Matrix  operator*(const Matrix &M, const Matrix &N);
	
		friend Matrix operator*(const double & c, const Matrix &M);
		
		friend double trace(const Matrix &M);
		friend double norm(const Matrix &M);

		Matrix swapRows( int m, int n);
		Matrix scaleRow(double k, int m);
		Matrix subtractRows(int m, int n, double scalefac);

		Matrix gaussEli() ;
		Matrix cholesky();

		friend Matrix gaussEli( Matrix & M);
		friend std::tuple<Matrix, Matrix, Matrix, Matrix> lu(Matrix & M);
		friend std::tuple<Matrix, Matrix, Matrix> luCrout(Matrix & M);
		friend Matrix cholesky(Matrix & M);
		static Matrix identity(int n);

		friend Matrix partialSwap(Matrix & M, int, int, int, int);

		friend void qrdecomp(Matrix A, Matrix & Q, Matrix &R);
};



		Matrix randd(int, int);
		Matrix eye (int, int);
		Matrix ones(int, int);
		Matrix  zeros(int, int);
//		std::ostream& operator<<(std::ostream& os, const Matrix& m);
	
