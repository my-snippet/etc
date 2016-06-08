class Temparature():

    def __init__(self, celsius):
        self.celsius = celsius
        self.farenheit = celsius * (9 / 5) + 32

    @property
    def temparature(self):
        return {'celsius': self.celsius, 'farenheit': self.farenheit}

    @temparature.setter
    def temparature(self, celsius):
        self.celsius = celsius
        self.farenheit = celsius * (9 / 5) + 32

    def __repr__(self):
        self.temparature += 10
        return ('celsius %d, farenheit %d' % (self.celsius, self.farenheit))
