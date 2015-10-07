#include "RCSwitch.h"
#include<iostream>
#include<wiringPi.h>
#include<sys/time.h>
#include<stdio.h>
using namespace std;
int main(void)
{
 wiringPiSetup();
 int PIN=29;
 int code=5;
 if (wiringPiSetup () == -1) return 1;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 long int n;
 cout<<"enter configuration ";
 cin>>n;
 int trigPin[n];
 int echoPin[n];
 long distance[n-1];
 switch (n)
 {
  case 1 :
   trigPin[1]=1;
   echoPin[1]=0;
   break;
  case 2 :
   trigPin[1]=1;
   echoPin[1]=0;
   trigPin[2]=4;
   echoPin[2]=3;
   break;
  case 3 :
   trigPin[1]=1;
   echoPin[1]=0;
   trigPin[2]=4;
   echoPin[2]=3;
   trigPin[3]=28;
   echoPin[3]=25;
   break;
  case 4 :
   trigPin[1]=28;
   echoPin[1]=25;
   trigPin[2]=4;
   echoPin[2]=3;
   break;
  default :
   break; 
 }
 for (int i=1;i<=n;i++)
 {
  pinMode(echoPin[i],INPUT);
  pinMode(trigPin[i],OUTPUT);
 }
 struct timeval start,end;
 long seconds, useconds;
 long duration;
 printf("sending code %i",code);
 mySwitch.send(code,24);
 
 while(true) 
 {
  for (int i=1;i<=n;i++)
  {
   digitalWrite(trigPin[i],LOW);
  }
  delayMicroseconds(2);
  for (int i=1;i<=n;i++)
  {
   digitalWrite(trigPin[i],HIGH);
  }
  delayMicroseconds(10);
//  printf("sending code %i",code);
//  mySwitch.send(code,24); 
  for (int i=1;i<=n;i++)
  {
   digitalWrite(trigPin[i],LOW);
  }
   while (digitalRead(echoPin[1])==0)  
   {
    gettimeofday(&start,NULL);
   } 
   while (digitalRead(echoPin[1])==1)
   {
    gettimeofday(&end,NULL);
   }  
  
   seconds=end.tv_sec-start.tv_sec;
   useconds=end.tv_usec-start.tv_usec;
   duration=((useconds)*1000+seconds/1000.0)+0.5;
   distance[1]=(duration)/(2*29.1);
  
  // if ((distance[i]>1000)&&(distance[i]<2000000))
  //  { 
   cout<<"distance from emmiter "<<1<<" = "<<distance[1]<<"\n";
  //  }
//  } 
 delay(50);
 }
}

