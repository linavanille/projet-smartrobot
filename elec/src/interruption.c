#include "ultrason.h"
#include <stdbool.h>
#include <wiringPi.h>

void STOP_loop(void (*interruption)(void), void (*activation)(void))
{
    bool actif = false;
    float dist;
    while (1)
    {
        dist = USON_obtenirDistance();
        if (actif && (dist < 10))
        {
            interruption();
            actif = false;
        }
        else if (!actif && (dist >= 10))
        {
            activation();
            actif = true;
        }
        delayMicroseconds(500);
    }
}