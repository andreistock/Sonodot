#include "RCSwitch.h"
#include<sys/time.h>
#include<iostream>
class receiver
{
  public:
    long distance;;
    receiver(int n);
    void init();
    double dst();
    long trigPin;
    long echoPin;
    struct timeval start,end;
    double duration,seconds,useconds;
};
receiver::receiver(int n)
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
void receiver::init(void)
{
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  std::cout<<echoPin<<trigPin<<std::endl;
}
double receiver::dst()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  while (digitalRead(echoPin==0))
  {
    gettimeofday(&start,NULL);
  }
  while (digitalRead(echoPin)==1)
  {
    gettimeofday(&end,NULL);
  }
  std::cout<<start.tv_sec<<end.tv_sec;
  seconds=end.tv_sec-start.tv_sec;
  useconds=end.tv_usec-start.tv_usec;
  duration==((useconds)*1000+seconds/1000.0)+0.5;
  distance=duration/29.1;
  return distance;
}
