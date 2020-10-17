#include<stdio.h>

void solve(int n, char* source, char* destination, char* helper)
{
    if(n==1)
    {
        printf("Move top disk from %s to %s\n",source,destination);
        return;
    }

    solve(n-1,source,helper,destination);

    printf("Move top disk from %s to %s\n",source,destination);

    solve(n-1,helper,destination,source);

}

void main()
{
    int n;
    char source[100],destination[100],helper[100],buffer;

    printf("Enter the no. of disks : ");
    scanf("%d",&n);
    scanf("%c",&buffer); printf("\n");

    printf("Enter the name of Source Tower of disks : ");
    gets(source);
    printf("\n");

    printf("Enter the name of Destination Tower of disks : ");
    gets(destination);
    printf("\n");

    printf("Enter the name of Helper Tower of disks : ");
    gets(helper);
    printf("\n");

    solve(n,source,destination,helper);
}
