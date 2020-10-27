#include<stdio.h>
#include<conio.h>
int main()
 {int fnum,secnum;
  clrscr();
  printf("enter the first number=");
  scanf("%d",&fnum);
  printf("\nenter the second number=");
  scanf("%d",&secnum);
   fnum=fnum-secnum;
   secnum=fnum+secnum;
   fnum=secnum-fnum;
  printf("\nAfter swaping,first number=%d",fnum);
  printf("\nAfter swaping,second number=%d",fnum);
  getch();
  return 1;
}
