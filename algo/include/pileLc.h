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
void PILELC_pileLc(PILELC *PileDeCase);

/**
* @brief Vérifier si une pile est vide
* @return 1 si la pile est vide, 0 sinon
*/
int PILELC_estVide(PILELC *PileDeCase);

/**
* @brief Empiler une case
*/
void PILELC_empiler(PILELC *PileDeCase, int uneCase);

/**
* @brief Dépiler une case
* Précondition : La pile n'est pas vide
*/
void PILELC_depiler(PILELC *PileDeCase);

/**
* @brief Récupérer la valeur du sommet de la pile
* Précondition : La pile n'est pas vide
* @return La valeur au sommet
*/
int PILELC_obtenirCase(PILELC *PileDeCase);

/**
 * @brief Affiche le contenu d'une pileLc.
 * @param PileDeCase Pointeur vers la pileLc à afficher.
 */
void PILELC_afficher(PILELC *PileDeCase);


#endif
