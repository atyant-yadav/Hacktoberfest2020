#include <stdio.h>

// Program to reverse a number without using arithmetic

int main()
{
    int d1, d2, d3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &d1, &d2, &d3);

    printf("The reversal is: %d%d%d\n", d3, d2, d1);

    return 0;
}