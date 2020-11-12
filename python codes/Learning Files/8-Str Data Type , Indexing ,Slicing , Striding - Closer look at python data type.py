# String are immutable
# s1="python"
# print(id(s1))
# s1="java"
# print(id(s1))

# 2.String is ordered data structure - indexing and Slicing

# Indexing
s="Python Sample String"
# in python there are two types of indexing , one is from left to right and another
# right to left
# indexing starts from 0 and -1 from right to left
# print(s[::-1])

# Slicing
# If i want only Python from the string i dont need to write an for loop or 
# we can use Slicing
# I want python from the string
# print(s[0:5])
# the end in not inclusive
# print(s[0:6])
# print(s[:6])
# if i want to remaing string 
# print(s[7:])
# frist parameter gives where to start
# IF i want altenate character from the string , there is a thrid parameter

# Stride

# print(s[::2])
# print(s[:-1])
# print(s[-1:])
# print(s[::-1])
# Stride Decides the direction of the flow , +ve left to right , -ve right to left


# Indexing will throw an error if we use wrong index but slicing wont through an 
# error
# it will return an empty string
# print(s[6:0])

for value in s[::2]:
	print(value,sep="2")

# help(print)