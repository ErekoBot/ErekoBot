import math

class AngleCalculator():
    """docstring for AngleCalculator"""
    d0 = 42
    d = 81
    pi = 3.141592
    a = 20 * pi/180
    k = 2
    M = 5
    i = 1
    psi = 0
    flag = True
    x = 1
    angles = []

    def __init__(self, arg=0):
        self.arg = arg

    def calculate(self):
        while self.flag:
            angle = (2*self.a* math.sin(self.pi*self.k/self.M) * math.sin(self.psi+((2*self.pi*self.k/self.M)*(self.i-1+self.d0/self.d)))*180/self.pi) + 90
            angle = int(angle)
            self.angles.append(angle)
            print(angle)
            if self.psi > 2*self.pi:
                self.flag = False
            self.psi += self.pi/180
        return 0

    def get_angles(self):
        return self.angles;
