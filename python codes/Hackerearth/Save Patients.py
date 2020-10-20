n=int(input())
st=list(map(int,input().split()))
p=list(map(int,input().split()))
st.sort()
p.sort()
v=0
for i in range(len(st)):
    if(st[i]<p[i]):
        v=1
        break
if(v==1):
    print("No")
else:
    print("Yes")            
 
