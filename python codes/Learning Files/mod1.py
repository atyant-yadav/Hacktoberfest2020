"""
here what ever u specify is your doc string
Docstring is your description of that particular module
this module conatin factorial function








"""
# factorial(5) = 5 * factorial(4)
# 						4* fact(3)
# 							3* fact(2)
# 								2* fact(1)
# 									1


def factorial(num):
	"""
	Factirial of a number : input a number and it returns its factirial
	"""
	if num==1:
		return 1
	else:
		return num * factorial(num -1)

# print(__name__)
if __name__=='__main__':
	num1= 5
	result = factorial(num1)
	print(result)

