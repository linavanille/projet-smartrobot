#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pileLc.h"
#include "chemin.h"
#include "ensemble.h"

/*Permet d'obtenir un chemin*/
PILELC CHM_chemin(LAB_Labyrinthe* l){
    PILELC res;
    PILELC_pileLc(&res); 
    Ensemble visitees;
    ENS_ensemble(&visitees);
 
    printf(" Sortie: %d\n" ,CASE_obtenirNumeroCase(*LAB_obtenirSortie(l)));
    CHM_recSortirLabyrinthe(*LAB_obtenirEntree(l),&visitees,*LAB_obtenirSortie(l),&res);
    return res;

}

void CHM_recSortirLabyrinthe(CASE_Case c, Ensemble* visitees,CASE_Case objectif,PILELC* res){
    printf("Dans recSortir\n");
    int* enfants;
    CASE_Case enfant;
    int i;
    if(!ENS_estPresent(visitees,CASE_obtenirNumeroCase(c))){
        printf("Le  numéro de case est %d\n",CASE_obtenirNumeroCase(c));
        ENS_ajouter(visitees,CASE_obtenirNumeroCase(c));
        PILELC_empiler(res,CASE_obtenirNumeroCase(c));

        if(CASE_obtenirNumeroCase(c)!= CASE_obtenirNumeroCase(objectif)){
            enfants = CASE_obtenirCasesAccessibles(c);
            i=1;
            while((i<=enfants[0])&&(PILELC_obtenirCase(res)!=CASE_obtenirNumeroCase(objectif))){
                enfant.Numero = enfants[i];
                CHM_recSortirLabyrinthe(enfant,visitees,objectif,res);
                i++;
            };
            if(CASE_obtenirNumeroCase(objectif) != PILELC_obtenirCase(res)){
                PILELC_depiler(res);
            }
        }
    }
}
