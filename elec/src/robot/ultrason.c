#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "ultrason.h"
#include "pinsRef.h"

void USON_init()
{
	//wiringPiSetupGpio();
	pinMode(ECHO, INPUT);
	pinMode(TRIG, OUTPUT);
}

float USON_obtenirDistance()
{
	struct timeval tv1;
	struct timeval tv2;
	long start, stop;
	float dis;

	digitalWrite(TRIG, LOW);
	delayMicroseconds(2);

	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	while(!(digitalRead(ECHO) == 1));
	gettimeofday(&tv1, NULL);

	while(!(digitalRead(ECHO) == 0));
	gettimeofday(&tv2, NULL);

	start = tv1.tv_sec * 1000000 + tv1.tv_usec;
	stop  = tv2.tv_sec * 1000000 + tv2.tv_usec;

	dis = (float)(stop - start) / 1000000 * 34000 / 2;

	return dis;
}
