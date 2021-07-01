class Remote:
    def __init__(self, megapi):
        self.megapi = megapi
        self.receiver = self.megapi.InfraredReceiver()
