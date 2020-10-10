import pyshorteners

short = pyshorteners.Shortener()

print(" { URL Shortener by belux }")
url = input("Your URL : ")
hasil = short.tinyurl.short(url)
print("Output : " + hasil)
