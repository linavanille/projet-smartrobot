#include <stdio.h>
#include "../include/testChemin.h"

int main(){
    LAB_Labyrinthe* l;
    printf("Avant création de lab\n");
    *l = LAB_creerLabyrinthe(25,6,20);
    printf("labyrinthe crée \n");
    PILE* chemintrouve;
    chemintrouve = chemin(l);
    afficherPile(chemintrouve);
    return 0;
}