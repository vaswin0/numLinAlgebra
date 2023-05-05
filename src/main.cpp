#include "Matrix.h"
#include <iostream>
#include <tuple>


int main(){

Matrix m(3,3);
//p.shape();

m.initMatrix();

//p.shape();
//std::cout << p.transpose() << std::endl;
//std::cout << p << std::endl;
std::cout << m << std::endl;
//std::cout << gaussEli(p) << std::endl;
Matrix l, u, p, a;
auto result =  lu(m);

l = std::get<0>(result);
u = std::get<1>(result) ;
p = std::get<2>(result) ;
a = std::get<3>(result) ;

std::cout << l << std::endl;
std::cout << u << std::endl;
std::cout << p << std::endl;
std::cout << a << std::endl;
//std::cout <<  (3*p*p).swapRows(0,2).scaleRow(3,2) << std::endl;



return 0;
}

