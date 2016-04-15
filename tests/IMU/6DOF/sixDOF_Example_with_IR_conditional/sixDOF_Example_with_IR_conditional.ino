#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <Servo.h>
#include <Wire.h>

float angles[3]; // yaw pitch roll
Servo myservo;
float d0 = 35, d = 70 , pi = 3.141592, a = pi / 12, k = 1, anguloMotor, M = 5,  i = 2, psi = 0;

// Set the FreeSixIMU object
FreeSixIMU sixDOF = FreeSixIMU();

void setup() {   
  Serial.begin(9600);
  Wire.begin();
  pinMode(13, OUTPUT);
  myservo.attach(9);
  delay(5);
  sixDOF.init(); //begin the IMU
  delay(5);
}

void loop() { 
  sixDOF.getEuler(angles);  
  
  if(angles[1] < -10 || angles[1] > 10){
    sixDOF.getEuler(angles);
    Serial.print(angles[0]);
    Serial.print(" | ");  
    Serial.print(angles[1]);
    Serial.print(" | ");
    Serial.println(angles[2]);
    
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
  else{}

  if(angles[1] > -10 && angles[1] < 10){
      digitalWrite(13, HIGH);
    }
    else{
      digitalWrite(13, LOW);
    }

  
  delay(100); 
}

