/**
 * @file evolutionRobot.h
 * @author Tom G.
 * @brief Module des mouvements du ROBOT
 *
 * @details Procédure permettant au robot d'évoluer au sein du labyrinthe
 */


#include <wiringPi.h>
#include <stdbool.h>
#include "motors.h"
#include "odres.h"
#include "pinsRef"


/**
 * @enum EtatDAvancement
 * @brief Enumération de situations potentielles du ROBOT
*/
typedef enum{Avancer, Intersection, Urgence, Sorti}ROBOT_EtatDAvancement;



/**
 * @fn void ROBOT_avancer(etat : *ROBOT_EtatDAvancement) 
 * @brief Procédure faisant suivre une ligne au ROBOT jusqu'à la prochaine intersection
 * @param etat Entrée/Sortie : etat dans lequel se trouve le robot. Est modifié au cours du programme
 * 
 * @details Utilise les fonctions booléenne SENS_estARedresserADroite et SENS_estARedresserAGauche pour savoir si le ROBOT dévie à gauche ou à droite (respectivement).
 * S'il faut redresser, appelle la fonction MTR_redresser pour remettre le capteur central sur la ligne.
 * 
 */

 void ROBOT_avancer(etat : *ROBOT_EtatDAvancement);

 /**
 * @fn void ROBOT_tourner(etat : *ROBOT_EtatDAvancement, prochaineAction : ORD_Ordre) 
 * @brief Procédure faisant tourner le ROBOT à une intersection
  *@param etat Entrée/Sortie : etat dans lequel se trouve le robot. Est modifié au cours du programme
 * @param prochaineAction Entrée : correspond à l'action que doit faire le ROBOT à cette intersection
 * (TD - TD - AV)
 * @details Selon la valeur de prochaineAction, peut faire tourner le robot à droite ou à gauche ou bien le faire continuer tout droit.
 * normalement renvoi etat = Avancer pour remettre le ROBOT en route. Sinon etat = Urgence le ROBOT s'arrête. 
 * 
 */

 void ROBOT_tourner(etat : *ROBOT_EtatDAvancement/*, prochaineAction : ORD_Ordre*/ );

 /**
 * @fn void ROBOT_urgence() 
 * @brief Procédure d'arrêt d'urgence du robot
 * 
 * @details 
 */

 void ROBOT_urgence();

/**
 * @fn void ROBOT_evolutionRobot(listeDOrdre : ) 
 * @brief Procédure faisant évoluer le ROBOT au sein du labyrinthe en suivant la liste d'Ordres
 * @param listeDOrdre Entrée : Suite d'instructions que doit suivre le ROBOT pour sortir du Labyrinthe.
 * 
 * @details Appelle les procédures ROBOT_avancer et ROBOT_tourner en fonction de la variable etat qui correspond à l'état d'avancement du ROBOT.
 * S'arrête lorsque le ROBOT est sorti du labyrinthe (etat = Sorti) 
 */

 void ROBOT_evolutionRobot(listeDOrdre : *ORD_ListeOrdres);