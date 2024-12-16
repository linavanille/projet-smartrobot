#include "../include/labyrinthe.h"
#include <stdlib.h>

LAB_Labyrinthe LAB_creerLabyrinthe(unsigned int largeur, int entree, int sortie)
{
    LAB_Labyrinthe lab;
    lab.entree = entree;
    lab.sortie = sortie;
    lab.largeur = largeur;
	lab.lesConnections = (CASE_Case *)malloc(largeur * largeur * sizeof(CASE_Case));
    return lab;
}

void LAB_supprimerLabyrinthe(LAB_Labyrinthe* lab)
{
	free(lab->lesConnections);
}

unsigned int LAB_obtenirLargeur(LAB_Labyrinthe* lab)
{
    return lab->largeur;
}

CASE_Case* LAB_obtenirEntree(LAB_Labyrinthe* lab)
{
    return &lab->lesConnections[lab->entree];
}

CASE_Case* LAB_obtenirSortie(LAB_Labyrinthe* lab)
{
    return &lab->lesConnections[lab->sortie];
}

CASE_Case* LAB_iemeCase(LAB_Labyrinthe* lab, unsigned int iCase)
{
    return &lab->lesConnections[iCase];
}

CASE_Case *Lab_obtenirCasesAccessibles(LAB_Labyrinthe* lab, unsigned int iCase)
{
	return LAB_iemeCase(lab, iCase);
}