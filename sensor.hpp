#include "RCSwitch.h"
#include<sys/time.h>
#include<iostream>
#include<stdio.h>
class receiver
{
  protected:
    int trigPin;
    int echoPin;
    timeval start,end;
    double duration,seconds,useconds;
  public:
    double distance; 
  receiver(int n)
    {
      switch (n)
      {
      case 1 :
        trigPin=1;
        echoPin=0;
        std::cout<<trigPin<<echoPin<<std::endl;
        break;
      case 2 :
        trigPin=4;
        echoPin=3;
        break;
      case 3 :
        trigPin=26;
        echoPin=25;
        break;
      case 4 :
        trigPin=27;
        echoPin=24;
        break;
      case 5 :
        trigPin=28;
        echoPin=25;
        break;
      default:
        break;
      }
    }
    void init(void)
    {
      wiringPiSetup();
      if (wiringPiSetup()==-1) std::cout<<"fuck you"<<std::endl;      
      pinMode(echoPin,INPUT);
      pinMode(trigPin,OUTPUT);
    }
    double dst()
    {
      digitalWrite(trigPin,LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(14);
      digitalWrite(trigPin,LOW);
      while (digitalRead(echoPin)==0)
      {
        gettimeofday(&start,NULL);
      }
      while (digitalRead(echoPin)==1)
      {
        gettimeofday(&end,NULL); 
      }
      seconds=end.tv_sec-start.tv_sec;
      useconds=end.tv_usec-start.tv_usec;
      duration=((useconds)*1000+seconds/1000.0)+0.5;
      distance=(duration)/(29.1*2);
      return distance;
      
    }
};
