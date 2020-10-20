for _ in range(int(input())):
    n=int(input())
    if(n%4==0 or n%4==1):
        print((n//4)**2)
    else:
        print(((n//4)+1) * (n//4))        
