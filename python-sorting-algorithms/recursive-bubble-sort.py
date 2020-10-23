# Bubble sort algorithm to practice recursion in python 
def recursive_bubble_sort(array, index):
    
    # goes through the array changing the higher number to the end
    for i in range(len(array) - 2):
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
    
    # checking base case
    if index > 1:        
        recursive_bubble_sort(array, index-1)   

# testing
array = [6,2,9,11,9,3,7,12]
index = len(array)    
recursive_bubble_sort(array, index)
print(array)