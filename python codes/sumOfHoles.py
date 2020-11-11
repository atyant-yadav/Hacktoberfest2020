# Problem statement :
#What do the digits 0, 4, 6, 8, and 9 have in common?
#Well, they are whole numbers... and they are also 
#hole numbers (not actually a thing until now). Hole numbers are 
#numbers with holes in their shapes (8 is special in that it contains two holes).
#14 is a hole number with one hole. 88 is a hole number with four holes.

#Your task is to create a function with argument N that returns the sum of the holes for the integers n in the range of range 0 < n <= N.

#Input: Integer

#Output: Integer

#Sample Input: 14

#Sample Output: 7 (because there are 7 holes in 4, 6, 8, 9, 10 and 14.)

#Note: All test cases are positive real integers.

#code
def sum_of_holes(limit):
    hole =[1,0,0,0,1,0,1,0,2,1]
    count = 0
    for i in range (1,limit+1):
        for j in str(i):
            count += (hole[int(j)])
    return count
