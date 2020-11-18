#check if a word is a palindrome
while True:
    x = 0

    list= input("enter numbers to check if its a palindrome: ")
    first_check = (list[:])
    second_check = (list[::-1])
    if first_check == second_check:
        print( list + " is a palindrome")
    else:
        print(list + " is not a palindrome please")
    x += 1