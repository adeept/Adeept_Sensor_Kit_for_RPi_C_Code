#include <wiringPi.h>
#include <stdio.h>

#define TrackSensorPin_S  0

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	
	pinMode(TrackSensorPin_S, INPUT);

	while(1){
		if(digitalRead(TrackSensorPin_S) == LOW){
			printf("White line is detected\n");
			delay(100);
		}	
		else{
			printf("...Black line is detected\n");
			delay(100);
		}
	}

	return 0;
}
