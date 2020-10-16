# Python program for implementation of heap Sort 

# To heapify subtree rooted at index i. 
# n is size of heap 
from heapq import heappop, heappush

def heap_sort(array):
    heap = []
    for element in array:
        heappush(heap, element)

    ordered = []

    # While we have elements left in the heap
    while heap:
        ordered.append(heappop(heap))

    return ordered

array = [4, 86, 32, 56, 9, 4, 19]
print(heap_sort(array))
