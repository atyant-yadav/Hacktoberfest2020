lst=[]
def addnum(lst):
    return sum(lst)
total_number=input("enter total number to be added")
for i in range(0,total_number):
    a=input("enter value")
    lst.append(a)
print addnum(lst)    
