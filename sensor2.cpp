#include "sensor.hpp"
#include<iostream>
using namespace std;
int main()
{
 std::cout<<"helo";
 double distance1; 
 receiver receiver(1);
 receiver.init();
 while(true)
{
 distance1=receiver.dst();
 std::cout<<distance1<<std::endl;
 delayMicroseconds(1000000);
} 
}

