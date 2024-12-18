#include <wiringPi.h>
#include <sys/time.h>
#include <stdio.h>
#include "motorsPi.h"
#include "pinsRef.h"
#include "robot.h"
#include "capteursLignes.h"
#include "lcd1602.h"

int main()
{
    int nb = 0;
    if (wiringPiSetupGpio() != 0)
    {
        printf("Mauvaise connection\n");
        return 1;
    }
    printf("%d, %d\n", PWM_EN1, PWM_EN2);
    LCD_Init();
    MTR_initialisationMoteur(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4, PWM_EN1, PWM_EN2);

    char texte1[17] = "Trouve";
    char texte2[17]= "";
    LCD_Write(texte2, texte2);
    ROBOT_EtatDAvancement etat = Avancer;
    ROBOT_avancer(&etat);
    if (etat==Intersection)
    {
        LCD_Write(texte1, texte2);
        printf("Trouvé !\n");
        MTR_arreter(MOTEUR_IN1, MOTEUR_IN2, MOTEUR_IN3, MOTEUR_IN4);
    }
    return 0;
}
