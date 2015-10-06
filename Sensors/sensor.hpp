#include "RCSwitch.h"
#include<sys/time.h>
#include<iostream>
#include<stdio.h>
class receiver
{
  protected:
    int trigPin;
    int echoPin;
    struct timeval start1, start,end;
    double duration,seconds,useconds;
  public:
    double distance; 
  receiver(int n)
    {
      switch (n)
      {
      case 1 :
        trigPin=7;
        echoPin=1;
//        std::cout<<trigPin<<echoPin<<std::endl;
        break;
      case 2 :
        trigPin=0;
        echoPin=2;
        break;
      case 3 :
        trigPin=3;
        echoPin=4;
        break;
      case 4 :
        trigPin=5;
        echoPin=6;
        break;
      case 5 :
        trigPin=21;
        echoPin=26;
        break;
      case 6 :
        trigPin=22;
        echoPin=23;
        break;
      case 7 :
        trigPin=24;
        echoPin=27;
        break;
      case 8 :
        trigPin=25;
        echoPin=28;
        break;
      default:
        break;
      }
    }
    void init(void)
    {
      wiringPiSetup();
      if (wiringPiSetup()==-1) std::cout<<"watch your language"<<std::endl;
      pinMode(echoPin,INPUT);
      pinMode(trigPin,OUTPUT);
    }
    double dst()
    {
      distance=0;
//      duration=0;
      digitalWrite(trigPin,LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(14);
      digitalWrite(trigPin,LOW);
      gettimeofday(&start1,NULL);
      while (digitalRead(echoPin)==0)
      {
        gettimeofday(&start,NULL);
        seconds=start.tv_sec-start1.tv_sec;
        useconds=start.tv_usec-start1.tv_usec;
        duration=((useconds)*1000+seconds/1000.0)+0.5;
        if (duration/2 >= 1000000)
          {
          distance=0.1;
          goto mylabel;
          }
      }
      while (digitalRead(echoPin)==1)
      {
        gettimeofday(&end,NULL);
        seconds=end.tv_sec-start.tv_sec;
        useconds=end.tv_usec-start.tv_usec;
        duration=((useconds)*1000+seconds/1000.0)+0.5;  
        if (duration/2 >10000000)
          {
          distance=0.2;
          goto mylabel;
          }
      }
      mylabel :
      if ((distance==0.1)||(distance==0.2))
      {
      return distance;
      }
      else
      {
      seconds=end.tv_sec-start.tv_sec;
      useconds=end.tv_usec-start.tv_usec;
      duration=((useconds)*1000+seconds/1000.0)+0.5;
      distance=(duration)/(29.15*2000);
//      std::cout<<distance<<"  e"<<std::endl; 
//      std::cout<<duration/2<<std::endl;
      return distance;
      }
    }
};
