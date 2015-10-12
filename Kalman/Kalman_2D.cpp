#include <iostream>
#include <cmath>
#include <fstream>
#include "armadillo"
#include <stdlib.h>
using namespace arma;
using namespace std;
#define pi acos(-1)


#if (ARMA_VERSION_MAJOR > 0 || (ARMA_VERSION_MINOR >= 9 && ARMA_VERSION_PATCH >= 50))
#define RAND randu
#else
#define RAND rand
#endif


int main(){

ofstream data;
data.open ("data.txt");

int i,j,k,Niter;
//cout<<"Enter the dimension of matrix"<<endl;
//cin>>n;
int n=4, t=20;

mat y(n,t),x(n,t),temp(n,t), F(n,n), B(n,n), P(n,n), Q(n,n), K(n,n), H(n,n), I(n,n), R(n,n);
colvec b(t),c(t); //random noise vector
colvec Ytt(n),Xt(n),Xtt(n); //random noise vector
b.randn(),c.randn();
y.zeros(),x.zeros(),F.zeros(),B.zeros(),P.zeros(),Q.zeros(),K.zeros(),H.zeros(),R.zeros();
I = eye<mat>(n,n);
//  z(1)=0.39, z(2)=0.50, z(3)=0.48,z(4)=0.29,z(5)=0.25,z(6)=0.32,z(7)=0.34,z(8)=0.48,z(9)=0.41,z(10)=0.45 ;
//  z(11)=0.39, z(12)=0.50, z(13)=0.48,z(14)=0.29,z(15)=0.25,z(16)=0.32,z(17)=0.34,z(18)=0.48,z(19)=0.41 ;
//I.print(),A.print();

for (j=0;j<t;j++) {
     y(0,j)= j +   b(j);   //positions x
     y(1,j)= j +   c(j);   //position y
     y(2,j)= 1.0;  //vx
     y(3,j)= 1.0;  //vy
}

//y.print();


  F << 1 << 0 << 1 <<0 << endr 
    << 0 << 1 << 0 <<1 << endr
    << 0 << 0 << 1 <<0 << endr
    << 0 << 0 << 0 <<1 << endr;

//F.eye();
P.eye(), H.eye();
//P.fill(1.0);
R.diag().fill(1.0);  //set to variance
Q.fill(0.0000);

for (int i=0;i<t-1;i++) {
    x.col(i+1)=F*(x.col(i));
    P = F*P*trans(F)+Q;
    K= P*trans(H)*inv(H*P*trans(H)+R);
    x.col(i+1)=x.col(i+1)+K*(y.col(i+1)-H*(x.col(i+1)));
    P=(I-K*H)*P;
    data << i << "  " << x(0,i) << "  " << x(1,i) << "  " << y(0,i) << "  " << y(1,i) << endl;
//    data << i << "  " << x(0,i)  << "  " << y(0,i) << "  " << endl;

}

//x.row(0).print();
//temp.row(0).print();

data.close();


return 0;
}

