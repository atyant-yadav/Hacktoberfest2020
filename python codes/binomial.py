#Reading input from STDIN. Print output to STDOUT
#A single line containing the following values: ratio of two occassion such as (1.09 1)
#modify the code for the list of numbers such as (6,5,4,3,2,1) are 6 unique observation

#this program suppose to find The ratio of boys to girls for babies born in Russia, which is 1.09:1  
#If there is  child born per birth, what proportion of Russian families with exactly 6 children will have at least 3 boys?

from itertools import combinations

l, r = list(map(float, input().split(" ")))

p = l/(l+r)
q = r/(l+r)

def binomial(x):
    answer=len(list(combinations([6,5,4,3,2,1],x)))*(p**x)*(q**(6-x))
    return answer

prob3 = binomial(3)+binomial(4)+binomial(5)+binomial(6)
print(round(prob3, 3))
