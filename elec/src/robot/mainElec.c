#include <stdlib.h>
#include <stdio.h>
#include <initElec.h>
#include "robot.h"

int main(int argc, char** argv){
    ORD_Ordre* listeDOrdre; 

    if(initialisationGPIO()==-1){
        printf("Erreur d'initialisation des GPIO\n");
        return EXIT_FAILURE;
    }
    //recuperation de la liste d'Ordre
    ROBOT_evolutionRobot(listeDOrdre);
    return EXIT_SUCCESS; 
}