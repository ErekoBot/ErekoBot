#
 # @file   main.py
 # @author Samuel Venzi
 # @date   20/09/2016
 #
 # @brief Perfil 2 de comunicação
 #
 # Esse código realiza a comunicação dos módulos com o computador host
 # utilizando o formato pré-definido do segundo perfil, que manda
 # o instante de tempo para cada módulo.
#


import XBee  # XBee é uma classe própria implementada em XBee.py
import math
from time import sleep
# importação de pacotes


if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyUSB0")  # Your serial port name here

    while True:
        data_to_write = str(raw_input(">> ")) # data_to_write recebe o instante de tempo
        
        # conversão para strings para envio
        if data_to_write == 'p':
            data_to_write = "400" # código escolhido para ser comando de parada
        
        # desmenbramento para envio como string
        if len(data_to_write) == 1:
            data_to_write = "00" + data_to_write 
        if len(data_to_write) == 2:
            data_to_write = "0" + data_to_write

        xbee.SendStr(data_to_write, 0xFFFF) # o endereço 0xFFFF faz com que seja feito broadcast