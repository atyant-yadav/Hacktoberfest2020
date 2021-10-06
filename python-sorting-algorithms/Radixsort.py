def radix(array):

  size = len(str(max(array)))

  for i in range(size):

    b = [[] for i in range(10)]

    for elem in array:

      num = elem // 10**(i) % 10

      b[num].append(elem)

    array = sum(b,[])

  return array

array = list(map(int,input("Enter Elements:\n").split()))

print("Sorted Array:")

print(radix(array))
