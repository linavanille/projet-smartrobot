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
 * @struct ORD_Position
 * @brief Représente une position dans le labyrinthe
 */
typedef CASE_Case ORD_Position;
 
/**
 * @enum ORD_Orientation
 * @brief Représente la façon dont est orienté le robot par rapport au labyrinthe 
 */
typedef enum {Nord,Sud,Est,Ouest,Invalide} ORD_Orientation; 

/**
 * @enum ORD_Ordre
 * @brief Représente les 3 types d'ordres que le robot peut exécuter 
 */
typedef enum {AV,TG,TD} ORD_Ordre;

/**
 * @struct Liste
 * @brief Représente une liste de cases
 */
typedef struct Liste {
	ORD_Position** cases;  
	unsigned int taille;  
} Liste;

ORD_Position* ORD_avancer(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

ORD_Position* ORD_tournerGauche(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

ORD_Position* ORD_tournerDroite(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

ORD_Position* ORD_initialisation(LAB_Labyrinthe* labyrinthe, ORD_Orientation* orientation);

ORD_Orientation ORD_calculerOrientation(ORD_Position* caseActuelle, ORD_Position* caseSuivante, unsigned int largeurLabyrinthe);

bool ORD_estIntersection(ORD_Position* position, LAB_Labyrinthe* labyrinthe);

bool ORD_estVirage(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

ORD_Ordre* ORD_obtenirOrdres(ORD_Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe);

bool estAccessible(ORD_Position* positionActuelle, ORD_Position* positionVoisine);

#endif // ORDRES_ROBOT_H
