from flask import Flask , render_template
from flaskwebgui import FlaskUI #get the FlaskUI class

app = Flask(__name__)

# Feed it the flask app instance 
ui = FlaskUI(app)

# do your logic as usual in Flask
@app.route("/")
@app.route("/home")
def index():
  return render_template("boot.html")

@app.route("/about")
def about():
  return render_template("about.html")

@app.route("/login")
def login():
  return render_template("login.html")


# call the 'run' method
ui.run()

