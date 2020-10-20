#l=[100,200,300,400]
#l2=[]
#for value in l:
#	l2.append(value*value)
#print(l2)

#l2=[value*value for value in l]
#print(l2)

#to get even nos, from a list to another list 

#l=[10,20,25,30,55,50,65,70,85,80,100]
#l2=[value for value in l if value%2 == 0]
#print(l2)

#to store length of each element in another list 

# l=['abc','abcd','abcde','zzzzzzz']
# l2=[len(value) for value in l]
# print(l2)

# we can also use nested for loops in compresion
# l1=[(value,value2) for value in range(0,3) for value2 in range(100,103)]
# print(l1)

#l=[[1,2,3],[4,5,6],[7,8,9]]
#we want l2[1,2,3,4,5,6,7,8,9]
#l2=[real for value in l for real in value]
#print(l2)

#ther is a list and we have to make a another list telling wether the itrattive vale is even or odd
# l=[100,105,110,115,130]
# l2=['even'if value%2 ==0 else 'odd' for value in l]
# print(l2)

#Dictionary comphrencion

#d={x:x**2 for x in range(1,5)}
#print(d)

# d={chr(x):x for x in range(65,91)}
# print(d)
#if we want to swap keys and values from the exicitence Dictionary
# d2={value:key for key,value in d.items()}
# print(d2)