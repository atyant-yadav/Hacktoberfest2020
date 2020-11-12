import requests
from bs4 import BeautifulSoup

content=requests.get("https://www.flipkart.com/laptops/~intel-top/pr?sid=6bo%2Cb5g&otracker=hp_bannerads_2_1.bannerAdCard.BANNERADS_Intel_PY4GIV96TE6Q")
#print(content)

soup = BeautifulSoup(content.content,"html.parser")
#print(soup.prettify())

cards = soup.find_all("div",attrs={"class":"_1UoZlX"})
#print(card)
for card in cards:
	price=card.find("div",attrs={"class":"_1vC4OE _2rQ-NK"})
#print(price.text)

	title = card.find("div",attrs={"class":"_3wU53n"})
#print(title.text)
	specs=card.find("div",attrs={"class":"_3ULzGw"})
	data='{} {} {}'.format((price.text),(title.text),(specs.txt))
	print(data)