#include "Matrix.h"
#include <iostream>

int main(){

Matrix p(4,4);

Matrix pt ;


//p.initMatrix();


//std::cout << p << std::endl;

//pt =  p.transpose();

Matrix sum = p + p;

std::cout << sum  << std::endl;

Matrix diff = p*p - p;

std::cout << diff << std::endl;

std::cout << p*p << std::endl;


return 0;
}

