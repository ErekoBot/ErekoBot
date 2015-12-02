#include <DistanceSensor.h>
#include <UltrasonicDistanceSensor.h>
#include <AnalogDistanceSensor.h>
#include <DistanceGP2Y0A21YK.h>
#include <DistanceGP2Y0A41SK.h>
#include <DistanceSRF04.h>

#include <Servo.h>
#include <Wire.h>

Servo myservo;
char estado;
float d0 = 35, d = 70 , pi = 3.141592, a = pi / 12, k = 1, anguloMotor, M = 5,  i = 2, psi = 0;



void setup(){
  Serial.begin(9600);
  myservo.attach(9);            // conecta o servo no pino 9
  DistanceGP2Y0A41YK Dist;
} 
void loop(){

  while(Serial.available()>0){  //há algo para ler?
    estado = Serial.read(); //Se tem, leia-a  

    while(estado == 'i'){
      anguloMotor = (2 * a * sin(pi * k / M) * sin(psi + ((2 * pi * k / M) * (i - 1 + d0 / d))) * 180 / pi) + 90;    
      myservo.write(anguloMotor); 
      Serial.println(" em movimento ");
      delay(20); 
      delay(20);
      if(psi == 2*pi){
        psi = 0;
      }else{
      psi += pi/180;
      }
    }
  }
}








