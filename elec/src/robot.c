#include "wiringPi.h"
#include <stdbool.h>
#include "motorsPi.h"
#include "ordresRobot.h"
#include "interruption.h"
#include "lcd1602.h"
#include "buzzer.h"
#include "pinsRef.h"

#ifndef __TEMPS__
#define __TEMPS__

#define TEMPS_REDRESSEMENT      250       //temps en ms pour remetrre le robot droit après redressement
#define TEMPS_VIRAGE            1000      //temps en ms d'un virage

#endif

typedef enum{Avancer, Intersection, Urgence, Sorti}ROBOT_EtatDAvancement;

void ROBOT_avancer(etat : *ROBOT_EtatDAvancement){
    while(!SENS_intersection(LINE_SENSOR_FRONT, LINE_SENSOR_LEFT, LINE_SENSOR_RIGHT) && etat != Urgence){
        MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        if(SENS_redresserADroite(LINE_SENSOR_FRONT, LINE_SENSOR_LEFT, LINE_SENSOR_RIGHT)){
            MTR_redresser(PWM_EN2, PWM_EN1);
            /*do{
                if(USON_obtenirDistance()<=10){
                    ROBOT_urgence();
                }(digitalRead(LINE_SENSOR_FRONT) == 1)
            }*/
           MTR_redresser(PWM_EN1, PWM_EN2);
           delayMicroseconds(TEMPS_REDRESSEMENT);
           MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        else if(SENS_redresserAGauche(LINE_SENSOR_FRONT, LINE_SENSOR_LEFT, LINE_SENSOR_RIGHT)){
            MTR_redresser(PWM_EN1, PWM_EN2);
            /*do{
                if(USON_obtenirDistance()<=10){
                    ROBOT_urgence();
                }(digitalRead(LINE_SENSOR_FRONT) == 1)
            }*/
           MTR_redresser(PWM_EN2, PWM_EN1);
           delayMicroseconds(TEMPS_REDRESSEMENT);
           MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        etat = Intersection; 
    }
}

void ROBOT_intersection(etat : *ROBOT_EtatDAvancement, prochaineAction : ORD_Ordre){
    switch(prochaineAction){
        case TD:
            MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
            delayMicroseconds(TEMPS_VIRAGE);
            break;
        case TG :
            MTR_tournerGauche(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
            delayMicroseconds(TEMPS_VIRAGE);
            break;
        case AV :
            etat = Avancer;
            break;
        default :
            etat = Sorti;
            break;
    }
}

void ROBOT_urgence(){
    BUZZ_ON(); 
    STOP_loop();
    BUZZ_OFF();
}

void ROBOT_evolutionRobot(listeDOrdre : *ORD_ListeOrdres){

    ORD_Ordre prochaineAction;
    ROBOT_EtatDAvancement etat = Avancer;
    int numOrdre = 1;

    prochaineAction = ORD_obtenirIemeOrdre(listeDOrdre, numOrdre);

    while(etat!=Sorti && prochaineAction != .){
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


void main(){


    return(EXIT_SUCCESS)
}