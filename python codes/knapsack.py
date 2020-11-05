def knapSack(w, wt, val, n): 
    K = [[0 for x in range(w + 1)] for x in range(n + 1)] 
    for i in range(n + 1): 
        for j in range(w + 1): 
            if i == 0 or j == 0: 
                K[i][j] = 0
            elif wt[i-1] <= w: 
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]) 
            else: 
                K[i][j] = K[i-1][j] 
    return K[n][j] 
  
val = [40, 80, 100] 
wt = [10, 20, 30] 
W = 25
n = len(val) 
print(knapSack(W, wt, val, n)) 