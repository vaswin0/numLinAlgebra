#include "Matrix.h"
#include <iostream>
#include <tuple>
#include <vector>



int main(){


 std::vector<std::vector<double>> mtrx = {
        {0, 1,-1,-1},
        {1,1,-2,-3},
        {3,-1,1,4},
		{1,2,3,4}
    };






Matrix M(mtrx);
std::cout<<M<<std::endl;
M.shape();
std::cout<<norm(M)<<std::endl;
//Matrix A(3,3) ; A.initRand(3,3);
//Matrix x(4,1) ; x.initRand(4,1);


//Matrix m(3,4);
//m.initMatrix();
//std::cout<<m;
//p.pshape();

//m.initRand(6,6);

//std::cout<<trace(A)<<std::endl;

//std::cout<<A<<std::endl;

/*

auto [L,U,LU]= luCrout(M);
std::cout <<"input M: " << M << "\n";
std::cout <<"L: " << L << "\n";
std::cout << "U: " << U << "\n";
//std::cout << "P: " << P << "\n";
//std::cout << "Q: " << MM << "\n";


Matrix temp = L*U;
std::cout << "recon:" << "\n" << temp << "\n";
*/


//std::cout <<m.gaussEli() << std::endl;
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

