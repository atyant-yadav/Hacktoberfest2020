# help(str)
# if you only want the list of functions
# print(dir(str))

# format
# num1=100
# num2=200
# print("Value of num1 is ", num1,"value of num2 is",num2)
# #this is not the recommend way from the string printing
# print("Value of num1 is {} value of num2 is {}".format(num1,num2))
# using indexing we can use format functions
# print("Value of num1 if {1} and value of num2 is {0}".format(num1,num2))
# it will show the value of num2 in num1 and vice versa
# print("Value of num1 is {val1} and value of num2 is {val2}".format(val1=num1,val2=num2))


# s="python Sample String"
# s1=s.capitalize()
# print(s1)
# capitalize returns new string and only captlize frist letter

# upper
# lower
# tilte
# t=s.upper()
# print(s.upper())
# print(t.isupper())
# print(s.lower())
# print(s.title())
# print(s.islower())
# print(s.istitle())

# There are function to check whether the function is lower or captial or title but
# there 
# is no function for capitalize


# split
# join

s="HTML,CSS,Python,Java ,Djando"
# print(s)
# l=s.split(",")
# print(l)

# s1=(" ".join(l))
# print(s1)

# s1="abcd"
# s2="1234"
# s3="Python Sample String abcd"



# # maketrans - make maping
# # translate - actual translation
# table=str.maketrans(s1,s2)
# result = s3.translate(table)
# print(result)

# index
# rfind
# find

s = "HTML,CSS,PYTHON,PYTHON"
# print("PYTHON" in s)
# print(s.index("PYTHON"))
# it is case sensitive

# print(s.find("pyhton"))
# similar to index but if not found it will return -1

# print(s.rfind("PYTHON"))
# it will return from the right side and give the value of P


# s="                       This is sample string         "
# s1=s.strip(" ")
# print(s1)
# s2="**************This is a sample string****"
# s3=s2.strip("*")
# print(s3)
# s3=s2.lstrip("*")
# print(s3)
# lly rstrip()

s="python"
s1=s.center(20,"*")
print(s1)
# lly ljust, rjust

# s= "html,css,python,html"
# s1=s.replace("html","HTML5")
# print(s1)


# help(str)
# print(dir(str))