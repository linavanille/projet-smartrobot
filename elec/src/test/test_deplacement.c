#include <wiringPi.h>
#include <sys/time.h>
#include <stdio.h>
#include "motorsPi.h"
#include "pinsRef.h"
#include "robot.h"
#include "capteursLignes.h"
#include "lcd1602.h"

int main()
{
    int nb = 0;
    if (wiringPiSetupGpio() != 0)
    {
        printf("Mauvaise connection\n");
        return 1;
    }
    printf("%d, %d\n", PWM_EN1, PWM_EN2);
    LCD_Init();
    MTR_initialisationMoteur(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    delayMicroseconds(1000000);
    MTR_changerVitessePWM(PWM_EN1, 0);
    delayMicroseconds(3000000);
    MTR_changerVitessePWM(PWM_EN2, 0);
    delayMicroseconds(3000000);
    MTR_changerVitessePWM(PWM_EN1, 100);    
    delayMicroseconds(3000000);
    MTR_changerVitessePWM(PWM_EN2, 100);
    delayMicroseconds(1000000);
    ROBOT_avancer(Avancer);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    return 0;
}
