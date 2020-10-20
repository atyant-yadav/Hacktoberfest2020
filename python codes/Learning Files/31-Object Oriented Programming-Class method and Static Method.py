# class Account(object):
# 	count = 0
# 	# Class Variable
# 	def __init__(self,cust_id,name,initial_balance=0):
# 		self.__customer_id=cust_id
# 		self.__name=name
# 		self.__balance=initial_balance
# 		Account.count+=1

# 	def get_balance(self):
# 		return self.__balance

# 	def get_id(self):
# 		return self.__customer_id

# 	def deposite(self,amount):
# 		self.__balance= self.__balance +amount

# 	def withdral(self,amount):
# 		if amount>self.__balance:
# 			print("balance insufficient")
# 		else:
# 			self.__balance-=amount

# customer1=Account("101","XYZ")
# customer2=Account("102","PQR")

# print(Account.count)
# print(customer1.count)

# Account.count+=5
# print(Account.count)

# customer1.count=100
# print(Account.count)
# print(customer1.count)
# print(customer2.count)

# if we want to modify a class variable we can only modify by class name
# but if we try to update an class variable using object python wont give error
#rather it will make a local variable for customer1
# print(Account.__dict__)
# print(customer1.__dict__)

# Class Method: If we want to work with all ur object variables




class Account(object):
	count = 0
	# Class Variable

	@classmethod
	def incr_count(cls):
		cls.count+=1

	@classmethod
	def get_count(cls):
		return cls.count

	@staticmethod
	def print_val():
		print("staticmethod in account class")

	def __init__(self,cust_id,name,initial_balance=0):
		self.__customer_id=cust_id
		self.__name=name
		self.__balance=initial_balance
		Account.incr_count()

	def get_balance(self):
		return self.__balance

	def get_id(self):
		return self.__customer_id

	def deposite(self,amount):
		self.__balance= self.__balance +amount

	def withdral(self,amount):
		if amount>self.__balance:
			print("balance insufficient")
		else:
			self.__balance-=amount

customer1=Account("101","XYZ")
customer2=Account("102","PQR")


# If we want to access the class Methods we need to access using class names
print(Account.get_count())

Account.print_val()

# In staticmethod we wont be accessing the class variable nor the init variable