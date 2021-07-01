from flask import Flask, render_template
from gpiozero import LED

app = Flask(__name__)

led = LED(23)


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
