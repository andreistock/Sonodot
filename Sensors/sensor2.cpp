#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#include</home/pi/Sonodot/Kalman/Kalman_3D.cpp>
#include<fstream>
#define PIN 29
int main()
{
 int code=5,i=0;
 double duration,pos_arr[3][2], tmp1=0, tmp2=0, tmp3=0; 
 timeval start,end;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2),receiver3(3);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 printf("activating emitter\n");
 mySwitch.send(code,24);
// delay(3);
 ofstream data;
 data.open ("data.txt");
 while (true)
 {
// gettimeofday(&start,NULL);
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 std::thread t3(&receiver::dst,&receiver3);
 t1.join();
 t2.join();
 t3.join();
// std::cout<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<"  "<<i<<std::endl;
 pos_arr[0][0]=tmp1;
 pos_arr[1][0]=tmp2;
 pos_arr[2][0]=tmp3;
 pos_arr[0][1]=receiver1.distance;
 pos_arr[1][1]=receiver2.distance;
 pos_arr[2][1]=receiver3.distance;
 tmp1= pos_arr[0][1];
 tmp2= pos_arr[1][1];
 tmp3= pos_arr[2][1];
// kalman(pos_arr);
// gettimeofday(&start,NULL);
 kalman(pos_arr);
// gettimeofday(&end,NULL);
// duration=((end.tv_usec-start.tv_usec)*1000+(end.tv_sec-start.tv_sec)/1000)+0.5;
// std::cout<<"time for Kalman "<<duration<<std::endl;
 delay(50);





// gettimeofday(&end1,NULL);
// duration1=((end1.tv_usec-start1.tv_usec)*1000+(end1.tv_sec-start1.tv_sec)/1000)+0.5;
// std::cout<<"time for Kalman "<<duration<<std::endl;
// delay(50-duration1/1000000);
 i++;
 }
data.close();
return 0;
}
