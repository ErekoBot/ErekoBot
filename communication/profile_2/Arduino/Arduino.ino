#include "XBee.h"
#include "queue.h"
#include <Servo.h>
#include <SoftwareSerial.h>


Servo myservo;
XBee xbee;
Queue RxQ;

bool flag;
int angles[] = {90, 90, 91, 91, 92, 93, 93, 94, 95, 95, 96, 97, 97, 98, 99, 99, 100, 101, 101, 102, 103, 103, 104, 104, 105, 106, 106, 107, 107, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 119, 120, 120, 121, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 128, 128, 128, 128, 128, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 125, 125, 125, 125, 125, 124, 124, 124, 123, 123, 123, 122, 122, 122, 121, 121, 121, 120, 120, 119, 119, 119, 118, 118, 117, 117, 116, 116, 115, 115, 114, 114, 113, 113, 112, 112, 111, 111, 110, 110, 109, 109, 108, 107, 107, 106, 106, 105, 104, 104, 103, 103, 102, 101, 101, 100, 99, 99, 98, 97, 97, 96, 95, 95, 94, 93, 93, 92, 91, 91, 90, 90, 89, 88, 88, 87, 86, 86, 85, 84, 84, 83, 82, 82, 81, 80, 80, 79, 78, 78, 77, 76, 76, 75, 75, 74, 73, 73, 72, 72, 71, 70, 70, 69, 69, 68, 68, 67, 67, 66, 66, 65, 65, 64, 64, 63, 63, 62, 62, 61, 61, 60, 60, 60, 59, 59, 58, 58, 58, 57, 57, 57, 56, 56, 56, 55, 55, 55, 54, 54, 54, 54, 54, 53, 53, 53, 53, 53, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 51, 51, 51, 51, 51, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 53, 53, 53, 53, 53, 54, 54, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58, 58, 58, 59, 59, 60, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 69, 69, 70, 70, 71, 72, 72, 73, 73, 74, 75, 75, 76, 76, 77, 78, 78, 79, 80, 80, 81, 82, 82, 83, 84, 84, 85, 86, 86, 87, 88, 88, 89, 89, 90};

void setup(void)
{
    myservo.attach(9);
    Serial.begin(9600);
}

void loop(void)
{
    int t_instant;
    t_instant = receive();
    
    int len = sizeof(angles)/sizeof(int);
    while(flag){
      Serial.println("Entered while");
      for(int j = t_instant; j < len; j++){
        Serial.println("Entered for");
        if(j == len - 1){
          myservo.write(angles[j]);
          j = 0;
          delay(10);
          }
          myservo.write(angles[j]);
          delay(10);
        }
        
      }

}

int receive(){
    
    delay(5);
    int t_instant;
    int queueLen = 0;
    int delPos = 0;
   
    while (Serial.available() > 0){
        unsigned char in = (unsigned char)Serial.read();
        if (!RxQ.Enqueue(in)){
            break;
        }
    }

    queueLen = RxQ.Size();
    for (int i=0;i<queueLen;i++){
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

                // 10 + (-9) = 1 more byte in new content than in previous message
                //frameLen = xbee.Send(outMsg, msgLen+1, outFrame, addr);
                //Serial.write(outFrame, frameLen);
                i += msgLen;
                delPos = i;
                
                t_instant = msgBuff[8];
                  
            }else{
                if (i>0){
                    delPos = i-1;
                }
            }
        }
    }
  RxQ.Clear(delPos);
  
  return t_instant;
  }

