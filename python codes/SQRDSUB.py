#solution to problem https://www.codechef.com/APRIL20B/problems/SQRDSUB

test=int(input())
while test>0:
    n=int(input())
    seq=list(map(int,input().split()))
    ans=0
    p,a,b=-1,-1,-1
    for i in range(n):
        if seq[i]%4==0:
            k=1;
        if seq[i]%4==0:
            ans+=(i+1)
            p=i
        elif seq[i]%2==0:
            a=b 
            b=i
            if p>=a:
                a=p
                ans+=(a+1)
            else:
                ans+=(a+1)
        else:
            k=(i+1)-(b-a)
            if p>=b:
                ans+=(i+1)
            else:
                ans+=k
    print(ans)
    test-=1 
