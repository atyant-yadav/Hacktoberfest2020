n = input()
l = []
l.append(0)
l.append(1)
i = 2
while(i<=n):
    x = l[i-1] + l[i-2]
    l.append(x)
print(l[l.len-1])
