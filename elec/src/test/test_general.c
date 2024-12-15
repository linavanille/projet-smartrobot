#include <stdio.h>
#include <wiringPi.h>
#include "pinsRef.h"
#include "initElec.h"
#include "lcd1602.h"
#include "motorsPi.h"
#include "capteursLignes.h"
#include "ultrason.h"
#include "robot.h"

#ifndef TPS
#define TPS

#define TEMPS_REDRESSEMENT 100000

#endif

int main(){
	char bonjour[17] = "Bonjour";
    char vide[17] = "";
    char init[17] = "Initialisation...";
    char init2[17] = "Initialisation";
    char fin[17] = "finie !";

    LCD_Write(bonjour, vide);
    delayMicroseconds(2000000);
    LCD_Write(init, vide);
	initialisationGPIO();
    LCD_Write(init2, fin);

    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    if(CPTR_estTropAGauche(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

        while(!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
            MTR_redresser(PWM_EN2, PWM_EN1);
            if(USON_obtenirDistance()<=10){
                ROBOT_urgence();
            }
        }
        MTR_redresser(PWM_EN1, PWM_EN2);
        delayMicroseconds(TEMPS_REDRESSEMENT);
        MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    }
    else if(CPTR_estTropADroite(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

        while(!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
            MTR_redresser(PWM_EN1, PWM_EN2);
            if(USON_obtenirDistance()<=10){
                ROBOT_urgence();
            }
        }
        MTR_redresser(PWM_EN2, PWM_EN1);
        delayMicroseconds(TEMPS_REDRESSEMENT);
        MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    }
	return 0;
}
