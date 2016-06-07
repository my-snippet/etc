class Temparature():

    def __init__(self, celsius):
        self.celsius = celsius

    @property
    def farenheit(self):
        return self.celsius * (9 / 5) + 32
