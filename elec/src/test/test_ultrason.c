#include <wiringPi.h>
#include <stdio.h>
#include "../../include/ultrason.h"

int main(){
    while (1){
	if (wiringPiSetupGpio()==-1){
		return 1;
	}
	printf("Init done");
	USON_init();
        float d = USON_obtenirDistance();
        printf("%f", d);
        delayMicroseconds(3000000);
    }
}
