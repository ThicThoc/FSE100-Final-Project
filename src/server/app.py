import warnings

from flask import Flask, render_template
from gpiozero.pins.mock import MockFactory
from gpiozero.exc import BadPinFactory, PinFactoryFallback

from gpiozero import Device, LED

# Try-block for developing on non-Pi platforms
# Gracefully test pin and set pin_factory to MockFactory if not on a Pi
try:
    warnings.filterwarnings("ignore", category=PinFactoryFallback)
    led = LED(1)
except BadPinFactory:
    Device.pin_factory = MockFactory
finally:
    warnings.filterwarnings("default", category=PinFactoryFallback)

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/command/<command_name>')
def command(command_name):
    print(command_name)
    if command_name == 'led-on':
        led.on()
    if command_name == 'led-off':
        led.off()
    return 'success', 200


app.run(debug=True, host='0.0.0.0')
