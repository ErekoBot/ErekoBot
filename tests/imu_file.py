import serial

s = serial.Serial('/dev/ttyACM0', baudrate = 9600)

f = open("imu_data.txt", "w")
data_to_write = str(raw_input(">>"))
s.write(data_to_write)
while True:
	line = s.read()
	f.write(line)

f.close()
