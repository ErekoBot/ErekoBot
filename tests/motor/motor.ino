#include <Servo.h>

Servo myservo;

int position = 0;
void setup(){
	myservo.attach(9);
	Serial.begin(9600);
}

void loop(){
	if(Serial.available() > 0){
		position = Serial.read(); //read angle from serial port
		myservo.write(position);
		delay(15);
	}
}
