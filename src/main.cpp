#include "Matrix.h"
#include <iostream>

int main(){

Matrix p(4,4);

Matrix pt ;


p.initMatrix();


std::cout << p << std::endl;

pt =  p.transpose();

std::cout << pt << std::endl;






return 0;
}

