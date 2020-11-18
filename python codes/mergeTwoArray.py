# Python3 program to implement 
# the above appraoch 
  
# Function to perform min heapify 
# on array brr[]  
def minHeapify(brr, i, M): 
  
    # Stores index of left child 
    # of i. 
    left = 2 * i + 1
  
    # Stores index of right child 
    # of i. 
    right = 2 * i + 2
  
    # Stores index of the smallest element 
    # in (arr[i], arr[left], arr[right]) 
    smallest = i 
  
    # Check if arr[left] less than 
    # arr[smallest] 
    if (left < M and brr[left] < brr[smallest]): 
  
        # Update smallest 
        smallest = left 
  
    # Check if arr[right] less than 
    # arr[smallest] 
    if (right < M and brr[right] < brr[smallest]): 
  
        # Update smallest 
        smallest = right 
  
    # If i is not the index 
    # of smallest element 
    if (smallest != i): 
  
        # Swap arr[i] and arr[smallest] 
        brr[i], brr[smallest] = brr[smallest], brr[i] 
  
        # Perform heapify on smallest 
        minHeapify(brr, smallest, M) 
  
# Function to merge two sorted arrays 
def merge(arr, brr, N, M): 
  
    # Traverse the array arr[] 
    for i in range(N): 
  
        # Check if current element 
        # is less than brr[0] 
        if (arr[i] > brr[0]): 
  
            # Swap arr[i] and brr[0] 
            arr[i], brr[0] = brr[0], arr[i] 
  
            # Perform heapify on brr[] 
            minHeapify(brr, 0, M) 
  
    # Sort array brr[] 
    brr.sort() 
  
# Function to print array elements 
def printArray(arr, N): 
  
    # Traverse array arr[] 
    for i in range(N): 
        print(arr[i], end = " ") 
  
# Driver code 
if __name__ == '__main__': 
  
    arr = [ 2, 23, 35, 235, 2335 ] 
    brr = [3, 5] 
    N = len(arr) 
    M = len(brr) 
  
    # Function call to merge 
    # two array 
    merge(arr, brr, N, M) 
  
    # Print first array 
    printArray(arr, N) 
  
    # Print Second array. 
    printArray(brr, M) 
  
