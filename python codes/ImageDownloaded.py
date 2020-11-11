import random
import urllib.request

def download_image(url):
    name = random.randrange(1,100)
    fullname = str(name)+".jpg"
    urllib.request.urlretrieve(url,fullname)     

#to run the code:
download_image(<image url here>)
