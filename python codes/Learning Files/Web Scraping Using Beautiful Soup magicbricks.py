import requests
from bs4 import BeautifulSoup

responce = requests.get("https://www.magicbricks.com/property-for-sale/residential-real-estate?&proptype=Multistorey-Apartment,Builder-Floor-Apartment,Penthouse,Studio-Apartment,Service-Apartment,Residential-House,Villa&cityName=Bangalore&mbTrackSrc=tabChange&page=1&category=S")
#print(responce.status_code)
#print(type(responce))
content=BeautifulSoup(responce.content,"html.parser")
#print(type(content))
#print(content.prettify())
card=content.find("div",attrs={"class":"flex relative clearfix m-srp-card__container"})
#print(card)
price=card.find("div",attrs={"class":"m-srp-card__price"})
print(price.text)
title=card.find("div",attrs={"class":"m-srp-card__heading clearfix"})
print(title.text)