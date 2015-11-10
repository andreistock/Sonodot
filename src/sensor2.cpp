

#include<iostream>
#include<sys/time.h>
#include<time.h>
#include<stdio.h>
#include<thread>
#include</home/pi/Sonodot/Kalman/Kalman_3D.cpp>
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
 receiver receiver1(1),receiver2(2),receiver3(3);
 receiver1.init();
 receiver2.init();
 receiver3.init();
 ofstream data;
 data.open ("data.txt");
 printf("activating emitter\n");
 mySwitch.send(code,24);
// delay(3);
 auto duration2=0;
 while (true)
 {
 tsleep.tv_nsec=50000000-duration2;
 nanosleep(&tsleep,NULL);
 auto begin = std::chrono::high_resolution_clock::now();
// gettimeofday(&start1,NULL);
 // std::cout<<start1.tv_usec<<std::endl;
 std::thread t1(&receiver::dst,&receiver1);
 std::thread t2(&receiver::dst,&receiver2);
 std::thread t3(&receiver::dst,&receiver3);

//std::cout<<"receiver1"<<receiver1.distance <<"receiver2"<<receiver2.distance<< "receiver3"<<receiver3.distance  <<      std::endl;
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
// gettimeofday(&start,NULL);
// kalman(pos_arr);
// gettimeofday(&end1,NULL);
 auto end = std::chrono::high_resolution_clock::now();
// duration1=((end1.tv_sec-start.tv_sec)*1000+(abs(end1.tv_usec-start1.tv_usec)/1000.0)+0.5)/2;
// duration=(abs(end1.tv_usec-start.tv_usec)/1000.0);
 auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count(); 
 printf("Duration: %lli \n",duration2); 
 printf("%g %g %g \n",receiver1.distance,receiver2.distance,receiver3.distance);
//std::cout<<"receiver1"<<receiver1.distance <<"receiver2"<<receiver2.distance<< "receiver3"<<receiver3.distance  <<      std::endl;
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
