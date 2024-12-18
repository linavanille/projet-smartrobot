#include <stdlib.h>
#include <stdio.h>
#include <initElec.h>
#include "robot.h"

int main(int argc, char** argv){

    if(initialisationGPIO()==-1){
        printf("Erreur d'initialisation des GPIO\n");
        return EXIT_FAILURE;
    }
    
    ROBOT_evolutionRobot();
    return EXIT_SUCCESS; 
}