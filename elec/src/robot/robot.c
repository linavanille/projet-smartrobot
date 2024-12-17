#include <wiringPi.h>
#include <stdbool.h>
#include <stdio.h>
#include "interruption.h"
#include "buzzer.h"
#include "ultrason.h"
#include "lcd1602.h"
#include "capteursLignes.h"
#include "motorsPi.h"
#include "pinsRef.h"
#include "robot.h"

#ifndef __TEMPS__
#define __TEMPS__

#define TEMPS_ATTENTE           200000      //temps d'attente en ms du début du virage 
#define TEMPS_VIRAGE            100         //temps en ms d'un virage
#define TEMPS_ARRIVE_INTER      700000      //temps d'attente en ms pour mettre le point de pivot à l'intersection

#endif

void ROBOT_avancer(ROBOT_EtatDAvancement* etat){
    bool estSurInter = false;
    /*char vide[17] = "";
    char sens[17] = "        ";
    int nb = 0;*/
    MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
    while(!estSurInter){
        //estSurInter = CPTR_estSurUneIntersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT);
        /*if (USON_obtenirDistance()<=10){
                    ROBOT_urgence();
                }*/
        if(CPTR_estTropAGauche(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

            while(!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
                MTR_redresser(PWM_EN2, PWM_EN1);
                // if(USON_obtenirDistance()<=10){
                //     ROBOT_urgence();
                // }
            }
           MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        if(CPTR_estTropADroite(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){

            while(!CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
                MTR_redresser(PWM_EN1, PWM_EN2);
                // if(USON_obtenirDistance()<=10){
                //     ROBOT_urgence();
                // }
            }
            MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
        }
        if (CPTR_estSurUneIntersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
            delayMicroseconds(TEMPS_ARRIVE_INTER);
            MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
            estSurInter = true; 
        }
    }
    *etat = Intersection;
    print("*etat = Intersection;");
}

void ROBOT_intersection(ROBOT_EtatDAvancement* etat, char* prochaineAction){
    switch(prochaineAction[1]){
        case 'D':
            MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
            delayMicroseconds(TEMPS_ATTENTE);
            while(!CPTR_estSurLaLigne(CPTR_LIGNE_DROIT)){
                delayMicroseconds(TEMPS_VIRAGE);
            }
            break;
        case 'G' :

            MTR_tournerGauche(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
            delayMicroseconds(TEMPS_VIRAGE);
            while(!CPTR_estSurLaLigne(CPTR_LIGNE_GAUCHE)){
                delayMicroseconds(TEMPS_VIRAGE);
            }
            break; 
            
        case 'V' :
            *etat = Avancer;
            break;
        default :
            *etat = Sorti;
            break;
    }
}

void ROBOT_urgence(){
    float dist;
    char texte1[17] = "Interruption";
    char texte2[17]= "Obstacle !";


    dist = USON_obtenirDistance();
    while (dist<=10)
    {
        BUZZ_loop();
        MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
        LCD_Write(texte1, texte2);
        dist = USON_obtenirDistance();
        delayMicroseconds(200000);
    }
    BUZZ_OFF();
    LCD_clear();
}

void ROBOT_evolutionRobot()
{
    char prochaineAction[17];
    char sorti[17]="Sorti !";
    char gruik[17] = "GRUIK !";
    	
    ROBOT_EtatDAvancement etat = Avancer;
    
    while(prochaineAction[0] != '.'){
        scanf("%s", prochaineAction);
        if(prochaineAction[0] == 'E'){
            scanf("%s", prochaineAction);
        }
	    LCD_Write(prochaineAction, gruik);
        switch(etat){
            case Avancer :
                ROBOT_avancer(&etat);
                break;
            case Intersection :
                ROBOT_intersection(&etat, prochaineAction);
                break;
            case Sorti :
		        LCD_Write(sorti, gruik);
                MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
                delayMicroseconds(2000);
                MTR_tournerDroite(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                for(int i=1; i<=3; i++){
                    BUZZ_loop();
                }
                MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
                break;
            default :
                ROBOT_urgence();
                break;
        }
    }
    LCD_Write(sorti, gruik);
    MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    delayMicroseconds(3000000);
    LCD_clear();
}
