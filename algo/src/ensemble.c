#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

void ENS_ensemble(Ensemble* ensembleDeCases){
    ensembleDeCases->tete = NULL;
}



int ENS_estPresent(Ensemble *ensembleDeCases, int uneCase){
   Node* courant = ensembleDeCases -> tete;
   while(courant != NULL){
        if(courant->numeroCase == uneCase){
            return 1;
        }
        courant = courant -> suivant;
   }
   return 0;
}


void ENS_ajouter(Ensemble *ensembleDeCases, int uneCase){
    if (ENS_estPresent(ensembleDeCases,uneCase)){
        printf("Ajout impossible : Élément présent \n");
        return;
    };
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau -> numeroCase = uneCase;
    nouveau -> suivant = ensembleDeCases -> tete;
    ensembleDeCases -> tete = nouveau;
    printf("Élément %d ajouté avec succès\n",uneCase);

}

void ENS_libererEnsemble(Ensemble* ensembleDeCases){
    Node* courant = ensembleDeCases->tete;
    while(courant != NULL){
        Node* temp = courant;
        courant = courant->suivant;
        free(temp);
    };
    ensembleDeCases->tete = NULL;

}

void ENS_afficher(Ensemble* ensembleDeCases){
    Node* courant=ensembleDeCases->tete;
    printf("{\t");
    while(courant != NULL){
        printf("%d\t",courant->numeroCase);
        courant=courant->suivant;

    }
   printf("}\n");
}

