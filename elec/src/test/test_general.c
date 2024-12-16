#include <stdio.h>
#include <wiringPi.h>
#include "pinsRef.h"
#include "initElec.h"
#include "lcd1602.h"
#include "motorsPi.h"
#include "capteursLignes.h"
#include "ultrason.h"
#include "buzzer.h"
#include "robot.h"


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
