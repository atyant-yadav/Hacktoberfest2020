"""
@author Jeppe Kristensen
jepify
"""

def binarySearch(l, n, start, end):
    if start == end:
        return l[start] == n

    test_index = (end - start) // 2 + start
    test_number = l[test_index]
    if test_number == n:
        return True
    elif n < test_number:
        return binarySearch(l, n, start, test_index - 1)
    elif n > test_number:
        return binarySearch(l, n, test_index + 1, end)



l = [1,2,3,4,5,7,8,9,10]

print(f"{binarySearch(l,5, 0, len(l) - 1)=}")
print(f"{binarySearch(l,6, 0, len(l) - 1)=}")