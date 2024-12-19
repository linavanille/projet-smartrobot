#include <stdlib.h>
#include <stdio.h>
#include "wiringPi.h"
#include "initElec.h"
#include "robot.h"
#include "lcd1602.h"

int main(int argc, char** argv){

    if(initialisationGPIO()==-1)
    {
        printf("Erreur d'initialisation des GPIO\n");
        return EXIT_FAILURE;
    }

    char init2[17] = "Initialisation";
    char fin[17] = "finie !";
    LCD_Write(init2, fin);
    delayMicroseconds(1500000);
    LCD_clear();
    ROBOT_evolutionRobot();
    return EXIT_SUCCESS; 
}