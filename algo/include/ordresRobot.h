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

//-------------------------------------------------------
// Fonctions de motricité (avancer, gauche, droite)
//-------------------------------------------------------

ORD_Position* ORD_avancer(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

/**
 * @brief Change l'orientation actuelle du robot en tournant à gauche, puis fait avancer le robot
 * jusqu'à la prochaine intersection ou virage
 * @param position La position actuelle du robot
 * @param orientation L'orientation actuelle du robot
 * @param casesAccessibles donne les cases accessibles pour chaque position
 * @return La nouvelle position du robot après avoir tourné et avancé
 */
ORD_Position* ORD_tournerGauche(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

/**
 * @brief Change l'orientation actuelle du robot en tournant à droite, puis fait avancer le robot
 * jusqu'à la prochaine intersection ou virage
 * @param position La position actuelle du robot
 * @param orientation L'orientation actuelle du robot
 * @param casesAccessibles donne les cases accessibles pour chaque position
 * @return La nouvelle position du robot après avoir tourné et avancé
 */
ORD_Position* ORD_tournerDroite(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

//-------------------------------------------------------
// Fonction d'initialisation
//-------------------------------------------------------

/**
 * @brief Initialise la position et l'orientation de départ du robot
 * @return La position initiale du robot (entrée)
 * @param orientation L'orientation initiale du robot (modifiée par la fonction)
 */
ORD_Position* ORD_initialisation(LAB_Labyrinthe* labyrinthe, ORD_Orientation* orientation);

//-------------------------------------------------------
// Fonctions de décision
//-------------------------------------------------------

/**
 * @brief Calcule l'orientation nécessaire pour passer d'une case à une autre
 * @param caseActuelle La position actuelle
 * @param caseSuivante La position cible
 * @return L'orientation à adopter pour atteindre la case cible
 */
ORD_Orientation ORD_calculerOrientation(ORD_Position* caseActuelle, ORD_Position* caseSuivante, unsigned int largeurLabyrinthe);

//-------------------------------------------------------
// Fonctions de vérification (cases accessibles et 
// gestion des intersections et virages)
//-------------------------------------------------------

/**
 * @brief Vérifie si une case est une intersection
 * @param posiiton Case à vérifier
 * @param labyrinthe Contenant les informations sur les cases du labyrinthe (casesAccessibles par exemple)
 * @return vrai si c'est une intersection, faux sinon
 */
bool ORD_estIntersection(ORD_Position* position, LAB_Labyrinthe* labyrinthe);

 /**
 * @brief Vérifie si une case est un virage
 * @param position Case à vérifier
 * @param labyrinthe Contenant les informations sur les cases du labyrinthe (casesAccessibles par exemple)
 * @param largeurLabyrinthe La largeur du labyrinthe
 * @return vrai si c'est un virage, faux sinon
 */
bool ORD_estVirage(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe);

bool estAccessible(ORD_Position* positionActuelle, ORD_Position* positionVoisine);

//-------------------------------------------------------
// Fonction principale
//-------------------------------------------------------

/**
 * @brief Génère une liste d'ordres pour sortir du labyrinthe à partir d'un chemin donné
 * @param chemin La liste des positions formant le chemin
 * @return Un tableau dynamique contenant les ordres nécessaires pour suivre le chemin
 */
ORD_Ordre* ORD_obtenirOrdres(ORD_Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe);


#endif // ORDRES_ROBOT_H
