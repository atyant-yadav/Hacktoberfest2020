# Datatypes
# #1 int:
# num1 = 100
# print(type(num1))

# 2 float

# num2 = 15.25
# print(type(num2))

# integer and float are immutable data types
# immutable= which data cant be changed
# num1=100
# print(id(num1))
# num1 = 105
# print(id(num1))

# it will store it in a new variable and we cant modify the value at
# same memory location 
# thats interger and float are immutable

# 3 str '' "" """ """
# s="Python"
# print(id(s))
# print(s)

# s="New Python"
# print(id(s))
# it is also immutable

# # 4 list:
# any thing enclosed between square brackets is list
l = [10,20,30,40,50,"python", "django"]
print(id(l))
l.append(60)
print(l)
print(id(l))


# lists are mutable in nature that means the can update value in same memory location
# lists are hetrogenous in nature: it 
# can store different type of data in a particular list

# 5 tuple:

# t = (10,20,30,40,"Uday")
# print(t)
# tuple is immutable data type remaining are same as list

# 6 dict:

# it is key value pair or called as hash maps
# d ={"name":"ABC","email":"abc@gmail.com"}
# Dictionary is a mutable data type

# 7 Set {}
# s = {10,20,30,40}
#set is mutable, in this we can perform all set operations such as union
#intersection.

# 8 bool:
# True False

# 9 complex:
# a=4 +3j
# print(a)

# help(str)
# help(dict)
