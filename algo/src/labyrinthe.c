#include "../include/labyrinthe.h"
#include <stdlib.h>

LAB_Labyrinthe LAB_creerLabyrinthe(uint largeur, char* entree, char* sortie)
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
    return &lab->lesConnections[atoi(lab->entree)];
}

CASE_Case* LAB_obtenirSortie(LAB_Labyrinthe* lab)
{
    return &lab->lesConnections[atoi(lab->sortie)];
}

CASE_Case* LAB_iemeCase(LAB_Labyrinthe* lab, unsigned int iCase)
{
    return &lab->lesConnections[iCase];
}

CASE_Case *Lab_obtenirCasesAccessibles(LAB_Labyrinthe* lab, unsigned int iCase)
{
	return LAB_iemeCase(lab, iCase);
}

char* LAB_obtenirDirectionEntree(LAB_Labyrinthe* lab)
{
    return &lab->entree[1];
}

char* LAB_obtenirDirectionSortie(LAB_Labyrinthe* lab)
{
    return &lab->sortie[1];
}