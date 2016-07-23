import XBee
import math
from time import sleep

if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyUSB1")  # Your serial port name here

    while True:
        data_to_write = str(raw_input(">>"))
        xbee.SendStr(data_to_write, 0xFFFF)