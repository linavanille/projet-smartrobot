#include "../include/chemin.h"
#include "../include/ensemble.h"
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*Permet d'obtenir un chemin*/
PILE* chemin(LAB_Labyrinthe* l){
    printf("Dans chemin\n");
    PILE* res = (PILE*) malloc(sizeof(PILE));
    if (!res) {
        perror("Erreur d'allocation mémoire pour res\n");
        exit(EXIT_FAILURE);
    }
    pile(res); 
    printf("Après pile(res)\n");
    Ensemble* visitees = (Ensemble*) malloc(sizeof(Ensemble));
    if (!visitees) {
        perror("Erreur d'allocation mémoire pour visitees");
        exit(EXIT_FAILURE);
    }
    printf("Avant ensemble : visitees = %p\n", (void*)visitees);
    ensemble(visitees);
    printf("Après ensemble : visitees = %p\n", (void*)visitees);
 
    assert(visitees!=NULL);
    printf(" Sortie: %d\n" ,CASE_obtenirNumeroCase(*LAB_obtenirSortie(l)));
    recSortirLabyrinthe(*LAB_obtenirEntree(l),visitees,*LAB_obtenirSortie(l),res);
    afficherPile(res);
    return res;

}

void recSortirLabyrinthe(CASE_Case c, Ensemble* visitees,CASE_Case objectif,PILE* res){
    int* enfants;
    CASE_Case enfant;
    int i;
    if(!estPresent(visitees,CASE_obtenirNumeroCase(c))){
        ajouter(visitees,CASE_obtenirNumeroCase(c));
        empiler(res,CASE_obtenirNumeroCase(c));
        if(CASE_obtenirNumeroCase(c)!= CASE_obtenirNumeroCase(objectif)){
            enfants = CASE_obtenirCasesAccessibles(c);
            i=1;
            while((i<=enfants[0])&&(obtenirCase(res)!=CASE_obtenirNumeroCase(objectif))){
                enfant.Numero = enfants[i];
                recSortirLabyrinthe(enfant,visitees,objectif,res);
                i++;
            };
            if(CASE_obtenirNumeroCase(objectif) != obtenirCase(res)){
                depiler(res);
            }
        }
    }
}
