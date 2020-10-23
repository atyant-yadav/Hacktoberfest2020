#include <stdio.h>
//addUpTo.c will sum numbers until it reaches the entered value [AKA the factorial number (n!)]
int enterNum(void)
{
  int e;    
  scanf("%d", &e);
  return e;
}
//this funtion will calculate N!
int add_up_to(int N)
{
  int i=0, temp=0;
  printf("\n Summing the next numbers...\n");
  printf("  ");
  while (i<=N)
  {
    printf("[%d]",i);
    temp=temp+i;
    i++;
  }
  return temp;
}

int main(void)
{
  int n;
  printf("\n This program will calculate the factorial of the entered number.\n > Please enter an entire number: ");
    n=enterNum();
        while(n<0){
            printf("\n The value must be no-negative.\n  > Try again: ");
            n=enterNum();
        }
  printf("\n\n The final value of the entered number is %d.\n\n", add_up_to(n));
  return 0;
}
