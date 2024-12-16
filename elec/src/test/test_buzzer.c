#include <wiringPi.h>
#include <buzzer.h>
#include <stdio.h>
#include "pinsRef.h"

int main()
{
    if (wiringPiSetupGpio() != 0)
    {
        printf("Mauvaise connection\n");
        return 1;
    }
    BUZZ_setup();
    BUZZ_loop();
    return 0;
}