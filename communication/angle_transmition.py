import serial

s = serial.Serial('/dev/ttyACM0', baudrate = 9600)
while True:
    data_to_write = str(raw_input(">>"))    #recebe input em forma de string
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