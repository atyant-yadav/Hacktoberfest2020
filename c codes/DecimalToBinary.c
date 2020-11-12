#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int d,r,p,b;

    printf("Enter Decimal No.:");
    scanf("%d",&d);

    p=0;
    b=0;

        while (d!=0)
        {
            r=d%2;
            b=b+r*pow(10,p);
            d=d/2;
            p++;
        }

        printf("Binary No.:%d",b);
}
