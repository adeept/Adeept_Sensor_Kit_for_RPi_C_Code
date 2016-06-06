/*
* File name   : laser.c
* Description : laser transmitter
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/04
*/
#include <wiringPi.h>
#include <stdio.h>

#define  LaserPin   0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LaserPin, OUTPUT);

	while(1){
		digitalWrite(LaserPin, LOW);
		printf("OFF...\n");
		delay(1000);
		digitalWrite(LaserPin, HIGH);
		printf("...ON\n");
		delay(1000);
	}

	return 0;
}

