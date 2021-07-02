from chassis import Chassis
from platform import Platform
from makeblock import MegaPi


class Bot:
    def __init__(self):
        self.megapi = MegaPi.connect()  # or megapi = MegaPi.connect(SerialPort.connect("/dev/ttyXXXX"))
        self.chassis = Chassis(self.megapi)
        self.platform = Platform(self.megapi)
        self.megapi.start()

    def run(self):
        # Test each motor individually in order to identify them
        for _ in range(3):
            self.chassis.test_drive()


bot = Bot()
bot.run()
