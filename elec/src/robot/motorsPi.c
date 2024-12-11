#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _VITESSE_PWM_CYCLE_
#define _VITESSE_PWM_CYCLE_

#define AVANCER_GAUCHE		100
#define AVANCER_DROIT		100
#define TOURNER_INTERIEUR	90
#define TOURNER_EXTERIEUR	100
#define FREQUENCE           1024

#endif

//Note : le PWM0 correspondra à la roue gauche et le PWM1 à la roue droite

void MTR_initialisationPWM(int pwm0, int pwm1){

	pinMode(pwm0,PWM_OUTPUT);
	pinMode(pwm1,PWM_OUTPUT);
}


void MTR_changerVitessePWM(int pwm, int cycleD){

	int value = (FREQUENCE*cycleD)/100;

	pwmWrite(pwm,value);
}

void MTR_modifierMoteur(int A_1, int A_2, int A_3, int A_4, int val1, int val2, int val3, int val4)
{
	digitalWrite(A_1, val1);
	digitalWrite(A_2, val2);
	digitalWrite(A_3, val3);
	digitalWrite(A_4, val4);

}

void MTR_avancer(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1)
{
	MTR_changerVitessePWM(pwm0, AVANCER_GAUCHE);
	MTR_changerVitessePWM(pwm1, AVANCER_DROIT);
	
	MTR_modifierMoteur(A_1,A_2,A_3,A_4,1,0,0,1);
}

void MTR_arreter(int A_1, int A_2, int A_3, int A_4)
{
	MTR_modifierMoteur(A_1,A_2,A_3,A_4,0,0,0,0);
}


void MTR_tournerDroite(int A_1, int A_2, int A_3, int A_4)
{
	MTR_modifierMoteur(A_1,A_2,A_3,A_4,1,0,1,0);
}

void MTR_tournerGauche(int A_1, int A_2, int A_3, int A_4)
{
	MTR_modifierMoteur(A_1,A_2,A_3,A_4,0,1,0,1);
}

void MTR_redresser(int pwmInterieur, int pwmExterieur)
{
	MTR_changerVitessePWM(pwmInterieur, TOURNER_INTERIEUR);
	MTR_changerVitessePWM(pwmExterieur, TOURNER_EXTERIEUR);

}

//SetUp les GPIO et met en OUTPUT tout ceux qui sont utilisés par le moteur
	//initialise egalement les PWM en les mettant par defaut à 50% de la sortie maximale
void MTR_initialisationMoteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1){
	
	/*if(wiringPiSetupGpio() == -1){
		printf("Erreur d'initialisation\n");
	}
	else{*/

		pinMode(A_1,OUTPUT);
		pinMode(A_2,OUTPUT);
		pinMode(A_3,OUTPUT);
		pinMode(A_4,OUTPUT);
		
		MTR_arret(A_1, A_2, A_3, A_4); 

		MTR_initialisationPWM(pwm0, pwm1);
		MTR_changerVitessePWM(pwm0, 50);
		MTR_changerVitessePWM(pwm1, 50);
	//}
}


