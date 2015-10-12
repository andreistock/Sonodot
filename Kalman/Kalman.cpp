//MTMCC assignement Conjugate Gradient. Niccolo Corsini
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


//x.print();
//z.print();
//cout << x(1) << "  " << x(2) << "   " << x(3) << "  " << x(4) << "   " << x(5) << endl;
//cout << P(1) << "  " << P(2) << "   " << P(3) << "  " << P(4) << "   " << P(5) << endl;







return 0;
}




/*int main(){
int i,j,k,n,Niter;
	cout<<"Enter the dimension of matrix"<<endl;
	cin>>n;
	cout<<"Enter number of iteration"<<endl;
	cin>>Niter;
    double el,xxx,alpha,alpha1,beta,residue,tempo,alphahat;
    colvec g(n),p(n),b(n),X(n),X1(n),uuu(n),temp(n),vvv(n),yyy(n),zzz(n),g1(n); 
    mat A(n,n);

    cout << "Enter value for x: ";
    cin >> xxx;
    
    // Generate A and b
    b = RAND<colvec>(n);
	X=RAND<colvec>(n);
	X1=X;
    A = eye<mat>(n,n);
    el = xxx;
    for (i=1;i<(n+1)/2;i++) {
        for (j=0;j<n;j++) {
            k = (i+j) % n;
            A(j,k) = el;
            A(k,j) = el;
        }
        el *= xxx;
    }
	
	//Takes a first steepest descent step
	g=A*X-b;
	p=-g;  
	zzz=(trans(g)*g)/(trans(g)*(A*g)); //Need to store scalar as a vector due to armadillo hitch
	alpha=zzz(0);
	X +=-alpha1*g;
	
	//Conjugate Gradient method
	for(int i=0;i<Niter;i++){
	    uuu=(trans(p)*g)/(trans(p)*(A*p));   
	    alpha=uuu(0);
		temp=trans(g)*g;
		tempo=temp(0);
		g=A*X-b; 
		vvv=(trans(g)*g)/tempo;    
		beta=vvv(0);
		p=-g +beta*p;
		yyy=(trans(p)*g)/(trans(p)*A*p);
		alphahat=yyy(0);
		X+=-alphahat*p;
		}
		
	//Steepest descent method
	for(int i=0;i<Niter;i++){
	g=A*X1-b;                
	zzz=(trans(g)*g)/(trans(g)*(A*g));  
	alpha1=zzz(0);
	X1 +=-alpha1*g;
	
	}
	
	colvec x1=solve(A,b);   //Solves using armadillo for comparison with Steepest descent and CG
	
	cout<<"Error in Conjugate gradient  "<<norm(x1-X,2)<<"  Error in Steepest descent  "<<norm(x1-X1,2)<<endl;
	
	return 0;
	
}
*/	

