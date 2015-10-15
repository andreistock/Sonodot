#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<stdio.h>
#include<thread>
#include "/home/pi/Sonodot/trilat/tsi.cpp"
//#include "/home/pi/Sonodot/Kalman/Kalman_3D.cpp"
#define PIN 29
int main()
{
// setup();
int i=0;

// double data_arr[3][100];
// double pos_arr[3][2];

 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2),receiver3(3);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 std::cout<<"Activating emitter"<<std::endl;
 mySwitch.send(5,24);
 delay(3);
// std::thread t1(&receiver::dst,&receiver1);
// std::thread t2(&receiver::dst,&receiver2);
// std::thread t3(&receiver::dst,&receiver3);
 while (true)
 {
 i++;
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 std::thread t3(&receiver::dst,&receiver3);
 t1.join();
 t2.join();
 t3.join();
 std::cout<<receiver1.distance<<"  "<<receiver2.distance<<"  "<<receiver3.distance<<"  "<<i<<std::endl;
/* calculate(receiver1.distance,receiver2.distance,receiver3.distance);
     data_arr[0][i]=receiver1.distance;  //x
     data_arr[1][i]=receiver2.distance;  //y
     data_arr[2][i]=receiver3.distance;  //z

     pos_arr[0][0]= data_arr[0][i-1]; //x
     pos_arr[1][0]= data_arr[1][i-1]; //y
     pos_arr[2][0]= data_arr[2][i-1]; //z
     pos_arr[0][1]= data_arr[0][i];   //x
     pos_arr[1][1]= data_arr[1][i];   //y
     pos_arr[2][1]= data_arr[2][i];   //z

  kalman(pos_arr);
*/
 delay(50);
 }
 return 0;
}

