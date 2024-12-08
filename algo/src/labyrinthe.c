#include <stdio.h>
#include <stdlib.h>

#include "labyrinthe.h"

LAB_Labyrinthe LAB_creerLabyrinthe(unsigned int l, LAB_Case entree, LAB_Case sortie) {
    LAB_Labyrinthe lab;
    lab.entree = entree;
    lab.sortie = sortie;
    lab.largeur = largeur;
    return lab;
}

unsigned int LAB_obtenirLargeur(LAB_Labyrinthe lab) {
    return lab.largeur;
}

LAB_Case LAB_obtenirEntree(LAB_Labyrinthe lab) {
    return lab.entree;
}

LAB_Case LAB_obtenirSortie(LAB_Labyrinthe lab) {
    return lab.sortie;
}

unsigned int LAB_iemeCase(LAB_Labirynthe lab, unsigned int iCase) {
    LAB_Case res = lab.lesConnections[iCase];
    return res;
}

LAB_Case Lab_obtenirCasesAccessibles(LAB_Labyrinthe lab, unsigned int iCase) {
    LAB_Case res = LAB_iemeCase(lab, iCase);
    return res;
}