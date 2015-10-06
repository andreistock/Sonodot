#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#include<fstream>
#define PIN 29
int main()
{
 int code=5,i=0;
 struct timeval  start,end;
 double duration,seconds,useconds;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2),receiver3(3);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 printf("activating emitter\n");
 mySwitch.send(code,24);
 std::ofstream data;
 data.open ("data.txt");
// delay(3);

 while (true)
 {
 gettimeofday(&start,NULL);
// mySwitch.send(code,24);
 receiver1.dst();
// receiver2.dst();
// receiver3.dst();
 std::cout<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<std::endl;
 gettimeofday(&end,NULL);
 seconds=end.tv_sec-start.tv_sec;
 useconds=end.tv_usec-start.tv_usec;
 duration=((useconds)*1000+seconds/1000.0)+0.5;

 delay(50);
 }
return 0;
}
