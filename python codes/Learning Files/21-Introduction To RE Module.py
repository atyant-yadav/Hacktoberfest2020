import re

#. - it will match with any char expt new line
#[a-zA-Z] - char class a or b or c .... or A or B....
#[0-9] - digit class 
# These all match only one character

#if you want multiple occurence to be matched
# + at least one 
#* - zero or more


# If u want to match something at the start of a experession
#^- start of the string
#$ -end of the string

#? - optional 
# [a-z]{2,4}


# validate a PAN number  
#[a-z]{2,4}

#s="ABCDE1234A"
#r = re.compile("^[A-Z]{5}[0-9]{4}[A-Z]{1}$")
#l=re.findall(r,s)
#print(l)

#help(re)

# s="+91 9381569588"
# r=re.compile("(?:\+91\s)?([6-9]{1}[0-9]{9})")
#l=re.findall(r,s)
#print(l)
m=re.search(r,s)
if m:
	print(m.group())
else:
	print("Match not found")




#dd-mm-yyyy
#d="08-02-2001"
#r=re.compile("^(?P<date>[0-9]{2})-(?P<month>[0-9]{2})-(?P<year>[0-9]{4})$")
#l=re.findall(r,d)
#print(l)

#m = re.search(r,d)
#print(m.group())
#if m:
#	print(m.group("month"))
#else:
#	print("Match not found")


