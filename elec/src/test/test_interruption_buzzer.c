#include "buzzer.h"
#include "ultrason.h"
#include "interruption.h"
#include <wiringPi.h>

int main()
{
    wiringPiSetupGpio();
    BUZZ_setup();
    USON_init();
    STOP_loop(BUZZ_loop, BUZZ_loop);
    return 0;
}