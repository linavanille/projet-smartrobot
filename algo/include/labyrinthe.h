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
    int largeur;
} LAB_Labyrinthe;

/**
* @fn LAB_creerLabyrinthe LAB_creerLabyrinthe()
* @brief Créer un labyrinthe
* @return un labyrinthe
*/
LAB_Labyrinthe LAB_creerLabyrinthe();

/**
* @fn int* LAB_obtenirCasesAccessibles(LAB_Case)
* @brief Obtenir la liste des cases accessibles d'une case 
* @param LAB_Labyrinthe le labyrinthe
* @param LAB_Case une case
* @return liste de cases accessibles
*/
LAB_Case* LAB_obtenirCasesAccessibles(LAB_Labyrinthe, LAB_Case);

/**
* @fn LAB_Case LAB_obtenirEntree(LAB_Labyrinthe)
* @brief Obtenir la case entrée d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case d'entrée
*/
unsigned int LAB_obtenirEntree(LAB_Labyrinthe);

/**
* @fn LAB_Case LAB_obtenirSortie(LAB_Labyrinthe)
* @brief Obtenir la case sortie d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la case de sortie
*/
unsigned int LAB_obtenirSortie(LAB_Labyrinthe);

/**
* @fn LAB_Case LAB_obtenirLargeur(LAB_Labyrinthe)
* @brief Obtenir la largeur d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la largeur
*/
unsigned int LAB_obtenirLargeur(LAB_Labyrinthe);

/**
* @fn LAB_Case LAB_iemeCase(LAB_Labyrinthe, unsigned int)
* @brief Obtenir la ième case d'un labyrinthe
* @param LAB_Labyrinthe un labyrinthe
* @return la ième case
*/
LAB_Case LAB_iemeCase(LAB_Labyrinthe, unsigned int);

#endif