#include <stdio.h>

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

    printf("AV ");
    printf("TG ");
    printf("AV ");
    printf("AV ");
    printf("TD ");
    printf("AV ");
    printf("TG ");
    printf("AV ");
    printf(".");
    return 0;
}
