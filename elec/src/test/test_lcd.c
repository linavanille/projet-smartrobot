#include <wiringPi.h>
#include <stdio.h>
#include "lcd1602.h"
#include "buzzer.h"
#include <wiringPiI2C.h>

int main()
{
    wiringPiSetupGpio();
    LCD_Init();
    char texte1[17] = "Bonjour";
    char texte2[17] = "Wesh wesh";
    LCD_Write(texte1, texte2);
    printf("Tout s'est bien passé\n");
    return 0;
}
