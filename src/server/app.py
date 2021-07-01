from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/command/<command_name>')
def command(command_name):
    print(command_name)
    return 'success', 200


app.run(debug=True, host='0.0.0.0')
