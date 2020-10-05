def bubble_Sort(arr): 
    n = len(arr) 
  
    for i in range(n-1):  
        for j in range(0, n-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
  
arr = [2,4,12,58,20,98,5,1,0]
bubble_Sort(arr) 
  
print ("Current array:") 
for i in range(len(arr)): 
    print ("%d" %arr[i])  
