# frist we have to open the file
# open()
# take 2 arguments (filename,"mode in which we want to open")
# r=read
# r+
# w=write
# w+
# a=apend
# a+
fp=open("input.txt","r")
# content=fp.read()
# print(content)
# openfunction returns a file object on which we can perform the file operations
# if we want to read the content
# content = fp.read()
# it will read all the file content and return a string
# print(content)

# print("------------------------------------------------------------")
# content = fp.read()
# print(content)
#it wont print again 
#file pointer , when we open a file in read mode the curser is at start position
#and when it starts reading the courser moves for wards but when we read the file again
# as the curser is at the end it cant read again.

# if i want to read specific no of characters 
# content=fp.read(20)
# print(content)

# we have readlines and readline

# content = fp.readlines()
# print(content)
# it returns a list type so we can perform slicing.
# readlines returns a list but every line is an element of the list
# print(content[:5])

# if i want to read line by line i will use readline function
content = fp.readline()
print(content)
content = fp.readline()
print(content)
content = fp.readline()
print(content)

# content = fp.readline()
# print(content)
#here the next line is blank space

# content = fp.readline()
# print(content)


# for x in fp:
# 	print(x)

# it will print the file contents in string format with no. of new line
# equal to no of string
