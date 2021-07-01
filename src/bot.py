from chassis import Chassis
from platform import Platform
from makeblock import MegaPi


class Bot:
    def __init__(self):
        self.megapi = MegaPi.connect()  # or megapi = MegaPi.connect(SerialPort.connect("/dev/ttyXXXX"))
        self.chassis = Chassis(self.megapi)
        self.platform = Platform()

    def run(self):
        pass


bot = Bot()
bot.run()
