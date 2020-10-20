import random

def rps(str):
    if (str==1):
        return "Rock"
    elif (str==2):
        return "Paper"
    else:
        return "Scissor"

print("1. Rock 2.Paper 3.Scissor \n")
choice=int(input())
print("You "+rps(choice))
computer = random.randint(1,3)
print("Computer "+rps(computer))
print()

if (choice==computer):
    print('Tie!')
elif (choice==1):
    if (computer==2):
        print("Computer Wins!")
        print(rps(computer),"beat",rps(choice))
    elif (computer==3):
        print("You Wins!")
        print(rps(choice),"beat",rps(computer))
elif (choice==2):
    if (computer==3):
        print("Computer Wins!")
        print(rps(computer),"beat",rps(choice))
    elif (computer==1):
        print("You Wins!")
        print(rps(choice),"beat",rps(computer))
elif (choice==3):
    if (computer==1):
        print("Computer Wins!")
        print(rps(computer),"beat",rps(choice))
    elif (computer==2):
        print("You Wins!")
        print(rps(choice),"beat",rps(computer))


