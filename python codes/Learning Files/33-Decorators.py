# decorator is a function which takes function as an parameter and returns anothe function
def deco(func):
	def new_func(val1,val2):
		if type(val1)==type(val2):
			return func(val1,val2)
		else:
			return func(str(val1),str(val2))
	return new_func


@deco
def concat(val1,val2):
	return val1+val2

result=concat(10,10)
print(result)


result=concat("Python","String")
print(result)


result=concat("Python",10)
print(result)

# Befor excuting the function there is a decorator , the function will pass to the decorator
# the underline function will pass as an argument