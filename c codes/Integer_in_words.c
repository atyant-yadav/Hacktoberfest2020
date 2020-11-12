//TO PRINT INTEGER IN WORDS(CONTAINING NON-ZERO DIGIT)
#include<stdio.h>
#include<math.h>
int reverse(int);
void print(int);
void main()
 {
  int num,rev;
  printf("Enter a number:");
  scanf("%d",&num);
  rev=reverse(num);//Reverses the number
  print(rev);//Print in words
 }
  
int reverse(int n)
 {
  int i,j,s; 
  for(i=-1,j=n;j;i++,j/=10){}//Calculates number of digits 
  for(i,j=n,s=0;j;i--,j/=10)
     s+=(j%10)*(pow(10.0,i));
  return(s);
 }   
    
void print(int x)
 {
   int a;
   while(x)
   {
    a=x%10;
    switch(a)
     {
      case 1:
      printf("One ");
      break;
      
      case 2:
      printf("Two ");
      break;
      
      case 3:
      printf("Three ");
      break;
     
      case 4:
      printf("Four ");
      break;
      
      case 5:
      printf("Five ");
      break;
      
      case 6:
      printf("Six ");
      break;
      
      case 7:
      printf("Seven ");
      break;
      
      case 8:
      printf("Eight ");
      break;
      
      case 9:
      printf("Nine ");
      break;
     }
      x/=10;
    }
 }
