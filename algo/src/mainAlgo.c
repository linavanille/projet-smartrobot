#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "case.h"
#include "labyrinthe.h"
#include "initLab.h"
#include "chemin.h"
#include "ordresRobot.h"

int main(int argc, char** argv){
    LAB_Labyrinthe labyrinthe;
    CASE_Case* chemin;
    Ordre* listeDOrdre;

    uint i = 0;
    bool done = false;
    char print[4];

    if(argc != 2){
        printf("Le fichier non precise\n"); 
        return EXIT_FAILURE;
        
    }
    char* path = argv[1];
    if(access(path, R_OK)!=0){
        printf("Le fichier n'existe pas\n"); 
        return EXIT_FAILURE; 
    }
    
    initialisationLabyrinthe(path, &labyrinthe);
    chemim = CHM_chemin(labyrinthe)
    listeDOrdre = ORD_obtenirOrdres(&chemin, LAB_obtenirLargeur(labyrinthe));
    do{
        switch(ORD_iemOrdre(listeDOrdre, i)){
            case AV :
                print = "AV";
                break;
            case TD :
                print = "TD";
                break;
            case TG :
                print = "TG";
                break;
            case . :
                print = ".";
                done = true;
                break;
            default :
                print = "ERR";
                break; 
        }
        printf("%s", print);
        i++
    }while(!done);

    return 0;
}