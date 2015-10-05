

#include "sensor.hpp"
#include<iostream>
#include<sys/time.h>
#include<time.h>
#include<stdio.h>
#include<thread>
//#include</home/pi/Sonodot/Kalman/Kalman_3D.cpp>
#include<fstream>
#define PIN 29
#include<chrono>
int main()
{
 int code=5,i=0;
 double duration,duration1,pos_arr[3][2], tmp1=0, tmp2=0, tmp3=0; 
 struct timeval start,end1,start1;
 timespec tsleep{0};
// clock_t t;
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 receiver receiver1(1),receiver2(2),receiver3(3),receiver4(4),receiver5(5),receiver6(6),receiver7(7),receiver8(8);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 receiver4.init();
 receiver5.init();
 receiver6.init();
 receiver7.init();
 receiver8.init();
 std::ofstream data;
 data.open ("data.txt");
 printf("activating emitter\n");
 mySwitch.send(code,24);
// delay(3);
 long long duration2=0;
 while (true)
 {
 tsleep.tv_nsec=50000000-duration2;
// std::cout<<tsleep.tv_nsec<<"\n";
 nanosleep(&tsleep,NULL);
 auto begin = std::chrono::high_resolution_clock::now();
// gettimeofday(&start1,NULL);
// std::cout<<start1.tv_usec<<std::endl;
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 std::thread t3(&receiver::dst,&receiver3);
 std::thread t4(&receiver::dst,&receiver4);
 std::thread t5(&receiver::dst,&receiver5);
 std::thread t6(&receiver::dst,&receiver6);
 std::thread t7(&receiver::dst,&receiver7);
 std::thread t8(&receiver::dst,&receiver8);
// std::cout<<"receiver1"<<receiver1.distance <<"receiver2"<<receiver2.distance<< "receiver3"<<receiver3.distance  <<      std::endl;
 std::cout<<"receiver1 "<<receiver1.distance <<" receiver2 "<<receiver2.distance<<" receiver 3"<<receiver3.distance<<"receiver 4 "<<receiver4.distance<<" receiver 5 "<<receiver5.distance<<" receiver 6 "<<receiver6.distance<<" receiver 7 "<<receiver7.distance<<"receiver 8 "<<receiver8.distance<<"\n";


 t1.join();
 t2.join();
 t3.join();
 t4.join();
 t5.join();
 t6.join();
 t7.join();
 t8.join();
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
// gettimeofday(&start,NULL);
// kalman(pos_arr);
// gettimeofday(&end1,NULL);
 auto end = std::chrono::high_resolution_clock::now();
// std::cout<<end;
// duration1=((end1.tv_sec-start.tv_sec)*1000+(abs(end1.tv_usec-start1.tv_usec)/1000.0)+0.5)/2;
// duration=(abs(end1.tv_usec-start.tv_usec)/1000.0);
 auto duration2 = std::chrono::duration_cast <std::chrono::nanoseconds>(end-begin).count();
// printf("Duration: %lli \n",duration2); 
// printf("%g %g %g \n",receiver1.distance,receiver2.distance,receiver3.distance);
//std::cout<<"receiver1"<<receiver1.distance <<"receiver2"<<receiver2.distance<< "receiver3"<<receiver3.distance  <<      std::endl;
  std::cout<<"receiver1 "<<receiver1.distance <<" receiver2 "<<receiver2.distance<< " receiver3 "<<receiver3.distance  <<" receiver 4 "<<receiver4.distance<<" receiver 5 "<<receiver5.distance<<" receiver 6 "<<receiver6.distance<< " receiver 7 "<<receiver7.distance<< " receiver 8 "<<receiver8.distance<<"\n";

// std::cout<<"time for Kalman / calculations "<<duration<< "  " << duration1<< std::endl;
// usleep(50000-duration2/1000000.0)*1000);

// gettimeofday(&end1,NULL);
// duration1=((dend1.tv_usec-start1.tv_usec)*1000+(end1.tv_sec-start1.tv_sec)/1000)+0.5;
// std::cout<<"time for Kalman "<<duration<<std::endl;
// usleep(50000);//-duration2/1000.0);
// i++;
 }
data.close();
return 0;
}
