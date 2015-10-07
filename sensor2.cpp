#include "sensor.hpp"
#include<iostream>

int main()
{
 double distance1; 
 receiver receiver1(1);
 receiver1.init();
 while(true)
{
 distance1=receiver1.dst();
 std::cout<<distance1;
 delayMicroseconds(100);
} 
}

