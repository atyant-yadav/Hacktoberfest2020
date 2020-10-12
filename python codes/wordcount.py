counts=dict()
print("please enter the name of your file.\n Make sure the text file is in the-same folder as this python code.")
fname=input()
fhand= open(fname)
for line in fhand:
	words=line.split()
	for word in words:
		counts[word]= counts.get(word,0)+1
print('counts', counts)

bigc= None
bigw=None
for w,c in counts.items():
	if bigc is None or c > bigc:
		bigw= w
		bigc=c
		
print(bigw, bigc)
