def linearSearch(arr, target):
    i = 0
    while i < len(arr):
        if arr[i] == target:
            return i
        i += 1
    return "Fail"

arr = [3,5,6,1,4,7,9,8]
target = 4
print(linearSearch(arr, target))
