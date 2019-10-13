num = input("Enter a number or string to check for palindrome : ")
rnum = num[::-1]
if num == rnum :
    print("Palindrome")
else :
    print("Not a palindrome")
