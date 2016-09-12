import XBee
import math
import cv2
from time import sleep

def calculate(i):
    d0 = 42
    d = 81
    pi = 3.141592
    a = 20 * pi/180
    k = 2
    M = 5
    psi = 0
    flag = True
    x = 1
    angles = []

    while flag:
        angle = (2*a* math.sin(pi*k/M) * math.sin(psi+((2*pi*k/M)*(i-1+d0/d)))*180/pi) + 90
        angle = int(angle)
        angles.append(angle)
        print(angle)
        if psi > 2*pi:
            flag = False
        psi += pi/180
    return angles


if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyUSB0")  # Your serial port name here
    
    angles_1 = calculate(1)
    angles_2 = calculate(2)
    angles_3 = calculate(3)
    angles_4 = calculate(4)
    angles_5 = calculate(5)
    angles_6 = calculate(6)

    while True:
        i = 0
        for angle in angles_1:
            content_1 = format(angle, '02x')
            content_2 = format(angles_2[i], '02x')
            content_3 = format(angles_3[i], '02x')
            content_4 = format(angles_4[i], '02x')
            content_5 = format(angles_5[i], '02x')
            content_6 = format(angles_6[i], '02x')
            print(angle)
            xbee.Send(bytearray.fromhex(content_1), 0x0001)  
            # xbee.Send(bytearray.fromhex(content_2),0x0002)
            # xbee.Send(bytearray.fromhex(content_3),0x0003)
            # xbee.Send(bytearray.fromhex(content_4),0x0004)
            # xbee.Send(bytearray.fromhex(content_5),0x0005)
            # xbee.Send(bytearray.fromhex(content_6),0x0006)
            i += 1
            sleep(0.005)
            
        print("over")
        
        