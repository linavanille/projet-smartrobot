/**
 * @file labyrinthe.h
 * @brief Implémantation du TAD LAB_Labyrinthe
 */

#ifndef __LABYRINTHE__
#define __LABYRINTHE__

typedef struct {
    int Haut;
    int Gauche;
    int Bas;
    int Droite;
} LAB_Case;

typedef struct {
    LAB_Case lesConnections[4];
    int entree;
    int sortie;
} LAB_Labyrinthe;

/**
* @fn LAB_Labyrinthe labyrinthe()
* @brief Créer un labyrinthe
* @return un labyrinthe
*/
LAB_Labyrinthe LAB_labyrinthe();

/**
* @fn int* obtenirCasesAccessibles(LAB_Case)
* @brief Obtenir la liste des cases accessibles d'une case 
* @param LAB_Case une case
* @return liste de cases
*/
LAB_Case* LAB_obtenirCasesAccessibles(LAB_Case);

/**
* @fn LAB_Case obtenirEntree(LAB_Labyrinthe)
* @brief Obtenir la case sortie d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case d'entrée
*/
LAB_Case LAB_obtenirEntree(LAB_Labyrinthe);

/**
* @fn LAB_Case obtenirSortie(LAB_Labyrinthe)
* @brief Obtenir la case sortie d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case de sortie
*/
LAB_Case LAB_obtenirSortie(LAB_Labyrinthe);

#endif