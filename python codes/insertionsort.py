"""
A insertion sort is an inplace sorting method
used to generally sort the array which are partially sorted
is been checked with the help of loop invariant method
"""


# build the function for insertion sort
def insertion_sort(arr: list, reverse: bool = False) -> list:
    """
    A function to perform a insertion sort algorithm
    It's an inplace sorting algorithm
    :param arr: unsorted list of elements
    :param reverse: to define if sorting in reverse order or not
    :return: a sorted list of elements
    """

    # start a for loop in range of 2 to len of array
    for j in range(1, len(arr)):
        key = arr[j]  # key to check in j-1 array
        i = j - 1  # i: to iterate over j-1 array and perform sorting

        # check if reverse is true?
        if reverse == True:
            # perform operations for reversed order
            # check if key < arr[i]
            while i >= 0 and arr[i] < key:
                # shift array from a[i] to a[i+1]
                arr[i + 1] = arr[i]
                i -= 1
        # execute else part
        else:
            # check if i > 0 and arr[i] > 0
            while i >= 0 and arr[i] > key:
                # shift a[i] to a[i+1]
                arr[i + 1] = arr[i]
                i -= 1  # decrement of i

        # assign the value of key to i+1 position after termination of while loop
        arr[i + 1] = key

    # return sorted array
    return arr
