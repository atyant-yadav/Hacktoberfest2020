#sets

#s= {10,20,30}
#print(type(s))

#Sets are mutable = can be added or deleted
#All the elements should be unique
#can add only immutable elents in the sets = ints float tuple str
#unordered like dictionary = cant perform slicing and indexing , python wont insert in an orderd
#example of unordered

#s={10,20,30,40,10,20,30}
#print(s)

#s={100,200,300,400}
#s.add(500)
#print(s)

# s1={10,20,30,40,50,60}
# s2={40,50,60,70,80,90}

# s3=s1.union(s2)
# print(s3)

#s3=s1.intersection(s2)
#print(s3)

#s3=s1.difference(s2)
#print(s3)

# s3=s1.symmetric_difference(s2)
# print(s3)

# print(s1)
# s1.update(s2)
# print(s1)
#will perform union operation but dont return anything and modify the original set
#similary to s1.intersection_update(s2)  s1.difference_update(s2) s1.symmetric_difference_update(s2)

s1={100,200,300,400,500}
s2={100,200,300}

print(s2.issubset(s1))
print(s1.issuperset(s2))

#u have two lists construct a ordered list from it 
#l1=[100,200,300,400,800]
#l2=[50,100,150,45,100,200,32,5]

#s1=set(l1)
#s2=set(l2)

#s3=s1.union(s2)
#print(s3)
#l3=list(s3)
#l3.sort()
#print(l3)

#pop
#remove
#discard
#clear
#del

s={100,200,300,400,500,600}

#r=s.pop()
#print(s,r)
#u cant remove the value u want but return the element

#s.remove(500)
#print(s)
#in remove function if u pass and argument which doents exist it will throw an error
#s.remove(5000)
#print(s)

#discard also remove the items but if argument doesnt exist it wont show an error

#s.clear()
#print(s)

#del s
#print(s)