#include<stdio.h>
void main()
{
    int n,t,sum=0,rem;

    printf("The armstrong numbers from 1 to 100 are: ");

    for(n=1;n<=100;n++)
    {
    t=n;
    while(t!=0)
    {
        rem=t%10;
        sum=sum+rem*rem*rem;
        t=t/10;
    }

    if(sum==n)
    {
        printf("%d",n);
    }
    }
}
