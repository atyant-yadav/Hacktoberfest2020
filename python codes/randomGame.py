from random import randint
print ('Welcome!')
drawn = randint(1, 100)
choice = 0
while choice != drawn:
    choice = int(input ('choose a number between 1 to 100: '))
    if drawn == choice:
        print ('You Won!')
    else:
        if choice > drawn:
            print ('higher')
        else:
            print ('lower')
print ('End the game!')