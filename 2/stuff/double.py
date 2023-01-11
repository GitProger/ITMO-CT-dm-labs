class double:
    def of(x):
        if type(x) == int:
            return double(x)
        else:
            return x
    def __init__(self):
        pass
    def __init__(self, x, y=1):
        self.x = x // gcd(x, y)
        self.y = y // gcd(x, y)
    def __str__(self):
        return "{" + str(self.x) + "/" + str(self.y) + "}"
    def __abs__(self):
        return abs(self.x / self.y)
    def minus(self):
        return double(-self.x, self.y)
    def inv(self):
        return double(self.y, self.x)
    def __add__(self, d):
        return double(self.x * d.y + d.x * self.y, d.y * self.y)
    def __mul__(self, d):
        return double(self.x * d.x, self.y * d.y)
    def __sub__(self, d):
        return self.__add__(d.minus())
    def __truediv__(self, d):
        return self.__mul__(d.inv())
