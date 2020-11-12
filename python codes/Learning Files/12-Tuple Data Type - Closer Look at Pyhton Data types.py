# tuple is immutable - we cant add updade or delete valsue from it
# since it is a ordered data structure it has slicing and indexing
# t=(10,20,20,20,20,30,40)
# important point is for indexing and slicing we will use [] instead of()
# print(t[-1]) 
# print(t[:3])
# print(t.index(20))
# it will give me the frist occurence of 20

# print(t.count(20))

# l = [10,20,30,40,50]
# for t in enumerate(l):
	# print(t)

# if u want to convert a list in tuple
# t=tuple(l)
# print(t)
# and now u cant modify the value

# if u have a tuple and want to convert to a list
# t=(10,20,30)
# l=list(t)
# print(l)