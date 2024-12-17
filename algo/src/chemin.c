#include "../include/chemin.h"
#include "../include/ensemble.h"

/*Permet d'obtenir un chemin*/
PILE* chemin(LAB_Labyrinthe* l){
    PILE* res;
    pile(res);
    Ensemble* visitees;
    ensemble(visitees);
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
