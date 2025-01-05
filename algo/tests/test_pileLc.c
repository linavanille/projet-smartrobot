#include "../include/pileLc.h"
#include <stdio.h>
#include <stdlib.h>

void afficherPileLc(PILELC *PileDeCase) {
    if (estVideLc(PileDeCase)) {
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
/*
int main() {
    PILELC pileDeCase;
    pileLc(&pileDeCase);

    empilerLc(&pileDeCase, 2);
    empilerLc(&pileDeCase, 3);
    empilerLc(&pileDeCase, 4);
    empilerLc(&pileDeCase, 100);
    empilerLc(&pileDeCase, 0);

    afficherPileLc(&pileDeCase);

    depilerLc(&pileDeCase);
    depilerLc(&pileDeCase);

    printf("Le sommet est %d\n", obtenirCaseLc(&pileDeCase));

    while (!estVideLc(&pileDeCase)) {
        depilerLc(&pileDeCase);
    }

    afficherPileLc(&pileDeCase);

    return 0;
}
*/