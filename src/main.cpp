#include "Matrix.h"
#include <iostream>
#include <tuple>


int main(){

Matrix m(5,5);
//std::cout<<m;
//p.shape();

m.initRand(5,5);
std::cout<<m<<std::endl;

m(2,2) =  7777;

std::cout<<m(2,2)<<std::endl;
std::cout<<m<<std::endl;


//p.shape();
//std::cout << p.transpose() << std::endl;
//std::cout << p << std::endl;
//std::cout << m << std::endl;
//std::cout << gaussEli(p) << std::endl;
//Matrix l, u, p;
//auto result =  luCrout(m);

//l = std::get<0>(result);
//u = std::get<1>(result) ;
//p = std::get<2>(result) ;
//a = std::get<2>(result) ;

//std::cout << l << std::endl;
//std::cout << u << std::endl;
//std::cout << p << std::endl;
//std::cout << a << std::endl;
//std::cout <<  (3*p*p).swapRows(0,2).scaleRow(3,2) << std::endl;



//std::cout <<"cholesky \n" <<  cholesky(m) << std::endl;
//std::cout << cholesky(m)*(cholesky(m).transpose()) << std::endl;
/*int n = 100000;
Matrix x(n,n);
x.initRand(n,n);
Matrix q(n,n);
Matrix r(n,n);

qrdecomp(x,q, r);
std::cout<< x << q << r << q*r << std::endl;*/
return 0;
}

