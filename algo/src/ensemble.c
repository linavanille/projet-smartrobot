#include <stdio.h>
#include <stdlib.h>
#include "../include/ensemble.h"

void ensemble(Ensemble* ensembleDeCases){
    ensembleDeCases->tete = NULL;
};

int estPresent(Ensemble *ensembleDeCases, int uneCase){
   Node* courant = ensembleDeCases -> tete;
   while(courant != NULL){
        if(courant->numeroCase == uneCase){
            return 1;
        }
        courant = courant -> suivant;
   }
   return 0;
};


void ajouter(Ensemble *ensembleDeCases, int uneCase){
    if (estPresent(ensembleDeCases,uneCase)){
        printf("Ajout impossible : Élément présent \n");
        return;
    };
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau -> numeroCase = uneCase;
    nouveau -> suivant = ensembleDeCases -> tete;
    ensembleDeCases -> tete = nouveau;
    printf("Élément %d ajouté avec succès\n",uneCase);

};

void libererEnsemble(Ensemble* ensembleDeCases){
    Node* courant = ensembleDeCases->tete;
    while(courant != NULL){
        Node* temp = courant;
        courant = courant->suivant;
        free(temp);
    };
    ensembleDeCases->tete = NULL;

};

