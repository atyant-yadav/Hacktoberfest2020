#check if a word is a palindrome
Continue = True
while Continue:
    list= input("Enter String to check if its a palindrome: ")
    first_check = (list[:])
    second_check = (list[::-1])
    if first_check == second_check:
        print( list + " is a palindrome")
    else:
        print(list + " is not a palindrome please")
    print("Do You want to Continue???\nEnter (1/0):")
    try:
        Continue = int(input())
    except(ValueError):
        print("Somthing Went Wrong")
