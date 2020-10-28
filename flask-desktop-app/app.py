from flask import Flask , render_template
from flaskwebgui import FlaskUI #get the FlaskUI class

app = Flask(__name__)

# Feed it the flask app instance 
ui = FlaskUI(app)

# do your logic as usual in Flask
@app.route("/")
def index():
  return render_template("boot.html")

# call the 'run' method
ui.run()

