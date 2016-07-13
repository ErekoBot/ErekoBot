import XBee
import AngleCalculator
from time import sleep

if __name__ == "__main__":
    xbee = XBee.XBee("/dev/ttyACM0")  # Your serial port name here
    
    calculator = AngleCalculator.AngleCalculator()
    calculator.calculate() 
    angles = calculator.get_angles()

    while True:
        for angle in angles:
            content = format(angle, '02x')
            xbee.Send(bytearray.fromhex(content))   
            sleep(0.02)

