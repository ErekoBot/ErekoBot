import serial
import time
import math

s = serial.Serial('/dev/ttyUSB0', baudrate = 9600)

d0 = 42
d = 81
pi = 3.141592
a = 20 * pi/180
k = 2
M = 5
i = 1
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

while True:
    for angle in angles:
        print angle
        int_data = int(angle)
        angle2 = 0
        int_data2 = 0
        if int_data > 127:
            int_data2 = int_data - 127
            int_data = 127
        angle = unichr(int_data)
        angle2 = unichr(int_data2)
        s.write(angle)
        s.write(angle2)
        time.sleep(0.017)

