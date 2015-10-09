#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#define PIN 29
int main()
{
 int code=5;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 double distance1,distance2;
 receiver receiver1(1),receiver2(2);
 receiver1.init();
 receiver2.init();
 printf("activating emitter");
 mySwitch.send(code,24);
 delay(2);
 while (true)
 {
 distance1=receiver1.dst();
// distance2=receiver2.dst();
 std::cout<<distance1<<"  "<<distance2<<std::endl;
 delay(100);
 }
 return 0;
}

