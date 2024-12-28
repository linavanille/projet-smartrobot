#include "../include/pileLc.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void pileLc(PILELC *PileDeCase) {
    printf("Dans pileLC\n");
    if (!PileDeCase) {
        printf("Erreur : Pointeur NULL passé à pileLc\n");
        exit(EXIT_FAILURE);
    }
    PileDeCase->sommet = NULL;
}

int estVideLc(PILELC *PileDeCase) {
    return PileDeCase->sommet == NULL;
}

void empilerLc(PILELC *PileDeCase, int uneCase) {
    Element *nouveau = (Element *)malloc(sizeof(Element));
    if (!nouveau) {
        printf("Erreur : Allocation mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = uneCase;
    nouveau->suivant = PileDeCase->sommet;
    PileDeCase->sommet = nouveau;
}

void depilerLc(PILELC *PileDeCase) {
    assert(!estVideLc(PileDeCase));
    Element *tmp = PileDeCase->sommet;
    PileDeCase->sommet = tmp->suivant;
    free(tmp);
}

int obtenirCaseLc(PILELC *PileDeCase) {
    assert(!estVideLc(PileDeCase));
    return PileDeCase->sommet->valeur;
}
