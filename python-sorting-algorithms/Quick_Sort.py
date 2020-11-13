a = [5, 4, 8, 3, 4, 14, 90, 45, 9, 3, 2, 4, 45]
p, r = 0, len(a)-1
def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q-1)
        quick_sort(a, q+1, r)
def partition(a, p, r):
    x = a[r]
    i = p-1
    for j in range(p,r):
        if a[j] <= x:
            i += 1
            print(a[i],a[j])
            a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]
    return i+1
quick_sort(a, p, r)
print(a)