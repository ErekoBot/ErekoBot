import serial
from math import*

d0 = 42
d = 81
pi = 3.141592
a = 20 * pi/180
k = 2
M = 5
i = 1
psi = 0

angle_list = []

while psi < 2*pi:
	angle = (2*a*sin(pi*k/M)*sin(psi+((2*pi*k/M) * (i-1+d0/d)))*180/pi) + 90
	angle = int(angle)
	print angle
	psi += pi/180
	angle_list.append(angle)



s = serial.Serial('/dev/ttyACM0', baudrate = 9600)
while True:
    #data_to_write = str(raw_input(">>"))    #recebe input em forma de string
    
    int_data = int(data_to_write)           #transforma a string em integer (exemplo  "100" vira 100)
    data2_to_write = 0                      #essa variavel servira de auxiliar caso o valor seja maior que 127
    int_data2 = 0;                          #essa variavel recebera o valor inteiro de data2_to_write
    if int_data > 127:                      #caso o valor de int_data nao caiba em 1 byte, sera dividido em dois
        int_data2 = int_data - 127
        int_data = 127
    data_to_write = str(unichr(int_data))   #os valores de data_to_write sao atualizados para char e enviados 
    data2_to_write = str(unichr(int_data2))
    s.write(data_to_write)                  #primeiro byte de informacao
    s.write(data2_to_write)                 #segundo byte de informacao 