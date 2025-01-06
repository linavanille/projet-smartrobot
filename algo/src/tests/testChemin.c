#include <stdio.h>
#include "labyrinthe.h"
#include "chemin.h"
#include "initLab.h"

int main(){
    LAB_Labyrinthe* l;
    printf("Avant création de lab\n");
    *l = LAB_creerLabyrinthe(25,6,20);
    printf("labyrinthe crée \n");
    PILELC chemintrouve;
    chemintrouve = CHM_chemin(&l);
    PILELC_afficher(&chemintrouve);
    return 0;
}