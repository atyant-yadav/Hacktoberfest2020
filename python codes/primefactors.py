import math

def primefactor(number):
    primefactors = []
    while number % 2 == 0:
        primefactors.append(2)
        number = number / 2

    for i in range(3, int(math.sqrt(number)) + 1, 2):
        while number % i == 0:
            primefactors.append(int(i))
            number = number / i

    if number > 2:
        primefactors.append(int(number))

    return primefactors

n=int(input("Enter a number: "))
print(primefactor(n))
