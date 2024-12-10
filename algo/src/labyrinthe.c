#include "labyrinthe.h"
#include <stdlib.h>

LAB_Labyrinthe LAB_creerLabyrinthe(unsigned int largeur, int entree, int sortie) {
    LAB_Labyrinthe lab;
    lab.entree = entree;
    lab.sortie = sortie;
    lab.largeur = largeur;
	lab.lesConnections = (LAB_Case *)malloc(largeur * largeur * sizeof(LAB_Case));
    return lab;
}

unsigned int LAB_obtenirLargeur(LAB_Labyrinthe lab) {
    return lab.largeur;
}

LAB_Case LAB_obtenirEntree(LAB_Labyrinthe lab) {
    return lab.lesConnections[lab.entree];
}

LAB_Case LAB_obtenirSortie(LAB_Labyrinthe lab) {
    return lab.lesConnections[lab.sortie];
}

LAB_Case LAB_iemeCase(LAB_Labyrinthe lab, unsigned int iCase) {
    return lab.lesConnections[iCase];
}

LAB_Case Lab_obtenirCasesAccessibles(LAB_Labyrinthe lab, unsigned int iCase) {
	return LAB_iemeCase(lab, iCase);
}