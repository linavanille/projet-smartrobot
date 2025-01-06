/**
 * @file labyrinthe.h
 * @brief Implémantation du TAD LAB_Labyrinthe
 */

#ifndef __LABYRINTHE__
#define __LABYRINTHE__
#include "case.h"

typedef unsigned int uint;

typedef struct {
    CASE_Case *lesConnections;
    char* entree;
    char* sortie;
    unsigned int largeur;
} LAB_Labyrinthe;

/**
* @brief Crée un labyrinthe.
* @return un labyrinthe
* @param l La largeur du labyrinthe
* @param entree L'entrée du labyrinthe
* @param sortie La sortie du labyrinthe
*/
LAB_Labyrinthe LAB_creerLabyrinthe(uint l, char* entree, char* sortie);

/**
* @brief Obtenir la liste des cases accessibles d'une case 
* @param labyrinthe le labyrinthe
* @param c une case
* @return liste de cases accessibles
*/
CASE_Case *LAB_obtenirCasesAccessibles(LAB_Labyrinthe lab, CASE_Case c);

/**
* @brief Obtenir la case entrée d'un labyrinthe
* @param labyrinthe un labyrinthe
* @return la case d'entrée
*/
CASE_Case* LAB_obtenirEntree(LAB_Labyrinthe* labyrinthe);

/**
* @brief Obtenir la case sortie d'un labyrinthe
* @param labyrinthe un labyrinthe
* @return la case de sortie
*/
CASE_Case* LAB_obtenirSortie(LAB_Labyrinthe* labyrinthe);

/**
* @brief Obtenir la largeur d'un labyrinthe
* @param labyrinthe un labyrinthe
* @return la largeur
*/
unsigned int LAB_obtenirLargeur(LAB_Labyrinthe* labyrinthe);

/**
* @brief Obtenir la ième case d'un labyrinthe
* @param labyrinthe un labyrinthe
* @param i Le numéro de la case
* @return la ième case
*/
CASE_Case* LAB_iemeCase(LAB_Labyrinthe* lab, uint i);

/**
* @brief Obtenir la direction d'entrée d'un labyrinthe
* @param labyrinthe un labyrinthe
* @return la direction de l'entrée
*/
char* LAB_obtenirDirectionEntree(LAB_Labyrinthe* labyrinthe);

/**
* @brief Obtenir la direction de sortie d'un labyrinthe
* @param labyrinthe un labyrinthe
* @return la direction de la sortie
*/
char* LAB_obtenirDirectionSortie(LAB_Labyrinthe* labyrinthe);

#endif