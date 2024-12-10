#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "labyrinthe.h"
#include "chemin.h"
#include "case.h"

void extraireiCases(char* buffer, int* c1, int* c2){
    int i=0;
    char temp[4];

    while(buffer[i]>='0' && buffer[i] <= '9'){
        i++;
    }

    strncpy(temp, buffer, i);
    temp[i] = '\0';
    c1 = atoi(temp); 

    strncpy(temp, &buffer[i+1], strlen(buffer)-(i+1));
    temp[strlen(buffer)-(i+1)] = '\0';
    c2 = atoi(temp);
}

LAB_Labyrinthe initialiserLabyrinthe(char* fnom){
    char temp[4];
    char buffer[10];
    int l, sortie, entree;
    int c1, c2;
    int i = 0;
    
    FILE* fichier = fopen(fnom, "r");

    fgets(buffer, 10, fichier);
    l = atoi(buffer); 

    fgets(buffer, 10, fichier);
    strncpy(temp, buffer, strlen(buffer)-1);
    temp[strlen(buffer)-1] = '\0';
    entree = atoi(temp);

    fgets(buffer, 10, fichier);
    strncpy(temp, buffer, strlen(buffer)-1);
    temp[strlen(buffer)-1] = '\0';
    sortie = atoi(temp);

    LAB_Labyrinthe labyrinthe = LAB_Labyrinthe(l, entree, sortie);
    
    fgets(buffer, 10, fichier);
    if(buffer[0]!='.'){
        extraireiCases(buffer, &c1, &c2); 
        initCase(LAB_iemeCase(labyrinthe, c1), c2);
        initCase(LAB_iemeCase(labyrinthe, c2), c1);
    }
    return labyrinthe; 
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Le fichier non precise\n"); 
        return EXIT_FAILURE;
        
    }
    char* path = argv[1];
    if(access(path, R_OK)!=0){
        printf("Le fichier n'existe pas\n"); 
        return EXIT_FAILURE; 
    }
    LAB_Labyrinthe labyrinthe; 
    labyrinthe = initialiserLabyrinthe(path);

}