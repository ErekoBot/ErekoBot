#
 # @file   main.py
 # @author Samuel Venzi
 # @date   20/09/2016
 #
 # @brief Perfil 1 de comunicação
 #
 # Esse código realiza a comunicação dos módulos com o computador host
 # utilizando o formato pré-definido do primeiro perfil, que manda
 # cada ângulo que o motor do módulo deve estar.
#


import XBee  # XBee é uma classe própria implementada em XBee.py
import math
from time import sleep
# importação de pacotes


def calculate(i): # função que recebe o número do módulo e retorna uma lista com ângulos do respectivo módulo
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
    
    angles_1 = calculate(1)  # cálculo dos ângulos de cada um dos N módulos do robô
    angles_2 = calculate(2)
    angles_3 = calculate(3)
    angles_4 = calculate(4)
    angles_5 = calculate(5)
    angles_6 = calculate(6)

    while True:
        i = 0
        for angle in angles_1:

            content_1 = format(angle, '02x')         # formatação do pacote que será enviado 
            content_2 = format(angles_2[i], '02x')
            content_3 = format(angles_3[i], '02x')
            content_4 = format(angles_4[i], '02x')
            content_5 = format(angles_5[i], '02x')
            content_6 = format(angles_6[i], '02x')

            xbee.Send(bytearray.fromhex(content_1), 0x0001)  # envio dos contents de cada módulo ao seu respectivo endereço
            xbee.Send(bytearray.fromhex(content_2),0x0002)
            xbee.Send(bytearray.fromhex(content_3),0x0003)   # o endereço é definido pelo XCTU para cada XBee escravo
            xbee.Send(bytearray.fromhex(content_4),0x0004)   # em hexadecimal
            xbee.Send(bytearray.fromhex(content_5),0x0005)
            xbee.Send(bytearray.fromhex(content_6),0x0006)
            i += 1

            sleep(0.005)
        
        