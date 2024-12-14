#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>

#include "lcd1602.h"
#include "pinsRef.h"

#include <stdio.h>
#include <stdlib.h>

#define        AF_BASE              64
#define        AF_RS                (AF_BASE + 0)
#define        AF_RW                (AF_BASE + 1)
#define        AF_E                 (AF_BASE + 2)
#define        AF_LED               (AF_BASE + 3)

#define        AF_DB4               (AF_BASE + 4)
#define        AF_DB5               (AF_BASE + 5)
#define        AF_DB6               (AF_BASE + 6)
#define        AF_DB7               (AF_BASE + 7)

int lcdHandle;

int LCD_Init()
{
    int i; 
    pcf8574Setup(AF_BASE,0x27); //pcf8574 I2C address
    for(i=0;i<8;i++)
    {
        pinMode(AF_BASE+i,OUTPUT);
    }
    digitalWrite(AF_LED, HIGH);
    digitalWrite(AF_RW, LOW);
    lcdHandle = lcdInit(2, 16, 4, AF_RS, AF_E, AF_DB4, AF_DB5, AF_DB6, AF_DB7, 0,0,0,0);
    if (lcdHandle < 0)
    {
	printf("Erreur d'initiatlisation LCD\n");
	return EXIT_FAILURE; 
    }
    return EXIT_SUCCESS;
}

void LCD_Write(char arcLine1[17], char arcLine2[17])
{    
    lcdClear(lcdHandle);
    lcdPosition(lcdHandle, 0, 0);
    lcdPrintf(lcdHandle, arcLine1);
    lcdPosition(lcdHandle, 0, 1);
    lcdPrintf(lcdHandle, arcLine2);
}

void LCD_clear(int handle){
    lcdClear(handle);
}
