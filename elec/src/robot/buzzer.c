#include "buzzer.h"
#include "pinsRef.h"
#include <wiringPi.h>

void BUZZ_setup()
{
  pinMode(BUZZ, OUTPUT);
}

void BUZZ_loop()
{
  digitalWrite(BUZZ, HIGH);
  delayMicroseconds(500000);
  digitalWrite(BUZZ, LOW);
}

void BUZZ_ON()
{
  digitalWrite(BUZZ, HIGH);
}

void BUZZ_OFF()
{
  digitalWrite(BUZZ, LOW);
}