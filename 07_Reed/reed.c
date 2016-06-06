/*
* File name   : reed.c
* Description : Toggle a led by reed switch.
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/04
*/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    0
#define ReedPin   1

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ReedPin, INPUT);

	pullUpDnControl(ReedPin, PUD_DOWN);

	while(1){
		if(digitalRead(ReedPin)){
			digitalWrite(LedPin, 0);	
			printf("LED ON...\n");
		}	
		digitalWrite(LedPin, 1);	
		printf("LED OFF...\n");
	}

	return 0;
}
