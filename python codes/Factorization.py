n = int(input())
factors = [1]
i = 2
while(i<=pow(n,0.5)):
    if(n%i==0):
        n = n//i
        factors.append(i)
    else:
        i+=1
factors.append(n)
print(factors)
