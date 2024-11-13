#include "buzzer.h"
#include "pinref.h"

void BUZZ_setup()
{
  pinMode(BUZZ_Pin, OUTPUT);
}

void BUZZ_loop()
{
  digitalWrite(BUZZ_Pin, HIGH);
  delay(3000);
  digitalWrite(BUZZ_Pin, LOW);
}