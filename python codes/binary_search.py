def binarySearch(array, value, low, high):
    if low > high:
        return False
    mid = int((low + high) / 2)
    if array[mid] > value:
        return binarySearch(array, value, low, mid-1)
    elif array[mid] < value:
        return binarySearch(array, value, mid+1, high)
    else:
        return mid


arr = [2, 4, 12, 58, 20, 98, 5, 1, 0]
arr.sort()
print(arr)
target = binarySearch(arr, 20, 0, len(arr)-1)
print(target)