#include "/home/pi/Sonodot/Sensors/sensor.hpp"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include "/home/pi/Sonodot/Sensors/RCSwitch.h"
#include<thread>
#define PIN 29 

RCSwitch mySwitch;
int main()
{
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
    //    delay(3);
        while(true) 
        {
          std::thread t1(&receiver::dst,&receiver1);
          std::thread t2(&receiver::dst,&receiver2);
          t1.join();
          t2.join();
          delay(50);
        }
      }
//  mySwitch.resetAvailable();
    }
  }
  return 0;
}
