#time Complx = 0(n(log log n))
import math
n=int(input())
if(n<=1):
    print(1)
else:
    x=[1]*(n+1)#eficiet way
    for i in range(2,int(math.sqrt(n))+1):
        if(x[i]==1):
            for j in range(i*i,n+1,i):
                x[j]=0
for i in range(2,n+1):
    if(x[i]==1):
        print(i)