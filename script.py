import math

def getNumber():

    x = 0

    while (len(str(abs(x))) != 2):
        x += 1

        if(len(str(abs(x))) == 2):
            for i in range(100):
                if (x % 5 == 0 and x % 2 != 0):
                    print(x)
                    x += 1
                else:
                    x += 1
    
    exit

getNumber()
