# a dynamic approach
# Returns the maximum value that can be stored by the bag
def knapSack(W, wt, val, n):
   K = [[0 for x in range(W + 1)] for x in range(n + 1)]
   #Table in bottom up manner
   for i in range(n + 1):
      for w in range(W + 1):
         if i == 0 or w == 0:
            K[i][w] = 0
         elif wt[i-1] <= w:
            K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
         else:
            K[i][w] = K[i-1][w]
   return K[n][W]
#Main
val = [50,100,150,200]
wt = [8,16,32,40]
W = 64
n = len(val)
print(knapSack(W, wt, val, n))
