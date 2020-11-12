#Program to find out GCD of two numbers
import sys

def gcd(a,b):
    if (b == 0):
        return a
    return gcd(b, a%b)


a = int(sys.argv[1])
b = int(sys.argv[2])
g = gcd(a,b)

if(g):
    print(g)
else:
    print('not found')
