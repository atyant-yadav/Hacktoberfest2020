from itertools import cycle
A = [[1,2,3],[4,5,6],[7]]
B = [[8],[9,10,11],[12,13]]
i = len(A)
j = 0
C = [ ] #for results
list_num = cycle(k for k in range ( i ))
for x in list_num:
j += 1
if j == i*3:
break

if A[x]:
    C.append(A[x].pop(0))
    
if B[x]:
    C.append(B[x].pop(0))        
