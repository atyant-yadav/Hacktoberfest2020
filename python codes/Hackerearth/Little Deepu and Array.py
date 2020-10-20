n=int(input())
l=list(map(int,input().split()))
l1=[]
m=int(input())
for i in  range (m):
    a=int(input())
    l1.append(a)
for j in range(m):  
    for i in range(n):
        if(l[i]>l1[j]):
            l[i]=l[i]-1
for i in range(n):
    print(l[i],end=" ")          

