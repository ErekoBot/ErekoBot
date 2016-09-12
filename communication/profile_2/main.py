import XBee
import math
from time import sleep

if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyUSB0")  # Your serial port name here

    while True:
        data_to_write = str(raw_input(">> "))
        if data_to_write == 'p':
            data_to_write = "400"
        if len(data_to_write) == 1:
            data_to_write = "00" + data_to_write
        if len(data_to_write) == 2:
            data_to_write = "0" + data_to_write
        xbee.SendStr(data_to_write, 0xFFFF)