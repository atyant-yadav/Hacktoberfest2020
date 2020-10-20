# dict:
# 1. mutable
# 2.unordered= no indexing and slicing
# 3.key must be unque
# 4.keys should be immutable
# 5. the only allowed data type for key is int , string , tuple
# reason mutable data type is not allowed
# for example
# d={"emp_id":101 , [10,20,30]:100,[10,20]:200}
# if we add an element into [10,20] of 30 we will be creating a duplicate key
#d={"emp_id":101, "emp_name":"Uday Kiran", "email_id":"kiranu941@gmail.com"}
# print(d)
#d["email_id"]=102
#print(d)
#d["contact_no"]=123456789
#print(d)
 # d["contact_no"]=1234567898
 # it will update the value
# get 
# setdeafult

# get retrive a data from the key specified
#print(d.get("emp_name"))
# if we specified a key which doesnt exist it wont through an error
# it will return None

# if u want the function to return a value when the key doesnt exist 
# we can specify a second parameter
#print(d.get("email","Key doesnt exist"))

#setdeafult adds elemets if key doesnt exit else it will retrive data
#print(d.setdefault("age"))
# since age is not present it will add the age key and the assign a value of None
# if we want to assign a value to it i inilization its self
# print(d.setdefault("age",50))
#d["email_id"]="kiranu942@gmail.com"
#print(d)


#for x in d:
#	print(x)
# defaultly it will iterate over the keys



#for x in d:
#	print(x,d[x])
# if we also want the values
#dic={}

#for num in range(1,11):
#	dic[num]=num*num

#print(dic)

#keys
#values
#items

# print(d.keys()) it is a list of all the keys 
# print(d.values()) it is a list of all the values
# print(d.items()) it returns a tuple

# for t in d.items():
# 	print(t)