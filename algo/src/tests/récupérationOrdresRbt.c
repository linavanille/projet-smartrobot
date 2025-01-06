#include <stdio.h>

int main(){
    char prochaineAction[3];
    do{
        scanf("%s\n", prochaineAction);
        printf("%s\n", prochaineAction);
    }while(prochaineAction[0] !='.');
    return 0;
}