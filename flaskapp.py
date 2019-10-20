from flask import Flask

app  = Flask(__name__)
app.config['SECRET KEY'] = 'this is supposed to be a secret key'

@app.route("/")
def home():
    return "<h1>Hello World using Flask</h1>"

if __name__ == "__main__":
    app.run(debug = True)