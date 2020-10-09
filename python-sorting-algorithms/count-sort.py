def counting_sorted(arr, K):
    c = [0] * K
    sorted_arr = [0] * len(arr)

    for i in arr:
        c[i] += 1

    for i in range(1, K):
        c[i] += c[i - 1]

    for i in range(len(arr)):
        sorted_arr[c[arr[i]] - 1] = arr[i]
        c[arr[i]] -= 1
    return sorted_arr

arr = [3, 5, 1, 2, 9, 6, 4, 7, 5]
print(counting_sorted(arr, 20))
