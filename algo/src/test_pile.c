#include <stdio.h>
#include "../include/test_pile.h"

void afficherPile(PILE *PileDeCase){
    if (estVide(PileDeCase)){
        printf("La pile de case est vide \n");
    }
    else {
        int taille = (PileDeCase)->nbCase;
        for(int i=0;i<taille;i++){
            printf("\t%d\n",PileDeCase->lesCases[i]);
            printf("\t-\n");
        }
    }
}
/*
int main(){
    PILE *PileDeCase;
    pile(PileDeCase);
    empiler(PileDeCase,2);
    empiler(PileDeCase,3);
    empiler(PileDeCase,4);
    empiler(PileDeCase,5);
    empiler(PileDeCase,6);
    afficherPile(PileDeCase);
    depiler(PileDeCase);
    depiler(PileDeCase);
    printf("Le sommet est %d\n", obtenirCase(PileDeCase));

}
*/