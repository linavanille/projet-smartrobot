/**
 * @file ordresRobot.h
 * @author Lina El Omari Bouya
 * @brief Structures et fonctions nécessaires au mouvement du robot
 */
 
#ifndef ORDRES_ROBOT_H
#define ORDRES_ROBOT_H 
#include <stdbool.h> 
#include "labyrinthe.h"
#include "case.h"

/**
 * @struct Position
 * @brief Représente une position dans le labyrinthe
 */
typedef CASE_Case Position;
 
/**
 * @enum Orientation
 * @brief Représente la façon dont est orienté le robot par rapport au labyrinthe 
 */
typedef enum {Nord,Sud,Est,Ouest,Invalide} Orientation; 

/**
 * @enum Ordre
 * @brief Représente les 3 types d'ordres que le robot peut exécuter 
 */
typedef enum {AV,TG,TD} Ordre;

/**
 * @struct Liste
 * @brief Représente une liste de cases
 */
typedef struct Liste {
	Position** cases;  
	unsigned int taille;  
} Liste;

Position* ORD_avancer(Position* position, Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

Position* ORD_tournerGauche(Position* position, Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

Position* ORD_tournerDroite(Position* position, Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

Position* ORD_initialisation(LAB_Labyrinthe* labyrinthe, Orientation* orientation);

Orientation ORD_calculerOrientation(Position* caseActuelle, Position* caseSuivante, unsigned int largeurLabyrinthe);

bool ORD_estIntersection(Position* position, LAB_Labyrinthe* labyrinthe);

bool ORD_estVirage(Position* position, Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

Ordre* ORD_obtenirOrdres(Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe);

bool estAccessible(Position* positionActuelle, Position* positionVoisine);

#endif // ORDRES_ROBOT_H
