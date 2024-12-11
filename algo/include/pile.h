/** 
* @file pile.h
* @brief  Pile de case. Les cases sont désignées par leurs numéros
* qui sont des entiers
* 
*/
#ifndef __PILE_H__
#define __PILE_H__
#define MAXELEM  1000

typedef struct  {
    int lesCases[MAXELEM];
    int nbCase;
}PILE;


/**
* @brief Créer une pile vide 
*/
void pile(PILE *PileDeCase);

/**
* @brief Vérifier si une pile est vide 
*/
int estVide(PILE *PileDeCase);

/**
*@brief empiler une case 
*/
void empiler(PILE *PileDeCase, int uneCase);

/**
*@brief Dépiler une case quand la pile n'est pas vide
*précondition : PiledeCase non vide
*/
void depiler(PILE *PileDeCase);

/**
*@brief Recupérer une case en sommet de pile 
*précondition : PiledeCase non vide
*/
int obtenirCase(PILE *PileDeCase);

#endif