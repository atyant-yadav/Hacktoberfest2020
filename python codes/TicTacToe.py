
####################################
#     TIC
#     TAC
#     TOE..!
# Author @MeghanaPalkar
#####################################


square = [0,1,2,3,4,5,6,7,8,9]

def main():
    player = 1
    status = -1

    while status== -1:
        board()
        
        if player%2 == 1:
            player = 1
        else:
            player = 2

        print('\nPlayer', player)
        choice = int(input('Enter a number:'))

        if player == 1:
            mark = 'X'
        else:
            mark = 'O'

        if choice == 1 and square[1] == 1:
            square[1] = mark
        elif choice == 2 and square[2] == 2:
            square[2] = mark
        elif choice == 3 and square[3] == 3:
            square[3] = mark
        elif choice == 4 and square[4] == 4:
            square[4] = mark
        elif choice == 5 and square[5] == 5:
            square[5] = mark
        elif choice == 6 and square[6] == 6:
            square[6] = mark
        elif choice == 7 and square[7] == 7:
            square[7] = mark
        elif choice == 8 and square[8] == 8:
            square[8] = mark
        elif choice == 9 and square[9] == 9:
            square[9] = mark
        else:
            print('Invalid move ')
            player -= 1
                
        status = game_status()
        player += 1
            
    print('RESULT')    
    if status == 1:
        print('Player',player-1,'win')
    else:
        print('Game draw')


###############################################
#    FUNCTION TO RETURN GAME STATUS
#    1 FOR GAME IS OVER WITH RESULT
#    -1 FOR GAME IS IN PROGRESS
#    O GAME IS OVER AND NO RESULT
###############################################

def game_status():
    if square[1] == square[2] and square[2] == square[3]:
        return 1
    elif square[4] == square[5] and square[5] == square[6]:
        return 1
    elif square[7] == square[8] and square[8] == square[9]:
        return 1
    elif square[1] == square[4] and square[4] == square[7]:
        return 1
    elif square[2] == square[5] and square[5] == square[8]:
        return 1
    elif square[3] == square[6] and square[6] == square[9]:
        return 1
    elif square[1] == square[5] and square[5] == square[9]:
        return 1
    elif square[3] == square[5] and square[5] == square[7]:
        return 1
    elif square[1] != 1 and square[2] != 2 and square[3] != 3 and square[4] != 4 and square[5] != 5 and square[6] != 6 and square[7] != 7 and square[8] != 8 and square[9] != 9:
        return 0
    else:
        return -1



###############################################
#    FUNCTION TO DRAW BOARD
#    OF TIC TAC TOE WITH PLAYERS MARK
###############################################


def board():
    print('\n\n\tTic Tac Toe\n\n')

    print('Player 1 (X)  -  Player 2 (O)' ) 
    print()

    print('     |     |     ' )
    print(' ' ,square[1] ,' | ' ,square[2] ,' |  ' ,square[3] )

    print('_____|_____|_____' )
    print('     |     |     ' )

    print(' ' ,square[4] ,' | ' ,square[5] ,' |  ' ,square[6] )

    print('_____|_____|_____' )
    print('     |     |     ' )

    print(' ' ,square[7] ,' | ' ,square[8] ,' |  ' ,square[9] )

    print('     |     |     ' )

main()
