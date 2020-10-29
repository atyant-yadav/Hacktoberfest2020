n = int(input())

while n>0:
    dec = int(input())
    binary = bin(dec).replace("0b", "")
    print(binary)
    
    n=n-1