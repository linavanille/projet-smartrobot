#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pileLc.h"


void PILELC_pileLc(PILELC *PileDeCase) {
    printf("Dans pileLC\n");
    if (!PileDeCase) {
        printf("Erreur : Pointeur NULL passé à pileLc\n");
        exit(EXIT_FAILURE);
    }
    PileDeCase->sommet = NULL;
}

int PILELC_estVide(PILELC *PileDeCase) {
    return PileDeCase->sommet == NULL;
}

void PILELC_empiler(PILELC *PileDeCase, int uneCase) {
    Element *nouveau = (Element *)malloc(sizeof(Element));
    if (!nouveau) {
        printf("Erreur : Allocation mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = uneCase;
    nouveau->suivant = PileDeCase->sommet;
    PileDeCase->sommet = nouveau;
}

void PILELC_depiler(PILELC *PileDeCase) {
    assert(!PILELC_estVide(PileDeCase));
    Element *tmp = PileDeCase->sommet;
    PileDeCase->sommet = tmp->suivant;
    free(tmp);
}

int PILELC_obtenirCase(PILELC *PileDeCase) {
    assert(!PILELC_estVide(PileDeCase));
    return PileDeCase->sommet->valeur;
}

void PILELC_afficher(PILELC *PileDeCase) {
    if (PILELC_estVide(PileDeCase)) {
        printf("La pile de case est vide.\n");
    } else {
        printf("Contenu de la pile :\n");
        Element *courant = PileDeCase->sommet;
        while (courant != NULL) {
            printf("\t%d\n", courant->valeur);
            printf("\t-\n");
            courant = courant->suivant;
        }
    }
}
