#include<iostream>
#include<wiringPi.h>
#include<sys/time.h>
using namespace std;
int main(void)
{
 wiringPiSetup();
 int n=3;
 int trigPin[n];
 int echoPin[n];
 long distance[n-1];
 switch (n)
 {
  case 1 :
   trigPin[1]=1;
   echoPin[1]=0;
  case 2 :
   trigPin[1]=1;
   echoPin[1]=0;
   trigPin[2]=4;
   echoPin[2]=3;
  case 3 :
   trigPin[1]=1;
   echoPin[1]=0;
   trigPin[2]=4;
   echoPin[2]=3;
   trigPin[3]=28;
   echoPin[3]=25; 
 }
 for (int i=1;i<=n;i++)
 {
  pinMode(echoPin[i],INPUT);
  pinMode(trigPin[i],OUTPUT);
 }
 struct timeval start,end;
 long seconds, useconds;
 long duration;
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
  delayMicroseconds(14);
  for (int i=1;i<=n;i++)
  {
   digitalWrite(trigPin[i],LOW);
  }
  for (int i=1;i<=n-1;i++)
  {
   while (digitalRead(echoPin[i])==0)  
   {
    gettimeofday(&start,NULL);
   } 
   while (digitalRead(echoPin[i])==1)
   {
    gettimeofday(&end,NULL);
   }  
  
   seconds=end.tv_sec-start.tv_sec;
   useconds=end.tv_usec-start.tv_usec;
   duration=((useconds)*1000+seconds/1000.0);//+0.5;
   distance[i]=(duration)/29.1;
  
   if ((distance[i]>1000)&&(distance[i]<2000000))
    { 
   cout<<"distance from emmiter "<<i<<" = "<<distance[i]<<"\n";
    }
  } 
 delay(50);
 }
}

