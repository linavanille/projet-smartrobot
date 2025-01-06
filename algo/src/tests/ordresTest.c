#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

    char buffer[10];

    if(argc != 2){
        printf("Le fichier non precise\n"); 
        return EXIT_FAILURE;
        
    }
    char* path = argv[1];
    if(access(path, R_OK)!=0){
        printf("Le fichier n'existe pas\n"); 
        return EXIT_FAILURE; 
    }

    FILE* fichier = fopen(path, "r");

    do{
        fgets(buffer, 10, fichier);
        printf("%s",buffer);
    }while(buffer[0]!='.');

    return EXIT_SUCCESS;
}
