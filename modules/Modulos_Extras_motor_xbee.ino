

#include <Servo.h>
Servo Motor;

char estado,sair;
//Varie o i dependendo do modulo, se for o modulo 2, i= 2, modulo 3, i =3 ...

float d0 = 45, d = 85 , pi = 3.141592, a = pi * 20 / 180, k = 2, anguloMotor, M = 5 ,  i = 3 , psi = 0,distancia;

void setup(){
  Serial.begin(9600); 
  Motor.attach(9);            // conecta o servo no pino 9
}  
void loop(){
  if(Serial.available()>0){  //há algo para ler?
    estado = Serial.read(); //Se tem, leia-a  
    if(estado == 'i' ){
      Serial.println(" Li ");
    }  
  }
  while(estado == 'i'){
    anguloMotor = (2 * a * sin(pi * k / M) * sin(psi + ((2 * pi * k / M) * (i - 1 + d0 / d))) * 180 / pi) + 90;    
    Motor.write(anguloMotor); 
    Serial.println(" Movimento ");


    if(psi == 2*pi){
      psi = 0;
    }
    psi += pi/180;

    if(Serial.available()>0){  //há algo para ler?
      sair = Serial.read(); //Se tem, leia-a  
      if(sair == 'p' ){
        Serial.println(" Parado ");
        estado = 'p';
      }
    }
    delay(7); 
  }
  delay(5);


}






