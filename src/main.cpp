#include "Matrix.h"
#include <iostream>

int main(){

Matrix p(4,4);

Matrix P ;
P =  p.transpose();

std::cout << P;





return 0;
}

