#l1=[1,2,3,4,5]
#l2=[1,4,9,16,25]

#d=dict(zip(l1,l2))
# zip combines elements of same index
#print(d)

#l=[1,2,3,4,5]
# create a dict have where 1,2,3,4,5 will the keys
#d=dict.fromkeys(l)
# it is a class method
#print(d)
# if u want to assign a default value to it add it into second parameter
#e=dict.fromkeys(l,"uday")
#print(e)

#update method wont return anything it will modify the dict

d1={1:1,2:4,3:9,4:16,5:25,6:36,7:49}
# d2={8:64,9:81,10:100}
# d1.update(d2)
# print(d1)


#pop
#popitem
#clear
#del

#d2=d1.pop(5)
#print(d1,d2)
#pop will take key as a aegument it will return the value of the key and also delete 
#the key from it



#r=d1.popitem()
#print(d1,r)
# it wont take any arguments and remove the last element and retuen a tuple of key 
#and value pair


# d1.clear()
# print(d1)

# del d1