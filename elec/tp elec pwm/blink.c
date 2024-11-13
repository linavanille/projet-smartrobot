#include <stdio.h>
#include <wiringPi.h>
#include <time.h> 


int main(int argc, char **argv)
{
	wiringPiSetupGpio();
	int LED = 19;
	pinMode(LED, OUTPUT); //GPIO en sortie
	while(1)
	{
		digitalWrite(LED, HIGH); //On allume
		delay(500);				// on attend
		digitalWrite(LED, LOW); //on eteint
		delay(500);
	}
	return 0;
}

