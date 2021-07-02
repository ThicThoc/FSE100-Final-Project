
class Platform:
    def __init__(self, megapi):
        self.megapi = megapi
        self.actuator = megapi.Motor

    def elevate(self):
        pass
        # write high to one, low to other

    def lower(self):
        pass
        # write inverse of elevate
