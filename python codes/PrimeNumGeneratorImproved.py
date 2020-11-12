import math, time

# The function that checks if a number is prime
# Note: This function only works for Positive Integers 
# Your For Loop should protect the negative values 
def isPrime(n):
    if n > 1:
        n_lim = math.sqrt(n)
        n_lim = math.floor(n_lim)
        for i in range(2, n_lim+1):
            if n%i == 0:
                return False
        return True
    else:
        return True

print("== Improved Prime Number Generator Program ==\n====== With O(sqrt(n)) Time Complexity ======")

r_lower = int(input("Enter Lower Bound: "))
if r_lower < 1:
    print("Lower Bound cannot be 0 or Negative")
    exit()

r_upper = int(input("Enter Upper Bound: "))
if r_upper < r_lower:
    print("Upper Bound cannot be less than Lower Bound")
    exit()

print("Prime Numbers: ", end='')
t_start = time.time()
for i in range(r_lower, r_upper + 1):
    if isPrime(i):
        print("%d " % (i), end='')

print("\nExecution time: %s seconds" % (time.time()-t_start))