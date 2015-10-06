#include "RCSwitch.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int PIN=29;
 int code=5;
 if (wiringPiSetup () == -1) return 1;
 printf("sending code[%i]\n", code);
 RCSwitch mySwitch = RCSwitch();
 mySwitch.enableTransmit(PIN);
 for (int i=1;i<=20;i++)   
 {
   mySwitch.send(i, 24);
 } 
        return 0;

}
 
