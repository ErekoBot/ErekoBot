import math


d0 = 42
d = 81
pi = 3.141592
a = 20 * pi/180
k = 2
M = 5
i = 1
psi = 0
flag = True
while flag:
    angle = (2*a* math.sin(pi*k/M) * math.sin(psi+((2*pi*k/M)*(i-1+d0/d)))*180/pi) + 90
    print(angle)
    if psi > 2*pi:
        flag = false
    psi += pi/180

