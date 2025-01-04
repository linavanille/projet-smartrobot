#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/labyrinthe.h"
#include "../include/case.h"

void extraireNumCases(char* buffer, int* c1, int* c2){
    int i=0;
    char temp[4];

    while(buffer[i]>='0' && buffer[i] <= '9'){
        i++;
    }

    strncpy(temp, buffer, i);
    temp[i] = '\0';
    *c1 = atoi(temp); 

    strncpy(temp, &buffer[i+1], strlen(buffer)-(i+1));
    temp[strlen(buffer)-(i+1)] = '\0';
    *c2 = atoi(temp);
}

void attributionConnections(LAB_Labyrinthe* labyrinthe, int c1, int c2){
    CASE_Case* uneCase;
    CASE_Case* lAutreCase;

    uneCase = LAB_iemeCase(labyrinthe, c1);
    lAutreCase = LAB_iemeCase(labyrinthe, c2);

    if(c2 < c1){
        if (c2+1 == c1){
            CASE_fixerGauche(uneCase, c2);
            CASE_fixerDroite(lAutreCase, c1);
        }
        else{
            CASE_fixerHaut(uneCase, c2);
            CASE_fixerBas(lAutreCase, c1);
        }
    }
    else{
        if (c2-1 == c1){
            CASE_fixerDroite(uneCase, c2);
            CASE_fixerGauche(lAutreCase, c1);
        }
        else{
            CASE_fixerBas(uneCase, c2);
            CASE_fixerHaut(lAutreCase, c1);
        }
    }
}


LAB_Labyrinthe initialiserLabyrinthe(char* fnom){
    char buffer[10];
    int l;
    char *sortie, *entree;
    int c1, c2;
    LAB_Labyrinthe labyrinthe;
    
    FILE* fichier = fopen(fnom, "r");

    fgets(buffer, 10, fichier);
    l = atoi(buffer); 

    fgets(buffer, 10, fichier);
    entree = buffer;

    fgets(buffer, 10, fichier);
    sortie = buffer;

    printf("largeur = %d\n entree = %d\n sortie = %d\n", l, atoi(entree), atoi(sortie));
    labyrinthe = LAB_creerLabyrinthe(l, entree, sortie);


    do{
        fgets(buffer, 10, fichier);
        if(buffer[0]!='.'){
            extraireNumCases(buffer, &c1, &c2);
            if(c1 != c2){
                attributionConnections(&labyrinthe, c1, c2);
            }
        }
    }while(buffer[0]!='.');

    return labyrinthe; 
}

LAB_Labyrinthe initialisationLabyrinthe(char* fnom){
    LAB_Labyrinthe lab = initialiserLabyrinthe(fnom);
    return lab;
}