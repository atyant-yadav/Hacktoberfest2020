#Basic Calculator in Python without any gui.
import math 
#create functions for calculations
def add(num1, num2):
	return num1 + num2

def sub(num1, num2):
	return num1 - num2

def mul(num1, num2):
	return num1 * num2

def div(num1, num2):
	if num2 == 0:
		print("Can't divide a number by 0")
		exit()
	return num1 / num2
def fact(num1) :
	i = 1
	factorial_num = 1
	for i<=num1 :
		factorial_num = factorial_num*num1
	print(factorial_num)

print("Please Select Operations\n "
      	   "Note: Enter the angles in degrees\n"
	   "1. Addition\n " 
	   "2. Subtraction \n"
	   "3. Multiplication \n"
	   "4. Divide \n"
      	   "5. Sqrt \n"
     	   "6. Factorial\n"
	   "7. Sine\n"
	   "8. Cosine\n")
	   "9. tan\n")

#Take Input From Keyword
select = input("Press\n" "1 " "2 " "3 " "4 \n")
list1 = ['1','2','3','4']
if select in list1 :
	number_1 = int(input("Type Your First Number :"))
	number_2 = int(input("Type Your Second Number :"))
else :
	number_1 = int(input("Type Your First Number :"))

if select == '1':
	print(number_1, "+", number_2, '=')
	print(add(number_1, number_2))

elif select == '2':
	print(number_1, '-', number_2, '=')
	print(sub(number_1, number_2))

elif select == '3':
	print(number_1, '*', number_2, '=')
	print(mul(number_1, number_2))

elif select == '4':
	print(number_1, '/', number_2, '=')
	print(div(number_1, number_2))
elif select == '5':
	print("Sqrt of ",number_1)
	print(math.sqrt(number_1, number_2))
elif select == '6':
	print("Factorial of ",number_1)
	fact(number_1)
elif select == '7':
	print("sin(",number_1,')')
	math.radians(number_1)
	print(math.sin(number_1))
elif select == '8':
	print("cos(",number_1,')')
	math.radians(number_1)
	print(math.cos(number_1))
elif select == '9':
	print("tan(",number_1,')')
	math.radians(number_1)
	print(math.tan(number_1))	
else:
	print('Invalid Input ! Try aagian ')
	
print('Thanks for Using Calculator')
