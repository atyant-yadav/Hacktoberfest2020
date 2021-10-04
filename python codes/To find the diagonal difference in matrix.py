def diagonalDifference(arr):
    k = 0
    left_result = []
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            left_result.append(arr[i][j+k])
            break
        k += 1
    left_diag = sum(left_result)
    new_arr = arr[::-1]
    k = 0
    right_result = []
    for i in range(len(arr)):
        for j in range(len(new_arr[i])):
            right_result.append(new_arr[i][j + k])
            break
        k += 1
    right_diag = sum(right_result)
    return abs(left_diag-right_diag)


def main():
    size = int(input("Enter the size of the array : "))
    array = []
    for i in range(size):
        rows = []
        for j in range(size):
            value = int(input("Enter the value : "))
            rows.append(value)
        array.append(rows)
    final = diagonalDifference(array)
    print(final)


main()
