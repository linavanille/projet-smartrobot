/**
* @file pileLc.h
* @brief Pile de case implémentée avec une liste chaînée.
*/

#ifndef __PILELC_H__
#define __PILELC_H__

typedef struct m_Element {
    int valeur;
    struct m_Element *suivant;
} Element;

typedef struct {
    Element *sommet;
} PILELC;

/**
* @brief Créer une pile vide
*/
void pileLc(PILELC *PileDeCase);

/**
* @brief Vérifier si une pile est vide
* @return 1 si la pile est vide, 0 sinon
*/
int estVideLc(PILELC *PileDeCase);

/**
* @brief Empiler une case
*/
void empilerLc(PILELC *PileDeCase, int uneCase);

/**
* @brief Dépiler une case
* Précondition : La pile n'est pas vide
*/
void depilerLc(PILELC *PileDeCase);

/**
* @brief Récupérer la valeur du sommet de la pile
* Précondition : La pile n'est pas vide
* @return La valeur au sommet
*/
int obtenirCaseLc(PILELC *PileDeCase);

#endif
