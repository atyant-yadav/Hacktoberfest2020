# Guessing game where the user picks a random number between 0 and 100. The computer tries to guess the number until it gets it right, and the total number of attempts is then displayed. 
# The computer implements binary search to guess the number. 

def guess():
    a = 0    # Lowest end of the range. 
    b = 100  # H ghest end of the range. 
    m = 50   # m is the middle number in the range, always the first guess. 
    counter = 1 # number of guesses take.
    print("Please guess a number")
  
    answer = input("Is your guess " + str(m) + "? Return 0 if it's too low, 1 if it is your guess, and 2 if it's too high")
    while answer != 1:
        if answer == 0:
            a = m + 1
        elif answer == 2:
            b = m - 1
        m = (a + b) / 2
        counter += 1
        answer = input("Is your guess " + str(m) + "? Return 0 if it's too low, 1 if it is your guess, and 2 if it's too high")
    print ("It took " + counter + " attemps to guess your number!"

guess()






