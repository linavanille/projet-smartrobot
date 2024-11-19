/**
 * @file evolutionRobot.h
 * @author Tom G.
 * @brief Module des mouvements du ROBOT
 *
 * @details Procédure permettant au robot d'évoluer au sein du labyrinthe
 */


#include <wiringPi.h>
#include <stdbool.h>
#include "pinsRef"


/**
 * @enum EtatDAvancement
 * @brief Enumération de situations potentielles du ROBOT
*/
typedef enum{Avancer, Intersection, Urgence, Sorti}ROBOT_EtatDAvancement;



/**
 * @fn void ROBOT_avancer(etat : *ROBOT_EtatDAvancement) 
 * @brief procédure faisant suivre une ligne au ROBOT jusqu'à la prochaine intersection
 * @param etat Entrée Sortie : etat dans lequel se trouve le robot. Est modifié au cours du programme
 * 
 * @details Utilise les fonctions booléenne SENS_estARedresserADroite et SENS_estARedresserAGauche pour savoir si le ROBOT dévie à gauche ou à droite (respectivement)
 * S'il faut redresser, appelle la fonction MTR_redresser pour remettre le capteur central sur la ligne
 * 
 */

 void ROBOT_avancer(etat : *EtatDAvancement);

 /**
 * @fn void ROBOT_tourner(etat : *ROBOT_EtatDAvancement, prochaineAction : ORDRE_Ordre) 
 * @brief procédure faisant tourner le ROBOT à une intersection
 * @param etat etat dans lequel se trouve le robot
 * 
 */

 void ROBOT_tourner(etat : *EtatDAvancement);