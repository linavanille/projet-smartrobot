#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void modifierMoteur(int A_1, int A_2, int A_3, int A_4, 
int val1, int val2, int val3, int val4)
{
	digitalWrite(A_1, val1);
	digitalWrite(A_2, val2);
	digitalWrite(A_3, val3);
	digitalWrite(A_4, val4);
}

void turnRight(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,1,0,1,0);
}

void turnLeft(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,1,0,1);
}

void avancer(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,1,0,0,1);
}

void reculer(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,1,1,0);
}

void stop(int A_1, int A_2, int A_3, int A_4)
{
	modifierMoteur(A_1,A_2,A_3,A_4,0,0,0,0);
}

int main(void)
{
	int A_1 = 27;
	int A_2 = 17;
	int A_3 = 21;
	int A_4 = 20;
	int pwm0 = 18;
	int pwm1 = 13;
	if(wiringPiSetupGpio() == -1)
	{
			return 1;
	}
	pinMode(pwm0,PWM_OUTPUT);
	pinMode(pwm1,PWM_OUTPUT);
	int cycleD;// entre 0 et 100
	int value = (1024*cycleD)/100;
	printf("Step 1 done\n");
	pwmWrite(pwm0,100);
	pwmWrite(pwm1,100);
	
	printf("Step 2 done\n");
	pinMode(A_1,OUTPUT);
	pinMode(A_2,OUTPUT);
	pinMode(A_3,OUTPUT);
	pinMode(A_4,OUTPUT);
	
	for(cycleD = 0;cycleD <= 100; cycleD += 10)
	{
		value = (1024*cycleD)/100;
		printf("valuePWM? : \n");
		scanf("%d",&value);
		
		
		pwmWrite(pwm0,value);
		pwmWrite(pwm1,value);
		//printf("Working on...\n");
		avancer(A_1,A_2,A_3,A_4);
		delay(1000);
		stop(A_1,A_2,A_3,A_4);
		delay(2000);
		
		reculer(A_1,A_2,A_3,A_4);
		delay(2000);
		stop(A_1,A_2,A_3,A_4);
		delay(2000);
		
		turnLeft(A_1,A_2,A_3,A_4);
		delay(2000);
		stop(A_1,A_2,A_3,A_4);
		delay(2000);
		
		turnRight(A_1,A_2,A_3,A_4);
		delay(2000);
		stop(A_1,A_2,A_3,A_4);
		delay(2000);
		printf("%d\n",cycleD);
	}
	stop(A_1,A_2,A_3,A_4);
	pwmWrite(pwm0,0);
	pwmWrite(pwm1,0);
	return 0;
}
