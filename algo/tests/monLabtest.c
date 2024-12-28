#include <stdio.h>
#include "../include/labyrinthe.h"
#include "../include/initLab.h"
#include "../include/pileLc.h"
#include "../include/ensemble.h"
#include "../include/chemin.h"
#include "../include/case.h"
#include "../include/test_pileLc.h"

char* fichierLab = "labSujet.txt";



int main(){
    LAB_Labyrinthe l = initialisationLabyrinthe(fichierLab);
    printf("Après initialisation du labyrinthe\n");
    PILELC chemintrouve;
    chemintrouve = chemin(&l);
    afficherPileLc(&chemintrouve);
    return 0;
}

