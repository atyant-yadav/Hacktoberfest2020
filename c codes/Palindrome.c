#include <stdio.h>
int main() {
    int n, reversedN = 0, remainder, originalN;
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;
    for(int i=n;i>0;i/=10)
    {
        remainder = i % 10;
        reversedN = reversedN * 10 + remainder;
    }
    if (originalN == reversedN)
        printf("%d is a palindrome.", originalN);
    else
        printf("%d is not a palindrome.", originalN);

    return 0;
}
