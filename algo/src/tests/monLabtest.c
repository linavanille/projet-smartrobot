#include <stdio.h>
#include "labyrinthe.h"
#include "initLab.h"
#include "pileLc.h"
#include "ensemble.h"
#include "chemin.h"
#include "case.h"


char* fichierLab = "labSujet.txt";



int main(){
    LAB_Labyrinthe l = initialisationLabyrinthe(fichierLab);
    printf("Après initialisation du labyrinthe\n");
    PILELC chemintrouve;
    chemintrouve = CHM_chemin(&l);
    PILELC_afficher(&chemintrouve);
    return 0;
}

