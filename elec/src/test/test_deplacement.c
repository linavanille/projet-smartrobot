#include <wiringPi.h>
#include <sys/time.h>
#include <stdio.h>
#include "motorsPi.h"
#include "pinsRef.h"

int main()
{
    int nb = 0;
    if (wiringPiSetupGpio() != 0)
    {
        printf("Mauvaise connection\n");
        return 1;
    }
    MTR_initialisationMoteur(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    printf("%d\n", nb++);
    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    printf("%d\n", nb++);
    delayMicroseconds(2000000);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    printf("%d\n", nb++);
    delayMicroseconds(2000000);
    MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    printf("%d\n", nb++);
    delayMicroseconds(2000000);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    printf("%d\n", nb++);
    delayMicroseconds(2000000);
    MTR_tournerGauche(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    printf("%d\n", nb++);
    delayMicroseconds(2000000);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    printf("%d\n", nb++);
    return 0;
}