#include "../include/pile.h"
#include <assert.h>


void pile(PILE *PileDeCase){
    (*PileDeCase).nbCase = 0;
};

int estVide(PILE *PileDeCase){
    return (*PileDeCase).nbCase == 0;
};

void empiler(PILE *PileDeCase,int uneCase){

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

