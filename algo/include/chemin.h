/**/
#include "labyrinthe.h"
#include "case.h"
#include "pile.h"
#include "ensemble.h"


*CASE_Case chemin(LAB_Labyrinthe l);
/*Renvoi un chemin : une liste de case */

/**
*@brief cherche récursivement un chemin de sortie
*@param c case d'entrée
*@param visitees l'ensemble de cases visitées
*@param objectif la case de sortie
*@param res la pile de case qui compose le chemin vers la sortie
*/
void recSortirLabyrinthe(CASE_Case c, Ensemble* visitees,CASE_Case objectif,PILE* res);
