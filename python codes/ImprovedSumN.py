import time

def sumN (n):
    s = 0
    for i in range(n+1):
        s += i
    return s

def sumNi (n):
    ret = 0.5*n*(n+1)
    return ret

n = int(input("Enter n: "))

# Analyse runtime for Sum of n Traditional 
t_start1 = time.time()
r1 = sumN(n)
t_end1 = time.time()

# Analyse runtime for Sum of n Improved
t_start2 = time.time()
r2 = sumNi(n)
t_end2 = time.time()

print("Traditional Algorithm: %d" % r1)
print("Runtime: %s seconds" % (t_end1 - t_start1))
print("Improved Algorithm: %d" % r2)
print("Runtime: %s seconds" % (t_end2 - t_start2))
