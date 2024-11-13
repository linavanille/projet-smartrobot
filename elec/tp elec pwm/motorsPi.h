#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//====================================================
//Fonctions de motricité (droite, gauche, avant, arriere, stop)

void turnRight(int A_1, int A_2, int A_3, int A_4);

void turnLeft(int A_1, int A_2, int A_3, int A_4);

void avancer(int A_1, int A_2, int A_3, int A_4);

void reculer(int A_1, int A_2, int A_3, int A_4);

void stop(int A_1, int A_2, int A_3, int A_4);
//====================================================


//-----------------------------------------------------
//Fonctions d'initialisation des GPIO (normaux et PWM)

void initialisation_PWM(int pwm0, int pwm1);

void changerVitesse_PWM(int cycleD);

void initialisation_Moteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1)

//-----------------------------------------------------
