#def fibo():
#	first_num=0
#	second_num=1
#	third_num=0
#	print(first_num)
#	print(second_num)
#	while(True):
#		third_num = second_num + first_num
#		first_num=second_num
#		second_num=third_num
#		yield third_num

#next runs the function only till it excutes a yiels statement , again when the next appear
#it will continue the functio from yield and excutes until it encounters another yield
#result=fibo()
#print(result)
#print(next(result))
#print(next(result))
#print(next(result))
#print(next(result))
#print(next(result))
#print(next(result))
#print(next(result))
#print(next(result))

#def fibo():
#	first_num=0
#	second_num=1
#	third_num=0
#	yield second_num
#	while(True):
#		third_num = second_num + first_num
#		first_num=second_num
#		second_num=third_num
#		yield third_num

#uday=fibo()
#print(next(uday))
#print(next(uday))
#print(next(uday))
#print(next(uday))
#print(next(uday))
#print(next(uday))

#for example i want frist ten fibo then
#for value in range(10):
#	print(next(uday))

#for next 10 num , generators will keep the state of the function
#for value in range(10):
#	print(next(uday))


#for list comprehension [] for generator generation()
l=[10,20,30,40,50]
l2=(value*value for value in l)
print(l2)
print(next(l2))
print(next(l2))
print(next(l2))
print(next(l2))
print(next(l2))