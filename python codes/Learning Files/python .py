# 4.5

"""problem 1>>write a python code which compare data that takes as arguments two lists of integer each.
Each lists consists of a month and a year, in that order. The function should return -1 if 
the frist date is earlier than the second date , 0 if both the dates are same , and 1 if 
the frist date is earlier than the second .
example 
>>>compare_date([10,1995],[8,1995])1
>>>compare_date([10,1995],[10,1995])0
>>>compare_date([10,1993],[8,1998])-1"""
#def compare_date(l1,l2):
#	if (l1[1]>l2[1]) or (l1[0]>l2[0] and l1[1]==l2[1]):
#		return 1
#	elif (l1[0]==l2[0] and l1[1]==l2[1]):
#		return 0
#	else:
#		return -1

#result1= compare_date([10,1995],[8,1995])
#result2= compare_date([10,1995],[10,1995])
#result3= compare_date([10,1993],[8,1998])

#print(result1,result2,result3)

"""problem 2>>>Assume v is a list containig numbers . Write a python code to find and print 
the highest two values in v. If the list contains only one number, print only that number. 
If the list is empty , print nothing."""
#def highest(l):
#	if len(l)>0:
#		if len(l)>=2:
#			l.sort()
#			print(l[-2],l[-1])
#		else:
#			print(l[1])
#	else:
#		print("nothing")

#l=[7,3,1,5,10,6]
#highest(l)

"""problem  3>>COnsider the data , name of the restaurant , type of restaurant , and the 
ratings are provided. These are read into lists of lists of teh form below:
restaurants=[['Acme','Italian',2,4,3,5],
			['Flintstone','Steak',5,2,4,3,3,4],
			['Bella troy','Italian',1,4,5]]

Write a python code that prints all italian restaurants in the restaurants lists that 
have no rating of value 1 and at least one rating of value 5. In the above example, Acme 
would be printed ."""

#def find(l):
#	lrestaurant=[]
#	for value in l:
#		for x in value:
#			if x == 'Italian':
#				lrestaurant.append(value)
#	for value in lrestaurant:
#		for x in value:
#			if x==1:
#				break
#			elif x==5:
#				print(value[0])


#restaurants=[['Acme','Italian',2,4,3,5],
#			['Flintstone','Steak',5,2,4,3,3,4],
#			['Bella troy','Italian',1,4,5]]

#find(restaurants)

"""problem 4>>> Assume that u have a code 
			in_file=open(yelp.txt)

			for line in in_file:
				p_line= parse_line(line)
				print p_line 

and parse_line functon will return a list which looks like 
["meka's loudge",42.74,-73.69,"Bars",[5,2,4,4,3,4,5],3.857142857142857]
where the last entry in the list is average rating.
modify the for loop above to creat a list called high that stores the names of all restaurants
that have an average rating of atleast 4.0. You dont have to print high
 """


"""problem 5>>>In a game of chess you can often estimate how well you are doing by adding the
 values of the peices you have captured. The peices are Pawns,Bishops,Knights,Rooks and Queen.
 their values are 
 P -(P)awn, value =1
 B - (B)ishop, value =3
 K - (K)night, value =3
 R - (R)ook , value =5
 Q - (Q)ueen, value =9
Write a code that takes a single string as an argument and returns the combined values 
represented by the pieces in the string. You may assume that only P,B,K,R and Q appear 
in the string. You may not use any if statements and you may not use any for loops. 
As example,
print(chess_score(BQBP))
it must return 16
"""
#def chess_score(str):
#	P=1
#	B=3
#	K=3
#	R=5
#	Q=9
#	p=str.count('P')
#	b=str.count('B')
#	k=str.count('K')
#	r=str.count('R')
#	q=str.count('Q')
#	result=p*P + b*B + k*K + r*R + q*Q
#	return result
#print(chess_score('BQBP'))


""" problem 6>>> Use DeMmorgan's laws to rewrite the following 
boolean expressions using only one not.
(not exp1) and (not exp2)
(not exp1) or (not ex2)"""
# not((exp1) or (exp2))
# not((exp1) and (exp2))

""" problem 7>>> Use distributive law to rewrite the following
ex1 or (ex2 and ex3)
ex1 and (ex2 or ex3)"""
#(ex1 or ex2) and (ex1 or ex3)
#(ex1 and ex2) or ( ex1 and ex3)

""" problem 9>>>Write a programe that sums all th frist integers , and second integers,and the thrid integes outputting the resulting sums all.
ex 
[2,5,7]
[3,6,10]
[1,2,-3]
[2,4,1]
the result must be [8,17,15]"""
#l1=[2,5,7]
#l2=[3,6,10]
#l3=[1,2,-3]
#l4=[2,4,1]
#lresult=[]
#for i in range(len(l1)):
#	lresult.append(l1[i]+l2[i]+l3[i]+l4[i])
#print(lresult)

"""problem 10>> Write a python code to generate the following ranges 
a)(100,99,98,....,0)
b)(55,53,51,...,-1)
c)(3,5,7,9,....,29)
d)(-95,-90,-85,...,85,90)"""
#c)
#for value in range(3,30,3):
#	print(value)
#d)
#for value in range(-95,95,5):
#	print(value)

#a)
#l=list(range(100,-1,-1))
#print(l)
#b)
#l=list(range(55,-2,-2))
#print(l)




"""Write a programe that sums all th frist integers , and second integers,and the thrid integes outputting the resulting sums all.
ex 
[2,5,7]
[3,6,10]
[1,2,-3]
[2,4,1]
the result must be [8,17,15]
"""
#l1=[2,5,7]
#l2=[3,6,10]
#l3=[1,2,-3]
#l4=[2,4,1]
#l5=l1 + l2 +l3 +l4
#lresult=[]

#sum2=0
#sum1=0
#sum=0
#for value in lstart:
#	sum=sum+value
#lresult.append(sum)
#
#for value1 in lmiddle:
#	sum1=sum1+value1
#lresult.append(sum1)
#for value in llast:
#	sum2=sum2+value
#lresult.append(sum2)
#print(lresult)

#Original answer
#l1=[2,5,7]
#l2=[3,6,10]
#l3=[1,2,-3]
#l4=[2,4,1]
#lresult=[]
#for i in range(len(l1)):
#	lresult.append(l1[i]+l2[i]+l3[i]+l4[i])
#print(lresult)




""" problem 11>> Write a while loop to add all of the numbers in a list v until it reaches
a negative number or until it reaches the end of the list."""

#def sum(list):
#	x=list[0]
#	sum=0
#	count=1
#	if x<0:
#		return sum 
#	else:
#		while(x >= 0 and count <=len(list)):
#			sum=sum+x
#			x = list[count]
#			count=count+1
#	return sum
#list=[5,12,13,-1]
#result=sum(list)
#print(result)

"""Write code that take a list of numbers, v , and outputs the positive values that are 
in v in incresing order , one value per line.If there is no positive value, then the 
output shouldbbe the string 'none'. you may assume that at least one value in the list.
example 
v=[17,-5,15,-3,12,-5,0,12,22,-1]
the the output of the code should be
12
12
15
17
22
"""

#v=[-5,-15,-3,-12,-5,0,-12,-22,-1]
#v.sort()
#sum=0
#for value in v:
#	if value <=0:
#		continue
#	else:
#		print(value)
#		sum=sum+value
#if value ==0:
#	print("none")""" 