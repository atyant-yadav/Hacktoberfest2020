from random import randint

t = ["r", "p", "s"]

computer = t[randint(0,2)]

player = False

name = input("Enter your name:")
print("Type 'reset' to reset score")

You = 0
PC = 0

def win():
  global You
  You+=1
  print(message)
  print('Computer =', PC, '\n', name, '=', You)

def lose():
  global PC
  PC+=1
  print (message)
  print('Computer =', PC, '\n', name, '=', You)

while player == False:
    player = input("Rock, Paper, Scissors?(r,p,s)")
    if player == computer:
        print("Tie!")
        print('Computer =',PC)
        print(name,'=',You)
    elif player == "r":
        if computer == "p":
            message = "You lose!,Paper covers Rock"
            lose()
        else:
            message ="You win!, Scissors cuts Paper"
            win()
    elif player == "p":
        if computer == "s":
            message = "You lose!,Paper covers Rock"
            lose()
        else:
            message ="You win!, Scissors cuts Paper"
            win()
    elif player == "s":
        if computer == "r":
            message = "You lose!,Paper covers Rock"
            lose()
        else:
            message ="You win!, Scissors cuts Paper"
            win()
    elif player == "reset":
      You=1*0
      PC=1*0
      print("The score has been reset!")
    else:
        print("That's not a valid play. Please select a valid option!")
    player = False

    computer = t[randint(0,2)]
    
