# -*- coding: utf-8 by Vinay -*-
"""
sum of even and odd number of given range
"""
n = int(input("enter range starting"))
r = int(input("enter ending "))
even_sum = 0
odd_sum = 0
for i in range(n,r+1):
    if i%2== 0:
        even_sum+= i
    else:
        odd_sum+= i
print("odd sum is",odd_sum)
print("even sum is",even_sum)
