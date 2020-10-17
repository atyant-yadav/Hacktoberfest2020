num=int(input("Enter a number:"))
n=num
b=str(num)
a=len(b)
sum=0
while (num!=0):
	digit=num%10
	sum=sum+(digit**a)
	num=num//10
if sum==n:
	print(n,"is an Armstrong number")
else:
	print(n,"is not an Armstrong number")

