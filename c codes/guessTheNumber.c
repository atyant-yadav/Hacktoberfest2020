// This is a number guessing game created using C that will randomly generate numbers between 1 to 100 and you have to guess it.
// If you write greater than generated number it will prompt to enter smaller value. At the end it will result in number of steps taken by you for guessing the number correctly.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
srand(time(0));
int num=rand()%100;
int n,count=1;
// printf("%d",num);

do{ 
    printf("Enter you number\n");
    scanf("%d",&n);

    if(n>num){
        printf("Enter smaller number!!!!\n");

    }
    else if(n<num){
        printf("Enter greater number!!!!\n");
    }
    else
    printf("You got right %d in %d attempts!!!!\n",num,count);
    count++;
    printf("***********************************************\n");
}
while(n!=num);

}
