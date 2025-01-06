#include <stdio.h>
#include "initElec.h"


int main(){
	
	printf("Debut de l'initialisation...\n");
	initialisationGPIO();
	printf("Tout s'est bien passé\n");
	return 0;
}
