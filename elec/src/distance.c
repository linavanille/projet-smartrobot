#include <wiringPi.h>  
#include <stdio.h>  
#include <sys/time.h>  
#include <time.h>

#define  Trig    18 
#define  Echo    24

void ultraInit(void)  
{  
	wiringPiSetupGpio();
	pinMode(Echo, INPUT);  
	pinMode(Trig, OUTPUT);  
}  

float disMeasure(void)  
{  
	struct timeval tv1;  
	struct timeval tv2;  
	long start, stop;  
	float dis;  

	digitalWrite(Trig, LOW);  
	delayMicroseconds(2);  

	digitalWrite(Trig, HIGH);  //produce a pluse
	delayMicroseconds(10); 
	digitalWrite(Trig, LOW);  

	while(!(digitalRead(Echo) == 1));  
	gettimeofday(&tv1, NULL);           //current time 

	while(!(digitalRead(Echo) == 0));  
	gettimeofday(&tv2, NULL);           //current time  

	start = tv1.tv_sec * 1000000 + tv1.tv_usec; 
	stop  = tv2.tv_sec * 1000000 + tv2.tv_usec;  

	dis = (float)(stop - start) / 1000000 * 34000 / 2;  //count the distance 

	return dis;  
}  

int main(void)  
{  
	ultraInit();
	while(1)
	{
		printf("%f\n", disMeasure());
		delay(500);
	}
	return 0;
}  
