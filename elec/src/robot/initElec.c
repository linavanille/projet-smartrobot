#include <wiringPi.h>
#include "motorsPi.h"
#include "ultrason.h"
#include "lcd1602.h"
#include "capteursLignes.h"
#include "pinsRef.h"
#include "initElec.h"

int initialisationGPIO(){

    if(wiringPiSetupGpio() == -1){
        return -1;
	}

    CPTR_init(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT);                             //initialisation des capteurs

    MTR_initialisationMoteur(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);     //initialisation des Moteurs

    USON_init();                                                                                    //initialisation de l'emmetteur et du capteur d'US

    LCD_Init();                                                                                     //initialiation de l'ecran LCD

    return 1;
}
