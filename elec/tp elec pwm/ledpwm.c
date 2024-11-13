#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int LED = 18;
	if(wiringPiSetupGpio() == -1)
	{
			return 1;
	}
	pinMode(LED,PWM_OUTPUT);
	int cycleD;// entre 0 et 100
	int value = (1024*cycleD)/100;
	printf("Step 1 done\n");
	pwmWrite(LED,100);
	
	printf("Step 2 done\n");

	for(cycleD = 0;cycleD <= 100; cycleD += 10)
	{
		value = (1024*cycleD)/100;
		pwmWrite(LED,value);
		delay(1000);
	}
	pwmWrite(LED,0);
	return 0;
}
