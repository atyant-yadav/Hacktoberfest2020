#include<stdio.h>
#include<conio.h>
char tic[10]={'0','1','2','3','4','5','6','7','8','9'};
int win();
void game();
int main()
{
    int player=1,i,choice;
    char mark;
    do
    {
        game();
        player=(player % 2)?1:2;

        printf("Player %d Move : ",player);
        scanf("%d",&choice);	

        mark=(player == 1)?'X':'O';

        if (choice==1 && tic[1]=='1')
            tic[1]=mark;         
        else if (choice==2 && tic[2]=='2')
            tic[2]=mark;  
        else if (choice==3 && tic[3]=='3')
            tic[3]=mark;
        else if (choice==4 && tic[4]=='4')
            tic[4]=mark;
        else if (choice==5 && tic[5]=='5')
            tic[5]=mark;
        else if (choice==6 && tic[6]=='6')
            tic[6]=mark;            
        else if (choice==7 && tic[7]=='7')
            tic[7]=mark;            
        else if (choice==8 && tic[8]=='8')
            tic[8]=mark;            
        else if (choice==9 && tic[9]=='9')
            tic[9]=mark;            
        else
        {
            printf("Not Valid");
            player--;
            getch();
        }
        i=win();
        player++;
    }while (i== -1);

    game();
    if (i==1)
	printf("Player %d Win", --player);
    else
	printf("It's Tie..");
    getch();
    return 0;
}

int win()
{
    if (tic[1]==tic[2] && tic[2]==tic[3])
        return 1;        
    else if (tic[4]==tic[5] && tic[5]==tic[6])
        return 1;       
    else if (tic[7]==tic[8] && tic[8]==tic[9])
        return 1;        
    else if (tic[1]==tic[4] && tic[4]==tic[7])
        return 1;        
    else if (tic[2]==tic[5] && tic[5]==tic[8])
        return 1;        
    else if (tic[3]==tic[6] && tic[6]==tic[9])
        return 1;        
    else if (tic[1]==tic[5] && tic[5]==tic[9])
        return 1;       
    else if (tic[3]==tic[5] && tic[5]==tic[7])
        return 1;    
    else if (tic[1] != '1' && tic[2] != '2' && tic[3] != '3' &&
        tic[4] != '4' && tic[5] != '5' && tic[6] != '6' && tic[7] 
        != '7' && tic[8] != '8' && tic[9] != '9')
        return 0;
    else
        return - 1;
}
void game()
{
    printf("Player 1 (X) & Player 2 (O)\n\n\n");
    printf(" %c | %c | %c \n", tic[1], tic[2], tic[3]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n", tic[4], tic[5], tic[6]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n", tic[7], tic[8], tic[9]);
    printf("   |   |   \n\n");
}
