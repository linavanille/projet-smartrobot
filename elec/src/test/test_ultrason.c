#include <wiringPi.h>
#include <stdio.h>
#include "../../include/ultrason.h"

int main(){
    while (1){
        float d = USON_obtenirDistance();
        printf("%f", d);
        delayMicroseconds(3000000);
    }
}