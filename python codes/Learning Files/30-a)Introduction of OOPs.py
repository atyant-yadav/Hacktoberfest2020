# Definitions: In OOPs we just dont stick to the datatypes we also specifiy the behaviour
# of the datatype, those data is called as objects.
# for example
# student = John 
# we just assigned a data to variable 
# but in OOPs we say John is ... , John sleeps ... ,etc

# superhero="Tony Stark"
# if we want to specify the about him we use OOPs 
# like "Toy Stark will build a time machine "

# there are 
# abstraction:
# the main goal of abstraction is hide the unnessary information from user
# Example coffee machine

# Encapsulation:
# Grouping together logical connected data into 1 unit
# Usually we use Classes in code , it is Encapsulation
# Datahiding is one of the main point.
# Example:Mobile
# In Mobile the circuit board is Encapsulation of Touch Screen
# abstraction is just Touch Screen
# in abstraction we just want the user to use only rather than show the code lke in coffe machine

# Inheritance:Same meaning like in real life

# Polymorphism:Ablity to take multiple forms
# not like mistique
# Example:Area 
# Area may be square ,rectangle, Triangle


# Paytm:
# 	Name
# 	email
# 	Contact no.


# 	deposite
# 	transfer
# 	online shoping

# 	there are million of users they can idependly perform the tasks in it
# user1
# user2

# Paytm is Class and every user interacting with the class is object



# In OPPs we define two thing
# Class

# 	variable 
# 	in Paytm user name email etc

# 	functions
# 	like deposite transfer shoping


# Objects (any user)

# 	any user can interact with the class and use the functions






class User:
	# username
	# password
	# email
	# name

	# getdetails
	# change name
	# change mail
	# every time use try to creat a new object it calls inti
	count = 0 #Class Variable , User1 check and user2 checks the same value will come
	def __init__(self,username,password,email,name):
		self.user_name=username
		self.password=password
		self.email=email
		self.name=name
		# instance variables
		# all these variables will be available with any function in the class

	def login(self,username,password):
		if ((self.user_name==username) and (self.password==password)):
			print("Login Succesful")
		else:
			print("Invalid Creditianles")
	def get_details(self):
		return self.user_name 


user1=User("abc","abc@123","abc@xyz","abc")
# User(user1,"abc","abc@123","abc@xyz","abc")
user2=User("pqr","pqr@123","pqr@xyz","pqr")
# python always passes the object as the frist argument
# print(user1.user_name)
# print(user2.user_name)
# one of the advantage is same functions is used by different objects . Code reuseablity
# user1.login("abc","abc@123")


# two types of variables:
# 1.instance variable :
	# if every object has its own set of variable
# 2.Class variable entirely class will have same value
# Example:- We need to count total no of users present 

# print(user1.count)
# Changing a class variable
# User.count=100
# print(user1.count)

# user1.count= 500
# print(User.count)#100
# print(user1.count)#500
# print(user2.count)#100

# We are trying to change a class variable using object.
# in that case python will create a local variable for user1

# print(user1.__dict__)
# print(user2.__dict__)
# print(User.__dict__)

# User.count=82
# print(user1.count)
# It will change the user1.count also



# Inheritance
# class Profile(User):
# 	pass

# user3=Profile("uday123","password","kiranu941@gmail.com","uday")
# print(user3.user_name)

# in Inheritance all the variables and functions will be available to the inherited class
# + he can create his own functions and variables

# class Profile(User):
# 	def __init__(self,user_name,password,email,name,contact,fb):
# 		super().__init__(user_name,password,email,name)
# 		self.contact_no=contact
# 		self.facebook=fb

# user4=Profile("uday123","password","kiranu941@gmail.com","uday","7123456789","www.fb/dog.com/sfsf/fsgerg")
# print(user4.__dict__)


class Demo:
	def get_details():
		return "Hi from Demo"


# Now we inherit from both the class 

class Profile(User,Demo):
	def __init__(self,user_name,password,email,name,contact,fb):
		super().__init__(user_name,password,email,name)
		self.contact_no=contact
		self.facebook=fb
	def get_details(self):
		return super().get_details(),self.contact_no

user5=Profile("qwe123","qwer","qwe@123.com","qwe",789123456,"www.fb.com/sdsdf/sdrgtg")
# print(user5.get_details()) #('qwe123',789123456)


#if we use Demo,User it will return ('Hi from demo',789123456)

# help(Profile)
# It is calculated by Depth frist left to Right
# See the Method Resolution Order


