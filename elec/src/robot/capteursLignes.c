#include <wiringPi.h>
#include <stdbool.h>

void CPTR_init(int capteurCentre, int capteurGauche, int capteurDroit){
    pinMode(capteurCentre, INPUT);                                                               //initialisation des Capteurs
    pinMode(capteurGauche, INPUT); 
    pinMode(capteurDroit, INPUT);
}

bool CPTR_estSurLaLigne(int pinCapteur)
{
    int signal = digitalRead(pinCapteur);
    
    if(signal == LOW){
        return false;
    }
    else{
        return true;
    }
}

bool CPTR_estSurUneIntersection(int capteurCentre, int capteurGauche, int capteurDroit)
{
    return (CPTR_estSurLaLigne(capteurCentre) && (CPTR_estSurLaLigne(capteurGauche) || CPTR_estSurLaLigne(capteurDroit)));
}

bool CPTR_estTropADroite(int capteurCentre, int capteurGauche, int capteurDroit)
{
    return (!CPTR_estSurLaLigne(capteurCentre) && CPTR_estSurLaLigne(capteurGauche) && !CPTR_estSurLaLigne(capteurDroit));
}

bool CPTR_estTropAGauche(int capteurCentre, int capteurGauche, int capteurDroit)
{
    return (!CPTR_estSurLaLigne(capteurCentre) && !CPTR_estSurLaLigne(capteurGauche) && CPTR_estSurLaLigne(capteurDroit));
}
