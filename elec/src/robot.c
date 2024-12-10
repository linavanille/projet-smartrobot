#include <wiringPi.h>
#include <stdbool.h>
#include "interruption.h"
#include "lcd1602.h"
#include "buzzer.h"
#include "ultrason.h"
#include "motorsPi.h"
#include "pinsRef.h"
#include "robot.h"

#ifndef __TEMPS__
#define __TEMPS__

#define TEMPS_REDRESSEMENT      250       //temps en ms pour remetrre le robot droit après redressement
#define TEMPS_VIRAGE            500      //temps en ms d'un virage

#endif

void ROBOT_avancer(ROBOT_EtatDAvancement* etat){
    while(!SENS_intersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT) && etat != Urgence){
        MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        if(SENS_redresserADroite(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

            while(digitalRead(CPTR_LIGNE_CENTRE)==0){
                MTR_redresser(PWM_EN2, PWM_EN1);
                /*if(USON_obtenirDistance()<=10){
                    ROBOT_urgence();
                }*/
            }
           MTR_redresser(PWM_EN1, PWM_EN2);
           delayMicroseconds(TEMPS_REDRESSEMENT);
           MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        else if(SENS_redresserAGauche(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

            while(digitalRead(CPTR_LIGNE_CENTRE)==0){
                MTR_redresser(PWM_EN1, PWM_EN2);
                /*if(USON_obtenirDistance()<=10){
                    ROBOT_urgence();
                }*/
            }
            MTR_redresser(PWM_EN2, PWM_EN1);
            delayMicroseconds(TEMPS_REDRESSEMENT);
            MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        *etat = Intersection; 
    }
}

void ROBOT_intersection(ROBOT_EtatDAvancement* etat, ORD_Ordre prochaineAction){
    switch(prochaineAction){
        case TD:

            do{
                MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                delayMicroseconds(TEMPS_VIRAGE);
            }while(digitalRead(CPTR_LIGNE_CENTRE)!=1);

            break;
        case TG :

            do{
                MTR_tournerGauche(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                delayMicroseconds(TEMPS_VIRAGE);
            }while(digitalRead(CPTR_LIGNE_CENTRE)!=1);

        case AV :
            *etat = Avancer;
            break;
        default :
            *etat = Sorti;
            break;
    }
}

void ROBOT_urgence(){
    float dist;
    BUZZ_ON();

    dist = USON_obtenirDistance();
    while (dist<=10)
    {
        MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
        LCD_Write("Attention", "Obstacle");
        dist = USON_obtenirDistance();
        delayMicroseconds(500);
    }

    BUZZ_OFF();
}

void ROBOT_evolutionRobot(ORD_Ordre* listeDOrdre){

    ORD_Ordre prochaineAction;
    ROBOT_EtatDAvancement etat = Avancer;
    int numOrdre = 1;

    prochaineAction = ORD_iemeOrdre(listeDOrdre, numOrdre);

    while(etat!=Sorti && prochaineAction != FIN){
        switch(etat){
            case Avancer :
                ROBOT_avancer(&etat);
                break;
            case Intersection :
                ROBOT_intersection(&etat, prochaineAction);
                break;
            case Urgence :
                ROBOT_urgence();
                break;
            case Sorti :
                MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
                delayMicroseconds(2000);
                MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                for(int i=1; i<=3; i++){
                    BUZZ_loop();
                }
                MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                break;
        }
    }
}