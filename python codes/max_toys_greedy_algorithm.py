#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maximumToys function below.
def maximumToys(prices, k, n):
    prices.sort()

    toys = 0
    balance = k

    for i in range(0, n):
        if(prices[i] > balance):
            break
        else:
            toys = toys+1
            balance = balance - prices[i]
    
    return toys


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    prices = list(map(int, input().rstrip().split()))

    result = maximumToys(prices, k, n)

    fptr.write(str(result) + '\n')

    fptr.close()
