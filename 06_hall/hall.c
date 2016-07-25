#include <wiringPi.h>
#include <stdio.h>

#define HallPin    1
#define LedPin     0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !\n");
		
		return -1; 
	}

	pinMode(HallPin, INPUT);
	pinMode(LedPin, OUTPUT);

	while(1){
		if(0 == digitalRead(HallPin)){
			delay(10);
			if(0 == digitalRead(HallPin)){
				while(!digitalRead(HallPin));
				digitalWrite(LedPin, !digitalRead(LedPin));	
				printf("Magnetic materials detected!\n");	
			}
		}
	}

	return 0;
}
