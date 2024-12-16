#include <wiringPi.h>
#include <stdio.h>
#include "pinsRef.h"
#include "capteursLignes.h"


int main()
{
    wiringPiSetupGpio();
    CPTR_init(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT);
    while(1){
	if (CPTR_estSurLaLigne(CPTR_LIGNE_GAUCHE)){
	    printf(" G ");
	}
    	if (CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE)){
	    printf(" C ");
	}
    	if (CPTR_estSurLaLigne(CPTR_LIGNE_DROIT)){
	    printf(" D\n");
    	}
    	delayMicroseconds(500000);
    }
    return 0;
}

