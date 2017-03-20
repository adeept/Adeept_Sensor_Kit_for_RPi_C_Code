/*
* File name   : flame.c
* Description : fire detection
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/06
*/
#include <wiringPi.h>
#include <stdio.h>

#define Flame_S  0

void myISR(void)
{
	printf("Fire detected !!!\n");	
}

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(Flame_S, INPUT);

	pullUpDnControl(Flame_S, PUD_UP);
	
	if(wiringPiISR(Flame_S, INT_EDGE_FALLING, myISR) < 0){
		printf("ISR setup error!\n");
		return -1;
	}

	while(1){
		printf("test...\n");
		delay(100);
	}

	return 0;
}
