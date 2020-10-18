# -*- coding: utf-8 -*-
"""
Created on Sat Oct 17 12:07:43 2020

@author: adity
"""

def binarySearch(arr, val):
    upper = len(arr)-1
    lower = 0
    middle = (upper + lower) // 2
    
    while lower <= upper:
        
        if arr[middle] < val:
            lower = middle + 1
        elif arr[middle] > val:
            upper = middle - 1
        elif arr[middle] == val:
            return middle
        middle = (upper + lower) // 2
    return "value not found"


    
    
    