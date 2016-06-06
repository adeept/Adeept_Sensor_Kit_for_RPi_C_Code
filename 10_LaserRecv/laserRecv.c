/*
* File name   : laserRecv.c
* Description : laser receive
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/04
*/
#include <wiringPi.h>
#include <stdio.h>

#define  LaserRecv   0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(LaserRecv, INPUT);

	while(1){
		if(digitalRead(LaserRecv) == 0){
			printf("Laser received...\n");
		}
		printf("...Laser not received!\n");
	}

	return 0;
}

