#include <wiringPi.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//====================================================
//Fonctions de motricité (droite, gauche, avant, arriere, stop)
void tournerDroite(int A_1, int A_2, int A_3, int A_4);
void tournerGauche(int A_1, int A_2, int A_3, int A_4);
void avancer(int A_1, int A_2, int A_3, int A_4);
//void reculer(int A_1, int A_2, int A_3, int A_4);
void stop(int A_1, int A_2, int A_3, int A_4);
//====================================================


//-----------------------------------------------------
//Fonctions d'initialisation des GPIO (normaux et PWM)
void initialisation_PWM(int pwm0, int pwm1); //contrôle de la vitesse des moteurs via PWM
void changerVitesse_PWM(int cycleD); //modifie duty cycle pour ajuste la vitesse des moteurs
void initialisation_Moteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1) //mise en lien des moteurs aux pins PWM
//-----------------------------------------------------
