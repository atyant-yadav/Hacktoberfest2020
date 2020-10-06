num=int(input("enter number:"))
for i in range(2,num):
    if num%i==0:
        print("composite number")
        break
else:
    print("prime number")
