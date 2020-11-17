#check if a word is a palindrome
print("Palindrome Tester")
while True:
    list = input("Enter a word to be tested: ")
    first_check = (list[:])
    second_check = (list[::-1])
    list = list.capitalize()
    if first_check == second_check:
        print(list + " is a palindrome.")
    else:
        print(list + " is not a palindrome.")
