#include<iostream>
#include<cmath>
using namespace std;
class sphere
{
  public:
  double param[3];
  void setparam() 
  {
    cout<<"what is the x coordinate? = ";
    cin>>param[0];
    cout<<"What is the y coordinate? = ";
    cin>>param[1];
    cout<<"What is the z choordinate? = ";
    cin>>param[2];
  }
};
  double norm(sphere sphere)
  {
    double out;
    out=sqrt(pow(sphere.param[0],2)+pow(sphere.param[1],2)+pow(sphere.param[2],2));
    return out;
  }
  double dot(sphere sphere1,sphere sphere2)
  {
    double out;
    out=sphere1.param[0]*sphere2.param[0]+sphere1.param[1]*sphere2.param[1]+sphere1.param[2]*sphere2.param[2];
    return out;
  }
  sphere cross(sphere sphere1,sphere sphere2)
  {
    sphere sphere3;
    sphere3.param[0]=sphere1.param[1]*sphere2.param[2]-sphere1.param[2]*sphere2.param[1];
    sphere3.param[1]=sphere1.param[2]*sphere2.param[0]-sphere1.param[0]*sphere2.param[2];
    sphere3.param[2]=sphere1.param[0]*sphere2.param[1]-sphere1.param[1]*sphere2.param[0]; 
    return sphere3;
  }
  sphere mult(const double x ,sphere sphere)
  { 
    sphere.param[0]=sphere.param[0]*x;
    sphere.param[1]=sphere.param[1]*x;
    sphere.param[2]=sphere.param[2]*x;
    return sphere;
  }
  sphere divide(const double x,sphere sphere)
  {
    sphere.param[0]=sphere.param[0]/x;
    sphere.param[1]=sphere.param[1]/x;
    sphere.param[2]=sphere.param[2]/x;
    return sphere;
  }
  sphere ominus(sphere sphere1,sphere sphere2)
  {
    sphere sphere3;
    sphere3.param[0]=sphere1.param[0]-sphere2.param[0];
    sphere3.param[1]=sphere1.param[1]-sphere2.param[1];
    sphere3.param[2]=sphere1.param[2]-sphere2.param[2];
    return sphere3;
  }
  sphere oplus(sphere sphere1,sphere sphere2)
  {
    sphere sphere3;
    sphere3.param[0]=sphere1.param[0]+sphere2.param[0];
    sphere3.param[1]=sphere1.param[1]+sphere2.param[1];
    sphere3.param[2]=sphere1.param[2]+sphere2.param[2];
    return sphere3;
  }

void disp(sphere sphere)
  {
    for (int i=0;i<3;i++)
    {cout<<sphere.param[i]<<" ";
    }
    cout<<endl;
  }  
