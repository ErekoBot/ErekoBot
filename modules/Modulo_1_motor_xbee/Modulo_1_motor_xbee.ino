#include <Servo.h>

Servo Motor;

char estado,sair;
float d0 = 42, d = 81 , pi = 3.141592, a = 20 * pi/180, k = 2, anguloMotor, M = 5,  i = 1, psi = 0, distancia;

void setup(){
  Serial.begin(9600);
  Motor.attach(9);            // conecta o servo no pino 9
}

void loop(){
  if(Serial.available()>0){  //há algo para ler?
    estado = Serial.read(); //Se tem, leia-a  
  }
  
  while(estado == 'i'){
    anguloMotor = (2 * a * sin(pi * k / M) * sin(psi + ((2 * pi * k / M) * (i - 1 + d0 / d))) * 180 / pi) + 90;    
    Motor.write(anguloMotor); 
    if(psi == 2*pi){
      psi = 0;
    }
    psi += pi/180;
    if(Serial.available()>0){  //há algo para ler?
      estado = Serial.read(); //Se tem, leia-a  
      }
    }
    delay(7); 
  
  delay(5);
}



















