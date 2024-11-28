/**
 * @file evolutionRobot.h
 * @brief Module des mouvements du ROBOT
 *
 * @details Procédures permettant au robot d'évoluer au sein du labyrinthe
 */


#include <wiringPi.h>
#include <stdbool.h>
#include "motorsPi.h"
#include "ordresRobot.h"
#include "interruption.h"
#include "lcd1602.h"
#include "buzzer.h"
#include "pinsRef.h"


/**
 * @enum EtatDAvancement
 * @brief Enumération de situations potentielles du ROBOT
 */

typedef enum{Avancer, Intersection, Urgence, Sorti}ROBOT_EtatDAvancement;



/**
 * @fn void ROBOT_avancer(etat : *ROBOT_EtatDAvancement) 
 * @brief Faire suivre une ligne au ROBOT jusqu'à la prochaine intersection
 * @param etat Etat dans lequel se trouve le robot. Est modifié au cours du programme
 * 
 * @details Utilise les fonctions booléenne SENS_estARedresserADroite et SENS_estARedresserAGauche pour savoir si le ROBOT dévie à gauche ou à droite (respectivement).
 * S'il faut redresser, appelle la fonction MTR_redresser pour remettre le capteur central sur la ligne.
 * 
 */

void ROBOT_avancer(etat : *ROBOT_EtatDAvancement);

/**
 * @fn void ROBOT_intersection(etat : *ROBOT_EtatDAvancement, prochaineAction : ORD_Ordre) 
 * @brief Faire choisir une direction au ROBOT à une intersection
 * @param etat etat dans lequel se trouve le robot. Est modifié au cours du programme
 * @param prochaineAction Action que doit faire le ROBOT à cette intersection
 * @details Selon la valeur de prochaineAction, peut faire tourner le robot à droite ou à gauche ou bien le faire continuer tout droit.
 * Normalement renvoi etat = Avancer pour remettre le ROBOT en route. Sinon etat = Urgence le ROBOT s'arrête. 
 * 
 */

void ROBOT_intersection(etat : *ROBOT_EtatDAvancement, prochaineAction : ORD_Ordre);

/**
 * @fn void ROBOT_urgence() 
 * @brief Arrêter d'urgence le ROBOT
 * @param
 * @details Arrête le ROBOT en présence d'obstacle jusqu'à l'absence d'obstacle
 */

void ROBOT_urgence();

/**
 * @fn void ROBOT_evolutionRobot(listeDOrdre : *ORD_ListeOrdres) 
 * @brief Faire évoluer le ROBOT au sein du labyrinthe en suivant la liste d'Ordres.
 * @param listeDOrdre Suite d'instructions que doit suivre le ROBOT pour sortir du Labyrinthe.
 * 
 * @details Appelle les procédures ROBOT_avancer et ROBOT_intersection en fonction de la variable etat qui correspond à l'état d'avancement du ROBOT.
 * S'arrête lorsque le ROBOT est sorti du labyrinthe (etat = Sorti) 
 * 
 */

void ROBOT_evolutionRobot(listeDOrdre : *ORD_ListeOrdres);