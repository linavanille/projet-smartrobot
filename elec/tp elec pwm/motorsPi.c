#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void modifierMoteur(int A_1, int A_2, int A_3, int A_4, 
int val1, int val2, int val3, int val4)
{
	digitalWrite(A_1, val1);
	digitalWrite(A_2, val2);
	digitalWrite(A_3, val3);
	digitalWrite(A_4, val4);
}

void turnRight(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,1,0,1,0);
}

void turnLeft(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,1,0,1);
}

void avancer(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,1,0,0,1);
}

void reculer(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,1,1,0);
}

void arret(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,0,0,0);
}


void initialisation_PWM(int pwm0, int pwm1){

	pinMode(pwm0,PWM_OUTPUT);
	pinMode(pwm1,PWM_OUTPUT);
}

const frequence = 1024; 
void changerVitesse_PWM(int cycleD){

	int value = (frequence*cycleD)/100;

	pwmWrite(pwm0,value);
	pwmWrite(pwm1,value);

}

//SetUp les GPIO et met en OUTPUT tout ceux qui sont utilisés par le moteur
	//initialise egalement les PWM en les mettant par defaut à 50% de la sortie maximale
void initialisation_Moteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1){
	
	if(wiringPiSetupGpio() == -1){
		printf("Erreur d'initialisation\n");
	}
	else{

		pinMode(A_1,OUTPUT);
		pinMode(A_2,OUTPUT);
		pinMode(A_3,OUTPUT);
		pinMode(A_4,OUTPUT);
		
		arret(A_1, A_2, A_3, A_4); 

		initialisation_PWM(pwm0, pwm1);
		changerVitesse_PWM(50);
	}
}

/*
	int A_1 = 27;
	int A_2 = 17;
	int A_3 = 21;
	int A_4 = 20;
	int pwm0 = 18;
	int pwm1 = 13;
*/


