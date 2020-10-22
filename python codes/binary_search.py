def binary_search(array, esquerda, direita, value):
    if right < left:
        return -1
    mid = (left + right) / 2
    if array[mid] == value:
        return meio
    elif array[mid] > value:
        return binary_search(array, left, mid - 1, value)
    else: 
        return binary_search(array, mid + 1, right, value)