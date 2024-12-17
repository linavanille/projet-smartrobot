#include <wiringPi.h>
#include <stdio.h>
#include "pinsRef.h"
#include "capteursLignes.h"
#include "buzzer.h"
#include "lcd1602.h"

int main()
{
    char vide[17] = "";
    char inter[17] = "INTER";
    char sens[17] = "        ";
    char *res;
    wiringPiSetupGpio();
    LCD_Init();
    LCD_clear();
    CPTR_init(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT);
    while(1){
        if (CPTR_estSurUneIntersection(CPTR_LIGNE_CENTRE, CPTR_LIGNE_GAUCHE, CPTR_LIGNE_DROIT)){
            res = inter;
            // BUZZ_loop();
        }
        else
        {
            res = vide;
        }
        if (CPTR_estSurLaLigne(CPTR_LIGNE_GAUCHE))
        {
            sens[0] = 'G';
            sens[1] = 'a';
        }
        else
        {
            sens[0] = ' ';
            sens[1] = ' ';
        }
        if (CPTR_estSurLaLigne(CPTR_LIGNE_CENTRE))
        {
            sens[3] = 'C';
            sens[4] = 'e';
        }
        else
        {
            sens[3] = ' ';
            sens[4] = ' ';
        }
        if (CPTR_estSurLaLigne(CPTR_LIGNE_DROIT))
        {
            sens[6] = 'D';
            sens[7] = 'r';
        }
        else
        {
            sens[6] = ' ';
            sens[7] = ' ';
        }
        LCD_Write(sens, res);
    	delayMicroseconds(500000);
    }
    return 0;
}

