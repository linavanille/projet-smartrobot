#include "buzzer.h"
#include "ultrason.h"
#include "interruption.h"

int main()
{
    BUZZ_setup();
    USON_init();
    STOP_loop(BUZZ_loop, BUZZ_loop);
    return 0;
}