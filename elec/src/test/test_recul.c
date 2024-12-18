#include <wiringPi.h>
#include "motorsPi.h"
#include "pinsRef.h"

int main(){
	wiringPiSetupGpio();
	MTR_avancer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
	delayMicroseconds(100000);
	MTR_reculer(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);
	delayMicroseconds(3000000);
	MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
	return 0;
}
