"""A programe which will find all such numers between 1000 and 3000
such that each digit of the number is an even number"""

#num1=0
#num2=0
#num3=0
#num4=0
#real=0
#lresult=[]
#def even(num,num1,num2,num3,real):
#	if (num%2==0) and (num1%2==0) and (num2%2==0) and (num3%2==0):
#		lresult.append(real)

#for value in range(1000,3001):
#	real=value
#	while(value!=0):
#		num1=value%10
#		value=value/10
#		num2=value%10
#		value=value/10
#		num3=value%10
#		value=value/10
#		num4=value
#	even(num1,num2,num3,num4,real)
#print(lresult)
		

"""v is a list containig numbers. write code to find and print the highest two values 
in v. If the list contains only one number, print only that number. If the list is empty,
print nothing .
For example
v=[7,3,1,5,10,6]
output,l=[7,10]"""

#v=[7,3,1,5,10,6]
#maxvalue=v[0]
#secmax=maxvalue
#for value in v:
#	if value >= maxvalue:
#		secmax=maxvalue
#		maxvalue=value
#	else:
#		continue
#print(secmax,maxvalue)


"""Write a programe that takes two different lists as inouts and returns the smallest value that appears in both lists.
example 
l1=[1,3,8,12,12,15,20]
l2=[7,9,10,11,15,30,35]
l3=[2,4,5,13,16,17,23,25]
then
print smallest_in_common(l1,l2) should output 15
print smallest_in_common(l1,l3) should output None"""
#def smallest_in_common(s1,s2):
#	s4=s1.intersection(s2)
#	small=0
#	for value in s4:
#		small=value
#		break
#	for x in s4:
#		if x < small:
#			small=x
#		else:
#			continue
#	print(small)
#l1=[1,3,8,12,12,15,20]
#l2=[7,9,10,11,15,30,35]
#l3=[2,4,5,13,16,17,23,25]
#s1=set(l1)
#s2=set(l2)
#s3=set(l3)
#smallest_in_common(s1,s2)
#smallest_in_common(s1,s3)

"""Python code that takes a list of numbeers, and outputs the positive values that
are in v in incresing order, if there are no positive values, then the output should
be none. for example l=[17,-5,15,-3,12,-5,0,12,22,-1]
then the output of the code'[12,12,15,17,22]"""

#l=[17,-5,15,-3,12,-5,0,12,22,-1]
#l2=[]
#l.sort()
#print(l)
#for value in l:
#	if value>0:
#		l2.append(value)
#print(l2)




"""given a list of test scores, where the maximum score is 100,write cod that prints
the nmber of scrores that are in the range 0-9,10-19,20-29,....80-89,90-100.For 
example given the list of scores
[12,90,10,52,56,76,92,83,39,77,73,70,80]
 
 the output should be :
 (0,9):0,(10,19):1,(20,29):0,(30,39):1,(40,49):0,(50,59):2,(60,69):0,(70,79):4,
 (80,89):2,(90,100):3"""

#l=[12,90,10,52,56,76,92,83,39,77,73,70,80]
#key1=0
#key2=0
#key3=0
#key4=0
#key5=0
#key6=0
#key7=0
#key8=0
#key9=0
#key10=0

#for value in l:
#	if value <=9:
# 		key1=key1+1
#	elif value <=19:
#		key2=key2+1
#	elif value<19:
# 		key3=key3+1
#	elif value <39:
# 		key4=key4+1
#	elif value <=49:
#		key5=key5+1
#	elif value <=59:
# 		key6=key6+1
#	elif value <=69:
# 		key7=key7+1
#	elif value <=79:
# 		key8=key8+1
#	elif value <=89:
# 		key9=key9+1
#	else:
# 		key10=key10+1

#d={(0,9):key1,(10,19):key2,(20,29):key3,(30,39):key4,(40,49):key5,(50,59):key6,(60,69):key7,(70,79):key8,(80,89):key9,(90,100):key10}
#print(d)

"""A Programe to read elements in a matrix and check whether the matrix is 
identity matrix or not .
Identity matrix is a special square matrix whose diagonal elements is equal to 1 and
other elements are 0
Input elements in atrix 
[[1,0,0],
[0,1,0],
[0,0,1]]

output
Its an identity matrix"""

#l=[[1,0,0],[0,1,0],[0,0,1]]
#l2=[]
#for value in l:
#	for val in value:
#		l2.append(val)
#l3=l2[::4]
#if sum(l3)==sum(l2):
#	print("given matrix is an identity matrix")

'''
Practice Question on dictionaries in Python:
-------------------------------------------
1) Given a dictionary that associates the names of states with a list of the names of cities that appear in it,
write a program that creates a new dictionary that associates the name of a city with the list of states that it appears in.
As an example, if the first dictionary is 

states = {'New Hampshire': ['Concord', 'Hanover'],
'Massachusetts': ['Boston', 'Concord', 'Springfield'],
'Illinois': ['Chicago', 'Springfield', 'Peoria']}

cities = {'Hanover': ['New Hampshire'],
'Chicago': ['Illinois'],'Boston': ['Massachusetts'],
'Peoria': ['Illinois'],'Concord': ['New Hampshire', 'Massachusetts'],Springfield': ['Massachusetts', 'Illinois']}
'''
'''
states = {'New Hampshire': ['Concord', 'Hanover'],
'Massachusetts': ['Boston', 'Concord', 'Springfield'],
'Illinois': ['Chicago', 'Springfield', 'Peoria']}

cities = {}

for k,v in states.items():
    for idx in v:
        if idx in cities.keys():
            cities[idx].append(k)
        else:
            cities.setdefault(idx,[k])
print(cities)
'''
