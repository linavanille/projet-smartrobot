#include "../include/chemin.h"
#include "../include/ensemble.h"
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/pileLc.h"

/*Permet d'obtenir un chemin*/
PILELC chemin(LAB_Labyrinthe* l){
    PILELC res;
    // if (!res) {
    //     perror("Erreur d'allocation mémoire pour res\n");
    //     exit(EXIT_FAILURE);
    // }
    pileLc(&res); 
    Ensemble visitees;
    // if (!visitees) {
    //     perror("Erreur d'allocation mémoire pour visitees\n");
    //     exit(EXIT_FAILURE);
    // }
    ensemble(&visitees);
 
    printf(" Sortie: %d\n" ,CASE_obtenirNumeroCase(*LAB_obtenirSortie(l)));
    recSortirLabyrinthe(*LAB_obtenirEntree(l),&visitees,*LAB_obtenirSortie(l),&res);
    afficherPileLc(&res);
    return res;

}

void recSortirLabyrinthe(CASE_Case c, Ensemble* visitees,CASE_Case objectif,PILELC* res){
    printf("Dans recSortir\n");
    int* enfants;
    CASE_Case enfant;
    int i;
    if(!estPresent(visitees,CASE_obtenirNumeroCase(c))){
        printf("Le  numéro de case est %d\n",CASE_obtenirNumeroCase(c));
        ajouter(visitees,CASE_obtenirNumeroCase(c));
        empilerLc(res,CASE_obtenirNumeroCase(c));
        if(CASE_obtenirNumeroCase(c)!= CASE_obtenirNumeroCase(objectif)){
            enfants = CASE_obtenirCasesAccessibles(c);
            i=1;
            while((i<=enfants[0])&&(obtenirCaseLc(res)!=CASE_obtenirNumeroCase(objectif))){
                enfant.Numero = enfants[i];
                recSortirLabyrinthe(enfant,visitees,objectif,res);
                i++;
            };
            if(CASE_obtenirNumeroCase(objectif) != obtenirCaseLc(res)){
                depilerLc(res);
            }
        }
    }
}
