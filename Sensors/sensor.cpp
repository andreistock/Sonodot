#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#define PIN 29
int main()
{
 int code=5,i=0;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2),receiver3(3);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 printf("activating emitter\n");
 mySwitch.send(code,24);
// delay(3);

 while (true)
 {
// mySwitch.send(code,24);
 receiver1.dst();
 receiver2.dst();
 receiver3.dst();
 std::cout<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<std::endl;
 i++;
 delay(50);
 }
return 0;
}
