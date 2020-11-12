import itertools
#l=[10,20,30,40,50]
#i= iter(l)
#print(i)
#print(next(i))
#print(next(i))
#print(next(i))

#for value in i:
#	print(value)

l1=[10,20,30,40,50]
l2=[100,200,300,400,500]
l3=[1000,2000,3000,4000,5000]
i = itertools.chain(l1,l2,l3)
# print(next(i))
# for value in i :
# 	print(next(i))
# count=0
# for value in itertools.cycle(l1):
# 	if count <20:
# 		print(value)
# 	else:
# 		break
# 	count+=1

# count=0
# for value in itertools.repeat(l1):
# 	if count <20:
# 		print(value)
# 	else:
# 		break
# 	count+=1

# in case i want to just iterat till 8th element
#for value in itertools.islice(i,0,8):
#	print(value)

#u want infinite no.s use count 
#count=0
#for value in itertools.count(100):
#	if count <20:
#		print(value)
#	else:
#		break
#	count+=1


# permutations in python 
# l=[1,2,3,4,5,6]
# print(list(itertools.permutations(l,2)))
# similary combinations