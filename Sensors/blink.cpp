#include <wiringPi.h>
int main (void)
{
  wiringPiSetup();
  pinMode (0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);

  while(true)
  {
  digitalWrite (0,HIGH); delay(100);
  digitalWrite (0,LOW); delay(100);
  digitalWrite (1,HIGH); delay(100);
  digitalWrite (1,LOW); delay(100);
  digitalWrite (2,HIGH); delay(100);
  digitalWrite (2,LOW); delay(100);
  }
}

