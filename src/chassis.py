import time


class Chassis:
    def __init__(self, megapi):
        self.megapi = megapi
        # self.front_left = self.megapi.DCMotor(1, 1)
        # self.front_right = self.megapi.DCMotor(1, 2)
        # self.rear_left = self.megapi.DCMotor(2, 1)
        # self.rear_right = self.megapi.DCMotor(2, 2)

        self.motor1 = self.megapi.DCMotor(1, 1)
        self.motor2 = self.megapi.DCMotor(1, 2)
        self.motor3 = self.megapi.DCMotor(2, 1)
        self.motor4 = self.megapi.DCMotor(2, 2)

    def _drive(self, motor1, motor2, motor3, motor4):
        self.motor1.run(motor1)
        self.motor2.run(motor2)
        self.motor3.run(motor3)
        self.motor4.run(motor4)

    def _stop(self):
        self.motor1.run(0)
        self.motor2.run(0)
        self.motor3.run(0)
        self.motor4.run(0)

    def drive_forward(self, duration):
        self._drive(50, 50, 50, 50)
        time.sleep(duration)
        self._stop()

    def drive_backward(self, duration):
        self._drive(-50, -50, -50, -50)
        time.sleep(duration)
        self._stop()

    def turn_left(self, duration):
        self._drive(-50, 50, -50, 50)
        time.sleep(duration)
        self._stop()

    def turn_right(self, duration):
        self._drive(50, -50, 50, -50)
        time.sleep(duration)
        self._stop()

    def test_drive(self):
        self.drive_forward(3)
        self.drive_backward(3)
        self.turn_left(3)
        self.turn_right(3)
