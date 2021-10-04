#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <poll.h>

void create();
void display();
void createCandy();
int moveSnake();

int screen[30][50];
int candy_x, candy_y;
int left = 0, right = 1, top = 0, bottom = 0;
int score = 0;

struct node
{
    int x, y;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    char ch;
    create(2, 4);
    create(2, 3);
    create(2, 2);
    create(2, 1);
    createCandy();
    display();
    while (1)
    {
        struct pollfd mypoll = {STDIN_FILENO, POLLIN | POLLPRI};
        char key;
        if (poll(&mypoll, 1, 200))
        {
            scanf("%c", &key);
            if( key == 27)
            {
                break;
            }
            if (key == 'A' || key == 'a')
            {
                if (right == 0 && left == 0)
                {
                    left = 1;
                    top = 0;
                    bottom = 0;
                    right = 0;
                }
            }
            else if (key == 'W' || key == 'w')
            {
                if (top == 0 && bottom == 0)
                {
                    left = 0;
                    top = 1;
                    bottom = 0;
                    right = 0;
                }
            }
            else if (key == 'D' || key == 'd')
            {
                if (right == 0 && left == 0)
                {
                    left = 0;
                    top = 0;
                    bottom = 0;
                    right = 1;
                }
            }
            else if (key == 'S' || key == 's')
            {
                if (top == 0 && bottom == 0)
                {
                    left = 0;
                    top = 0;
                    bottom = 1;
                    right = 0;
                }
            }
        }
        if (moveSnake() == 1)
        {
            printf("\nGameOver\nScore = %d\n",score);
            break;
        }
        usleep(150000);
        system("clear");
        display();

    }
    return 0;
}
int moveSnake()
{
    int temp_x = start->x, temp_y = start->y;
    if (right == 1)
    {
        if (start->y != 48)
        {
            start->y++;
            struct node *p = start->next;
            int stop = 0;
            while (p != NULL)
            {
                if (p->x == start->x && p->y == start->y)
                {
                    stop = 1;
                }
                p = p->next;
            }
            if (stop == 1)
            {
                return 1;
            }
        }
        else
        {
            start->y = 1;
        }
        struct node *ptr;
        ptr = start->next;
        while (ptr != NULL)
        {

            int temp_a = ptr->x;
            ptr->x = temp_x;
            temp_x = temp_a;

            int temp_b = ptr->y;
            ptr->y = temp_y;
            temp_y = temp_b;

            ptr = ptr->next;
        }
    }
    else if (left == 1)
    {
        if (start->y != 1)
        {
            start->y--;
            struct node *p = start->next;
            int stop = 0;
            while (p != NULL)
            {
                if (p->x == start->x && p->y == start->y)
                {
                    stop = 1;
                }
                p = p->next;
            }
            if (stop == 1)
            {
                return 1;
            }
        }
        else
        {
            start->y = 48;
        }
        struct node *ptr;
        ptr = start->next;
        while (ptr != NULL)
        {

            int temp_a = ptr->x;
            ptr->x = temp_x;
            temp_x = temp_a;

            int temp_b = ptr->y;
            ptr->y = temp_y;
            temp_y = temp_b;

            ptr = ptr->next;
        }
    }
    else if (top == 1)
    {
        if (start->x != 1)
        {
            start->x--;
            struct node *p = start->next;
            int stop = 0;
            while (p != NULL)
            {
                if (p->x == start->x && p->y == start->y)
                {
                    stop = 1;
                }
                p = p->next;
            }
            if (stop == 1)
            {
                return 1;
            }
        }
        else
        {
            start->x = 28;
        }
        struct node *ptr;
        ptr = start->next;
        while (ptr != NULL)
        {

            int temp_a = ptr->x;
            ptr->x = temp_x;
            temp_x = temp_a;

            int temp_b = ptr->y;
            ptr->y = temp_y;
            temp_y = temp_b;

            ptr = ptr->next;
        }
    }
    else if (bottom == 1)
    {
        if (start->x != 28)
        {
            start->x++;
            struct node *p = start->next;
            int stop = 0;
            while (p != NULL)
            {
                if (p->x == start->x && p->y == start->y)
                {
                    stop = 1;
                }
                p = p->next;
            }
            if (stop == 1)
            {
                return 1;
            }
        }
        else
        {
            start->x = 1;
        }
        struct node *ptr;
        ptr = start->next;
        while (ptr != NULL)
        {

            int temp_a = ptr->x;
            ptr->x = temp_x;
            temp_x = temp_a;

            int temp_b = ptr->y;
            ptr->y = temp_y;
            temp_y = temp_b;

            ptr = ptr->next;
        }
    }
    if (start->x == candy_x && start->y == candy_y)
    {
        create(temp_x, temp_y);
        score++;
        createCandy();
    }
    return 0;
}
void createCandy()
{
    candy_x = (rand() % (28 - 1 + 1)) + 1;
    candy_y = (rand() % (48 - 1 + 1)) + 1;
    struct node *ptr;
    ptr = start;
    while (1)
    {
        int flag = 0;
        ptr = start;
        while (ptr != NULL)
        {
            if (candy_x == ptr->x && candy_y == ptr->y)
            {
                candy_x = (rand() % (28 - 1 + 1)) + 1;
                candy_y = (rand() % (48 - 1 + 1)) + 1;
                flag = 1;
            }
            ptr = ptr->next;
        }
        if (flag == 0)
        {
            break;
        }
    }
}
void create(int x_index, int y_index)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        exit(0);
    }
    temp->x = x_index;
    temp->y = y_index;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display()
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            struct node *ptr;
            ptr = start;
            int flag = 0;
            while (ptr != NULL)
            {
                if (ptr->x == i && ptr->y == j)
                {
                    if (ptr == start)
                    {
                        printf("◆");
                    }
                    else
                    {
                        printf("✪");
                    }
                    flag = 1;
                }
                ptr = ptr->next;
            }
            if (flag == 0)
            {
                if (i == 0 || i == 29)
                {
                    printf("─");
                }
                else if (j == 0 || j == 49)
                {
                    printf("|");
                }
                else if (i == candy_x && j == candy_y)
                {
                    printf("@");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
