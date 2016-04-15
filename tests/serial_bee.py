import serial

s = serial.Serial('/dev/ttyACM0', baudrate = 9600)
while True:
    data_to_write = str(raw_input(">>"))
    s.write(data_to_write)