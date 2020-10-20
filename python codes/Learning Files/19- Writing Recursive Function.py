# factorial(5) = 5 * factorial(4)
# 						4* fact(3)
# 							3* fact(2)
# 								2* fact(1)
# 									1


def factorial(num):
	if num==1:
		return 1
	else:
		return num * factorial(num -1)
num1= 5
result = factorial(num1)
print(result)

