#include <wiringPi.h>
#include <sys/time.h>
#include <stdio.h>
#include "robot.h"
#include "initElec.h"
#include "motorsPi.h"
#include "pinsRef.h"

int main()
{
    if(initialisationGPIO()==-1)
    {
        printf("Erreur d'initialisation des GPIO\n");
        return 1;
    }
    ROBOT_EtatDAvancement etat = Avancer;
    ROBOT_avancer(&etat);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    return 0;
}
