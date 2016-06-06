/*
* File name   : motor.c
* Description : controlling a 5V DC motor
* Website     : www.adeept.com
* E-mail      : support@adeept.com
* Author      : Jason
* Date        : 2016/06/04
*/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define MotorPin_A   0
#define MotorPin_B   1

void motor(int status, int dir)
{
	pinMode(MotorPin_A, OUTPUT);
	pinMode(MotorPin_B, OUTPUT);
	
	if(0 == status){   //stop
		digitalWrite(MotorPin_A, HIGH);
		digitalWrite(MotorPin_B, HIGH);
	}else{  //run
		if(0 == dir){  //clockwise
			digitalWrite(MotorPin_A, HIGH);
			digitalWrite(MotorPin_B, LOW);
		}else{  //anticlockwise
			digitalWrite(MotorPin_A, LOW);
			digitalWrite(MotorPin_B, HIGH);
		}
	}
}

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !\n");
		return -1; 
	}

	while(1){
		motor(1, 1);
		delay(5000);

		motor(0, 1);//stop
		delay(5000);

		motor(1, 0);
		delay(5000);
	}

	return 0;
}
