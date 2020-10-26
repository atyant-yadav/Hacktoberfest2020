def is_prime(n):
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
    for a in range(2, n):
        if n % a == 0:
            return False
    return True

result = 0
num = 3453
for a in range(2, num ):
    if num % a == 0 and a % 2 != 0:
        if is_prime(a):
            result = a

print(f"{result} adalah faktor prima terbesar!")
