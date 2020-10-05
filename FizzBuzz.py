def fizzbizz(n):
    for i in range(1,n+1):
        output = ""
        if (i%3==0):
            output = output + "Fizz"
        if (i%5==0):
            output = output + "Buzz"
        if (output == ""):
            output = output + str(i)
        print(output)


n = int(input("Enter the number of lines : "))
fizzbizz(n)