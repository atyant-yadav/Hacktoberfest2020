# Operators in python
# 1 Arithmetic Operators +,-,*,/,//,%,**
# 2 Comparision Operators <,>,<=,>=,==,!=
# 3 Identity Operators is , is not
# 4 Assignment Operators =, += ,-= , *=,/=
# 5 Bitwise operators &,|,^,>>,<<
# 6 Logical Operators And , Or and Not
# 7 Membership Operators in , not in


#1 Arthmetic Operators
# num1=10
# num2=20
# print(num1+num2)
# print(num1-num2)
# print(num1*num2)
# These operators are binary operators

# print(10/3)
# We will always get a floationg point operator in python while dividing even 10/2 is 5.0
# print(10//3)
# Floor division . Integer part of division

# print(10%3)
# Reminded
# print(45 ** 3)
# power


# 2 Comparision Operators 
# we can compare to integers , strings, lists and dictionaries.
# It always returns True or False
# num1=100
# num2=200
# print(num1 == num2)
# print(num1 > num2)
# print(num1 != num2)



#3. Identity Operators
# num1=100
# num2=100
# print(num1 == num2)#True
# print(num1 is num2)#True
# #Therefore is operator is nearly equal to == as it checks the memory location

# l=[10,20,30]
# l2=[10,20,30]
# print(l == l2)#True
# print(l is l2)#False
# Reason == compares the two value on the other hand is operator compare the memory location
# integers of two same value will be assigned to same memory location,but as list are mutable
# it will assign two different locations for two same lists.Similary is not checks the 
# memory location is different or not.


# 4 Assignment Operators =, += ,-= , *=,/=

# num1 = 100 
# = operator always assignes right hand side value to left 
# num1 = num1 +5
# num+=5
# lly num-=5


# 5 Bitwise operators &,|,^,>>,<<
# num1=2
# num2=1
# print(bin(num1),bin(1))
# print(num1 & num2)#0
# print(num1 | num2)#3
# print(2<< 1) #4


# 6 LOgical Operators And , Or , Not
# returns True or False

# print(10==10 and 20==20)# true
# not performs compliment of the operation
# print(not(10==10))



# 7 Membership Operators in , not in
# l=[10,20,30,40,50,60]
# print(30 in l)#true
# print(300 in l)# false

# s="Python String"
# print("Python"in s)
# lly not in