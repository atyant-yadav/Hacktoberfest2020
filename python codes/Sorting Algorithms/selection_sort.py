import sys

def selection_sort(arr):
    for i in range(len(arr)):
        min_indx = i

        for j in range(i+1, len(arr)):
            if arr[min_indx] > arr[j]:
                min_indx = j
        
        arr[i], arr[min_indx] = arr[min_indx], arr[i]

    return arr


arr = [0, 8, 64, 5, 87, 3, 54]
print(selection_sort(arr))