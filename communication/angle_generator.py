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
text_file = open("angles.txt","w")

while flag:
    angle = (2*a* math.sin(pi*k/M) * math.sin(psi+((2*pi*k/M)*(i-1+d0/d)))*180/pi) + 90
    print(angle)
    angle = str(int(angle))
    text_file.write(angle)
    text_file.write(", ")
    if psi > 2*pi:
        flag = False
    psi += pi/180

text_file.close()