#include <wiringPi.h>
#include <stdio.h>
#include "pinsRef.h"
#include "capteursLignes.h"
#include "buzzer.h"

int main()
{
    wiringPiSetupGpio();
    CPTR_init(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT);
    while(1){
	if (CPTR_estSurUneIntersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
		BUZZ_loop();
	}
    	delayMicroseconds(500000);
    }
    return 0;
}

