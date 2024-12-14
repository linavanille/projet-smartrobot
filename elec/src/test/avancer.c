#include <wiringPi.h>
#include <sys/time.h>
#include <stdio.h>
#include "motorsPi.h"
#include "pinsRef.h"

int main()
{
    if (wiringPiSetupGpio() != 0)
    {
        printf("Mauvaise connection\n");
        return 1;
    }
    MTR_initialisationMoteur(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    digitalWrite(MOTEUR_IN1, HIGH);
    return 0;
}