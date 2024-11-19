#include "buzzer.h"
#include "pinsRef.h"

void BUZZ_setup()
{
  pinMode(BUZZ, OUTPUT);
}

void BUZZ_loop()
{
  digitalWrite(BUZZ, HIGH);
  delay(3000);
  digitalWrite(BUZZ, LOW);
}