#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "labyrinthe.h"
#include "chemin.h"
#include "case.h"

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
    FILE *flab = fopen(path, "r");

    char temp[4];
    char buffer[10];
    int l;

    fgets(buffer, 10, flab);
    l = atoi(buffer); 

    fgets(buffer, 10, flab);
    strncpy(temp, buffer, strlen(buffer)-1);
    temp[strlen(buffer)-1] = '\0';
    int entree = atoi(temp);

    fgets(buffer, 10, flab);
    strncpy(temp, buffer, strlen(buffer)-1);
    temp[strlen(buffer)-1] = '\0';
    int sortie = atoi(temp);

    printf("longueur %d, entree %d, sortie %d\n", l, entree, sortie);

    LAB_Labyrinthe labyrinthe = LAB_Labyrinthe(l, entree, sortie);
    LAB_remplirLabyrinthe(flab, labyrinthe);

    CASE_case *chemin = CHM_chemin(labyrithe);
    ORD_ordres *listeDOrdre = ORD_obtenirOrdre(chemin);
    
}