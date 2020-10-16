import random
i = 5
count_computer = 0
count_player = 0
while i > 0:
    x = ['s','w','g']
    computer_input = random.choice(x)
    player_input = input('snake water gun?')
    if player_input == 's':
        if computer_input == 's':
            print('tie point!')
            count_computer = count_computer+1
            count_player = count_player+1
        elif computer_input == 'w':
            print('better luck next time! computer won')
            print(f'computer chose  {computer_input}')
            count_computer = count_computer+1
        else:
            print('woahhh!you won!!')
            print(f'computer chose  {computer_input}')
            count_player = count_player+1
    elif player_input == 'w':
        if computer_input == 's':
            print('better luck next time! computer won')
            print(f'computer chose  {computer_input}')
            count_computer=count_computer+1
        elif computer_input == 'w':
            print('tie point!')
            count_computer = count_computer+1
            count_player = count_player+1
        else:
            print('woahhh!you won!!')
            print(f'computer chose {computer_input}')
            count_player = count_player+1
    elif player_input == 'g':
        if computer_input == 's':
            print('woahhh! you won!!')
            print(f'computer chose  {computer_input}')
            count_player = count_player+1
        elif computer_input == 'w':
            print('better luck next time! computer won')
            print(f'computer chose  {computer_input}')
            count_computer = count_computer+1
        else:
            print('woah! you won!!')
            print(f'computer chose  {computer_input}')
            count_player = count_player+1
    else:
        print('enter correct input')
    print(f'you are left with  { i - 1}  chances')
    i = i-1
if count_computer > count_player:
    print('computer won!!... its ok,try again!')
elif count_computer < count_player:
    print('congratulations and celebrations , you won!!!!!')
elif count_computer == count_player:
    print('tie! both are winnerss!!')
else:
    print('none')
print('total points are  ' 
      f'computer =  {count_computer}  '
      f'player =   {count_player}')

