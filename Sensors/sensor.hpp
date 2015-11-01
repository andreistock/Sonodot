#include "RCSwitch.h"
#include<sys/time.h>
#include<iostream>
#include<stdio.h>
class receiver
{
  protected:
    int trigPin;
    int echoPin;
    struct timeval start,end;
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
//        std::cout<<trigPin<<echoPin<<std::endl;
        break;
      case 2 :
        trigPin=4;
        echoPin=3;
        break;
      case 3 :
        trigPin=26;
        echoPin=22;
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
      if (wiringPiSetup()==-1) std::cout<<"watch your language"<<std::endl;
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
        seconds=end.tv_sec-start.tv_sec;
        useconds=end.tv_usec-start.tv_usec;
        duration=((useconds)*1000+seconds/1000.0)+0.5;  
        if (duration/2 >=10000000)
	  break;
      }
      seconds=end.tv_sec-start.tv_sec;
      useconds=end.tv_usec-start.tv_usec;
      duration=((useconds)*1000+seconds/1000.0)+0.5;
      distance=(duration)/(29.15*2000);
//      std::cout<<distance<<"  e"<<std::endl; 
//      std::cout<<duration/2<<std::endl;
      return distance;
      
    }
};
