#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#include</home/pi/Sonodot/Kalman/Kalman_3D.cpp>
#define PIN 29
int main()
{
 int code=5,i=0;
 double pos_arr[3][2], tmp1=0, tmp2=0, tmp3=0;
 clock_t init,final;
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
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 std::thread t3(&receiver::dst,&receiver3);
 t1.join();
 t2.join();
 t3.join();
 std::cout<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<"  "<<i<<std::endl;
 pos_arr[0][i]=tmp1;
 pos_arr[1][i]=tmp2;
 pos_arr[2][i]=tmp3;
 pos_arr[0][i+1]=receiver1.distance;
 pos_arr[1][i+1]=receiver2.distance;
 pos_arr[2][i+1]=receiver3.distance;
 tmp1= pos_arr[0][i+1];
 tmp2= pos_arr[1][i+1];
 tmp3= pos_arr[2][i+1]; 
 init=clock(); 
 kalman(pos_arr);
 final=clock()-init;
 cout<<"time for Kalman "<<double(final) / double(CLOCKS_PER_SEC)<<endl; 
 delay(50);
 i++;
 }
return 0;
}
