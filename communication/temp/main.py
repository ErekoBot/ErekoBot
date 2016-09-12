import XBee
import math
import cv2
from time import sleep

if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyUSB0")  # Your serial port name here


    for i in xrange(0,1000):
        content_1 = format(30, '02x')  
        xbee.Send(bytearray.fromhex(content_1), 0xFFFF)
        print(i)
        sleep(0.01)
            
    print("over")
        
        