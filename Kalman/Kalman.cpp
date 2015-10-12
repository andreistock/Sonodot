// 1D Example of Kalman filter 

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
int  n=20;
double R=0.1; 
colvec z(n),x(n),P(n),K(n);
z.zeros();x.zeros();P.zeros();K.zeros();
//z=RAND<colvec>(n);
z(1)=0.39, z(2)=0.50, z(3)=0.48,z(4)=0.29,z(5)=0.25,z(6)=0.32,z(7)=0.34,z(8)=0.48,z(9)=0.41,z(10)=0.45 ;
z(11)=0.39, z(12)=0.50, z(13)=0.48,z(14)=0.29,z(15)=0.25,z(16)=0.32,z(17)=0.34,z(18)=0.48,z(19)=0.41 ;

P(0)=1.0;

for (int i=0;i<n;i++){
//Time update
 x[i+1]=x[i];
// cout << " Iteration #"<< i<<"  " <<  x[i+1] << endl;
 P[i+1]=P[i];
// cout << P[i+1]<< endl;
 K[i+1]= P[i+1]/(P[i+1]+R);
// cout << K[i+1]<< endl;
 x[i+1]= x[i+1]+K[i+1]*(z[i+1]-x[i+1]);
// cout << x[i+1]<< endl;
 P[i+1]=(1.0-K[i+1])*P[i+1];
// cout << P[i+1] << endl;
}
data << z << endl;
data << x << endl;

data.close();
return 0;
}
