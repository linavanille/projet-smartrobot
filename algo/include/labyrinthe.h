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
    int entree;
    int sortie;
    unsigned int largeur;
} LAB_Labyrinthe;

/**
* @brief Crée un labyrinthe.
* @return un labyrinthe
* @param uint La largeur du labyrinthe
* @param uint L'entrée du labyrinthe
* @param uint La sortie du labyrinthe
*/
LAB_Labyrinthe LAB_creerLabyrinthe(uint, int, int);

/**
* @brief Obtenir la liste des cases accessibles d'une case 
* @param LAB_Labyrinthe le labyrinthe
* @param CASE_Case une case
* @return liste de cases accessibles
*/
CASE_Case *LAB_obtenirCasesAccessibles(LAB_Labyrinthe, CASE_Case);

/**
* @brief Obtenir la case entrée d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case d'entrée
*/
CASE_Case LAB_obtenirEntree(LAB_Labyrinthe);

/**
* @brief Obtenir la case sortie d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case de sortie
*/
CASE_Case LAB_obtenirSortie(LAB_Labyrinthe);

/**
* @brief Obtenir la largeur d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la largeur
*/
unsigned int LAB_obtenirLargeur(LAB_Labyrinthe);

/**
* @brief Obtenir la ième case d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @param uint Le numéro de la case
* @return la ième case
*/
CASE_Case LAB_iemeCase(LAB_Labyrinthe, uint);

#endif