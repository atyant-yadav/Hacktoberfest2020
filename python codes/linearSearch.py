def linearSearch(arr, l, e):
    for i in range(0,l):
        if arr[i]==e:
            return i
    return -1
a=[2,54,62,64,22]
n=len(a)
x=int(input("Enter the element to be searched: "))
result=linearSearch(a,n,x)
if result==-1:
    print("Element does not exist in the array")
else:
    print("Element at index: ", result)
