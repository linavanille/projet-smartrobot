#include "../include/pile.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void pile(PILE *PileDeCase){
    if (!PileDeCase) {
        printf("Erreur : Pointeur NULL passé à pile\n");
        exit(EXIT_FAILURE);
    };
    (*PileDeCase).nbCase = 0;
};

int estVide(PILE *PileDeCase){
    return (*PileDeCase).nbCase == 0;
};

void empiler(PILE *PileDeCase,int uneCase){

        if (PileDeCase->nbCase >=MAXELEM_PILE ) {
        printf("Erreur : Dépassement de la taille maximale de la pile\n");
        exit(EXIT_FAILURE);
        };
        (*PileDeCase).lesCases[(*PileDeCase).nbCase ] = uneCase;
        (*PileDeCase).nbCase = (*PileDeCase).nbCase + 1;
};

void depiler(PILE *PileDeCase){
    assert(!estVide(PileDeCase));
    (*PileDeCase).nbCase = (*PileDeCase).nbCase-1;
};

int obtenirCase(PILE *PileDeCase){
    assert(!estVide(PileDeCase));
    return (*PileDeCase).lesCases[(*PileDeCase).nbCase-1];
};

