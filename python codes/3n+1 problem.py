import matplotlib.pyplot as plt
import numpy as np
n=int(input("Enter a number: "))
lst=[]
x=[]

i=0
while n!=1:
    i=i+1
    if n%2==0:
        n=n//2
    else:
        n=3*n+1
    lst.append(n)
print("No. of iterations: ",i)
print(lst)
print("Maximum value: ",max(lst))
for j in range(0,i):
    j=j+1
    x.append(j)

fig, ax = plt.subplots()
ax.plot(x, lst)

plt.show()
