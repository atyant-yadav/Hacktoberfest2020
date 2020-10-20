#map
#lambda
#filter

# map faster than comprehension and list and for loop
#map defaultly take one element at a time from the iteratable datatype
# map takes another functions as arguments
#def srq(num):
#	return num**2

#l=[10,20,30,40,50]

#result=map(srq,l)
#print(list(result))
#for value in result:
#	print(value)


#def add(l1,l2):
#	return l1+l2
#l1=[100,200,300,400,500]
#l2=[10,20,30,40,50]
#result=map(add,l1,l2)
#print(list(result))
#for value in result:
#	print(value)

def check_num(num):
	if num%2==0:
		return True
	else:
		return False

# l=[100,115,120,125,130,140]
# result=list(filter(check_num,l))
# print(result)
# it will return [100,120,130,140]

#l=[10,20,30,40,50]

#result=list(map(lambda num:num**2,l))
#print(result)

#l=[100,115,120,125,130,140]
#result=list(filter(lambda num:num%2==0,l))
#print(result)

#sort a dict on bases of its values
# d={8:50,3:40,2:30,1:20,5:10}
# l=sorted(d)
# print(l)
#sorted will return a sorted list on basies of key
# l=sorted(d.items())
# print(l)
#it will return a tuple in list
# l=sorted(d.items(),key=lambda x:x[1])
# print(l)