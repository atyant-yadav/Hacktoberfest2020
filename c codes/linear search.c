#include<stdio.h>
void main()
{
    int array[10];
    int i, num, keynum, found=0;
    clrscr();
    printf("enter the value of num \n");
    scanf("%d",&num);
    printf("enter the elements one by one \n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arrary[i]);
    }
    printf("input array is\n");
    for(i=0;i<num;i++)
    {
        printf("%d\n",array[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d",&keynum);
    for(i=0;i<num;i++
    {
        if(keynum==array[i])
        {
            found=1;
            break;
        }
    }
    if(found==1)
    printf("element is present in the array\n");
    else
    printf("element is not present in the array\n");
}