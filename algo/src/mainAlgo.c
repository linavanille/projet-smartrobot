#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "case.h"
#include "labyrinthe.h"
#include "initLab.h"
#include "chemin.h"
#include "ordres.h"
#include "pileLc.h"

int main(int argc, char** argv){
    LAB_Labyrinthe labyrinthe;
    // CASE_Case* chemin;

    if(argc != 2){
        printf("Le fichier non precise\n"); 
        return EXIT_FAILURE;
        
    }
    char* path = argv[1];
    if(access(path, R_OK)!=0){
        printf("Le fichier n'existe pas\n"); 
        return EXIT_FAILURE; 
    }
    
    labyrinthe = initialisationLabyrinthe(path);
    //chemim = CHM_chemin(labyrinthe)
    //tailleChemin = CHM_longueur(chemin)                           La fonction n'existe pas mais c'est ce que l'on aurait dû avoir
    //ORD_obtenirOrdres(chemin, tailleChemin, labyrinthe)           Mauvais type pour chemin

    return EXIT_SUCCESS;
}
