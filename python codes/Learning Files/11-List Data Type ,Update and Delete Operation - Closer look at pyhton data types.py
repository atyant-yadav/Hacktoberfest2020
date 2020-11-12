# l=[10,20,30,40,50]
# To remove element we have different operators
# pop
# remove 
# clear
# del

# r=l.pop()
# print(r)
# it will automatically remove the last element
# if we want to remove the at paritcular index
# r=l.pop(2)
# print(l,r)

# if you want to remove on basics on values we use remove method
# l.remove(20)
# print(l)

# if i have multiple occurence of l
# it will only remove 1st occurence


# if u want to remove all the element from a list
# l.clear()
# print(l)

# if we want to remove the reference of a list frm the memory
# del(l)
# print(l)

# l=[50,40,30,20,10]
# l.sort()
# print(l)
# it wont return any value it will modify the original list
# print(l.sort())
# thats y it wont return any it will modify the original list
# if we want to reverse
# print(l[::-1])
# l.reverse()
# print(l)

# l3=sorted(l)
# print(l3)
# it will return a list , it works on any data type list,tuple,dictionary.
# note the list goes inside the function rather than l.sorted()


# For example u want to get at what value is a element is present in list we use index function
# print(l.index(30))
# even we have multiple occurences it will show the frist one similiar to string

# count will return the total no. of occurence
# print(l.count(30))


# l=[10,20,30,40,50]
# l2=[100,200,300]
# print(l+l2)
# What is the difference between extend and concantenation
# extend doesnt return anything it will modify the originaly list 

# l = [0.1]
# print(l * 10)
# it will take 10, 0.1

