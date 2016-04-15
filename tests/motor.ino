#include <Servo.h>

Servo myservo;

int position = 0, flag = 0;
void setup(){
	myservo.attach(9);
	Serial.begin(9600);
}

void loop(){
	while(flag == 0){
		if(Serial.available() > 0){
			position = Serial.read(); //read angle from serial port
			myservo.write(position);
			delay(15);
		}
	}
}