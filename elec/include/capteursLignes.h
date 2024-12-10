/**
 * @file capteursLignes.h
 * @brief fonction d'utilisation des Capteurs de Ligne
 *
 */

#ifndef __CAPTEURS__
#define __CAPTEURS__

#include <stdbool.h>

/**
 * @fn void CPTR_init(int capteurCentre, int capteurGauche, int capteurDroit)
 * @brief Initialise les GPIO des capteurs
 * @param capteurCentre numéro du GPIO du capteur central
 * @param capteurGauche numéro du GPIO du capteur gauche
 * @param capteurDroit numéro du GPIO du capteur droit
 * 
 */
void CPTR_init(int capteurCentre, int capteurGauche, int capteurDroit);



/**
 * @fn bool CPTR_estSurLaLigne(int pinCapteur)
 * @brief Renvoie si le capteur est au dessus de la ligne ou pas
 * @param pinCapteur numéro du GPIO du capteur
 * 
 */

bool CPTR_estSurLaLigne(int pinCapteur);

/**
 * @fn bool CPTR_estSurUneIntersection(int capteurCentre, int capteurGauche, int capteurDroit)
 * @brief Renvoie si le capteur arrive à une intersection
 * @param capteurCentre numéro du GPIO du capteur central
 * @param capteurGauche numéro du GPIO du capteur gauche
 * @param capteurDroit numéro du GPIO du capteur droit
 * @details Une intersection correspond à une détection du capteur central et de l'un des deux autres capteurs.
 */

bool CPTR_estSurUneIntersection(int capteurCentre, int capteurGauche, int capteurDroit);

/**
 * @fn bool CPTR_estTropADroite(int capteurCentre, int capteurGauche, int capteurDroit)
 * @brief Renvoie si le capteur derive sur la droite de la ligne
 * @param capteurCentre numéro du GPIO du capteur central
 * @param capteurGauche numéro du GPIO du capteur gauche
 * @param capteurDroit numéro du GPIO du capteur droit
 * @details Une déviation correspond à une absence de détection du capteur central et d'une détection du capteur de gauche.
 *
 */

bool CPTR_estTropADroite(int capteurCentre, int capteurGauche, int capteurDroit);

/**
 * @fn bool CPTR_estTropAGauche(int capteurCentre, int capteurGauche, int capteurDroit)
 * @brief Renvoie si le capteur derive sur la gauche de la ligne
 * @param capteurCentre numéro du GPIO du capteur central
 * @param capteurGauche numéro du GPIO du capteur gauche
 * @param capteurDroit numéro du GPIO du capteur droit
 * @details Une déviation correspond à une absence de détection du capteur central et d'une détection du capteur de droite.
 *
 */

bool CPTR_estTropAGauche(int capteurCentre, int capteurGauche, int capteurDroit);

#endif