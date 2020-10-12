num = int(input("Enter how many fibonaccy numbers you want to calculate, starting from 0: "))
a = 0
b = 1
print(a)
print(b)
count = 2
while count < num:
	number = a + b
	print(number)
	a = b
	b = number
	count = count + 1