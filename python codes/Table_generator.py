num = int(input("Enter number to generate table : "))

for i in range(0,11):
    a = i*num
    print("{} x {} = {}".format(num,i,a))