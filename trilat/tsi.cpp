#include<iostream>
#include "tsi.hpp"
#include<cmath>
using namespace std;
  static double a,i,j,x,y,z,d,temp4;
  static sphere sphere1,sphere2,sphere3,temp1,e_x,temp2,temp3,e_y,e_z,p_12_a,p_12_b,temp6,temp5;
void setup()  
{
  sphere1.setparam();
  sphere2.setparam();
  sphere3.setparam();
}
void calculate(double r1, double r2, double r3)
{
  temp1=ominus(sphere2,sphere1);
  e_x=divide(norm(temp1),temp1);
  temp2=ominus(sphere3,sphere1);
  i=dot(e_x,temp2);
  temp6=mult(i,e_x);
  temp3=ominus(temp2,temp6);
  a=norm(temp3);
  e_y=divide(a,temp3);
  e_z=cross(e_x,e_y);
  temp5=ominus(sphere2,sphere1);
  d=norm(temp5);
  j=dot(e_y,temp2);
  x=(pow(r1,2)-pow(r2,2)+pow(d,2))/(2*d);
  y=(pow(r1,2)-pow(r3,2)-2*i*x+pow(i,2)+pow(j,2))/(2*j);
  temp4=pow(r1,2)-pow(x,2)-pow(y,2);
//  std::cout<<temp4<<endl;
  if (temp4<0)
  std::cout<<"The three spheres do not intersect!";
  z=sqrt(temp4);
  temp6=mult(x,e_x);
  p_12_a=oplus(sphere1,temp6);
  temp6=mult(y,e_y);
  p_12_a=oplus(p_12_a,temp6);
  temp6=mult(z,e_z);
  p_12_b=ominus(p_12_a,temp6);
  p_12_a=oplus(p_12_a,temp6);
  disp(p_12_a);
  disp(p_12_b);
}
void test()
{
setup();
double cnt=10;

calculate(cnt,cnt,cnt);
}
