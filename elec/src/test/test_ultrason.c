#include <wiringPi.h>
#include <stdio.h>
#include "ultrason.h"

int main(){
    printf("Début !\n");
	if (wiringPiSetupGpio()==-1){
		return 1;
    }
	printf("Init GPIO done\n");
	USON_init();
	printf("Init USON done\n");
    float d = USON_obtenirDistance();
    printf("%f\n", d);
    delayMicroseconds(3000000);
    return 0;
}
