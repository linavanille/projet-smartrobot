#include <stdio.h>
#include <wiringPi.h>
#include "../../include/pinsRef.h"
#include "../../include/initElec.h"
#include "../../include/lcd1602.h"
#include "../../include/motorsPi.h"
#include "../../include/capteursLignes.h"
#include "../../include/ultrason.h"
#include "../../include/buzzer.h"
#include "../../include/robot.h"


int main(){
    char bonjour[17] = "Bonjour";
    char vide[17] = "";
    char depart[17] = "LESS' GO !";
    char init2[17] = "Initialisation";
    char fin[17] = "finie !";

    initialisationGPIO();
    LCD_Write(bonjour, vide);
    delayMicroseconds(2000000);
    LCD_Write(init2, fin);
    delayMicroseconds(1500000);
    LCD_Write(depart, vide);
    delayMicroseconds(1500000);
    LCD_clear();

    ROBOT_evolutionRobot();

	return 0;
}
