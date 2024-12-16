#include <stdio.h>
#include <wiringPi.h>
#include "pinsRef.h"
#include "initElec.h"
#include "lcd1602.h"
#include "motorsPi.h"
#include "capteursLignes.h"
#include "ultrason.h"
#include "buzzer.h"
#include "robot.h"

#ifndef TPS
#define TPS

#define TEMPS_REDRESSEMENT 100000

#endif

int main(){
    char bonjour[17] = "Bonjour";
    char vide[17] = "";
    char depart[17] = "LESS' GO !";
    char init2[17] = "Initialisation";
    char fin[17] = "finie !";

    initialisationGPIO();
    LCD_Write(bonjour, vide);
    delayMicroseconds(2000000);
    LCD_Write(init2, fin);
    delayMicroseconds(1500000);
    LCD_Write(depart, vide);
    delayMicroseconds(1500000);
    LCD_clear();

    while(1){
    	MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    	if(CPTR_estTropAGauche(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
	    while (!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
	    	MTR_redresser(PWM_EN2, PWM_EN1);
	    }
	    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    	}
    	if(CPTR_estTropADroite(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
	    while (!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
		MTR_redresser(PWM_EN1, PWM_EN2);
	    }
	    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
	}
	if (CPTR_estSurUneIntersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
	    delayMicroseconds(750000);
	    MTR_tournerGauche(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
	    delayMicroseconds(200000);
	    while (!CPTR_estSurLaLigne(CPTR_LIGNE_GAUCHE)){
		    delayMicroseconds(100);
	    }
	    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
	    break;
	}
    }
	return 0;
}
