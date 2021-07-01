import gpiozero


class Platform:
    def __init__(self):
        self.vcc = 1
        self.gnd = 2
        # set mode to output for both

    def elevate(self):
        pass
        # write high to one, low to other

    def lower(self):
        pass
        # write inverse of elevate
