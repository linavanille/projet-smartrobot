#include "buzzer.h"
#include "pinsRef.h"
#include "wiringPi.h"

void BUZZ_setup()
{
  pinMode(BUZZ, OUTPUT);
}

void BUZZ_loop()
{
  digitalWrite(BUZZ, HIGH);
  delayMicroseconds(500);
  digitalWrite(BUZZ, LOW);
}