#binary search
l = []
n = int(input('number of elements'))
for i in range(n):
    ele = int(input('enter the element'))
    l.append(ele)
l.sort()
x = int(input('element  to be searched'))
low = 0
high = n-1
while low <= high:
    mid = int((low+high)/2)
    if l[mid] == x:
        print(f'element found at position {mid}')
        break
    elif x<l[mid]:
        high = mid-1
    elif x>l[mid]:
        low = mid+1
    else:
        print('invalid')
