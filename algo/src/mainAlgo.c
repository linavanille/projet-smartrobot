#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "../include/case.h"
#include "../include/labyrinthe.h"
#include "../include/initLab.h"
#include "../include/chemin.h"
#include "../include/ordresRobot.h"

int main(int argc, char** argv){
    LAB_Labyrinthe labyrinthe;
    CASE_Case* chemin;
    ORD_Ordre listeDOrdre[] = {AV,TG,AV,TD,AV,TG,AV,TD,AV,AV,TD,AV,TG,AV,FIN};

    uint i = 0;
    bool done = false;

    if(argc != 2){
        //printf("Le fichier non precise\n"); 
        //return EXIT_FAILURE;
        
    }
    char* path = argv[1];
    if(access(path, R_OK)!=0){
        //printf("Le fichier n'existe pas\n"); 
        //return EXIT_FAILURE; 
    }
    
    //labyrinthe = initialisationLabyrinthe(path);
    //chemim = CHM_chemin(labyrinthe)
    //listeDOrdre[] = ;
    do{
        switch(listeDOrdre[i]){
            case AV :
                printf("AV\n");
            case TD :
                printf("TD\n");
                break;
            case TG :
                printf("TG\n");
                break;
            case FIN :
                printf(".\n");
                done = true;
                break;
            default :
                printf("ERROR");
                break;
        }
        i++;
    }while(!done);

    return 0;
}
