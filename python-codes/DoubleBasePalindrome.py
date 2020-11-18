#Problem statement: The decimal number, 585 is equal to 1001001001 in binary.
#And both are palindromes. Such a number is called a double-base palindrome.
#Write a function that takes a decimal number n and checks if it's binary equivalent and itself are palindromes.
#The function should return True if n is a double-base palindrome or else it should return False.
#Input: Integer
#Output: Boolean value
#Sample Input: 585
#Sample Output: True


#code starts from here 
def check_Palindrome(n):
    n = str(n)
    rev = n[::-1]
    if n == rev:
        return True
    return False
   


def isDoubleBasePalindrome(n):
    b = str(bin(n)[2:])
    if check_Palindrome(n) and check_Palindrome(b):
        return True
    return False
