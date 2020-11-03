from flask import Flask, jsonify, request
from flask_cors import CORS, cross_origin
from datetime import datetime, timedelta

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

@app.route('/')
@cross_origin()
def home():
  return 'Hello Flask API'

@app.route('/api/brazildate', methods=['GET'])
@cross_origin()
def get_date():
  return (datetime.now() - timedelta(hours=3)).strftime("%d/%m/%Y %H:%M:%S")

if __name__ == "__main__":
  app.run(threaded=True, port=5000)