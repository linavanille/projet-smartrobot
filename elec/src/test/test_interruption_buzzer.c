#include "buzzer.h"
#include "ultrason.h"
// #include "interruption.h"
#include <wiringPi.h>
#include <stdbool.h>
#include <stdio.h>

void STOP_loop()
{
    static bool actif = false;
    float dist;
    dist = USON_obtenirDistance();
    printf("%f\n", dist);
    if (actif && (dist < 10))
    {
        printf("Interruption\n");
        actif = false;
    }
    else if (!actif && (dist >= 10))
    {
        printf("Activation\n");
        actif = true;
    }
}

int main()
{
    wiringPiSetupGpio();
    BUZZ_setup();
    USON_init();
    while (1)
    {
        STOP_loop();
        delayMicroseconds(500000);
    }
    return 0;
}