
#simple hangman game

print("Let's  play hangman!\n")

print("Start guessing a letter")


#the secret word
word = "secret"

#empty variable for storing guesses
guesses = ''

#the number of turns
turns = 10

while turns > 0:         

    # make a counter that starts with zero
    failed = 0             

    for char in word:      

        if char in guesses:    
            print (char),    

        else:
            print ("_"),     
            failed += 1    

    # print You Won
    if failed == 0:        
        print ("You won")  

    # exit the script
        break              

    
    guess = input("guess a character:")
    guesses += guess                    

    if guess not in word:  
        turns -= 1        
        print ("Wrong guess")
        print ("You have", + turns, 'more guesses' )
        if turns == 0:           
            print ("You Lose")
