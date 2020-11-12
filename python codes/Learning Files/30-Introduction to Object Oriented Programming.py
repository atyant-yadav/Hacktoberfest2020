# class Account(object):
# 	"""docstring for Account"""
# 	def __init__(self,cust_id,name,initial_balance=0):
# 		self.customer_id=cust_id
# 		self.name=name
# 		self.balance=initial_balance
# 	def get_balance(self):
# 		return self.balance
# 	def deposite(self,amount):
# 		self.balance= self.balance +amount
# 	def withdral(self,amount):
# 		if amount>self.balance:
# 			print("balance insufficient")
# 		else:
# 			self.balance-=amount
		

# customer1=Account("101","ABC")
# print(customer1.customer_id,customer1.name,customer1.balance)
# customer2=Account("102","PQR")
# customer3=Account("103","XYZ")
# customer1.deposite(50000)
# customer1.withdral(10000)
# print(customer1.get_balance())
# customer4= Account("104","qwe")

# # Lets deposite some amount in bank accounts
# customer2.deposite(8000)
# customer3.deposite(7000)
# customer4.deposite(70000)

# l= [customer1,customer2,customer3,customer4]

# for obj in l:
# 	if obj.balance < 10000:
# 		print(obj.customer_id)

# It will return all the account having less than 10000 rupeess

# If u want to restrict a access to a variable which u are defining in class put double underscore
# in front of it


class Account(object):
	"""docstring for Account"""
	def __init__(self,cust_id,name,initial_balance=0):
		self.__customer_id=cust_id
		self.__name=name
		self.__balance=initial_balance
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


# Now if i access the user name or balance it wont show as it is outside the class 
customer1=Account("101","ABC",7000)
customer2=Account("102","PQR",10000)
customer3=Account("103","XYZ",70000)
l=[customer1,customer2,customer3]

# for obj in l:
# 	if obj.get_balance()<10000:
# 		print(obj.get_id())

print(customer1._Account__customer_id)

print(customer1.__dict__)