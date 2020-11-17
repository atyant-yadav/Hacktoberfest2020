import math
import os
import random
import re
import sys

# Complete the minimumDistances function below.
def minimumDistances(a):
    l = len(a)
    min_d = l + 1
    flag = 0
    for i in range(l):
        for j in range(i+1,l):
            if(a[i] == a[j] and j-i < min_d):
                min_d = j-i
                flag = 1
    if(flag == 1):
        return min_d
    else:
        return -1
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()