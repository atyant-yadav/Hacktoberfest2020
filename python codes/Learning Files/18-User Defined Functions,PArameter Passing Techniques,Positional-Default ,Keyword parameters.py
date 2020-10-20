# in this we will see different ways to pass an argument
# 1.positional Argument:if total number of argument in function call 
#and function definition are same, if we send less no. of argument it will 
#return error we cant send more arguments also


#def linear_search (l,key):
#	for index,value in enumerate(l):
#		if key == value:
#			print("Element found ")
#			return index
#	else:
#		print("Element not found")


#l=[100,200,300,400,500,600]
#key=1000

#result=linear_search(l,key)
#print("Element found in ",result,"position")

# 2.Default argument system

#Random Password Generator
# 8 char
# 1 upper
# 1 lower
# 1 special
# 5 digits

#s="A0bC2Dd8k"
#for value in s:
#	s1=value
#	result= isupper(s1)
#	if result == True:
#		print(s1)

#print(chr(90))
#print(ord('z'))

import random
def gen_password():
	captial=chr(random.randint(65,90))
	lower=chr(random.randint(97,122))
	l=['@','#','$','&']
	special=random.choice(l)
	digits=random.randint(10000,99999)
	digit=str(digits)
	result= captial + lower +special +digit
	return result

result=gen_password()
print(result)
# we can also use optional parameter to a function which will be defeault
# . For example if i wont pass any thing then it must return 8 length long
# password, if i pass gen_password(5) if must return 5 didgit long password



#def gen_password(length=8):
#	captial=chr(random.randint(65,90))
#	lower=chr(random.randint(97,122))
#	l=['@','#','$','&']
#	special=random.choice(l)
#	digits=random.randint(10000,99999)
#	digit=str(digits)
#	result= captial + lower +special +digit
#   l = random.sample(password,length)
#   print(l)
#   password=("").join(l)
#	return password
# sample will return the no. of characters from the sample str of provided 
# length and will return a list

# 3.Keyword Argument system


# def validate(username,password):
# 	if username =="ABC" and password=="Abc123":
# 		print("validate password")
# 	else:
# 		print("not validate password")


# validate("ABC", "Abc123")
# validate(password="Abc123",username="ABC")

# example for keyword and default argument sysytem is ur print function
# help(print)
# print(100,200,sep=",",end=" ")
# print("Hi")

# 4. Variable Length positional Argument

# l = [10,20,30,40,50]
# l.append(500)
# print(l)
# append wont add more than one element . write a function which will 
# add more than one element in list 

# add_value(100,200,300,400,500)
# add_value(100,200)
# add_value(10,20,30,4,050,6,70,8,0,90,100)
# Total number of parameters are not fixed

# def add_value(*args):
# 	print(args)


#syntax for variable length paraments 
# all those arguments goes into args in form of tuple and since it is
# tuple we can iterate over it but cant change value


# def add_value2(*u):
# 	l=[]
# 	for value in u:
# 		l.append(value)


# add_value(100,200,300,400,500)
# add_value(100,200)
# add_value(10,20,30,4,50,6,70,8,0,90,100)

# 5.Variable Length Keyword Argument
 # login form 
 # name email contact dob
 # some migth provide email or contact but one is mandatorary

# def get_details(**kwargs):
	# print(kwargs)
# if we use ** it will convert all the input to form of dictionary

# get_details(name="ABC",email="abc@gmail.com",contact=7123456789,dob="12-05-1890")
# get_details(name="ABC",email="abc@gmail.com",dob="12-05-1890")
# get_details(name="ABC",email="abc@gmail.com",contact=7123456789)

