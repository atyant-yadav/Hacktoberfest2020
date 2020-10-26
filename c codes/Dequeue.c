/* Write a C program to implement basic operations on dequeue. */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

void insert_right()
{
	int x;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{
		printf("Queue Overflow.\n");
		return;
	}
	if(left == -1)
	{	
		left = 0;
		right = 0;
	}
	else if(right == MAX-1)
	{
		right = 0;
	}
	else
	{
		right++;
	}
		
	printf("Enter the data: ");
	scanf("%d",&x);
	deque_arr[right] = x;
}

void insert_left()
{	
	int x;
	if((left == 0 && right == MAX-1)||(left == right+1))
	{
		printf("Queue Overflow.\n");
		return;	
	}
	if (left==-1)
	{
		left = 0;
		right = 0;	
	}
	else if(left== 0)
	{
		left=MAX-1;
	}
	else
	{
		left--;
	}
	printf("Enter the data: ");
	scanf("%d",&x);
	deque_arr[left] = x;
}

void delete_left()
{	
	if (left==-1)
	{
		printf("Queue Underflow.\n");
		return ;
	}
	printf("Deleted data: %d\n",deque_arr[left]);
	if(left==right)
	{	
		left=-1;
		right=-1;
	}
	else if(left==MAX-1)
	{
		left=0;
	}
	else
	{
		left++;
	}
}

void delete_right()
{
	if(left==-1)
	{
		printf("Queue Underflow.\n");
		return ;
	}
	printf("Deleted data: %d\n",deque_arr[right]);
	if(left==right)
	{
		left = -1;
		right=-1;
	}
	else if(right == 0)
	{
		right=MAX-1;
	}
	else
	{
		right--;
	}
}

void display_queue()
{	
	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	
		printf("Queue is empty. Nothing to display.\n");
		return;
	}
	printf("Data:\n");
	if(front_pos<=rear_pos )
	{
		while(front_pos<=rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	else
	{
		while(front_pos<=MAX-1)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
		front_pos=0;
		while(front_pos<=rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}

void input_que()
{	int ch;
	while(1)
	{	
		printf("1. Insert At Right\n2. Delete From Left\n3. Delete From Right\n4. Display\n5. Exit\nYour choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_right();
				break;
		 	case 2:
				delete_left();
				break;
		 	case 3:
				delete_right();
				break;
		 	case 4:
				display_queue();
				break;
		 	case 5:
            	exit(0);
		 	default:
				printf("Invalid Option.\n");
		}
	}
}

void output_que()
{
	int ch;
	while(1)
	{	
		printf("1. Insert At Right\n2. Insert At Left\n3. Delete From Left\n4. Display\n5. Exit\nYour choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_right();
				break;
		 	case 2:
				insert_left();
				break;
		 	case 3:
				delete_left();
				break;
		 	case 4:
				display_queue();
				break;
		 	case 5:
				exit(0);
			default:
				printf("Invalid Option.\n");
		}
	}
}

int main()
{
	int ch;
	printf("1. Input Restricted Dequeue\n2. Output Restricted Dequeue\n3. Exit\nYour choice: ");
	scanf("%d",&ch);
	while(1)
	{
		switch(ch)
		{
			case 1 :
				input_que();
				break;
		 	case 2:
				output_que();
				break;
			case 3:
				exit(0);
		 	default:
				printf("Invalid Option.\n");
		}
	}
	return 0;
}

/* OUTPUT :
	1. Input Restricted Dequeue
	2. Output Restricted Dequeue
	3. Exit
	Your choice: 1
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 1
	Enter the data: 10
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 1
	Enter the data: 20
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 1
	Enter the data: 30
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 2
	Deleted data: 10
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 3
	Deleted data: 30
	1. Insert At Right
	2. Delete From Left
	3. Delete From Right
	4. Display
	5. Exit
	Your choice: 4
	Data:
	20
*/
