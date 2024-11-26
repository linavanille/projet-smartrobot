/**
 * @file ordresRobot.h
 * @author Lina El Omari Bouya
 * @brief Structures et fonctions nécessaires au mouvement du robot
 */
 
#ifndef ORDRES_ROBOT_H
#define ORDRES_ROBOT_H 
#include <stdbool.h> 

/**
 * @struct Position
 * @brief Représente une position dans le labyrinthe
 */
typedef unsigned int Position;
} Position;
 
/**
 * @enum Orientation
 * @brief Représente la façon dont est orienté le robot par rapport au labyrinthe 
 */
typedef enum {Nord,Sud,Est,Ouest} Orientation; 

/**
 * @enum Ordre
 * @brief Représente les 3 types d'ordres que le robot peut exécuter 
 */
typedef enum {AV,TG,TD} Ordre;

//-------------------------------------------------------
//Fonctions de motricité (avancer, gauche, droite)
//-------------------------------------------------------

/**
 * @brief Fait avancer le robot depuis sa position actuelle jusqu'à la prochaine intersection ou virage en suivant sa direction actuelle
 * @param position La position actuelle du robot
 * @param orientation L'orientation actuelle du robot
 * @param casesAccessibles donne les cases accessibles pour chaque position
 * @return La nouvelle position du robot après avoir avancé.
 */
Position avancer(Position position, Orientation orientation, Position** casesAccessibles);

/**
 * @brief Change l'orientation actuelle du robot en tournant à gauche, puis fait avancer le robot
 * jusqu'à la prochaine intersection ou virage
 * @param position La position actuelle du robot
 * @param orientation L'orientation actuelle du robot
 * @param casesAccessibles donne les cases accessibles pour chaque position
 * @return La nouvelle position du robot après avoir tourné et avancé
 */
Position tournerGauche(Position position, Orientation* orientation, Position** casesAccessibles);

/**
 * @brief Change l'orientation actuelle du robot en tournant à droite, puis fait avancer le robot
 * jusqu'à la prochaine intersection ou virage
 * @param position La position actuelle du robot
 * @param orientation L'orientation actuelle du robot
 * @param casesAccessibles donne les cases accessibles pour chaque position
 * @return La nouvelle position du robot après avoir tourné et avancé
 */
Position tournerDroite(Position position, Orientation* orientation, Position** casesAccessibles);


//-------------------------------------------------------
//Fonctions d'initialisation et fonction principale 
//-------------------------------------------------------

/**
 * @brief Initialise la position et l'orientation de départ du robot
 * @return La position initiale du robot (entrée)
 * @param orientation L'orientation initiale du robot (modifiée par la fonction)
 */
Position initialiser(Orientation* orientation);

/**
 * @brief Génère une liste d'ordres pour sortir du labyrinthe à partir d'un chemin donné
 * @param chemin La liste des positions formant le chemin
 * @return Un tableau dynamique contenant les ordres nécessaires pour suivre le chemin
 */
Ordre* obtenirOrdres(Position* chemin);


//-------------------------------------------------------
//Fonctions de décision (quelle action à effectuer)
//-------------------------------------------------------

/**
 * @brief Calcule l'orientation nécessaire pour passer d'une case à une autre
 * @param caseActuelle La position actuelle
 * @param caseSuivante La position cible
 * @return L'orientation à adopter pour atteindre la case cible
 */
Orientation calculerOrientation(Position caseActuelle, Position caseSuivante);

/**
 * @brief Détermine si le robot doit tourner à gauche, à droite, ou continuer tout droit pour atteindre une orientation cible à partir de son orientation actuelle
 * @param orientationActuelle L'orientation actuelle du robot
 * @param orientationCible L'orientation que le robot doit atteindre
 * @return Ordre à effectuer 
 */
Ordre tournerVers(Orientation orientationActuelle, Orientation orientationCible);

#endif // ORDRES_ROBOT_H
