#include <Servo.h>

Servo myservo;
int pos1 = 0, pos2 = 0;
int pos;
char estado;
void setup(){
  myservo.attach(9);
  myservo.write(180);
  Serial.begin(4800);
  pos1 = 0;
  pos2 = 0;
}

void loop(){

  if(Serial.available() > 0){
    pos1 = Serial.read();  //primeiro byte
  }
  if(Serial.available() > 0){
    pos2 = Serial.read();  //segundo byte
  }

    pos = pos1 + pos2;
    Serial.println(pos);
    myservo.write(pos);
    delay(17);
  
}
