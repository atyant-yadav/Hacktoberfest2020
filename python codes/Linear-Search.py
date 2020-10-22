#Linear Search
pos=-1

#Search function
def search(list,n):
    i=0
    while i<len(list):
        if list[i]==n:
            globals()['pos']=i
            return True
        i=i+1
    return False

list=[1,2,3,4,6,7,8,9,0]

n=9

if search(list,n):
    print("Found at pos",pos)
else:
    print("Not Found")

