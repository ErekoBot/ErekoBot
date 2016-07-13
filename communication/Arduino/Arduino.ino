#include "XBee.h"
#include "queue.h"
#include <Servo.h>


Servo myservo;
XBee xbee;
Queue RxQ;


int pos;

void setup(void)
{
    myservo.attach(9);
    myservo.write(180);
    Serial.begin(9600);
}

void loop(void)
{
    delay(5);
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
                int addr = ((int)msgBuff[4] << 8) + (int)msgBuff[5];

                // 10 is length of "you sent: "
                memcpy(outMsg, "you sent: ", 10);
                // len - (9 bytes of frame not in message content)
                memcpy(&outMsg[10], &msgBuff[8], msgLen-9);

                // 10 + (-9) = 1 more byte in new content than in previous message
                frameLen = xbee.Send(outMsg, msgLen+1, outFrame, addr);
                //Serial.write(outFrame, frameLen);
                i += msgLen;
                delPos = i;
                pos = msgBuff[8];
            }else{
                if (i>0){
                    delPos = i-1;
                }
            }
        }
    }

    RxQ.Clear(delPos);
    
    myservo.write(pos);
    delay(17);
}
