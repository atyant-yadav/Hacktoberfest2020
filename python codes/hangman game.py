# ***************Hangman game(bollywood)***********************#
import getpass

name = input('Write your name: ')

print('Welcome to the Hangman Game', name)

Enter a word, her input will be hidden
hangman = getpass.getpass('Type a word: ')

# You will have a maximum of 5 attempts
print('Your goal is to get the word typed right. You can make a maximum of 5 mistakes')
print('\n')

letters = []
mistakes = 5

while True:
    if mistakes == 0:
        print('\033[31m\nYOU LOST!!!\033[0m')
        break
        # At the end of 5 wrong attempts, the game is over

    # Enter a letter
    letter = input('Type a letter: ')

    if len(letter) > 1:
        # Enter just one letter
        print("\nPlease enter only one letter\n")
        continue

    if letter in hangman:
        # If the initial word contains the typed letter, it will be printed on the screen that the letter exists in the word
        print(f'The letter "{letter}" exists in the word')
        letters.append(letter)
    else:
        # If the initial word does not contain the typed letter, it will be printed on the screen that the letter does not exist in the word and the number of attempts left
        print(f'A letter "{letter}" does not exist in the word')
        mistakes -= 1
        print(f'You have {mistakes} mistakes')

    hangman_temp = ''
    for letter_secret in hangman:
        if letter_secret in letters:
            hangman_temp += letter_secret
        else:
            hangman_temp += '*'

    if hangman_temp == hangman:
        # If you get the word right, it will be printed that you won
        print(
            f'\033[32m\nYOU HIT the word! The word was: {hangman}\033[0m')
        break
    else:
        if mistakes != 0:
            # Each letter typed, right or wrong, will be printed on the screen as the word is, with the correct letter positions that have already been typed
            print(
                f'\033[34m\nThe word looks like this: {hangman_temp}\n\033[0m')

