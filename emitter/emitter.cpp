#include "/home/pi/Sonodot/Sensors/sensor.hpp"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include "/home/pi/Sonodot/Sensors/RCSwitch.h"
#include<thread>
#include<chrono>
#define PIN 29

RCSwitch mySwitch;
int main()
{
  long long duration=0;

  int i=0;
  timespec tsleep{0};
  tsleep.tv_nsec=50000000;
  receiver receiver1(1),receiver2(2);
  receiver1.init();
  receiver2.init();
  mySwitch = RCSwitch();
  mySwitch.enableReceive(PIN);
  
  while (1)
  {
    if (mySwitch.available())
    {
      int value = mySwitch.getReceivedValue(); 
      if (value == 0) 
      {
        printf("Unknown encoding\n");
      }
      else
      {
        printf("received %i\n",mySwitch.getReceivedValue() );
//        delay(3);
        while(1) 
        {
//          auto begin = std::chrono::high_resolution_clock::now();
       ///////////////////////////////////////////////////////////////////
          std::thread t1(&receiver::dst,&receiver1);
          std::thread t2(&receiver::dst,&receiver2);
          t1.join();
          t2.join();
//          i++;
      ///////////////////////////////////////////////////////////////////////////
//          auto end = std::chrono::high_resolution_clock::now();
//          duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
          tsleep.tv_nsec=tsleep.tv_nsec-duration;
          nanosleep(&tsleep,NULL);
//          if (i=20)
//          { i=0;
//            goto mylabel;
//          }
        
        }
//        mySwitch.resetAvailable();
      }
       
//        mySwitch.resetAvailable();
    }
    mylabel :
    mySwitch.resetAvailable();
  }
  return 0;
}
