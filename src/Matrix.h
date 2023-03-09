#pragma once

#include<iostream>






class Matrix{

	protected:

		double **A;
		int numRows, numCols;
		
	public:
		Matrix(int rows, int cols);
		
		
		//void transpose();

		~Matrix();
   		
		friend std::ostream& operator<<(std::ostream & os, const  Matrix & m);

};


		
