def combination(arr, r):
    arr = sorted(arr)

    def generate(chosen):
        if len(chosen) == r:
            print(chosen)
            return

        start = arr.index(chosen[-1]) + 1 if chosen else 0
        for nxt in range(start, len(arr)):
            chosen.append(arr[nxt])
            generate(chosen)
            chosen.pop()
    generate([])


combination([1, 2, 3, 4, 5], 3)