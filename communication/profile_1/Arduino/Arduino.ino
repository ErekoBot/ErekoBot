/*
  @file   Arduino.ino
  @author Samuel Venzi
  @date   20/09/2016
 
  @brief Perfil 1 de comunicação
 
  Esse código realiza a comunicação dos módulos com o computador host
  utilizando o formato pré-definido do primeiro perfil, que recebe
  cada ângulo que o motor do módulo deve estar.
*/

#include "XBee.h"
#include "queue.h"
#include <Servo.h>
#include <SoftwareSerial.h>


Servo myservo;
XBee xbee; //Xbee é uma classe própria implementada em XBee.cpp
Queue RxQ; //Queue é uma classe própria de ED fila implementada em queue.cpp

int pos;
bool received;

void setup(void)
{
    myservo.attach(9);
    Serial.begin(9600);
}

void loop(void)
{
    delay(5);

    int queueLen = 0;
    int delPos = 0;

    received = false;

    while (Serial.available() > 0){
        unsigned char in = (unsigned char)Serial.read();
        if (!RxQ.Enqueue(in)){
            break;
        }
    }

    queueLen = RxQ.Size();

    for (int i=0; i < queueLen; i++){  // com uma estrutura de fila, o código abaixo recebe cada byte do pacote
        if (RxQ.Peek(i) == 0x7E){
            unsigned char checkBuff[Q_SIZE];
            unsigned char msgBuff[Q_SIZE];
            int checkLen = 0;
            int msgLen = 0;
            
            checkLen = RxQ.Copy(checkBuff, i);
            msgLen = xbee.Receive(checkBuff, checkLen, msgBuff);
            if (msgLen > 0){
                unsigned char outMsg[Q_SIZE];
                unsigned char outFrame[Q_SIZE];
                int frameLen = 0;
                int addr = ((int)msgBuff[5] << 8) + (int)msgBuff[6];
                             
                // 10 is length of "you sent: "
                memcpy(outMsg, "you sent: ", 10);
                // len - (9 bytes of frame not in message content)
                memcpy(&outMsg[10], &msgBuff[8], msgLen-9);
                
                i += msgLen;
                delPos = i;
                
                pos = msgBuff[8];  // msgBuff[8] é onde está a informação de posição do pacote
                
                received = true; // se recebeu
                  
            }else{
                if (i>0){
                    delPos = i-1;
                }
            }
        }
    }
    RxQ.Clear(delPos);
    if(received == true){   //se recebeu a posição, aplica ao motor
        myservo.write(pos);
        Serial.println(pos); //verificação por print na porta serial
    }

    delay(10);
}
