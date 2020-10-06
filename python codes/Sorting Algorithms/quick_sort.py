def partition(arr, low, high):
    i = low-1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def quick_sort(arr, low, high):
    if low < high:

        q = partition(arr, low, high)
        quick_sort(arr, low, q-1)
        quick_sort(arr, q+1, high)

    return arr


arr = [21, 2, 0, 65, 9, 87, 25]
print(quick_sort(arr, 0, len(arr)-1))