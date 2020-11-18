
# Simple class to discribre a O(N) algoritm to sorting

class CountingSort:
    '''
        Count ordering is a stable, complex ordering algorithm is O (n).
        The keys can take values ​​between 0 and M-1.
        If there are k0 keys with a value of 0, then they occupy the first k0 positions of the final vector: from 0 to k0-1.
        The basic idea of ​​the sort count is to determine, for each entry x, the number of elements less than x. This information can be used to place the element x directly in its position in the output array. For example, if there are 17 elements less than x, then x belongs to position 18.
        This scheme must be modified when there are several elements with the same value, since we do not want them to be earlier in it.
    '''
    def sort(self,array):

        smaller = min(array)

        keyValue = 0

        if smaller < 0: keyValue = 1 - smaller


        lenArray = len(array)

        tempArray = [0] * lenArray


        for i in range(lenArray):
            tempArray[i] = array[i] + keyValue

        bigger = max(tempArray)
        smaller = min(tempArray)
        size = (bigger - smaller) + 2

        contArray = [0] * size

        for i in range(len(tempArray)):
            contArray[tempArray[i] - smaller + 1] += 1

        for i in range(1, len(contArray)):
            contArray[i] += contArray[i - 1]


        for i in range(len(tempArray)):
            array[contArray[tempArray[i] - smaller + 1] -1] = tempArray[i]
            contArray[tempArray[i] - smaller + 1] -= 1
