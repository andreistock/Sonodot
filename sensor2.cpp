#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#define PIN 29
int main()
{
 int code=5;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2);
 receiver1.init();
 receiver2.init();
 printf("activating emitter");
 mySwitch.send(code,24);
 delay(2);
 while (true)
 {
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 t1.join();
 t2.join();
 std::cout<<receiver1.distance<<"  "<<receiver2.distance<<std::endl;
 delay(50);
 }
 return 0;
}

