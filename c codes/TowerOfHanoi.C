#include<stdio.h>

//The program demonstrates a solution to the Tower of Hanoi problem using simple recursion
//Last Mdified 09-11-2019  18:38     COpyrights:- SANCHIT GUPTA (Elliptic Studios)

void towerofhanoi(int nod, int from,int to)		//The function gives the solution to the problem by breaking it into smaller parts
{												//The logic if I need solution for n discs from 1 to 3 ,I will find solution for n-1 discs from 1 to 2 , Move disc from 1 to 3 and find solutions for n-1 discs from 2 to 3 
	int intermediate;
	for(intermediate=1;intermediate<=3;intermediate++)
	{
		if(intermediate!=from && intermediate!=to)
			break;
	}
	if(nod>1)
	{	
		towerofhanoi(nod-1,from ,intermediate);
	}
	printf("Move %d to %d",from,to);
	printf("\n");
	if(nod>1)
	{
		towerofhanoi(nod-1,intermediate,to);
	}

}


void main()						//The main function just takes the number of discs and from and to position from the user and hence calls the above function and print the solution
{
int numberofdiscs,from,to;
printf("Enter the number of discs present on the first rod to get the instructional steps for their transfer to third rod following the rule that no larger disc is above a smaller disc");
scanf("%d",&numberofdiscs);
printf("Enter the initial rod");
scanf("%d",&from);
printf("Enter the final rod");
scanf("%d",&to);
printf("\n");
towerofhanoi(numberofdiscs,from,to);
}
