import numpy as np

print("My pyramid array \nby BroFar\n\n")
arr = np.array([[2, 3, 4, 2, 8], [8, 3, 5, 1, 3], [6, 7, 4, 9, 8], [3, 1, 4, 5, 7], [1, 7, 8, 1, 6]]) 
i = 0
j = 0
x = len(arr)
while x>0:
   for i in range(len(arr)):
       output = np.squeeze(arr[i])
       print("     ",output) 
       print("          ",output[i])
       x = x-1
       for j in range(len(output)):
           print(x*("  ")+(f" {output[j]}  ")*output[i])
           
           

