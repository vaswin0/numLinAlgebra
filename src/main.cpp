#include "Matrix.h"
#include <iostream>
#include <tuple>
#include <vector>



int main(){


 std::vector<std::vector<double>> mtrx = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };






Matrix m(mtrx);

Matrix n =  m + m;
//m.initMatrix();
//std::cout<<m;
//p.shape();

//m.initRand(6,6);
std::cout<<n<<std::endl;

//m(2,2) =  7777;

//std::cout<<m(2,2)<<std::endl;
//std::cout<<m<<std::endl;

//m.shape();


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

