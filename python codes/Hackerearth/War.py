for _ in range(int(input())):
    n=int(input())
    b=list(map(int,input().split()))
    a=list(map(int,input().split()))
    b.sort()
    a.sort()
    if(max(b)==max(a)):
        print("Tie")
    elif(max(b)>max(a)):
        print("Bob")
    else:
        print("Alice")        
