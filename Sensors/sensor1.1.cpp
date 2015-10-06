#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#include<fstream>
#define PIN 29
#include<chrono>
int main()
{
 int code=5,i=0;
 timespec tsleep{0};
 long long duration2=0,duration1=0;
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
 auto begin = std::chrono::high_resolution_clock::now();
////////////////////////////////////////////////////////////////////////////////
 mySwitch.send(code,24);
 receiver1.dst();
// receiver2.dst();
// receiver3.dst();
 data<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<std::endl;

////////////////////////////////////////////////////////////////////////////////
 auto end = std::chrono::high_resolution_clock::now(); 

// data<<end.tv_usec<<"\n";
 duration2 = std::chrono::duration_cast <std::chrono::nanoseconds>(end-begin).count();
// tsleep.tv_nsec=50000000-duration2;
// nanosleep(&tsleep,NULL);
 auto end2 = std::chrono::high_resolution_clock::now();
 duration1 = std::chrono::duration_cast <std::chrono::nanoseconds>(end2-begin).count();
 data<<duration1<<"\n";
 }
return 0;
}
