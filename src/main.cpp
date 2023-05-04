#include "Matrix.h"
#include <iostream>


int main(){

Matrix p(4,4);
//p.shape();

p.initMatrix();

//p.shape();
//std::cout << p.transpose() << std::endl;
//std::cout << p << std::endl;
std::cout << p << std::endl;
//std::cout << gaussEli(p) << std::endl;
std::cout << lu(p) << std::endl;
//std::cout <<  (3*p*p).swapRows(0,2).scaleRow(3,2) << std::endl;



return 0;
}

