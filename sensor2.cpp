#include "sensor.hpp"
#include<iostream>
int main()
{
 std::cout<<"helo"<<std::endl;
 double distance1;
 receiver receiver(2);
 receiver.init();
 while (true)
 {
 distance1=receiver.dst();
 std::cout<<distance1<<std::endl;
 delayMicroseconds(100000);
 }
 return 0;
}

