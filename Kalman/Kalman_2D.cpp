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

int i,j,k;
int n=4, t=20;    //Define dimensions of state vector X 


// Define and initialise matrices

mat y(n,t),x(n,t),temp(n,t), F(n,n), B(n,n), P(n,n), Q(n,n), K(n,n), H(n,n), I(n,n), R(n,n);
colvec b(t),c(t); //random noise vector
colvec Ytt(n),Xt(n),Xtt(n); //random noise vector
b.randn(),c.randn();
y.zeros(),x.zeros(),F.zeros(),B.zeros(),P.zeros(),Q.zeros(),K.zeros(),H.zeros(),R.zeros();
I = eye<mat>(n,n);

// Generate measurement vector Y with white noise. 

for (j=0;j<t;j++) {
     y(0,j)= j +   b(j)/10;   //positions x
     y(1,j)= j +   c(j)/10;   //position y
     y(2,j)= 1.0;  //vx
     y(3,j)= 1.0;  //vy
}

//Defines propagator model (no acceleration in this case)

  F << 1 << 0 << 1 <<0 << endr 
    << 0 << 1 << 0 <<1 << endr
    << 0 << 0 << 1 <<0 << endr
    << 0 << 0 << 0 <<1 << endr;

// No measurement error    
P.eye(), H.eye();

//Define the covariance matrices
R.diag().fill(0.1);  
Q.fill(0.0000);

//Time and measurement update performed together 
for (int i=0;i<t-1;i++) {
    //Time update
    x.col(i+1)=F*(x.col(i));
    P = F*P*trans(F)+Q;
    //Measurement update
    K= P*trans(H)*inv(H*P*trans(H)+R);
    x.col(i+1)=x.col(i+1)+K*(y.col(i+1)-H*(x.col(i+1)));
    P=(I-K*H)*P;
    data << i << "  " << x(0,i) << "  " << x(1,i) << "  " << y(0,i) << "  " << y(1,i) << endl;

}

//x.row(0).print();
//temp.row(0).print();

data.close();


return 0;
}

