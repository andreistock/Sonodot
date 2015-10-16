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



void kalman(double pos_arr[3][2]){

//ofstream data;
//data.open ("data.txt");

int i,j,k;
int n=3, t=3;    //Define dimensions of state vector X 


// Define and initialise matrices

mat y(n,t),x(n,t), F(n,n), B(n,n), P(n,n), Q(n,n), K(n,n), H(n,n), I(n,n), R(n,n);
colvec temp(n), b(t),c(t); //random noise vector
colvec Ytt(n),Xt(n),Xtt(n); //random noise vector
b.randn(),c.randn();
y.zeros(),x.zeros(),F.zeros(),B.zeros(),P.zeros(),Q.zeros(),K.zeros(),H.zeros(),R.zeros();
I = eye<mat>(n,n);


      y(0,1)=  pos_arr[0][0];
      y(0,2)=  pos_arr[0][1];
    //  y(0,3)=  pos_arr[0][2];
      y(1,1)=  pos_arr[1][0];
      y(1,2)=  pos_arr[1][1];
   //   y(1,3)=  pos_arr[1][2];
      y(2,1)=  pos_arr[2][0];
      y(2,2)=  pos_arr[2][1];
   //   y(2,3)=  pos_arr[2][2];
  



// Generate measurement vector Y with white noise. 

//Defines propagator model (no acceleration in this case)

  F << 1 << 0 << 0  << endr 
    << 0 << 1 << 0  << endr
    << 0 << 0 << 1  << endr;
 //   << 0 << 0 << 0 <<1 << endr;

// No measurement error    
P.eye(), H.eye();

//Define the covariance matrices
R.diag().fill(3);  
Q.fill(0.0000);

//Time and measurement update performed together 
for (int i=0;i<t-1;i++) {
    //Time update
    x.col(i)=temp;
    x.col(i+1)=F*(x.col(i));
    P = F*P*trans(F)+Q;
    //Measurement update
    K= P*trans(H)*inv(H*P*trans(H)+R);
    x.col(i+1)=x.col(i+1)+K*(y.col(i+1)-H*(x.col(i+1)));
    P=(I-K*H)*P;
    temp=x.col(i+1);

//    data << i << "  " << x(0,i) << "  " << x(1,i) << "  " << y(0,i) << "  " << y(1,i) << endl;
cout << i+1 << "  " << x(0,i+1)  << "  "<< x(1,i+1)<< "  " << x(2,i+1)<< "  " << y(0,i+1) << "  " << y(1,i+1)<< " "<< y(2,i+1)<< "  "  << endl;
}


//data.close();


}



