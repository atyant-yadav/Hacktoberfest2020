l=[10,20,22,30,40,50,55]
# print(type(l))
# 1 Lists are mutable = add update and delete
# 2 Ordered = indexing and slicing
# 3 Hetrogenous

# indexing and slicing:
# print(l[-1])
# print(l[1:3])
#end is not inclusive
# reverse a Lists
# print(l[::-1])

# if you want to iterate over alternate characters
# for value in l[::2]:
# 	print(value)


# append

# if u want to add single element in a list 
# it wont return any thing
#memory location will be the same
# l.append(60)
# print(l)

# extend
# if u want to add multiple elements
# it only take one agrument
# it will iterate over give argument
#l.extend("Python")
# l.extend([500,600,700,800])

# print(l)
# in case of append it will add the whole list as one element

# insert
# Both append and extend will add element at last but if you want to add at particular
# position we use insert method

# l.insert(1,1000)
# print(l)

# l = [ 10,20,30]
# l2=l
# l.append(40)
# print(id(l),id(l2))
# print(l,l2)
# if we modifiy the frist list it will also modifiy the second list
# so we use some time copy

l = [ 10,20,30]
l2=l.copy()
l.append(40)
print(id(l),id(l2))
print(l,l2)
