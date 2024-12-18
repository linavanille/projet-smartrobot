#include <stdio.h>
#include "../include/labyrinthe.h"
#include "../include/initLab.h"
#include "../include/pile.h"
#include "../include/ensemble.h"
#include "../include/chemin.h"
#include "../include/case.h"

char* fichierLab = "labSujet.txt";



int main(){
    LAB_Labyrinthe l = initialisationLabyrinthe(fichierLab);
    printf("Après initialisation du labyrinthe\n");
    PILE* chemintrouve;
    chemintrouve = chemin(&l);
    afficherPile(chemintrouve);
    return 0;
}

