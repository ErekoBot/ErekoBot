#include <CommunicationUtils.h>
#include <DebugUtils.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <FreeSixIMU.h>
#include <Wire.h>

float angles[3]; // yaw pitch roll
char estado;
FreeSixIMU sixDOF = FreeSixIMU();

void setup(){
 Serial.begin(9600); 
 delay(5);
 sixDOF.init(); //begin the IMU
 delay(5);
}

void loop(){
  if(Serial.available()>0){
    estado = Serial.read();
  }
  while(estado == 'i'){
    sixDOF.getEuler(angles);
    Serial.print(" X   ");
    Serial.print(angles[0]);
    Serial.print(" | ");  
    Serial.print(" Y   ");
    Serial.print(angles[1]);
    Serial.print(" | ");
    Serial.print(" Z   ");
    Serial.println(angles[2]);
    
    delay(50);
  }
}  
