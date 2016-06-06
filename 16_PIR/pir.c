/*
* File name   : Pir.c
* Description : Intrusion detection
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/06
*/
#include <wiringPi.h>
#include <stdio.h>

#define Pir_S  0

void myISR(void)
{
	printf("Someone invasion !!!\n");	
}

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(Pir_S, INPUT);

	pullUpDnControl(Pir_S, PUD_DOWN);
	
	if(wiringPiISR(Pir_S, INT_EDGE_RISING, myISR) < 0){
		printf("ISR setup error!\n");
		return -1;
	}

	while(1){
	
	}

	return 0;
}
