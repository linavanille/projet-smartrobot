#include <stdio.h>
#include "../include/testEnsemble.h"


void afficherEnsemble(Ensemble* ensembleDeCases){
    Node* courant=ensembleDeCases->tete;
    printf("{\t");
    while(courant != NULL){
        printf("%d\t",courant->numeroCase);
        courant=courant->suivant;

    }
   printf("}\n");
};


int main(){
    Ensemble* monEnsemble;
    ensemble(monEnsemble);
    ajouter(monEnsemble,12);
    ajouter(monEnsemble,13);
    ajouter(monEnsemble,17);
    afficherEnsemble(monEnsemble);
    libererEnsemble(monEnsemble);
    afficherEnsemble(monEnsemble);
    return 0;
}